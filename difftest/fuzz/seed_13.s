.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 266
    li x3, 298
    li x4, 702
    li x5, 932
    li x6, 701
    li x7, 822
    li x9, 870
    li x10, 912
    li x11, 191
    li x12, 668
    li x13, 237
    li x14, 683
    li x15, 151
    li x16, 891
    li x17, 231
    li x18, 657
    li x19, 752
    li x20, 192
    li x21, 134
    li x22, 73
    li x23, 545
    li x24, 867
    li x25, 220
    li x26, 763
    li x27, 302
    li x28, 31
    li x29, 442
    li x30, 130
    li x31, 858

    # 4. Randomized Instruction Stream (Seed: 13)
    lbu     x6, 0(s0)
    xori    x29, x17, -57
    sw      x18, 128(s0)
    bltu    x21, x16, fuzz_br_0
    addi    x31, x16, 41
    addi    x13, x23, 8
fuzz_br_0:
    sltiu   x25, x17, -59
    srliw   x20, x7, 12
    slti    x11, x14, 6
    lwu     x18, 200(s0)
    sllw    x31, x9, x6
    sraiw   x15, x1, 2
    sraiw   x28, x25, 16
    srliw   x26, x30, 22
    srli    x19, x25, 30
    ld      x21, 104(s0)
    sh      x7, 16(s0)
    sraw    x28, x24, x5
    bne     x4, x16, fuzz_br_1
    addi    x17, x29, 22
fuzz_br_1:
    sh      x5, 0(s0)
    slli    x21, x22, 60
    or      x1, x13, x6
    slliw   x10, x24, 18
    lw      x26, 192(s0)
    slliw   x24, x29, 16
    subw    x14, x27, x21
    srlw    x23, x14, x3
    addiw   x4, x4, -126
    sb      x20, 152(s0)
    and     x12, x19, x6
    sll     x5, x14, x9
    srliw   x12, x3, 8
    sraiw   x17, x21, 2
    addi    x6, x28, 37
    subw    x31, x1, x30
    sh      x4, 40(s0)
    subw    x3, x25, x24
    bne     x19, x28, fuzz_br_2
    addi    x9, x21, 26
    addi    x22, x3, 36
fuzz_br_2:
    beq     x22, x6, fuzz_br_3
    addi    x20, x15, 20
    addi    x6, x20, 20
fuzz_br_3:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
