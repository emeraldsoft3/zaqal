# Design Decision: Decoupled Frontends (Fetch vs Decode Width)

In early superscalar CPUs, the entire Frontend was a rigid pipeline: if the CPU decoded 4 instructions per cycle, it explicitly fetched exactly 4 instructions per cycle. Modern high-end processors realize this is a massive bottleneck.

---

## Option 1: Synchronous Fetch/Decode
The Fetch stage and the Decode stage are perfectly locked in step.

**Used by**: Low-end embedded cores, early RISC designs.

- **How it works**: The CPU fetches a 16-byte block, sends it to a 4-wide decoder, and waits. If the decoder stalls, the Fetch stage halts immediately.
- **The Benefit (Pros)**: Very easy to debug. The pipeline is visually and conceptually straight.
- **The Cost (Cons)**: Terrible real-world performance. Cache misses or complex instructions in Decode cause the entire Frontend to grind to a halt instantly, starving the massive execution engine.

---

## Option 2: Decoupled Fetch with Instruction Buffer (Fetch Queue)
The Fetch stage acts independently, wildly over-fetching instructions and dumping them into a massive waiting queue (the Fetch Queue or I-Buffer) for the Decoders to process at their own pace.

**Used by**: All modern high-end processors (Intel Core, AMD Zen, ARM Neoverse, XiangShan).

- **How it works**: The CPU might feature an 8-wide Fetch unit (fetching 32 bytes per cycle) but only a 6-wide Decoder. The Fetch unit sprints ahead of the Decoders, filling up a 32-entry Fetch Queue.
- **The Benefit (Pros)**: "Hides" L1i cache latency. If Fetch hits an L1 miss and stalls for 3 cycles, the Decoders keep happily running because they are draining the buffered Fetch Queue.
- **The Cost (Cons)**: Requires complex branch prediction queuing. If Fetch is running 30 instructions ahead of Decode, the branch predictor must also run 30 instructions ahead, creating massive "Bubble" penalties if the predictor guesses wrong early.

---

## Recommendation for Zaqal

> [!TIP]
> **XiangShan Alignment**
> Zaqal will absolutely use **Option 2: Decoupled Fetch**. In fact, we laid the groundwork for this in Phase 1 by implementing the `FTQ` (Fetch Target Queue) and the `IBUF` (Instruction Buffer). In Phase 4 (Superscalar), we will scale the I-Buffer to smoothly feed our 6-wide Decoders even while Fetch bursts blocks asynchronously.

---

## Recommended Reading / Seminal Papers
- **"Decoupled Access/Execute Computer Architectures" (Smith, 1982)**: The philosophical grandfather paper that proved breaking rigid pipelines into buffered queues maximizes throughput.
- **"Fetch Directed Instruction Prefetching" (Reinman et al., 1999)**: Discusses running an aggressive Fetch engine fully decoupled from the rest of the processor.
