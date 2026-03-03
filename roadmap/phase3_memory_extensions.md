# Phase 3: Memory & Extensions (RV64M, etc.)

This phase handles data movement and complex arithmetic like multiplication and division.

### Day 7-8: Memory Operations (I-Type & S-Type)
- [ ] `LB`, `LH`, `LW`, `LD`: Load Byte, Half, Word, Double (signed)
- [ ] `LBU`, `LHU`, `LWU`: Load Byte, Half, Word (unsigned)
- [ ] `SB`, `SH`, `SW`, `SD`: Store Byte, Half, Word, Double

### Day 9: Integer Multiplication & Division (M-Extension)
- [ ] `MUL`, `MULH`, `MULHSU`, `MULHU`, `MULW`
- [ ] `DIV`, `DIVU`, `REM`, `REMU`, `DIVW`, `DIVUW`, `REMW`, `REMUW`

### Day 10-12: Floating Point (F & D Extensions - Optional Start)
- [ ] `FLW`, `FSW`, `FLD`, `FSD`
- [ ] `FADD.S`, `FSUB.S`, `FMUL.S`, `FDIV.S`

---

## Technical Goal
- Establish a reliable memory interface protocol.
- Integrate multi-cycle execution units (Divider).
- Correctly handle 32-bit vs 64-bit integer signedness.
