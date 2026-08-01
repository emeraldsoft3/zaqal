import os

vcd_path = 'vcd/Lithium.vcd'
gtkw_path = 'vcd/Full_Pipeline_Trace.gtkw'

if not os.path.exists(vcd_path):
    print(f"VCD not found at {vcd_path}")
    exit(1)

signals = []
keywords = [
    'ibuffer', 'decode', 'dispatch', 'intrat', 'curr_spec_table',
    'busy_table', 'free_list', 'intiq', 'bru', 'alu', 'regfile', 'snapshot'
]

print("Parsing VCD header...")
with open(vcd_path, 'r', encoding='utf-8', errors='ignore') as f:
    scope_stack = []
    for line in f:
        stripped = line.strip()
        if stripped.startswith('$enddefinitions'):
            break
        
        if stripped.startswith('$scope'):
            parts = stripped.split()
            if len(parts) >= 3:
                scope_stack.append(parts[2])
        elif stripped.startswith('$upscope'):
            if scope_stack:
                scope_stack.pop()
        elif stripped.startswith('$var'):
            parts = stripped.split()
            if len(parts) >= 5:
                sig_name = parts[4]
                if '[' in sig_name:
                    pass # Keep the bracket if it exists
                # Reconstruct full path
                full_path = '.'.join(scope_stack) + '.' + sig_name
                
                # Filter by keywords
                lower_path = full_path.lower()
                if any(kw in lower_path for kw in keywords) and ('io_' in lower_path or 'valid' in lower_path or 'pc' in lower_path or 'regs' in lower_path or 'table' in lower_path):
                    if len(signals) < 150: # Limit to 150 signals to avoid massive gtkw
                        signals.append(full_path)

print(f"Found {len(signals)} matching signals.")

with open(gtkw_path, 'w') as f:
    f.write("[*]\n[*] GTKWave Analyzer v3.3.111 (w)\n[*]\n")
    f.write(f'[dumpfile] "{os.path.abspath(vcd_path)}"\n')
    f.write(f'[savefile] "{os.path.abspath(gtkw_path)}"\n')
    f.write("[timestart] 0\n[size] 1920 1080\n[pos] -1 -1\n")
    f.write("*-10.000000 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1\n")
    
    # Write tree open for main scopes
    scopes_to_open = set()
    for sig in signals:
        parts = sig.split('.')
        for i in range(1, min(len(parts), 5)):
            scopes_to_open.add('.'.join(parts[:i]) + '.')
            
    for scope in sorted(list(scopes_to_open)):
        f.write(f"[treeopen] {scope}\n")
        
    f.write("[sst_width] 300\n[signals_width] 400\n[sst_expanded] 1\n[sst_vpaned_height] 300\n")
    
    # Write signals
    for sig in signals:
        if '[' in sig:
            f.write(f"@22\n{sig}\n")
        else:
            f.write(f"@28\n{sig}\n")
            
print(f"Generated {gtkw_path}")
