.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 116
    li x3, 761
    li x4, 134
    li x5, 559
    li x6, 612
    li x7, 730
    li x9, 183
    li x10, 232
    li x11, 136
    li x12, 654
    li x13, 476
    li x14, 782
    li x15, 428
    li x16, 216
    li x17, 219
    li x18, 148
    li x19, 402
    li x20, 167
    li x21, 863
    li x22, 979
    li x23, 135
    li x24, 621
    li x25, 193
    li x26, 207
    li x27, 29
    li x28, 417
    li x29, 246
    li x30, 72
    li x31, 98

    # 4. Randomized Instruction Stream (Seed: 28)
    srli    x25, x29, 22
    bltu    x19, x25, fuzz_br_0
    addi    x22, x10, 44
    addi    x17, x6, 13
fuzz_br_0:
    ori     x23, x24, -88
    xori    x26, x5, -43
    xor     x3, x16, x14
    sltiu   x29, x15, -39
    srai    x27, x21, 53
    bne     x9, x3, fuzz_br_1
    addi    x14, x24, 45
    addi    x27, x31, 26
fuzz_br_1:
    sraw    x26, x18, x9
    slliw   x21, x16, 26
    srai    x17, x10, 4
    srliw   x24, x20, 28
    or      x23, x17, x24
    sraw    x15, x9, x5
    lh      x30, 56(s0)
    slliw   x4, x6, 10
    beq     x17, x19, fuzz_br_2
    addi    x19, x18, 48
    addi    x28, x25, 26
fuzz_br_2:
    addiw   x30, x25, 40
    sltiu   x21, x21, 63
    slli    x31, x27, 50
    addiw   x30, x6, 76
    xor     x6, x12, x29
    bne     x1, x24, fuzz_br_3
    addi    x22, x21, 31
fuzz_br_3:
    bge     x1, x10, fuzz_br_4
    addi    x5, x31, 27
fuzz_br_4:
    andi    x18, x29, 39
    sllw    x27, x3, x25
    sraw    x1, x13, x5
    srl     x4, x22, x21
    xori    x24, x17, 126
    bltu    x7, x10, fuzz_br_5
    addi    x15, x21, 17
    addi    x9, x15, 3
fuzz_br_5:
    srliw   x19, x10, 20
    lwu     x6, 136(s0)
    blt     x3, x20, fuzz_br_6
    addi    x30, x25, 15
    addi    x24, x13, 38
fuzz_br_6:
    subw    x13, x20, x14
    bge     x1, x25, fuzz_br_7
    addi    x1, x3, 34
    addi    x13, x19, 8
fuzz_br_7:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
