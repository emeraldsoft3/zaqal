vcd_path = 'test_run_dir/chisel_test_1784876492591/Core.vcd'

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
redirects = []
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

            if sig == 'redirect' and val == '1':
                restore = int(sig_values['RestoreIdx'], 2) if 'x' not in sig_values['RestoreIdx'] else -1
                rat14 = int(sig_values['rat_14'], 2) if 'x' not in sig_values['rat_14'] else -1
                enqPtr = int(sig_values['EnqPtr'], 2) if 'x' not in sig_values['EnqPtr'] else -1
                redirects.append((time, restore, rat14, enqPtr))

print(f"All redirects (time, restoreIdx, rat_14_at_time, enqPtr):")
for t, r, v, e in redirects:
    print(f"  Time {t:4d}: restoreIdx={r:2d}  enqPtr={e}  rat_14={v}")

print(f"\nTotal redirects: {len(redirects)}")

print("\nBack-to-back redirect pairs (<= 4 time units apart):")
found = False
for i in range(1, len(redirects)):
    gap = redirects[i][0] - redirects[i-1][0]
    if gap <= 4:
        print(f"  *** Times {redirects[i-1][0]} and {redirects[i][0]} (gap={gap}) — restoreIdx {redirects[i-1][1]} then {redirects[i][1]} | rat_14: {redirects[i-1][2]} then {redirects[i][2]}")
        found = True
if not found:
    print("  None! Fix confirmed ✓")
