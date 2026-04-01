# Design Decision: ALU Pipeline Depth (Integer Add Latency)

Perhaps the most fundamental hardware decision in the Execution Stage is whether the simplest integer operations (`ADD`, `SUB`, `AND`, `OR`) actually complete in one hardware cycle.

---

## Option 1: Single-Cycle ALUs
A 64-bit integer addition completes its electrical propagation across the transistors within a single tick of the processor clock.

**Used by**: Classic RISC architectures, Intel Core (Haswell/Skylake), AMD Zen (up to Zen 3), XiangShan.

- **How it works**: The execution unit grabs the data from the PRF, runs the adder combinatorial logic, and blasts the result back onto the bypass network to dependent instructions essentially instantly.
- **The Benefit (Pros)**: Zero-cycle latency on dependent back-to-back additions. If `add x2, x0, 1` is immediately followed by `add x3, x2, 1`, they execute in perfectly adjacent clock cycles without stalling.
- **The Cost (Cons)**: The combinatorial delay of a 64-bit carry-lookahead adder determines the physical speed limit of the *entire* microprocessor. If the adder takes 200 picoseconds to resolve, the processor physically cannot spin faster than 5 GHz.

---

## Option 2: 2-Cycle or Pipelined Standard ALUs
A simple integer addition is forcefully sliced in half into two distinct hardware pipeline stages to artificially raise the clock ceiling.

**Used by**: Intel Pentium 4 (double-pumped ALU exception), AMD Zen 4/5 (in some ultra-high frequency models).

- **How it works**: The 64-bit adder computes the lower 32 bits on Cycle 1, and the upper 32 bits on Cycle 2.
- **The Benefit (Pros)**: Shatters the 5GHz frequency wall. By halving the longest logic path in the processor, you can clock the entire machine incredibly fast (e.g., 6 GHz+).
- **The Cost (Cons)**: Severe IPC degradation. Two dependent `ADD` instructions must now fire 2 cycles apart, creating massive bubbles in integer-heavy workloads unless the Out-of-Order Engine can find perfectly independent instructions to fill the gap.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Phase 3 (ALU/Execution Units) will definitely use **Option 1: Single-Cycle ALUs**. A 64-bit 1-cycle adder is the baseline for almost every state-of-the-art RISC-V design. Slicing an ALU into 2 stages (Option 2) in Chisel makes bypassing and operand forwarding infinitely more complex for very little practical FPGA frequency gain. We will stick to the gold standard 1-cycle integer math.

---

## Recommended Reading / Seminal Papers
- **"The Microarchitecture of the Pentium 4 Processor" (Hinton et al., 2001)**: Famously documents the "Staggered Add" double-pumped ALU, which executed 16-bit halves in half-cycles to achieve record-breaking clock speeds at the cost of crippling IPC.
- **"AMD Zen 4 Microarchitecture Summary"**: Showcases how ultra-modern architectures grapple with the 5GHz wall and when breaking ALUs becomes mathematically viable.
