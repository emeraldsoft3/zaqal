# Design Decision: Vector/SIMD Hardware Paths

Virtually every modern CPU architecture possesses extensions for executing dense mathematics concurrently on enormous bit widths. For RISC-V, this is the Vector Extension (RVV); for x86, AVX-512; for ARM, NEON or SVE.

---

## Option 1: Strictly Unified Data Paths
The 64-bit Integer ALUs physically stretch into 512-bit Vectors by dynamically re-wiring themselves on the fly.

**Used by**: Early Core architectures, low-power Embedded designs.

- **How it works**: The processor has 8 dedicated 64-bit ALUs. When it receives a 512-bit Vector instruction (which requires computing eight 64-bit integers simultaneously), the processor commandeers all 8 ALUs, locking them up for several cycles to process the single SIMD command.
- **The Benefit (Pros)**: Unbelievably low semiconductor area. The Execution Engine is vastly smaller because it physically doesn't build redundant 512-bit multiplier hardware arrays.
- **The Cost (Cons)**: Terrible contention. If the program runs 1 Vector operation, the 8 ALUs are instantly hijacked. All regular integer work (branching, addressing, loops) completely halts until the Vector finishes.

---

## Option 2: Isolated Floating/Vector Units (FPU/VPU)
The Execution Stage builds a massive, completely separate pipeline consisting solely of 128/256/512-bit execution units.

**Used by**: High-end Intel Core (Golden Cove), AMD Zen 4+, Apple Silicon.

- **How it works**: The Decoder spots a Vector math instruction and sends it to a profoundly discrete Vector Issue Queue. The data lives in a discrete 512-bit Vector Physical Register File (VPRF). The VPU runs it completely independently of the Integer core.
- **The Benefit (Pros)**: Zero IPC degradation on integer math. A 512-bit Vector Matrix Multiply can execute silently in the background while the standard Integer ALUs continue executing branches and addressing code at 5 GHz concurrently.
- **The Cost (Cons)**: Bloats the entire physical silicon footprint by sometimes 40%+. An AVX-512 VPU requires enormous power delivery constraints, frequently forcing the entire chip to downclock by 500 MHz when engaged.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will absolutely adopt **Option 2: Isolated Vector Data Paths** for any Phase 10 implementations of the RISC-V Vector Extension (`V` Extension). High-end cores like XiangShan strictly bifurcate the Integer ALUs from the Floating-Point/Vector execution blocks because mixing them cripples IPC and causes horrendous wire-routing nightmares during place-and-route.

---

## Recommended Reading / Seminal Papers
- **"The RISC-V "V" Vector Extension Specification"**: Delivers the baseline mechanics for decoupled SIMD operations instead of packed AVX semantics.
- **"AMD Zen Microarchitecture: The Float and Vector separation"**: Analysis on how Zen 1 literally severed the Floating Point pipeline completely from the Integer pipeline.
