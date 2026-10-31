.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 562
    li x3, 78
    li x4, 355
    li x5, 613
    li x6, 866
    li x7, 621
    li x9, 296
    li x10, 89
    li x11, 523
    li x12, 950
    li x13, 353
    li x14, 403
    li x15, 426
    li x16, 20
    li x17, 998
    li x18, 34
    li x19, 107
    li x20, 868
    li x21, 456
    li x22, 668
    li x23, 231
    li x24, 823
    li x25, 358
    li x26, 88
    li x27, 510
    li x28, 338
    li x29, 940
    li x30, 623
    li x31, 556

    # 4. Randomized Instruction Stream (Seed: 29)
    subw    x17, x7, x16
    lb      x12, 96(s0)
    srlw    x29, x16, x19
    slti    x27, x12, 75
    beq     x26, x31, fuzz_br_0
    addi    x30, x6, 17
    addi    x6, x25, 22
fuzz_br_0:
    bltu    x15, x7, fuzz_br_1
    addi    x23, x23, 28
    addi    x17, x12, 40
fuzz_br_1:
    lbu     x25, 160(s0)
    bgeu    x26, x26, fuzz_br_2
    addi    x24, x11, 1
fuzz_br_2:
    beq     x15, x16, fuzz_br_3
    addi    x16, x6, 19
fuzz_br_3:
    beq     x26, x3, fuzz_br_4
    addi    x5, x1, 41
    addi    x19, x31, 4
fuzz_br_4:
    bltu    x27, x1, fuzz_br_5
    addi    x7, x25, 29
fuzz_br_5:
    srl     x1, x26, x11
    subw    x9, x5, x30
    slliw   x30, x10, 13
    lw      x31, 120(s0)
    beq     x22, x5, fuzz_br_6
    addi    x13, x10, 44
    addi    x16, x28, 4
fuzz_br_6:
    bge     x12, x21, fuzz_br_7
    addi    x12, x16, 44
fuzz_br_7:
    xor     x15, x16, x28
    bgeu    x13, x15, fuzz_br_8
    addi    x6, x7, 23
fuzz_br_8:
    ld      x13, 200(s0)
    slliw   x3, x17, 14
    bge     x7, x30, fuzz_br_9
    addi    x7, x7, 3
    addi    x23, x17, 4
fuzz_br_9:
    ld      x5, 232(s0)
    bne     x13, x10, fuzz_br_10
    addi    x9, x25, 39
fuzz_br_10:
    sllw    x5, x28, x13
    beq     x6, x14, fuzz_br_11
    addi    x29, x29, 15
fuzz_br_11:
    andi    x11, x20, 35
    slli    x9, x24, 20
    ld      x28, 32(s0)
    sd      x11, 112(s0)
    blt     x27, x24, fuzz_br_12
    addi    x26, x4, 19
    addi    x23, x5, 41
fuzz_br_12:
    bgeu    x13, x28, fuzz_br_13
    addi    x14, x5, 42
    addi    x24, x14, 19
fuzz_br_13:
    beq     x22, x25, fuzz_br_14
    addi    x6, x19, 45
    addi    x7, x19, 2
fuzz_br_14:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
