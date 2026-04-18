# Phase 3: Memory & Extensions (A, M, & B)

This phase expansion covers the "A" (Atomic), "M" (Multiplication), and "B" (Bitmanip) extensions, plus the 64-bit Memory details.
## Week 0: Metaprogramming & Build Hierarchy Refactor (Days 7-12)
*Zaqal Synergy Task based on XiangShan's modular build system.*
- [x] **Day 7**: Migrate Zaqal from traditional SBT to the Mill build system (`build.sc`).
- [x] **Day 8**: Abstract common configurations (widths, queue depths) into a `case class ZaqalParams` akin to `XSCoreParams`.
- [x] **Day 9**: Decompose the monolithic codebase into strictly isolated compile targets (e.g., `zaqal.frontend`, `zaqal.backend`).
- [x] **Day 10**: Introduce a `zaqal.utility` module for standardizing Chisel `ValidIO` skid buffers and pipeline registers.
- [x] **Day 11**: Connect the `moduleDeps` in `build.sc` to enforce a clean Directed Acyclic Graph (DAG) for the build.
- [x] **Day 12**: Run `mill resolve __.compile` to verify that components can compile and test independently.


## Week 1: Core Memory & Alignment (Days 13-17)
- [x] **Day 13**: Load Instructions (LB, LH, LW, LD, LBU, LHU, LWU).
- [x] **Day 14**: Store Instructions (SB, SH, SW, SD).
- [x] **Day 15**: Memory Alignment & Byte Masking (Handling unaligned access).
- [x] **Day 16**: Multiplication (RV64M) - MUL, MULH, MULW.
- [x] **Day 17**: Division (RV64M) - DIV, DIVU, REM, REMU (SRT-like logic).

## Week 2: Atomics & Bitmanip (Days 18-22)
- [x] **Day 18**: Atomics (LR/SC) - Reservation set management.
- [x] **Day 19**: AMO Operations (AMOADD, AMOXOR, etc.).
- [x] **Day 20**: Bitmanip - Zba (Address Generation: SH1ADD, etc.).
- [x] **Day 21**: Bitmanip - Zbb (Basic Bit Ops: CLZ, CTZ, CPOP).
- [x] **Day 22**: Bitmanip - Zbs (Single-bit manipulation).

## Week 3: Compressed Instructions (RV64C) (Days 23-28)
- [x] **Day 23**: IFU modifications for 16-bit/32-bit instruction alignment.
- [x] **Day 24**: Predecoder refactor: Introduction of `RVCExpander` module (XiangShan Parity).
  - [x] Refactor inline expansion to dedicated module.
- [ ] **Day 25**: Full RV64C Instruction Coverage.
  - [ ] Support for Q0 (Memory), Q1 (Arith/Logic/CFI), and Q2 (Stack/CFI).
  - [ ] Handling instructions crossing cache-line boundaries (Final Polish).
- [ ] **Day 26**: Updates to the PC generator (incrementing by +2 or +4).
- [ ] **Day 27**: Modifying BRU & Exceptions for 2-byte alignment restrictions.
- [ ] **Day 28**: Verification of C extension with compiled Linux binaries.

## Week 4-5: Floating Point Unit (Days 29-38)
- [ ] **Day 29-30**: FPU Front-end (FP Register file, fcsr, and decoding).
- [ ] **Day 31-33**: FADD, FSUB, FMUL pipelines (Iterative refinement).
- [ ] **Day 34-35**: FDIV, FSQRT (High-latency logic).
- [ ] **Day 36**: FMIN/MAX, FCVT, F-Misc operations.
- [ ] **Day 37**: Memory/FP Integration (FLW, FSW, FLD, FSD).
- [ ] **Day 38**: Final Phase 3 Benchmarking (CoreMark-FP).

---
