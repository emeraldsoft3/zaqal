# Phase 1: Integer ALU ISA (RV64I)

In this phase, we build the "compute core" of the CPU. We will implement these instructions one by one to ensure the decoder and ALU are rock-solid.

## Day 1: Logical Operations (Bitwise)
- [ ] `AND`, `OR`, `XOR` (Register-Register)
- [ ] `ANDI`, `ORI`, `XORI` (Register-Immediate)
- **Goal**: Verify bitwise logic with 0xFFFF and 0x0000 patterns.

## Day 2: Shift Operations
- [ ] `SLL`, `SRL`, `SRA` (64-bit Reg-Reg)
- [ ] `SLLI`, `SRLI`, `SRAI` (64-bit Reg-Imm)
- [ ] `SLLW`, `SRLW`, `SRAW` (32-bit Word variants)
- [ ] `SLLIW`, `SRLIW`, `SRAIW` (32-bit Word Immediate versions)
- **Goal**: Handle the 5-bit vs 6-bit shift amount masking correctly.

## Day 3: Comparison & Movement
- [ ] `SLT`, `SLTU` (Set if less than - Signed/Unsigned)
- [ ] `SLTI`, `SLTIU` (Set less than immediate)
- [ ] `LUI` (Load Upper Immediate)
- [ ] `AUIPC` (Add Upper Immediate to PC)
- **Goal**: Master the sign-extension of 32-bit immediates into 64-bit registers.

## Day 4: Arithmetic Completion
- [ ] `SUB` (Subtract - you have `ADD` already)
- [ ] `ADDW`, `SUBW`, `ADDIW` (Word-based arithmetic)
- **Goal**: Ensure the "W" instructions properly sign-extend the 32-bit result to 64-bits.
