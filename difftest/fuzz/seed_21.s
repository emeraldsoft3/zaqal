.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 169
    li x3, 429
    li x4, 707
    li x5, 429
    li x6, 651
    li x7, 289
    li x9, 491
    li x10, 864
    li x11, 222
    li x12, 812
    li x13, 487
    li x14, 828
    li x15, 987
    li x16, 525
    li x17, 188
    li x18, 518
    li x19, 541
    li x20, 242
    li x21, 808
    li x22, 4
    li x23, 15
    li x24, 380
    li x25, 956
    li x26, 600
    li x27, 439
    li x28, 71
    li x29, 149
    li x30, 813
    li x31, 770

    # 4. Randomized Instruction Stream (Seed: 21)
    srlw    x25, x3, x26
    ld      x13, 208(s0)
    add     x23, x14, x6
    sd      x17, 40(s0)
    srli    x15, x18, 23
    lw      x4, 240(s0)
    lbu     x31, 104(s0)
    sb      x20, 32(s0)
    bne     x13, x6, fuzz_br_0
    addi    x12, x14, 29
    addi    x19, x15, 21
fuzz_br_0:
    bge     x11, x1, fuzz_br_1
    addi    x7, x25, 46
fuzz_br_1:
    bge     x1, x18, fuzz_br_2
    addi    x20, x22, 48
fuzz_br_2:
    slli    x20, x22, 23
    lh      x14, 176(s0)
    sw      x4, 152(s0)
    bne     x27, x16, fuzz_br_3
    addi    x7, x24, 3
    addi    x24, x19, 43
fuzz_br_3:
    bge     x7, x26, fuzz_br_4
    addi    x31, x14, 32
fuzz_br_4:
    subw    x31, x10, x20
    sraiw   x27, x26, 3
    beq     x30, x11, fuzz_br_5
    addi    x3, x16, 16
    addi    x7, x15, 5
fuzz_br_5:
    bgeu    x31, x6, fuzz_br_6
    addi    x26, x26, 31
fuzz_br_6:
    srlw    x23, x19, x1
    blt     x28, x6, fuzz_br_7
    addi    x22, x27, 28
    addi    x18, x21, 31
fuzz_br_7:
    addi    x6, x27, 67
    sh      x23, 8(s0)
    sraiw   x11, x24, 8
    sll     x15, x5, x1
    sd      x23, 72(s0)
    xori    x20, x13, 124
    bltu    x7, x7, fuzz_br_8
    addi    x30, x15, 13
fuzz_br_8:
    lwu     x30, 16(s0)
    ld      x15, 24(s0)
    sltu    x15, x27, x7
    bne     x11, x25, fuzz_br_9
    addi    x26, x3, 16
    addi    x15, x6, 20
fuzz_br_9:
    lbu     x20, 144(s0)
    add     x20, x22, x19

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
