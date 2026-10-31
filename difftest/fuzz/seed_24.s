.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 730
    li x3, 393
    li x4, 860
    li x5, 597
    li x6, 187
    li x7, 224
    li x9, 172
    li x10, 199
    li x11, 174
    li x12, 687
    li x13, 699
    li x14, 94
    li x15, 723
    li x16, 776
    li x17, 155
    li x18, 826
    li x19, 724
    li x20, 291
    li x21, 742
    li x22, 945
    li x23, 785
    li x24, 14
    li x25, 452
    li x26, 479
    li x27, 887
    li x28, 739
    li x29, 651
    li x30, 119
    li x31, 29

    # 4. Randomized Instruction Stream (Seed: 24)
    sraiw   x26, x30, 19
    sra     x24, x27, x29
    ld      x20, 160(s0)
    lh      x13, 16(s0)
    beq     x12, x5, fuzz_br_0
    addi    x24, x22, 10
fuzz_br_0:
    bge     x30, x12, fuzz_br_1
    addi    x20, x26, 18
    addi    x9, x4, 37
fuzz_br_1:
    sllw    x23, x6, x18
    sllw    x18, x19, x19
    sw      x11, 120(s0)
    sllw    x15, x9, x15
    ori     x29, x13, -34
    sw      x31, 216(s0)
    or      x30, x17, x17
    or      x3, x4, x25
    sraiw   x20, x18, 25
    blt     x12, x14, fuzz_br_2
    addi    x6, x13, 48
    addi    x4, x28, 38
fuzz_br_2:
    lwu     x1, 8(s0)
    sb      x31, 208(s0)
    srliw   x15, x24, 20
    beq     x15, x1, fuzz_br_3
    addi    x17, x28, 5
    addi    x7, x28, 15
fuzz_br_3:
    bltu    x23, x31, fuzz_br_4
    addi    x17, x6, 12
fuzz_br_4:
    beq     x29, x4, fuzz_br_5
    addi    x10, x1, 36
fuzz_br_5:
    bge     x3, x7, fuzz_br_6
    addi    x28, x12, 7
    addi    x30, x7, 8
fuzz_br_6:
    slt     x22, x28, x18
    slti    x11, x24, 107
    lhu     x30, 208(s0)
    sw      x19, 72(s0)
    sllw    x17, x13, x30
    bgeu    x22, x6, fuzz_br_7
    addi    x5, x12, 48
fuzz_br_7:
    lb      x4, 120(s0)
    sraiw   x22, x21, 21
    bge     x25, x30, fuzz_br_8
    addi    x30, x3, 12
fuzz_br_8:
    subw    x26, x29, x1
    srai    x18, x24, 42
    ori     x18, x20, -113
    srai    x10, x14, 50

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
