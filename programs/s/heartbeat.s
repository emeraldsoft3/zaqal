# ZAQAL Agile V1.0 Test
# This program increments x1 and loops forever

.section .text
.globl _start

_start:
    addi x1, x0, 1      # x1 = 0 + 1  (Assignment)
    addi x2, x0, 10     # x2 = 0 + 10 (Our 'Limit')
loop:
    addi x1, x1, 1      # x1 = x1 + 1 (Addition)
    jal x0, loop        # Jump back to 'loop' (Branching/Redirect)