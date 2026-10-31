.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 387
    li x3, 787
    li x4, 950
    li x5, 864
    li x6, 864
    li x7, 16
    li x9, 220
    li x10, 954
    li x11, 893
    li x12, 313
    li x13, 652
    li x14, 485
    li x15, 44
    li x16, 879
    li x17, 976
    li x18, 776
    li x19, 262
    li x20, 36
    li x21, 314
    li x22, 579
    li x23, 435
    li x24, 99
    li x25, 603
    li x26, 880
    li x27, 128
    li x28, 590
    li x29, 704
    li x30, 747
    li x31, 853

    # 4. Randomized Instruction Stream (Seed: 25)
    sltiu   x29, x7, 55
    sub     x31, x29, x22
    slliw   x14, x9, 29
    slliw   x21, x4, 2
    srl     x29, x21, x27
    sraiw   x16, x28, 30
    addiw   x12, x7, 81
    bge     x23, x17, fuzz_br_0
    addi    x18, x10, 28
fuzz_br_0:
    lbu     x6, 176(s0)
    subw    x24, x7, x10
    blt     x9, x7, fuzz_br_1
    addi    x14, x12, 24
    addi    x18, x18, 30
fuzz_br_1:
    srliw   x17, x15, 7
    blt     x16, x13, fuzz_br_2
    addi    x25, x21, 40
fuzz_br_2:
    bltu    x1, x7, fuzz_br_3
    addi    x19, x5, 48
    addi    x28, x11, 38
fuzz_br_3:
    lw      x25, 24(s0)
    blt     x31, x7, fuzz_br_4
    addi    x4, x5, 27
    addi    x24, x22, 45
fuzz_br_4:
    sd      x21, 184(s0)
    subw    x20, x25, x4
    sll     x13, x25, x19
    sd      x25, 128(s0)
    sra     x17, x22, x28
    blt     x11, x11, fuzz_br_5
    addi    x30, x7, 18
fuzz_br_5:
    beq     x19, x12, fuzz_br_6
    addi    x12, x4, 48
fuzz_br_6:
    sb      x3, 72(s0)
    addiw   x14, x29, 24
    andi    x27, x6, 85
    sll     x23, x5, x29
    sll     x6, x31, x24
    sltiu   x12, x31, -105
    sltiu   x5, x5, -112
    addiw   x3, x28, -85
    and     x18, x7, x27
    lhu     x24, 136(s0)
    addi    x20, x5, -87
    sraw    x7, x4, x15
    slliw   x4, x22, 24
    sllw    x19, x9, x18

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
