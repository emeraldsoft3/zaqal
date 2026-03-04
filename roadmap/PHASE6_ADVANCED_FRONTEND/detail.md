# Phase 6: Advanced Frontend (XiangShan BPU)

In a high-end core, the Frontend is a "Branch Prediction Factory." We will implement the multiple layers used by XiangShan.

## Week 1: Target Prediction (FTB & RAS)
- [ ] **Fetch Target Buffer (FTB)**: Replacing traditional BTB with a more powerful target buffer capable of predicting multiple branches in a single fetch packet.
- [ ] **Return Address Stack (RAS)**: A LIFO stack for function returns (100% accuracy for call/ret).
- [ ] **Indirect Target Predictor**: For `JALR` instructions where the target changes dynamically.

## Week 2: Conditional Prediction (TAGE)
- [ ] **Bimodal Predictor**: The baseline.
- [ ] **TAGE Predictor**: (TAgged GEometric) - The gold standard of branch prediction.
- [ ] **Statistical Corrector (SC)**: A neural-network-like layer that fixes common TAGE mistakes.
- [ ] **ITTAGE**: Specifically for indirect branches.

## Week 3: I-Cache & Fetch Logic
- [ ] **Pre-decoder & Instruction Fold**: Identifying branches early and "folding" multiple jumps/branches in a single cycle.
- [ ] **Instruction Fetch Queue (IFQ)**: Decoupling IF from IBUF.
- [ ] **L1I Pre-fetcher**: Guessing the next line of code before it's even asked for.
- [ ] **Banked I-Cache**: Delivering 16-32 bytes per cycle to the IBuffer.
