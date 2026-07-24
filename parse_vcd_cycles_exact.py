vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# Signal character mappings
sig_chars = {
    'clock': ']m!',
    'redirect': '#',
    'RestoreIdx': 'f4',
    'snptEnq': '\\4',
    'EnqIdx': ']4',
    'EnqPtr': 'g4',
    'rat_14': '7v!',
    'snap5_14_int': 'Ui!',   # intRat snapshots_5_14
    'snap5_14_fp':  'Rl!',   # fpRat  snapshots_5_14
}

char_to_sig = {v: k for k, v in sig_chars.items()}

sig_values = {
    'clock': '0',
    'redirect': '0',
    'RestoreIdx': '000',
    'snptEnq': '0',
    'EnqIdx': '000',
    'EnqPtr': '000',
    'rat_14': '00000000',
    'snap5_14_int': 'xxxxxxxx',
    'snap5_14_fp': 'xxxxxxxx',
}

started = False
with open(vcd_path, 'r') as f:
    time = 0
    for line in f:
        line = line.strip()
        if not started:
            if line.startswith('#'):
                started = True
            else:
                continue

        if line.startswith('#'):
            time = int(line[1:])

        if time < 100 or time > 145:
            continue

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
            sig_values[sig] = val
            val_dec = int(val, 2) if ('x' not in val and 'z' not in val) else val
            print(f"Time {time:3d}: {sig:<18} changed to {val_dec}")
