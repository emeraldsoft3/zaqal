# Phase 12: SoC Integration, 14nm Silicon Sign-off & Shipping

The final milestone: integrating Zaqal into an industry-grade SoC, proving full-system execution with Difftest, closing physical timing, and tapeout readiness.

## Goal: Silicon-Grade Verification, 14nm Tapeout & Linux Shipping

## Day 1-3: Difftest Integration (Golden Model Co-Simulation)
- [ ] Connect Zaqal to the Difftest framework for co-simulation with Spike/NEMU.
- **Detailed Plan**: Testing a complex out-of-order processor requires co-simulation. We will integrate Zaqal into the XiangShan Difftest framework. As Zaqal executes instructions in hardware simulation, Difftest simultaneously executes the exact same program in a golden reference software emulator (like Spike or NEMU). After every committed instruction, Difftest compares Zaqal's architectural register state, memory state, and CSRs against the golden reference, immediately flagging any micro-architectural divergence.
- **XiangShan Study**: [XSTile.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/XSTile.scala) - *See how the core is wrapped for testing.*

## Day 4-6: Random Instruction Generation & Fuzzing
- [ ] Stress test the core with random instructions (Google RISCV-DV / Torture).
- **Detailed Plan**: Superscalar corner cases—such as a branch mispredict happening on the exact cycle as a page fault, while a store buffer drain encounters a cache miss—are discovered through constrained random instruction generation. We will use Google's RISCV-DV framework to generate millions of randomized instruction sequences, running them through Difftest to guarantee silicon-grade stability.

## Day 7-9: AXI4 Bus & Peripherals
- [ ] Implement AXI4 managers for I-Cache and D-Cache.
- [ ] Integrate UART, SPI, DRAM Controller, and MMIO crossbars.
- **Detailed Plan**: We will standardize the memory interfaces on AMBA AXI4, integrating standard MMIO peripherals (UART serial console, SPI Flash/SD-card reader, and DRAM memory controller) to create a self-contained SoC.

## Day 10-12: Bootloader, Benchmarks & Linux Bring-up
- [ ] Write Zero-Stage Bootloader (ZSBL) and integrate OpenSBI.
- [ ] Run CoreMark and SPECint performance benchmarks.
- [ ] Boot BusyBox Linux into an interactive shell.
- **Detailed Plan**: We will load OpenSBI and U-Boot, booting a customized RISC-V Linux kernel (Buildroot/BusyBox) in simulation and on FPGA. We will measure architectural IPC across CoreMark and SPECint benchmarks.

## Day 13-16: 14nm Physical Design & Tapeout Sign-off (Consolidated from Phase 5 & 7)
- [ ] **Logic Synthesis (Yosys / Synopsys Design Compiler)**: Synthesize full-chip Verilog to 14nm standard cells with realistic timing constraints.
- [ ] **SRAM Macro Generation**: Integrate compiled physical SRAM macros for multi-ported PRF, ROB, and L1/L2 Cache data/tag arrays.
- [ ] **Floorplanning & Power Grid (PDN)**: Define core die dimensions, power stripes, and IO pad ring.
- [ ] **Place & Route (P&R) & Clock Tree Synthesis (OpenROAD / Cadence Innovus)**: Place standard cells, build low-skew clock trees across the 6-wide pipeline, and route all metal layers.
- [ ] **Sign-off Static Timing Analysis (STA)**: Extract routed wire RC parasitics, calculate Worst Negative Slack (WNS), and verify $F_{max} \ge 1.0\text{--}1.5\text{ GHz}$.
- [ ] **DRC & LVS Sign-off**: Verify 100% clean Design Rule Checks (DRC) and Layout Versus Schematic (LVS) ready for foundry tapeout.

