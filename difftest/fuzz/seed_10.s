.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 586
    li x3, 34
    li x4, 440
    li x5, 495
    li x6, 592
    li x7, 16
    li x9, 212
    li x10, 474
    li x11, 833
    li x12, 504
    li x13, 844
    li x14, 285
    li x15, 670
    li x16, 831
    li x17, 165
    li x18, 36
    li x19, 534
    li x20, 502
    li x21, 336
    li x22, 78
    li x23, 256
    li x24, 976
    li x25, 976
    li x26, 764
    li x27, 370
    li x28, 46
    li x29, 431
    li x30, 881
    li x31, 143

    # 4. Randomized Instruction Stream (Seed: 10)
    sh      x17, 192(s0)
    srli    x24, x14, 58
    lwu     x15, 120(s0)
    srl     x10, x6, x12
    sraw    x13, x24, x17
    or      x23, x21, x30
    addw    x16, x10, x3
    sub     x20, x30, x6
    slli    x22, x6, 12
    srlw    x14, x16, x17
    sltiu   x6, x22, -37
    blt     x17, x12, fuzz_br_0
    addi    x24, x23, 12
fuzz_br_0:
    lh      x16, 240(s0)
    or      x13, x31, x10
    slliw   x15, x21, 24
    bge     x24, x31, fuzz_br_1
    addi    x26, x19, 18
fuzz_br_1:
    sraiw   x4, x7, 29
    bne     x16, x20, fuzz_br_2
    addi    x20, x15, 32
    addi    x25, x7, 36
fuzz_br_2:
    addiw   x29, x3, 96
    sll     x14, x4, x5
    sb      x27, 248(s0)
    srliw   x13, x26, 29
    sllw    x26, x10, x22
    sraw    x23, x31, x21
    bge     x1, x28, fuzz_br_3
    addi    x12, x16, 16
fuzz_br_3:
    sd      x29, 40(s0)
    sraiw   x6, x14, 12
    bne     x4, x21, fuzz_br_4
    addi    x16, x9, 7
fuzz_br_4:
    lb      x30, 152(s0)
    sw      x11, 216(s0)
    add     x23, x28, x9
    slliw   x30, x15, 4
    lh      x11, 40(s0)
    srliw   x27, x9, 29
    lh      x15, 248(s0)
    ori     x14, x26, 119
    bge     x21, x18, fuzz_br_5
    addi    x25, x20, 47
fuzz_br_5:
    sraiw   x28, x7, 4
    andi    x1, x21, 36

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
