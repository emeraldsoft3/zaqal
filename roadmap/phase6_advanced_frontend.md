# Phase 6: Advanced Frontend (Caches & BPU)

This final phase brings the processor to its peak potential by optimizing the instruction delivery system.

### Day 21-23: Instruction Cache (I-Cache)
- [ ] Implement a 2-way Set-Associative I-Cache.
- [ ] Handle cache misses (stalling the pipeline until the memory returns).

### Day 24-26: Data Cache (D-Cache)
- [ ] Implement a 4-way Set-Associative D-Cache.
- [ ] Implement Load-to-Use penalty handling.

### Day 27-30: Dynamic Branch Prediction (BPU)
- [ ] Implement a GShare or TAGE predictor (Advanced).
- [ ] Implement a BTB (Branch Target Buffer) to store target addresses.
- [ ] Replace the hardcoded BPU logic with these dynamic tables.

---

## Technical Goal
- Reach an IPC close to the theoretical maximum (e.g., 4-5 instructions per cycle).
- Successfully run complex programs (e.g., CoreMark) at high performance.
