# Zaqal Project Roadmap: Path to XiangShan (Kunminghu)

This roadmap outlines the multi-month journey to transform Zaqal from a simple 1-wide prototype into a world-class, superscalar, out-of-order RISC-V processor.

## Architectural Philosophy
- **Phase 1-3**: Functional Core (1-wide, in-order, correct).
- **Phase 4-5**: High Frequency & Superscalar (1-wide to 6-wide, pipelined).
- **Phase 6-7**: Performance Engine (Out-of-order, Advanced BPU, Caches).
- **Phase 8-10**: System Readiness (Exceptions, MMU, Multicore, Vectors).
- **Ongoing**: **Continuous Refactoring & Cleanup** (Aligning with XiangShan's modular design).

## Detailed Roadmap Phases

| Phase | Title | Est. Time | Key Goal |
| :--- | :--- | :--- | :--- |
| **[Phase 1](./PHASE1_INTEGER_ISA/detail.md)** | **Base Integer ALU** | 1 Week | Mastery of 64-bit integer compute. |
| **[Phase 2](./PHASE2_BRANCHING_MISPREDICT/detail.md)** | **Branching & Mispredict** | 1 Week | Control flow and redirect integrity. |
| **[Phase 3](./PHASE3_MEMORY_EXTENSIONS/detail.md)** | **Memory & Bitmanip** | 2 Weeks | Load/Store, Atomics, and B-Extension (BKU). |
| **[Phase 4](./PHASE4_SUPERSCALAR_DISPATCH/detail.md)** | **Superscalar Dispatch** | 3 Weeks | Transition to 6-wide parallel execution. |
| **[Phase 5](./PHASE5_TIMING_OPTIMIZATION/detail.md)** | **Timing & Pipelining** | 2 Weeks | Reaching GHz clock speeds (Fmax). |
| **[Phase 6](./PHASE6_ADVANCED_FRONTEND/detail.md)** | **Advanced Frontend** | 3 Weeks | **FTB**, TAGE, and Instruction Folding. |
| **[Phase 7](./PHASE7_OUT_OF_ORDER/detail.md)** | **Out-of-Order Engine** | 4 Weeks | ROB, **Register Cache**, and FU Clusters. |
| **[Phase 7.5](./PHASE7_MEMORY_PREFETCH/detail.md)** | **Memory Prefetching** | 2 Weeks | **SMS**, Stride, and Frontend Data Prefetchers. |
| **[Phase 8](./PHASE8_SYSTEM_PRIVILEGE/detail.md)** | **System & Privilege** | 3 Weeks | MMU, PMP/PMA, and **Debug Module**. |
| **[Phase 9](./PHASE9_VECTOR_ISA/detail.md)** | **Vector Extension (RVV)** | 4 Weeks | High-performance vector processing. |
| **[Phase 10](./PHASE10_VERIFICATION_SOC/detail.md)** | **Verification & SoC** | Ongoing | Difftest, UART, Linux Boot. |

---

## The "XiangShan" Checklist
To be truly "XiangShan-like", we must eventually implement:
- [ ] **Multi-stage BPU** (Bimodal -> GShare -> TAGE -> ITTAGE).
- [ ] **Instruction Buffer (IBuffer)** with banked parallel dequeue.
- [ ] **Rename Stage** (Map Table + Free List).
- [ ] **Reorder Buffer (ROB)** for in-order commitment.
- [ ] **Distributed Issue Queues** (Separate queues for ALU, MEM, etc.).
- [ ] **Advanced Load/Store Unit** (Memory Disambiguation, Speculative Loads).
