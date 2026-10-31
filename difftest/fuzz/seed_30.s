.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 553
    li x3, 828
    li x4, 297
    li x5, 626
    li x6, 31
    li x7, 637
    li x9, 670
    li x10, 847
    li x11, 216
    li x12, 264
    li x13, 50
    li x14, 407
    li x15, 386
    li x16, 657
    li x17, 138
    li x18, 84
    li x19, 473
    li x20, 8
    li x21, 535
    li x22, 955
    li x23, 249
    li x24, 27
    li x25, 75
    li x26, 164
    li x27, 931
    li x28, 863
    li x29, 836
    li x30, 614
    li x31, 544

    # 4. Randomized Instruction Stream (Seed: 30)
    bgeu    x14, x20, fuzz_br_0
    addi    x15, x1, 16
fuzz_br_0:
    bgeu    x11, x27, fuzz_br_1
    addi    x21, x5, 44
    addi    x11, x23, 36
fuzz_br_1:
    beq     x22, x18, fuzz_br_2
    addi    x6, x29, 20
    addi    x31, x12, 17
fuzz_br_2:
    sllw    x10, x25, x5
    lwu     x12, 208(s0)
    sllw    x18, x23, x19
    slli    x19, x13, 2
    beq     x18, x31, fuzz_br_3
    addi    x11, x18, 17
    addi    x21, x11, 45
fuzz_br_3:
    bne     x24, x7, fuzz_br_4
    addi    x19, x12, 27
fuzz_br_4:
    sb      x31, 104(s0)
    lb      x24, 152(s0)
    sb      x14, 192(s0)
    sllw    x26, x7, x19
    beq     x25, x9, fuzz_br_5
    addi    x27, x13, 36
fuzz_br_5:
    sltiu   x30, x15, -110
    sb      x22, 0(s0)
    blt     x17, x29, fuzz_br_6
    addi    x6, x30, 25
fuzz_br_6:
    srai    x29, x1, 52
    sraiw   x1, x6, 4
    addi    x27, x12, 33
    addiw   x27, x17, 54
    slliw   x21, x26, 7
    slliw   x15, x5, 12
    sub     x5, x15, x7
    srli    x1, x31, 47
    andi    x9, x22, -52
    sraw    x25, x22, x29
    slliw   x5, x22, 20
    sh      x16, 72(s0)
    and     x26, x28, x26
    addiw   x29, x11, 117
    xor     x16, x26, x20
    slt     x10, x3, x31
    lw      x5, 104(s0)
    slli    x1, x20, 44
    sraiw   x13, x26, 28
    subw    x26, x4, x1

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
