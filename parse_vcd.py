import sys

def analyze_vcd(vcd_path):
    signals = []
    
    with open(vcd_path, 'r', encoding='latin-1') as f:
        # Find identifier
        for line in f:
            if "flushOut" in line or "exception" in line.lower() or "bpu_redirect" in line:
                if "$var" in line:
                    parts = line.split()
                    if len(parts) >= 4:
                        print(line.strip())
            if "$enddefinitions" in line:
                break

if __name__ == "__main__":
    analyze_vcd("/home/emerald/zaqal/programs/vcd/Lithium.vcd")
