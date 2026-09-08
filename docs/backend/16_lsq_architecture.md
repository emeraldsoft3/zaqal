# 16. Load/Store Queues (LSQ) & Out-of-Order Memory Architecture

## Overview
In an Out-of-Order (OoO) superscalar processor like Zaqal, arithmetic operations can be renamed using the Register Alias Table (RAT) to eliminate WAW and WAR false hazards. However, **memory cannot be renamed at decode/dispatch** because the target physical address is unknown until the Address Generation Unit (AGU) computes `base + offset`.

The **Load/Store Queues (LSQ)** provide the hardware foundation for:
1. **Speculative Store Buffering**: Preventing speculative stores from touching the L1 Data Cache until non-speculative commitment at the head of the ROB.
2. **Out-of-Order Load Execution**: Allowing independent loads to execute ahead of older instructions without stalling.
3. **Store-to-Load Forwarding (STLF)**: Transparently forwarding uncommitted store data from the Store Queue directly to dependent loads in 1 clock cycle.
4. **Precise Exception & Misprediction Recovery**: Instantly squashing speculative memory operations on branch mispredicts without corrupting architectural memory.

---

## Block Diagram

```
                             ┌────────────────────────────────────────┐
                             │       Dispatch Stage (In-Order)        │
                             └───────────────────┬────────────────────┘
                                                 │ Allocates entries & records age
                        ┌────────────────────────┴────────────────────────┐
                        ▼                                                 ▼
             ┌─────────────────────┐                           ┌─────────────────────┐
             │   Load Queue (LQ)   │                           │  Store Queue (SQ)   │
             │     (16 Entries)    │                           │    (16 Entries)     │
             └──────────┬──────────┘                           └──────────┬──────────┘
                        │                                                 │
         AGU calculates │                                       AGU / PRF │ Address & Data
         Load Address   │                                       resolves  │ arrive
                        ▼                                                 ▼
             ┌─────────────────────┐                           ┌─────────────────────┐
             │  STLF Match Logic   │◄──────Forward Store Data──┤ Holds speculative   │
             │  (Associative CAM)  │                           │ store data buffer   │
             └──────────┬──────────┘                           └──────────┬──────────┘
                        │                                                 │
             Miss in SQ │ Read from Cache                                 │ ROB Commits Store
                        ▼                                                 ▼
                  [L1 D-Cache] ◄───────────────Commit Drain───────────────┘
```

---

## 1. The Store Queue (`StoreQueue.scala`)

### Storage Fields
Each entry in the 16-entry Store Queue maintains:
| Field | Width | Description |
| :--- | :--- | :--- |
| `valid` | 1 bit | Entry is allocated and currently in-flight. |
| `committed` | 1 bit | ROB has signaled architectural commitment (safe to drain). |
| `addr_valid` | 1 bit | AGU stage has computed the physical address. |
| `data_valid` | 1 bit | Store data operand has arrived from the PRF. |
| `robIdx` | 7 bits | ROB entry index (used for age comparison and commit matching). |
| `snapshotIdx` | 4 bits | Branch checkpoint tag for instantaneous 1-cycle rollback. |
| `paddr` | 64 bits | Physical memory byte address. |
| `wmask` | 16 bits | Byte write strobe mask (supports up to 128-bit unaligned windows). |
| `wdata` | 128 bits | Shifted store payload formatted to match the 128-bit memory window. |

### Lifecycle of a Store:
1. **Allocation (Dispatch)**: The store reserves the tail entry of the SQ in program order.
2. **Address & Data Resolution (Execution Stage)**:
   - When the memory issue queue issues the store, the AGU computes `paddr` and `wmask`.
   - The PRF provides `src2` (store data), which is shifted into `wdata`.
   - The SQ entry sets `addr_valid := true` and `data_valid := true`.
3. **Commit (ROB Head)**:
   - When the store reaches the head of the ROB and all older instructions commit without exceptions, the ROB asserts `io.commits.commitValid` matching the store's `robIdx`.
   - The SQ marks `entry.committed := true`.
4. **Drain to Data Cache**:
   - The head entry of the SQ (`deqPtr`), once marked `committed`, issues a write request to `DataMem` / `dcache_req`.
   - After the cache accepts, the entry is freed and `deqPtr` advances.

---

## 2. Store-to-Load Forwarding (STLF)

When a load executes in the AGU stage:
1. **Associative Query**: The load queries the Store Queue with its `load_paddr`, `load_mask`, and `robIdx`.
2. **Age Filtering**: The query only considers stores that are **strictly older in program order** (`isOlderInRob(store.robIdx, load.robIdx, robHeadPtr)`).
3. **Address & Mask Matching**:
   - Doubleword / line address match: `store.paddr(63, 3) === load.paddr(63, 3)`.
   - Byte mask overlap: `(store.wmask & load.mask) =/= 0`.
4. **Forwarding Path**:
   - If a matching older store with valid data is found, `stlf_hit := true`.
   - The store's 128-bit `wdata` is multiplexed directly into `lsu.io.mem_data`, bypassing the Data Cache completely.
   - The load's formatting logic in `LSU` extracts and sign/zero-extends the requested byte/half/word in **1 clock cycle**.
5. **Cache Fallback**: If no older store matches, the load reads from `dmem` / L1 D-Cache normally.

---

## 3. The Load Queue (`LoadQueue.scala`)

The 16-entry Load Queue tracks in-flight speculative loads:
- **Allocation**: Dispatched loads reserve an entry with their `robIdx` and `snapshotIdx`.
- **Execution**: Records `paddr` once the AGU resolves the address.
- **Retirement**: Deallocated when the ROB commits the load.
- **Flushes**: Uncommitted loads younger than a mispredicted branch are invalidated.

---

## 4. Redirection & Exception Handling

- **Branch Mispredictions (`io.redirect.valid && !io.redirect.is_exception`)**:
  - The SQ and LQ inspect `snapshotIdx` for all uncommitted entries.
  - Any entry younger than `io.redirect.snapshotIdx` is wiped in **1 cycle**.
  - Committed stores awaiting drain are **preserved**, guaranteeing that non-speculative state is never lost.
- **Exceptions (`io.redirect.is_exception`)**:
  - All uncommitted entries in both SQ and LQ are purged immediately.
  - The core state safely rolls back to the architectural commit point.
