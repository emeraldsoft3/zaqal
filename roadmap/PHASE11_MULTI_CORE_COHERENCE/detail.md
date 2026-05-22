# Phase 11: Multi-Hart & Coherence

This phase focuses on scaling Zaqal from a single-core processor to a multi-core System-on-Chip (SoC) with cache coherence.

## Day 1-3: TileLink/CHI Bus Implementation
- [ ] Implement a coherent bus protocol (inspired by XiangShan's use of TileLink or CHI).
- [ ] Support for Acquire/Release and Probe/Grant transactions.
- **Detailed Plan**: Scaling to multiple cores requires a specialized interconnect that supports caching. Standard AXI4 is insufficient because it lacks coherence primitives. We will transition the top-level core interface to a coherent protocol like TileLink or AMBA CHI. This requires implementing a complex set of channels to handle memory requests (Acquire), data writebacks (Release), and most importantly, external coherence invalidations sent from the bus back to the core (Probes).

## Day 4-7: L2 & L3 Cache Coherence
- [ ] Implement an Inclusive L2 cache with hardware coherence (MESI/MOESI).
- [ ] Implement a shared L3 cache for multi-cluster support.
- **Detailed Plan**: When multiple cores read and write to the same memory, they must stay perfectly synchronized. We will build an inclusive L2 Cache that acts as the coherence serialization point. We will implement the MESI (Modified, Exclusive, Shared, Invalid) or MOESI hardware directory protocol. The L2 cache will track which L1 caches hold specific memory lines. If Core A writes to a variable that Core B is holding, the L2 cache will automatically generate Probe transactions to invalidate the stale data in Core B's L1 cache, ensuring strict cache coherence without software intervention.

## Day 8-12: Multi-Hart Boot & Synchronization
- [ ] Implement Hart ID discovery and multi-core reset handling.
- [ ] Verify atomicity (LR/SC and AMOs) across multiple cores using co-simulation.
- **Detailed Plan**: We will configure the system to instantiate multiple Zaqal harts (hardware threads/cores) on the same SoC. Each core must be assigned a unique `mhartid` so the operating system can distinguish them. We will implement advanced Atomic Memory Operations (AMOs) like Load-Reserved/Store-Conditional (LR/SC) and Atomic Fetch-and-Add. These are critical for software mutexes and spinlocks. The coherent interconnect must enforce strict atomicity across all cores, locking memory lines during updates to guarantee thread-safe synchronization.

## Day 13+: Memory Consistency Verification
- [ ] Use Litmus tests to verify the RISC-V Weak Memory Ordering (RVWMO) model.
- [ ] Benchmark multi-threaded workloads (e.g., Pthread, OpenMP).
- **Detailed Plan**: Multi-core architectures are notoriously difficult to verify due to complex memory reordering. RISC-V uses the Weak Memory Ordering (RVWMO) model. We will run rigorous "Litmus Tests"—tiny programs specifically designed to stress-test memory consistency barriers (FENCE instructions) and coherence races. Once the memory consistency is mathematically proven correct, we will boot SMP (Symmetric Multi-Processing) Linux and run multi-threaded workloads like OpenMP benchmarks to validate the raw multi-core scaling performance of the Zaqal SoC.
