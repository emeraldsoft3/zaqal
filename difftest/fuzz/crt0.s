# Minimal CRT0 and Trap Handler for Zaqal Fuzzing
# Places execution at 0x80000000, sets up stack and mtvec, runs test, then halts cleanly.

.section .text.init
.globl _start
_start:
    # 1. Disable interrupts in Machine status
    csrw mstatus, zero
    csrw mie, zero

    # 2. Setup Trap Vector (mtvec) pointing to _trap_handler
    la t0, _trap_handler
    csrw mtvec, t0

    # 3. Setup Stack Pointer
    la sp, _stack_top

    # 4. Clear all General Purpose Registers to known state (0)
    # This prevents Difftest uninitialized register divergences.
    li x1, 0
    li x3, 0
    li x4, 0
    li x5, 0
    li x6, 0
    li x7, 0
    li x8, 0
    li x9, 0
    li x10, 0
    li x11, 0
    li x12, 0
    li x13, 0
    li x14, 0
    li x15, 0
    li x16, 0
    li x17, 0
    li x18, 0
    li x19, 0
    li x20, 0
    li x21, 0
    li x22, 0
    li x23, 0
    li x24, 0
    li x25, 0
    li x26, 0
    li x27, 0
    li x28, 0
    li x29, 0
    li x30, 0
    li x31, 0

    # 5. Jump to the generated fuzz test payload
    jal ra, _fuzz_test_body

    # 6. Success exit: write 1 to tohost and loop
_test_pass:
    la t0, tohost
    li t1, 1
    sd t1, 0(t0)
1:  wfi
    j 1b

    # 7. Trap Handler: if illegal instruction or trap occurs
_trap_handler:
    la t0, tohost
    li t1, 2            # 2 = Failure / unexpected trap
    sd t1, 0(t0)
2:  wfi
    j 2b

.section .tohost
.globl tohost
.align 6
tohost:
    .dword 0
fromhost:
    .dword 0
