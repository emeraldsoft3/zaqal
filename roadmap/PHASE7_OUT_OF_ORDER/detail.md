# Phase 7: Out-of-Order Engine (The Heart of XiangShan)

This is the most complex structural change. We move from "one by one" to "do whatever is ready."

## Week 1: Register Renaming & Cache
- [ ] **Map Table (RAT)**: Mapping 31 architectural registers to 128+ physical registers.
- [ ] **Free List**: Managing available physical registers.
- [ ] **Register Cache**: Implementing a small, fast cache in front of the Large Physical Register File to meet timing at high frequencies.
- [ ] **Eliminated Move**: Implementing "Zero-cycle" moves by just re-mapping.

## Week 2: Reorder Buffer (ROB)
- [ ] **ROB Structure**: Tracking the status of every in-flight instruction.
- [ ] **In-Order Commit**: Ensuring that even if instructions finish out of order, they update the state in order.
- [ ] **Exception Handling**: Flushed the pipeline correctly when an OoO instruction faults.

## Week 3: Issue Queues & FU Clusters
- [ ] **Distributed Issue Queues**: Separate queues for each cluster (ALU, MEM, BRANCH, VECTOR).
- [ ] **Wakeup & Select Loop**: Optimizing the selection logic for GHz-level frequencies.
- [ ] **Payload RAM Bypass**: Reducing latency for ready-to-execute instructions.

## Week 4: Load/Store Disambiguation
- [ ] **Load-Store Queue (LSQ)**: Ensuring a Load doesn't bypass a Store to the same address.
- [ ] **Memory Dependency Predictor**: Guessing if a Load will conflict with a Store.
