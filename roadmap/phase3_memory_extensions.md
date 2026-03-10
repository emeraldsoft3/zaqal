# Phase 3: Memory & Extensions (RV64M, etc.)

This phase handles data movement and complex arithmetic like multiplication and division.

### Day 7-8: Memory Operations (I-Type & S-Type)
- [ ] `LB`, `LH`, `LW`, `LD`: Load Byte, Half, Word, Double (signed)
- [ ] `LBU`, `LHU`, `LWU`: Load Byte, Half, Word (unsigned)
- [ ] `SB`, `SH`, `SW`, `SD`: Store Byte, Half, Word, Double

### Day 9: Integer Multiplication & Division (M-Extension)
- [ ] `MUL`, `MULH`, `MULHSU`, `MULHU`, `MULW`
- [ ] `DIV`, `DIVU`, `REM`, `REMU`, `DIVW`, `DIVUW`, `REMW`, `REMUW`

### Day 10-12: Floating Point (F & D Extensions)
- [ ] **RV64F**: Single-precision floating point instructions.
- [ ] **RV64D**: Double-precision floating point instructions.
- [ ] Implement FPU pipeline (Fadd, Fmul, Fdiv, Fsqrt).
- **XiangShan Study**: [fpu/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/fpu/) - *Study the FP pipeline.*

---

## Technical Goal
- Establish a reliable memory interface protocol.
- Integrate multi-cycle execution units (Divider).
- Correctly handle 32-bit vs 64-bit integer signedness.
