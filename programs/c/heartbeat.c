// heartbeat.c
void _start() {
    // addi x1, x0, 1
    int x1 = 1; 
    
    // addi x2, x0, 10
    int x2 = 10; 

    // loop:
    while(1) {
        // addi x1, x1, 1
        x1 = x1 + 1;
        
        // jal x0, loop 
        // (The 'while' loop condition creates the jump back)
    }
}