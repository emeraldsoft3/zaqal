with open('sim_run_new.log', 'r', errors='replace') as f:
    for i in range(40):
        line = f.readline()
        if not line:
            break
        print(f"{i}: {line}", end='')
