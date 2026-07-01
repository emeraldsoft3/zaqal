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
- **Detailed Plan**: The Reorder Buffer (ROB) is the backbone of out-of-order execution. It ensures that while instructions execute in any order as soon as their data is ready, they update the architectural state strictly in-order. We will build a massive circular buffer (e.g., 128+ entries). Instructions are allocated in the ROB at dispatch, and they graduate (commit) only when they reach the head of the ROB and have successfully executed without exceptions. If an exception occurs, the ROB acts as the rollback mechanism, flushing all younger speculative instructions.
- **XiangShan Study**: [Rob.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/Rob.scala)

## Day 9-15: Register Renaming, Cache & Snapshots
- [ ] **Day 9-11**: **Rename Alias Table (RAT)**: Map logical registers to physical ones.
- [ ] **Day 11.5**: **Checkpoint Array (Snapshots)**: Implement 1-cycle RAT/FreeList state recovery for branch mispredicts (XiangShan parity).
- [ ] **Day 12-13**: **Physical Register File (PRF)**: High-bandwidth multi-port RF.
- [ ] **Day 14-15**: **Register Cache (RC)**: Reduce PRF read latency to improve $F_{max}$.
- **Detailed Plan**: We will separate the architectural registers from the Physical Register File (PRF). The RAT will dynamically map the 32 logical RISC-V registers to a much larger pool of physical registers (e.g., 160+), entirely eliminating Write-After-Write (WAW) and Write-After-Read (WAR) false dependencies. We will also implement a Checkpoint Array, taking micro-architectural snapshots of the RAT at every branch, enabling instantaneous 1-cycle rollback upon misprediction. To alleviate PRF read bottlenecks, we will introduce a Register Cache to hold recently written values. Since the bypass network, wakeup buses, and checkpoint arrays scale quadratically with issue width, we will run the 14nm logic synthesis and P&R toolchain on the backend block to verify that these structures do not degrade our 1.0–1.5 GHz $F_{max}$ target.
- **XiangShan Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala)

## Day 16-25: Issue Queues & LSQ (The Schedulers)
- [ ] **Day 16-18**: **Distributed Issue Queues**: Parallel schedulers for ALU, Mem, and Branch.
- [ ] **Day 19-21**: **Load/Store Queues (LSQ)**: Handle memory dependencies out-of-order.
- [ ] **Day 22-24**: **Memory Disambiguation**: Speculative loads and store-to-load forwarding.
- [ ] **Day 25**: **Memory Dependence Predictor (MDP)**: Implement Store Sets (SSIT/LFST) or Wait Table to predict load/store collisions and avoid costly memory violation flushes (XiangShan parity).
- [ ] **Day 25.5**: **RV64D (Double Precision FPU)**: Complete the "G" extension requirement by adding 64-bit double precision paths to the FPU execution units, missing from Phase 3.
- [ ] **Day 25.8**: **Advanced Micro-op Fusion**: Implement advanced fusion rules (e.g. Memory + ALU) in the decoders and issue queues.
- **Detailed Plan**: We will build distributed, out-of-order Issue Queues that wake up instructions via a broadcast bypass network and pick the oldest ready instructions using a selection matrix. For memory, the Load/Store Queues (LSQ) will allow loads to execute out-of-order and safely bypass older stores if the addresses don't match. If an older store writes to the same address a younger load is requesting, the LSQ will transparently forward the data directly. We will also build an advanced Memory Dependence Predictor (MDP) to learn which loads frequently collide with stores, artificially delaying them to prevent catastrophic memory violation flushes.

