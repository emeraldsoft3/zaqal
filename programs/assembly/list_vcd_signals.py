import sys

def list_signals():
    vcd_path = 'programs/vcd/Lithium.vcd'
    with open(vcd_path, 'r') as f:
        for line in f:
            if line.startswith('$var'):
                parts = line.split()
                # $var type size identifier reference_name $end
                # E.g. $var reg 64 ) io_pc [63:0] $end
                sig_name = ' '.join(parts[4:-1])
                if 'ghr' in sig_name.lower() or 'phr' in sig_name.lower() or 'tables_0' in sig_name.lower() or 'ittage' in sig_name.lower() or 'regfile' in sig_name.lower():
                    print(line.strip())
            elif line.startswith('$dumpvars'):
                break

if __name__ == '__main__':
    list_signals()
