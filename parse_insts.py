with open('sim_output3.txt', 'r') as f:
    for line in f:
        if '80000024' in line or '8000003c' in line:
            if 'RENAME' in line or 'BRU' in line or 'IQ ISSUE' in line or 'FTB UPDATE' in line:
                print(line.strip())
