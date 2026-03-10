# Zaqal Project Roadmap: The AI-Native (Kunminghu-Based) Core

This roadmap outlines the journey to transform Zaqal from a simple prototype into a world-class, **AI-Native**, superscalar, out-of-order RISC-V processor.

## Architectural Philosophy
- **Phase 1-3**: Functional Core (1-wide, in-order, correct).
- **Phase 4-5**: High Frequency & Superscalar (1-wide to 6-wide, pipelined).
- **Phase 6-7**: Performance Engine (**Neural BPU**, Out-of-order, Advanced Caches).
- **Phase 8-10**: AI-Native Power (**AMX**, MMU, Vectors, Linux Boot).
- **Unique Vision**: **Intelligence in the Pipeline** (Neural-guided prediction and native 2D Matrix compute).

## Detailed Roadmap Phases

| Phase | Title | Est. Time | Key Goal | Study Reference (XiangShan) |
| :--- | :--- | :--- | :--- | :--- |
| **[Phase 1](./PHASE1_INTEGER_ISA/detail.md)** | **Base Integer ALU** | 1 Week (4 Days) | Mastery of 64-bit integer compute. | `backend/fu/Alu.scala` |
| **[Phase 2](./PHASE2_BRANCHING_MISPREDICT/detail.md)** | **Branching & Mispredict** | 1 Week (4 Days) | Control flow & pipeline flushing. | `backend/fu/Branch.scala` |
| **[Phase 3](./PHASE3_MEMORY_EXTENSIONS/detail.md)** | **Memory, Bitmanip & FPU** | 2 Weeks (10 Days) | Load/Store, B-Ext, and **Floating Point (F/D)**. | `backend/fu/LSU.scala`, `fpu/` |
| **[Phase 4](./PHASE4_SUPERSCALAR_DISPATCH/detail.md)** | **Superscalar Dispatch** | 3 Weeks (15 Days) | 1-wide to 6-wide transition. | `backend/decode/Dispatch.scala` |
| **[Phase 5](./PHASE5_TIMING_OPTIMIZATION/detail.md)** | **Timing & Pipelining** | 2 Weeks (10 Days) | High-frequency logic & stages. | `backend/decode/DecodeStage.scala` |
| **[Phase 6](./PHASE6_ADVANCED_FRONTEND/detail.md)** | **Advanced Frontend** | 3 Weeks (15 Days) | **Neural BPU (Perceptron)** & FTB. | `frontend/BPU.scala`, `FTB.scala` |
| **[Phase 7](./PHASE7_OUT_OF_ORDER/detail.md)** | **Out-of-Order Engine** | 4 Weeks (20 Days) | ROB, Register Renaming, Issue. | `backend/robuffer/ROB.scala` |
| **[Phase 7.5](./PHASE7_MEMORY_PREFETCH/detail.md)** | **Memory Prefetching** | 2 Weeks (10 Days) | **SMS** and Stride Prefetchers. | `mem/Prefetch.scala` |
| **[Phase 8](./PHASE8_SYSTEM_PRIVILEGE/detail.md)** | **System, Privilege & MMU** | 3 Weeks (15 Days) | **Linux Boot Readiness** (Supervisor, MMU, PLIC). | `backend/fu/CSR.scala` |
| **[Phase 9](./PHASE9_VECTOR_ISA/detail.md)** | **AI & Vector ISA (AMX)** | 4 Weeks (20 Days) | **Matrix (AMX)** and Vector Units. | `backend/fu/vector/` |
| **[Phase 10](./PHASE10_VERIFICATION_SOC/detail.md)** | **Verification & SoC** | Ongoing | Difftest, Linux, and Tapeout-ready. | `XSTile.scala` |

---

## Software Compatibility Goals
To ensure Zaqal is a "real-world" processor, we target:
- [ ] **Linux Boot**: Full support for RV64GC (G = IMAFD) with Supervisor mode and Sv39/Sv48 MMU.
- [ ] **GNU Toolchain**: Ability to run code compiled by `gcc` and `llvm` without emulation.
- [ ] **Distro Support**: Aiming for Debian/Fedora RISC-V ports.
- [ ] **Windows App Compatibility**: Running Windows-software via **Wine** on RISC-V Linux.

## The "XiangShan" Checklist
To be truly "XiangShan-like", we must eventually implement:
- [ ] **Multi-stage BPU** (Bimodal -> GShare -> TAGE -> ITTAGE).
- [ ] **Instruction Buffer (IBuffer)** with banked parallel dequeue.
- [ ] **Rename Stage** (Map Table + Free List).
- [ ] **Reorder Buffer (ROB)** for in-order commitment.
- [ ] **Distributed Issue Queues** (Separate queues for ALU, MEM, etc.).
- [ ] **Advanced Load/Store Unit** (Memory Disambiguation, Speculative Loads).
