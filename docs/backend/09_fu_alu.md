# ALU (Arithmetic Logic Unit)

## 1. Overview
The ALU is the primary integer execution unit, handling arithmetic, logical, shift, comparison, and bit manipulation instructions. It evaluates all these operations combinationally in a single cycle.

## 2. Detailed Diagram
```mermaid
graph TD
    %% Interfaces
    src1([Operand 1])
    src2([Operand 2])
    dec([DecodeSignals])
    result([Result Data])
    
    %% Submodules
    Adder[Adder Sub-Unit]
    Logical[Logical Sub-Unit]
    Shifter[Shifter Sub-Unit]
    Comparator[Comparator Sub-Unit]
    Bitmanip[Bitmanip Sub-Unit Zba/Zbb/Zbs]
    Mux{Result Mux}
    
    %% Flow
    src1 --> Adder & Logical & Shifter & Comparator & Bitmanip
    src2 --> Adder & Logical & Shifter & Comparator & Bitmanip
    dec --> Adder & Logical & Shifter & Comparator & Bitmanip
    
    Adder --> Mux
    Logical --> Mux
    Shifter --> Mux
    Comparator --> Mux
    Bitmanip --> Mux
    
    Mux -->|Selected by DecodeSignals| result
```

## 3. Configuration & Sizes
- **Datapath**: 64-bit (`xLen`).
- **Latency**: 1 cycle.

## 4. Key Internal Logic
- **Sub-module Delegation**: The ALU delegates specific operations to dedicated sub-modules (e.g., `Adder.scala`, `Shifter.scala`).
- **Bitmanip Extension (Zba, Zbb, Zbs)**: Zaqal explicitly supports advanced bit manipulation. The `Bitmanip` submodule handles operations like `CLZ` (Count Leading Zeros), `CPOP` (Population Count), single-bit sets/clears, and `MIN/MAX` instructions. `Zba` address generation (e.g., `SH1ADD`) is handled directly in the ALU's combinational datapath.
- **Result Mux**: A large `MuxCase` selects the final 64-bit output by matching the `DecodeSignals` (e.g., `is_add`, `is_slt`, `is_clz`) against the sub-module outputs.

## 5. GTKWave Signals for Debugging
- `TOP.Core.backend.execute.alu_0.io_src1`
- `TOP.Core.backend.execute.alu_0.io_src2`
- `TOP.Core.backend.execute.alu_0.io_result`
- `TOP.Core.backend.execute.alu_0.adder.io_result`

## 6. Optimization Decisions & Timing Improvements
To target 1.5 GHz+ operating frequencies on 14nm/7nm PDK nodes, the following ALU and Multiplier optimizations are planned:
1. **Adder-Subtractor Consolidation**: Eliminate separate adder and subtractor units by using a shared adder module with conditional input inversion (`src2 ^ is_sub`) and a `carry-in` bit to minimize silicon footprint and routing density.
2. **Multiplier 3-Stage Pipelining**: Separate the Wallace Tree compression from the final 128-bit Carry-Propagate Addition (CPA) by adding a pipeline register boundary. This ensures the CPA does not form the overall timing bottleneck of the execution core.
3. **Radix-8 Booth Encoding**: Reduce Wallace Tree logic depth and congestion by using Radix-8 Booth encoding (reducing partial product lines from 33 to 22) to lower overall cell delay.
4. **Flat result selection Muxes**: Convert serial nested priority multiplexers to flat, One-Hot decoded multiplexers (`Mux1H`) to enable parallel logic gate mapping.
