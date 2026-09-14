vcd_path = '/home/emerald/zaqal/programs/vcd/Lithium.vcd'
target_sids = {'0?': 'valid', '/?': 'ready', '/M': 'pc'}

current_time = 0
values = {'valid': 0, 'ready': 0, 'pc': 0}
with open(vcd_path) as f:
    for line in f:
        line = line.strip()
        if not line: continue
        if line[0] == '#':
            t = int(line[1:])
            if t != current_time and (t % 2 == 1):
                if values['valid'] == 1 and values['ready'] == 1:
                    print(f"Time {current_time} (Cycle {current_time//2}): fpIq FIRED PC=0x{values['pc']:08x}")
            current_time = t
        elif line[0] in ('0', '1'):
            sid = line[1:]
            if sid in target_sids:
                values[target_sids[sid]] = int(line[0])
        elif line[0] == 'b':
            parts = line.split()
            if len(parts) == 2 and parts[1] == '/M':
                values['pc'] = int(parts[0][1:], 2)
