# Phase 4: Superscalar & Dispatch (The XiangShan Shift)

This is where we transition Zaqal from a simple core to a high-performance engine.

## Goal: Multi-Issue Execution (6-Wide)

## Day 1: Multi-wide Frontend Interface
- [x] Update `FetchPacket` and `IBuffer` to support bundles of 6+ instructions.
- **XiangShan Study**: [FrontendBundle.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FrontendBundle.scala) - *See how they define the fetch packet.*

## Day 2: IBuffer Redesign (Banked Dequeue)
- [x] Expand the simple 1-entry `IBuffer` into a fully decoupled multi-entry Instruction Fetch Queue (IFQ/FIFO) to handle continuous aligned and compressed instruction streaming for superscalar issue.
- [x] Implement parallel dequeue logic to feed multiple decoders.
- **XiangShan Study**: [IBuffer.scala:L80-120](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/IBuffer.scala) - *How instructions are buffered and dequeued in parallel.*

## Day 3: Parallel Decoders
- [x] Instantiate 6 `Decoder` modules in the Backend.
- **XiangShan Study**: [DecodeUnit.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/DecodeUnit.scala) - *Look for parameters like `DecodeWidth`.*

## Day 3.5: Instruction Fusion (XiangShan Parity)
- [x] **Macro-Op Fusion**: Fuse patterns like `LUI`+`ADDI` into a single micro-op to save rename/issue bandwidth.
- [x] **Micro-Op Fusion**: Fuse Memory + ALU operations where applicable.
- **Goal**: Increase effective dispatch width and reduce PRF pressure.

## Day 4: Register Renaming (Map Table)
- [x] Implement the Map Table to translate logical registers to physical registers.
- [x] **Verify the above implementation** (Study the intra-bundle bypassing and state management).
- [x] **Renaming Parity**: Expand `RenameTable` to include separate Integer and Floating-Point RATs (XiangShan parity).
- **XiangShan Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala) - *Study the RAT (Register Alias Table) implementation.*

## Day 5: Free List Management
- [x] Build the Free List to track available physical registers.
- **XiangShan Study**: [Rename.scala:L200-250](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/Rename.scala) - *Allocation and deallocation logic.*

## Day 5.5: Speculative State Snapshots (XiangShan Parity)
- [ ] **Snapshot Study**: Study how XiangShan uses `SnapshotGenerator` to save RAT and FreeList state on every branch.
- **Goal**: Plan the integration of Checkpoint Arrays to allow 1-cycle recovery from mispredicts.
- **XiangShan Study**: [BaseFreeList.scala:L71](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/freelist/BaseFreeList.scala) - *See `SnapshotGenerator` usage.*

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

## Day 16: Hazard & Shadow Branch Testing (Phase 2 Regression)
- [ ] **Back-to-Back Branches**: Test multiple unresolved branches caught in the 6-wide decoder/issue stage.
- [ ] **Shadowed Mispredictions**: Re-run the Epoch inversion tests from Phase 2 Day 6. Ensure parallel flushes do not corrupt the single-bit epoch state.
- [ ] **Load-to-Branch Hazard**: Verify data forwarding and stalling works gracefully across the 6-way execution units.
