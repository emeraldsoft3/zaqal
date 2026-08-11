# Instruction Cache (ICache)

## 1. Overview
The Instruction Cache (ICache) is responsible for supplying high-bandwidth instruction data to the IFU. In the current iteration, it serves as a non-blocking functional model that directly feeds an underlying memory bus or simulated program memory, retrieving raw program bytes based on the requested PC.

## 2. Detailed Diagram
```mermaid
graph TD
    %% Interfaces
    pc_in([Request PC from Frontend])
    inst_out([Raw Instructions to IFU])
    
    %% Internal
    SRAM[(ICache SRAM / Program Mem)]
    TagCheck{Tag Hit/Miss}
    
    %% Flow
    pc_in --> TagCheck
    TagCheck -->|Hit| SRAM
    TagCheck -->|Miss| ExtMem([AXI/TileLink to L2])
    
    SRAM -->|Read 256-bit Line| inst_out
```

## 3. Configuration & Sizes
- **Line Size**: Typically fetches a cache line matching the frontend fetch width (e.g., 8 instructions $\times$ 32 bits = 256 bits).

## 4. Data Interfaces
### Inputs
- `io.pc`: The 64-bit target address requested by the FTQ.

### Outputs
- `io.ready`: Indicates the requested data is available this cycle.
- `io.insts`: The vector of fetched instruction words.

## 5. Key Internal Logic
- **Line Alignment**: Automatically zeroes out the lower bits of the `pc` to fetch aligned cache blocks.
- **Test Mode Overlay**: In simulation, the ICache may include logic to inject specific hardware test programs (e.g., OoO Issue Queue Verification scripts) directly into the stream, overriding normal memory fetches for rapid debug cycles.

## 6. GTKWave Signals for Debugging
- `TOP.Core.frontend.icache.io_pc`
- `TOP.Core.frontend.icache.io_ready`
- `TOP.Core.frontend.icache.io_insts_0`
