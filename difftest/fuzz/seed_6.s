.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 813
    li x3, 588
    li x4, 842
    li x5, 83
    li x6, 497
    li x7, 781
    li x9, 268
    li x10, 38
    li x11, 1
    li x12, 150
    li x13, 679
    li x14, 601
    li x15, 482
    li x16, 989
    li x17, 778
    li x18, 753
    li x19, 383
    li x20, 328
    li x21, 789
    li x22, 23
    li x23, 280
    li x24, 501
    li x25, 822
    li x26, 203
    li x27, 748
    li x28, 894
    li x29, 424
    li x30, 933
    li x31, 552

    # 4. Randomized Instruction Stream (Seed: 6)
    slt     x9, x21, x25
    blt     x24, x28, fuzz_br_0
    addi    x30, x16, 22
fuzz_br_0:
    blt     x28, x16, fuzz_br_1
    addi    x17, x25, 7
    addi    x27, x9, 45
fuzz_br_1:
    sd      x21, 144(s0)
    bgeu    x14, x18, fuzz_br_2
    addi    x19, x21, 42
fuzz_br_2:
    bltu    x1, x23, fuzz_br_3
    addi    x10, x22, 28
    addi    x12, x14, 38
fuzz_br_3:
    sllw    x5, x22, x12
    sw      x22, 192(s0)
    sll     x9, x27, x1
    sb      x12, 152(s0)
    sraiw   x3, x7, 25
    addiw   x10, x28, 100
    sraiw   x28, x4, 30
    srliw   x4, x9, 28
    sraw    x1, x1, x5
    sltiu   x9, x11, 103
    xori    x16, x31, 120
    sraiw   x24, x18, 9
    sb      x13, 248(s0)
    sraw    x22, x15, x11
    slliw   x18, x26, 18
    addiw   x3, x7, -71
    sb      x30, 184(s0)
    sraw    x6, x11, x1
    slliw   x4, x18, 6
    subw    x24, x23, x22
    sub     x23, x24, x25
    addiw   x17, x26, -113
    ld      x7, 64(s0)
    lhu     x17, 128(s0)
    sll     x28, x23, x29
    bge     x18, x27, fuzz_br_4
    addi    x17, x20, 18
    addi    x18, x25, 38
fuzz_br_4:
    andi    x14, x12, -111
    slti    x11, x11, 92
    slli    x3, x25, 31
    bgeu    x10, x20, fuzz_br_5
    addi    x26, x7, 22
fuzz_br_5:
    srl     x26, x27, x25

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
