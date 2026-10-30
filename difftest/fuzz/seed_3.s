.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 244
    li x3, 607
    li x4, 558
    li x5, 134
    li x6, 379
    li x7, 938
    li x9, 619
    li x10, 486
    li x11, 641
    li x12, 595
    li x13, 68
    li x14, 621
    li x15, 14
    li x16, 931
    li x17, 858
    li x18, 481
    li x19, 266
    li x20, 565
    li x21, 240
    li x22, 197
    li x23, 735
    li x24, 482
    li x25, 554
    li x26, 857
    li x27, 563
    li x28, 488
    li x29, 407
    li x30, 655
    li x31, 882

    # 4. Randomized Instruction Stream (Seed: 3)
    srlw    x30, x19, x26
    sltu    x7, x27, x3
    sra     x29, x30, x18
    sraiw   x25, x28, 25
    lw      x31, 224(s0)
    srl     x6, x18, x11
    bge     x27, x23, fuzz_br_0
    addi    x16, x19, 25
    addi    x21, x14, 35
fuzz_br_0:
    addw    x31, x13, x30
    sllw    x25, x30, x20
    bltu    x5, x25, fuzz_br_1
    addi    x23, x29, 37
fuzz_br_1:
    xor     x4, x18, x4
    sll     x16, x31, x1
    addiw   x30, x5, -105
    ori     x20, x31, -8
    blt     x1, x4, fuzz_br_2
    addi    x22, x20, 3
fuzz_br_2:
    bge     x12, x22, fuzz_br_3
    addi    x6, x25, 3
    addi    x30, x13, 21
fuzz_br_3:
    srlw    x31, x30, x15
    addiw   x23, x30, 10
    sllw    x12, x16, x19
    xori    x1, x28, 33
    sllw    x3, x23, x17
    ori     x22, x25, 122
    or      x24, x1, x11
    lh      x7, 152(s0)
    ori     x27, x14, 25
    ld      x21, 48(s0)
    sw      x23, 64(s0)
    bne     x13, x7, fuzz_br_4
    addi    x23, x25, 7
    addi    x5, x22, 21
fuzz_br_4:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
