with open('sim_run_new.log', 'r', encoding='utf-8', errors='replace') as f:
    lines = f.readlines()

matches = 0
for idx, line in enumerate(lines):
    if '51' in line or '50' in line:
        if 'pc=00000000800000' in line or 'REGFILE WRITE' in line or 'IQ Entry' in line or 'RENAME' in line or 'REDIRECT' in line:
            print(f"Line {idx:3d}: {line.strip()}")
            matches += 1
            if matches > 50:
                break
