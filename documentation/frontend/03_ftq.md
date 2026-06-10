# Fetch Target Queue (FTQ)

## 1. Overview
The Fetch Target Queue (FTQ) records the history of fetch packets requested by the BPU. It maintains metadata (such as original PC, prediction details, and epoch) for instructions as they traverse the pipeline. When instructions commit, or when a branch misprediction occurs, the backend consults the FTQ to recover the correct frontend state.

## 2. Detailed Diagram
```mermaid
graph TD
    %% Interfaces
    bpu_in([From BPU: Decoupled FetchRequest])
    ifu_out([To IFU / ICache: Decoupled FetchRequest])
    backend_read([Backend Read Port: io.readPtr / io.readData])
    
    subgraph FTQ Core (64 Entries)
        Queue["RAM Array [64] (FetchRequest Bundle)"]
        EnqPtr[Enqueue Pointer: 6-bit]
        DeqPtr[Dequeue Pointer: 6-bit]
        Occupancy[Occupancy Counter: 7-bit]
    end
    
    subgraph Metadata per Entry (16 Slots)
        PCVec["Vector of 16 PCs (pc_0 to pc_15)"]
        Mask[Valid Mask: 8-bit]
        Prediction[Prediction Metadata]
        FTQTag[FTQ Pointer Tag: 6-bit]
    end

    %% Flow
    bpu_in -->|1. Enqueue Request| Queue
    EnqPtr -.->|Indexes| Queue
    Queue -->|2. Dequeue Request| ifu_out
    DeqPtr -.->|Indexes| Queue
    
    backend_read -->|3. Read Index| Queue
    Queue -->|4. Retrieve Entry| PCVec & Mask & Prediction & FTQTag
    PCVec & Mask & Prediction & FTQTag -->|5. Output FetchPacket| backend_read
```

## 3. Configuration & Sizes
- **Capacity**: 64 entries (`ftqEntries`).
- **Entry Structure**: Each entry tracks one fetch packet. Since Zaqal supports the Compressed (RVC) extension, a single 16-byte cache line fetch can contain up to **16 compressed instructions**. Therefore, each FTQ entry tracks up to **16 individual Instruction PCs** (`predictWidth` = 16).
- **Pointer Width**: 6 bits (`ftqPtrWidth`).

## 4. Data Interfaces
### Inputs
- `io.fromBpu`: Fetch target predictions.
- `io.readPtr`: A backend index pointer requesting metadata for a specific fetch packet.
- `io.flush`: Asynchronously invalidates FTQ entries on a pipeline redirect.

### Outputs
- `io.toIfu`: Forwards the request address to the IFU and ICache.
- `io.toICache`: Synchronized valid signal to the ICache.
- `io.readData`: Provides the `FetchPacket` metadata requested by the backend's `readPtr`.
  - **Why are there 16 PC signals (`io_readData_pc_0` to `io_readData_pc_15`)?**
    Because a single fetch packet contains a vector of up to 16 instructions. The interface broadcasts the PCs for all 16 potential slots in parallel so downstream stages (such as the IBUF or Predecoder) can associate the correct PC with any RVC-expanded instruction.
- `io.occupancy`: Exposes the number of currently active fetch blocks in flight.

## 5. Key Internal Logic
- **Metadata Vault**: While the raw instruction bits are fetched from the ICache, the FTQ acts as a side-band memory storing the *context* of that fetch (what the BPU predicted, what the epoch was).
- **Backend Coupling**: The Rename and Commit stages receive an `ftqPtr` embedded in the micro-op payload. They use this pointer to index back into the FTQ via `io.readPtr` to finalize state updates or trigger branch recovery.

## 6. GTKWave Signals for Debugging
- `TOP.Core.frontend.ftq.io_fromBpu_valid`
- `TOP.Core.frontend.ftq.io_readPtr`
- `TOP.Core.frontend.ftq.io_readData_pc_0` to `TOP.Core.frontend.ftq.io_readData_pc_15`
- `TOP.Core.frontend.ftq.occupancy`
- `TOP.Core.frontend.ftq.enqPtr`
- `TOP.Core.frontend.ftq.deqPtr`
