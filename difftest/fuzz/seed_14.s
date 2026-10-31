.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 110
    li x3, 631
    li x4, 720
    li x5, 774
    li x6, 668
    li x7, 540
    li x9, 963
    li x10, 253
    li x11, 278
    li x12, 753
    li x13, 262
    li x14, 299
    li x15, 752
    li x16, 75
    li x17, 675
    li x18, 461
    li x19, 311
    li x20, 478
    li x21, 701
    li x22, 894
    li x23, 407
    li x24, 404
    li x25, 797
    li x26, 931
    li x27, 122
    li x28, 270
    li x29, 229
    li x30, 892
    li x31, 924

    # 4. Randomized Instruction Stream (Seed: 14)
    sltiu   x14, x28, -52
    slli    x7, x1, 15
    srl     x4, x11, x30
    bge     x21, x17, fuzz_br_0
    addi    x30, x23, 44
fuzz_br_0:
    bltu    x21, x23, fuzz_br_1
    addi    x7, x30, 7
    addi    x26, x30, 32
fuzz_br_1:
    sraw    x11, x17, x9
    slli    x19, x11, 15
    beq     x11, x11, fuzz_br_2
    addi    x1, x7, 48
fuzz_br_2:
    sll     x16, x18, x20
    xori    x18, x17, 85
    and     x11, x18, x10
    slliw   x4, x21, 31
    sb      x16, 224(s0)
    andi    x18, x11, 26
    xor     x23, x20, x28
    slliw   x5, x3, 19
    sra     x21, x19, x19
    blt     x11, x5, fuzz_br_3
    addi    x6, x27, 13
fuzz_br_3:
    ori     x30, x19, -35
    andi    x12, x26, -112
    subw    x19, x23, x14
    sraw    x15, x20, x27
    bge     x22, x3, fuzz_br_4
    addi    x23, x16, 31
fuzz_br_4:
    sd      x6, 40(s0)
    srlw    x9, x11, x17
    addiw   x3, x28, 3
    sb      x10, 216(s0)
    subw    x6, x1, x23
    blt     x22, x24, fuzz_br_5
    addi    x21, x16, 30
fuzz_br_5:
    srliw   x13, x4, 3
    bgeu    x23, x20, fuzz_br_6
    addi    x30, x4, 28
fuzz_br_6:
    beq     x30, x3, fuzz_br_7
    addi    x4, x1, 44
fuzz_br_7:
    sraw    x15, x31, x6
    sraiw   x17, x28, 1
    sltiu   x10, x12, -128
    sllw    x26, x1, x31
    xor     x15, x15, x12
    srli    x1, x11, 36
    bgeu    x12, x9, fuzz_br_8
    addi    x1, x31, 42
    addi    x4, x17, 22
fuzz_br_8:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
