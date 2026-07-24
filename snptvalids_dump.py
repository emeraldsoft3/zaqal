vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

# Signal character mappings for intRat snptValids[0:7]
sig_chars = {
    'clock':   ']m!',
    'redirect': '#',
    'RestoreIdx': 'f4',
    'rat_14':  '7v!',
    'valid_0': 'i4',
    'valid_1': 'j4',
    'valid_2': 'k4',
    'valid_3': 'l4',
    'valid_4': 'm4',
    'valid_5': 'n4',
    'valid_6': 'o4',
    'valid_7': 'p4',
}

char_to_sig = {v: k for k, v in sig_chars.items()}

sig_values = {k: '0' for k in sig_chars}
sig_values['rat_14'] = '00000000'
sig_values['RestoreIdx'] = '000'

started = False
with open(vcd_path, 'r') as f:
    time = 0
    cycle = 0
    last_clock = '0'
    for line in f:
        line = line.strip()
        if not started:
            if line.startswith('#'):
                started = True
            else:
                continue

        if line.startswith('#'):
            time = int(line[1:])

        if time < 115 or time > 135:
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

            valids = ''.join([sig_values[f'valid_{i}'] for i in range(8)])
            rat14 = int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else 'x'
            restoreIdx = int(sig_values['RestoreIdx'], 2) if 'x' not in sig_values['RestoreIdx'] else 'x'

            print(f"Time {time:3d} | {sig:<14} = {val:<8} | valids={valids} | RestoreIdx={restoreIdx} | rat_14={rat14} | redirect={sig_values['redirect']}")
