import re

with open('sim_output3.txt', 'r') as f:
    current_cycle = 0
    for line in f:
        m = re.search(r'\[TESTBENCH\]\s+Cycle\s+(\d+)', line)
        if m:
            current_cycle = int(m.group(1))
        if 103 <= current_cycle <= 145:
            if any(k in line for k in ['RENAME', 'IQ ISSUE', 'BRU REDIRECT', 'FTB UPDATE', 'FLUSH', 'snptEnq', 'snptValids', 'restore_idx']):
                print(f"C{current_cycle:3d}: {line.strip()}")
