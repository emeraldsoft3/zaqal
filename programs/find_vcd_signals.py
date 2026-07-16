with open('programs/vcd/Lithium.vcd', 'r') as f:
    scope_stack = []
    for line in f:
        stripped = line.strip()
        if stripped.startswith('$scope'):
            parts = stripped.split()
            scope_stack.append(parts[2])
        elif stripped.startswith('$upscope'):
            if scope_stack:
                scope_stack.pop()
        elif stripped.startswith('$var'):
            if 'tags_mport_en' in stripped.lower():
                print(f"Path: {'.'.join(scope_stack)} -> {stripped}")
