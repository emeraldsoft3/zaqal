# Phase 9: AI & Vector ISA (AMX Power)

Zaqal differentiates itself by integrating high-performance 2D matrix operations directly into the backend.

## Goal: Matrix Acceleration & Standard Vector (RVV 1.0)

## Day 1-5: Matrix Functional Unit (AMX) - Foundation
- [ ] **Hardware Architecture**: Define the 2D "Tile" registers for AMX.
- [ ] **Matrix Load/Store**: Implement specialized instructions to load 2D sub-matrices.
- **Goal**: High-bandwidth data movement for AI tiles.

## Day 6-12: The Matrix Engine (GEMM Acceleration)
- [ ] **Matrix Multiply-Accumulate (MMA)**: Implement the core unit that performs `C += A * B` on 2D tiles.
- [ ] **Precision Support**: Support for Int8, BF16, and FP32 for AI inference.
- **Study Reference**: Look at industry standards like Intel AMX or Apple's AMX for ISA inspiration.

## Day 13-17: Vector Register File (VRF) & LMUL
- [ ] Implement VLEN-sized registers (128/256/512-bit).
- [ ] Implement the standard RVV 1.0 configuration registers (vtype, vl).
- **XiangShan Study**: [Bundles.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Bundles.scala)

## Day 18-20: Vector Arithmetic & Memory
- [ ] Implement standard vector-integer and vector-float operations.
- [ ] Implement Unit-Stride and Strided vector loads.
- **XiangShan Study**: [VIPU.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/VIPU.scala) and [Mgu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Mgu.scala)
