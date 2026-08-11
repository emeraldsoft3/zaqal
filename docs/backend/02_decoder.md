# Decoder Stage

## 1. Overview
The Decoder stage maps raw 32-bit instructions (which are RVC-expanded if they were compressed) to internal control bundles (`DecodeSignals`). It parses opcodes, generates immediates, flags architectural register usage, and identifies operation types. 

In Zaqal's 6-wide pipeline, the backend instantiates a vector of **6 decoders** in parallel to decode up to 6 instructions per cycle.

---

## 2. 6-Wide Decoder Pipeline & Rename Routing

The following diagram illustrates how the 6 parallel decoders process a fetch bundle and route their outputs to the Rename stage:

```mermaid
graph TD
    subgraph Frontend Input
        IBufOut[IBuffer Output: 6-Wide io.dispatch Bundle]
    end

    subgraph 6-Wide Decoders 
        Dec0[Decoder 0]
        Dec1[Decoder 1]
        Dec2[Decoder 2]
        Dec3[Decoder 3]
        Dec4[Decoder 4]
        Dec5[Decoder 5]
    end

    subgraph Rename & FreeList Allocation 
        RAT[Register Alias Table - RAT]
        FL[Free List Managers]
        DecodedUops["Vec(6, DecodedMicroOp)"]
    end

    subgraph Dispatch Stage
        Disp[Dispatch Module]
    end

    %% Wiring Inputs
    IBufOut -->|io.dispatch0.bits.inst_raw| Dec0
    IBufOut -->|io.dispatch1.bits.inst_raw| Dec1
    IBufOut -->|io.dispatch2.bits.inst_raw| Dec2
    IBufOut -->|io.dispatch3.bits.inst_raw| Dec3
    IBufOut -->|io.dispatch4.bits.inst_raw| Dec4
    IBufOut -->|io.dispatch5.bits.inst_raw| Dec5

    %% Wiring Outputs to Rename
    Dec0 -->|io.out| RAT & DecodedUops
    Dec1 -->|io.out| RAT & DecodedUops
    Dec2 -->|io.out| RAT & DecodedUops
    Dec3 -->|io.out| RAT & DecodedUops
    Dec4 -->|io.out| RAT & DecodedUops
    Dec5 -->|io.out| RAT & DecodedUops
    
    %% FreeList Allocation
    FL -->|Allocate pdest| DecodedUops
    
    %% Wiring out of Rename
    DecodedUops -->|Renamed Micro-Ops: psrs1, psrs2, pdest| Disp
```

---

## 3. After Decoders: Where Do the Signals Go?

Immediately after the decoding step, the decoded signals enter the **Rename Stage**. Here is how the information flows step-by-step:

1. **Decoder Extraction**: Each decoder `i` extracts the logical register fields (`rs1`, `rs2`, `rd`) and instruction flags.
2. **Rename Lookup**: The logical source registers (`rs1`, `rs2`, `rs3`) are sent to the Register Alias Table (`rat`):
   ```scala
   rat.io.dec(i) := decoders(i).io.out
   ```
3. **Physical Register Retrieval**: The `rat` returns the physical register tags currently mapped to those logical registers. These are written into the renamed micro-op bundle:
   ```scala
   decoded_uops(i).psrs1 := rat.io.psrs1(i)
   decoded_uops(i).psrs2 := rat.io.psrs2(i)
   decoded_uops(i).psrs3 := rat.io.psrs3(i)
   ```
4. **Physical Destination Allocation**: If the instruction writes to a register (`rf_wen` or `fp_wen`), the `FreeList` allocates a new physical register (`pdest`), which is mapped in the RAT:
   ```scala
   decoded_uops(i).pdest := MuxCase(0.U, Seq(
     intFreeList.io.allocateReq(i) -> intFreeList.io.allocatePhyReg(i),
     fpFreeList.io.allocateReq(i)  -> fpFreeList.io.allocatePhyReg(i)
   ))
   
   rat.io.renamePorts(i).wen  := io.dispatch(i).fire && (rf_wen || fp_wen)
   rat.io.renamePorts(i).addr := dec.rd
   rat.io.renamePorts(i).data := decoded_uops(i).pdest
   ```
5. **Dispatch Routing**: The completed `DecodedMicroOp` bundle (containing both decoded control flags and physical registers) is passed to the **Dispatch stage**, which directs them to the correct issue queues.

---

## 4. Chisel Source Implementation

In [`Backend.scala`](file:///wsl.localhost/Ubuntu/home/emerald/zaqal/backend/src/zaqal/backend/Backend.scala), the 6 decoders are instantiated and wired as follows:

```scala
  // Instantiate 6 decoders in a vector
  val decoders = Seq.fill(decodeWidth)(Module(new Decoder))

  // Connect decoders to raw instruction bits and rename table
  for (i <- 0 until decodeWidth) {
    val dec = decoded_uops(i).decode
    
    // Connect input raw instruction from IBuffer output
    decoders(i).io.inst := io.dispatch(i).bits.inst_raw
    
    // Save decoded control signals into the uop pipeline registers
    decoded_uops(i).decode := decoders(i).io.out
    decoded_uops(i).uop := io.dispatch(i).bits
    
    // Connect decoded register numbers directly to Rename Table read ports
    rat.io.dec(i) := dec
  }
```

---

## 5. GTKWave Signals for Debugging
- `TOP.Core.backend.decoders_0.io_inst[31:0]` (through `decoders_5`)
- `TOP.Core.backend.decoders_0.io_out_is_add` (ALU add operation flag)
- `TOP.Core.backend.decoders_0.io_out_imm[63:0]` (Parsed immediate)
- `TOP.Core.backend.decoders_0.io_out_rd[4:0]` (Logical destination register)
- `TOP.Core.backend.decoders_0.io_out_rs1[4:0]` (Logical source register 1)
