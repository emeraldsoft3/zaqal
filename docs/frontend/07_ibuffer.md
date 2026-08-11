# Instruction Buffer (IBUF)

## 1. Overview
The `IBUF` module serves as the decoupling queue between the Instruction Fetch Unit (IFU) and the Decode/Rename stages. It absorbs bursts of variable-sized fetch packets from the frontend and outputs a steady stream of up to 6 instructions per cycle to the downstream backend logic.

## 2. Detailed Diagram
```mermaid
graph TD
    %% Interfaces
    inst_in([io.inst_data from IFU: FetchPacket])
    flush_in([io.flush from Redirect])
    
    subgraph IBUF circular buffer (48 Entries)
        BufferVec["buffer_0_inst_raw to buffer_47_inst_raw (32-bit registers)"]
        ValidVec["valid_0 to valid_47 (1-bit registers)"]
        Head[Head Pointer: 6-bit]
        Tail[Tail Pointer: 6-bit]
    end

    subgraph Dequeue Matrix (6-wide Output)
        Port0[io.out_0_bits_inst_raw]
        Port1[io.out_1_bits_inst_raw]
        Port2[io.out_2_bits_inst_raw]
        Port3[io.out_3_bits_inst_raw]
        Port4[io.out_4_bits_inst_raw]
        Port5[io.out_5_bits_inst_raw]
    end

    %% Enqueue Logic
    inst_in -->|1. Masked Enqueue: Up to 16 instructions| BufferVec
    inst_in -->|2. Set Valid Bits| ValidVec
    inst_in -->|3. Advance count| Tail
    
    %% Dequeue Logic
    Head -.->|4. Index base| BufferVec & ValidVec
    BufferVec -->|5. Multi-port Dequeue| Port0 & Port1 & Port2 & Port3 & Port4 & Port5
    ValidVec -->|6. Set Port Valids| Port0 & Port1 & Port2 & Port3 & Port4 & Port5
    
    %% Control
    flush_in -->|Reset pointers & clear valids| Head & Tail & ValidVec
```

## 3. Configuration & Sizes
- **Capacity (`ibufSize`)**: 48 entries (Configurable via `ZaqalParams`).
- **Enqueue Width**: Up to 16 instructions (`predictWidth`), mapped via an enqueue mask.
- **Dequeue Width**: Up to 6 instructions (`decodeWidth`).
- **Internal Storage**: 48 registers storing `MicroOp` bundles, exposed in GTKWave as:
  - `TOP.Core.frontend.ibuf.buffer_0_inst_raw[31:0]` to `TOP.Core.frontend.ibuf.buffer_47_inst_raw[31:0]`.

## 4. Signal Analysis & Internal Mechanics

### 4. Data Interfaces & Module Connectivity

### 1. What does the IBUF receive inputs from?
The `IBUF` receives raw instruction packets from the **Instruction Fetch Unit (IFU)** via a decoupled interface, buffered through a `SkidBuffer` to absorb redirects.
* **Chisel Connection (`Frontend.scala`)**:
  ```scala
  ibuf.io.inst_data <> SkidBuffer(ifu.io.toIbuffer, is_valid_redirect)
  ```

### 2. To which modules does the IBUF output?
The IBUF outputs a 6-wide bundle of instructions (`io.out(0)` to `io.out(5)`) to the **Decoders** inside the `Backend` module.
* **Chisel Connection (`Frontend.scala` to `Backend.scala`)**:
  ```scala
  // Inside Frontend.scala: Exposes IBUF output to top level dispatch interface
  for (i <- 0 until decodeWidth) {
    io.dispatch(i) <> ibuf.io.out(i)
  }
  ```

### 3. Backend Pipeline Flow: Decoders -> Rename -> Dispatch
Once the backend receives the 6-wide `io.dispatch` bundle from the frontend:
1. **Decoders**: The raw instruction bits are decoded in parallel:
   ```scala
   decoders(i).io.inst := io.dispatch(i).bits.inst_raw
   decoded_uops(i).decode := decoders(i).io.out
   ```
