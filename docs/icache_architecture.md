# L1 Instruction Cache Architecture & Flow

## Where does the new I-Cache sit?
The new I-Cache (`ICache.scala`) is a fully functional Level-1 Cache located inside the `Frontend` module of the Zaqal Core. 

It sits perfectly between the **Instruction Fetch Unit (IFU)** and the **Main Memory (DRAM)**.

### The Pipeline Flow (Before Day 14):
1. IFU requests address `0x80000000`.
2. The mock I-Cache instantly reads from a Scala Array.
3. The mock I-Cache instantly returns the instruction.

### The Pipeline Flow (After Day 14):
The new I-Cache introduces physical SRAM arrays and realistic stall logic.

#### Scenario A: Cache Miss (Data is not in L1)
1. **IFU Request**: IFU asks for address `0x80000000`.
2. **Lookup**: The I-Cache checks its `Tag Array` for that address.
3. **Miss Detected**: The Tag does not match. The I-Cache immediately drops `io.ready` to `0`, **stalling the entire IFU pipeline**.
4. **Memory Request**: The I-Cache Cache Controller FSM transitions to the `MISS_REQ` state and drives the `MemoryBus` to ask Main Memory for the data block.
5. **DRAM Latency**: The simulated Main Memory in `ZaqalTest.scala` sees the request, waits **50 cycles**, and then streams the 256-bit block back.
6. **Refill**: The I-Cache FSM transitions to `REFILL`, writes the data into its `Data Array`, writes the address into the `Tag Array`, and sets the `Valid` bit.
7. **Resume**: The I-Cache returns to `IDLE`, raises `io.ready` back to `1`, and the IFU finally gets its instruction and resumes operation.

#### Scenario B: Cache Hit (Data is already in L1)
1. **IFU Request**: IFU asks for address `0x80000000`.
2. **Lookup**: The I-Cache checks its `Tag Array` and finds a match! The `Valid` bit is also 1.
3. **Instant Return**: The I-Cache FSM remains in `IDLE`, keeps `io.ready` high, and instantly reads the instruction out of its `Data Array` and sends it to the IFU in the same cycle.

## Integration with the uOp Cache
The I-Cache and the uOp Cache work together seamlessly:
- **First Pass (Cold)**: Both the I-Cache and uOp Cache miss. The I-Cache stalls the pipeline for 50 cycles to fetch the raw instructions from RAM. It then feeds them to the IFU and decoders. Finally, the decoded uOps are saved into the uOp Cache.
- **Second Pass (Warm)**: The uOp Cache hits! The uOp Cache intercepts the fetch and directly feeds the backend. The I-Cache is bypassed completely and doesn't even need to be accessed. 

## Physical SRAM Arrays
Our new I-Cache contains:
- `validArray`: 64 entries of 1 bit each (tracks if a line has valid data).
- `tagArray`: 64 entries of the upper address bits (verifies we have the correct physical block).
- `dataArray`: 64 entries of 256-bit cache lines (holds the actual RISC-V instructions).

---

## GTKWave Verification Guide
To verify the new L1 I-Cache and its 50-cycle memory latency behavior, run the testbench and open `test_run_dir/.../Lithium.vcd` in GTKWave.

### 1. Watch the Pipeline Stall (The 50-Cycle Freeze)
Add these signals to your viewer:
- `TOP.Core.frontend.icache.io_pc` (The address the IFU wants, e.g., `0x80000000`)
- `TOP.Core.frontend.icache.state` (The Cache Controller FSM State)
- `TOP.Core.frontend.icache.io_ready` (The signal that tells the IFU it has data)

**What you will see on the first loop iteration:**
1. `io_pc` changes to `0x80000000`.
2. `state` immediately jumps from `0` (IDLE) to `1` (MISS_REQ).
3. `io_ready` drops to `0`. The entire pipeline is now frozen!
4. You will see a long, flat line of exactly **50 clock cycles** where the processor does nothing. This is the simulated DRAM latency in action!
5. After 50 cycles, `state` jumps to `2` (REFILL) for one cycle, then back to `0` (IDLE).
6. `io_ready` goes back to `1`, and the pipeline resumes!

### 2. Watch the Memory Bus (TileLink/AXI Mock)
To see the physical request going out to the testbench:
- `TOP.Core.io_mem_req_valid`
- `TOP.Core.io_mem_req_bits_addr`
- `TOP.Core.io_mem_resp_valid`
- `TOP.Core.io_mem_resp_bits_data`

**What you will see:**
1. When the cache misses, `io_mem_req_valid` spikes to `1` for one cycle, sending the requested physical address (`0x80000000`) out of the Core.
2. 50 cycles later, the testbench responds! `io_mem_resp_valid` spikes to `1`.
3. In that exact same cycle, `io_mem_resp_bits_data` will show the massive 256-bit block containing all 8 `addi x1, x1, 1` instructions being injected back into the Core!

### 3. Watch the uOp Cache Take Over!
Add these signals:
- `TOP.Core.frontend.uop_hit`
- `TOP.Core.frontend.ifu_io_fetch_req_valid`

**What you will see on the second loop iteration:**
1. When the test program reaches the `jal x0, -92` instruction, the PC jumps back to `0x80000000`.
2. You will **NOT** see the 50-cycle stall again!
3. `uop_hit` will instantly jump to `1`.
4. `ifu_io_fetch_req_valid` drops to `0`.
5. The decoders are bypassed, the L1 I-Cache is ignored, and the uOp Cache delivers the instructions directly to the backend at full speed!
