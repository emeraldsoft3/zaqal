.global _start
_start:
    addi x1, x0, 20
    addi x5, x0, 0
    addi x2, x0, 2
    addi x3, x0, 3
loop_start:
    addi x5, x5, 6
    andi x14, x5, 3
    beq x14, x0, target1
    addi x6, x0, 6
    addi x7, x0, 7
    jal x0, target_join
target1:
    addi x8, x0, 8
    addi x9, x0, 9
target_join:
    slli x17, x14, 2
    jal x4, helper
ret_A:
    addi x10, x0, 10
    jal x0, loop_end
ret_B:
    addi x11, x0, 11
    addi x12, x0, 12
    jal x0, loop_end
helper:
    add x4, x4, x17
    addi x13, x0, 13
    jalr x1, x4, 0
loop_end:
    addi x1, x1, -1
    bne x1, x0, loop_start
done:
    addi x12, x0, 99
    jal x0, done
