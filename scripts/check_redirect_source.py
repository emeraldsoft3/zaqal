vcd_path = '/home/emerald/zaqal/programs/vcd/Lithium.vcd'

# Look for bru or violation signals
sigs = {}
with open(vcd_path) as f:
    for line in f:
        if line.startswith('$var'):
            parts = line.split()
            if len(parts) >= 5:
                name = parts[4]
                sid = parts[3]
                if name in ('r0_valid', 'r1_valid', 'lq_io_violation_valid'):
                    sigs[sid] = name
        elif line.startswith('$enddefinitions'):
            break

print('Signals found:', sigs)
current_time = 0
with open(vcd_path) as f:
    for line in f:
        line = line.strip()
        if not line: continue
        if line[0] == '#':
            current_time = int(line[1:])
        elif line[0] in ('0', '1'):
            sid = line[1:]
            if sid in sigs:
                print(f'Time {current_time} (Cycle {current_time//2}): {sigs[sid]} = {line[0]}')
