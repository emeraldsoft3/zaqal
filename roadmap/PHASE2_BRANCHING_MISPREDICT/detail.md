# Phase 2: Branching & Mispredict Handling

This phase is the most critical for understanding how the core handles "surprises" in the execution flow.

## Goal: 1-Wide Control Integrity
Even though we are staying 1-wide, we will refine the **IBuffer** to handle flushes perfectly under different pipeline depths.

## Day 5: Conditional Branching
- [ ] `BEQ`, `BNE` (Equal / Not Equal)
- [ ] `BLT`, `BGE` (Less than / Greater than or equal - Signed)
- [ ] `BLTU`, `BGEU` (Unsigned variants)

## Day 6: Jumps & Links
- [ ] `JAL` (Jump and Link - PC relative)
- [ ] `JALR` (Jump and Link Register - Indirect)
- **Goal**: Correctly compute `PC+4` for the `ra` (x1) register.

## Day 7: Misprediction Deep Dive
- [ ] Implement a **Delayed Redirect**: artificially add 1-2 registers to the redirect path.
- [ ] Observe the "Speculative Leak": see instructions enter the pipeline after a branch.
- [ ] Refine the `IBuffer` flush to clear these leaked instructions before they reach the Register File.

## Technical Challenge
Ensure that when a branch mispredicts, the **FTQ** and **IBuffer** are synchronized so fetch restarts exactly at the target address.
