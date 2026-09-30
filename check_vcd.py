import os, sys

vcd_path = "/home/emerald/zaqal/programs/vcd/Lithium.vcd"

# Let's find the full hierarchy path for mret and registers
mret_syms = {}
hierarchy = {}

with open(vcd_path, "r") as f:
    scope = []
    for line in f:
        line = line.strip()
        if line.startswith("$scope"):
            parts = line.split()
            if len(parts) >= 3:
                scope.append(parts[2])
        elif line.startswith("$upscope"):
            if scope:
                scope.pop()
        elif line.startswith("$var"):
            parts = line.split()
            if len(parts) >= 5:
                sym = parts[3]
                name = parts[4]
                full_path = ".".join(scope) + "." + name
                if any(k in name.lower() for k in ["mret", "priv_mode", "mcause", "mepc", "trap_in"]):
                    mret_syms[full_path] = sym
        elif line.startswith("$enddefinitions"):
            break

print("Top mret & CSR signals in GTKWave:")
for p in sorted(mret_syms.keys()):
    if any(k in p for k in ["exec.csr", "backend.exec"]):
        print(f"  {p}")
