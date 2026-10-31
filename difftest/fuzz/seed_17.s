.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 535
    li x3, 425
    li x4, 827
    li x5, 311
    li x6, 984
    li x7, 375
    li x9, 297
    li x10, 179
    li x11, 785
    li x12, 723
    li x13, 722
    li x14, 554
    li x15, 678
    li x16, 285
    li x17, 113
    li x18, 940
    li x19, 28
    li x20, 255
    li x21, 394
    li x22, 835
    li x23, 765
    li x24, 430
    li x25, 259
    li x26, 881
    li x27, 514
    li x28, 822
    li x29, 326
    li x30, 656
    li x31, 867

    # 4. Randomized Instruction Stream (Seed: 17)
    sd      x6, 200(s0)
    bne     x6, x31, fuzz_br_0
    addi    x13, x20, 8
fuzz_br_0:
    bgeu    x4, x12, fuzz_br_1
    addi    x4, x19, 31
    addi    x23, x22, 10
fuzz_br_1:
    lh      x1, 208(s0)
    or      x31, x27, x3
    blt     x21, x27, fuzz_br_2
    addi    x30, x15, 16
fuzz_br_2:
    sllw    x10, x19, x3
    sltiu   x9, x26, -62
    srli    x14, x13, 42
    addi    x13, x1, 50
    addi    x18, x23, -27
    xor     x26, x25, x1
    sb      x7, 64(s0)
    slli    x6, x24, 27
    andi    x28, x31, 33
    srliw   x4, x25, 16
    sd      x20, 200(s0)
    sh      x21, 120(s0)
    slti    x3, x26, 73
    bne     x20, x16, fuzz_br_3
    addi    x4, x17, 49
    addi    x9, x10, 31
fuzz_br_3:
    addw    x14, x22, x26
    srliw   x3, x31, 10
    bltu    x10, x22, fuzz_br_4
    addi    x14, x7, 49
    addi    x9, x12, 28
fuzz_br_4:
    slt     x19, x5, x1
    srlw    x17, x17, x30
    srliw   x17, x1, 16
    xor     x29, x31, x13
    sd      x19, 104(s0)
    sb      x25, 0(s0)
    bltu    x9, x27, fuzz_br_5
    addi    x27, x29, 2
fuzz_br_5:
    addw    x30, x23, x30
    slt     x16, x3, x3
    andi    x11, x14, 85
    or      x19, x27, x4
    lbu     x12, 16(s0)
    slt     x13, x6, x29
    sraiw   x29, x12, 7

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
