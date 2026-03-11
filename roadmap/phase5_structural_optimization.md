# Phase 5: Structural Optimization (Fmax)

This phase focus on the hardware's electrical speed. We will break long combinational paths that limit the clock frequency.

### Day 16: Register Instruction Buffer (Dispatch)
- [ ] Implement a registered (2-cycle) dispatch buffer.
- [ ] Connect `redirect.valid` to flush this buffer to avoid "bubble leak."

### Day 17-18: Pipelined Execute Stage
- [ ] Split ALU into 2-3 stages (Arithmetic -> Register Write).
- [ ] Implement Bypass Logic (Forwarding) so instructions can use results immediately.

### Day 19-20: Timing Closure & Modularity
- [ ] Review critical paths in the synthesized Verilog.
- [ ] Adjust logic to ensure a high clock frequency target (e.g., 500MHz-1GHz for Zaqal).
- [ ] **Transition to Modular Functional Units**: Break down the unified ALU/Shifter into separate, optimized modules (like XiangShan) to improve timing and extensibility for future ISA extensions (Bitmanip, Vector).
- [ ] **Hardware Logic Sharing**: Refactor the `Adder` to use a single 64-bit adder for both ADD and SUB (using 2's complement). Integrate this shared adder with the `Comparator` module to eliminate redundant subtraction logic.
- [ ] **ALU-BRU Resource Sharing**: Link the `BRU` (Branch Unit) to the ALU's `Adder` and `Comparator`. Use the ALU hardware for branch target calculation and condition checks.
- [ ] **ALU-LSU (AGEN) Sharing**: Reuse the ALU's `Adder` for memory address generation (rs1 + offset) in the Load/Store Unit, reducing area.
- [ ] **Unified Shifter & Bitmanip**: Integrate Zba/Zbb (Bitmanip) instructions into the `Shifter` logic to share bit-extraction and multi-bit shifting hardware.

---

## Technical Goal
- Break all long combinational paths between fetch and writeback.
- Ensure that every signal has at least one register to "breathe" through before the next clock edge.
- Implement a "Modular FU" architecture to reduce Mux overhead and allow independent physical optimization of shifters, adders, and complex logic.
