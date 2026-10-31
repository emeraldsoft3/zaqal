.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 464
    li x3, 887
    li x4, 574
    li x5, 878
    li x6, 947
    li x7, 800
    li x9, 477
    li x10, 463
    li x11, 521
    li x12, 876
    li x13, 602
    li x14, 195
    li x15, 190
    li x16, 824
    li x17, 525
    li x18, 488
    li x19, 645
    li x20, 629
    li x21, 813
    li x22, 191
    li x23, 97
    li x24, 458
    li x25, 311
    li x26, 146
    li x27, 93
    li x28, 552
    li x29, 830
    li x30, 912
    li x31, 711

    # 4. Randomized Instruction Stream (Seed: 11)
    lhu     x26, 200(s0)
    lbu     x19, 80(s0)
    srl     x9, x31, x22
    slliw   x13, x17, 14
    sd      x17, 248(s0)
    lbu     x4, 208(s0)
    lwu     x12, 160(s0)
    sra     x15, x5, x15
    add     x30, x24, x9
    and     x18, x15, x16
    sllw    x27, x24, x13
    slli    x1, x16, 17
    xor     x1, x3, x28
    subw    x17, x19, x26
    ld      x15, 208(s0)
    sraw    x1, x11, x12
    beq     x9, x7, fuzz_br_0
    addi    x30, x22, 42
    addi    x21, x5, 3
fuzz_br_0:
    bne     x17, x11, fuzz_br_1
    addi    x27, x22, 22
fuzz_br_1:
    bge     x4, x4, fuzz_br_2
    addi    x9, x21, 41
fuzz_br_2:
    slti    x14, x22, -63
    bge     x29, x21, fuzz_br_3
    addi    x30, x15, 12
fuzz_br_3:
    lbu     x22, 152(s0)
    sraw    x7, x26, x9
    lwu     x4, 192(s0)
    slt     x5, x3, x11
    sraiw   x11, x16, 18
    xor     x6, x10, x20
    sw      x26, 32(s0)
    srai    x16, x17, 7
    srli    x14, x19, 11
    slliw   x13, x24, 2
    bge     x14, x25, fuzz_br_4
    addi    x3, x1, 39
    addi    x23, x4, 31
fuzz_br_4:
    slli    x13, x6, 9
    srli    x26, x3, 43
    sraiw   x31, x4, 1
    bltu    x1, x22, fuzz_br_5
    addi    x15, x21, 1
    addi    x22, x4, 6
fuzz_br_5:
    and     x11, x31, x26

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
