# Register File Pipelining & 2-Level Bypass Architecture

## 1. Overview
To achieve higher clock frequencies ($F_{max}$), the Zaqal processor pipelines its Physical Register File (PRF) writeback path. 
* **Cycle 2 (Execute)**: The execution units finish computing their results and output write-enable (`next_regFile_wen`), write-address (`next_regFile_waddr`), and write-data (`next_regFile_wdata`).
* **Cycle 3 (Write-back Staging & SRAM write)**: Results are latched into staging registers (`r_regFile_wen`, `r_regFile_waddr`, `r_regFile_wdata`) on the clock edge. In this cycle, the staging registers drive the physical register file ports to write to the SRAM array.

To prevent execution stalls, the bypass network is expanded to forward values from both timing levels:
1. **Level 1 Bypass (`r_wbX`)**: Captures results from instructions that finished executing in the previous cycle (currently in the write-back staging stage).
2. **Level 2 Bypass (`r2_wbX`)**: Captures results from instructions that are currently performing their physical write-back into the SRAM.

---

## 2. Pipelined Writeback and Bypass Diagram

```mermaid
graph TD
    subgraph Cycle 2: Execute Stage
        EX_Units[ALU0 / ALU1 / Div / LSU / FP] -->|next_regFile_wdata| WB_Mux[Write-back Interface]
        EX_Units -->|Compute Result| L1_Reg_In[Result]
    end

    subgraph Clock Edge 1 (End of Cycle 2)
        L1_Reg_In -->|Latch| r_wb[Level 1 Bypass Reg: r_wb]
        WB_Mux -->|Latch| Staging_Regs[Writeback Staging Regs: r_regFile_wdata]
    end

    subgraph Cycle 3: Writeback Stage
        Staging_Regs -->|Write Port| SRAM[(PRF SRAM Array)]
    end

    subgraph Clock Edge 2 (End of Cycle 3)
        r_wb -->|Shift| r2_wb[Level 2 Bypass Reg: r2_wb]
    end

    subgraph Bypass Multiplexer (Cycle 2 operands)
        PRF_Read[Raw RegFile Read Data] --> Bypass_Mux{Bypass Mux}
        r_wb -->|Level 1 Forward| Bypass_Mux
        r2_wb -->|Level 2 Forward| Bypass_Mux
        Bypass_Mux -->|Forwarded Operand| EX_Units
    end

    classDef stageStyle fill:#f9f,stroke:#333,stroke-width:2px;
    classDef regStyle fill:#bbf,stroke:#333,stroke-width:2px;
    classDef memStyle fill:#bfb,stroke:#333,stroke-width:2px;
    
    class EX_Units,Bypass_Mux stageStyle;
    class r_wb,r2_wb,Staging_Regs regStyle;
    class SRAM memStyle;
```

---

## 3. Bypass Priority Logic
The operand muxes in the `Execute` module prioritize forwarding from the youngest instruction to ensure the most up-to-date state is consumed:
1. **Level 1 Bypass (`r_wbX`)**: Matches if `r_wbX_pdest === rs` (1-cycle issue distance).
2. **Level 2 Bypass (`r2_wbX`)**: Matches if `r2_wbX_pdest === rs` (2-cycle issue distance).
3. **Register File Output**: Consumed if no bypass matches.

---

## 4. GTKWave Verification Signal Checklist
To trace register write-backs and forwarding, inspect the following signals under `TOP.Core.backend.exec`:
* `r_regFile_wen[4:0]`, `r_regFile_waddr[4:0]`, `r_regFile_wdata[4:0]` (Staging registers inputs to the PRF).
* `r_wb0_pdest`, `r_wb0_data` (Level 1 bypass channel).
* `r2_wb0_pdest`, `r2_wb0_data` (Level 2 bypass channel).
