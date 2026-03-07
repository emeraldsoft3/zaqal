# Phase 4: Superscalar & Dispatch (The XiangShan Shift)

This is where we transition Zaqal from a simple core to a high-performance engine.

## Goal: Multi-Issue Execution (6-Wide)

## Day 1: Multi-wide Frontend Interface
- [ ] Update `FetchPacket` and `IBuffer` to support bundles of 6+ instructions.
- **XiangShan Study**: [FrontendBundle.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FrontendBundle.scala) - *See how they define the fetch packet.*

## Day 2: IBuffer Redesign (Banked Dequeue)
- [ ] Implement parallel dequeue logic to feed multiple decoders.
- **XiangShan Study**: [IBuffer.scala:L80-120](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/IBuffer.scala) - *How instructions are buffered and dequeued in parallel.*

## Day 3: Parallel Decoders
- [ ] Instantiate 6 `Decoder` modules in the Backend.
- **XiangShan Study**: [DecodeUnit.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/DecodeUnit.scala) - *Look for parameters like `DecodeWidth`.*

## Day 4: Register Renaming (Map Table)
- [ ] Implement the Map Table to translate logical registers to physical registers.
- **XiangShan Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala) - *Study the RAT (Register Alias Table) implementation.*

## Day 5: Free List Management
- [ ] Build the Free List to track available physical registers.
- **XiangShan Study**: [Rename.scala:L200-250](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/Rename.scala) - *Allocation and deallocation logic.*

## Day 6: Dispatch Logic (The Traffic Cop)
- [ ] Route decoded instructions to appropriate issue queues (ALU, MEM, etc.).
- **XiangShan Study**: [Dispatch.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/Dispatch.scala) - *How instructions are assigned to functional unit ports.*

## Day 7: Structural Hazard Detection
- [ ] Handle cases where available ports are fewer than ready instructions.
- **Goal**: Implement backpressure from Dispatch to Frontend.

## Day 8-10: Issue Queue Allocation & Selection
- [ ] Implement the "Picker" logic for instruction selection.
- **XiangShan Study**: [IssueQueue.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/IssueQueue.scala) - *Study the selection (pick) and wakeup logic.*

## Day 11-13: Execution Clusters
- [ ] Group functional units into clusters (e.g., Integer, Float, Memory).
- **XiangShan Study**: [XSCore.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/XSCore.scala) - *See how the top-level core connects these components.*

## Day 14-15: Flush Propagation & Completion
- [ ] Verify that flushes correctly clear all 6 slots in the pipeline stages.
- **Goal**: Maintain correctness while achieving 6-wide throughput.
