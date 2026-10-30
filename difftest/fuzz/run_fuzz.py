#!/usr/bin/env python3
import argparse
import os
import subprocess
import sys
import re

FUZZ_DIR = "/home/emerald/zaqal/difftest/fuzz"
BUILD_DIR = "/home/emerald/zaqal/build"
EMU_BIN = os.path.join(BUILD_DIR, "emu")
LINK_LD = os.path.join(FUZZ_DIR, "link.ld")
GEN_SCRIPT = os.path.join(FUZZ_DIR, "fuzz_gen.py")

def run_cmd(cmd, cwd=None):
    res = subprocess.run(cmd, shell=True, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return res.returncode, res.stdout, res.stderr

def run_seed(seed, inst_count=50, max_cycles=200):
    s_path = os.path.join(FUZZ_DIR, f"seed_{seed}.s")
    elf_path = os.path.join(FUZZ_DIR, f"seed_{seed}.elf")
    bin_path = os.path.join(FUZZ_DIR, f"seed_{seed}.bin")

    # 1. Generate assembly
    gen_cmd = f"python3 {GEN_SCRIPT} -n {inst_count} -s {seed} -o {s_path}"
    ret, out, err = run_cmd(gen_cmd)
    if ret != 0:
        return False, 0, 0.0, f"Generator error: {err.strip()}"

    # 2. Compile and link
    compile_cmd = f"riscv64-unknown-elf-gcc -T {LINK_LD} -nostdlib -static -march=rv64im -mabi=lp64 {s_path} -o {elf_path}"
    ret, out, err = run_cmd(compile_cmd)
    if ret != 0:
        return False, 0, 0.0, f"GCC error: {err.strip()}"

    objcopy_cmd = f"riscv64-unknown-elf-objcopy -O binary {elf_path} {bin_path}"
    ret, out, err = run_cmd(objcopy_cmd)
    if ret != 0:
        return False, 0, 0.0, f"Objcopy error: {err.strip()}"

    # 3. Run in Difftest emu
    emu_cmd = f"{EMU_BIN} -i {bin_path} -m {max_cycles}"
    ret, out, err = run_cmd(emu_cmd, cwd="/home/emerald/zaqal")
    
    # 4. Check for divergence
    if "[DIFFTEST DIVERGENCE DETECTED]" in out or ret != 0:
        # Extract divergence details
        match = re.search(r"\[DIFFTEST DIVERGENCE DETECTED\].*?(PC:.*?Register:.*?\n)", out, re.DOTALL)
        div_info = match.group(0).replace("\n", " ") if match else "Divergence detected"
        return False, 0, 0.0, div_info

    # Extract commit and IPC info
    commits_match = re.search(r"Total Commits:\s+(\d+)", out)
    ipc_match = re.search(r"Average IPC:\s+([0-9.]+)", out)
    commits = int(commits_match.group(1)) if commits_match else 0
    ipc = float(ipc_match.group(1)) if ipc_match else 0.0

    return True, commits, ipc, "PASS"

def main():
    parser = argparse.ArgumentParser(description="Zaqal Difftest Batch Fuzzing Harness")
    parser.add_argument("--start", type=int, default=1, help="Starting seed")
    parser.add_argument("--count", type=int, default=10, help="Number of seeds to run")
    parser.add_argument("-n", "--inst-count", type=int, default=50, help="Instructions per test")
    parser.add_argument("-m", "--max-cycles", type=int, default=200, help="Max simulation cycles")
    args = parser.parse_args()

    print("=" * 70)
    print("      ZAQAL 6-WIDE OoO CO-SIMULATION CONSTRAINED-RANDOM FUZZER      ")
    print("=" * 70)
    print(f"  Range:       Seeds {args.start} -> {args.start + args.count - 1}")
    print(f"  Insts/Test:  {args.inst_count}")
    print(f"  Golden Ref:  NEMU (riscv64-nemu-interpreter-so)")
    print("=" * 70)
    print(f"{'Seed':<8} | {'Status':<8} | {'Commits':<10} | {'IPC':<8} | {'Notes'}")
    print("-" * 70)

    passed = 0
    failed = 0

    for s in range(args.start, args.start + args.count):
        success, commits, ipc, note = run_seed(s, args.inst_count, args.max_cycles)
        status_str = "\033[92mPASS\033[0m" if success else "\033[91mFAIL\033[0m"
        plain_status = "PASS" if success else "FAIL"
        print(f"{s:<8} | {plain_status:<8} | {commits:<10} | {ipc:<8.3f} | {note}")
        if success:
            passed += 1
        else:
            failed += 1

    print("=" * 70)
    print(f"Fuzzing Summary: {passed}/{args.count} PASSED ({failed} FAILED)")
    print("=" * 70)

    if failed > 0:
        sys.exit(1)

if __name__ == "__main__":
    main()
