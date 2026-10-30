.section .text
.globl _fuzz_test_body
_fuzz_test_body:
    # Basic ALU checks
    addi x10, zero, 42
    addi x11, zero, 58
    add  x12, x10, x11      # x12 = 100
    sub  x13, x12, x10      # x13 = 58
    slli x14, x13, 2        # x14 = 232
    xor  x15, x14, x12

    # Forward branch test
    beq  x10, x11, 1f       # Not taken
    addi x16, zero, 1
1:
    ret
