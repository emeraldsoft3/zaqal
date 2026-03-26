# Branch Verification Methodology

To ensure control-flow integrity, Zaqal is tested against a comprehensive matrix of branch scenarios.

## Verification Matrix (The "Dirty Dozen")

| No | Type | Dir | Outcome | BPU Pred | Block Type | Status | Note |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | BEQ | Fwd | Not Taken | Hit (NP) | Intra | [x] Verified | No prediction = NT |
| **2** | BEQ | Fwd | Taken | Hit (T) | Intra | [x] Verified | Pred Taken = Hit |
| **3** | BEQ | Fwd | Taken | Miss (NP) | Intra | [ ] Pending | No pred, but Taken |
| **4** | BEQ | Fwd | Not Taken | Miss (T) | Intra | [x] Verified | Pred Taken, but NT |
| **5** | BEQ | Bwd | Not Taken | Hit (NP) | Intra | [x] Verified | No prediction = NT |
| **6** | BEQ | Bwd | Taken | Hit (T) | Intra | [x] Verified | **Loop Hit (True Intra)** |
| **7** | BEQ | Bwd | Taken | Miss (NP) | Intra | [x] Verified | No prediction, but Taken |
| **8** | BEQ | Bwd | Not Taken | Miss (T) | Intra | [x] Verified | Pred Taken, but NT |
| **9** | BEQ | Fwd | Not Taken | Hit (NP) | Inter | [ ] Pending | |
| **10** | BEQ | Fwd | Taken | Hit (T) | Inter | [ ] Pending | |
| **11** | BEQ | Fwd | Taken | Miss (NP) | Inter | [ ] Pending | |
| **12** | BEQ | Fwd | Not Taken | Miss (T) | Inter | [ ] Pending | |

> [!NOTE]
> **Inter-block**: Branch target is in a different fetch packet (32B aligned).
> **Intra-block**: Branch target is in the same fetch packet.
