# Phase 10: Verification & SoC Integration

The final step is proving it works and making it a real chip.

## Goal: Silicon-Grade Verification & Tapeout Readiness

## Day 1-2: Difftest Integration
- [ ] Connect Zaqal to the Difftest framework for co-simulation with Spike/NEMU.
- **Detailed Plan**: Testing a complex out-of-order processor cannot be done solely with unit tests. We will integrate Zaqal into the Difftest framework, a highly advanced co-simulation environment. As Zaqal executes instructions in hardware simulation, Difftest simultaneously executes the exact same program in a golden reference software emulator (like Spike or NEMU). After every committed instruction, Difftest compares Zaqal's architectural register state, memory state, and CSRs against the golden reference, immediately flagging any micro-architectural divergence.
- **XiangShan Study**: [XSTile.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/XSTile.scala) - *See how the core is wrapped for testing.*

## Day 3-5: Random Instruction Generation
- [ ] Stress test the core with random instructions (Torture/Riscv-DV).
- **Detailed Plan**: The most insidious bugs in superscalar processors are deep pipeline race conditions—such as a branch mispredict happening on the exact same cycle as a cache miss, while a TLB page fault is raised on a separate lane. We will use Google's RISCV-DV framework or RISC-V Torture to generate millions of highly constrained, chaotic, randomized instruction sequences. Running these through the Difftest framework ensures we cover obscure corner cases and achieve silicon-grade verification confidence.

## Day 6-7: AXI4 Bus & Memory System
- [ ] Implement AXI4 managers for I-Cache and D-Cache.
- **Detailed Plan**: To integrate Zaqal into a real-world System-on-Chip (SoC), it must communicate using industry-standard bus protocols. We will refactor the memory interfaces of the L1 Caches to speak the ARM AMBA AXI4 protocol. This involves handling complex burst transactions, out-of-order responses, and multiple outstanding memory requests. By standardizing on AXI4, Zaqal can be seamlessly plugged into open-source DRAM controllers and interconnect IP.
- **XiangShan Study**: [L2Top.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/L2Top.scala) - *Study the memory system top level.*

## Day 8-9: Peripherals & Bootloader
- [ ] Integrate UART, SPI, and other SoC components.
- [ ] Write a basic bootloader to jump to the Linux kernel.
- **Detailed Plan**: An SoC requires peripherals to be useful. We will connect the AXI4 interconnect to MMIO (Memory Mapped I/O) peripherals including a SPI controller for reading from an SD Card or Flash memory, and GPIOs for hardware interaction. We will then write the Zero-Stage Bootloader (ZSBL) in assembly. This bootloader will live in on-chip Read-Only Memory (ROM), initialize the hardware, copy the First-Stage Bootloader (like OpenSBI/U-Boot) from the SD Card into DRAM, and transfer control to it.

## Day 10+: Performance Benchmarking & Linux Boot
- [ ] Run CoreMark, SpecInt, and finally boot BusyBox Linux.
- **Detailed Plan**: The ultimate milestone of any high-performance processor project. We will compile and run industry-standard benchmarks like CoreMark, Dhrystone, and SPECint to precisely measure Zaqal's Instructions Per Clock (IPC) and compare it against targets like ARM Cortex-A76 or XiangShan. Finally, we will compile a full Buildroot/BusyBox Linux kernel, mount a root filesystem, and watch Zaqal boot an interactive Linux shell in simulation and eventually on an FPGA.
