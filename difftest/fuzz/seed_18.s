.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 186
    li x3, 126
    li x4, 678
    li x5, 460
    li x6, 343
    li x7, 246
    li x9, 203
    li x10, 975
    li x11, 502
    li x12, 644
    li x13, 506
    li x14, 188
    li x15, 492
    li x16, 303
    li x17, 470
    li x18, 909
    li x19, 271
    li x20, 201
    li x21, 260
    li x22, 921
    li x23, 709
    li x24, 121
    li x25, 333
    li x26, 535
    li x27, 692
    li x28, 781
    li x29, 807
    li x30, 179
    li x31, 887

    # 4. Randomized Instruction Stream (Seed: 18)
    bne     x7, x10, fuzz_br_0
    addi    x26, x14, 37
fuzz_br_0:
    srliw   x9, x25, 16
    sraiw   x10, x27, 22
    ori     x29, x11, -70
    subw    x18, x24, x9
    sraiw   x6, x16, 6
    bne     x21, x11, fuzz_br_1
    addi    x28, x28, 43
    addi    x20, x18, 6
fuzz_br_1:
    addiw   x6, x18, -1
    sb      x28, 176(s0)
    sub     x6, x27, x18
    sraiw   x7, x15, 8
    srliw   x24, x25, 9
    sltiu   x6, x16, -119
    bge     x6, x27, fuzz_br_2
    addi    x22, x26, 42
fuzz_br_2:
    beq     x19, x20, fuzz_br_3
    addi    x20, x5, 1
    addi    x27, x22, 50
fuzz_br_3:
    sraiw   x18, x22, 26
    bne     x10, x7, fuzz_br_4
    addi    x14, x26, 41
fuzz_br_4:
    sub     x27, x29, x14
    lwu     x6, 88(s0)
    blt     x4, x7, fuzz_br_5
    addi    x6, x12, 7
fuzz_br_5:
    sub     x14, x13, x22
    xori    x26, x7, 80
    bge     x26, x19, fuzz_br_6
    addi    x11, x16, 48
fuzz_br_6:
    slli    x15, x11, 27
    slti    x6, x25, -83
    ori     x29, x24, 110
    sub     x10, x25, x30
    slli    x7, x27, 28
    sraiw   x19, x27, 25
    lwu     x23, 232(s0)
    bne     x24, x9, fuzz_br_7
    addi    x4, x15, 43
fuzz_br_7:
    lh      x9, 32(s0)
    sllw    x25, x23, x1
    bne     x25, x25, fuzz_br_8
    addi    x11, x1, 34
    addi    x16, x24, 48
fuzz_br_8:
    slti    x16, x6, -4
    sh      x19, 240(s0)
    srliw   x12, x28, 0

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
