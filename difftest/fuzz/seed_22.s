.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 982
    li x3, 930
    li x4, 144
    li x5, 249
    li x6, 25
    li x7, 628
    li x9, 458
    li x10, 189
    li x11, 719
    li x12, 124
    li x13, 758
    li x14, 668
    li x15, 900
    li x16, 354
    li x17, 812
    li x18, 911
    li x19, 82
    li x20, 238
    li x21, 276
    li x22, 983
    li x23, 51
    li x24, 328
    li x25, 1000
    li x26, 616
    li x27, 184
    li x28, 955
    li x29, 566
    li x30, 702
    li x31, 751

    # 4. Randomized Instruction Stream (Seed: 22)
    bgeu    x31, x3, fuzz_br_0
    addi    x21, x11, 20
fuzz_br_0:
    sraw    x30, x5, x19
    bltu    x3, x25, fuzz_br_1
    addi    x22, x13, 17
    addi    x7, x15, 20
fuzz_br_1:
    bgeu    x19, x6, fuzz_br_2
    addi    x29, x11, 43
    addi    x25, x7, 28
fuzz_br_2:
    slt     x16, x11, x12
    slliw   x15, x24, 19
    srliw   x21, x1, 27
    sb      x14, 216(s0)
    slliw   x3, x29, 15
    srl     x17, x31, x7
    srliw   x14, x7, 22
    sw      x28, 224(s0)
    ld      x3, 96(s0)
    sltu    x29, x6, x17
    slt     x18, x25, x6
    addiw   x18, x26, 53
    beq     x29, x28, fuzz_br_3
    addi    x5, x1, 12
    addi    x19, x14, 41
fuzz_br_3:
    sltu    x7, x23, x16
    sw      x14, 88(s0)
    lb      x30, 104(s0)
    sub     x11, x27, x21
    addw    x15, x14, x26
    bltu    x29, x7, fuzz_br_4
    addi    x10, x15, 40
fuzz_br_4:
    srlw    x27, x18, x3
    sw      x31, 208(s0)
    srli    x4, x24, 22
    bgeu    x13, x3, fuzz_br_5
    addi    x18, x7, 39
fuzz_br_5:
    srliw   x25, x1, 0
    slliw   x30, x24, 28
    sllw    x14, x13, x30
    bgeu    x1, x25, fuzz_br_6
    addi    x22, x23, 7
    addi    x7, x30, 40
fuzz_br_6:
    sltiu   x11, x30, 6
    andi    x19, x7, 125
    lw      x18, 64(s0)
    slt     x15, x24, x9
    sb      x13, 40(s0)

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
