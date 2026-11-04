
.section .text.init
.globl _start

_start:
    # 1. Set stack pointer
    la sp, _stack_top

    # 2. UART 16550 Base Address: 0x10000000
    li s0, 0x10000000

    # 3. Print ZSBL boot banner
    la s1, zsbl_banner
print_loop:
    lb s2, 0(s1)
    beqz s2, boot_opensbi
    sb s2, 0(s0)
    addi s1, s1, 1
    j print_loop

boot_opensbi:
    # 4. Standard RISC-V Boot Protocol:
    # a0 = current hartid (0)
    li a0, 0
    # a1 = Pointer to Device Tree Blob (DTB) at 0x80400000
    li a1, 0x80400000

    # 5. Jump to OpenSBI entry point at 0x80010000
    li t0, 0x80010000
    jr t0

.section .rodata
zsbl_banner:
    .string "\r\n=======================================================\r\n[ZSBL] Zaqal RV64 6-Wide OoO Zero-Stage Bootloader\r\n[ZSBL] Initializing HartID 0 & DTB at 0x80400000\r\n[ZSBL] Transferring control to OpenSBI at 0x80010000...\r\n=======================================================\r\n"

.section .stack
.align 4
.space 4096
_stack_top:
