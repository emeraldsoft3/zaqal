with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

print(f"Total lines in file: {len(lines)}")
for idx, line in enumerate(lines):
    if 'FLUSH' in line or 'ACCEPTED' in line:
        print(f"Line {idx}: {line.strip()}")
