// rvc_test.c
// Designed to verify RVC (Compressed) instructions in Zaqal

int main() {
    int a = 10;
    int b = 20;
    int result = 0;

    // A loop to ensure branches and arithmetic
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            result += a;
        } else {
            result += b;
        }
    }

    // result should be 10 (i=0) + 20 (i=1) + 10 (i=2) + 20 (i=3) + 10 (i=4) = 70
    // We will check x10 (result) at the end of simulation
    
    // Manual halt for the simulation
    // In a real OS this would be exit(), here we just loop
    while(1);
    
    return result;
}
