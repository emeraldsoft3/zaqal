# Zaqal Implementation Decision Matrix (SOTA Architectures)

High-end processors agree on the fundamentals of Out-of-Order (OoO) superscalar execution, but differ radically in specific implementation philosophies.

This master index tracks the major forks in the road for Zaqal.

## 1. [Branch Recovery & Checkpointing](./01_branch_recovery_checkpointing.md)
*How the CPU recovers the map table after a mispredicted branch.*

## 2. [Issue Queue Structure](./02_issue_queue_structure.md)
*How instructions wait for execution (Unified pool vs. Distributed queues).*

## 3. [Physical Register File (PRF) Architecture](./03_physical_register_file.md)
*Where in-flight temporary data values actually live in the hardware.*

## 4. [Memory Consistency & Ordering](./04_memory_consistency.md)
*How the hardware enforces or relaxes the sequence of load/store operations.*

## 5. [Branch Prediction Hierarchy & BTB](./05_branch_prediction_hierarchy.md)
*How the Branch Target Buffer (BTB) stores target addresses for indirect branches.*

## 6. [Frontend Width and Pipeline Depth](./06_frontend_width_and_depth.md)
*Trading off instruction throughput (width) against clock frequency and flush penalties (depth).*

## 7. [Store-to-Load Forwarding (STLF)](./07_store_to_load_forwarding.md)
*How loads rapidly bypass the L1 cache to grab data directly from in-flight stores.*

## 8. [Decoded Instruction Cache (uOp Cache)](./08_uop_cache_vs_decoded_icache.md)
*Using an L0 cache to eliminate massive decoding power bottlenecks in wide frontends.*

## 9. [Inclusive vs. Exclusive L2 Caching](./09_inclusive_vs_exclusive_l2.md)
*How redundant data is handled between the fast L1 and massive L2/L3 architectures.*

## 10. [Memory Dependency Prediction](./10_memory_dependency_prediction.md)
*How the hardware guesses if a fast-executing Load is going to illegally bypass an unknown slower Store.*

## 11. [Decoupled Frontends (Fetch/Decode Width)](./11_decoupled_frontends.md)
*How wide fetches queue up massive instruction buffers to hide cache stall latency from Decoders.*

## 12. [ALU Pipeline Depth (Single vs. Multi-Cycle)](./12_alu_pipeline_depth.md)
*Slicing simple 64-bit integer adders in half to hit 6 GHz at the expense of crippling IPC.*

## 13. [Simultaneous Multithreading (SMT/HyperThreading)](./13_simultaneous_multithreading.md)
*Competitively sharing 200 ROB entries vs. strictly cutting them in half to prevent thread starvation.*

## 14. [Vector/SIMD Hardware Paths](./14_vector_simd_hardware.md)
*Hijacking 64-bit integer ALUs to run Vector math vs. building profoundly isolated FPU pipelines.*

## 15. [FPU Divider & Square Root Algorithm](./15_fpu_divider_algorithm.md)
*Balancing area against latency via iterative Radix shifts vs. Multiplicative FMA routines.*
