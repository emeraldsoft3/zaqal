# Design Decision: Inclusive vs. Exclusive L2 Caching

As Zaqal integrates massive Level 1 (L1) and Level 2 (L2) caches, a pivotal design question arises about how data duplicated across these layers is physically managed. This dictates the core's latency profiles and evictions on cache misses.

---

## Option 1: Strictly Inclusive L2/L3 Architecture
If a 64-byte block of memory is downloaded into the L1 cache, it **must** also be stored identically in the L2 cache simultaneously. 

**Used by**: Legacy Intel architectures (Nehalem, Haswell), XiangShan default parameters.

- **How it works**: The L2 physically guarantees that any data owned by an inner core L1 is mirrored inside the larger L2.
- **The Benefit (Pros)**: Cache coherency across 8+ cores is ridiculously easy. When Core 0 wants to check if Core 1 modified a variable, Core 0 simply pings the giant Shared L2. If the L2 says "No, I don't have it," it is mathematically impossible for Core 1's L1 to have it. Zero internal snoop traffic.
- **The Cost (Cons)**: Severe capacity waste. If you have 1MB of L2 and 512KB of L1, half of your L2 is completely redundantly storing the exact same data currently inside your L1!

---

## Option 2: Strictly Exclusive L2 Architecture
If a block is in the L1 cache, it is physically wiped/evicted from the L2 cache entirely.

**Used by**: AMD Zen, ARM processors.

- **How it works**: The L1 and L2 act as a single contiguous pool. When data is requested, it migrates completely out of the L2 and ascends up into the L1. When it is done (evicted), it sinks back into the L2.
- **The Benefit (Pros)**: Ultimate maximum capacity utilization. Every single byte of SRAM on your silicon is storing unique, distinct data.
- **The Cost (Cons)**: Horrifically painful multi-core snooping. Because the L2 doesn't technically know exactly what arbitrary 512KB of data is currently parked in the L1, cache coherency checks force the hardware to directly query the inner L1 tags constantly.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will mirror **Option 1: Strictly Inclusive L2/L3**. The complexity of verifying an Exclusive cache's snooping coherency across multiple cores in Chisel is staggering. XiangShan prefers slightly wasted cache capacity in exchange for brutally simple multi-core directory coherency, which inherently scales better for massive Server SoC environments.

---

## Recommended Reading / Seminal Papers
- **"Exclusive versus Inclusive Cache Hierarchies" (Jaleel et al., 2010)**: Examines the tipping point algorithms for when chip architects choose exclusion over inclusion based on core counts and working set sizes.
