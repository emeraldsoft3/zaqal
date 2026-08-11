# Zaqal Architecture: Instruction Flow, Decoding, and Renaming

This document describes the high-level flow of instructions through the Zaqal processor. It provides a deeply detailed look at the 6-wide decoding stage, the macro-op fusion logic, and the intricacies of the superscalar renaming stage (including the Map Tables and Free Lists).

## Mermaid.js Diagram

Copy the code below into [Mermaid Live Editor](https://mermaid.live/) to view the diagram.

```mermaid
graph TD
    %% Frontend
    subgraph Frontend ["Frontend (Fetch Engine)"]
        BPU["BPU (Branch Prediction Unit)<br/>TAGE / Neural Predictor"]
        FTQ["FTQ (Fetch Target Queue)<br/>Deep Instruction Decoupling"]
        IFU["IFU (Instruction Fetch Unit)"]
        ICache["ICache (Instruction Cache)"]
        
        BPU -->|"Predicted PC"| FTQ
        FTQ -->|"Target PC"| IFU
        IFU <-->|"Fetch 128-bit / 8 Parcels"| ICache
    end

    %% Decouple
    IBuffer["IBuffer (Instruction Buffer)<br/>6-Wide Banked Parallel Dequeue"]
    ICache -->|"128-bit Parcel Bundle"| IBuffer

    %% Backend: Decode Stage
    subgraph DecodeStage ["Decode Stage"]
        subgraph Decoders ["6-Wide Parallel Decoders"]
            DEC0["Decoder 0"]
            DEC1["Decoder 1"]
            DEC2["Decoder 2"]
            DEC3["Decoder 3"]
            DEC4["Decoder 4"]
            DEC5["Decoder 5"]
        end
        FusionLogic["Macro-Op Fusion Logic<br/>(e.g., LUI+ADDI, AUIPC+ADDI)"]
        
        IBuffer -->|"Parcel 0"| DEC0
        IBuffer -->|"Parcel 1"| DEC1
        IBuffer -->|"Parcel 2"| DEC2
        IBuffer -->|"Parcel 3"| DEC3
        IBuffer -->|"Parcel 4"| DEC4
        IBuffer -->|"Parcel 5"| DEC5
        
        DEC0 --> FusionLogic
        DEC1 --> FusionLogic
        DEC2 --> FusionLogic
        DEC3 --> FusionLogic
        DEC4 --> FusionLogic
        DEC5 --> FusionLogic
    end

    %% Backend: Renaming Stage
    subgraph RenamingStage ["Renaming Stage (Register Renaming)"]
        subgraph RenameTableWrapper ["RenameTable Wrapper (Int & FP)"]
            subgraph RenameTable ["Rename Table (Map Table)"]
                ArchTable["Architectural Table<br/>(Committed State)"]
                SpecTable["Speculative Table<br/>(Cascading Wire Table for Intra-Bundle Bypassing)"]
            end
            OldPdestMap["Old Pdest Map<br/>(For Recovery/Commit)"]
        end
        
        subgraph FreeListLogic ["Multi-Port Free List"]
            FreeListBuf["Circular Buffer<br/>(Available Physical Regs: size = numPhyRegs - numLogicalRegs)"]
            HeadPtr["Head Pointer<br/>(Speculative Allocation)"]
            TailPtr["Tail Pointer<br/>(Architectural Freeing)"]
        end
        
        FusionLogic -->|"Merged Micro-Ops"| SpecTable
        FusionLogic -->|"Allocate Reqs"| FreeListLogic
        FreeListBuf -->|"Pdest (Physical Dest)"| SpecTable
        SpecTable -->|"Old Pdest"| OldPdestMap
        SpecTable -->|"Renamed Micro-Ops<br/>(psrs1, psrs2, psrs3, pdest)"| IssueQueues
    end

    %% Backend: Issue and Execute
    subgraph IssueAndExecute ["Issue & Execution Stage"]
        IssueQueues["Distributed Issue Queues<br/>(ALU, MEM, FPU, etc.)"]
        
        subgraph ExecuteUnits ["Execution Units"]
            ALU0["ALU 0<br/>(Supports 32-bit Fused Ops)"]
            ALU1["ALU 1"]
            BRU["BRU (Branch Unit)"]
            LSU["LSU (Load/Store Unit)"]
            FPU["FPU (Floating Point Unit)"]
        end
        
        IssueQueues -->|"Ready Ops"| ExecuteUnits
    end

    %% Writeback/Commit
    subgraph CommitStage ["Commit Stage"]
        ROB["ROB (Reorder Buffer)<br/>In-Order Commitment"]
    end
    
    ExecuteUnits -->|"Execution Results"| ROB
    ROB -->|"Commit Updates (Redirects)"| ArchTable
    ROB -->|"Free Old Pdest"| TailPtr

    %% Styling
    classDef frontend fill:#f9e0f0,stroke:#333,stroke-width:2px;
    classDef decode fill:#e0f0f9,stroke:#333,stroke-width:2px;
    classDef rename fill:#f9f5e0,stroke:#333,stroke-width:2px;
    classDef execute fill:#e0f9e0,stroke:#333,stroke-width:2px;
    classDef commit fill:#e0e0e0,stroke:#333,stroke-width:2px;
    classDef important fill:#f9a03f,stroke:#333,stroke-width:3px;
    
    class Frontend frontend;
    class DecodeStage decode;
    class RenamingStage rename;
    class IssueAndExecute execute;
    class CommitStage commit;
    class SpecTable,ArchTable,FreeListBuf important;
```

## Renaming Stage Details

1.  **6-Wide Decoding**: The IBuffer outputs 6 parcels which are decoded in parallel.
2.  **Fusion Logic**: The fusion logic looks across the decoded bundle. If it spots a `LUI` and `ADDI` targeting the same register (e.g., at Decoder 0 and Decoder 2), it merges the immediate values into the `LUI` instruction and marks the `ADDI` instruction to be "fused away" (ignored).
3.  **Free List Allocation**:
    - Uses a circular buffer holding available physical registers.
    - Speculative execution advances the `Head Pointer` to allocate a `Pdest` for valid instructions.
    - Fused-away instructions do *not* request a register, saving physical register space.
4.  **Rename Table (Map Table)**:
    - Divided into `Int` and `FP` wrappers.
    - **Intra-Bundle Bypassing**: Uses a cascading wire table (`curr_spec_table`) so if Decoder 1 depends on Decoder 0's result, it instantly sees the newly allocated physical register.
    - The `Architectural Table` tracks the true, non-speculative state updated only upon ROB commitment.
    - Stores the `Old Pdest` so that if a branch mispredicts, the ROB knows which physical register to return to the Free List.
