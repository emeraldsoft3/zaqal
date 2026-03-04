# Phase 8: System & Privilege (Linux Readiness)

To run an Operating System, we need "Privilege Mode" and "Address Translation."

## Week 1: CSRs & Privilege Levels
- [ ] **Control and Status Registers (CSRs)**: `mtvec`, `mepc`, `mstatus`, etc.
- [ ] **Privilege Modes**: Machine (M), Supervisor (S), and User (U).
- [ ] **Traps & Interrupts**: Handling timer interrupts and software exceptions.
- [ ] **PMP & PMA**: Implementing Physical Memory Protection and Attributes checking.

## Week 2: Virtual Memory (Sv39 MMU)
- [ ] **Translation Lookaside Buffer (TLB)**: Caching page table entries.
- [ ] **Page Table Walker**: Hardware walker to traverse memory if the TLB misses.
- [ ] **Address Protection**: Checking Read/Write/Execute permissions.

## Week 3: Platform & Debug
- [ ] **PLIC & CLINT**: Platform Level Interrupt Controller and Core Local Interruptor.
- [ ] **A-Extension Integration**: Ensuring Atomics work across the MMU.
- [ ] **RISC-V Debug Module**: JTAG/GDB support for hardware debugging (D-Extension).
