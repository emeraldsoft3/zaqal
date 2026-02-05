int main() {
    int counter = 1;    // x1
    int limit = 64;     // x2
    int total_sum = 0;  // x4

    while (counter < limit) {       // This loop starts at PC 0x0C
        total_sum += counter;       // add x4, x4, x1
        int temp = counter;         // add x5, x0, x1
        int divisor = 2;            // addi x6, x0, 2

        // Inner logic: Even/Odd check
        if (temp % divisor == 0) {  // div x8, x5, x6 then mul/bne
            total_sum += counter;   // Bonus add if even (PC 0x24)
        }

        // Long straight path (the addi x4, x4, 1 block)
        total_sum += 16;            // Representing the 16 individual addis

        counter++;                  // addi x1, x1, 1
    }                               // blt x1, x2, back to start

    int average = total_sum / 64;

    while(1); // jal x0, 0 (Infinite halt)
}