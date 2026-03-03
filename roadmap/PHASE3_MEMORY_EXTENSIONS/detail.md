# Phase 3: Memory & Extensions (A & M)

This phase expansion covers the "A" (Atomic) and "M" (Multiplication) extensions, plus the 64-bit Memory details.

## Week 2: Load/Store Mastery
- [ ] `LB`, `LH`, `LW`, `LD`: Byte, Half, Word, Double (signed)
- [ ] `LBU`, `LHU`, `LWU`: Unsigned variants
- [ ] `SB`, `SH`, `SW`, `SD`: Store operations
- [ ] **Unaligned Access**: Implement logic to handle loads that cross a 64-bit boundary (Optional but common in high-end).

## Week 3: Multiplication & Division (RV64M)
- [ ] `MUL`, `MULH`, `MULHSU`, `MULHU`: Full 128-bit multiplication products.
- [ ] `MULW`: 32-bit word multiplication.
- [ ] `DIV`, `DIVU`, `REM`, `REMU`: The complex divider.
- [ ] `DIVW`, `DIVUW`, `REMW`, `REMUW`: Word variants.
- **Challenge**: Implement the "Divider Busy" stall mechanism without halting the entire machine if independent instructions follow (Introduction to Scoreboarding).

## Week 4: Atomic Memory Operations (RV64A)
- [ ] **Load-Reserved / Store-Conditional**: `LR.D`, `SC.D`.
- [ ] **Atomic Ops**: `AMOADD`, `AMOXOR`, `AMOAND`, `AMOOR`, `AMOMIN`, `AMOMAX`.
- **Note**: Crucial for running multi-core Linux later.
