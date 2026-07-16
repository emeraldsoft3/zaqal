with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

start_idx = 0
for idx, line in enumerate(lines):
    if 'Final Physical Register State' in line:
        start_idx = idx
        break

print(f"Found block start at line {start_idx}")
for idx in range(max(0, start_idx - 100), start_idx + 10):
    print(f"Line {idx:3d}: {lines[idx].strip()}")
