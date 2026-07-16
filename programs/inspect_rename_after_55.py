with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

for idx, line in enumerate(lines):
    if 'CORE RENAME' in line:
        parts = line.split('Cycle')
        if len(parts) > 1:
            try:
                cycle_num = int(parts[1].split(']')[0].strip())
                if cycle_num >= 55:
                    print(f"Line {idx:3d}: {line.strip()}")
            except ValueError:
                pass
