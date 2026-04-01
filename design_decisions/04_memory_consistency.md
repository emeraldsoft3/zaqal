# Design Decision: Memory Consistency & Ordering

How the CPU hardware officially enforces or relaxes the sequence of load/store operations reaching the Data Cache and main memory hierarchy.

---

## Option 1: Weak Memory Ordering (WMO)
The hardware is given immense freedom. As long as the ultimate execution outcome of a single thread is coherent, the CPU can freely rearrange Loads and Stores out of their original visual program sequence to maximize pipeline throughput.

**Used by**: RISC-V Architecture (RVWMO), ARM (AArch64 WMO), Apple Silicon.

- **How it works**: The CPU blasts Memory ops outward. If a programmer specifically demands absolute sequence logic across multiple cores or threads, they must manually insert a "Memory Barrier" or "FENCE" instruction to explicitly throttle the pipeline.
- **The Benefit (Pros)**: Maximizes sheer, unbridled performance. The Out-of-Order Engine never stalls waiting for a slow store if a fast load is ready.
- **The Cost (Cons)**: Tremendously difficult for multithreaded debugging. Code written poorly can behave inexplicably wildly because the hardware reorders assumptions under the hood.

---

## Option 2: Total Store Ordering (TSO)
The hardware takes on strict responsibilities, enforcing that the outside world observes stores exactly in the order the program executed them. 

**Used by**: Intel x86, AMD x86.

- **How it works**: The CPU guarantees that stores appear globally in sequence. A load can sneak ahead of a store, but stores can never sneak past each other.
- **The Benefit (Pros)**: Supremely programmer-friendly. Extremely robust, legacy-compatible behavior. Fewer "weird" concurrency bugs occur in high-level software stacks.
- **The Cost (Cons)**: Inherently sacrifices maximum theoretical performance. The hardware pipeline must frequently stall or throttle itself just to enforce external ordering guarantees.

---

## Recommendation for Zaqal

> [!TIP]
> **RISC-V WMO Compliance**
> Since Zaqal is inherently a RISC-V core (RV64I), it is architecturally bound to implement **Option 1: Weak Ordering (RVWMO)**. 
> *However*, high-end processors like XiangShan frequently leverage a trick: they utilize **Age-based Load/Store Queues (LSQ)** to execute instructions internally with a quasi-TSO strictness, but relax to WMO externally. This provides blistering performance without horrific internal pipeline bugs. Zaqal will mirror this LSQ approach in Phase 7.

---

## Recommended Reading / Seminal Papers
- **"Memory Consistency Models: A Tutorial" (Adve & Gharachorloo, 1996)**: The definitive, legendary primer on how Memory Ordering theoretically functions and why weak-ordering scales infinitely better than strict TSO.
- **RISC-V Unprivileged ISA Specification**: Specifically the chapter on RVWMO (RISC-V Weak Memory Ordering) memory barrier semantics.
