#include <stdio.h>

void target_a(int* counter) {
    *counter += 10;
}

void target_b(int* counter) {
    *counter += 11;
}

int main() {
    int counter = 20;
    int state = 0;

    // Simulate the exact logic of sc_test.s
    while (counter != 0) {
        state += 6;
        int cond = state % 4; // andi x14, x5, 3

        void (*func_ptr)(int*);
        
        if (cond == 0) {
            // target1 path
            // (Assembly markers s0=8, s1=9 are executed here)
            
            // Set function pointer for indirect jump later
            func_ptr = &target_a;
        } else {
            // Fallthrough path
            // (Assembly markers t1=6, t2=7 are executed here)
            
            // Set function pointer for indirect jump later
            func_ptr = &target_b;
        }

        // Indirect Jump Simulation (jalr x0, tp, 0 in assembly)
        // ITTAGE Predicts this dynamic jump target!
        func_ptr(&counter);

        counter--; // addi ra, ra, -1
    }
    
    // Done marker
    int done_marker = 99;
    return 0;
}
