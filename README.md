# Zaqal: AI-Native Superscalar RISC-V Core

Zaqal is a high-performance, **6-wide superscalar**, out-of-order (OoO) RISC-V processor core designed in Chisel. It is deeply inspired by the **XiangShan** (Kunminghu/Nanhu) architecture, aiming to bridge the gap between open-source hardware and silicon-grade performance.

## 🚀 Project Vision
The goal of Zaqal is to provide an **AI-Native** execution engine that excels at both standard general-purpose computing (RV64GC) and modern AI workloads (Matrix/Vector extensions).

## 🛠 Architectural Specifications
- **ISA**: RV64GCBK (Integer, Compressed, Atomic, Multiply, Floating-Point, Bitmanip).
- **Frontend**: 
  - Decoupled Branch Prediction Unit (BPU) with TAGE/Neural predictors.
  - 8-parcel (128-bit) Fetch Bandwidth.
  - Fetch Target Queue (FTQ) for deep instruction decoupling.
- **Execution Engine**:
  - **6-Wide Issue/Dispatch**: Massive parallel instruction throughput.
  - Fully Out-of-Order (OoO) execution via Rename, ROB, and PRF.
  - High-latency units (FPDIV/FSQRT) with SRT-16 recurrence.
- **AI Acceleration**: Dedicated Phase 9 roadmap for Matrix (AMX) and Vector (RVV) units.

## 📈 Roadmap Progress
- [x] **Phase 1-2**: Base Integer ISA & Branch Integrity.
- [x] **Phase 3**: FPU Integration & Memory Parity (FLW/FLD/FSW/FSD).
- [/] **Phase 4**: **[Current]** Superscalar Dispatch (1-wide to 6-wide transition).
- [ ] **Phase 5-7**: OoO Engine (ROB, Rename, Issue Queues).
- [ ] **Phase 8-10**: Linux Support, AI-Native Extensions, and SoC Verification.

## 🏗 Build & Test
Zaqal uses the **Mill** build system for fast, modular compilation.

```bash
# To run the core simulation
mill zaqal.runMain zaqal.ZaqalTest

# To run unit tests
mill zaqal.test
```

## 🤝 Acknowledgments
Zaqal draws significant inspiration from the **XiangShan Project** (ICT, CAS). We follow their philosophy of high-performance, open-source hardware development.
