import sys

def extract_signals(vcd_path):
    target_signals = [
        "s0_pc",
        "io_redirect_target",
        "io_redirect_valid",
        "rob_io_bpu_redirect_valid",
        "io_bpu_redirect_valid",
        "io_redirect_pc",
        "ghr",
        "phr"
    ]
    
    ids = {}
    names = {}
    
    with open(vcd_path, 'r', encoding='latin-1') as f:
        # 1. Map IDs
        for line in f:
            if "$var" in line:
                parts = line.split()
                if len(parts) >= 5:
                    sig_id = parts[3]
                    sig_name = parts[4]
                    for ts in target_signals:
                        if ts in sig_name:
                            ids[sig_id] = sig_name
                            names[sig_name] = sig_id
            if "$enddefinitions" in line:
                break
                
        print("Found Signals:")
        for k, v in ids.items():
            print(f"{k} -> {v}")
            
        # 2. Track values
        values = {k: "x" for k in ids}
        current_time = 0
        
        # We know cycle 165 is roughly around time = 165 * 10 = 1650 (or whatever clock period is).
        # Let's print changes between time 1500 and 1800
        
        f.seek(0)
        for line in f:
            if line.startswith('#'):
                current_time = int(line.strip()[1:])
                continue
                
            if 1500 <= current_time <= 1800:
                # Value change format:
                # b10101 ID  or 1ID or 0ID
                if line.startswith('b'):
                    parts = line.split()
                    if len(parts) == 2:
                        val, sig_id = parts[0][1:], parts[1]
                        if sig_id in ids:
                            print(f"Time {current_time}: {ids[sig_id]} changed to {val}")
                elif line[0] in '01xXzZ':
                    val, sig_id = line[0], line[1:].strip()
                    if sig_id in ids:
                        print(f"Time {current_time}: {ids[sig_id]} changed to {val}")

if __name__ == "__main__":
    extract_signals("/home/emerald/zaqal/programs/vcd/Lithium.vcd")