2. **Rename**: Logical registers are mapped to physical registers:
   ```scala
   rat.io.dec(i) := decoded_uops(i).decode
   decoded_uops(i).psrs1 := rat.io.psrs1(i)
   decoded_uops(i).psrs2 := rat.io.psrs2(i)
   ```
3. **Dispatch**: The fully renamed micro-ops (`decoded_uops(i)`) are passed into the `Dispatch` stage to be routed to issue queues:
   ```scala
   dispatch.io.in(i).valid := io.dispatch(i).valid && can_allocate_all
   dispatch.io.in(i).bits  := decoded_uops(i)
   ```

Therefore, the exact structural flow is:
$$\text{IFU} \xrightarrow{\text{toIbuffer}} \text{SkidBuffer} \xrightarrow{} \textbf{IBUF} \xrightarrow{\text{io.out}} \text{Decoders} \xrightarrow{} \text{Rename Stage} \xrightarrow{} \text{Dispatch Module} \xrightarrow{} \text{Issue Queues}$$

---

## 5. Backpressure and Ready Signal Anomaly

### The Anomaly
In simulation, you will observe that **`TOP.Core.frontend.ibuf.io_out_0_ready`** (through `io_out_5_ready`) is **always `1`**, and `valid` is often `1`, even when long-latency instructions (like division) are executing. You do not see backpressure (stalling) at the output of the Instruction Buffer.

### Why does this happen?
This behavior is caused by a design simplification in the backend's dispatch and backpressure wiring:

1. **Tied-off Ready Wires**: In `zaqal/backend/Backend.scala`, the ready signals from the execution clusters are tied off to `true`:
   ```scala
   dispatch.io.aluReady := true.B
   dispatch.io.memReady := true.B
   dispatch.io.bruReady := true.B
   dispatch.io.fpuReady := true.B
   ```
2. **Ignored Queue Backpressure**: The `Dispatch` module (`zaqal/backend/Dispatch.scala`) calculates `port_ready(i)` and `can_dispatch(i)` (which directly drives the ready signal of its inputs: `io.in(i).ready := can_dispatch(i)`) solely based on `aluReady`, `memReady`, etc., and local structural hazard checks. It **never** reads the `.ready` status of its output ports (`io.aluOut(i).ready`, `io.memOut(i).ready`, etc.).
3. **Broken Pipeline Feedback**: Because `io.dispatch(i).ready` connects directly to the IBUF's `io.out(i).ready`, and `io.dispatch(i).ready` is derived from `can_dispatch(i)` (which is always `1` due to the tied-off ready wires), **the backend is telling the IBUF that it is always ready to receive instructions, regardless of the issue queues' capacity**.

### Why doesn't the processor crash?
- **Issue Queue Capacity**: The `IssueQueue` (`intIq`) has a capacity of 16 entries.
- **Divider Dequeue Backpressure**: When a division executes, `Execute.scala` does assert backpressure on the *dequeue* port of the `IssueQueue` (`io.deq(0).ready := div.io.ready`), which stops the `IssueQueue` from issuing new division operations.
- **Small Test Programs**: Because the assembly test programs we run are small (under 16 instructions in flight), the 16-entry `IssueQueue` never actually fills up to maximum capacity.
- **Result**: Even though the backend backpressure path to the IBUF is structurally open (non-functional), the queue occupancy never overflows, meaning instructions are never silently dropped in these test cases. If a larger benchmark were run, this lack of backpressure would result in queue overflow and lost instructions.

---

## 6. GTKWave Signals for Debugging
- `TOP.Core.frontend.ibuf.io_inst_data_valid`
- `TOP.Core.frontend.ibuf.io_inst_data_ready`
- `TOP.Core.frontend.ibuf.head`
- `TOP.Core.frontend.ibuf.tail`
- `TOP.Core.frontend.ibuf.io_out_0_valid` to `io_out_5_valid`
- `TOP.Core.frontend.ibuf.io_out_0_ready` to `io_out_5_ready`
- `TOP.Core.frontend.ibuf.buffer_0_inst_raw` to `TOP.Core.frontend.ibuf.buffer_47_inst_raw`
