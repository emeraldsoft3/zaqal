# Phase 1: Integer ALU ISA (RV64I) [COMPLETE]

In this phase, we built the "compute core" of the CPU. We implemented these instructions one by one to ensure the decoder and ALU are rock-solid.

## Day 1: Logical Operations (Bitwise) [x]
- [x] `AND`, `OR`, `XOR` (Register-Register)
- [x] `ANDI`, `ORI`, `XORI` (Register-Immediate)
- **Goal**: Verified bitwise logic with 0xFFFF and 0x0000 patterns.

## Day 2: Shift Operations [x]
- [x] `SLL`, `SRL`, `SRA` (64-bit Reg-Reg)
- [x] `SLLI`, `SRLI`, `SRAI` (64-bit Reg-Imm)
- [x] `SLLW`, `SRLW`, `SRAW` (32-bit Word variants)
- [x] `SLLIW`, `SRLIW`, `SRAIW` (32-bit Word Immediate versions)
- **Goal**: Handled the 5-bit vs 6-bit shift amount masking correctly.

## Day 3: Comparison & Movement [x]
- [x] `SLT`, `SLTU` (Set if less than - Signed/Unsigned)
- [x] `SLTI`, `SLTIU` (Set less than immediate)
- [x] `LUI` (Load Upper Immediate)
- [x] `AUIPC` (Add Upper Immediate to PC)
- **Goal**: Mastered the sign-extension of 32-bit immediates into 64-bit registers.

## Day 4: Arithmetic Completion [x]
- [x] `SUB` (Subtract)
- [x] `ADDW`, `SUBW`, `ADDIW` (Word-based arithmetic)
- **Goal**: Ensured the "W" instructions properly sign-extend the 32-bit result to 64-bits.
