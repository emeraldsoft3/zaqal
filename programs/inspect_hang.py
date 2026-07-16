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
interesting_keywords = ["redirect", "ftq_valid", "ftq_ready", "fetch_pc", "bpu.io_pc", "bpu_enq_ptr"]
matched_symbols = {}

for sym, paths in symbol_to_signals.items():
    for path in paths:
        path_lower = path.lower()
        if any(kw in path_lower for kw in interesting_keywords) or path.endswith(".clock"):
            matched_symbols[path] = sym

print(f"Matched {len(matched_symbols)} signals.")

symbol_values = {}
prev_clock = '0'
events = []

# Resolve clock symbol
clock_sym = None
for path, sym in matched_symbols.items():
    if path.endswith(".clock") or path.endswith("_clock") or path == "TOP.clock":
        clock_sym = sym
        break

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
                    raw_val = symbol_values.get(s, '0')
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
# Print details for cycles 55 to 80
for cycle_idx in range(55, min(90, len(events))):
    time, state = events[cycle_idx]
    print(f"\n--- Cycle {cycle_idx} (Time {time} ps) ---")
    for path in sorted(state.keys()):
        if "clock" in path:
            continue
        # Filter for key signals
        path_lower = path.lower()
        if any(x in path_lower for x in ["redirect", "ftq_valid", "bpu.io_pc"]):
            print(f"  {path:60s} : {state[path]}")
