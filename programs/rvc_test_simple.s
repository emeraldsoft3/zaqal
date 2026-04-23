.section .text
.global _start
_start:
    # --- RVC Verification Test ---
    li x10, 0          # x10 = 0 (32-bit inst)
    c.li x10, 5        # x10 = 5 (16-bit inst)
    c.addi x10, 10     # x10 = 15 (16-bit inst)
    li x11, 2          # x11 = 2 (32-bit inst)
    c.add x10, x11     # x10 = 17 (16-bit inst)
    
    # Check if x10 is 17 (0x11)
    # Success markers
    li x12, 0x11       # Success expected value
    
    # Infinite loop to halt
halt:
    j halt
