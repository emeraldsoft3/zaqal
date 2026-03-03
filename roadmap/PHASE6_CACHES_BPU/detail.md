# Phase 6: Caches & Advanced BPU (The Performance Finish)

The final stage is all about minimizing stalls due to memory latency and branch uncertainty.

## Goal: High-Performance Memory & Prediction

## Day 21-23: Instruction Cache (I-Cache)
- [ ] Replace the simple "Memory Model" with a real L1 I-Cache.
- [ ] Implement "Refill" logic (fetching a 16rd line from memory on a miss).

## Day 24-26: Data Cache (D-Cache)
- [ ] Implement a non-blocking D-Cache.
- [ ] Support "Hit-under-Miss" (keep executing if a Load misses, as long as independent instructions are available).

## Day 27-30: Advanced Branch Predictor (TAGE/GShare)
- [ ] Replace the basic BPU with a global history-based predictor.
- [ ] Implement a **Branch Target Buffer (BTB)** to avoid the 1-cycle decode delay for targets.
- [ ] Implement a **Return Address Stack (RAS)** to predict function returns with 100% accuracy.
