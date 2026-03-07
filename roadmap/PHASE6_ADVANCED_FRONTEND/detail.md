# Phase 6: Advanced AI-Frontend (Beyond TAGE)

To feed a 6-wide OoO machine, we need near-perfect branch prediction. Zaqal will use a hybrid approach.

## Goal: Neural-Assisted Branch Prediction

## Day 1-3: FTB (Fetch Target Buffer) Refinement
- [ ] Implement the FTB to store branch targets and prediction metadata.
- **XiangShan Study**: [FTB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/FTB.scala)

## Day 4-8: TAGE & ITTAGE Predictors
- [ ] Implement the base TAGE (Tagged Geometric) predictor.
- [ ] Add ITTAGE for indirect branch targets.
- **XiangShan Study**: [Tage.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Tage.scala)

## Day 9-13: Neural BPU (The Perceptron)
- [ ] **Implementation**: Build a Perceptron table that learns branch history weights.
- [ ] **Switchable Logic**: Implement a "mode bit" in a CSR to toggle between TAGE and Perceptron or use them in a tournament style.
- **Goal**: Superior prediction of data-dependent patterns.

## Day 14-15: BPU Composer & Performance Tuning
- [ ] Integrate all predictors into a single BPU Composer.
- [ ] Monitor accuracy and mispredict penalties.
- **XiangShan Study**: [Bpu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/Bpu.scala)

## Day 12: Pre-decoder & Instruction Fusion
- [ ] Identify branches early and fuse instructions where possible.
- **XiangShan Study**: [PreDecode.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/PreDecode.scala) - *Look for branch identification logic.*

## Day 13: Decoupled IF/IBUF (IFQ)
- [ ] Redesign the fetch queue to decouple I-Cache from the IBuffer.
- **Goal**: Allow fetch to continue even if the backend is stalled.

## Day 14-15: Banked I-Cache & Prefetching
- [ ] Implement a banked instruction cache for high bandwidth.
- **XiangShan Study**: [icache/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/frontend/icache/) - *Explore the I-Cache implementation.*
