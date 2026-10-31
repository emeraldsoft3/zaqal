.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 694
    li x3, 45
    li x4, 804
    li x5, 917
    li x6, 533
    li x7, 124
    li x9, 524
    li x10, 205
    li x11, 403
    li x12, 356
    li x13, 542
    li x14, 297
    li x15, 599
    li x16, 152
    li x17, 610
    li x18, 268
    li x19, 111
    li x20, 267
    li x21, 422
    li x22, 336
    li x23, 992
    li x24, 275
    li x25, 855
    li x26, 111
    li x27, 792
    li x28, 334
    li x29, 919
    li x30, 319
    li x31, 24

    # 4. Randomized Instruction Stream (Seed: 19)
    subw    x31, x4, x5
    addiw   x30, x26, -78
    and     x21, x26, x27
    bge     x24, x12, fuzz_br_0
    addi    x28, x23, 27
fuzz_br_0:
    and     x28, x9, x9
    sraiw   x5, x20, 0
    bge     x22, x5, fuzz_br_1
    addi    x29, x19, 32
    addi    x14, x16, 35
fuzz_br_1:
    beq     x10, x4, fuzz_br_2
    addi    x17, x15, 29
fuzz_br_2:
    ori     x6, x18, 102
    sllw    x17, x17, x12
    sh      x24, 16(s0)
    bge     x5, x17, fuzz_br_3
    addi    x17, x19, 29
fuzz_br_3:
    sh      x4, 8(s0)
    srlw    x16, x12, x29
    addiw   x31, x24, 91
    sb      x22, 72(s0)
    lwu     x14, 16(s0)
    bne     x11, x19, fuzz_br_4
    addi    x3, x1, 50
    addi    x11, x23, 14
fuzz_br_4:
    sltiu   x19, x17, -59
    bltu    x28, x11, fuzz_br_5
    addi    x23, x26, 44
    addi    x19, x12, 42
fuzz_br_5:
    addiw   x29, x18, -14
    addiw   x30, x5, 5
    lh      x14, 192(s0)
    sltiu   x26, x5, 102
    sub     x30, x14, x13
    srliw   x21, x26, 2
    xori    x4, x10, -112
    bne     x18, x24, fuzz_br_6
    addi    x25, x22, 33
fuzz_br_6:
    add     x21, x16, x25
    sd      x11, 160(s0)
    sraw    x12, x5, x30
    sra     x25, x17, x20
    addw    x14, x26, x24
    sraw    x14, x17, x10
    slti    x3, x21, -65
    bltu    x4, x18, fuzz_br_7
    addi    x15, x19, 18
fuzz_br_7:
    sraiw   x3, x19, 1

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
