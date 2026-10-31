.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 638
    li x3, 262
    li x4, 760
    li x5, 368
    li x6, 815
    li x7, 708
    li x9, 966
    li x10, 862
    li x11, 758
    li x12, 668
    li x13, 945
    li x14, 543
    li x15, 30
    li x16, 861
    li x17, 477
    li x18, 795
    li x19, 966
    li x20, 256
    li x21, 665
    li x22, 54
    li x23, 923
    li x24, 161
    li x25, 116
    li x26, 381
    li x27, 481
    li x28, 890
    li x29, 253
    li x30, 390
    li x31, 557

    # 4. Randomized Instruction Stream (Seed: 5)
    subw    x1, x26, x16
    addiw   x7, x27, -57
    sd      x30, 224(s0)
    subw    x7, x30, x12
    subw    x20, x31, x7
    bgeu    x9, x31, fuzz_br_0
    addi    x12, x1, 24
    addi    x16, x7, 10
fuzz_br_0:
    addi    x12, x29, 45
    slti    x29, x12, 33
    addiw   x25, x7, 3
    beq     x26, x14, fuzz_br_1
    addi    x1, x20, 27
    addi    x14, x15, 38
fuzz_br_1:
    bge     x3, x25, fuzz_br_2
    addi    x22, x9, 8
fuzz_br_2:
    sh      x31, 232(s0)
    srliw   x5, x21, 18
    slt     x9, x13, x22
    sraw    x13, x11, x4
    slli    x12, x7, 19
    lw      x26, 152(s0)
    srliw   x3, x10, 16
    addiw   x6, x3, 124
    sraw    x6, x26, x6
    sb      x14, 208(s0)
    sraiw   x12, x6, 10
    bge     x18, x25, fuzz_br_3
    addi    x18, x11, 19
    addi    x18, x15, 10
fuzz_br_3:
    sllw    x23, x18, x7
    sltiu   x19, x28, 56
    addi    x25, x21, 28
    ori     x29, x18, 22
    blt     x23, x7, fuzz_br_4
    addi    x18, x20, 50
fuzz_br_4:
    sltiu   x17, x12, 54
    xori    x26, x29, 51
    bne     x30, x30, fuzz_br_5
    addi    x14, x13, 34
    addi    x6, x19, 11
fuzz_br_5:
    ori     x30, x18, -88
    sb      x12, 208(s0)
    ld      x9, 136(s0)
    slliw   x22, x23, 14
    ld      x18, 88(s0)

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
