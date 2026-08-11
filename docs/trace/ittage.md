# TAGE and ITTAGE Prediction Subsystem Trace Analysis

This document provides a comprehensive guide to understanding, tracing, and verifying the TAGE (conditional branch) and ITTAGE (indirect jump) branch prediction subsystems within the Zaqal processor. It contains the assembly program breakdown, a mapping C program, a cycle-by-cycle execution trace analysis, and a GTKWave verification signal guide.

---

## 1. Assembly Program Structure (`ICache.scala`)

The hardcoded stress-test program in `ICache.scala` is specifically designed to test both conditional branch direction prediction and indirect branch target prediction with alternating outcomes.

Here is the disassembled program with memory offsets (assuming PC starts at `0x8000_0000`, mapping to index `0x00` in the relative PC space):

```assembly
; Relative PC: Instruction Hex       ; Disassembly & Explanation
0x00:          0x00a00093           ; addi x1, x0, 10   (Outer loop counter: x1 = 10)
0x04:          0x00000293           ; addi x5, x0, 0    (Alternating index counter: x5 = 0)

; --- LOOP START ---
0x08:          0x00628293           ; addi x5, x5, 6    (Increment alternating counter by 6)
0x0c:          0x0032f713           ; andi x14, x5, 3   (x14 = x5 % 4; sequence: 2, 0, 2, 0, 2...)
0x10:          0x00070463           ; beq x14, x0, 8    (Taken if x14 == 0; Jumps 8 bytes to 0x18)
0x14:          0x00100793           ; addi x15, x0, 1   (Executed only on odd iterations where x14 != 0)
0x18:          0x00271893           ; slli x17, x14, 2  (x17 = x14 * 4; alternates: 8 on odd, 0 on even)
0x1c:          0x0140026f           ; jal x4, 20        (Jump-and-link 20 bytes to 0x30; save pc+4 [0x20] in x4)

; --- INDIRECT TARGETS ---
0x20:          0x00a00793           ; addi x15, x0, 10  (Target A: Executed when x14 == 0)
0x24:          0x0180006f           ; jal x0, 24        ; Jump to Loop End (0x24 + 24 = 0x3c)
0x28:          0x01400793           ; addi x15, x0, 20  (Target B: Executed when x14 == 2)
0x2c:          0x0100006f           ; jal x0, 16        ; Jump to Loop End (0x2c + 16 = 0x3c)

; --- INDIRECT JUMP HELPER ---
0x30:          0x01120233           ; add x4, x4, x17   (x4 = 0x20 + x17; alternates: 0x28 on odd, 0x20 on even)
0x34:          0x000200e7           ; jalr x1, x4, 0    (Dynamic indirect jump to Target A or Target B; save pc+4 [0x38] in x1)

; --- LOOP DECREMENT (BYPASSED) ---
0x38:          0xfff08093           ; addi x1, x1, -1   (Bypassed! Target A & B jump directly to 0x3c)

; --- LOOP END & BRANCH BACK ---
0x3c:          0xfc0096e3           ; bne x1, x0, -52   (If x1 != 0, branch to Loop Start at 0x08)
0x40:          0x06300613           ; addi x12, x0, 99  (Done marker: x12 = 99)
```

> [!NOTE]
> **Loop Bypassing & Infinite Run Behavior**:
> The `jalr x1, x4, 0` instruction writes its return address (`0x38`) into `x1` during execution. Target A and Target B both end with an unconditional jump (`jal`) directly to `0x3c` (Loop End). Because of this, the decrement instruction at `0x38` is bypassed. Since `x1` contains the return address `0x38` (non-zero) at the end of the loop, the loop branches back to `0x08` infinitely. This provides a stable, long-running stream of branches to stress-test and train the predictors.

---

## 2. C Program Mapping

Below is a clean C program replicating the exact flow of the assembly logic. It illustrates the register state changes, loop control flow, and target switching.

