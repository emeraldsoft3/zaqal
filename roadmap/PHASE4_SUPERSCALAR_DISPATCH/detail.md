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
- [x] **Snapshot Study**: Study how XiangShan uses `SnapshotGenerator` to save RAT and FreeList state on every branch.
- **Goal**: Plan the integration of Checkpoint Arrays to allow 1-cycle recovery from mispredicts.
- **XiangShan Study**: [BaseFreeList.scala:L71](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/freelist/BaseFreeList.scala) - *See `SnapshotGenerator` usage.*

## Day 6: Dispatch Logic (The Traffic Cop)
- [x] Route decoded instructions to appropriate issue queues (ALU, MEM, etc.).
- **XiangShan Study**: [Dispatch.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/Dispatch.scala) - *How instructions are assigned to functional unit ports.*

## Day 7: Structural Hazard Detection
- [x] Handle cases where available ports are fewer than ready instructions.
- **Detailed Plan**: At this stage, the core is capable of decoding 6 instructions per cycle, but the execution engine might only have a limited number of functional units (e.g., 1 ALU, 1 MEM). We must dynamically count the resource requests from the 6-wide dispatch bundle. If a structural hazard is detected (e.g., two ALU instructions but only one ALU port), the dispatch unit must gracefully backpressure the frontend. This involves stalling the Instruction Buffer (IBUF) so that younger instructions remain in the buffer, rotating to the front of the queue in subsequent cycles. This ensures 100% sequential execution without dropping any instructions.
- **Goal**: Implement dynamic, resource-aware backpressure from Dispatch to Frontend.

## Day 8-10: Issue Queue Allocation & Selection
- [ ] Implement the "Picker" logic for instruction selection.
- **Detailed Plan**: Out-of-order execution requires buffering instructions that are waiting for their operands to become ready. We will implement distributed Issue Queues (IQs) that sit between the Dispatch stage and the Execution stage. When operands are broadcast on the bypass network, the "Wakeup" logic notifies dependent instructions. The "Selection" (or Picker) logic then scans the queue and selects the oldest ready instruction to be issued to the execution units. This involves complex age-matrix or tree-based arbitration to pick the winner within a single clock cycle.
- **XiangShan Study**: [IssueQueue.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/IssueQueue.scala) - *Study the selection (pick) and wakeup logic.*

## Day 11-13: Execution Clusters
- [ ] Group functional units into clusters (e.g., Integer, Float, Memory).
- **Detailed Plan**: To achieve true superscalar multi-issue execution, the backend must be refactored from a single Execution pipeline into multiple parallel Execution Clusters. We will group the functional units—such as creating an Integer Cluster containing multiple ALUs and Branch units, a Memory Cluster for Load/Store operations, and a Floating-Point Cluster. This allows independent instructions (e.g., an ALU op and a Memory load) to be issued and executed simultaneously in the exact same clock cycle, dramatically increasing IPC (Instructions Per Cycle).
- **XiangShan Study**: [XSCore.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/XSCore.scala) - *See how the top-level core connects these components.*

## Day 14-15: Flush Propagation & Completion
- [ ] Verify that flushes correctly clear all 6 slots in the pipeline stages.
- **Detailed Plan**: In a wide superscalar architecture, a branch misprediction or an exception requires flushing a massive amount of in-flight state. We must ensure that the 6-wide pipelines (Decode, Rename, Dispatch, Issue) immediately invalidate their invalid instructions upon receiving a flush signal from the Reorder Buffer or Branch Predictor. This includes carefully managing the 1-cycle latency delays between stages and ensuring that shadow parcels or fused micro-ops are also correctly flushed without causing state corruption.
- **Goal**: Maintain correctness while achieving 6-wide throughput under heavy branch pressure.

## Day 16: Hazard & Shadow Branch Testing (Phase 2 Regression)
- [ ] **Back-to-Back Branches**: Test multiple unresolved branches caught in the 6-wide decoder/issue stage. We must ensure that if multiple branches are decoded in the same cycle, the core respects the first misprediction and accurately flushes the younger ones.
- [ ] **Shadowed Mispredictions**: Re-run the Epoch inversion tests from Phase 2 Day 6. Ensure parallel flushes do not corrupt the single-bit epoch state, particularly when branches are mixed with 16-bit compressed shadow parcels.
- [ ] **Load-to-Branch Hazard**: Verify data forwarding and stalling works gracefully across the 6-way execution units. If a branch depends on a load that just executed, the bypass network must forward the loaded data directly to the branch unit to resolve the condition without unnecessary stalls.
