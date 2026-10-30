#!/usr/bin/env python3
"""
Zaqal Constrained Random Instruction Fuzzer Generator
Generates valid, constrained-random RISC-V assembly sequences designed
to stress 6-wide superscalar out-of-order execution pipelines.
"""

import random
import argparse
import sys

# ALU instructions: R-type, I-type, 32-bit W-types
ALU_R = ["add", "sub", "sll", "srl", "sra", "or", "and", "xor", "slt", "sltu"]
ALU_W = ["addw", "subw", "sllw", "srlw", "sraw"]
ALU_I = ["addi", "slli", "srli", "srai", "ori", "andi", "xori", "slti", "sltiu"]
ALU_IW = ["addiw", "slliw", "srliw", "sraiw"]

BRANCHES = ["beq", "bne", "blt", "bge", "bltu", "bgeu"]

# Memory instructions (using safe base s0 = _scratchpad_start)
LOADS = ["ld", "lw", "lh", "lb", "lwu", "lhu", "lbu"]
STORES = ["sd", "sw", "sh", "sb"]

# Available General Purpose Registers (excluding x0=zero, x2=sp, x8=s0 scratchpad base)
FREE_REGS = [f"x{i}" for i in range(1, 32) if i not in (0, 2, 8)]

def gen_fuzz_assembly(num_instructions, seed=None):
    if seed is not None:
        random.seed(seed)

    lines = []
    lines.append(".section .text.init")
    lines.append(".globl _start")
    lines.append("_start:")
    lines.append("    # 1. Setup Stack Pointer")
    lines.append("    la sp, _stack_top")
    lines.append("    # 2. Setup Data Scratchpad Base (la produces clean 64-bit address)")
    lines.append("    la s0, _scratchpad_start")
    lines.append("    # 3. Initialize all free registers to known non-zero values")
    for r in FREE_REGS:
        val = random.randint(1, 1000)
        lines.append(f"    li {r}, {val}")

    lines.append("\n    # 4. Randomized Instruction Stream (Seed: {})".format(seed))

    branch_id = 0
    i = 0
    while i < num_instructions:
        dice = random.random()

        if dice < 0.60:
            # 60% ALU operation
            op_cat = random.choice(["R", "W", "I", "IW"])
            rd = random.choice(FREE_REGS)
            rs1 = random.choice(FREE_REGS)
            if op_cat == "R":
                op = random.choice(ALU_R)
                rs2 = random.choice(FREE_REGS)
                lines.append(f"    {op:<7} {rd}, {rs1}, {rs2}")
            elif op_cat == "W":
                op = random.choice(ALU_W)
                rs2 = random.choice(FREE_REGS)
                lines.append(f"    {op:<7} {rd}, {rs1}, {rs2}")
            elif op_cat == "I":
                op = random.choice(ALU_I)
                if op in ("slli", "srli", "srai"):
                    imm = random.randint(0, 63)
                else:
                    imm = random.randint(-128, 127)
                lines.append(f"    {op:<7} {rd}, {rs1}, {imm}")
            else: # IW
                op = random.choice(ALU_IW)
                if op in ("slliw", "srliw", "sraiw"):
                    imm = random.randint(0, 31)
                else:
                    imm = random.randint(-128, 127)
                lines.append(f"    {op:<7} {rd}, {rs1}, {imm}")
            i += 1

        elif dice < 0.80:
            # 20% Memory operation (constrained to s0 offset 0..248, aligned to 8)
            offset = random.randint(0, 31) * 8
            if random.random() < 0.5:
                # Store
                op = random.choice(STORES)
                rs2 = random.choice(FREE_REGS)
                lines.append(f"    {op:<7} {rs2}, {offset}(s0)")
            else:
                # Load
                op = random.choice(LOADS)
                rd = random.choice(FREE_REGS)
                lines.append(f"    {op:<7} {rd}, {offset}(s0)")
            i += 1

        else:
            # 20% Short Forward Branch (skips 1 to 3 instructions)
            op = random.choice(BRANCHES)
            rs1 = random.choice(FREE_REGS)
            rs2 = random.choice(FREE_REGS)
            lbl = f"fuzz_br_{branch_id}"
            branch_id += 1
            lines.append(f"    {op:<7} {rs1}, {rs2}, {lbl}")
            
            # Emit 1-2 instructions inside branch shadow
            shadow_count = random.randint(1, 2)
            for _ in range(shadow_count):
                rd = random.choice(FREE_REGS)
                src = random.choice(FREE_REGS)
                lines.append(f"    addi    {rd}, {src}, {random.randint(1, 50)}")
                i += 1
            lines.append(f"{lbl}:")

    # Halt gracefully in an infinite loop
    lines.append("\n    # 5. End of Random Sequence -> Infinite Loop")
    lines.append("fuzz_done:")
    lines.append("    j fuzz_done\n")
    return "\n".join(lines)

def main():
    parser = argparse.ArgumentParser(description="Zaqal Random Instruction Generator")
    parser.add_argument("-n", "--count", type=int, default=50, help="Number of instructions to generate")
    parser.add_argument("-s", "--seed", type=int, default=1234, help="Random seed")
    parser.add_argument("-o", "--output", type=str, default="/home/emerald/zaqal/difftest/fuzz/test_seed.s", help="Output .s file path")
    args = parser.parse_args()

    code = gen_fuzz_assembly(args.count, args.seed)
    with open(args.output, "w") as f:
        f.write(code)
    print(f"[FuzzGen] Successfully generated {args.count} instructions with seed {args.seed} to {args.output}")

if __name__ == "__main__":
    main()
