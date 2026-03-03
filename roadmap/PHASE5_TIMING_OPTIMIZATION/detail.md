# Phase 5: Timing & Optimization (The Clock Speed Push)

Now that the core is wide, we must make it fast. We will break the long wires that limit our MHz.

## Goal: High Frequency (Fmax) Optimization

## Day 17: Pipelined Decode & Dispatch
- [ ] Add registers between the `IBuffer` and the `Dispatch` stage.
- [ ] Add registers between `Dispatch` and `Execute`.
- **Result**: You now have a **4-5 cycle redirect penalty**.

## Day 18: Register File Pipelining
- [ ] Implement 2-cycle Register File access (Read in Cycle 1, Execute in Cycle 2).
- [ ] This requires **Bypass/Forwarding logic** so the result of an Add can be used by the immediately following instruction.

## Day 19-20: Critical Path Analysis
- [ ] Use synthesis tools to find the slowest path.
- [ ] Manually optimize Chisel code (e.g., breaking large Muxes or long Carry chains).
