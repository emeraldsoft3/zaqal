# Zaqal Project Roadmap: The AI-Native (Kunminghu-Based) Core

This roadmap outlines the journey to transform Zaqal from a simple prototype into a world-class, **AI-Native**, superscalar, out-of-order RISC-V processor.

## Architectural Philosophy
- **Phase 1-3**: Functional Core (1-wide, in-order, correct).
- **Phase 4-5**: High Frequency & Superscalar (1-wide to 6-wide, pipelined).
- **Phase 6-7**: Performance Engine (**Neural BPU**, Out-of-order, Advanced Caches).
- **Phase 8-10**: AI-Native Power (**AMX**, MMU, Vectors, Linux Boot).
- **Unique Vision**: **Intelligence in the Pipeline** (Neural-guided prediction and native 2D Matrix compute).

## Detailed Roadmap Phases

| Phase | Title | Schedule | Key Goal | Study Reference |
| :--- | :--- | :--- | :--- | :--- |
| **[Phase 1](./PHASE1_INTEGER_ISA/detail.md)** | **Base Integer ALU** | Days 1-4 | **[COMPLETE]** Mastery of RV64I calculations. | `backend/fu/Alu.scala` |
| **[Phase 2](./PHASE2_BRANCHING_MISPREDICT/detail.md)** | **Branching & Mispredict** | Days 5-10 | [/] Control Flow & Pipeline Integrity. | `backend/fu/Branch.scala` |
| **[Phase 3](./PHASE3_MEMORY_EXTENSIONS/detail.md)** | **Memory & Extensions** | Days 11-32 | Memory/FPU Mastery (RV64G/Bitmanip). | `backend/fu/LSU.scala` |
| **[Phase 4](./PHASE4_SUPERSCALAR_DISPATCH/detail.md)** | **Superscalar Dispatch** | Days 33-50 | 1-wide to 6-wide (Mapping/RAT). | `backend/decode/Dispatch.scala` |
| **[Phase 5](./PHASE5_TIMING_OPTIMIZATION/detail.md)** | **Timing & Pipelining** | Days 51-65 | High Frequency Optimization. | `backend/decode/DecodeStage.scala` |
| **[Phase 6](./PHASE6_ADVANCED_FRONTEND/detail.md)** | **Advanced Frontend** | Days 66-85 | **Neural BPU (Perceptron)** & FTB. | `frontend/BPU.scala` |
| **[Phase 7](./PHASE7_OUT_OF_ORDER/detail.md)** | **Out-of-Order Engine** | Days 86-110 | ROB, Register Renaming, Issue. | `backend/robuffer/ROB.scala` |
| **[Phase 8](./PHASE8_SYSTEM_PRIVILEGE/detail.md)** | **System & Linux Boot** | Days 111-130 | Supervisor Mode & Sv39 MMU. | `backend/fu/CSR.scala` |
| **[Phase 9](./PHASE9_VECTOR_ISA/detail.md)** | **AI & Vector ISA** | Days 131-155 | Matrix Compute & Vector Units. | `backend/fu/vector/` |
| **[Phase 10](./PHASE10_VERIFICATION_SOC) ** | **SoC & Tapeout** | Ongoing | Difftest & Silicon Readiness. | `XSTile.scala` |

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
- [ ] Privilege Levels (M, S, U)
- [ ] CSRs & Exceptions
- [ ] MMU (Sv39)
- [ ] 32-bit Compatibility (UXL/SXL)
- [ ] **Rename Stage** (Map Table + Free List).
- [ ] **Reorder Buffer (ROB)** for in-order commitment.
- [ ] **Distributed Issue Queues** (Separate queues for ALU, MEM, etc.).
- [ ] **Advanced Load/Store Unit** (Memory Disambiguation, Speculative Loads).
