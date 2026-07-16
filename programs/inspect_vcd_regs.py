import os
import re

vcd_path = 'programs/vcd/Lithium.vcd'

scope_stack = []
symbol_to_signals = {}

with open(vcd_path, 'r') as f:
    for line in f:
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith('$scope'):
            parts = stripped.split()
            scope_name = parts[2]
            scope_stack.append(scope_name)
        elif stripped.startswith('$upscope'):
            if scope_stack:
                scope_stack.pop()
        elif stripped.startswith('$var'):
            parts = stripped.split()
            symbol = parts[3]
            name_idx = 4
            while name_idx < len(parts) and parts[name_idx] != '$end':
                name_idx += 1
            name_parts = parts[4:name_idx]
            name = name_parts[0]
            
            full_path = ".".join(scope_stack) + "." + name
            if symbol not in symbol_to_signals:
                symbol_to_signals[symbol] = []
            symbol_to_signals[symbol].append(full_path)
        elif stripped.startswith('$enddefinitions'):
            break

pc_symbol = None
redirect_symbol = None
clock_symbol = None
reg_symbols = {}

for sym, paths in symbol_to_signals.items():
    for path in paths:
        path_lower = path.lower()
        if path.endswith(".clock") or path.endswith("_clock") or path == "TOP.clock":
            clock_symbol = sym
        if "frontend" in path_lower and ("io_pc" in path_lower or "debug_ftq_pc" in path_lower):
            pc_symbol = sym
        if "backend" in path_lower and "io_redirect_valid" in path_lower:
            redirect_symbol = sym
        if "regfile." in path_lower and "fpregfile" not in path_lower and "regs_" in path_lower:
            m = re.search(r'regs_(\d+)', path)
            if m:
                idx = int(m.group(1))
                reg_symbols[idx] = sym

print(f"Clock: {clock_symbol}, PC: {pc_symbol}, Redirect: {redirect_symbol}")
print(f"Found {len(reg_symbols)} integer register symbols")

symbol_values = {}
prev_clock = '0'
events = []

with open(vcd_path, 'r') as f:
    for line in f:
        if line.strip().startswith('$enddefinitions'):
            break

    current_time = 0
    for line in f:
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith('#'):
            current_time = int(stripped[1:])
            continue
            
        if stripped.startswith('b') or stripped.startswith('r'):
            parts = stripped.split()
            if len(parts) == 2:
                val, sym = parts
                symbol_values[sym] = val
        else:
            val = stripped[0]
            sym = stripped[1:]
            symbol_values[sym] = val
            
        # Clock check
        if clock_symbol and sym == clock_symbol:
            current_clock = val
            if prev_clock == '0' and current_clock == '1':
                # Rising edge!
                pc_val = int(symbol_values.get(pc_symbol, 'b0')[1:], 2) if pc_symbol in symbol_values else 0
                redir_val = int(symbol_values.get(redirect_symbol, '0')) if redirect_symbol in symbol_values else 0
                
                regs_vals = {}
                for idx, r_sym in reg_symbols.items():
                    r_val_str = symbol_values.get(r_sym, 'b0')
                    if r_val_str.startswith('b'):
                        regs_vals[idx] = int(r_val_str[1:], 2)
                    else:
                        regs_vals[idx] = int(r_val_str)
                events.append((current_time, pc_val, redir_val, regs_vals))
            prev_clock = current_clock

print(f"Captured {len(events)} cycles. Printing integer register changes:")
last_regs = {}
for cycle_idx, (time, pc, redir, regs) in enumerate(events):
    changed = {}
    for idx, val in regs.items():
        if val != last_regs.get(idx, 0):
            changed[idx] = val
    # Only print changes for active physical registers (p0 to p60)
    changed = {k: v for k, v in changed.items() if k <= 60}
    if changed or redir == 1:
        reg_str = ", ".join([f"p{idx}=0x{val:x}" for idx, val in sorted(changed.items())])
        print(f"Cycle {cycle_idx:3d} (Time {time:5d} ps) | PC: 0x{pc:08x} | Redirect: {redir} | Regs: {reg_str}")
    last_regs = dict(regs)
