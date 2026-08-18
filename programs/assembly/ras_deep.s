# RAS Deep Data Recovery Verification
# This program tests the Return Address Stack (RAS) recovery mechanism
# upon a branch misprediction in a deep call stack.

.globl _start
_start:
    # Initialize stack pointer and registers
    li sp, 0x80000000
    li x10, 0
    li x11, 5  # Loop counter

main_loop:
    # Call depth 1
    jal ra, func_depth1
    
    # Check if loop is done
    addi x11, x11, -1
    bnez x11, main_loop
    
    # End program
    j end_program

func_depth1:
    # Call depth 2
    addi sp, sp, -16
    sd ra, 8(sp)
    
    jal ra, func_depth2
    
    # Return from depth 1
    ld ra, 8(sp)
    addi sp, sp, 16
    ret

func_depth2:
    # Call depth 3
    addi sp, sp, -16
    sd ra, 8(sp)
    
    jal ra, func_depth3
    
    # Return from depth 2
    ld ra, 8(sp)
    addi sp, sp, 16
    ret

func_depth3:
    # Deepest level, inject a conditional branch that will mispredict
    # and cause a rollback, which should restore the spec_stack from arch_stack
    li x12, 1
    
    # This branch is highly predictable after the first iteration,
    # but the mispredict (either early or late) will test RAS rollback
    beq x12, zero, wrong_path
    
    # Correct path return
    ret

wrong_path:
    # If the core incorrectly speculates down this path, it will execute a false RET
    # This false RET pops from the RAS speculative stack.
    # When the BEQ resolves as mispredicted, the ROB flush MUST restore the RAS
    # so that the actual RET on the correct path uses the right return address.
    ret

end_program:
    nop
    nop
    nop
