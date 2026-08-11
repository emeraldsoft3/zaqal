# Zaqal Core Architecture (Frontend & Backend)

This document maps out the current complete architecture of the Zaqal processor (both frontend and backend). It traces the flow of instructions from branch prediction and instruction fetch, through the Instruction Buffer (IBuffer), decoding, renaming, dispatching, queueing, and execution, up to writeback and registers wakeup.

---

## 1. Architectural Diagram

```mermaid
graph TD
    subgraph Frontend Modules
        BPU[Branch Prediction Unit - BPU]
        FTQ[Fetch Target Queue - FTQ (64 entries)]
        ICache[Instruction Cache - ICache]
        IFU[Instruction Fetch Unit - IFU]
        IBuf[Instruction Buffer - IBuffer (48 entries)]
    end

    subgraph Decode & Rename
        Decoders[6-Wide Decoders]
        Fusion[Instruction Fusion Stage]
        Rename[Rename Stage - RAT]
        FreeList[Free List Manager]
        Snapshots[Rename Table Snapshots]
    end

    subgraph Dispatch
        Disp[Dispatch - Traffic Cop]
        Hazards[Structural Hazard Detection]
    end

    subgraph Issue & Schedule
        BusyTable[Busy Table - Ready States]
        intIq[intIq: Integer Issue Queue - 16 entries]
        memIq[memIq: Memory Issue Queue - 8 entries]
        fpIq[fpIq: FP Issue Queue - 8 entries]
    end

    subgraph Execution Clusters
        subgraph Integer Cluster
            ALU0[ALU 0]
            BRU[BRU - Branch Unit]
            ALU1[ALU 1]
            Mul[Multiplier]
            Div[Divider]
        end
        subgraph Memory Cluster
            LSU[LSU - Load Store Unit]
            DMem[Data Memory]
        end
        subgraph Floating-Point Cluster
            FPU[FPU]
            FPDiv[FP Divider]
            FPMisc[FP Misc Unit]
        end
    end

    subgraph Writeback & Wakeup
        PhyIntRegFile[Integer Physical RegFile - 192/224 Entries]
        PhyFPRegFile[FP Physical RegFile - 192 Entries]
        WakeupBus[5-Port Wakeup Bus]
    end

    %% Frontend Connections
    BPU -->|Branch Target & Metadata| FTQ
    FTQ -->|PC Fetch Address| IFU
    FTQ -->|Synchronized Target PC| ICache
    ICache -->|Raw Inst Bits| IFU
    IFU -->|Predecoded FetchPacket| IBuf
    IBuf -->|6-Wide Instruction Bundle| Decoders

    %% Decode & Rename Connections
    Decoders --> Fusion
    Fusion -->|6 Decoded Ops| Rename
    Rename <-->|Allocate pdest| FreeList
    Rename <--> Snapshots
    Rename -->|6 Renamed Ops w/ pdest| Disp
    Disp --> Hazards
    Hazards -->|Ready & Backpressured Ops| BusyTable
    BusyTable --> intIq
    BusyTable --> memIq
    BusyTable --> fpIq

    %% Issue Queue to EX Cluster Connections
    intIq -->|Deq 0| ALU0
    intIq -->|Deq 0| BRU
    intIq -->|Deq 1| ALU1
    intIq -->|Deq 1| Mul
    intIq -->|Deq 1| Div

    memIq -->|Deq 0| LSU
    LSU <--> DMem

    fpIq -->|Deq 0| FPU
    fpIq -->|Deq 0| FPDiv
    fpIq -->|Deq 0| FPMisc

    %% Writebacks & Wakeups (Data & pdest)
    ALU0 & BRU -->|Result + pdest to Port 0| PhyIntRegFile
    ALU1 & Mul -->|Result + pdest to Port 1| PhyIntRegFile
    Div -->|Result + pdest to Port 2| PhyIntRegFile
    LSU -->|Result + pdest to Port 3| PhyIntRegFile
    FPMisc -->|Result + pdest to Port 4| PhyIntRegFile

    LSU -->|FP Write + pdest| PhyFPRegFile
    FPU & FPMisc -->|FP Write + pdest| PhyFPRegFile
    FPDiv -->|FP Write + pdest| PhyFPRegFile

    %% Wakeup Loops
    ALU0 & BRU -->|Wakeup 0| WakeupBus
    ALU1 & Mul -->|Wakeup 1| WakeupBus
    Div -->|Wakeup 2| WakeupBus
    LSU -->|Wakeup 3| WakeupBus
    FPMisc -->|Wakeup 4| WakeupBus

    WakeupBus -->|Broadcast Ready States| BusyTable
    WakeupBus -->|Wakeup Dependents| intIq & memIq & fpIq
```

---

## 2. Walkthrough of Stage Interactions

1.  **Branch Prediction & Fetch Targets (BPU & FTQ)**:
    - The `BPU` generates the next prediction target address and metadata.
    - These targets are enqueued into the `FTQ` (Fetch Target Queue), which acts as a metadata buffer.
2.  **Instruction Fetching (IFU & ICache)**:
    - The `FTQ` dequeues requests to query the `ICache` and drive the `IFU`.
    - The `ICache` returns the instruction bytes. The `IFU` pre-decodes them (including RVC expansion from 16-bit to 32-bit instructions) and aligns them into a `FetchPacket`.
3.  **Instruction Buffering (IBuffer)**:
    - The `FetchPacket` is enqueued into the 48-entry `IBuffer`. The `IBuffer` decouples the variable-rate frontend from the backend, outputting up to 6 instructions per cycle.
4.  **Decode & Fusion**: 
    - Up to 6 instructions are dequeued from the `IBuffer` per cycle and decoded. Adjacent operations eligible for macro-op fusion (such as `LUI` + `ADDI`) are merged.
5.  **Rename**: 
    - Scalar and Floating-Point logical registers are mapped to physical registers using a `RenameTableWrapper` (which manages the integer RAT, FP RAT, and checkpoint snapshots for branches). The `FreeList` allocates a destination physical register (`pdest`) for every instruction that writes a result.
6.  **Dispatch**: 
    - The `Dispatch` module classifies instructions by execution type (ALU, MEM, BRU, FPU). It carries the allocated `pdest` down the pipeline. It evaluates structural hazards against limits and applies in-order backpressure.
7.  **Issue Queues**: 
    - Ready instructions wait in issue queues (`intIq`, `memIq`, `fpIq`). They monitor the `WakeupBus` to clear operand dependencies.
8.  **Execution Units**: 
    - Once operands are ready, instructions are issued to specialized execution pipelines. Long-latency operations (like the `Divider`) lock their target units and write back to the register files upon completion.
9.  **Wakeup Broadcast**: 
    - Completed instructions broadcast their destination physical registers on the 5-port `WakeupBus` to update the `BusyTable` and wake up dependent instructions waiting in the issue queues.
