# Phase 8: System & Privilege (Linux Readiness)

To run an Operating System, we need "Privilege Mode" and "Address Translation."

## Goal: Supervisor Mode & Virtual Memory Support

## Day 1-3: CSR Implementation
- [ ] Implement Control and Status Registers (CSRs) for Machine and Supervisor modes.
- **XiangShan Study**: [CSR.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/CSR.scala) - *See how CSRs are managed.*

## Day 4-5: Privilege Levels & Trap Handling
- [ ] Implement switching between M, S, and U modes.
- [ ] Handle exceptions, interrupts, and environment calls (ecall).
- **XiangShan Study**: [ExceptionGen.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/ExceptionGen.scala) - *How exceptions are tracked for state recovery.*

## Day 6-7: PMP & PMA
- [ ] Implement Physical Memory Protection (PMP) and Physical Memory Attributes (PMA).
- **XiangShan Study**: [PMP.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/PMP.scala) and [PMA.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/PMA.scala).

## Day 8-10: TLB (Translation Lookaside Buffer)
- [ ] Build the TLB for fast virtual-to-physical address translation.
- **XiangShan Study**: [TLB.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/cache/mmu/TLB.scala) - *Study the TLB architecture.*

## Day 11-13: Page Table Walker
- [ ] Implement a hardware walker for Sv39 page tables.
- **XiangShan Study**: [PageTableWalker.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/cache/mmu/PageTableWalker.scala) - *Study the state machine for page walking.*

## Day 14-15: System Integration (PLIC/CLINT)
- [ ] Integrate the PLIC and CLINT for interrupt management.
- **Goal**: Boot a minimal kernel or "Hello World" in supervisor mode.
