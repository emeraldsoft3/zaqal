.section .text
.global _start
_start:
    li sp, 0x80001000 # Simple stack
    call main
loop:
    j loop
