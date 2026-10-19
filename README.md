# Zaqal: Open-Source Desktop-Class Out-of-Order RISC-V Processor

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![ISA](https://img.shields.io/badge/ISA-RV64GCBK%20+%20RVV%201.0%20+%20AMX-green.svg)](https://riscv.org/)
[![Hardware HDL](https://img.shields.io/badge/HDL-Chisel%20%2F%20Scala-orange.svg)](https://www.chisel-lang.org/)
[![Status](https://img.shields.io/badge/Status-Phase%2010%20(Multi--Core%20Coherence)-brightgreen.svg)](roadmap/PHASE10_MULTI_CORE_COHERENCE/detail.md)

**Zaqal** is an open-source, high-performance, **6-wide superscalar, out-of-order (OoO) 64-bit RISC-V processor core** implemented in Chisel. 

Deeply inspired by the architectural ambition of the **[XiangShan Project](https://github.com/OpenXiangShan/XiangShan)** (Kunminghu/Nanhu architectures led by the Institute of Computing Technology, CAS), Zaqal is engineered to bridge desktop-class microarchitecture with domain-specific AI acceleration. Instead of a simple educational pipeline, Zaqal tackles the real-world microarchitectural complexities required to run modern operating systems and demanding parallel workloads.

---

## 🏛 Key Microarchitectural Specifications

| Subsystem | Architectural Features |
| :--- | :--- |
| **ISA Compliance** | **RV64GCBK**: 64-bit Integer (I), Multiply/Divide (M), Atomics (A), Compressed (C), Single/Double Floating Point (F/D), Bit Manipulation (B), and Scalar Cryptography (K). |
| **Frontend** | **8-parcel (128-bit) Fetch Bandwidth** decoupled via a pointer-based **Fetch Target Queue (FTQ)**. Multi-stage branch prediction stack featuring **FTB**, **TAGE**, **ITTAGE** (indirect targets), **Statistical Corrector (SC)** neural predictor, and **Return Address Stack (RAS)**. |
| **Execution Engine** | **6-Wide Superscalar Out-of-Order Execution**. Speculative renaming via Physical Register File (PRF) and Rename Alias Table (RAT), distributed Issue Queues, and a 128-entry **Reorder Buffer (ROB)** guaranteeing precise architectural commit and trap handling. |
| **Vector Engine (RVV 1.0)** | Full RVV 1.0 compliance featuring dynamic `vtype`/`vl` management, **128 physical vector registers (`pv0`–`pv127`)** with snapshot checkpoint recovery (matching **XiangShan Kunminghu parity**), a decoupled **Vector Dispatch Queue (VDQ)**, and an out-of-order **Vector Issue Queue (VIQ)**. |
| **AI Coprocessor (AMX)** | 2D Systolic Matrix Engine featuring **8 Tile registers (`tmm0`–`tmm7`)**, strided 2D memory load/store units, and dedicated matrix multiply-accumulate execution units supporting **INT8 and BF16 GEMM**. |
| **Privilege & MMU** | Hardware support for **Machine (M-mode)** and **Supervisor (S-mode)**, complete CSR state machine, trap redirection, and an **Sv39 Page Table Walker (PTW)** with multi-level TLB hierarchies capable of booting **OpenSBI** and hand-off to Linux. |
| **Memory & Coherence** | Non-blocking L1 Data Cache with Miss Status Holding Registers (MSHR) and Store Buffer. Interconnect features standard **5-Channel TileLink-C** (Channels A, B, C, D, E) supporting `Acquire`/`Grant` memory operations and external `Probe`/`Release` directory-based cache snooping. |

---

## 🗺 Detailed Project Roadmap

Development is driven by a comprehensive, 12-phase engineering roadmap. Every phase contains its own dedicated microarchitectural specification and verification plan:

| Phase | Milestone | Scope & Highlights | Status |
| :---: | :--- | :--- | :---: |
| **[Phase 1](roadmap/PHASE1_INTEGER_ISA/detail.md)** | **Base Integer ISA** | 64-bit ALU operations, immediate formats, shift/arithmetic logic. | **[COMPLETE]** |
| **[Phase 2](roadmap/PHASE2_BRANCHING_MISPREDICT/detail.md)** | **Branching & Misprediction** | Control-flow redirection, pipeline flush boundaries, jump/branch resolution. | **[COMPLETE]** |
| **[Phase 3](roadmap/PHASE3_MEMORY_EXTENSIONS/detail.md)** | **Memory & Floating Point** | RV64F/D, load/store alignment, IEEE 754 arithmetic, Mill build infrastructure. | **[COMPLETE]** |
| **[Phase 4](roadmap/PHASE4_SUPERSCALAR_DISPATCH/detail.md)** | **Superscalar Dispatch** | 1-wide to 6-wide transition, instruction steering, bundle alignment. | **[COMPLETE]** |
| **[Phase 5](roadmap/PHASE5_TIMING_OPTIMIZATION/detail.md)** | **Pipelining & Timing** | Register slices (skid buffers), multi-stage critical path isolation. | **[COMPLETE]** |
| **[Phase 6](roadmap/PHASE6_FRONTEND_PERFORMANCE/detail.md)** | **Advanced Frontend** | FTQ decoupling, multi-component BPU (FTB, TAGE, ITTAGE, SC, RAS). | **[COMPLETE]** |
| **[Phase 7](roadmap/PHASE7_ENGINE_PERFORMANCE/detail.md)** | **Out-of-Order Engine** | 128-entry ROB, PRF/RAT dynamic renaming, distributed issue queues, LSQ. | **[COMPLETE]** |
| **[Phase 8](roadmap/PHASE8_SYSTEM_PRIVILEGE/detail.md)** | **Privileged Arch & Sv39 MMU** | M/S modes, CSR state machine, Clint timer, PLIC, Sv39 Page Table Walker. | **[COMPLETE]** |
| **[Phase 9](roadmap/PHASE9_VECTOR_ISA/detail.md)** | **AI, Vector & AMX Engines** | RVV 1.0 (Kunminghu 128-pv parity, VDQ, VIQ) + 2D Matrix AMX coprocessor. | **[COMPLETE]** |
| **[Phase 10](roadmap/PHASE10_MULTI_CORE_COHERENCE/detail.md)** | **Multi-Core Cache Coherence** | 5-channel TileLink-C protocol, Directory Coherence Hub, L1/L2 snooping. | **[CURRENT]** |
| **[Phase 11](roadmap/PHASE11_SUBSYSTEM_VERIFICATION/detail.md)** | **Subsystem Verification** | Pre-tapeout module isolation, randomized stress tests, formal assertions. | Planned |
| **[Phase 12](roadmap/PHASE12_SOC_TAPE_OUT_SHIPPING/detail.md)** | **SoC Sign-off & Shipping** | Full SoC integration, Difftest co-simulation, P&R sign-off, Linux boot. | Planned |

### 🎯 XiangShan Parity Feature Checklist

* **Frontend Architecture**:
  * [x] **Skid Buffers (Register Slices)**: Elastic pipeline stage decoupling.
  * [x] **Fetch Target Queue (FTQ)**: Deep pointer-based skidding with state snapshots.
  * [x] **Fetch Target Buffer (FTB)**: Cached target addresses and instruction boundaries.
  * [x] **uFTB (Micro Fetch Target Buffer)**: Stage-0 (`s0_uFTB`) fast zero-bubble target predictor.
  * [x] **TAGE & ITTAGE**: Tagged geometric conditional and indirect branch target predictors.
  * [x] **Neural BPU (Statistical Corrector / SC)**: Perceptron weight tables for hard branches.
  * [x] **Return Address Stack (RAS)**: Speculative 16-entry call/return predictor with repair buffers.
  * [x] **Branch Checkpointing**: Snapshot GHR/PHR/RAS in FTQ for 1-cycle rollback on mispredicts.
  * [x] **Decoded uOp Cache (L0)**: Decoded micro-op buffer bypassing fetch/decode.

* **Execution & Out-of-Order Engine**:
  * [x] **6-Wide Superscalar Dispatch**: Parallel instruction routing and bundle steering.
  * [x] **Physical Register File (PRF) & RAT**: Dynamic integer renaming with FreeList tracking.
  * [x] **128-Entry Reorder Buffer (ROB)**: Speculative execution with precise in-order retirement.
  * [x] **Distributed Issue Queues**: Decoupled queues for scalar ALU, memory, and vector ops.

* **Vector & AI Coprocessor**:
  * [x] **RVV 1.0 Vector Engine**: Dynamic `vtype`/`vl` management, SEW (8/16/32/64), LMUL (1/2/4/8).
  * [x] **Vector Rename & FreeList**: 128 physical vector registers (`pv0`–`pv127`, XiangShan Kunminghu parity).
  * [x] **Decoupled Vector Dispatch Queue (VDQ)** & **Vector Issue Queue (VIQ)**.
  * [x] **AMX 2D Matrix Engine**: 8 Tile registers (`tmm0`–`tmm7`), 2D systolic INT8/BF16 GEMM.

* **Memory & Privilege Subsystem**:
  * [x] **Privileged Architecture**: Machine (M-mode) and Supervisor (S-mode) with full CSR state (`CSRFile.scala`), Clint timer, and PLIC.
  * [x] **Virtual Memory (Sv39)**: Hardware Page Table Walker (PTW) with multi-level TLB.
  * [x] **Non-blocking L1 D-Cache**: MSHR hit-under-miss concurrency and Store Buffer.
  * [/] **Multi-Core Interconnect**: 5-Channel TileLink-C (`Acquire`/`Grant`, `Probe`/`Release` coherence).

---

## 🛠 Prerequisites & Environment Setup

To compile the Chisel HDL and run cycle-accurate Verilator simulations, ensure you have the following installed:

* **Java Development Kit (JDK)**: Version 11 or higher (`openjdk-11-jdk`)
* **Mill Build Tool**: Included in repo (`./mill`)
* **Verilator**: Version `>= 4.200` (`sudo apt install verilator`)
* **GTKWave**: For waveform inspection (`sudo apt install gtkwave`)
* **Python 3**: For waveform analysis and simulation scripts

---

## 🚀 Quickstart: Building & Simulating

### 1. Clone the Repository
```bash
git clone https://github.com/emeraldsoft3/zaqal.git
cd zaqal
```

### 2. Run the Core Verification Testbench
The core testbench compiles the complete out-of-order pipeline with memory hierarchy and executes verified RISC-V assembly programs:
```bash
./mill zaqal.runMain zaqal.ZaqalTest
```

### 3. Run the Multi-Core Coherence Testbench
To simulate concurrent multi-core cache-coherence transactions (AcquireBlock, ProbeBlock, GrantData, and ProbeAckData) on the TileLink-C interconnect:
```bash
./mill zaqal.runMain zaqal.MultiCoreTopTest
```

### 4. Inspecting Simulation Waveforms
The testbench generates cycle-accurate VCD waveforms in `programs/vcd/`:
```bash
gtkwave programs/vcd/Lithium.vcd programs/vcd/Lithium.gtkw &
```
*(Pre-recorded reference waveforms and GTKWave signal layouts are included under `programs/vcd/` for immediate viewing).*

---

## 🧰 Diagnostic Tools & Utilities

The repository includes specialized engineering tools to assist in microarchitecture verification:

* **Interactive TAGE Branch Predictor Simulator**: Open [`programs/html/tage_calculator.html`](programs/html/tage_calculator.html) in any web browser for a real-time visual demonstration of tagged geometric history tables and provider selection.
* **Signal Inspection & Waveform Profilers**: Located in [`scripts/`](scripts/) for automated VCD parsing, ROB commit tracing, and register state verification.
* **Embedded Microbenchmarks**: Test suites in [`programs/assembly/`](programs/assembly/) covering CoreMark-FP, deep RAS recursion, and vector stress routines.

---

## 🤝 Acknowledgments & References

* **[XiangShan (CAS ICT)](https://github.com/OpenXiangShan/XiangShan)**: An extraordinary pioneer in open-source high-performance processor design whose architectural publications and Kunminghu/Nanhu cores served as the foundational inspiration for Zaqal.
* **[RISC-V International](https://riscv.org/)**: For establishing the open, standard instruction set architecture.
* **[Chips Alliance & Chisel Community](https://www.chisel-lang.org/)**: For providing modern hardware construction languages that make agile silicon engineering possible.

---

## 📄 License

Zaqal is licensed under the **[Apache License, Version 2.0](LICENSE)**. Open silicon belongs to everyone.
