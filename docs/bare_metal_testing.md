# Running Bare Metal Tests on Zaqal

As of Day 14, Zaqal has moved away from a mock, hardcoded instruction cache. It now features a real Set-Associative Level-1 Instruction Cache (L1 I-Cache) that communicates via a TileLink/AXI memory bus!

## Where to write your bare-metal programs
You no longer hardcode instructions inside `ICache.scala`. Instead, the testbench acts as your "Main Memory" (DRAM) and responds to cache misses.

Open `zaqal/src/zaqal/ZaqalTest.scala`. 
Around **Line 49**, you will see the `programMemory` array inside the **MEMORY RESPONDER MODEL**:

```scala
    // --- MEMORY RESPONDER MODEL ---
    // The bare metal program to run
    val programMemory = Seq(
      "h00108093".U(32.W), // addi x1, x1, 1
      "h00210113".U(32.W), // addi x2, x2, 2
      ...
    ).padTo(1024, "h00000013".U(32.W))
```

This is the simulated physical RAM. You can write your hex codes directly here, just as you did before.

## How to run the programs
Running the programs is exactly the same as before. The testbench automatically handles compiling the processor, wiring the simulated memory to the L1 Cache pins, and running the clock.

1. Open your terminal in WSL.
2. Run the testbench:
```bash
mill zaqal.runMain zaqal.ZaqalTest
```

## Advanced: How the Testbench Memory works
In `ZaqalTest.scala`, we have built a simulated memory controller that mimics real-world DRAM latency.
When your program starts, the PC is `0x80000000`. 
1. The L1 I-Cache checks its tags. Since it's empty, it registers a **Miss**.
2. The L1 I-Cache drives `io.mem.req.valid` HIGH to request the block from memory.
3. The Testbench sees this request. It intentionally waits **50 cycles** (`memLatencyCounter`) to simulate the delay of reaching out to real DDR RAM!
4. After 50 cycles, the Testbench streams the 256-bit data block (8 instructions) back to the L1 Cache.
5. The L1 Cache writes the data into its SRAM, raises its Valid bit, and resumes the IFU pipeline!
