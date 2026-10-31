.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 138
    li x3, 583
    li x4, 868
    li x5, 822
    li x6, 783
    li x7, 65
    li x9, 262
    li x10, 121
    li x11, 508
    li x12, 780
    li x13, 461
    li x14, 484
    li x15, 668
    li x16, 389
    li x17, 808
    li x18, 215
    li x19, 97
    li x20, 500
    li x21, 30
    li x22, 915
    li x23, 856
    li x24, 400
    li x25, 444
    li x26, 623
    li x27, 781
    li x28, 786
    li x29, 3
    li x30, 713
    li x31, 457

    # 4. Randomized Instruction Stream (Seed: 1)
    sllw    x21, x5, x1
    srl     x31, x15, x16
    lb      x20, 112(s0)
    srlw    x24, x10, x12
    bge     x29, x20, fuzz_br_0
    addi    x7, x23, 47
fuzz_br_0:
    beq     x26, x13, fuzz_br_1
    addi    x19, x29, 43
    addi    x9, x12, 19
fuzz_br_1:
    sraiw   x30, x19, 2
    slliw   x16, x24, 23
    sltiu   x4, x17, -73
    sd      x18, 200(s0)
    slliw   x23, x7, 14
    bne     x20, x30, fuzz_br_2
    addi    x15, x19, 23
fuzz_br_2:
    bltu    x14, x17, fuzz_br_3
    addi    x24, x20, 39
    addi    x26, x1, 25
fuzz_br_3:
    lwu     x9, 64(s0)
    or      x18, x30, x21
    srliw   x18, x29, 26
    addi    x17, x22, -11
    lbu     x20, 88(s0)
    sd      x4, 128(s0)
    bge     x1, x27, fuzz_br_4
    addi    x10, x11, 8
    addi    x28, x22, 12
fuzz_br_4:
    sra     x7, x7, x19
    bgeu    x11, x23, fuzz_br_5
    addi    x17, x25, 21
    addi    x18, x18, 8
fuzz_br_5:
    slliw   x13, x16, 16
    addw    x22, x16, x10
    subw    x3, x26, x17
    lw      x23, 216(s0)
    sd      x15, 224(s0)
    lb      x3, 160(s0)
    ld      x12, 64(s0)
    sll     x12, x12, x16
    addw    x1, x20, x21
    bltu    x17, x7, fuzz_br_6
    addi    x15, x9, 23
fuzz_br_6:
    sraiw   x21, x9, 6
    bge     x12, x19, fuzz_br_7
    addi    x1, x13, 40
    addi    x30, x15, 19
fuzz_br_7:
    sraw    x30, x13, x28

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
