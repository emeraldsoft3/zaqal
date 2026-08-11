vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

started = False
clock_edges = []
time = 0
last_clock = '0'

with open(vcd_path, 'r') as f:
    for line in f:
        line = line.strip()
        if not started:
            if line.startswith('#'):
                started = True
            else:
                continue
        
        if line.startswith('#'):
            time = int(line[1:])
        elif line == '1]m!': # Clock rise
            clock_edges.append(time)
            
# Print the timestamps for cycles 45 to 70
for i, t in enumerate(clock_edges):
    cycle = i + 1
    if 45 <= cycle <= 70:
        print(f"Cycle {cycle} starts at VCD Time {t}")
