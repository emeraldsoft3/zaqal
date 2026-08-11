# Zaqal L0 Decoded Instruction Cache (uOp Cache)

## 1. What is the uOp Cache and Where Does it Sit?
In a traditional pipeline, instructions follow this path:
`L1 ICache -> IFU (Pre-decode) -> IBUF -> Decode Stage -> Dispatch (Rename/Issue)`

The **Decode Stage** is a major bottleneck. For complex instructions (or even simple RISC-V instructions being expanded into micro-operations for a superscalar out-of-order backend), decoding takes time, power, and pipeline stages.

The **uOp Cache (Micro-Op Cache)**, also known as an L0 Decoded Cache, sits parallel to the L1 ICache and IFU. Its job is to store the **already decoded** micro-operations (`MicroOps`). 

When a program enters a loop, the first iteration is fetched normally through the ICache and decoded. Once decoded, the `MicroOps` are written into the uOp Cache. On the *second* loop iteration, the uOp Cache recognizes the Program Counter (PC), intercepts the fetch, and directly delivers the decoded `MicroOps` straight into the Dispatch queue. 

**Speed Improvement**: By bypassing the ICache, IFU, and Decoder stages, the processor shaves off 2-3 cycles of fetch/decode latency, saves massive amounts of power (decoders can sleep), and delivers a higher bandwidth of instructions to the backend per cycle.

---

## 2. Hit vs. Miss: How Does it Know?
You had a great question about how it determines a hit. Yes, your understanding is exactly correct!

When the processor wants to fetch an instruction block at `0x00`:
1. **Probe**: The fetch PC (`0x00`) is sent to both the ICache and the uOp Cache.
2. **Miss (1st Pass)**: The uOp Cache checks its internal memory (Tags) and sees no matching entry for `0x00`. It registers a **Miss**. The IFU proceeds to fetch from the ICache, pre-decode, and send it to the backend. As the IFU successfully packages the instructions, they are routed back to the uOp Cache and saved.
3. **Hit (2nd Pass)**: When the loop jumps back to `0x00`, the uOp Cache is probed again. This time, the PC matches a stored Tag, and the Valid bit is high. It registers a **Hit**! It immediately halts the IFU/ICache fetch process and dumps the stored `MicroOps` straight to the backend.

### What it Checks:
The uOp Cache is organized into Sets and Ways. It uses bits from the PC to index into a Set, and then checks the "Tags" (the remaining upper bits of the PC) of all Ways in that Set. If a Tag matches the requested PC and the Valid bit is `1`, it's a hit.

---

## 3. Advanced GTKWave Signals to Watch
Beyond the 3 basic signals, here are the detailed signals to trace the exact life cycle of an instruction block moving through the uOp cache:

### A. The "Hit" Resolution
* `TOP.Core.frontend.uopCache.tags_X_Y` (Where X is Way, Y is Set) -> Watch the tags being written.
* `TOP.Core.frontend.uopCache.valid_X_Y` -> Watch the valid bit flip to 1 when a block is stored.
* `TOP.Core.frontend.uopCache.hits_0` through `hits_7` -> This is the parallel 8-way tag comparator. When one of these goes high, it means the specific Way matched!

### B. The Write/Store Path (How it learns)
* `TOP.Core.frontend.uopCache.io_write_req_valid` -> Goes high when the IFU writes a decoded block into the cache.
* `TOP.Core.frontend.uopCache.io_write_req_bits_uops_0_inst_raw` -> The raw instruction being saved.
* `TOP.Core.frontend.uopCache.allocWay` -> Tells you which of the 8 ways it chose to store the new block in.

### C. The Dispatch Bypass (Seeing the speedup)
* `TOP.Core.frontend.uop_hit` -> The global bypass signal in the frontend.
* `TOP.Core.frontend.ifu_io_fetch_req_valid` -> When `uop_hit` is 1, you will see this drop to `0`. The IFU goes to sleep!
* `TOP.Core.frontend.ibuf_skids_0_io_enq_valid` -> You will see this spike to `1` simultaneously with the hit, proving that the uOp cache injected the decoded instructions directly into the dispatch queue without waiting for the IFU/Decoder pipeline.

---

## 4. Current Zaqal Parameters (XiangShan Parity)
We upgraded the Zaqal uOp Cache to parity with the high-performance XiangShan (NanHu/KMH) architecture. 

**Our Current Specs (Dynamically adjustable in `ZaqalConfig` / `Parameters.scala`):**
* **Sets**: `uopCacheSets = 64`
* **Associativity**: `uopCacheWays = 8` (8-way Set Associative)
* **Total Lines**: 512 Cache Lines
* **Capacity**: Up to ~3,000 uOps (depending on `fetchWidth`), matching XiangShan's capacity.

This is a massive cache designed to hold deep loops and complex branch paths entirely in decoded format.
