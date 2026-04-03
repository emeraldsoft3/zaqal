# Zaqal Roadmap: From Basics to XiangShan-Level Performance

This roadmap outlines the journey of building the Zaqal processor, starting from a basic RISC-V implementation and evolving into a state-of-the-art, high-performance out-of-order processor inspired by XiangShan.

---

## Phase 1: Foundation (RV64I & Tooling) - [COMPLETED]
- [x] Day 1: [RV64I Infrastructure](roadmap/PHASE1_RV64I/day1.md)
- [x] Day 2: [ALU & Instructions Part 1](roadmap/PHASE1_RV64I/day2.md)
- [x] Day 3: [ALU & Instructions Part 2](roadmap/PHASE1_RV64I/day3.md)
- [x] Day 4: [Memory Instructions basics](roadmap/PHASE1_RV64I/day4.md)
- [x] Day 5: [Control Flow Instructions basics](roadmap/PHASE1_RV64I/day5.md)

---

## Phase 2: Refinement & Advanced Architecture [CURRENT]
- [x] Day 1: [M-Extension Implementation](roadmap/PHASE2_M_EXTENSION/day1.md)
- [x] Day 2: [C-Extension Support basics](roadmap/PHASE3_C_EXTENSION/day1.md)
- [x] Day 3: [5-Stage Pipeline Baseline](roadmap/PHASE4_PIPELINE/day1.md)
- [x] Day 4: [Branch Prediction Unit (BPU) Start](roadmap/PHASE5_BRANCH_PREDICTION/day1.md)
- [x] Day 5: BPU Architecture & FTB (XiangShan Doc Sections 1.1 - 1.3 | pp. 2-29)
- [/] Day 6: Advanced Predictors & RAS (XiangShan Doc Sections 1.4 - 1.7 | pp. 30-61)
- [ ] Day 7: FTQ & Instruction Fetch Unit (XiangShan Doc Sections 2 - 3 | pp. 62-88)
- [ ] Day 8: ICache Design (XiangShan Doc Section 4 | pp. 89-114)
- [x] Day 9: [Modular Reorganization](roadmap/PHASE4_PIPELINE/day9.md) - **Alignment with XiangShan Structure**

---

## Phase 3: High Performance (Out-of-Order & Caches)
- [ ] Day 1: Register Renaming & Map Table
- [ ] Day 2: Reorder Buffer (ROB) Implementation
- [ ] Day 3: Issue Queues & Dispatch Logic
- [ ] Day 4: Data Cache (L1 D$) & Memory Disambiguation
- [ ] Day 5: Level 2 Cache (L2$) & Coherency basics

---

## Phase 4: Integration & Optimization
- [ ] Day 1: Full System Integration (TileLink/AXI4)
- [ ] Day 2: Performance Monitoring (HPM)
- [ ] Day 3: Debug Support (JTAG/DMI)
- [ ] Day 4: Booting Linux on Zaqal
- [ ] Day 5: Benchmark & Performance Tuning (CoreMark, SPEC)

---

## Future Goals
- [ ] Vector ISA Extension (V-Extension)
- [ ] Hypervisor Support (H-Extension)
- [ ] Cryptographic Extensions (K-Extension)
- [ ] Multi-Core scaling and Cache Coherency (TileLink-H)
