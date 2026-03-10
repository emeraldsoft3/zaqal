# Phase 3: Memory & Extensions (A, M, & B)

This phase expansion covers the "A" (Atomic), "M" (Multiplication), and "B" (Bitmanip) extensions, plus the 64-bit Memory details.

## Day 1: Load Instructions (Base)
- [ ] `LB`, `LH`, `LW`, `LD` (Signed)
- [ ] `LBU`, `LHU`, `LWU` (Unsigned)
- **XiangShan Study**: [LoadUnit.scala:L80-120](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/LoadUnit.scala) - *How they handle load requests.*

## Day 2: Store Instructions (Base)
- [ ] `SB`, `SH`, `SW`, `SD`
- **XiangShan Study**: [StoreUnit.scala:L50-90](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/StoreUnit.scala) - *Examine the store data path.*

## Day 3: Memory Alignment & Byte Masking
- [ ] Implement logic to handle unaligned loads/stores that cross 64-bit boundaries.
- **XiangShan Study**: [MaskedDataModule.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/MaskedDataModule.scala) - *See how they mask data for partial word accesses.*

## Day 4: Multiplication (RV64M)
- [ ] `MUL`, `MULH`, `MULHSU`, `MULHU`, `MULW`
- **XiangShan Study**: [Multiplier.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Multiplier.scala) - *Study the multiplier pipeline.*

## Day 5: Division (RV64M)
- [ ] `DIV`, `DIVU`, `REM`, `REMU`, `DIVW`, etc.
- **XiangShan Study**: [SRT16Divider.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/SRT16Divider.scala) - *High-performance divider implementation.*

## Day 6: Atomics (LR/SC)
- [ ] `LR.D`, `SC.D` (Load Reserved / Store Conditional)
- **XiangShan Study**: [AtomicsUnit.scala:L100-150](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/AtomicsUnit.scala) - *How reservation sets are managed.*

## Day 7: AMO Operations
- [ ] `AMOADD`, `AMOXOR`, `AMOAND`, `AMOOR`, `AMOMIN`, `AMOMAX`
- **XiangShan Study**: [AtomicsUnit.scala:L150-200](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/AtomicsUnit.scala) - *Atomic Arithmetic logic.*

## Day 8: Bitmanip - Zba (Address Generation)
- [ ] `SH1ADD`, `SH2ADD`, `SH3ADD`
- **XiangShan Study**: [Bku.scala:L20-50](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Bku.scala) - *Study the BKU (Bitmanip Kunminghu Unit).*

## Day 9: Bitmanip - Zbb (Basic Bit Operations)
- [ ] `ANDN`, `ORN`, `XNOR`, `CLZ`, `CTZ`, `CPOP`
- **XiangShan Study**: [Bku.scala:L60-100](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Bku.scala) - *Logic and counting operations.*

## Day 10: Bitmanip - Zbs (Single-bit)
- [ ] `BSET`, `BCLR`, `BINV`, `BEXT`
- **XiangShan Study**: [Bku.scala:L110-150](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Bku.scala) - *Single-bit manipulation logic.*

## Day 11-14: Floating Point Unit (FPU)
- [ ] **F-Extension**: Single-precision FPU (RV64F).
- [ ] **D-Extension**: Double-precision FPU (RV64D).
- [ ] **Architecture**: Implement the FP register file (f0-f31) and status register (fcsr).
- [ ] **Operations**: FADD, FSUB, FMUL, FDIV, FSQRT, FMIN/MAX, FCVT.
- **XiangShan Study**: [fpu/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/fpu/) - *Analyze the decoupled FP pipeline.*

## Day 15: Memory/FP Integration
- [ ] Implement `FLW`, `FSW`, `FLD`, `FSD` in the Load/Store unit.
- **Goal**: Run basic floating point benchmarks (e.g., CoreMark-FP).

---
