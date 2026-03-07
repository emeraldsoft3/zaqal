# Phase 10: Verification & SoC Integration

The final step is proving it works and making it a real chip.

## Goal: Silicon-Grade Verification & Tapeout Readiness

## Day 1-2: Difftest Integration
- [ ] Connect Zaqal to the Difftest framework for co-simulation with Spike/NEMU.
- **XiangShan Study**: [XSTile.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/XSTile.scala) - *See how the core is wrapped for testing.*

## Day 3-5: Random Instruction Generation
- [ ] Stress test the core with random instructions (Torture/Riscv-DV).
- **Goal**: Find and fix deep pipeline race conditions.

## Day 6-7: AXI4 Bus & Memory System
- [ ] Implement AXI4 managers for I-Cache and D-Cache.
- **XiangShan Study**: [L2Top.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/L2Top.scala) - *Study the memory system top level.*

## Day 8-9: Peripherals & Bootloader
- [ ] Integrate UART, SPI, and other SoC components.
- [ ] Write a basic bootloader to jump to the Linux kernel.

## Day 10+: Performance Benchmarking & Linux Boot
- [ ] Run CoreMark, SpecInt, and finally boot BusyBox Linux.
- **Goal**: Full system functionality at competitive performance.
