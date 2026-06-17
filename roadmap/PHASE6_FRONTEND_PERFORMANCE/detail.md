# Phase 6: Front-end Performance (Neural BPU & Caches)

To achieve true XiangShan-level performance, the front-end must provide near-perfect instruction flow while decoupling timing from the rest of the core.

## Goal: Intelligent Instruction Flow & High Frequency
- **Neural Prediction**: Perceptron-based guided branching.
- **Micro-Architecture**: 2-stage BPU with unified pointer-based skidding.
- **Timing**: Clean module interfaces using `zaqal.utility.SkidBuffer`.

---

## Day 1-5: The Predictor Array (TAGE & FTB)
- [ ] **Day 1-2**: **FTB (Fetch Target Buffer)**: Store targets and prediction metadata.
- [ ] **Day 3-5**: **TAGE & ITTAGE**: Implement tagged geometric predictors for long-history patterns.
- **Detailed Plan**: A simple branch predictor is insufficient for deep superscalar cores. We will build a Fetch Target Buffer (FTB) to cache branch target addresses and instruction boundaries. Alongside it, we will implement the TAGE (TAgged GEometric) predictor, the gold standard in modern branch prediction. TAGE uses multiple tables indexed by geometrically increasing lengths of global branch history, allowing it to predict highly complex, long-correlating branch patterns with extreme accuracy.
- **XiangShan Study**: [FTB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FTB.scala)

## Day 6-10: Neural BPU & Checkpointing (XiangShan-Parity)
- [ ] **Day 6-8**: **Neural BPU (The Perceptron)**: Table learning for data-dependent branches.
- [ ] **Day 9**: **Advanced Pointer Management**: Unify FTQ and SkidBuffer systems into a single elastic flow.
- [ ] **Day 10**: **Branch Checkpointing**: Store GHR/RAS snapshots in the FTQ for **1-cycle rollback** on mispredicts.
- **Detailed Plan**: To complement TAGE, we will implement a Neural Perceptron predictor. Perceptrons excel at predicting branches that have complex, linear data dependencies rather than just historical correlations. The BPU will become a decoupled, 2-stage pipeline. To protect this massive predictive state, we will implement Branch Checkpointing, storing snapshots of the Global History Register (GHR) and Return Address Stack (RAS) in the Fetch Target Queue (FTQ). If a misprediction occurs, we can restore the exact predictor state in a single clock cycle, avoiding massive penalty delays.
- **XiangShan Study**: [Bpu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Bpu.scala)

## Day 11-15: Memory Interface (Caches & uOp Cache)
- [ ] **Day 11**: **uOp Cache (L0 Decoded Cache)**: Implement decoded instruction cache to bypass decoders and increase fetch bandwidth (XiangShan parity).
- [ ] **Day 12-13**: **Instruction Cache (I-Cache)**: Replace the bypass model with a real L1-I with refill logic.
- [ ] **Day 14-15**: **Data Cache (D-Cache) & MSHRs**: Non-blocking L1-D with Miss Status Handling Registers (MSHRs) for true hit-under-miss support.
- **Detailed Plan**: We will rip out the simple mock instruction memory and build a genuine, Set-Associative Level-1 Instruction Cache (L1-I) with cache-line refill logic from the L2/Main Memory. To further decouple fetch from decode, we will introduce a uOp Cache (L0 Decoded Cache) that caches already-decoded micro-operations, saving significant decoding power and increasing frontend bandwidth. For the Data Cache (L1-D), we will implement a non-blocking architecture using Miss Status Handling Registers (MSHRs). MSHRs allow the cache to continue serving new memory requests even while waiting for a previous cache miss to be fetched from main memory, unlocking the true potential of out-of-order execution (Hit-Under-Miss).
- **XiangShan Study**: [icache/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/icache/)

## Day 16-20: Speculative State & Resilience
- [ ] **Day 16-18**: **Speculative RAS Buffers**: Prevent Return Address Stack corruption on wrong-path calls.
- [ ] **Day 19-20**: **BPU Composer**: Integrate all predictors into a single tournament-style BPU.
- **Detailed Plan**: When the core executes speculatively on the wrong path of a branch, it might execute `call` and `return` instructions that corrupt the Return Address Stack (RAS). We will build speculative RAS buffers to isolate these changes, applying them to the architectural RAS only when the branch commits. Finally, we will build a BPU Composer—a meta-predictor that dynamically learns whether the TAGE predictor or the Neural predictor is more accurate for a specific branch, intelligently multiplexing between them to achieve peak IPC.

---

## Future Scope: Multi-Branch Support
- Parallelize `PreDecode` to identify multiple branches per fetch packet (Kunminghu-style), allowing the frontend to predict past multiple sequential branches in a single cycle.
