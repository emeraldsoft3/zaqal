vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# Signal character mappings
sig_chars = {
    'clock': ']m!',
    'rat_14': '7v!',
    'snptEnq': '\\4',
    'port2_wen': '3l',
    'port2_addr': '$/',
    'port2_data': '=4',
}

# Inverse mapping
char_to_sig = {v: k for k, v in sig_chars.items()}

# State
sig_values = {
    'clock': '0',
    'rat_14': '00000000',
    'snptEnq': '0',
    'port2_wen': '0',
    'port2_addr': '00000',
    'port2_data': '00000000',
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
                    'rat_14': int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else -1,
                    'snptEnq': sig_values['snptEnq'],
                    'port2_wen': sig_values['port2_wen'],
                    'port2_addr': int(sig_values['port2_addr'], 2) if 'x' not in sig_values['port2_addr'] else -1,
                    'port2_data': int(sig_values['port2_data'], 2) if 'x' not in sig_values['port2_data'] else -1,
                })
                
            sig_values[sig] = val

print(f"{'Cycle':<8}{'rat_14':<10}{'snptEnq':<10}{'port2_wen':<12}{'port2_addr':<12}{'port2_data':<10}")
for t in timeline:
    if 50 <= t['cycle'] <= 65:
        print(f"{t['cycle']:<8}{t['rat_14']:<10}{t['snptEnq']:<10}{t['port2_wen']:<12}{t['port2_addr']:<12}{t['port2_data']:<10}")
