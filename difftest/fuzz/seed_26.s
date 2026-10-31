.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 766
    li x3, 929
    li x4, 208
    li x5, 676
    li x6, 211
    li x7, 443
    li x9, 616
    li x10, 558
    li x11, 59
    li x12, 131
    li x13, 795
    li x14, 974
    li x15, 783
    li x16, 489
    li x17, 43
    li x18, 748
    li x19, 700
    li x20, 639
    li x21, 515
    li x22, 176
    li x23, 651
    li x24, 440
    li x25, 977
    li x26, 249
    li x27, 766
    li x28, 419
    li x29, 735
    li x30, 865
    li x31, 207

    # 4. Randomized Instruction Stream (Seed: 26)
    lbu     x10, 8(s0)
    srlw    x22, x18, x14
    sra     x1, x26, x30
    add     x19, x3, x17
    lbu     x24, 160(s0)
    sllw    x3, x31, x9
    bge     x30, x16, fuzz_br_0
    addi    x3, x5, 5
fuzz_br_0:
    srl     x3, x16, x14
    or      x30, x20, x5
    xor     x16, x25, x21
    srai    x5, x24, 10
    bgeu    x11, x14, fuzz_br_1
    addi    x14, x19, 31
    addi    x22, x15, 46
fuzz_br_1:
    add     x6, x21, x19
    slliw   x3, x21, 2
    sb      x7, 216(s0)
    addw    x31, x5, x22
    beq     x30, x24, fuzz_br_2
    addi    x20, x1, 18
    addi    x18, x29, 21
fuzz_br_2:
    sd      x9, 200(s0)
    sltiu   x10, x6, 69
    sltiu   x25, x4, -95
    sb      x10, 16(s0)
    srlw    x11, x13, x18
    addiw   x10, x1, -75
    subw    x27, x5, x20
    lhu     x26, 16(s0)
    addw    x19, x3, x15
    srl     x16, x26, x13
    sra     x20, x1, x11
    sraiw   x29, x21, 20
    blt     x31, x23, fuzz_br_3
    addi    x29, x21, 31
    addi    x28, x3, 17
fuzz_br_3:
    sltu    x27, x3, x28
    ori     x10, x10, 86
    lh      x27, 8(s0)
    addi    x5, x29, -78
    beq     x26, x24, fuzz_br_4
    addi    x6, x15, 44
fuzz_br_4:
    lhu     x14, 40(s0)
    slliw   x18, x27, 26

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
