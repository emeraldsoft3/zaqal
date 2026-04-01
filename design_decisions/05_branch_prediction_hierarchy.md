# Design Decision: Branch Prediction Hierarchy & BTB

While virtually all modern high-end processors have converged on TAGE (Tagged Geometric) predictors for conditional branching, the architecture fundamentally diverges on how they store and predict the actual *targets* of indirect jumps (JALR) inside the Branch Target Buffer (BTB).

---

## Option 1: Virtual Address BTB (Full Target Storage)
The Branch Target Buffer explicitly stores the entire 64-bit target address for every branch it tracks.

**Used by**: Classic Intel architectures, early ARM implementations.

- **How it works**: When a JALR instruction is observed, the CPU memorizes the full 64-bit physical or virtual address it jumped to. The next time it fetches that PC, the BTB spits out the entire 64-bit target.
- **The Benefit (Pros)**: Blistering fast retrieval mechanisms. Zero decoding or math required on the frontend to figure out where to fetch next.
- **The Cost (Cons)**: Tremendously expensive in silicon space (SRAM mapping). Storing 64 independent bits translates into a severely smaller tracking history. A 4K-entry BTB storing 64 bits per entry consumes vast real estate, meaning older branch targets get evicted constantly.

---

## Option 2: Compressed/Offset BTB
Instead of copying full absolute addresses, the BTB heavily compresses targets, frequently storing only the *offset* or the few bits that changed relative to the current PC.

**Used by**: XiangShan (Kunminghu), modern high-density processors.

- **How it works**: Knowing that the vast majority of program jumps occur locally (within the same executable page or module), the BTB compresses the 64-bit target down to an offset (e.g., +0x4A0). 
- **The Benefit (Pros)**: Dramatically increases the BTB's capacity. Because each entry only requires 16-20 bits instead of 64, the processor can "memorize" up to 4x as many branches in the exact same silicon footprint. This guarantees a far superior "Hit Rate" for massive complex software structures (like Operating System kernels).
- **The Cost (Cons)**: Requires complex and instant mathematical reconstruction in the critical path of the Frontend. To predict the target, the hardware must physically execute `PC + Offset` on a microscopic cycle timing budget.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will leverage an implementation mirroring **Option 2: Compressed/Offset BTB**. As highlighted by the SOTA roadmap, dedicating massive SRAM footprints to storing redundant 64-bit absolute pointers is crippling for overall performance. XiangShan's multi-level BTB design heavily relies on compression to achieve its enormous prediction history sizes.

---

## Recommended Reading / Seminal Papers
- **"A Case for (Partially) TAgged GEometric History Length Branch Prediction" (Seznec & Michaud, 2006)**: Defines the TAGE predictor algorithm structurally.
- **"Micro-Architecture of the XiangShan Open-Source 64-bit RISC-V Processor"**: The official paper discussing the specific compression geometry and hierarchy of XiangShan's multi-level BTB design.
