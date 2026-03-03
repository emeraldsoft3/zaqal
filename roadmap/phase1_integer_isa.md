# Phase 1: Base Integer ISA (RV64I)

This phase focuses on the fundamental "brain" of the processor. We will implement the base integer instructions one category at a time.

### Day 1: Logical Operations
- [ ] `AND`, `OR`, `XOR` (Reg-Reg)
- [ ] `ANDI`, `ORI`, `XORI` (Reg-Imm)

### Day 2: Shift Operations
- [ ] `SLL`, `SRL`, `SRA` (Reg-Reg)
- [ ] `SLLI`, `SRLI`, `SRAI` (Reg-Imm)
- [ ] `SLLW`, `SRLW`, `SRAW` (Word versions for RV64)
- [ ] `SLLIW`, `SRLIW`, `SRAIW` (Word immediate versions)

### Day 3: Comparison & Upper Immediates
- [ ] `SLT`, `SLTU` (Reg-Reg)
- [ ] `SLTI`, `SLTIU` (Reg-Imm)
- [ ] `LUI` (Load Upper Immediate)
- [ ] `AUIPC` (Add Upper Immediate to PC)

### Day 4: Base Arithmetic (Completing the Basics)
- [ ] `SUB` (Subtract - you already have `ADD`)
- [ ] `ADDIW`, `ADDW`, `SUBW` (Word versions for RV64)

---

## Technical Goal
Ensure the `Decoder.scala` correctly identifies everyopcode/funct3/funct7 combination and the `Execute.scala` (ALU) produces the correct 64-bit result for all inputs.
