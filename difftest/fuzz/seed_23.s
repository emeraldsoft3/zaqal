.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 948
    li x3, 799
    li x4, 972
    li x5, 297
    li x6, 914
    li x7, 850
    li x9, 86
    li x10, 18
    li x11, 607
    li x12, 315
    li x13, 434
    li x14, 389
    li x15, 543
    li x16, 367
    li x17, 134
    li x18, 744
    li x19, 197
    li x20, 274
    li x21, 456
    li x22, 15
    li x23, 227
    li x24, 636
    li x25, 466
    li x26, 924
    li x27, 26
    li x28, 109
    li x29, 88
    li x30, 728
    li x31, 511

    # 4. Randomized Instruction Stream (Seed: 23)
    addiw   x14, x27, -23
    lwu     x9, 184(s0)
    blt     x21, x27, fuzz_br_0
    addi    x21, x12, 43
    addi    x13, x21, 6
fuzz_br_0:
    bne     x25, x18, fuzz_br_1
    addi    x24, x23, 11
    addi    x7, x28, 12
fuzz_br_1:
    addw    x21, x5, x5
    andi    x21, x11, -73
    slti    x20, x12, -17
    sub     x22, x28, x25
    sw      x26, 248(s0)
    addiw   x7, x17, -100
    sw      x24, 200(s0)
    addw    x28, x26, x20
    bge     x26, x4, fuzz_br_2
    addi    x1, x28, 25
    addi    x18, x9, 3
fuzz_br_2:
    sraiw   x20, x9, 18
    sll     x20, x19, x25
    srlw    x11, x5, x7
    bge     x27, x13, fuzz_br_3
    addi    x29, x7, 40
    addi    x25, x28, 27
fuzz_br_3:
    srlw    x20, x12, x16
    sub     x29, x12, x1
    lhu     x29, 168(s0)
    sllw    x24, x4, x20
    sb      x28, 56(s0)
    xori    x1, x13, -116
    lb      x9, 72(s0)
    sb      x26, 8(s0)
    sra     x16, x25, x18
    sllw    x19, x20, x11
    beq     x10, x31, fuzz_br_4
    addi    x30, x31, 32
fuzz_br_4:
    sltu    x24, x17, x16
    ori     x16, x14, 12
    blt     x7, x15, fuzz_br_5
    addi    x16, x31, 43
fuzz_br_5:
    slli    x20, x11, 49
    sltiu   x30, x6, 61
    sraiw   x5, x11, 0
    blt     x28, x30, fuzz_br_6
    addi    x10, x27, 37
fuzz_br_6:
    sd      x11, 16(s0)

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
