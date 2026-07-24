with open('sim_output3.txt', 'r') as f:
    for line in f:
        if any(k in line for k in ['[FTB UPDATE]', '[BRU REDIRECT]', 'TESTBENCH']):
            print(line.strip())
