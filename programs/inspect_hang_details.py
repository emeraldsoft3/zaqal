with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

for idx in range(160, min(250, len(lines))):
    print(f"Line {idx:3d}: {lines[idx].strip()}")
