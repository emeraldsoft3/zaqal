# Phase 4: Superscalar Transition (Multi-Issue)

This phase is the most architectural. We will transform our single-issue core into a multi-issue (superscalar) engine.

### Day 13: Expand Instruction Bundles
- [ ] Update `IBuffer` to output multiple instructions per cycle.
- [ ] Update `MicroOp` bundle to include rename/issue tags (if needed).

### Day 14: Multi-Execution Porting
- [ ] Instantiate 2-4 ALU units in `Backend.scala`.
- [ ] Implement a simple "Scoreboard" or "Issue Window" (Simplified for now).

### Day 15: Structural Hazard Resolution
- [ ] Implement Register File multi-read/multi-write ports.
- [ ] Resolve hazards when two instructions want the same register simultaneously.

---

## Technical Goal
- Achieve a Peak IPC of 6 instructions per cycle.
- Correctly handle intra-bundle dependencies (e.g., `addi x1, x1, 1` followed by `addi x1, x1, 1` in the same cycle).