```c
#include <stdio.h>

// Functions representing Target A and Target B jump blocks
void target_a(int *x15) {
    // Corresponds to PC = 0x20
    *x15 = 10;
}

void target_b(int *x15) {
    // Corresponds to PC = 0x28
    *x15 = 20;
}

int main() {
    int x1 = 10;  // Outer loop counter (x1) - initialized to 10
    int x5 = 0;   // Alternating index counter (x5)
    int x14 = 0;  // Condition register (x14)
    int x15 = 0;  // Accumulator/flag register (x15)
    int x17 = 0;  // Target offset register (x17)
    
    // Array of function pointers representing the targets
    void (*targets[])(int*) = { target_a, target_b };
    
    printf("Starting C Simulation of ICache.scala Branch Program...\n");
    
    int iteration = 0;
    while (1) {
        iteration++;
        x5 += 6;
        x14 = x5 & 3; // Equivalent to x5 % 4
        
        // 1. Conditional Branch (beq x14, x0, 8)
        if (x14 == 0) {
            // beq taken: Skip x15 assignment
        } else {
            // beq not taken: Fall through
            x15 = 1;
        }
        
        // 2. Target Offset Calculation (slli x17, x14, 2)
        x17 = x14 * 4; 
        
        // 3. Indirect Target Resolution (add x4, x4, x17)
        // If x14 == 2 (odd iteration), x17 = 8, selecting targets[1] (target_b)
        // If x14 == 0 (even iteration), x17 = 0, selecting targets[0] (target_a)
        int target_index = (x14 == 2) ? 1 : 0;
        
        // 4. Indirect Jump (jalr x1, x4, 0)
        targets[target_index](&x15);
        
        // jalr writes return address (0x38) to x1
        x1 = 0x38;
        
        printf("Iteration %d: x5=%2d, x14=%d, x15=%2d, x17=%d, jumped to Target %c (x1=0x%02x)\n", 
               iteration, x5, x14, x15, x17, (target_index == 1 ? 'B' : 'A'), x1);
        
        // 5. Loop Condition (bne x1, x0, -52)
        if (x1 == 0) {
            break; // Loop exits when x1 == 0 (never happens)
        }
        
        if (iteration >= 10) {
            printf("Limiting trace to 10 iterations to prevent infinite output.\n");
            break;
        }
    }
    
    return 0;
}
```

---

## 3. Cycle-by-Cycle Execution Trace

During simulation, the processor goes through a cold-start training phase before the branch predictor stabilizes.

### Phase 1: Cold Start (Iteration 1: x5 = 6, x14 = 2)
* **`beq x14, x0, 8` (PC = `0x10`)**:
  * Since TAGE tables are empty (valid bits are 0), they all report a miss.
  * BPU defaults to the base predictor (or FTB), which predicts **Not Taken**.
  * The actual outcome is **Not Taken** (`x14` is 2).
  * **Result**: Prediction is correct (Not Taken). No pipeline flush.
* **`jalr x1, x4, 0` (PC = `0x34`)**:
  * The indirect branch predictor (ITTAGE) is cold. It does not hit.
  * The frontend makes a default prediction or does not redirect, resulting in a target misprediction.
  * The instructions are dispatched, and the Backend eventually resolves the `jalr` target as `0x28` (Target B).
  * **Result**: **Target Misprediction**. The Backend asserts `redirect_valid`, flushes the FTQ, and redirects the fetch PC to `0x28`.
  * **Predictor Training**: ITTAGE receives an update request at PC `0x34` with target `0x28` and the current GHR. It allocates an entry in one of its tables (usually Table 0, which has the shortest history).

### Phase 2: Alternating Shift (Iteration 2: x5 = 12, x14 = 0)
* **`beq x14, x0, 8` (PC = `0x10`)**:
  * TAGE lookup occurs. Since Table 0 was allocated, it may or may not match depending on history bits, but if it misses, base predicts **Not Taken**.
  * The actual outcome is **Taken** (since `x14` is 0, jumping to `0x18`).
  * **Result**: **Direction Misprediction**. The Backend detects the misprediction, flushes the pipeline, redirects PC to `0x18`, and updates TAGE.
  * **Predictor Training**: TAGE receives an update request at PC `0x10` with direction **Taken**. It allocates an entry in the tagged tables.
* **`jalr x1, x4, 0` (PC = `0x34`)**:
  * ITTAGE lookup occurs. If the history indexes the same entry as Iteration 1, it might predict `0x28`.
  * The actual target is `0x20` (Target A).
  * **Result**: **Target Misprediction**. Backend flushes the pipeline, redirects to `0x20`, and updates ITTAGE.
  * **Predictor Training**: ITTAGE is updated for PC `0x34` with target `0x20`. Since a misprediction occurred, a new entry is allocated in a table with a longer history (Table 1) using the GHR path history.

