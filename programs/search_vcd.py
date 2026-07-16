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
            if 'ftq' in full_path.lower() and ('ptr' in full_path.lower() or 'count' in full_path.lower() or 'enq' in full_path.lower() or 'deq' in full_path.lower() or 'full' in full_path.lower() or 'empty' in full_path.lower()):
                print(full_path)
        elif stripped.startswith('$enddefinitions'):
            break
