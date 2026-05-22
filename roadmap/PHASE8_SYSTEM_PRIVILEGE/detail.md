# Phase 8: System & Privilege (Linux Readiness)

To run an Operating System, we need "Privilege Mode" and "Address Translation."

## Goal: Supervisor Mode & Virtual Memory Support

## Day 1-3: CSR Implementation
- [ ] Implement Control and Status Registers (CSRs) for Machine and Supervisor modes.
- **Detailed Plan**: Linux and other operating systems require a rich set of architectural registers to control the CPU's state. We will build the Control and Status Register (CSR) file, encompassing registers like `mstatus`, `sstatus`, `mepc`, `sepc`, `stvec`, and `satp`. This involves creating a specialized execution unit (CSR Unit) that can safely read and write these registers while ensuring pipeline synchronization, as CSR writes often change the global state of the processor and require a pipeline flush.
- **XiangShan Study**: [CSR.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/CSR.scala) - *See how CSRs are managed.*

## Day 4-5: Privilege Levels & Trap Handling
- [ ] Implement switching between M, S, and U modes.
- [ ] Handle exceptions, interrupts, and environment calls (ecall).
- **Detailed Plan**: We must enforce security by isolating applications (User Mode) from the operating system (Supervisor Mode) and firmware (Machine Mode). We will implement hardware trap generation logic. When an illegal instruction, memory fault, or `ecall` occurs, the core must instantly halt execution, save the current PC to the appropriate exception program counter (`mepc`/`sepc`), elevate the privilege level, and jump to the trap vector address defined in `mtvec` or `stvec`.
- **XiangShan Study**: [ExceptionGen.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/ExceptionGen.scala) - *How exceptions are tracked for state recovery.*

## Day 6-7: PMP & PMA
- [ ] Implement Physical Memory Protection (PMP) and Physical Memory Attributes (PMA).
- **Detailed Plan**: Firmware (Machine mode) uses Physical Memory Protection (PMP) to enforce sandbox restrictions, preventing the OS or applications from accessing protected hardware ranges. Physical Memory Attributes (PMA) define whether memory regions are cacheable, executable, or memory-mapped I/O (MMIO). We will integrate these access control checks directly into the instruction fetch and load/store paths, raising access fault exceptions immediately upon violation.
- **XiangShan Study**: [PMP.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/PMP.scala) and [PMA.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/PMA.scala).

## Day 8-10: TLB (Translation Lookaside Buffer)
- [ ] Build the TLB for fast virtual-to-physical address translation.
- **Detailed Plan**: Modern operating systems use virtual memory. Every single memory access (both instruction fetches and data loads/stores) must be translated from a Virtual Address to a Physical Address. Since reading page tables from memory is incredibly slow, we will build a Translation Lookaside Buffer (TLB)—a fast associative cache that stores recent address translations. We will implement separate L1 I-TLB and D-TLB, backed by a unified L2 TLB for high performance.
- **XiangShan Study**: [TLB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/cache/mmu/TLB.scala) - *Study the TLB architecture.*

## Day 11-13: Page Table Walker
- [ ] Implement a hardware walker for Sv39 page tables.
- **Detailed Plan**: When a TLB miss occurs, the processor must traverse the Page Tables located in main memory to find the translation. We will implement a hardware Page Table Walker (PTW) compliant with the RISC-V Sv39 standard (3-level radix tree). The PTW is a complex finite state machine that automatically performs memory loads, walking down the page table directory hierarchy, checking access permissions at each level, and refilling the TLB upon success or raising a page fault exception on failure.
- **XiangShan Study**: [PageTableWalker.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/cache/mmu/PageTableWalker.scala) - *Study the state machine for page walking.*

## Day 14-16: System Integration (SBI & UART)
- [ ] **SBI (Supervisor Binary Interface)**: Support for OpenSBI or similar firmware.
- [ ] **UART/Console**: Basic serial output to see the "Linux Banner."
- **Detailed Plan**: To boot Linux, the hardware must provide a standard interface for the OS to communicate with the firmware. We will ensure compatibility with OpenSBI, the industry-standard RISC-V boot firmware. We will also integrate a Universal Asynchronous Receiver-Transmitter (UART) peripheral mapped to physical memory space. This will allow the core to transmit and receive characters over a serial interface, providing the critical console output needed to witness the Linux boot sequence.

## Day 17-20: Advanced Interrupts (PLIC/CLINT)
- [ ] **PLIC**: Platform-Level Interrupt Controller for external device interrupts.
- [ ] **CLINT**: Core-Local Interruptor for timer and software interrupts (MTIME).
- **Detailed Plan**: The OS relies on timer interrupts for context switching between threads, and external interrupts for handling hardware devices (like keyboards or disk drives). We will integrate a Core-Local Interruptor (CLINT) providing the `mtime` and `mtimecmp` registers for highly accurate timer traps. We will also build a Platform-Level Interrupt Controller (PLIC) capable of prioritizing and routing dozens of external device interrupts to the core's trap handler.

---

## Linux Readiness Checklist
- [x] **RV64I/M/A/F/D** (The "G" extension).
- [ ] **Supervisor Mode** (S-mode).
- [ ] **Sv39/48 MMU**.
- [ ] **Timer Interrupts** for context switching.
- [ ] **32-bit Compatibility Mode** (mstatus.UXL).
