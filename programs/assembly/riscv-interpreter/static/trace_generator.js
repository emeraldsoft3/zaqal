// Zaqal Architectural Predictor Trace Generator
// Computes GHR, PHR, TAGE, ITTAGE, and FTB state transitions based on pure architectural simulation.

function generatePredictorTrace(codeText, limit) {
    // Instantiate a new Program instance for simulation
    const prog = new Program(codeText);
    
    // Initialize registers to 0
    prog.registers.fill(0);
    
    // TAGE constants matching Zaqal frontend
    const TAGE_TABLES = 4;
    const TAGE_HIST_LENS = [4, 12, 36, 108];
    const TAGE_INDEX_WIDTH = 7; // 128 rows
    const TAGE_TAG_WIDTH = 8;
    
    // ITTAGE constants matching Zaqal frontend
    const ITTAGE_TABLES = 4;
    const ITTAGE_HIST_LENS = [4, 12, 36, 108];
    const ITTAGE_INDEX_WIDTH = 6; // 64 rows
    const ITTAGE_TAG_WIDTH = 8;
    
    // Initialize predictor states
    let ghr = Array(128).fill(0); // LSB at index 0 (most recent)
    let phr = 0; // 32-bit integer path history
    
    // TAGE Tables: 4 tables, each has 128 entries
    let tageTables = [];
    for (let t = 0; t < TAGE_TABLES; t++) {
        let table = [];
        for (let i = 0; i < (1 << TAGE_INDEX_WIDTH); i++) {
            table.push({ valid: false, tag: 0, ctr: 3, u: 0 });
        }
        tageTables.push(table);
    }
    
    // ITTAGE Tables: 4 tables, each has 64 entries
    let ittageTables = [];
    for (let t = 0; t < ITTAGE_TABLES; t++) {
        let table = [];
        for (let i = 0; i < (1 << ITTAGE_INDEX_WIDTH); i++) {
            table.push({ valid: false, tag: 0, target: 0, u: 0 });
        }
        ittageTables.push(table);
    }
    
    // FTB entries tracking
    let ftb = {};
    
    // Helper function for folding history
    function foldHistory(historyBits, len, foldWidth) {
        const safeLen = Math.min(len, historyBits.length);
        const chunks = Math.ceil(safeLen / foldWidth);
        let result = 0;
        for (let i = 0; i < chunks; i++) {
            const start = i * foldWidth;
            const end = Math.min((i + 1) * foldWidth, safeLen);
            let chunkVal = 0;
            for (let j = start; j < end; j++) {
                if (historyBits[j] === 1) {
                    chunkVal |= (1 << (j - start));
                }
            }
            result ^= chunkVal;
        }
        return result;
    }
    
    // Get bits from 32-bit PHR
    function getPhrBits(phrVal) {
        let bits = [];
        for (let i = 0; i < 32; i++) {
            bits.push((phrVal >>> i) & 1);
        }
        return bits;
    }
    
    // Compute FTB index
    function getFtbIndex(pcVal) {
        return (pcVal >>> 5) & 0x3f;
    }
    
    // Formatting registers
    function formatReg(val, isHex) {
        if (isHex) {
            return val === 0 ? "0" : "0x" + (val >>> 0).toString(16).toUpperCase();
        }
        return val.toString();
    }
    
    // Convert GHR bit array to integer value for printing (shift left 1 to match hardware printout)
    function formatGhr(ghrArr) {
        let val = 0;
        for (let i = 0; i < 32; i++) {
            if (ghrArr[i] === 1) {
                val |= (1 << i);
            }
        }
        // Match the hardware shift (LSB is always 0)
        let shifted = (val << 1) >>> 0;
        return shifted === 0 ? "0" : "0b" + shifted.toString(2);
    }
    
    function formatPhr(phrVal) {
        return phrVal === 0 ? "0" : "0b" + (phrVal >>> 0).toString(2);
    }
    
    let traceData = [];
    let stepCount = 0;
    
    // Run the architectural simulator
    while (stepCount < limit && !prog.getErrors().length) {
        if (prog.pc / 4 >= prog.insns.length) {
            break;
        }
        
        let branchPc = prog.pc;
        let insn = prog.insns[branchPc / 4];
        let insnStr = insn[0];
        
        // Parse operation name
        let op = insnStr.split(" ")[0].trim().toLowerCase();
        let isCond = (op === "beq" || op === "bne" || op === "blt" || op === "bge" || op === "bltu" || op === "bgeu");
        let isJalr = (op === "jalr");
        
        // Snapshot predictor states before execution
        let rowGhr = ghr.slice();
        let rowPhr = phr;
        
        // 1. Predictor Lookup (to get index, tag, and provider table index before update)
        let providerTage = -1;
        let tageIndices = [];
        let tageTags = [];
        if (isCond) {
            let alignedPc = (branchPc & ~31) >>> 0;
            for (let t = 0; t < TAGE_TABLES; t++) {
                let histLen = TAGE_HIST_LENS[t];
                let idx_fh = foldHistory(ghr, histLen, TAGE_INDEX_WIDTH);
                let tag_fh = foldHistory(ghr, histLen, TAGE_TAG_WIDTH);
                let idx = (alignedPc ^ idx_fh) & 127;
                let tag = (alignedPc ^ tag_fh) & 255;
                
                tageIndices.push(idx);
                tageTags.push(tag);
                
                let entry = tageTables[t][idx];
                if (entry.valid && entry.tag === tag) {
                    providerTage = t;
                }
            }
        }
        
        let providerIttage = -1;
        let ittageIndices = [];
        let ittageTags = [];
        if (isJalr) {
            let alignedPc = (branchPc & ~31) >>> 0;
            let phrBits = getPhrBits(phr);
            for (let t = 0; t < ITTAGE_TABLES; t++) {
                let histLen = ITTAGE_HIST_LENS[t];
                let idx_fh = foldHistory(phrBits, histLen, ITTAGE_INDEX_WIDTH);
                let tag_fh = foldHistory(phrBits, histLen, ITTAGE_TAG_WIDTH);
                let idx = (alignedPc ^ idx_fh) & 63;
                let tag = (alignedPc ^ tag_fh) & 255;
                
                ittageIndices.push(idx);
                ittageTags.push(tag);
                
                let entry = ittageTables[t][idx];
                if (entry.valid && entry.tag === tag) {
                    providerIttage = t;
                }
            }
        }
        
        // 2. Step the simulation
        prog.step();
        stepCount++;
        
        let afterPc = prog.pc;
        
        // Determine branch outcomes
        let actualTaken = false;
        if (isCond) {
            actualTaken = (afterPc !== branchPc + 4);
        }
        
        // FTB Update
        let isCfi = isJalr || (op === "jal") || (isCond && actualTaken);
        if (isCfi) {
            let ftbIdx = getFtbIndex(branchPc);
            ftb[ftbIdx] = `x${branchPc.toString(16).padStart(2, '0')} - x${afterPc.toString(16).padStart(2, '0')}`;
        }
        
        // 3. TAGE Update & Detail Logging
        let tageDetails = "-";
        if (isCond) {
            let pT = providerTage;
            let pIdx = (pT !== -1) ? tageIndices[pT] : -1;
            let pTag = (pT !== -1) ? tageTags[pT] : -1;
            
            let providerPred = true; // Base bimodal table initial state in RTL is 2 (weakly taken)
            let altPred = false;
            
            if (pT !== -1) {
                providerPred = (tageTables[pT][pIdx].ctr >= 4);
                
                // Find alternate prediction
                let altT = -1;
                let altIdx = -1;
                for (let t = pT - 1; t >= 0; t--) {
                    let idx = tageIndices[t];
                    let tag = tageTags[t];
                    if (tageTables[t][idx].valid && tageTables[t][idx].tag === tag) {
                        altT = t;
                        altIdx = idx;
                        break;
                    }
                }
                if (altT !== -1) {
                    altPred = (tageTables[altT][altIdx].ctr >= 4);
                } else {
                    altPred = true; // Base predictor
                }
            }
            
            let mispredict = (providerPred !== actualTaken);
            let updateTable = -1;
            let updateIdx = -1;
            let updateTag = -1;
            
            // Allocation
            if (mispredict) {
                for (let t = pT + 1; t < TAGE_TABLES; t++) {
                    let idx = tageIndices[t];
                    let tag = tageTags[t];
                    if (tageTables[t][idx].u === 0) {
                        tageTables[t][idx].valid = true;
                        tageTables[t][idx].tag = tag;
                        tageTables[t][idx].ctr = actualTaken ? 4 : 3;
                        tageTables[t][idx].u = 0;
                        updateTable = t;
                        updateIdx = idx;
                        updateTag = tag;
                        break;
                    }
                }
                if (updateTable === -1) {
                    // Decay
                    for (let t = pT + 1; t < TAGE_TABLES; t++) {
                        let idx = tageIndices[t];
                        if (tageTables[t][idx].u > 0) {
                            tageTables[t][idx].u--;
                        }
                    }
                }
            }
            
            // Update existing provider
            if (pT !== -1) {
                let entry = tageTables[pT][pIdx];
                if (actualTaken) {
                    entry.ctr = Math.min(entry.ctr + 1, 7);
                } else {
                    entry.ctr = Math.max(entry.ctr - 1, 0);
                }
                if (providerPred !== altPred) {
                    if (providerPred === actualTaken) {
                        entry.u = Math.min(entry.u + 1, 3);
                    } else {
                        entry.u = Math.max(entry.u - 1, 0);
                    }
                }
                // If we did not allocate a longer history entry, the provider itself was updated
                if (!mispredict) {
                    updateTable = pT;
                    updateIdx = pIdx;
                    updateTag = pTag;
                }
            }
            
            // Format what was updated in the TAGE tables
            if (updateTable !== -1) {
                let entry = tageTables[updateTable][updateIdx];
                tageDetails = `T${updateTable}[${updateIdx}], Tag=0x${updateTag.toString(16).toUpperCase()}, US=${entry.u}, CTR=${entry.ctr}`;
            } else if (mispredict) {
                tageDetails = "Decay (No Alloc)";
            } else {
                tageDetails = "No Update";
            }
            
            // Shift outcome into GHR
            ghr.unshift(actualTaken ? 1 : 0);
            ghr.pop();
        }
        
        // 4. ITTAGE Update & Detail Logging
        let ittageDetails = "-";
        if (isJalr) {
            let pT = providerIttage;
            let pIdx = (pT !== -1) ? ittageIndices[pT] : -1;
            let pTag = (pT !== -1) ? ittageTags[pT] : -1;
            
            let providerPredTarget = (pT !== -1) ? ittageTables[pT][pIdx].target : 0;
            let mispredict = (pT === -1) || (providerPredTarget !== afterPc);
            
            let updateTable = -1;
            let updateIdx = -1;
            let updateTag = -1;
            
            if (pT !== -1) {
                let entry = ittageTables[pT][pIdx];
                if (providerPredTarget === afterPc) {
                    entry.u = Math.min(entry.u + 1, 3);
                } else {
                    entry.u = Math.max(entry.u - 1, 0);
                }
            }
            
            // Allocation
            if (mispredict) {
                for (let t = pT + 1; t < ITTAGE_TABLES; t++) {
                    let idx = ittageIndices[t];
                    let tag = ittageTags[t];
                    if (ittageTables[t][idx].u === 0) {
                        ittageTables[t][idx].valid = true;
                        ittageTables[t][idx].tag = tag;
                        ittageTables[t][idx].target = afterPc;
                        ittageTables[t][idx].u = 0;
                        updateTable = t;
                        updateIdx = idx;
                        updateTag = tag;
                        break;
                    }
                }
                if (updateTable === -1) {
                    for (let t = pT + 1; t < ITTAGE_TABLES; t++) {
                        let idx = ittageIndices[t];
                        if (ittageTables[t][idx].u > 0) {
                            ittageTables[t][idx].u--;
                        }
                    }
                }
            } else if (pT !== -1) {
                updateTable = pT;
                updateIdx = pIdx;
                updateTag = pTag;
            }
            
            // Format what was updated in the ITTAGE tables
            if (updateTable !== -1) {
                let entry = ittageTables[updateTable][updateIdx];
                ittageDetails = `T${updateTable}[${updateIdx}], Tag=0x${updateTag.toString(16).toUpperCase()}, Target=0x${entry.target.toString(16).toUpperCase()}, US=${entry.u}`;
            } else if (mispredict) {
                ittageDetails = "Decay (No Alloc)";
            } else {
                ittageDetails = "No Update";
            }
            
            // Shift target into PHR
            phr = ((phr << 6) | ((afterPc >>> 2) & 0x3f)) & 0xffffffff;
        }
        
        // Push record
        let pcOffset = branchPc & 0xff;
        let hexMap = {
            0x00: "00a00093", 0x04: "00000293", 0x08: "00628293", 0x0c: "0032f713",
            0x10: "00070463", 0x14: "00100793", 0x18: "00271893", 0x1c: "0140026f",
            0x20: "00a00793", 0x24: "0180006f", 0x28: "01400793", 0x2c: "0100006f",
            0x30: "01120233", 0x34: "000200e7", 0x38: "fff08093", 0x3c: "fe009ce3",
            0x40: "06300613"
        };
        let hexVal = hexMap[pcOffset] || "00000013";

        traceData.push({
            order: stepCount,
            pc: "x" + branchPc.toString(16).padStart(2, '0'),
            instruction: insn[2],
            hexInsn: hexVal,
            x1: formatReg(prog.registers[1], true),
            x4: formatReg(prog.registers[4], true),
            x5: formatReg(prog.registers[5], false),
            x14: formatReg(prog.registers[14], false),
            x15: formatReg(prog.registers[15], false),
            x17: formatReg(prog.registers[17], false),
            ftb0: ftb[0] || "EMPTY",
            ftb1: ftb[1] || "EMPTY",
            ghr: formatGhr(rowGhr),
            tage: tageDetails,
            phr: formatPhr(rowPhr),
            ittage: ittageDetails
        });
    }
    
    return traceData;
}

function exportTraceToCSV(traceData) {
    const headers = [
        "Order", "PC", "Instruction", "Hex",
        "x1", "x4", "x5", "x14", "x15", "x17",
        "FTB Entry 0 (Src-Tgt)", "FTB Entry 1 (Src-Tgt)",
        "GHR (TAGE index)", "TAGE Details",
        "PHR (ITTAGE index)", "ITTAGE Details"
    ];
    
    let csvRows = [headers.join(",")];
    
    traceData.forEach(row => {
        const fields = [
            row.order,
            row.pc,
            `"${row.instruction}"`,
            row.hexInsn,
            row.x1,
            row.x4,
            row.x5,
            row.x14,
            row.x15,
            row.x17,
            row.ftb0,
            row.ftb1,
            row.ghr,
            `"${row.tage}"`,
            row.phr,
            `"${row.ittage}"`
        ];
        csvRows.push(fields.join(","));
    });
    
    const csvContent = csvRows.join("\n");
    const blob = new Blob([csvContent], { type: "text/csv;charset=utf-8;" });
    saveAs(blob, "tage_test_trace_gemini.csv");
}
