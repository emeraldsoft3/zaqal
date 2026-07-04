vcd_path = 'programs/vcd/Lithium.vcd'
try:
    with open(vcd_path, 'r') as f:
        print("Searching for debug_rat elements...")
        matches = []
        for line in f:
            line_str = line.strip()
            if line_str.startswith('$var'):
                parts = line_str.split()
                name = ' '.join(parts[4:-1]) if parts[-1] == '$end' else ' '.join(parts[4:])
                if 'debug_rat' in name.lower():
                    char = parts[3]
                    matches.append((char, name))
        
        print(f"Found {len(matches)} matching signals:")
        for char, name in matches:
            print(f"Char: {char} -> Name: {name}")
except Exception as e:
    print("Error:", e)
