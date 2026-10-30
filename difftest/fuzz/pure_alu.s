.section .text.init
.globl _start
_start:
    # 1. Setup Stack Pointer
    la sp, _stack_top

    # 2. Clear GPRs x1 to x31 using pure ALU (no CSR instructions)
    addi x1,  zero, 0
    addi x3,  zero, 0
    addi x4,  zero, 0
    addi x5,  zero, 0
    addi x6,  zero, 0
    addi x7,  zero, 0
    addi x8,  zero, 0
    addi x9,  zero, 0
    addi x10, zero, 0
    addi x11, zero, 0
    addi x12, zero, 0
    addi x13, zero, 0
    addi x14, zero, 0
    addi x15, zero, 0
    addi x16, zero, 0
    addi x17, zero, 0
    addi x18, zero, 0
    addi x19, zero, 0
    addi x20, zero, 0
    addi x21, zero, 0
    addi x22, zero, 0
    addi x23, zero, 0
    addi x24, zero, 0
    addi x25, zero, 0
    addi x26, zero, 0
    addi x27, zero, 0
    addi x28, zero, 0
    addi x29, zero, 0
    addi x30, zero, 0
    addi x31, zero, 0

    # 3. Arithmetic operations
    addi x10, zero, 42
    addi x11, zero, 58
    add  x12, x10, x11      # x12 = 100
    sub  x13, x12, x10      # x13 = 58
    slli x14, x13, 2        # x14 = 232
    xor  x15, x14, x12

    # 4. Branch test
    beq  x10, x11, 1f       # Not taken
    addi x16, zero, 1
1:
    # 5. Jump back to loop
    j 1b
