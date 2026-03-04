# Phase 3: Memory & Extensions (A, M, & B)

This phase expansion covers the "A" (Atomic), "M" (Multiplication), and "B" (Bitmanip) extensions, plus the 64-bit Memory details.

## Week 2: Load/Store Mastery
- [ ] `LB`, `LH`, `LW`, `LD`: Byte, Half, Word, Double (signed)
- [ ] `LBU`, `LHU`, `LWU`: Unsigned variants
- [ ] `SB`, `SH`, `SW`, `SD`: Store operations
- [ ] **Unaligned Access**: Implement logic to handle loads that cross a 64-bit boundary.

## Week 3: Multiplication & Division (RV64M)
- [ ] `MUL`, `MULH`, `MULHSU`, `MULHU`: Full 128-bit multiplication products.
- [ ] `MULW`: 32-bit word multiplication.
- [ ] `DIV`, `DIVU`, `REM`, `REMU`: The complex divider (SRT-based).
- [ ] `DIVW`, `DIVUW`, `REMW`, `REMUW`: Word variants.
- **Challenge**: Implement the "Divider Busy" stall mechanism without halting the entire machine.

## Week 4: Atomics & Bitmanip (RV64A & RV64B)
- [ ] **Atomics**: `LR.D`, `SC.D`, and AMO operations (`AMOADD`, `AMOXOR`, etc.).
- [ ] **Bit Manipulation (Zba, Zbb, Zbc, Zbs)**: Address generation, basic bit ops, carry-less multiply, and single-bit manips to match XiangShan's BKU.
