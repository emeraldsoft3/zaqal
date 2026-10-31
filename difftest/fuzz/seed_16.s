.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top
    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)
    la s0, _scratchpad_start
    # 3. Initialize all free registers to known non-zero values
    li x1, 371
    li x3, 481
    li x4, 493
    li x5, 292
    li x6, 427
    li x7, 233
    li x9, 458
    li x10, 6
    li x11, 420
    li x12, 875
    li x13, 674
    li x14, 729
    li x15, 266
    li x16, 244
    li x17, 651
    li x18, 228
    li x19, 11
    li x20, 304
    li x21, 310
    li x22, 835
    li x23, 344
    li x24, 683
    li x25, 146
    li x26, 975
    li x27, 762
    li x28, 617
    li x29, 318
    li x30, 23
    li x31, 809

    # 4. Randomized Instruction Stream (Seed: 16)
    srli    x1, x31, 3
    ori     x10, x28, 57
    and     x14, x18, x19
    lh      x4, 144(s0)
    beq     x19, x14, fuzz_br_0
    addi    x18, x6, 20
fuzz_br_0:
    slliw   x17, x4, 30
    sb      x1, 0(s0)
    bge     x25, x28, fuzz_br_1
    addi    x17, x29, 40
fuzz_br_1:
    srl     x6, x25, x15
    beq     x20, x3, fuzz_br_2
    addi    x22, x13, 31
    addi    x19, x24, 44
fuzz_br_2:
    sd      x25, 32(s0)
    and     x10, x1, x23
    add     x26, x24, x30
    lhu     x11, 72(s0)
    srl     x10, x19, x5
    srlw    x11, x15, x3
    addiw   x17, x11, -98
    sllw    x16, x24, x19
    addw    x5, x16, x12
    sraiw   x6, x29, 15
    srlw    x31, x15, x19
    srlw    x14, x24, x29
    sraiw   x9, x24, 1
    slli    x5, x30, 39
    lb      x9, 120(s0)
    addw    x18, x20, x27
    lh      x3, 48(s0)
    addiw   x26, x27, 43
    and     x25, x14, x12
    subw    x9, x17, x25
    and     x10, x13, x22
    sd      x15, 24(s0)
    lwu     x25, 72(s0)
    bne     x19, x28, fuzz_br_3
    addi    x19, x1, 40
    addi    x22, x28, 33
fuzz_br_3:
    bge     x21, x18, fuzz_br_4
    addi    x6, x25, 30
    addi    x26, x25, 12
fuzz_br_4:
    sra     x4, x14, x23
    beq     x6, x3, fuzz_br_5
    addi    x22, x25, 49
fuzz_br_5:

    # 5. End of Random Sequence -> Infinite Loop
fuzz_done:
    j fuzz_done
