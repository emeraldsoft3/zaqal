# Phase 7.5: Memory Prefetching (L1 Hidden Power)

To achieve XiangShan-level performance, the memory system must be aggressive in pulling data before it is explicitly requested.

## Week 1: Spatial Memory Streaming (SMS)
- [ ] **SMS Prefetcher**: Implementing spatial pattern tracking for L1D to handle irregular but spatially-local accesses.
- [ ] **Stride Prefetcher**: Detecting constant-stride access patterns (e.g., array traversal).

## Week 2: Frontend & L2 Interaction
- [ ] **FDP (Frontend Data Prefetcher)**: Using branch prediction signals to prefetch data for future instructions.
- [ ] **L1-L2 Prefetch Interface**: Ensuring the prefetchers don't clog the main memory bus.
- [ ] **Prefetch Throttling**: Dynamic adjustment of prefetch aggressiveness based on cache miss rates.
