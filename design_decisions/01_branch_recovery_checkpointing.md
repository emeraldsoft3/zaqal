# Design Decision: Branch Recovery & RAT Checkpointing

As Zaqal advances toward an Out-of-Order (OoO), 6-wide superscalar architecture (Phases 4 & 7), we must decide how to recover the processor state (specifically the Register Alias Table / Map Table) after a branch misprediction. 

Since Zaqal aims for high performance, we explicitly **reject** low-end budget approaches like "Walking the ROB backward." We will only consider state-of-the-art (SOTA) checkpointing methods. 

Below are the three high-end architectural choices available to us when we implement our Rename stage:

---

## Option 1: Full Snapshot (The "XiangShan" & Intel Style)
This is the most aggressive and fastest method. Every time the Fetch/Rename stage sees a branch, the hardware literally copies the entire Register Alias Table (RAT) into a "Shadow Table."

**Used by**: XiangShan (Kunminghu), Intel Core (Sandy Bridge/Skylake forward).

- **How it works**: When a branch is predicted, a full hardware snapshot (checkpoint) of the Rename Map is saved.
- **The Recovery**: If the branch is wrong, the CPU doesn't conceptually "recalculate" anything. It just triggers a multiplexor to switch the active RAT to the saved Shadow Table.
- **Recovery Speed**: **Zero cycles**. The core is ready to Rename the correct path on the very next clock cycle.
- **The Cost (Cons)**: Massive silicon area. If the Map Table has 32 logical entries mapping to 128 physical entries, and we support 16 checkpointed branches in flight, we need 16 parallel copies of that entire table.

---

## Option 2: Walk-back / Undo Log (The "AMD Zen" Style)
A hybrid approach designed to save power and silicon footprint while remaining extremely performant. 

**Used by**: AMD Zen (Zen 1 through Zen 4).

- **How it works**: Instead of aggressively copying the whole table on every single branch, the processor maintains an "Undo Log" (sometimes integrated with the Retirement Map Table). When a mispredict happens, it walks back through the log to reconstruct the correct state.
- **The Trade-off**: The CPU might only take full snapshots for "hard-to-predict" branches, relying on the log for the rest.
- **Recovery Speed**: **1–3 cycles**. Slightly slower than a full snapshot, but massively faster than sequentially walking the ROB. 
- **The Benefit (Pros)**: Saves significant power and area because you are not constantly routing hundreds of bits into shadow SRAMs every time a branch passes Rename.

---

## Option 3: Distributed Checkpointing (The "ARM Neoverse" Style)
A highly scalable approach used in ultra-wide processors handling massive instruction throughput.

**Used by**: High-end ARM cores (AWS Graviton, Apple M-series).

- **How it works**: Instead of checkpointing just the Map Table, the architectural state is distributed. The processor checkpoints the Free List (the pool of available physical registers) and the Branch Mask/BRT state simultaneously across discrete units.
- **The Benefit (Pros)**: Allows the core to be remarkably "wide" (processing 8+ instructions at once) without creating a single giant monolithic bottleneck at the Rename stage.
- **Complexity (Cons)**: Tremendously complex to wire together and formalize. It requires meticulous cross-module synchronization during a flush.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> If our goal is to closely mirror XiangShan (Kunminghu), we will lean toward **Option 1: Full Snapshot**. While it consumes more area, it is conceptually the "cleanest" for achieving a 0-cycle rename recovery and is deeply explored in the XiangShan codebase. The choice will be finalized during **Phase 7: Out-of-Order Engine**.

---

## Recommended Reading / Seminal Papers
- **"MIPS R10000 Microprocessor Architecture" (Yeager, 1996)**: Explains the classic Explicit Register Renaming and mapping approach.
- **"Checkpointing Alternatives for High Performance Superscalar Processors" (Akkary et al., 2003)**: Argues the trade-offs of deep snapshotting versus log-based walk-backs in modern deep pipelines.
