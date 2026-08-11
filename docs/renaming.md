sequenceDiagram
    participant FE as Frontend & Decoder
    participant RAT as Speculative RAT
    participant FL as Free List
    participant RF as Physical Register File
    Note over FE, RF: Cycle 6: Renaming Initial Bundle
    FE->>RAT: Rename 0x00: addi x1, x0, 10
    RAT->>RAT: Map x1 -> p32
    FE->>RAT: Rename 0x02: shadow inst (unaligned garbage)
    RAT->>RAT: Map x1 -> p33 (Corrupted!)
    Note over FE, RF: Cycle 7: Branch Rename & Snapshot
    FE->>RAT: Rename 0x0c: beq (Branch)
    RAT->>RAT: Save Snapshot 0: x1 -> p33 (Saves Corrupted Map)
    Note over FE, RF: Cycle 14: Redirect & Recovery
    Note over RAT: Restore RAT from Snapshot 0 (x1 -> p33)
    FE->>RAT: Rename 0x24: addi x1, x1, 6
    RAT->>FE: Read rs1 (x1) -> maps to p33
    RAT->>FL: Allocate rd (x1) -> p36
    Note over FE, RF: Execution Stage
    RF->>FE: Read p33 (value = 0)
    Note over FE: Compute: 0 + 6 = 6
    FE->>RF: Write 6 to p36 (Expected: 16!)