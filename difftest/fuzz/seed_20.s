.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 928
    li x3, 741
    li x4, 703
    li x5, 806
    li x6, 785
    li x7, 902
    li x9, 927
    li x10, 155
    li x11, 267
    li x12, 691
    li x13, 651
    li x14, 870
    li x15, 927
    li x16, 104
    li x17, 894
    li x18, 336
    li x19, 587
    li x20, 928
    li x21, 174
    li x22, 28
    li x23, 422
    li x24, 417
    li x25, 77
    li x26, 106
    li x27, 129
    li x28, 327
    li x29, 486
    li x30, 973
    li x31, 595

    # 4. Randomized Instruction Stream (Seed: 20)
    sllw    x9, x13, x13
    slliw   x15, x4, 15
    sra     x4, x9, x25
    lw      x22, 152(s0)
    srl     x11, x25, x30
    bltu    x10, x3, fuzz_br_0
    addi    x28, x23, 40
fuzz_br_0:
    sllw    x25, x23, x22
    lh      x20, 72(s0)
    bne     x7, x15, fuzz_br_1
    addi    x25, x6, 50
fuzz_br_1:
    addi    x10, x5, -29
    addw    x29, x4, x28
    beq     x28, x23, fuzz_br_2
    addi    x24, x26, 26
    addi    x17, x19, 49
fuzz_br_2:
    lw      x5, 24(s0)
    bltu    x13, x1, fuzz_br_3
    addi    x21, x26, 7
fuzz_br_3:
    ori     x23, x4, -106
    sd      x7, 96(s0)
    subw    x31, x12, x16
    slliw   x5, x9, 12
    beq     x12, x6, fuzz_br_4
    addi    x31, x6, 42
    addi    x4, x17, 32
fuzz_br_4:
    sllw    x29, x23, x15
    beq     x29, x12, fuzz_br_5
    addi    x14, x22, 20
fuzz_br_5:
    add     x1, x11, x31
    slti    x15, x29, -78
    addiw   x9, x1, 46
    sd      x1, 88(s0)
    beq     x9, x26, fuzz_br_6
    addi    x22, x15, 45
fuzz_br_6:
    lb      x3, 184(s0)
    bne     x31, x22, fuzz_br_7
    addi    x31, x30, 36
    addi    x15, x15, 17
fuzz_br_7:
    sraiw   x4, x21, 20
    sllw    x12, x17, x15
    sub     x14, x6, x26
    beq     x27, x5, fuzz_br_8
    addi    x10, x20, 10
    addi    x12, x27, 47
fuzz_br_8:
    srli    x14, x19, 2
    sraiw   x10, x15, 18
    slli    x22, x27, 63
    subw    x17, x24, x18

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
