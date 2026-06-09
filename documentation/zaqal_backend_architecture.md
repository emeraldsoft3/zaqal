# Zaqal Clustered Backend Architecture

This document maps out the current architecture of the Zaqal processor's backend. It traces the flow of instructions from the Instruction Buffer (IBuffer) through decoding, renaming, dispatching, queueing, and execution, up to writeback and registers wakeup.

---

## 1. Architectural Diagram

```mermaid
graph TD
    subgraph Frontend
        IFQ[Instruction Buffer - IBuffer]
    end

    subgraph Decode & Rename
        Decoders[6-Wide Decoders]
        Fusion[Instruction Fusion Stage]
        Rename[Rename Stage - RenameTable]
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
        RegFile[Scalar RegFile - 7R / 5W]
        FPRegFile[FP RegFile - 4R / 3W]
        WakeupBus[5-Port Wakeup Bus]
    end

    %% Flows
    IFQ -->|6-Wide Bundle| Decoders
    Decoders --> Fusion
    Fusion -->|6 Decoded Ops| Rename
    Rename <--> FreeList
    Rename <--> Snapshots
    Rename -->|6 Renamed Ops| Disp
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

    %% Writebacks & Wakeups
    ALU0 & BRU -->|Port 0 Write| RegFile
    ALU1 & Mul -->|Port 1 Write| RegFile
    Div -->|Port 2 Write| RegFile
    LSU -->|Port 3 Write| RegFile
    FPMisc -->|Port 4 Write| RegFile

    LSU -->|FP Write| FPRegFile
    FPU & FPMisc -->|FP Write| FPRegFile
    FPDiv -->|FP Write| FPRegFile

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

1.  **Decode & Fusion**: Up to 6 instructions are dequeued from the `IBuffer` per cycle and decoded. Adjacent operations eligible for macro-op fusion (such as `LUI` + `ADDI`) are merged.
2.  **Rename**: Scalar and Floating-Point logical registers are mapped to physical registers using a `RenameTableWrapper` (which manages the integer RAT, FP RAT, and checkpoint snapshots for branches).
3.  **Dispatch**: The `Dispatch` module classifies instructions by execution type (ALU, MEM, BRU, FPU). It evaluates structural hazards against limits and applies in-order backpressure (stalling the frontend if downstream queues or ports are saturated).
4.  **Issue Queues**: Ready instructions wait in issue queues (`intIq`, `memIq`, `fpIq`). They monitor the `WakeupBus` to clear operand dependencies.
5.  **Execution Units**: Once operands are ready, instructions are issued to specialized execution pipelines. Long-latency operations (like the `Divider`) lock their target units and write back to the register files upon completion.
6.  **Wakeup Broadcast**: Completed instructions broadcast their destination physical registers on the 5-port `WakeupBus` to update the `BusyTable` and wake up dependent instructions waiting in the issue queues.
