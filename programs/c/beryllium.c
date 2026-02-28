int main() {
    // 0x00: addi x1, x0, 9  sometimes this is 9 sometimes this is 10
    int counter = 9;    
    // 0x04: addi x2, x0, 64
    int limit = 11;     
    // 0x08: addi x4, x0, 0
    int total_sum = 0;  

    // Because PC 0x0C is a straight entry into the math, 
    // this is technically a do-while loop in hardware.
    do {
        // 0x0c: add x4, x4, x1
        total_sum += counter;

        // 0x10, 0x14: setup for even/odd
        int temp = counter;
        int divisor = 2;

        // 0x18, 0x1c, 0x20: The Even/Odd check
        // temp / divisor = integer + remainder which is removed
        // than multiply divisor with the integer
        //if it equals temp, than remainder is 0 , temp is odd and addi instruction executes 
        // if its odd, BNE ( bne  x5, x9, 8 ) is TAKEN and the next instruction is skipped
        if (temp % divisor == 0) {
            // 0x24: add x7, x7, x1
            total_sum += 7; 
        }

        // 0x28 through 0x64: The 16 individual addi x4, x4, 1
        total_sum += 16; 

        // 0x68: addi x1, x1, 1
        counter++;

    // 0x6c: blt x1, x2, -72 (The loop condition)
    } while (counter < limit); 

    // 0x70: srli x10, x4, 6 (Right shift by 6 is division by 64)
    int average = total_sum / 64;

    // 0x74: jal x0, 0
    while(1); 
}