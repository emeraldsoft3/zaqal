# Phase 9: AI & Vector ISA (AMX Power)

Zaqal differentiates itself by integrating high-performance 2D matrix operations directly into the backend.

## Goal: Matrix Acceleration & Standard Vector (RVV 1.0)

## Day 1-5: Matrix Functional Unit (AMX) - Foundation
- [ ] **Hardware Architecture**: Define the 2D "Tile" registers for AMX.
- [ ] **Matrix Load/Store**: Implement specialized instructions to load 2D sub-matrices.
- **Detailed Plan**: To accelerate AI workloads, traditional 1D vector processing is inefficient. We will introduce a novel Matrix Functional Unit (AMX) inspired by Apple and Intel architectures. We will define large, 2-dimensional "Tile" architectural registers inside the core that can hold sub-matrices (e.g., 16x16 blocks of 8-bit integers). We will create custom load and store instructions capable of streaming massive continuous chunks of memory directly into these 2D Tile registers, utilizing the full bandwidth of the memory bus.

## Day 6-12: The Matrix Engine (GEMM Acceleration)
- [ ] **Matrix Multiply-Accumulate (MMA)**: Implement the core unit that performs `C += A * B` on 2D tiles.
- [ ] **Precision Support**: Support for Int8, BF16, and FP32 for AI inference.
- **Detailed Plan**: The heart of AI inference is the General Matrix Multiply (GEMM) operation. We will design a systolic array or massive parallel multiplier tree that can execute the `C += A * B` operation entirely in hardware across the 2D Tiles. This Matrix Multiply-Accumulate (MMA) unit will be integrated as a dedicated Execution Cluster within the Out-of-Order backend. We will support highly quantized data types essential for modern neural networks, specifically INT8 and Bfloat16 (BF16), maximizing computational density per clock cycle.
- **Study Reference**: Look at industry standards like Intel AMX or Apple's AMX for ISA inspiration.

## Day 13-17: Vector Register File (VRF) & LMUL
- [ ] Implement VLEN-sized registers (128/256/512-bit).
- [ ] Implement the standard RVV 1.0 configuration registers (vtype, vl).
- **Detailed Plan**: Alongside matrix math, we will fully implement the official RISC-V Vector Extension (RVV 1.0). This requires building a massive Vector Register File (VRF) with configurable widths (VLEN). We will implement the complex RVV state configuration registers (`vtype`, `vl`), which dynamically adjust the vector length and data element widths (e.g., configuring the registers to hold 32-bit floats vs 8-bit integers). We will also support LMUL (Length Multiplier), allowing the architecture to logically group multiple vector registers together to operate on immensely long data vectors.
- **XiangShan Study**: [Bundles.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Bundles.scala)

## Day 18-20: Vector Arithmetic & Memory
- [ ] Implement standard vector-integer and vector-float operations.
- [ ] Implement Unit-Stride and Strided vector loads.
- **Detailed Plan**: We will build the Vector Execution Units to perform SIMD (Single Instruction, Multiple Data) arithmetic. This includes vectorized add, multiply, divide, and complex floating-point vector reductions. For the memory interface, we will implement the complex Vector Load/Store unit, supporting Unit-Stride (contiguous memory blocks), Strided (jumping by fixed offsets, great for image processing), and Indexed/Scatter-Gather operations (loading scattered elements based on an array of indices).
- **XiangShan Study**: [VIPU.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/VIPU.scala) and [Mgu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Mgu.scala)
