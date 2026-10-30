.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 979
    li x3, 884
    li x4, 971
    li x5, 870
    li x6, 58
    li x7, 94
    li x9, 87
    li x10, 370
    li x11, 856
    li x12, 174
    li x13, 754
    li x14, 829
    li x15, 686
    li x16, 875
    li x17, 316
    li x18, 258
    li x19, 621
    li x20, 218
    li x21, 622
    li x22, 37
    li x23, 596
    li x24, 698
    li x25, 163
    li x26, 442
    li x27, 654
    li x28, 403
    li x29, 823
    li x30, 741
    li x31, 881

    # 4. Randomized Instruction Stream (Seed: 2)
    blt     x20, x17, fuzz_br_0
    addi    x31, x3, 2
    addi    x14, x17, 21
fuzz_br_0:
    bge     x31, x31, fuzz_br_1
    addi    x20, x7, 16
fuzz_br_1:
    subw    x13, x7, x19
    srlw    x31, x17, x26
    andi    x28, x21, 57
    bge     x7, x27, fuzz_br_2
    addi    x25, x26, 30
    addi    x23, x19, 16
fuzz_br_2:
    srliw   x19, x19, 29
    bge     x14, x21, fuzz_br_3
    addi    x18, x24, 15
    addi    x13, x29, 45
fuzz_br_3:
    bltu    x11, x27, fuzz_br_4
    addi    x12, x12, 46
    addi    x29, x19, 36
fuzz_br_4:
    slliw   x12, x26, 31
    or      x28, x29, x26
    addw    x26, x5, x21
    lhu     x31, 136(s0)
    bltu    x6, x30, fuzz_br_5
    addi    x10, x29, 14
    addi    x31, x3, 28
fuzz_br_5:
    beq     x3, x14, fuzz_br_6
    addi    x7, x10, 44
    addi    x1, x4, 8
fuzz_br_6:
    beq     x3, x26, fuzz_br_7
    addi    x14, x11, 9
fuzz_br_7:
    bne     x26, x7, fuzz_br_8
    addi    x15, x21, 3
fuzz_br_8:
    sd      x1, 120(s0)
    xor     x12, x13, x1
    and     x31, x11, x30
    sw      x4, 72(s0)
    ld      x17, 160(s0)
    lbu     x15, 64(s0)
    andi    x6, x30, 4

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
