.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 665
    li x3, 492
    li x4, 719
    li x5, 284
    li x6, 981
    li x7, 293
    li x9, 202
    li x10, 76
    li x11, 67
    li x12, 261
    li x13, 845
    li x14, 553
    li x15, 342
    li x16, 259
    li x17, 382
    li x18, 855
    li x19, 835
    li x20, 413
    li x21, 188
    li x22, 254
    li x23, 932
    li x24, 246
    li x25, 503
    li x26, 842
    li x27, 74
    li x28, 748
    li x29, 940
    li x30, 653
    li x31, 587

    # 4. Randomized Instruction Stream (Seed: 27)
    lhu     x3, 216(s0)
    sb      x11, 176(s0)
    srai    x22, x23, 18
    addiw   x27, x12, -85
    addw    x11, x20, x7
    bgeu    x1, x17, fuzz_br_0
    addi    x14, x31, 37
fuzz_br_0:
    xor     x12, x17, x14
    subw    x28, x11, x18
    sll     x19, x10, x9
    lh      x13, 248(s0)
    sd      x12, 200(s0)
    xor     x12, x17, x12
    xor     x12, x9, x20
    add     x1, x21, x14
    lbu     x5, 144(s0)
    sraiw   x16, x26, 0
    srai    x26, x1, 29
    slli    x29, x15, 44
    beq     x7, x4, fuzz_br_1
    addi    x12, x10, 9
fuzz_br_1:
    bltu    x29, x18, fuzz_br_2
    addi    x10, x22, 24
fuzz_br_2:
    beq     x24, x18, fuzz_br_3
    addi    x12, x20, 30
fuzz_br_3:
    slliw   x28, x12, 9
    lhu     x3, 168(s0)
    beq     x18, x22, fuzz_br_4
    addi    x10, x16, 21
fuzz_br_4:
    addw    x5, x15, x14
    bne     x27, x20, fuzz_br_5
    addi    x7, x17, 4
fuzz_br_5:
    slliw   x22, x3, 17
    bne     x5, x20, fuzz_br_6
    addi    x14, x13, 41
    addi    x19, x9, 26
fuzz_br_6:
    sw      x19, 80(s0)
    andi    x15, x18, -95
    add     x21, x27, x25
    sb      x20, 64(s0)
    sll     x24, x26, x12
    lhu     x13, 248(s0)
    lwu     x4, 192(s0)
    ori     x26, x18, 121
    sraw    x19, x26, x20
    bne     x26, x14, fuzz_br_7
    addi    x12, x25, 19
fuzz_br_7:
    sb      x11, 200(s0)

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