### Phase 3: Steady-State Prediction
* After 3-4 iterations, the TAGE and ITTAGE tables contain trained entries.
* The GHR (Global History Register) shifts in the outcomes of previous branches (`0` for Not Taken, `1` for Taken).
* The TAGE tables index using `PC ^ fold(GHR)`. Because of the geometric history lengths (4, 12, 36, 108), the predictor can distinguish PC `0x10` when GHR contains history leading to Taken vs. Not Taken.
* **Result**: Pipeline flushes (`FTQ Flushed!`) cease or drop dramatically, and instructions flow smoothly through the decode/rename/dispatch stages.

---

## 4. GTKWave Verification Guide & Signals

To monitor the training and prediction behavior of TAGE and ITTAGE, load the VCD dump (saved as `programs/vcd/Lithium.vcd` or located in `test_run_dir/*.vcd`) in GTKWave and add the following hierarchical signals.

### A. General Control Signals
Monitor the system state, clock, reset, and instruction stream.
* `TOP.Core.clock` — System clock.
* `TOP.Core.reset` — Reset signal (must be low for normal execution).
* `TOP.Core.frontend.io_pc[63:0]` — Current fetch PC. Look for jumps between loop blocks, Target A (`0x8000_0020`), and Target B (`0x8000_0028`).

### B. Redirect & Training Signals (BPU Update Path)
Look at these signals to see when the Backend corrects the BPU and trains the tables.
* `TOP.Core.frontend.bpu.io_redirect_valid` — Flashes high when a misprediction (target or direction) is resolved.
* `TOP.Core.frontend.bpu.io_redirect_pc[63:0]` — The PC of the instruction that mispredicted (e.g. `0x8000_0010` for `beq`, `0x8000_0034` for `jalr`).
* `TOP.Core.frontend.bpu.io_redirect_target[63:0]` — The correct target address resolved by the backend.
* `TOP.Core.frontend.bpu.io_redirect_taken` — The correct branch direction resolved (high = taken, low = not taken).
* `TOP.Core.frontend.bpu.io_redirect_is_jalr` — High if the redirect was caused by an indirect jump (`jalr`). This distinguishes ITTAGE updates from TAGE updates.

### C. TAGE (Conditional Branch) Monitoring
Trace how TAGE predicts and updates entries.
* `TOP.Core.frontend.bpu.tage.io_pred_hit` — High if TAGE hits in one of the tagged tables (relying on history instead of base prediction).
* `TOP.Core.frontend.bpu.tage.io_pred_taken` — The direction predicted by TAGE (high = taken, low = not taken).
* `TOP.Core.frontend.bpu.tage.io_pred_providerIdx[1:0]` — Which TAGE table (0, 1, 2, or 3) provided the prediction. Higher indexes mean longer history.
* `TOP.Core.frontend.bpu.tage.tables_0.io_allocate` — High when Table 0 is allocating a new entry on a misprediction.
* `TOP.Core.frontend.bpu.tage.tables_1.io_allocate` — High when Table 1 is allocating.

### D. ITTAGE (Indirect Branch) Monitoring
Trace how ITTAGE learns the target addresses.
* `TOP.Core.frontend.bpu.ittage.io_pred_hit` — High if ITTAGE hits. Should start hitting on PC `0x8000_0034` after a few iterations.
* `TOP.Core.frontend.bpu.ittage.io_pred_target[63:0]` — The target address predicted by ITTAGE. Look for it alternating between `0x8000_0020` and `0x8000_0028`.
* `TOP.Core.frontend.bpu.ittage.io_pred_providerIdx[1:0]` — The table index that provided the hit.
* `TOP.Core.frontend.bpu.ittage.tables_0.io_allocate` — Allocating in Table 0.
* `TOP.Core.frontend.bpu.ittage.tables_1.io_allocate` — Allocating in Table 1 (longer history).

### E. History Tracking
* `TOP.Core.frontend.bpu.ghr[127:0]` — The Global History Register. Trace how it shifts values on branch retirement and redirects.
