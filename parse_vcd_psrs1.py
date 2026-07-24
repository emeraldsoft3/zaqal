vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# Signal character mappings
sig_chars = {
    'clock': ']m!',
    'redirect': '#',
    'RestoreIdx': 'f4',
    'uop_pc': '0',
    'psrs1': 'D4',
    'rat_14': '7v!',
}

# Inverse mapping
char_to_sig = {v: k for k, v in sig_chars.items()}

# State
sig_values = {
    'clock': '0',
    'redirect': '0',
    'RestoreIdx': '000',
    'uop_pc': '0000000000000000',
    'psrs1': '00000000',
    'rat_14': '00000000',
}

cycle_count = 0
timeline = []

with open(vcd_path, 'r') as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        
        # Check for value changes
        val = None
        char = None
        if line.startswith('b'):
            parts = line.split()
            if len(parts) == 2:
                val, char = parts[0][1:], parts[1]
        elif line[0] in ('0', '1', 'x', 'z'):
            val, char = line[0], line[1:]
            
        if char in char_to_sig:
            sig = char_to_sig[char]
            
            # If clock changes to 1, record the state
            if sig == 'clock' and val == '1' and sig_values['clock'] == '0':
                cycle_count += 1
                timeline.append({
                    'cycle': cycle_count,
                    'redirect': sig_values['redirect'],
                    'RestoreIdx': int(sig_values['RestoreIdx'], 2) if 'x' not in sig_values['RestoreIdx'] else -1,
                    'uop_pc': int(sig_values['uop_pc'], 2) if 'x' not in sig_values['uop_pc'] else -1,
                    'psrs1': int(sig_values['psrs1'], 2) if 'x' not in sig_values['psrs1'] else -1,
                    'rat_14': int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else -1,
                })
                
            sig_values[sig] = val

print(f"{'Cycle':<8}{'Redirect':<10}{'RestoreIdx':<12}{'uop_pc (hex)':<15}{'psrs1 (prs1)':<15}{'rat_14':<10}")
for t in timeline:
    if 50 <= t['cycle'] <= 80:
        pc_hex = f"{t['uop_pc']:x}" if t['uop_pc'] != -1 else 'x'
        print(f"{t['cycle']:<8}{t['redirect']:<10}{t['RestoreIdx']:<12}{pc_hex:<15}{t['psrs1']:<15}{t['rat_14']:<10}")
