.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 475
    li x3, 628
    li x4, 383
    li x5, 274
    li x6, 142
    li x7, 191
    li x9, 888
    li x10, 693
    li x11, 7
    li x12, 347
    li x13, 515
    li x14, 475
    li x15, 920
    li x16, 620
    li x17, 83
    li x18, 343
    li x19, 568
    li x20, 959
    li x21, 632
    li x22, 717
    li x23, 42
    li x24, 746
    li x25, 389
    li x26, 174
    li x27, 721
    li x28, 969
    li x29, 463
    li x30, 975
    li x31, 743

    # 4. Randomized Instruction Stream (Seed: 9)
    addw    x10, x3, x6
    and     x27, x25, x28
    lw      x24, 48(s0)
    srliw   x31, x4, 13
    srai    x28, x3, 0
    beq     x31, x15, fuzz_br_0
    addi    x6, x1, 16
    addi    x16, x26, 8
fuzz_br_0:
    beq     x5, x27, fuzz_br_1
    addi    x31, x30, 13
fuzz_br_1:
    add     x6, x20, x19
    sraiw   x20, x9, 4
    sll     x25, x21, x7
    bgeu    x3, x3, fuzz_br_2
    addi    x20, x24, 39
    addi    x30, x6, 48
fuzz_br_2:
    and     x5, x30, x31
    slt     x26, x14, x21
    sub     x30, x14, x30
    blt     x17, x9, fuzz_br_3
    addi    x9, x21, 48
    addi    x1, x15, 39
fuzz_br_3:
    slliw   x5, x9, 28
    sra     x12, x23, x5
    slt     x1, x15, x28
    srai    x25, x27, 8
    srlw    x5, x27, x19
    ori     x6, x24, -41
    sw      x11, 128(s0)
    beq     x22, x6, fuzz_br_4
    addi    x3, x3, 29
fuzz_br_4:
    addiw   x12, x22, 53
    slliw   x20, x11, 5
    ld      x16, 144(s0)
    slliw   x21, x31, 17
    sd      x11, 248(s0)
    addw    x28, x23, x7
    lw      x7, 112(s0)
    sraiw   x4, x7, 16
    and     x21, x21, x20
    sltu    x31, x23, x20
    beq     x26, x10, fuzz_br_5
    addi    x5, x5, 45
fuzz_br_5:
    add     x18, x31, x24
    sb      x10, 184(s0)
    addiw   x31, x10, -85

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
