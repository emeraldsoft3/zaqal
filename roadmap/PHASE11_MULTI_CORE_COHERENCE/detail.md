# Phase 11: Multi-Hart & Coherence

This phase focuses on scaling Zaqal from a single-core processor to a multi-core System-on-Chip (SoC) with cache coherence.

## Day 1-3: TileLink/CHI Bus Implementation
- [ ] Implement a coherent bus protocol (inspired by XiangShan's use of TileLink or CHI).
- [ ] Support for Acquire/Release and Probe/Grant transactions.

## Day 4-7: L2 & L3 Cache Coherence
- [ ] Implement an Inclusive L2 cache with hardware coherence (MESI/MOESI).
- [ ] Implement a shared L3 cache for multi-cluster support.

## Day 8-12: Multi-Hart Boot & Synchronization
- [ ] Implement Hart ID discovery and multi-core reset handling.
- [ ] Verify atomicity (LR/SC and AMOs) across multiple cores using co-simulation.

## Day 13+: Memory Consistency Verification
- [ ] Use Litmus tests to verify the RISC-V Weak Memory Ordering (RVWMO) model.
- [ ] Benchmark multi-threaded workloads (e.g., Pthread, OpenMP).
