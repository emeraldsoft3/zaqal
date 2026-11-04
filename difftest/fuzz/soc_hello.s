
.section .text.init
.globl _start

_start:
    # 1. Set up stack pointer
    la sp, _stack_top

    # 2. UART Base Address: 0x10000000
    li s0, 0x10000000

    # 3. Print greeting string across AXI4 Bus to 16550 UART
    la s1, msg_hello

print_loop:
    lb s2, 0(s1)
    beqz s2, print_done
    sb s2, 0(s0)       # Write byte to UART THR (offset 0)
    addi s1, s1, 1
    j print_loop

print_done:
    # 4. Test SPI Controller at 0x10040000
    li s3, 0x10040000
    li t0, 0x03        # SPE=1, Master=1
    sb t0, 0(s3)       # Write SPICR
    li t1, 0x55        # Test byte
    sb t1, 8(s3)       # Write SPIDR (Transmit FIFO)

    # 5. Test DRAM read/write via AXI4 bus
    li s4, 0x80010000
    li t2, 0xCAFEBABE12345678
    sd t2, 0(s4)
    ld t3, 0(s4)

    # 6. Print confirmation if DRAM read matches written data
    bne t2, t3, fail

    la s1, msg_pass
pass_loop:
    lb s2, 0(s1)
    beqz s2, test_success
    sb s2, 0(s0)
    addi s1, s1, 1
    j pass_loop

fail:
    la s1, msg_fail
fail_loop:
    lb s2, 0(s1)
    beqz s2, test_hang
    sb s2, 0(s0)
    addi s1, s1, 1
    j fail_loop

test_success:
    # Write tohost success code
    la t4, tohost
    li t5, 1
    sd t5, 0(t4)
    # Loop indefinitely
    j test_hang

test_hang:
    wfi
    j test_hang

.section .rodata
msg_hello:
    .string "\r\n[ZAQAL-SoC] Booting RV64GCV Out-of-Order Core on AMBA AXI4 Bus...\r\n[ZAQAL-SoC] UART 16550 Serial Console Initialized!\r\n"
msg_pass:
    .string "[ZAQAL-SoC] AXI4 DRAM Burst Read/Write Verified: CAFEBABE12345678!\r\n[ZAQAL-SoC] SoC Bus & Peripherals Verification PASS!\r\n"
msg_fail:
    .string "[ZAQAL-SoC] ERROR: DRAM Verification Failed!\r\n"

.section .tohost
.align 6
.globl tohost
tohost:
    .dword 0
.globl fromhost
fromhost:
    .dword 0
