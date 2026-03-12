# Phase 2: Branching & Mispredict Handling

This phase is the most critical for understanding how the core handles "surprises" in the execution flow.

## Instruction Verification Matrix

| Instruction | Functional Logic Tests | PC Target Tests | BPU Scenarios | Link? |
| :--- | :--- | :--- | :--- | :--- |
| **BEQ** | Zero, Identical, Max/Min | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **BNE** | Zero, Identical, Max/Min | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **BLT** | Signed Boundaries (-1 < 1) | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **BGE** | Signed Boundaries | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **BLTU** | Unsigned Boundaries (-1 < 1 False) | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **BGEU** | Unsigned Boundaries | Fwd/Bwd, Max Range | Hit/Miss (T/NT) | No |
| **JAL** | N/A | Fwd/Bwd, Max Range | Hit (Always) | Yes (PC+4) |
| **JALR** | N/A | Indirect Target, Alignment | Hit (Always) | Yes (PC+4) |

## Day-by-Day Plan

### Day 1: Equality Branching & BPU Bootstrap [x]
- [x] Implement `BEQ` logic and Decoder support.
- [x] Setup hardcoded BPU predictions in `BPU.scala`.
- [x] Create initial `ICache` test cases for `BEQ` (Taken/Not-Taken).
- [x] Verify correct prediction (Hit) for Taken and Not-Taken.

### Day 2: Inequality Branching (Signed/Unsigned)
- [ ] Implement `BLT`, `BGE`, `BLTU`, `BGEU`.
- [ ] **Verification**: Functional tests for comparison logic (especially `-1 < 1` for BLT vs BLTU).
- [ ] **Goal**: Ensure the `Comparator` in the ALU/BRU handles all signedness correctly.

### Day 3: Jumps & Links (JAL/JALR)
- [ ] Implement `JAL` and `JALR`.
- [ ] **Link Register**: Verify `rd` (usually `x1/ra`) stores `PC + 4`.
- [ ] **Goal**: Correctly update the register file while jumping.

### Day 4: Indirect Jumps & Alignment Stress
- [ ] Stress test `JALR` with runtime-calculated pointers.
- [ ] **Verification**: Target calculation and alignment checks (2-byte/4-byte).

### Day 5: Pipeline Flush & Redirection logic
- [ ] Refine the `Redirect` signal from Backend to Frontend.
- [ ] Ensure `IBuffer` is cleared perfectly during a flush.
- [ ] **Goal**: No "wrong path" instruction ever reaches execution after a mispredict.

### Day 6: Architectural Stress Tests
- [ ] **Back-to-Back Branches**: Verify BPU handles rapid outcome changes.
- [ ] **Load-to-Branch Hazard**: Test branches following a load to its source register.
- [ ] **Page Boundaries**: Branch at extremely end of packet/page boundaries.

---

# Comprehensive Branch Verification Checklist (Reference)

*(Items included in the matrix and day-by-day tasks above)*
