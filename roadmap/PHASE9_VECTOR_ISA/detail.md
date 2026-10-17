# Phase 9: AI & Vector ISA (AMX Power)

Zaqal differentiates itself by integrating high-performance 2D matrix operations directly into the backend.

## Goal: Matrix Acceleration & Standard Vector (RVV 1.0)

## Day 1-5: Matrix Functional Unit (AMX) - Foundation **[COMPLETE]**
- [x] **Hardware Architecture**: Define the 2D "Tile" registers for AMX (`T0`-`T7`, 16 rows x 16 cols x 8-bit, 256 bytes per tile, 2 KB total).
- [x] **Matrix Load/Store**: Implement specialized instructions to load/store 2D sub-matrices (`TLD`, `TST`), single-cycle reset (`TZERO`), and configuration (`TCFG`).
- [x] **Integration & Verification**: Full out-of-order execution integration via Port 0 issue queue serialization, memory streaming handshake with `DataMem`, verified with both isolated unit tests (`AMXTest.scala`) and full top-level processor simulation (`ZaqalTest.scala`, `Lithium.vcd`).
- **Detailed Plan**: To accelerate AI workloads, traditional 1D vector processing is inefficient. We will introduce a novel Matrix Functional Unit (AMX) inspired by Apple and Intel architectures. We will define large, 2-dimensional "Tile" architectural registers inside the core that can hold sub-matrices (e.g., 16x16 blocks of 8-bit integers). We will create custom load and store instructions capable of streaming massive continuous chunks of memory directly into these 2D Tile registers, utilizing the full bandwidth of the memory bus.

## Day 6-12: The Matrix Engine (GEMM Acceleration) **[COMPLETE]**
- [x] **Matrix Multiply-Accumulate (MMA)**: Implement the core unit that performs `C += A * B` on 2D tiles.
- [x] **Precision Support**: Support for Int8, BF16, and FP32 for AI inference.
- [x] **Integration & Verification**: Full execution pipeline integration with TileRegFile, ROB retirement, verified with hardware simulation in `Lithium.vcd`.
- **Detailed Plan**: The heart of AI inference is the General Matrix Multiply (GEMM) operation. We will design a systolic array or massive parallel multiplier tree that can execute the `C += A * B` operation entirely in hardware across the 2D Tiles. This Matrix Multiply-Accumulate (MMA) unit will be integrated as a dedicated Execution Cluster within the Out-of-Order backend. We will support highly quantized data types essential for modern neural networks, specifically INT8 and Bfloat16 (BF16), maximizing computational density per clock cycle.
- **Study Reference**: Look at industry standards like Intel AMX or Apple's AMX for ISA inspiration.

## Day 13-17: Vector Register File (VRF) & LMUL **[COMPLETE]**
- [x] Implement VLEN-sized registers (128/256/512-bit).
- [x] Implement the standard RVV 1.0 configuration registers (vtype, vl).
- [x] Dynamic Vector Configuration & Stripmining (`vsetvli`, `vsetivli`, `vsetvl`, `VConfigUnit`).
- [x] Full Out-of-Order Execution & CSR integration verified via top-level test bench (`ZaqalTest.scala`, `Lithium.vcd`).
- **Detailed Plan**: Alongside matrix math, we will fully implement the official RISC-V Vector Extension (RVV 1.0). This requires building a massive Vector Register File (VRF) with configurable widths (VLEN). We will implement the complex RVV state configuration registers (`vtype`, `vl`), which dynamically adjust the vector length and data element widths (e.g., configuring the registers to hold 32-bit floats vs 8-bit integers). We will also support LMUL (Length Multiplier), allowing the architecture to logically group multiple vector registers together to operate on immensely long data vectors.
- **XiangShan Study**: [Bundles.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Bundles.scala)

## Day 18-20: Vector Arithmetic & Memory **[COMPLETE]**
- [x] Implement standard vector-integer and vector-float operations.
- [x] Implement Unit-Stride and Strided vector loads.
- [x] Implement Vector Execution Unit (`VectorAlu.scala`) with dynamic SEW (8, 16, 32, 64-bit) and reductions (`vredsum.vs`).
- [x] Implement Vector Load/Store Unit (`VectorLSU.scala`) and 128-bit streaming DataMem interface.
- [x] Full top-level processor simulation verification in `ZaqalTest.scala` and `Lithium.vcd`.
- **Detailed Plan**: We will build the Vector Execution Units to perform SIMD (Single Instruction, Multiple Data) arithmetic. This includes vectorized add, multiply, divide, and complex floating-point vector reductions. For the memory interface, we will implement the complex Vector Load/Store unit, supporting Unit-Stride (contiguous memory blocks), Strided (jumping by fixed offsets, great for image processing), and Indexed/Scatter-Gather operations (loading scattered elements based on an array of indices).
- **XiangShan Study**: [VIPU.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/VIPU.scala) and [Mgu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/vector/Mgu.scala)

## Day 21-25: Vector Out-of-Order Integration (Rename & Dispatch) **[COMPLETE]**
- [x] **Vector Rename Table (Vector RAT)**: Renaming logic for vector registers `v0`-`v31` mapping to 128 vector physical registers (`pv0`-`pv127`, XiangShan Kunminghu Parity).
- [x] **Vector Free List (VFreeList)**: Tracking 96 free vector physical registers with snapshot checkpoints and ROB retirement recovery.
- [x] **Vector Dispatch Queue (VDQ)**: Decoupled FIFO queue buffering renamed vector micro-ops to isolate vector multicycle execution from scalar dispatch.
- [x] **Dual-Scoreboard Sync & Issue Integration**: Dynamic wakeup and execution for both scalar base/operand registers and vector source registers without pipeline bubbles.
- [x] **Full 3-Suite Verification Matrix**:
  - *Test 1 (WAW Hazard & Dynamic Remapping)*: Dynamic remapping of vector destinations (`v1 -> pv34`) while consumer uops read previous physical registers (`pv32`).
  - *Test 2 (Deep RAW Hazard & Dual Scoreboard)*: Vector load (`vle32.v`) followed by dependent vector multiply (`vmul.vv`), vector add (`vadd.vv`), and vector-scalar multiply (`vmul.vx`), with concurrent scalar out-of-order execution on ALUs 1..3.
  - *Test 3 (Speculative Renaming & Branch Recovery)*: Branch misprediction flush, VRAT snapshot checkpoint recovery, VDQ squashing, and zero-leak FreeList pointer rollback.
- **Detailed Plan**: To enable full out-of-order execution for vector operations, we must rename vector registers. We will design a Vector Rename Table (VRAT) and a Vector Free List to track 128 vector physical registers (matching XiangShan's VfPhyRegs Kunminghu parity). To prevent long-latency vector operations from clogging the main scalar dispatch pipeline, we will implement a dedicated Vector Dispatch Queue. This queue buffers renamed vector micro-ops and dispatches them to separate Vector Issue Queues (VIQs), allowing scalar instructions to bypass stalled vector instructions and execute out-of-order.
- **XiangShan Parity & Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala) (Reg_V, Reg_V0, Reg_Vl), [Rename.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/Rename.scala) (VecFreeList with VfPhyRegs = 128-160), and [NewDispatch.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/dispatch/NewDispatch.scala) (VecBusyTable).
