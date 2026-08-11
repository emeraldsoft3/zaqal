vcd_path = 'test_run_dir/chisel_test_1784808135898/Core.vcd'

started = False
with open(vcd_path, 'r') as f:
    time = 0
    for line in f:
        line = line.strip()
        if not started:
            if line.startswith('#'):
                started = True
            else:
                continue
        
        if line.startswith('#'):
            time = int(line[1:])
        elif '#' in line:
            if line.startswith('1#'):
                print(f"Time {time}: redirect changed to 1")
            elif line.startswith('0#'):
                print(f"Time {time}: redirect changed to 0")
        elif '7v!' in line:
            if line.startswith('b'):
                parts = line.split()
                if len(parts) == 2 and 'x' not in parts[0] and 'z' not in parts[0]:
                    val = int(parts[0][1:], 2)
                    print(f"Time {time}: rat_14 changed to {val}")
            else:
                # Single bit change (not expected for 8-bit signal but let's handle just in case)
                pass
