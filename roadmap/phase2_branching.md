# Phase 2: Simple Branching & Jumps

Once the ALU instructions are complete, we move to control flow. This phase introduces the logic for jumps and conditional branches.

### Day 5: Conditional Branching (B-Type)
- [ ] `BEQ`: Branch if equal
- [ ] `BNE`: Branch if not equal
- [ ] `BLT`: Branch if less than (signed)
- [ ] `BGE`: Branch if greater than or equal (signed)
- [ ] `BLTU`: Branch if less than (unsigned)
- [ ] `BGEU`: Branch if greater than or equal (unsigned)

### Day 6: Unconditional Jumps (J-Type & I-Type)
- [ ] `JAL`: Jump and Link
- [ ] `JALR`: Jump and Link Register

---

## Technical Goal
- Correctly calculate branch targets (PC + offset).
- Correctly update the return address register (`x1/ra`).
- Verify that a 1-cycle redirect (flush) works for every branch type.
