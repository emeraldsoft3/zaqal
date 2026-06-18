# Phase 5: Timing & Optimization (The Clock Speed Push)

Now that the core is wide, we must make it fast. We will break the long wires that limit our MHz.

## Goal: High Frequency (Fmax) Optimization

## Day 1: Pipelined Decode
- [x] Add registers between the `IBuffer` and the `Decode` units.
- **Detailed Plan**: Decoding a 6-wide instruction bundle involves massive fan-out and deep combinatorial logic, especially when determining instruction boundaries and extracting immediates. To prevent this from becoming a critical path, we will insert pipeline registers (a full staging boundary) between the Instruction Buffer dequeue and the Decode payload generation. This splits the frontend delivery and the backend decode into distinct clock cycles, dramatically improving maximum frequency (Fmax).
- **XiangShan Study**: [DecodeStage.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/DecodeStage.scala) - *How they structure the decode stage logic.*

## Day 2: Pipelined Dispatch
- [ ] Add registers between `Decode` and `Dispatch`.
- **Detailed Plan**: Dispatching involves routing instructions to multiple issue queues based on structural hazards and dependency checks. This routing logic is highly combinatorial. By placing a skid buffer or a pipeline register array between Decode/Rename and Dispatch, we give the synthesizer a clear boundary to retime the logic. This ensures that the complex prefix-sum routing logic does not chain together with the Decode stage logic.
- **XiangShan Study**: [Dispatch.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/decode/Dispatch.scala) - *Look for staging registers.*

## Day 3: Result Forwarding (Bypass Network)
- [ ] Implement a full bypass network to allow back-to-back execution.
- **Detailed Plan**: When an instruction executes, its result is often immediately needed by the next instruction. Writing to the Physical Register File (PRF) and reading it back takes too long. We will build a Bypass Network that forwards the computed output directly from the ALU outputs to the inputs of the dependent Execution Units. We will need to heavily optimize the multiplexers in this network, as forwarding across multiple clusters can create severe timing bottlenecks.
- **XiangShan Study**: [BypassNetwork.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/issue/BypassNetwork.scala) - *Study how they handle data forwarding.*

## Day 4: Register File Pipelining (Read Stage)
- [ ] Implement 2-cycle Register File access (Read in Cycle 1, Execute in Cycle 2).
- **Detailed Plan**: A high-capacity, multi-ported Physical Register File is incredibly slow to read due to immense wire capacitance. To mitigate this, we will pipeline the Register File access. Instructions issued from the Issue Queues will spend Cycle 1 asserting read addresses and propagating signals through the SRAM/Latch arrays, and the actual execution (ALU/MEM) will take place in Cycle 2. This is a crucial step for achieving 500MHz+ in silicon.

## Day 5: Register File Pipelining (Write Stage)
- [ ] Split the write-back into multiple cycles if necessary.
- **Detailed Plan**: Just like reading, writing multiple 64-bit values back into a massive Register File can strain the clock cycle. We will implement write-back staging registers. When an execution unit finishes, it will first latch its result and write-enable signals into a buffer. The actual physical write to the SRAM array will complete in the following cycle. We must ensure the Bypass Network covers this extra cycle so dependent instructions don't stall.

## Day 6: ALU Critical Path Optimization
- [ ] Break down the ALU logic (especially multipliers and adders) into smaller chunks.
- [ ] **Zba Adder Reuse**: Refactor SH1ADD/SH2ADD/SH3ADD (and .UW variants) to pre-shift `src1` and feed it into the **single shared Adder** instead of creating 6 independent adders. Match XiangShan's `Alu.scala` lines 270-291 pattern: `shaddSource` → mux → existing `addModule`.
- **Detailed Plan**: The Arithmetic Logic Unit is the heart of the processor, and complex operations like multiplication or bit-manipulation can create long combinatorial chains. We will pipeline the Multiplier (e.g., creating a 2-stage or 3-stage Wallace Tree pipeline) and heavily reuse fast adders by pre-shifting operands for Zba instructions. This reduces gate depth and saves silicon area.
- **XiangShan Study**: [Alu.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Alu.scala) - *See how they reuse AddModule for SHxADD via operand pre-shifting.*
- **XiangShan Study**: [Multiplier.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/backend/fu/Multiplier.scala) - *See how they pipeline the multiplication operation.*

## Day 7: Load/Store Queue Timing
- [ ] Optimize the address calculation and memory request path.
- **Detailed Plan**: Memory operations require calculating an address (Base + Offset), translating it (TLB), and accessing the D-Cache, all within tight timing margins. We will optimize this by splitting address generation (AGU) and cache access into separate pipeline stages. We will also implement fast-path TLB lookups to ensure the address translation doesn't delay the cache hit/miss determination.
- **XiangShan Study**: [LoadUnit.scala](file:///home/emerald/xs-env/XiangShan/src/main/scala/xiangshan/mem/pipeline/LoadUnit.scala) - *Study the load request pipeline.*

## Day 8: Critical Path Analysis (Static Timing)
- [ ] Use synthesis tools to find the slowest path in the design.
- **Detailed Plan**: We will run the RTL through a synthesis tool (like Yosys or Vivado) and perform Static Timing Analysis (STA). This will give us a precise report of the Worst Negative Slack (WNS). We will methodically track down the top 5 longest timing paths in the core, analyzing the Chisel code that generated those paths to understand where the combinatorial logic is too deep.

## Day 9: Logic Restructuring
- [ ] Rewrite complex Muxes or priority encoders to use tree-based logic.
- **Detailed Plan**: Based on the timing reports, we will refactor the slowest parts of the design. Long chains of `if-else` statements in Chisel often compile into slow, serialized multiplexer chains. We will rewrite these using parallel tree-based reductions, fast priority encoders, and one-hot encoding to drastically minimize the gate depth and balance the propagation delays.

## Day 10: Retiming & Final Optimization
- [ ] Use Chisel's `RegNext` strategically to balance paths.
- **Detailed Plan**: Retiming involves shifting flip-flops backward or forward through combinatorial logic without changing the functional behavior. We will use `RegNext` and explicit Chisel pipelining to move registers out of fast paths and into slow paths, perfectly balancing the delay across all pipeline stages. 
- **Goal**: Reach target Fmax (e.g., 500MHz+ in simulation).
