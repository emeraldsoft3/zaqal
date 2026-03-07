# Phase 1: Integer ALU ISA (RV64I)

In this phase, we build the "compute core" of the CPU. We will implement these instructions one by one to ensure the decoder and ALU are rock-solid.

## Day 1: Logical Operations (Bitwise)
- [x] `AND`, `OR`, `XOR` (Register-Register)
- [x] `ANDI`, `ORI`, `XORI` (Register-Immediate)
- **XiangShan Study**: [Alu.scala:L231-236](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Alu.scala) - *See how they handle bitwise logic.*
- **Goal**: Verify bitwise logic with 0xFFFF and 0x0000 patterns.

## Day 2: Shift Operations
- [ ] `SLL`, `SRL`, `SRA` (64-bit Reg-Reg)
- [ ] `SLLI`, `SRLI`, `SRAI` (64-bit Reg-Imm)
- [ ] `SLLW`, `SRLW`, `SRAW` (32-bit Word variants)
- [ ] `SLLIW`, `SRLIW`, `SRAIW` (32-bit Word Immediate versions)
- **XiangShan Study**: [Alu.scala:L178-210](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Alu.scala) - *Examine the barrel shifter implementation.*
- **Goal**: Handle the 5-bit vs 6-bit shift amount masking correctly.

## Day 3: Comparison & Movement
- [ ] `SLT`, `SLTU` (Set if less than - Signed/Unsigned)
- [ ] `SLTI`, `SLTIU` (Set less than immediate)
- [ ] `LUI` (Load Upper Immediate)
- [ ] `AUIPC` (Add Upper Immediate to PC)
- **XiangShan Study**: [Alu.scala:L238-245](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Alu.scala) - *Compare signed vs unsigned SLT logic.*
- **Goal**: Master the sign-extension of 32-bit immediates into 64-bit registers.

## Day 4: Arithmetic Completion
- [ ] `SUB` (Subtract - you have `ADD` already)
- [ ] `ADDW`, `SUBW`, `ADDIW` (Word-based arithmetic)
- **XiangShan Study**: [Alu.scala:L160-175](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Alu.scala) - *See how Word (32-bit) operations are handled on 64-bit hardware.*
- **Goal**: Ensure the "W" instructions properly sign-extend the 32-bit result to 64-bits.
