vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

scopes = []
matches = {}

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
            if char in ('Rl!', 'Ui!'):
                full_path = '.'.join(scopes) + '.' + parts[4]
                matches[char] = full_path

for char, path in matches.items():
    print(f"Char: {char} -> Path: {path}")
