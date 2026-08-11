vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'
matches = []
try:
    with open(vcd_path, 'r') as f:
        for line in f:
            line_str = line.strip()
            if line_str.startswith('$var'):
                parts = line_str.split()
                name = ' '.join(parts[4:-1]) if parts[-1] == '$end' else ' '.join(parts[4:])
                name_lower = name.lower()
                if 'snapshot' in name_lower and '_5_' in name_lower and '14' in name_lower:
                    matches.append((parts[3], name))
        print(f"Found {len(matches)} matches:")
        for char, name in matches[:100]:
            print(f"Char: {char} -> Name: {name}")
except Exception as e:
    print("Error:", e)
