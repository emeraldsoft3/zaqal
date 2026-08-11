import re
with open('sim_output3.txt', 'r') as f:
    current_cycle = 0
    for line in f:
        m = re.search(r'\[TESTBENCH\]\s+Cycle\s+(\d+)', line)
        if m:
            current_cycle = int(m.group(1))
        if '8000001c' in line:
            print(f"C{current_cycle:3d}: {line.strip()}")
