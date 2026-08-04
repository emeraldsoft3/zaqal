# Phase 6: Front-end Performance (Neural BPU & Caches)

To achieve true XiangShan-level performance, the front-end must provide near-perfect instruction flow while decoupling timing from the rest of the core.

## Goal: Intelligent Instruction Flow & High Frequency
- **Neural Prediction**: Perceptron-based guided branching.
- **Micro-Architecture**: 2-stage BPU with unified pointer-based skidding.
- **Timing**: Clean module interfaces using `zaqal.utility.SkidBuffer`.

---

## Day 1-5: The Predictor Array (TAGE & FTB)
- [x] **Day 1-2**: **FTB (Fetch Target Buffer)**: Store targets and prediction metadata.
- [x] **Day 3-5**: **TAGE & ITTAGE**: Implement tagged geometric predictors for long-history patterns. *(Note: TAGE and ITTAGE have been implemented but are not thoroughly verified yet. Full verification is deferred until ROB and multi-branch support are added).*
- **Detailed Plan**: A simple branch predictor is insufficient for deep superscalar cores. We will build a Fetch Target Buffer (FTB) to cache branch target addresses and instruction boundaries. Alongside it, we will implement the TAGE (TAgged GEometric) predictor, the gold standard in modern branch prediction. TAGE uses multiple tables indexed by geometrically increasing lengths of global branch history, allowing it to predict highly complex, long-correlating branch patterns with extreme accuracy.
- **XiangShan Study**: [FTB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FTB.scala)

## Day 6-12: Neural BPU, RAS, uFTB & Checkpointing (XiangShan-Parity)
- [x] **Day 6-8**: **Neural BPU (Statistical Corrector / SC)**: Perceptron weight tables to override TAGE on hard data-dependent branches. *(Note: SC implementation complete, verification remaining).*
- [x] **Day 9**: **Advanced Pointer Management**: Unify FTQ and SkidBuffer systems into a single elastic flow.
- [ ] **Day 10**: **Return Address Stack (RAS)**: Build functional 16-entry Return Address Stack to predict function return targets (`JAL/JALR` with `x1`/`x5` link registers) at fetch time. *(See [Day 10 RAS Implementation & Verification Plan](./day10_ras.md))*.
- [ ] **Day 11**: **uFTB (Micro Fetch Target Buffer)**: Implement Stage-0 (`s0_uFTB`) zero-bubble / 1-cycle fast target predictor array (matching XiangShan Nanhu/Kunminghu parity). *(See [Day 11 uFTB Implementation & Verification Plan](./day11_uftb.md))*.
- [ ] **Day 12**: **Branch Checkpointing & State Recovery**: Store unified GHR/PHR/RAS snapshots in the FTQ for **1-cycle rollback** on mispredicts. *(See [Day 12 Branch Checkpointing Plan](./day12_branch_checkpointing.md))*.
- **Detailed Plan**: To achieve true XiangShan parity, the BPU predictor stack comprises **uFTB**, **FTB**, **TAGE**, **ITTAGE**, **SC**, and **RAS**. We will first build a dedicated **Return Address Stack (RAS)** to predict function returns (`ret`), followed by an ultra-fast Stage-0 **uFTB (Micro-FTB)** to eliminate fetch bubble latency. Finally, we will implement unified **Branch Checkpointing**, storing GHR, PHR, and RAS snapshots in the Fetch Target Queue (FTQ). If a misprediction occurs, the backend restores exact predictor states in a single clock cycle.
- **XiangShan Study**: [Bpu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Bpu.scala), [RAS.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/RAS.scala), [uFTB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/uFTB.scala)

## Day 13-17: Memory Interface (Caches & uOp Cache)
- [ ] **Day 13**: **uOp Cache (L0 Decoded Cache)**: Implement decoded instruction cache to bypass decoders and increase fetch bandwidth (XiangShan parity).
- [ ] **Day 14-15**: **Instruction Cache (I-Cache)**: Replace the bypass model with a real L1-I with refill logic.
- [ ] **Day 16-17**: **Data Cache (D-Cache) & MSHRs**: Non-blocking L1-D with Miss Status Handling Registers (MSHRs) for true hit-under-miss support.
- **Detailed Plan**: We will rip out the simple mock instruction memory and build a genuine, Set-Associative Level-1 Instruction Cache (L1-I) with cache-line refill logic from the L2/Main Memory. To further decouple fetch from decode, we will introduce a uOp Cache (L0 Decoded Cache) that caches already-decoded micro-operations, saving significant decoding power and increasing frontend bandwidth. For the Data Cache (L1-D), we will implement a non-blocking architecture using Miss Status Handling Registers (MSHRs). MSHRs allow the cache to continue serving new memory requests even while waiting for a previous cache miss to be fetched from main memory, unlocking the true potential of out-of-order execution (Hit-Under-Miss).
- **XiangShan Study**: [icache/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/icache/)

## Day 18-20: Speculative State & Resilience
- [ ] **Day 18-19**: **Speculative RAS Buffers**: Prevent Return Address Stack corruption on wrong-path calls.
- [ ] **Day 20**: **BPU Composer**: Integrate all predictors into a single tournament-style BPU.
- **Detailed Plan**: When the core executes speculatively on the wrong path of a branch, it might execute `call` and `return` instructions that corrupt the Return Address Stack (RAS). We will build speculative RAS buffers to isolate these changes, applying them to the architectural RAS only when the branch commits. Finally, we will build a BPU Composer—a meta-predictor that dynamically learns whether the TAGE predictor or the Neural Predictor (SC) is more accurate for a specific branch, intelligently multiplexing between them to achieve peak IPC.

---

## Future Scope: Multi-Branch Support
- Parallelize `PreDecode` to identify multiple branches per fetch packet (Kunminghu-style), allowing the frontend to predict past multiple sequential branches in a single cycle.

## Future Scope: TAGE & ITTAGE XiangShan Parity Upgrades
- [ ] **TAGE-L (Loop Predictor)**: Add a dedicated loop prediction array (matching XiangShan's loop predictor) to track loops with long, fixed iteration counts that geometric tables fail to capture.
- [ ] **Circular Shift Registers (CSRs)**: Transition from combinatorial/Scala folding of the global history register to hardware-efficient circular shift registers (CSRs) to reduce critical path wire delay.
- [ ] **Pipelined Multi-Cycle BPU Lookup**: Redesign lookup logic to span 2–3 pipeline stages (allowing larger tables to be queried without limiting clock frequency).
- [ ] **Table Sizing Expansion**: Scale table capacity up to 1024–4096 entries per table to match the footprint of XiangShan Nanhu/Kunminghu configurations.

## Future Phase: Comprehensive BPU Testing
- Once the Reorder Buffer (ROB) and multi-branch support (PreDecode upgrades) are completed, rigorous verification of TAGE and ITTAGE will commence.
- **Reference Test Files for Verification**:
  - `programs/tage_test_trace.xlsx` (golden trace with colors)
  - `programs/tage_test_trace_gemini.xlsx` (AI generated trace)
  - `programs/tage_test.xlsx` (program definition)
  - `programs/assembly/riscv-interpreter/index.html` (Golden trace generator)
  - `programs/html/tage_calculator.html` (TAGE/ITTAGE calculator tool)
