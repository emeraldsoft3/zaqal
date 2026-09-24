import re

vcd_path = 'programs/vcd/Lithium.vcd'

scope_stack = []
symbol_to_signals = {}

with open(vcd_path, 'r') as f:
    for line in f:
        stripped = line.strip()
        if not stripped: continue
        if stripped.startswith('$scope'):
            scope_stack.append(stripped.split()[2])
        elif stripped.startswith('$upscope'):
            if scope_stack: scope_stack.pop()
        elif stripped.startswith('$var'):
            parts = stripped.split()
            sym = parts[3]
            name = parts[4]
            full_path = ".".join(scope_stack) + "." + name
            if sym not in symbol_to_signals: symbol_to_signals[sym] = []
            symbol_to_signals[sym].append(full_path)
        elif stripped.startswith('$enddefinitions'):
            break

clock_sym = None
pc_sym = None
redir_sym = None
target_sym = None
rat_x1_sym = None
rat_x6_sym = None
rat_x2_sym = None
rat_x8_sym = None
reg_syms = {}

for sym, paths in symbol_to_signals.items():
    for p in paths:
        pl = p.lower()
        if pl.endswith('.clock') or pl == 'top.clock':
            clock_sym = sym
        if 'frontend' in pl and 'debug_ftq_pc' in pl:
            pc_sym = sym
        if 'backend' in pl and 'io_redirect_valid' in pl:
            redir_sym = sym
        if 'backend' in pl and 'io_redirect_target' in pl:
            target_sym = sym
        if 'regfile.' in pl and 'fpregfile' not in pl and 'regs_' in pl:
            m = re.search(r'regs_(\d+)', p)
            if m:
                reg_syms[int(m.group(1))] = sym
        if 'rat' in pl and 'debug_rat_1' in pl:
            rat_x1_sym = sym
        if 'rat' in pl and 'debug_rat_6' in pl:
            rat_x6_sym = sym
        if 'rat' in pl and 'debug_rat_2' in pl:
            rat_x2_sym = sym
        if 'rat' in pl and 'debug_rat_8' in pl:
            rat_x8_sym = sym

print(f"Tracking RAT x1={rat_x1_sym}, x2={rat_x2_sym}, x6={rat_x6_sym}, x8={rat_x8_sym}")

# Parse simulation time steps
curr_vals = {}
prev_clock = '0'
cycle = 0

with open(vcd_path, 'r') as f:
    for line in f:
        if line.strip().startswith('$enddefinitions'): break

    for line in f:
        line = line.strip()
        if not line: continue
        if line.startswith('#'): continue
        if line.startswith('b') or line.startswith('r'):
            parts = line.split()
            if len(parts) == 2:
                curr_vals[parts[1]] = parts[0]
        else:
            curr_vals[line[1:]] = line[0]

        if clock_sym and clock_sym in curr_vals:
            c = curr_vals[clock_sym]
            if prev_clock == '0' and c == '1':
                cycle += 1
                redir = curr_vals.get(redir_sym, '0')
                if redir == '1':
                    pc_raw = curr_vals.get(pc_sym, 'b0')
                    pc = int(pc_raw[1:], 2) if pc_raw.startswith('b') else 0
                    tgt = int(curr_vals.get(target_sym, 'b0')[1:], 2) if curr_vals.get(target_sym, '').startswith('b') else 0
                    print(f"Cycle {cycle:4d}: REDIRECT! PC=0x{pc:08x}, Target=0x{tgt:08x}")
            prev_clock = c

# Inspect final architectural registers from RAT mappings
print("\n--- Final Architectural Register State ---")
def get_val(sym):
    v = curr_vals.get(sym, 'b0')
    return int(v[1:], 2) if v.startswith('b') else int(v) if v.isdigit() else 0

p_x1 = get_val(rat_x1_sym) if rat_x1_sym else 1
p_x2 = get_val(rat_x2_sym) if rat_x2_sym else 2
p_x6 = get_val(rat_x6_sym) if rat_x6_sym else 6
p_x8 = get_val(rat_x8_sym) if rat_x8_sym else 8

val_x1 = get_val(reg_syms[p_x1]) if p_x1 in reg_syms else 0
val_x2 = get_val(reg_syms[p_x2]) if p_x2 in reg_syms else 0
val_x6 = get_val(reg_syms[p_x6]) if p_x6 in reg_syms else 0
val_x8 = get_val(reg_syms[p_x8]) if p_x8 in reg_syms else 0

print(f"x1 (p{p_x1}): 0x{val_x1:016x} (dec: {val_x1})")
print(f"x2 (p{p_x2}): 0x{val_x2:016x} (dec: {val_x2})")
print(f"x6 (p{p_x6}): 0x{val_x6:016x} (dec: {val_x6})")
print(f"x8 (p{p_x8}): 0x{val_x8:016x} (dec: {val_x8})")
