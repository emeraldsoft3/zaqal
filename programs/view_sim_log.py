import os

log_path = 'sim_run_new.log'
output = []
recording = False
cycle_count = 0

try:
    with open(log_path, 'r', encoding='utf-16') as f:
        lines = f.readlines()
except Exception:
    with open(log_path, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

for line in lines:
    if '[TESTBENCH] Cycle' in line:
        parts = line.split()
        try:
            cycle_count = int(parts[2])
            if 50 <= cycle_count <= 80:
                recording = True
            else:
                recording = False
        except ValueError:
            pass
    if recording:
        output.append(line)

print("".join(output))
