# Phase 5: Structural Optimization (Fmax)

This phase focus on the hardware's electrical speed. We will break long combinational paths that limit the clock frequency.

### Day 16: Register Instruction Buffer (Dispatch)
- [ ] Implement a registered (2-cycle) dispatch buffer.
- [ ] Connect `redirect.valid` to flush this buffer to avoid "bubble leak."

### Day 17-18: Pipelined Execute Stage
- [ ] Split ALU into 2-3 stages (Arithmetic -> Register Write).
- [ ] Implement Bypass Logic (Forwarding) so instructions can use results immediately.

### Day 19-20: Timing Closure
- [ ] Review critical paths in the synthesized Verilog.
- [ ] Adjust logic to ensure a high clock frequency target (e.g., 500MHz-1GHz for Zaqal).

---

## Technical Goal
- Break all long combinational paths between fetch and writeback.
- Ensure that every signal has at least one register to "breathe" through before the next clock edge.
