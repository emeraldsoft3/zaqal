# Phase 4: Superscalar & Dispatch (The XiangShan Shift)

This is where we transition Zaqal from a simple core to a high-performance engine.

## Goal: Multi-Issue Execution (6-Wide)

## Day 13: The Multi-Wide IBuffer
- [ ] Redesign `IBuffer.scala` as a banked queue (like XiangShan).
- [ ] Ability to read 6 instructions in a single cycle.

## Day 14: Parallel Decoders
- [ ] Instantiate 6 `Decoder` modules in the Backend.
- [ ] Map the 6 `IBuffer` outputs to these decoders.

## Day 15: The Dispatcher (The Traffic Cop)
- [ ] Implement the **Dispatch Tree**.
- [ ] Routing: Send "Add" instructions to ALU ports, "Load" to Memory ports.
- [ ] **Structural Hazard Check**: What if we have 6 Adds but only 4 ALUs? Implement stalling for the remaining 2.

## Day 16: Handling Mispredicts in 6-Wide
- [ ] Complexity: A branch might be in Position 3 of a 6-instruction bundle.
- [ ] Logic: Instructions at positions 4, 5, and 6 must be discarded immediately, even if the whole bundle was valid.
