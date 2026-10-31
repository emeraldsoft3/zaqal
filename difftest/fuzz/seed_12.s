.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 486
    li x3, 276
    li x4, 674
    li x5, 542
    li x6, 683
    li x7, 359
    li x9, 147
    li x10, 391
    li x11, 12
    li x12, 384
    li x13, 495
    li x14, 281
    li x15, 659
    li x16, 830
    li x17, 472
    li x18, 708
    li x19, 886
    li x20, 616
    li x21, 234
    li x22, 572
    li x23, 2
    li x24, 678
    li x25, 640
    li x26, 149
    li x27, 451
    li x28, 377
    li x29, 167
    li x30, 348
    li x31, 928

    # 4. Randomized Instruction Stream (Seed: 12)
    sllw    x4, x19, x24
    slt     x1, x3, x10
    sraiw   x17, x5, 8
    addw    x25, x31, x20
    and     x15, x22, x24
    addiw   x22, x15, -86
    bgeu    x11, x14, fuzz_br_0
    addi    x30, x25, 25
    addi    x24, x12, 8
fuzz_br_0:
    sltiu   x14, x14, -37
    addiw   x3, x19, -15
    sd      x27, 16(s0)
    sllw    x4, x25, x3
    addiw   x14, x22, 107
    slti    x12, x17, 118
    sllw    x17, x20, x7
    sllw    x22, x1, x27
    bne     x10, x28, fuzz_br_1
    addi    x19, x3, 16
fuzz_br_1:
    lwu     x6, 184(s0)
    ori     x31, x28, -68
    srliw   x18, x23, 16
    lw      x17, 224(s0)
    slt     x11, x13, x23
    lwu     x11, 104(s0)
    sll     x25, x1, x20
    bge     x6, x10, fuzz_br_2
    addi    x16, x18, 4
fuzz_br_2:
    xori    x27, x3, 92
    srliw   x28, x9, 23
    ld      x25, 192(s0)
    ld      x16, 8(s0)
    srliw   x28, x5, 12
    addiw   x22, x22, -20
    addiw   x21, x10, 80
    sll     x24, x13, x24
    srli    x12, x25, 55
    sltu    x9, x18, x17
    or      x24, x22, x17
    addi    x5, x10, 56
    sllw    x25, x16, x10
    sllw    x19, x31, x7
    slliw   x22, x19, 29

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
