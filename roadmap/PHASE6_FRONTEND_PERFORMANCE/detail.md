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
- **XiangShan Study**: [FTB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FTB.scala)

## Day 6-10: Neural BPU & Checkpointing (XiangShan-Parity)
- [ ] **Day 6-8**: **Neural BPU (The Perceptron)**: Table learning for data-dependent branches.
- [ ] **Day 9**: **Advanced Pointer Management**: Unify FTQ and SkidBuffer systems into a single elastic flow.
- [ ] **Day 10**: **Branch Checkpointing**: Store GHR/RAS snapshots in the FTQ for **1-cycle rollback** on mispredicts.
- **XiangShan Study**: [Bpu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Bpu.scala)

## Day 11-15: Memory Interface (Caches)
- [ ] **Day 11-13**: **Instruction Cache (I-Cache)**: Replace the bypass model with a real L1-I with refill logic.
- [ ] **Day 14-15**: **Data Cache (D-Cache) & MSHRs**: Non-blocking L1-D with Miss Status Handling Registers (MSHRs) for true hit-under-miss support.
- **XiangShan Study**: [icache/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/icache/)

## Day 16-20: Speculative State & Resilience
- [ ] **Day 16-18**: **Speculative RAS Buffers**: Prevent Return Address Stack corruption on wrong-path calls.
- [ ] **Day 19-20**: **BPU Composer**: Integrate all predictors into a single tournament-style BPU.

---

## Future Scope: Multi-Branch Support
- Parallelize `PreDecode` to identify multiple branches per fetch packet (Kunminghu-style).
