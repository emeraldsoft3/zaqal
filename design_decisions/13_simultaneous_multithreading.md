# Design Decision: Simultaneous Multithreading (SMT / HyperThreading)

As transistor density scales, one Physical Core is rarely fed enough instructions by a single thread to utilize 100% of its resources (e.g., 6 ALUs, 3 Load Ports). SMT allows a second independent Operating System Thread to pretend to execute on the same core simultaneously.

---

## Option 1: Strictly Partitioned Resources
The physical core statically divides specific critical resources perfectly in half between Thread 0 (T0) and Thread 1 (T1).

**Used by**: IBM POWER9, early Intel HyperThreading (Pentium 4).

- **How it works**: A 200-entry Reorder Buffer (ROB) is permanently severed: T0 gets 100 entries, and T1 gets 100 entries. A 128-entry Load Queue gives 64 entries to T0 and 64 to T1.
- **The Benefit (Pros)**: Zero Cross-Thread Quality-of-Service (QoS) degradation. Thread 0 can go utterly rogue (infinite cache misses, massive memory stalls) and it mathematically cannot stall Thread 1, because Thread 1 completely owns its own guaranteed 100 ROB slots.
- **The Cost (Cons)**: Terrible Single-Thread performance regression. If you turn off SMT (or T1 is asleep), Thread 0 is trapped with only half the core's resources (a 100-entry ROB), drastically crippling its maximum IPC.

---

## Option 2: Competitively Shared Resources (Watermark Thresholding)
The physical core allows both threads to violently compete for the entire 200-entry ROB at the exact same time.

**Used by**: Intel Core (Skylake/Raptor Lake), AMD Zen, XiangShan.

- **How it works**: T0 and T1 throw instructions into the single 200-entry pool. If T0 generates 180 instructions and T1 generates 20 instructions, the hardware dynamically allocates them on the fly.
- **The Benefit (Pros)**: The gold standard for performance. If T1 is sleeping, T0 seamlessly consumes 100% of the core's potential, running exactly as fast as a non-SMT processor. No resources are artificially wasted.
- **The Cost (Cons)**: Security nightmares (e.g., Spectre, Meltdown, side-channel attacks). A rogue T0 thread can intentionally fill the physical register file or load queues, artificially starving T1's timing to steal cryptographic keys.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will explicitly implement **Option 2: Competitively Shared Resources** when and if we eventually approach SMT architectures in Phase 9+. High-end RISC-V cores strongly prefer competitive sharing to remain competitive in Single-Thread rendering benchmarks (Geekbench 6). SMT is incredibly difficult to formally verify, so Zaqal will remain strictly Single-Threaded (1T) for Phases 1 through 8.

---

## Recommended Reading / Seminal Papers
- **"Simultaneous Multithreading: Maximizing On-Chip Resource Utilization" (Tullsen, Eggers, Levy, 1995)**: The origin point of SMT architecture. It proved that interleaving two threads dramatically boosts ALUD execution bandwidth.
- **"Performance Evaluation of Intel Hyper-Threading Core" (Marr et al., 2002)**: The specific technical implementation data on how partitioning vs. sharing ROBs actually translates to IPC.
