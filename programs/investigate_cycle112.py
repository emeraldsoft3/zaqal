import os

vcd_path = '/home/emerald/zaqal/programs/vcd/Lithium.vcd'
scope_stack = []
symbol_to_signals = {}

with open(vcd_path, 'r', errors='ignore') as f:
    for line in f:
        line = line.strip()
        if not line: continue
        if line.startswith('$scope'):
            parts = line.split()
            if len(parts) >= 3:
                scope_stack.append(parts[2])
        elif line.startswith('$upscope'):
            if scope_stack: scope_stack.pop()
        elif line.startswith('$var'):
            parts = line.split()
            if len(parts) >= 5:
                sym = parts[3]
                name = parts[4]
                full_path = '.'.join(scope_stack) + '.' + name
                symbol_to_signals.setdefault(sym, []).append(full_path)
        elif line.startswith('$enddefinitions'):
            break

clock_sym = None
sigs = {}

for sym, paths in symbol_to_signals.items():
    for p in paths:
        pl = p.lower()
        if pl.endswith('.clock') or pl == 'top.clock':
            clock_sym = sym
        if 'backend.exec.regfile.regs_35' in pl:
            sigs['regs_35'] = sym
        if 'backend.exec.csr.io_csr_wen' in pl:
            sigs['csr_wen'] = sym
        if 'backend.exec.csr.r_mscratch' in pl:
            sigs['mscratch'] = sym
        if 'backend.io_redirect_valid' in pl:
            sigs['redirect_valid'] = sym
        if 'backend.io_redirect_target' in pl:
            sigs['redirect_target'] = sym
        if 'backend.rob.io_commits_valid_0' in pl:
            sigs['commit0'] = sym
        if 'backend.rob.io_commits_valid_1' in pl:
            sigs['commit1'] = sym
        if 'rat' in pl and 'debug_rat_8' in pl:
            sigs['rat_x8'] = sym
        if 'rat' in pl and 'debug_rat_7' in pl:
            sigs['rat_x7'] = sym
        if 'rat' in pl and 'debug_rat_9' in pl:
            sigs['rat_x9'] = sym

print('Mapped signals:', {k: bool(v) for k, v in sigs.items()})

curr_vals = {}
prev_clock = '0'
cycle = 0

def to_int(s):
    if not s: return 0
    return int(s[1:], 2) if s.startswith('b') else int(s) if s.isdigit() else 0

with open(vcd_path, 'r', errors='ignore') as f:
    for line in f:
        if line.startswith('$enddefinitions'): break

    for line in f:
        line = line.strip()
        if not line or line.startswith('#'): continue
        if line.startswith('b') or line.startswith('r'):
            parts = line.split()
            if len(parts) == 2:
                curr_vals[parts[1]] = parts[0]
        else:
            curr_vals[line[1:]] = line[0]

        if clock_sym and clock_sym in curr_vals:
            c = curr_vals[clock_sym]
            if prev_clock == '0' and c == '1':
                cycle += 1
                if 105 <= cycle <= 125:
                    r35 = to_int(curr_vals.get(sigs.get('regs_35')))
                    cwen = curr_vals.get(sigs.get('csr_wen'), '0')
                    mscr = to_int(curr_vals.get(sigs.get('mscratch')))
                    redir = curr_vals.get(sigs.get('redirect_valid'), '0')
                    rtgt = to_int(curr_vals.get(sigs.get('redirect_target')))
                    rat8 = to_int(curr_vals.get(sigs.get('rat_x8')))
                    rat7 = to_int(curr_vals.get(sigs.get('rat_x7')))
                    rat9 = to_int(curr_vals.get(sigs.get('rat_x9')))
                    print(f'Cycle {cycle:3d}: regs_35={r35} (0x{r35:x}), csr_wen={cwen}, mscratch={mscr}, redir={redir} (tgt=0x{rtgt:x}), rat_x8=p{rat8}, rat_x7=p{rat7}')
            prev_clock = c

# Check final architectural RAT mappings and values
print('\nFinal RAT & Regfile check:')
print('Final rat_x8 maps to: p', to_int(curr_vals.get(sigs.get('rat_x8'))))
print('Final rat_x7 maps to: p', to_int(curr_vals.get(sigs.get('rat_x7'))))
print('Final rat_x9 maps to: p', to_int(curr_vals.get(sigs.get('rat_x9'))))
print('Final regs_35:', to_int(curr_vals.get(sigs.get('regs_35'))))
print('Final mscratch:', to_int(curr_vals.get(sigs.get('mscratch'))))
