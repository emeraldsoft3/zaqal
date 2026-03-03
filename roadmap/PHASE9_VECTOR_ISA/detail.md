# Phase 9: Vector ISA (RVV 1.0)

XiangShan (Kunminghu) has a powerful Vector unit. This is like building a second processor inside the first.

## Week 1: Vector Register File
- [ ] **VLEN Management**: Implementing 128-bit, 256-bit, or 512-bit vector registers.
- [ ] **Vector LMUL**: Handling register grouping.

## Week 2: Vector ALU
- [ ] **Stripmining**: Handling loops that are longer than the hardware VL.
- [ ] **Masking**: Conditional vector execution.
- [ ] **Vector Int/Float arithmetic**.

## Week 3-4: Vector Memory (Load/Store)
- [ ] **Unit-Stride / Strided / Indexed (Scatter-Gather)**.
- [ ] **Segment Loads/Stores**: For interleaved data (e.g., RGB).
- **Complexity**: Handling multiple memory requests from a single vector instruction.
