# FPU Divider & Square Root Algorithm (Radix-16 vs. Radix-2)

When computing high-latency floating-point division (`FDIV`) and square roots (`FSQRT`), processors balance hardware area against cycle latency.

## 1. The Options

### Option A: Radix-2 Restoring/Non-Restoring (The Baseline)
- **Mechanism**: Computes 1 bit of precision per cycle via shift-and-subtract.
- **Latency**: ~24-30 cycles for Float32.
- **Pros**: Extremely low area, zero complex logic.

### Option B: Multiplicative Iteration (Newton-Raphson / Goldschmidt)
- **Mechanism**: Re-uses high-speed Fused Multiply-Add (FMA) pipelines to run quadratic-converging precision loops. 
- **Latency**: ~10-15 cycles.
- **Cons**: Severe pipeline hijacking of the FMA units.

### Option C: Digit-Recurrence SRT-16 (The Golden Standard)
- **Mechanism**: Calculates 4 quotient bits per cycle. Employs Carry-Save Adders (CSAs) and lookup tables to guess next-bit sequences.
- **Latency**: ~11 cycles for Single Precision.
- **Pros**: Dedicated logic avoids FMA bottlenecking.

## 2. Industry Parity: What does XiangShan do?
The **XiangShan Kunminghu** core transitions from SRT-4 directly to **SRT-16** algorithms (supported by the `fudian` project), dropping single-precision latency down to roughly $\le 11$ cycles.

## 3. Zaqal Decision
For Phase 3 functional milestone testing, Zaqal retains the simple **Radix-2 state machine**. However, to achieve world-class parity, upgrading execution units to a pipelined **SRT-16 architecture** is slated for evaluation during Phase 5/Phase 7 optimization.
