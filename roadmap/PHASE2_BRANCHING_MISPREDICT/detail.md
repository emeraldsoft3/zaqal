# Phase 2: Branching & Mispredict Handling

This phase is the most critical for understanding how the core handles "surprises" in the execution flow.

## Goal: 1-Wide Control Integrity
Even though we are staying 1-wide, we will refine the **IBuffer** to handle flushes perfectly under different pipeline depths.

## Day 1: Conditional Branching
- [ ] `BEQ`, `BNE` (Equal / Not Equal)
- [ ] `BLT`, `BGE` (Less than / Greater than or equal - Signed)
- [ ] `BLTU`, `BGEU` (Unsigned variants)
- **XiangShan Study**: [Branch.scala:L33-55](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Branch.scala) - *How XiangShan resolves branch outcomes.*
- **Goal**: Verify branch taken/not-taken logic in simulation.

## Day 2: Jumps & Links
- [ ] `JAL` (Jump and Link - PC relative)
- [ ] `JALR` (Jump and Link Register - Indirect)
- **XiangShan Study**: [Jump.scala:L20-35](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Jump.scala) - *See JAL/JALR target calculation.*
- **Goal**: Correctly compute `PC+4` for the `ra` (x1) register and verify indirect jumps.

## Day 3: Branch Redirection logic
- [ ] Implement the `Redirect` signal from Backend to Frontend.
- [ ] Update the PC in the Fetch stage when a redirect occurs.
- **XiangShan Study**: [Frontend.scala:L230-260](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Frontend.scala) - *Look for how Redirect signals are prioritized.*
- **Goal**: Ensure the processor restarts fetch from the correct address.

## Day 4: Pipeline Flush & IBuffer Clearing
- [ ] Refine the `IBuffer` flush to clear leaked instructions.
- [ ] Verify that no instructions from the "wrong path" ever reach the commit stage.
- **XiangShan Study**: [IBuffer.scala:L120-145](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/IBuffer.scala) - *Study how they handle flushes in the instruction buffer.*
- **Goal**: Perfect synchronization between FTQ, IBuffer, and the Pipeline.
