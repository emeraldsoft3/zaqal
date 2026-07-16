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

for sym, paths in symbol_to_signals.items():
    for path in paths:
        path_lower = path.lower()
        if path.endswith(".clock") or path.endswith("_clock") or path == "TOP.clock":
            clock_symbol = sym
        if "frontend" in path_lower and ("io_pc" in path_lower or "debug_ftq_pc" in path_lower):
            pc_symbol = sym
        if "backend" in path_lower and "io_redirect_valid" in path_lower:
            redirect_symbol = sym

print(f"Clock: {clock_symbol}, PC: {pc_symbol}, Redirect: {redirect_symbol}")

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
                pc_val = int(symbol_values.get(pc_symbol, 'b0')[1:], 2) if pc_symbol in symbol_values else 0
                redir_val = int(symbol_values.get(redirect_symbol, '0')) if redirect_symbol in symbol_values else 0
                events.append((current_time, pc_val, redir_val))
            prev_clock = current_clock

print(f"Captured {len(events)} cycles. Printing PC trace (first 120 cycles):")
for cycle_idx in range(min(120, len(events))):
    time, pc, redir = events[cycle_idx]
    print(f"Cycle {cycle_idx:3d} (Time {time:5d} ps) | PC: 0x{pc:08x} | Redirect: {redir}")
