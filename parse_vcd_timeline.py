vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# Signal character mappings
sig_chars = {
    'clock': ']m!',
    'redirect': '#',
    'snptEnq': '\\4',
    'snptEnqIdx': ']4',
    'snptRestoreIdx': 'f4',
    'snptEnqPtr': 'g4',
    'rat_14': '7v!',
}

# Inverse mapping
char_to_sig = {v: k for k, v in sig_chars.items()}

# State
sig_values = {
    'clock': '0',
    'redirect': '0',
    'snptEnq': '0',
    'snptEnqIdx': '000',
    'snptRestoreIdx': '000',
    'snptEnqPtr': '000',
    'rat_14': '00000000',
}

cycle_count = 0
timeline = []

with open(vcd_path, 'r') as f:
    for line in f:
        line = line.strip()
        if not line:
            continue
        
        # Check for time steps
        if line.startswith('#'):
            # Time step, but we only print/save state when clock rises
            continue
        
        # Parse value change
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
                # Save snapshot of current values
                timeline.append({
                    'cycle': cycle_count,
                    'redirect': sig_values['redirect'],
                    'snptEnq': sig_values['snptEnq'],
                    'snptEnqIdx': int(sig_values['snptEnqIdx'], 2) if 'x' not in sig_values['snptEnqIdx'] else -1,
                    'snptRestoreIdx': int(sig_values['snptRestoreIdx'], 2) if 'x' not in sig_values['snptRestoreIdx'] else -1,
                    'snptEnqPtr': int(sig_values['snptEnqPtr'], 2) if 'x' not in sig_values['snptEnqPtr'] else -1,
                    'rat_14': int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else -1,
                })
                
            sig_values[sig] = val

# Print the timeline around cycle 51 (testbench cycle 56/57) and cycle 61
print(f"Total clock cycles: {cycle_count}")
print("Timeline around cycle 51-65:")
print(f"{'Cycle':<8}{'Redirect':<10}{'snptEnq':<10}{'EnqIdx':<10}{'RestoreIdx':<12}{'EnqPtr':<10}{'rat_14 (physical register)':<30}")
for t in timeline:
    # Adjust cycle filter if needed, in VCD cycles might be different
    # Testbench Cycle 56 in log could correspond to cycle 56 in VCD
    if 45 <= t['cycle'] <= 85:
        print(f"{t['cycle']:<8}{t['redirect']:<10}{t['snptEnq']:<10}{t['snptEnqIdx']:<10}{t['snptRestoreIdx']:<12}{t['snptEnqPtr']:<10}{t['rat_14']:<30}")
