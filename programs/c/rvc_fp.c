void _start() {
    // 1. Initialize SP and some data
    asm volatile ("li sp, 0x80004000");
    asm volatile ("li a0, 0x80000000");
    
    // 2. Test C.FLD / C.FSD (using registers x8-x15 which are supported by RVC)
    // We'll use a0 (x10) as base and s0 (x8) as floating point reg? 
    // Wait, RVC FP instructions use f8-f15.
    
    asm volatile ("fld f8, 0(a0)");      // Normal FLD
    asm volatile ("c.fsd f8, 8(a0)");    // RVC FSD
    asm volatile ("c.fld f9, 8(a0)");    // RVC FLD
    
    // 3. Test C.FLDSP / C.FSDSP
    asm volatile ("c.fsdsp f9, 0(sp)");  // RVC FSDSP
    asm volatile ("c.fldsp f10, 0(sp)"); // RVC FLDSP
    
    // 4. Final calculation to verify
    asm volatile ("fadd.s f11, f10, f9");
    
    while(1);
}
