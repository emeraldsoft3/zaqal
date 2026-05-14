# Phase 7: Engine Performance (Out-of-Order & Prefetching)

The goal of this phase is to turn the "Instructions-per-packet" into "Instructions-per-cycle" (IPC) through full-scale Out-of-Order execution and high-performance memory bandwidth.

## Goal: High-IPC Out-of-Order Execution
- **Commitment**: **Reorder Buffer (ROB)** for in-order state recovery.
- **Renaming**: **Register Alias Table (RAT)** and Physical Register File (PRF).
- **Execution**: **Distributed Issue Queues** (ALU, MEM, BRANCH).
- **Memory**: **Intelligent Prefetchers** (Stride, Spatial, Stream).

---

## Day 1-8: Reorder Buffer (ROB) & Commit Logic
- [ ] **Day 1-3**: **ROB Logic**: Implement the core buffer to track in-flight instructions.
- [ ] **Day 4-5**: **Pointer Management**: Enqueue/Dequeue pointers for circular commitment.
- [ ] **Day 6-8**: **Exception & Flush**: Precise exceptions and rollback state management.
- **XiangShan Study**: [Rob.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/Rob.scala)

## Day 9-15: Register Renaming, Cache & Snapshots
- [ ] **Day 9-11**: **Rename Alias Table (RAT)**: Map logical registers to physical ones.
- [ ] **Day 11.5**: **Checkpoint Array (Snapshots)**: Implement 1-cycle RAT/FreeList state recovery for branch mispredicts (XiangShan parity).
- [ ] **Day 12-13**: **Physical Register File (PRF)**: High-bandwidth multi-port RF.
- [ ] **Day 14-15**: **Register Cache (RC)**: Reduce PRF read latency to improve Fmax.
- **XiangShan Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala)

## Day 16-25: Issue Queues & LSQ (The Schedulers)
- [ ] **Day 16-18**: **Distributed Issue Queues**: Parallel schedulers for ALU, Mem, and Branch.
- [ ] **Day 19-21**: **Load/Store Queues (LSQ)**: Handle memory dependencies out-of-order.
- [ ] **Day 22-25**: **Memory Disambiguation**: Speculative loads and store-to-load forwarding.
- **XiangShan Study**: [IssueQueue.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/IssueQueue.scala)

## Day 26-35: Intelligent Memory Prefetching (L1-D Hidden Power)
- [ ] **Day 26-28**: **Stride & Stream Prefetchers**: Detect constant patterns in memory.
- [ ] **Day 29-31**: **Spatial Memory Streaming (SMS)**: Handle irregular spatially-local accesses.
- [ ] **Day 32-33**: **Frontend Data Prefetcher (FDP)**: Use branch signals to warm up the cache.
- [ ] **Day 34-35**: **Prefetch Coordination**: Throttling for bus congestion and L2-cache interaction.
- **XiangShan Study**: [prefetch/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/)

---

## Future Scope: Multi-Bit Branch Tagging (BRT)
- Replace the 1-bit `epoch` system with XiangShan's multi-bit `BranchTag` (BRT) arrays and redirection masks.
