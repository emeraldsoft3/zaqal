.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 233
    li x3, 380
    li x4, 986
    li x5, 385
    li x6, 130
    li x7, 198
    li x9, 722
    li x10, 45
    li x11, 88
    li x12, 141
    li x13, 254
    li x14, 831
    li x15, 519
    li x16, 215
    li x17, 411
    li x18, 658
    li x19, 32
    li x20, 471
    li x21, 500
    li x22, 465
    li x23, 400
    li x24, 507
    li x25, 587
    li x26, 197
    li x27, 919
    li x28, 851
    li x29, 413
    li x30, 92
    li x31, 497

    # 4. Randomized Instruction Stream (Seed: 8)
    slt     x25, x11, x16
    srliw   x26, x5, 6
    beq     x15, x22, fuzz_br_0
    addi    x5, x24, 4
    addi    x13, x10, 45
fuzz_br_0:
    subw    x21, x28, x22
    srl     x18, x25, x6
    bltu    x17, x26, fuzz_br_1
    addi    x12, x20, 23
    addi    x30, x31, 28
fuzz_br_1:
    or      x20, x25, x25
    slliw   x19, x22, 19
    slli    x19, x24, 28
    srl     x12, x13, x11
    xori    x15, x12, -39
    sd      x9, 56(s0)
    bne     x12, x5, fuzz_br_2
    addi    x28, x27, 25
fuzz_br_2:
    subw    x21, x16, x6
    addiw   x16, x16, -93
    sub     x3, x4, x27
    sltiu   x6, x28, 121
    sw      x13, 32(s0)
    or      x26, x12, x13
    beq     x23, x29, fuzz_br_3
    addi    x9, x3, 40
    addi    x3, x31, 49
fuzz_br_3:
    bltu    x7, x7, fuzz_br_4
    addi    x16, x17, 8
    addi    x4, x9, 39
fuzz_br_4:
    sraiw   x28, x6, 7
    sraiw   x23, x6, 5
    lbu     x14, 240(s0)
    xor     x9, x3, x5
    sltu    x25, x22, x1
    lhu     x27, 216(s0)
    lh      x19, 96(s0)
    sraw    x1, x12, x12
    bgeu    x13, x15, fuzz_br_5
    addi    x23, x12, 6
fuzz_br_5:
    andi    x28, x26, 26
    lh      x23, 176(s0)
    bne     x18, x14, fuzz_br_6
    addi    x21, x30, 20
    addi    x9, x12, 26
fuzz_br_6:
    lwu     x21, 176(s0)
    addiw   x9, x18, 9

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
