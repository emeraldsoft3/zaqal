# Phase 5: Timing & Optimization (The Clock Speed Push)

Now that the core is wide, we must make it fast. We will break the long wires that limit our MHz.

## Goal: High Frequency (Fmax) Optimization

## Day 1: Pipelined Decode
- [ ] Add registers between the `IBuffer` and the `Decode` units.
- **XiangShan Study**: [DecodeStage.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/DecodeStage.scala) - *How they structure the decode stage logic.*

## Day 2: Pipelined Dispatch
- [ ] Add registers between `Decode` and `Dispatch`.
- **XiangShan Study**: [Dispatch.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/Dispatch.scala) - *Look for staging registers.*

## Day 3: Result Forwarding (Bypass Network)
- [ ] Implement a full bypass network to allow back-to-back execution.
- **XiangShan Study**: [BypassNetwork.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/BypassNetwork.scala) - *Study how they handle data forwarding.*

## Day 4: Register File Pipelining (Read Stage)
- [ ] Implement 2-cycle Register File access (Read in Cycle 1, Execute in Cycle 2).
- **Goal**: Reduce the pressure on the clock cycle by splitting the RF access.

## Day 5: Register File Pipelining (Write Stage)
- [ ] Split the write-back into multiple cycles if necessary.
- **Goal**: Achieve stable write-back at high frequencies.

## Day 6: ALU Critical Path Optimization
- [ ] Break down the ALU logic (especially multipliers and adders) into smaller chunks.
- **XiangShan Study**: [Multiplier.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Multiplier.scala) - *See how they pipeline the multiplication operation.*

## Day 7: Load/Store Queue Timing
- [ ] Optimize the address calculation and memory request path.
- **XiangShan Study**: [LoadUnit.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/LoadUnit.scala) - *Study the load request pipeline.*

## Day 8: Critical Path Analysis (Static Timing)
- [ ] Use synthesis tools to find the slowest path in the design.
- **Task**: Identify the top 5 worst paths (WNS).

## Day 9: Logic Restructuring
- [ ] Rewrite complex Muxes or priority encoders to use tree-based logic.
- **Goal**: Minimize gate depth.

## Day 10: Retiming & Final Optimization
- [ ] Use Chisel's `RegNext` strategically to balance paths.
- **Goal**: Reach target Fmax (e.g., 500MHz+ in simulation).
