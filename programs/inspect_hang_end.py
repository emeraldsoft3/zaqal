with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

for idx in range(600, min(655, len(lines))):
    print(f"Line {idx:3d}: {lines[idx].strip()}")
