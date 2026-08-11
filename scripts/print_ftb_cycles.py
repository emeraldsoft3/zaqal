import re
current_cycle = 0
with open('sim_output4.txt', 'r') as f:
    for line in f:
        m = re.search(r'\[TESTBENCH\]\s+Cycle\s+(\d+)', line)
        if m:
            current_cycle = int(m.group(1))
        if '[FTB UPDATE]' in line:
            print(f"Cycle {current_cycle:3d}: {line.strip()}")
