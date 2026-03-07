# Phase 7: Out-of-Order Engine (The Heart of XiangShan)

This is the most complex structural change. We move from "one by one" to "do whatever is ready."

## Goal: High-Performance Out-of-Order Execution

## Day 1-3: Reorder Buffer (ROB) Logic
- [ ] Implement the ROB to track in-flight instructions and manage commit.
- **XiangShan Study**: [Rob.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/Rob.scala) - *Study the main ROB logic.*

## Day 4-5: ROB Pointers & Wrappers
- [ ] Manage enqueue and dequeue pointers for the circular ROB buffer.
- **XiangShan Study**: [RobEnqPtrWrapper.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/RobEnqPtrWrapper.scala) - *See how they handle pointer wrapping.*

## Day 6-8: Register Renaming (RAT Refinement)
- [ ] Transition to a full physical register file (PRF) with Rename Alias Table (RAT).
- **XiangShan Study**: [RenameTable.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rename/RenameTable.scala) - *Deep dive into renaming.*

## Day 9-11: Register Cache (Timing fix)
- [ ] Implement a Register Cache (RC) to reduce PRF read latency.
- **XiangShan Study**: [regcache/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/regcache/) - *Study the register cache implementation.*

## Day 12-14: Issue Queues (Wakeup & Select)
- [ ] Implement distributed issue queues for ALU, Mem, and Branch units.
- **XiangShan Study**: [IssueQueue.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/IssueQueue.scala) - *Wakeup and selection logic.*

## Day 15-17: Memory Disambiguation (LSQ)
- [ ] Implement Load/Store Queues to handle memory dependencies out-of-order.
- **XiangShan Study**: [lsqueue/](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/lsqueue/) - *Explore the load-store queue logic.*

## Day 18-20: Exception & Flush Handling
- [ ] Ensure precise exceptions and correct state recovery on flushes.
- **XiangShan Study**: [ExceptionGen.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/rob/ExceptionGen.scala) - *How exceptions are tracked in the ROB.*
