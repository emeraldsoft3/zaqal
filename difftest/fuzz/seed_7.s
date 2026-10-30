.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 332
    li x3, 971
    li x4, 155
    li x5, 405
    li x6, 667
    li x7, 50
    li x9, 75
    li x10, 841
    li x11, 549
    li x12, 97
    li x13, 375
    li x14, 597
    li x15, 60
    li x16, 932
    li x17, 520
    li x18, 220
    li x19, 39
    li x20, 89
    li x21, 445
    li x22, 429
    li x23, 72
    li x24, 247
    li x25, 93
    li x26, 565
    li x27, 435
    li x28, 61
    li x29, 847
    li x30, 580
    li x31, 127

    # 4. Randomized Instruction Stream (Seed: 7)
    bgeu    x23, x21, fuzz_br_0
    addi    x21, x21, 26
fuzz_br_0:
    subw    x3, x20, x12
    slt     x21, x12, x29
    lhu     x9, 48(s0)
    sltu    x21, x3, x9
    sraiw   x27, x13, 29
    subw    x28, x7, x4
    sraiw   x31, x13, 18
    sb      x7, 32(s0)
    lb      x3, 72(s0)
    beq     x27, x20, fuzz_br_1
    addi    x13, x25, 23
    addi    x22, x18, 38
fuzz_br_1:
    lh      x18, 32(s0)
    sh      x23, 32(s0)
    sraiw   x12, x25, 22
    addiw   x14, x7, 124
    srai    x6, x26, 50
    sraiw   x4, x7, 25
    sraw    x29, x16, x11
    lb      x10, 176(s0)
    subw    x6, x10, x1
    addw    x11, x12, x6
    andi    x22, x21, -64
    sb      x15, 24(s0)
    and     x18, x23, x3
    addw    x17, x7, x13
    sw      x20, 48(s0)
    slli    x22, x1, 26
    lh      x22, 72(s0)
    xor     x5, x30, x17
    slli    x4, x6, 43
    lw      x19, 240(s0)
    sltiu   x6, x25, -115
    lbu     x4, 152(s0)
    lw      x14, 128(s0)
    lwu     x28, 168(s0)
    lbu     x15, 96(s0)
    sb      x14, 112(s0)
    lb      x11, 8(s0)
    andi    x17, x28, 58

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
