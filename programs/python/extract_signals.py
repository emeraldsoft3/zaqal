#!/usr/bin/env python3
import sys

def parse_vcd_signals(vcd_file):
    """Extract full signal paths from VCD file."""
    signals = []
    current_path = []
    
    with open(vcd_file, 'r') as f:
        for line in f:
            line = line.strip()
            if line.startswith('$scope module'):
                # Enter new scope
                module_name = line.split()[2]
                current_path.append(module_name)
            elif line.startswith('$upscope'):
                # Exit scope
                if current_path:
                    current_path.pop()
            elif line.startswith('$var'):
                # Found a signal
                parts = line.split()
                if len(parts) >= 5:
                    var_type = parts[1]
                    width = parts[2]
                    code = parts[3]
                    name = parts[4]
                    full_name = '.'.join(current_path + [name])
                    signals.append(full_name)
    
    return signals

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <vcd_file>")
        sys.exit(1)
    
    vcd_file = sys.argv[1]
    signals = parse_vcd_signals(vcd_file)
    
    # Filter for CPU core signals
    for sig in signals:
        if any(keyword in sig for keyword in ['core', 'frontend', 'backend', 'lsu', 'mem']):
            print(sig)