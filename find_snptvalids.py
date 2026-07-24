vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# First find the snptValids symbols for Backend
matches = {}
scopes = []

with open(vcd_path, 'r') as f:
    for line in f:
        line_str = line.strip()
        if line_str.startswith('$scope'):
            parts = line_str.split()
            scopes.append(parts[2])
        elif line_str.startswith('$upscope'):
            if scopes:
                scopes.pop()
        elif line_str.startswith('$var'):
            parts = line_str.split()
            char = parts[3]
            name = ' '.join(parts[4:-1]) if parts[-1] == '$end' else ' '.join(parts[4:])
            scope_path = '.'.join(scopes)
            if 'backend' in scope_path and ('snptvalids' in name.lower() or 'valids' in name.lower()) and 'rat' in scope_path:
                matches[char] = (scope_path, name)

print("Snapshot Valid signals in rat scope:")
for char, (scope, name) in matches.items():
    print(f"  Char: {char} -> {scope}.{name}")
