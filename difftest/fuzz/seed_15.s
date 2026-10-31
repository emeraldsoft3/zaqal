.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 989
    li x3, 214
    li x4, 12
    li x5, 534
    li x6, 754
    li x7, 38
    li x9, 162
    li x10, 935
    li x11, 245
    li x12, 18
    li x13, 57
    li x14, 901
    li x15, 825
    li x16, 698
    li x17, 151
    li x18, 878
    li x19, 712
    li x20, 377
    li x21, 246
    li x22, 120
    li x23, 347
    li x24, 478
    li x25, 726
    li x26, 365
    li x27, 288
    li x28, 402
    li x29, 270
    li x30, 353
    li x31, 235

    # 4. Randomized Instruction Stream (Seed: 15)
    bne     x30, x14, fuzz_br_0
    addi    x10, x12, 47
    addi    x19, x16, 15
fuzz_br_0:
    sraiw   x18, x4, 23
    slti    x25, x23, 79
    sd      x9, 32(s0)
    addw    x22, x28, x12
    addw    x31, x30, x31
    slt     x4, x17, x12
    sraw    x7, x20, x14
    andi    x12, x7, 70
    blt     x30, x17, fuzz_br_1
    addi    x27, x29, 18
fuzz_br_1:
    and     x24, x18, x15
    ori     x26, x4, -96
    xor     x11, x7, x21
    addiw   x3, x19, 114
    bltu    x17, x10, fuzz_br_2
    addi    x25, x26, 17
    addi    x24, x4, 40
fuzz_br_2:
    xori    x27, x23, 94
    ori     x22, x17, -113
    bge     x1, x31, fuzz_br_3
    addi    x22, x15, 34
    addi    x1, x6, 17
fuzz_br_3:
    andi    x13, x10, 123
    andi    x25, x10, -98
    bgeu    x30, x19, fuzz_br_4
    addi    x29, x26, 37
fuzz_br_4:
    sllw    x13, x5, x13
    sraiw   x21, x5, 0
    srlw    x25, x23, x29
    sraw    x21, x20, x22
    sd      x19, 184(s0)
    lhu     x27, 80(s0)
    bge     x30, x22, fuzz_br_5
    addi    x1, x11, 22
    addi    x6, x27, 18
fuzz_br_5:
    sraw    x3, x17, x28
    srl     x23, x11, x26
    lw      x13, 224(s0)
    srl     x14, x16, x16
    sw      x19, 80(s0)
    slliw   x17, x17, 27
    srai    x17, x26, 3
    slliw   x31, x23, 2

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
