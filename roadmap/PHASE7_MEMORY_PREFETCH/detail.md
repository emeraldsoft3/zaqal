# Phase 7.5: Memory Prefetching (L1 Hidden Power)

To achieve XiangShan-level performance, the memory system must be aggressive in pulling data before it is explicitly requested.

## Goal: Intelligent Data Fetching & Cache Optimization

## Day 1-2: Stride Prefetcher
- [ ] Detect constant-stride access patterns (e.g., array traversal).
- **XiangShan Study**: [L1StridePrefetcher.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/L1StridePrefetcher.scala) - *See how they track memory strides.*

## Day 3-5: Spatial Memory Streaming (SMS)
- [ ] Implement spatial pattern tracking for L1D to handle irregular but spatially-local accesses.
- **XiangShan Study**: [SMSPrefetcher.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/SMSPrefetcher.scala) - *Deep dive into spatial prefetching.*

## Day 6: Stream Prefetcher
- [ ] Implement simple stream-based prefetching for sequential accesses.
- **XiangShan Study**: [L1StreamPrefetcher.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/L1StreamPrefetcher.scala) - *Study the stream prefetcher.*

## Day 7-8: Frontend Data Prefetcher (FDP)
- [ ] Use branch prediction signals to prefetch data for future instructions.
- **XiangShan Study**: [FDP.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/FDP.scala) - *See how BPU signals drive memory prefetching.*

## Day 9: Prefetch Interface & L1-L2 Coordination
- [ ] Ensure prefetchers communicate correctly with the memory hierarchy.
- **XiangShan Study**: [L1PrefetchInterface.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/L1PrefetchInterface.scala) - *Interface design between prefetchers and caches.*

## Day 10: Prefetch Monitoring & Throttling
- [ ] Monitor prefetch accuracy and throttle if causing bus congestion.
- **XiangShan Study**: [PrefetcherMonitor.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/prefetch/PrefetcherMonitor.scala) - *How they monitor prefetch effectiveness.*
