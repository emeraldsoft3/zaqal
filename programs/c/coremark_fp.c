// coremark_fp.c
// A representative floating-point benchmark for Zaqal Phase 3

void _start() {
    // 1. Setup Stack Pointer
    asm volatile ("li sp, 0x80004000");

    // 2. Initialize Floating Point Registers
    volatile float a = 1.234f;
    volatile float b = 2.345f;
    volatile float res = 0.0f;

    // 3. Main Benchmark Loop (Representative CoreMark-FP)
    // We'll do 50 iterations of a FMA-like operation and a division
    for (int i = 0; i < 50; i++) {
        res = (a * b) + a; // FMADD-like
        a = res - b;       // FSUB
        b = res / a;       // FDIV
        
        // Add some complexity to prevent compiler from optimizing too much
        if (b > 10.0f) {
            b = b / 2.0f;
        }
    }

    // 4. Store result to a known memory location (0x80002000)
    float *mem_ptr = (float *)0x80002000;
    *mem_ptr = res;

    // 5. Final Halt
    while(1);
}
