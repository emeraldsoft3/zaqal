import os

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

# Print matching paths
interesting_signals = [
    "TOP.Core.frontend.ftq.enqPtr",
    "TOP.Core.frontend.ftq.deqPtr",
    "TOP.Core.frontend.ftq.count",
    "TOP.Core.frontend.ftq.full",
    "TOP.Core.frontend.ftq.empty",
    "TOP.Core.frontend.io_redirect_valid",
    "TOP.Core.frontend.io_redirect_target",
    "TOP.Core.backend.io_redirect_valid",
    "TOP.Core.backend.io_redirect_target",
    "TOP.Core.debug_ftq_valid",
    "TOP.Core.debug_ftq_valid_out",
    "TOP.clock"
]
matched_symbols = {}

for sym, paths in symbol_to_signals.items():
    for path in paths:
        if path in interesting_signals:
            matched_symbols[path] = sym

symbol_values = {}
prev_clock = '0'
events = []

# Resolve clock symbol
clock_sym = matched_symbols.get("TOP.clock")

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
            
        if clock_sym and sym == clock_sym:
            current_clock = val
            if prev_clock == '0' and current_clock == '1':
                # Capture current state of matched signals
                state = {}
                for path, s in matched_symbols.items():
                    raw_val = symbol_values.get(s, 'b0')
                    if raw_val.startswith('b'):
                        try:
                            state[path] = int(raw_val[1:], 2)
                        except ValueError:
                            state[path] = -1
                    else:
                        try:
                            state[path] = int(raw_val)
                        except ValueError:
                            state[path] = -1
                events.append((current_time, state))
            prev_clock = current_clock

print(f"Captured {len(events)} cycles.")
# Print details for cycles 60 to 75
for cycle_idx in range(60, min(75, len(events))):
    time, state = events[cycle_idx]
    print(f"\n--- Cycle {cycle_idx} (Time {time} ps) ---")
    for path in sorted(state.keys()):
        if "clock" in path:
            continue
        print(f"  {path:40s} : 0x{state[path]:08x}")
