.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 655
    li x3, 115
    li x4, 26
    li x5, 760
    li x6, 282
    li x7, 251
    li x9, 229
    li x10, 143
    li x11, 755
    li x12, 105
    li x13, 693
    li x14, 759
    li x15, 914
    li x16, 559
    li x17, 90
    li x18, 605
    li x19, 433
    li x20, 33
    li x21, 31
    li x22, 96
    li x23, 224
    li x24, 239
    li x25, 518
    li x26, 617
    li x27, 28
    li x28, 575
    li x29, 204
    li x30, 734
    li x31, 666

    # 4. Randomized Instruction Stream (Seed: 42)
    sh      x28, 208(s0)
    bne     x25, x16, fuzz_br_0
    addi    x11, x6, 14
    addi    x27, x13, 7
fuzz_br_0:
    or      x14, x30, x22
    slt     x26, x17, x5
    bge     x4, x20, fuzz_br_1
    addi    x29, x23, 40
    addi    x31, x30, 24
fuzz_br_1:
    srl     x3, x24, x27
    sub     x30, x10, x15
    andi    x7, x14, -21
    lw      x20, 32(s0)
    sh      x23, 80(s0)
    lbu     x27, 112(s0)
    lbu     x13, 112(s0)
    or      x9, x21, x9
    lhu     x17, 200(s0)
    sraw    x10, x26, x20
    sraiw   x31, x21, 23
    addw    x19, x18, x27
    sll     x6, x23, x28
    sb      x19, 32(s0)
    sub     x24, x26, x24
    blt     x27, x23, fuzz_br_2
    addi    x5, x12, 28
    addi    x7, x17, 1
fuzz_br_2:
    bgeu    x11, x19, fuzz_br_3
    addi    x19, x5, 41
fuzz_br_3:
    subw    x6, x14, x20
    bltu    x1, x22, fuzz_br_4
    addi    x18, x1, 8
    addi    x14, x31, 20
fuzz_br_4:
    addw    x31, x21, x4
    lwu     x27, 32(s0)
    srliw   x20, x7, 27
    bltu    x27, x26, fuzz_br_5
    addi    x25, x12, 26
fuzz_br_5:
    bgeu    x14, x17, fuzz_br_6
    addi    x5, x10, 15
    addi    x4, x13, 2
fuzz_br_6:
    addw    x21, x10, x4
    sd      x30, 24(s0)
    srlw    x11, x24, x9
    sraiw   x10, x28, 26
    or      x24, x16, x16
    sub     x24, x23, x3

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
