# Zaqal Processor: Project Roadmap

Welcome to the Zaqal processor project. This roadmap provides a day-by-day technical guide to building a high-performance RISC-V core from scratch.

## Project Vision
To build a **Kunminghu-inspired**, superscalar, high-frequency RISC-V processor that is logically correct and performance-optimized.

---

## Technical Stages

| Phase | Focus | Status | Detail Link |
| :--- | :--- | :--- | :--- |
| **0** | **Bootstrap** | [x] Completed | - |
| **1** | **Base Integer ISA** | [/] In Progress | [Phase 1 Detail](phase1_integer_isa.md) |
| **2** | **Simple Branching** | [ ] Planned | [Phase 2 Detail](phase2_branching.md) |
| **3** | **Memory & FPU** | [ ] Planned | [Phase 3 Detail](phase3_memory_extensions.md) |
| **4** | **Superscalar Transition** | [ ] Planned | [Phase 4 Detail](phase4_superscalar.md) |
| **5** | **Structural Optimization** | [ ] Planned | [Phase 5 Detail](phase5_structural_optimization.md) |
| **6** | **Caches & Advanced BPU** | [ ] Planned | [Phase 6 Detail](phase6_advanced_frontend.md) |
| **8** | **Linux & Privileged** | [ ] Planned | [Phase 8 Detail](PHASE8_SYSTEM_PRIVILEGE/detail.md) |

---

## Software Compatibility Goals
Zaqal is designed to be a "real-world" processor capable of running:
- **Linux Kernel**: Booting standard RISC-V Linux.
- **Modern Applications**: Running software compiled for RV64GC.
- **Windows Apps**: Compatibility via Wine on Linux.

---

## Why we need a BPU?
The BPU is required because as the processor becomes **wider** (fetching more instructions per cycle) and **deeper** (adding more pipeline registers for higher frequency):
1.  **Instruction Delivery**: If we fetch 8 instructions per cycle but have a 10-cycle bubble, we lose **80** instruction slots.
2.  **Pipelining**: High-frequency circuits need many registers between Fetch and Execute. Without a BPU, the Fetcher would have to stop every time it sees a branch until the branch is fully executed, causing a huge "bubble."
3.  **Speculative Execution**: The BPU allows the processor to "bet" on an outcome and keep the pipeline full. A high-accuracy BPU is what distinguishes an "Agile" toy from a high-performance engine like XiangShan.
