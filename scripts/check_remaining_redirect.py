vcd_path = 'test_run_dir/chisel_test_1784876109633/Core.vcd'

sig_chars = {
    'clock':      ']m!',
    'redirect':   '#',
    'RestoreIdx': 'f4',
    'rat_14':     '7v!',
    'EnqPtr':     'g4',
}

char_to_sig = {v: k for k, v in sig_chars.items()}
sig_values = {'clock':'0','redirect':'0','RestoreIdx':'000','rat_14':'00000000','EnqPtr':'000'}

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

        if time < 420 or time > 450:
            continue

        val = None
        char = None
        if line.startswith('b'):
            parts = line.split()
            if len(parts) == 2:
                val, char = parts[0][1:], parts[1]
        elif line and line[0] in ('0','1','x','z'):
            val, char = line[0], line[1:]

        if char in char_to_sig:
            sig = char_to_sig[char]
            sig_values[sig] = val
            rat14 = int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else 'x'
            restore = int(sig_values['RestoreIdx'], 2) if 'x' not in sig_values['RestoreIdx'] else 'x'
            enqPtr = int(sig_values['EnqPtr'], 2) if 'x' not in sig_values['EnqPtr'] else 'x'
            print(f"Time {time:4d}: {sig:<14} = {sig_values[sig]:<8} | rat_14={rat14:3} restoreIdx={restore} EnqPtr={enqPtr} redirect={sig_values['redirect']}")