### Target Execution Unit Configuration (Kunminghu Parity)
To match the high-IPC processing power of XiangShan's Kunminghu core, Zaqal's execution engine is mapped into the following specialized execution pipelines, each fed by its own dedicated (or shared) Issue Queue port:
- **4 ALUs**: Fully pipelined single-cycle Integer pipelines for arithmetic, logical, shift, and address generation operations.
- **2 MDUs**: Pipelined multi-cycle Multiplication and Division execution units (often shared with two of the ALU physical ports).
- **2 BRUs**: Branch Resolution Units to calculate branch targets and evaluate predictions.
- **3 LSUs (Load/Store Units)**: High-bandwidth memory pipeline consisting of **2 Load pipelines** and **1 Store pipeline** (or 3 flexible Load/Store pipes) to sustain the L1-D cache throughput.
- **4 FPUs**: Pipelined Floating-Point Units, structured as **2 FP Add/Misc units** and **2 FP FMAC (Fused Multiply-Accumulate)** units.
- **Bypass Network Update**: Expand the list-based registered bypass network (`bypassChannels` in `Execute.scala`) by adding the new execution pipelines (ALUs 2-3, MDU 1, BRU 1, LSU 1-2, FPU 1-3) to ensure automatic result forwarding and back-to-back scheduling across all added functional units.
- **XiangShan Study**: [IssueQueue.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/IssueQueue.scala)


## Day 26-35: Intelligent Memory Prefetching (L1-D Hidden Power)
- [ ] **Day 26-28**: **Stride & Stream Prefetchers**: Detect constant patterns in memory.
- [ ] **Day 29-31**: **Spatial Memory Streaming (SMS)**: Handle irregular spatially-local accesses.
- [ ] **Day 32-33**: **Frontend Data Prefetcher (FDP)**: Use branch signals to warm up the cache.
- [ ] **Day 34-35**: **Prefetch Coordination**: Throttling for bus congestion and L2-cache interaction.
- **Detailed Plan**: Modern cores mask memory latency by predicting what data will be needed next. We will build hardware prefetchers that monitor the memory addresses requested by the LSQ. The Stride Prefetcher will detect sequential access patterns (like looping over an array) and fetch the data into the cache before the processor even asks for it. The Spatial Memory Streaming (SMS) prefetcher will learn irregular spatial footprints in memory blocks. A prefetch coordinator will manage these requests to ensure they don't saturate the memory bus and degrade actual demand-load performance.
- **XiangShan Study**: [prefetch/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/)

## Day 36-40: Out-of-Order Engine Timing Closure & Waveform Validation
- [ ] **Day 36-37**: **Physical Synthesis on Integrated Core**: Run the entire integrated backend (Rename + ROB + PRF + Schedulers + LSQ) through the Yosys/OpenLane toolchain established in Phase 5. Identify critical timing violations (WNS) and routing congestion in the bypass network and wakeup loops.
- [ ] **Day 38-39**: **OoO Critical-Path Optimizations**:
  - Restructure the **Rename Alias Table (RAT)** checkpoints to use fast one-hot multiplexers.
  - Optimize the **wakeup-select broadcast buses** by introducing segmented pipeline slices.
  - Implement tree-based comparison logic inside the **LSQ store-to-load forwarding matcher**.
- [ ] **Day 40**: **Functional Waveform Profiling**: Run execution traces (like Dhrystone and memory stress-tests) with full cycle-accurate FTQ and simulation logs. Trace instructions inside GTKWave from Rename through Issue, Memory Access, and ROB Commitment to ensure zero unexpected stalls or architectural mismatches.

---

## Future Scope: Multi-Bit Branch Tagging (BRT) & Post-Parity Execution Optimizations
- **Multi-Bit Branch Tagging (BRT)**: Replace the 1-bit `epoch` system with XiangShan's multi-bit `BranchTag` (BRT) arrays and redirection masks, allowing the core to track dozens of in-flight branches simultaneously and selectively flush independent execution paths with surgical precision.
- **ALU/MDU Post-Parity Optimization**: Once functional parity with baseline XiangShan structures is verified, apply advanced microarchitectural updates for physical synthesis timing improvements:
  1. Consolidate separate Adder & Subtractor modules into a single shared Adder-Subtractor using conditional input inversion and carry-in control to reduce physical area.
  2. Implement a 3-stage pipelined multiplier to isolate the slow 128-bit Carry-Propagate Addition (CPA) into its own dedicated clock cycle.
  3. Adopt Radix-8 Booth encoding to reduce Wallace Tree product rows from 33 down to 22.
  4. Flatten serially nested result selection multiplexers into fast, parallel One-Hot `Mux1H` selection trees.
