.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 242
    li x3, 311
    li x4, 106
    li x5, 739
    li x6, 406
    li x7, 491
    li x9, 159
    li x10, 93
    li x11, 69
    li x12, 21
    li x13, 412
    li x14, 563
    li x15, 940
    li x16, 297
    li x17, 820
    li x18, 784
    li x19, 61
    li x20, 228
    li x21, 533
    li x22, 550
    li x23, 369
    li x24, 284
    li x25, 799
    li x26, 177
    li x27, 847
    li x28, 109
    li x29, 269
    li x30, 220
    li x31, 966

    # 4. Randomized Instruction Stream (Seed: 4)
    bgeu    x28, x11, fuzz_br_0
    addi    x9, x7, 20
    addi    x12, x23, 47
fuzz_br_0:
    blt     x4, x30, fuzz_br_1
    addi    x24, x15, 33
    addi    x10, x7, 16
fuzz_br_1:
    slt     x29, x30, x29
    ori     x21, x25, -29
    srli    x16, x17, 29
    xor     x4, x3, x23
    bltu    x20, x23, fuzz_br_2
    addi    x25, x13, 10
    addi    x24, x9, 5
fuzz_br_2:
    srlw    x23, x23, x11
    srliw   x26, x21, 12
    beq     x29, x3, fuzz_br_3
    addi    x11, x27, 38
fuzz_br_3:
    sw      x12, 120(s0)
    sub     x14, x25, x31
    blt     x26, x24, fuzz_br_4
    addi    x1, x13, 19
    addi    x13, x6, 50
fuzz_br_4:
    sw      x31, 32(s0)
    sraw    x11, x15, x7
    xor     x14, x3, x7
    slli    x12, x21, 56
    bge     x9, x5, fuzz_br_5
    addi    x3, x3, 48
fuzz_br_5:
    sraw    x22, x3, x18
    sltiu   x3, x5, 21
    lw      x18, 208(s0)
    addiw   x16, x18, -16
    srlw    x23, x31, x29
    sllw    x3, x3, x11
    srlw    x27, x10, x30
    andi    x3, x31, -69
    bge     x31, x23, fuzz_br_6
    addi    x18, x15, 6
fuzz_br_6:
    srlw    x13, x12, x28
    blt     x29, x16, fuzz_br_7
    addi    x23, x28, 44
fuzz_br_7:
    blt     x15, x18, fuzz_br_8
    addi    x30, x11, 41
fuzz_br_8:
    sw      x27, 16(s0)
    bgeu    x30, x3, fuzz_br_9
    addi    x25, x23, 30
fuzz_br_9:
    addiw   x15, x9, -20
    beq     x22, x31, fuzz_br_10
    addi    x5, x15, 50
    addi    x28, x15, 15
fuzz_br_10:
    sraw    x7, x24, x13

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
