# Phase 8: System & Privilege (Linux Readiness)

To run an Operating System, we need "Privilege Mode" and "Address Translation."

## Week 1: CSRs & Privilege Levels
- [ ] **Control and Status Registers (CSRs)**: `mtvec`, `mepc`, `mstatus`, etc.
- [ ] **Privilege Modes**: Machine (M), Supervisor (S), and User (U).
- [ ] **Traps & Interrupts**: Handling timer interrupts and software exceptions.

## Week 2: Virtual Memory (Sv39 MMU)
- [ ] **Translation Lookaside Buffer (TLB)**: Caching page table entries.
- [ ] **Page Table Walker**: Hardware walker to traverse memory if the TLB misses.
- [ ] **Address Protection**: Checking Read/Write/Execute permissions.

## Week 3: Platform Integration
- [ ] **PLIC** (Platform Level Interrupt Controller).
- [ ] **CLINT** (Core Local Interruptor).
- [ ] **A-Extension Integration**: Ensuring Atomics work across the MMU.
