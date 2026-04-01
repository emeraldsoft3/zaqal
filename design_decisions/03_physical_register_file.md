# Design Decision: Physical Register File Architecture

Where do the actual data values (the results of computation) live while instructions are waiting to commit (retire) out-of-order?

---

## Option 1: Explicit Physical Register File (PRF)
This is the universally accepted standard for deep, Out-of-Order superscalar architectures.

**Used by**: XiangShan, AMD Zen, MIPS R10k, ARM.

- **How it works**: A dedicated, massive array of registers (e.g., 128 to 256 physical entries). The Reorder Buffer (ROB) itself holds *zero* data; it merely holds a tag pointing to where the physical data sits in the PRF.
- **The Benefit (Pros)**: Vastly more power-efficient and scalable to extremely deep pipelines. An instruction can write its result to the PRF immediately, and subsequent instructions simply read that PRF index. The ROB can be made incredibly deep (hundreds of entries) without bloating the silicon area because its entries are extremely small (just tags).
- **The Cost (Cons)**: Requires complex Register Renaming logic and a "Free List" management system to constantly track exactly which PRF entries contain final, valid values and which can be safely overwritten.

---

## Option 2: Merged ROB/Data Architecture
An older paradigm where the rename logic maps directly into the Reorder Buffer.

**Used by**: Older Intel Cores (Pentium Pro to Nehalem), early x86 architectures.

- **How it works**: The architectural registers (x0-x31 or EAX/EBX) exist independently. However, temporary results wait inside the actual Reorder Buffer (ROB). Every ROB entry has a giant data field attached to it.
- **The Benefit (Pros)**: Logically simpler to concept map. When the ROB slot commits, the data physically moves from the ROB into the permanent Architectural Register File (ARF). 
- **The Cost (Cons)**: Highly inefficient for silicon density and power. Moving data linearly across the chip constantly consumes vast amounts of power. Because every ROB entry must hold 64 physical bits (in a 64-bit architecture), the ROB bloats in physical size, effectively limiting how "deep" the out-of-order window can be.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will absolutely use **Option 1: Explicit Physical Register File (PRF)**. It has universally won the architectural war for high-performance processors. It perfectly decouples execution storage from the instruction tracking stage, which is precisely how XiangShan structures its data routing.

---

## Recommended Reading / Seminal Papers
- **"The MIPS R10000 Superscalar Microprocessor" (Yeager, 1996)**: The foundational paper introducing the architectural decoupling of the Reorder Buffer (ROB) from the Physical Register File. It pioneered the PRF-based renaming strategy used in almost every high-end mobile and server chip today.
