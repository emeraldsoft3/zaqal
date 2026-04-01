# Design Decision: Issue Queue Structure

Once instructions are renamed, they wait in a Queue until their operands (data) are ready. The CPU must "wake up" the instruction and "select" it for execution. The structure of this waiting area defines the physical layout of the core.

---

## Option 1: Unified Issue Queue (The "Intel" Style)
All instructions (Algebra, Floating Point, Memory, Branches) wait in one giant, centralized pool.

**Used by**: Intel Core (Skylake/Ice Lake/Raptor Lake).

- **How it works**: A massive 100+ entry queue where any functional unit can pull any ready instruction simultaneously.
- **The Benefit (Pros)**: Ultimate Load Balancing. If a program is entirely ALU-heavy, it can consume the entire 100-entry queue, maximizing IPC (Instructions Per Clock).
- **The Cost (Cons)**: Tremendously difficult to build. The wiring complexity to broadcast "Wakeup" tags and arbitrate "Selection" across 100+ slots to 6+ execution ports causes severe timing bottlenecks, preventing high clock speeds.

---

## Option 2: Distributed Issue Queues (The "XiangShan" Style)
The waiting area is split into specialized, smaller queues (e.g., one queue strictly for ALUs, another strictly for Memory Loads/Stores).

**Used by**: XiangShan, AMD Zen, Apple M-Series.

- **How it works**: The Dispatch stage acts as a traffic cop, routing an `ADD` instruction to the Integer Queue, and a `LOAD` to the Memory Queue.
- **The Benefit (Pros)**: Much easier to route and route signals rapidly. Smaller queues mean faster "Wakeup/Select" loops, which enables the processor to hit extremely high clock frequencies (2GHz+).
- **The Cost (Cons)**: Fragmentation. If the program is ALU-heavy, the Int Queue might fill up completely, forcing the entire pipeline to stall, even if the Memory Queue is completely empty and "wasting" space.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will use **Option 2: Distributed Issue Queues**. Writing a fully unified issue queue in Chisel that compiles to a fast FPGA/ASIC frequency is exceptionally difficult. Splitting them makes the design modular, easier to debug, and inherently aligns with XiangShan's `IssueQueue.scala` architectures.

---

## Recommended Reading / Seminal Papers
- **"Complexity-Effective Superscalar Processors" (Palacharla, Jouppi, Smith, 1997)**: This is *the* seminal paper that mathematically proved centralized instruction windows (unified queues) create hardware delays that scale quadratically $O(N^2)$, forcing the industry to adopt distributed/clustered issue queues to achieve high clock speeds.
