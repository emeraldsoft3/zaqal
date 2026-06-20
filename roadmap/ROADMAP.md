# Zaqal Project Roadmap: The AI-Native (Kunminghu-Based) Core

This roadmap outlines the journey to transform Zaqal from a simple prototype into a world-class, **AI-Native**, superscalar, out-of-order RISC-V processor, following the architectural footsteps of the XiangShan project.

## Architectural Philosophy
- **Phase 1-3: Functional Core**: Establishing correctness with 1-wide, in-order execution and foundational ISA extensions.
- **Phase 4-5: High Frequency & Superscalar**: Scaling from 1-wide to 6-wide and optimizing for multi-GHz clock speeds.
- **Phase 6-7: Performance Engine**: Implementing **Neural-guided BPU**, Out-of-order execution, and advanced memory prefetching.
- **Phase 8-10: System Power**: Achieving Linux-readiness, Matrix acceleration (**AMX**), and silicon-grade verification.

---

## Master Timeline Summary

| Phase | Title | Schedule | Status | Key Goal |
| :--- | :--- | :--- | :--- | :--- |
| **[Phase 1](./PHASE1_INTEGER_ISA/detail.md)** | **Base Integer ALU** | Days 1-4 | **[COMPLETE]** | Mastery of RV64I calculations. |
| **[Phase 2](./PHASE2_BRANCHING_MISPREDICT/detail.md)** | **Branching & Mispredict** | Days 5-10 | **[COMPLETE]** | Control Flow & Pipeline Integrity. |
| **[Phase 3](./PHASE3_MEMORY_EXTENSIONS/detail.md)** | **Memory & Build Refactor** | Days 11-42 | **[COMPLETE]** | Mill Build, Utilities, G-extension. |
| **[Phase 4](./PHASE4_SUPERSCALAR_DISPATCH/detail.md)** | **Superscalar Dispatch** | Days 43-60 | [ ] | 1-wide to 6-wide (Rename/RAT). |
| **[Phase 5](./PHASE5_TIMING_OPTIMIZATION/detail.md)** | **Timing & Pipelining** | Days 61-75 | [ ] | High Frequency Optimization. |
| **[Phase 6](./PHASE6_FRONTEND_PERFORMANCE/detail.md)** | **Advanced Front-end** | Days 76-95 | [ ] | **Neural BPU** & High-perf Caches. |
| **[Phase 7](./PHASE7_ENGINE_PERFORMANCE/detail.md)** | **Out-of-Order Engine** | Days 96-120 | [ ] | ROB, Issue Queues, LSQ. |
| **[Phase 8](./PHASE8_SYSTEM_PRIVILEGE/detail.md)** | **System & Linux Boot** | Days 121-140 | [ ] | Supervisor Mode & Sv39 MMU. |
| **[Phase 9](./PHASE9_VECTOR_ISA/detail.md)** | **AI & Vector ISA** | Days 141-165 | [ ] | Matrix/AMX & Vector Units. |
| **[Phase 10](./PHASE10_VERIFICATION_SOC/detail.md)** | **SoC & Tapeout** | Day 166-180 | [ ] | Difftest & Silicon Readiness. |
| **[Phase 11](./PHASE11_MULTI_CORE_COHERENCE/detail.md)** | **Multi-Hart & Coherence** | Day 181+ | [ ] | TileLink/CHI, L3 Cache, Coherence. |

---

## Technical Goal: The "XiangShan" Parity Checklist
To achieve world-class performance, Zaqal must eventually implement these critical features:

### Front-End
- [x] **Skid Buffers** (Register Slices) for module decoupling.
- [/] **FTQ (Fetch Target Queue)** with deep pointer-based skidding.
- [ ] **Multi-stage BPU** (Bimodal -> GShare -> TAGE -> ITTAGE).
- [ ] **Neural BPU (Perceptron)** for data-dependent branches.
- [ ] **Instruction Buffer (IBuffer)** with banked parallel dequeue.

### Execution Engine
- [/] **Rename Stage** (Map Table + Free List) - *Target: 192 Physical Registers (Kunminghu Parity).*
- [ ] **Reorder Buffer (ROB)** for in-order commitment.
- [ ] **Physical Register File (PRF)** with Register Cache.
- [ ] **Distributed Issue Queues** (Separate queues for ALU, MEM, etc.).
  - *Target Execution Units (XiangShan Kunminghu Parity):*
    - **4 ALUs** (Integer Arithmetic & Logical)
    - **2 MDUs** (Integer Multiplication/Division)
    - **2 BRUs** (Branch Resolution Units)
    - **3 LSUs** (Load/Store Units: 2 Load, 1 Store)
    - **4 FPUs** (Floating Point Units: 2 FP Add/Misc, 2 FP FMAC)
  - [ ] **Bypass Network Expansion**: Register all new execution unit writeback/staging outputs in the `bypassChannels` list in `Execute.scala` to dynamically scale up result forwarding.


### Memory & System
- [ ] **Advanced Load/Store Unit** (Memory Disambiguation, Speculative Loads).
- [ ] **Intelligent Prefetchers** (Stride, Spatial, Stream).
- [ ] **Privilege Levels** (M, S, U) & Sv39 MMU.
- [ ] **AMX Matrix Unit** (2D Tile acceleration for AI).

---

## Software Compatibility Goals
- [ ] **Linux Boot**: Full support for RV64GC with Supervisor mode.
- [ ] **GNU Toolchain**: Support for standard `gcc` and `llvm` outputs.
- [ ] **Benchmark Excellence**: Competitive CoreMark and SPECInt scores.
- [ ] **Windows-on-Zaqal**: Running software via **Wine** on RISC-V Linux.

---

## Future Evaluation: Architecture Design Decisions
Before finalizing the Out-of-Order Engine (Phase 7) and Multi-Core coherence (Phase 11), a comprehensive review of the design forks must be evaluated. 
Please refer to the [Design Decisions Index](./design_decisions/list.md) to form a "Phase 12" roadmap covering SMT, L2 cache exclusivity, and Vector/SIMD pathing.
