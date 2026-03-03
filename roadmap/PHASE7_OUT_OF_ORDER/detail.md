# Phase 7: Out-of-Order Engine (The Heart of XiangShan)

This is the most complex structural change. We move from "one by one" to "do whatever is ready."

## Week 1: Register Renaming
- [ ] **Map Table (RAT)**: Mapping 31 architectural registers to 128+ physical registers.
- [ ] **Free List**: Managing available physical registers.
- [ ] **Eliminated Move**: Implementing "Zero-cycle" moves by just re-mapping.

## Week 2: Reorder Buffer (ROB)
- [ ] **ROB Structure**: Tracking the status of every in-flight instruction.
- [ ] **In-Order Commit**: Ensuring that even if instructions finish out of order, they update the state in order.
- [ ] **Exception Handling**: Flushed the pipeline correctly when an OoO instruction faults.

## Week 3: Issue Queues (Dispatch to Issue)
- [ ] **Unified vs Distributed Queues**: Designing the Dispatch-to-Issue stage.
- [ ] **Wakeup & Select**: Logic for instructions to "see" their operands become ready and jump into execution.

## Week 4: Load/Store Disambiguation
- [ ] **Load-Store Queue (LSQ)**: Ensuring a Load doesn't bypass a Store to the same address.
- [ ] **Memory Dependency Predictor**: Guessing if a Load will conflict with a Store.
