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
csr_signals = {}

for sym, paths in symbol_to_signals.items():
    for p in paths:
        pl = p.lower()
        if pl.endswith('.clock') or pl == 'top.clock':
            clock_sym = sym
        if 'backend.exec.csr' in pl:
            if pl.endswith('.io_csr_addr'): csr_signals['addr'] = sym
            if pl.endswith('.io_csr_cmd'): csr_signals['cmd'] = sym
            if pl.endswith('.io_csr_wdata'): csr_signals['wdata'] = sym
            if pl.endswith('.io_csr_rdata'): csr_signals['rdata'] = sym
            if pl.endswith('.io_csr_wen'): csr_signals['wen'] = sym
            if pl.endswith('.r_mscratch'): csr_signals['mscratch'] = sym
            if pl.endswith('.r_satp'): csr_signals['satp'] = sym
            if pl.endswith('.io_flush_pipe'): csr_signals['flush'] = sym

print('Mapped CSR signals:', {k: bool(v) for k, v in csr_signals.items()})

curr_vals = {}
prev_clock = '0'
cycle = 0

events = []

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
                wen = curr_vals.get(csr_signals.get('wen'), '0')
                if wen == '1':
                    addr = curr_vals.get(csr_signals.get('addr'), 'b0')
                    wdata = curr_vals.get(csr_signals.get('wdata'), 'b0')
                    rdata = curr_vals.get(csr_signals.get('rdata'), 'b0')
                    mscratch = curr_vals.get(csr_signals.get('mscratch'), 'b0')
                    satp = curr_vals.get(csr_signals.get('satp'), 'b0')
                    flush = curr_vals.get(csr_signals.get('flush'), '0')
                    
                    events.append((cycle, to_int(addr), to_int(wdata), to_int(rdata), to_int(mscratch), to_int(satp), flush))
            prev_clock = c

print(f'Total cycles: {cycle}')
print(f'CSR Write Events recorded: {len(events)}')
for ev in events:
    print(f'Cycle {ev[0]:4d}: Addr=0x{ev[1]:03x}, WData=0x{ev[2]:08x}, RData=0x{ev[3]:08x}, mscratch=0x{ev[4]:08x}, satp=0x{ev[5]:08x}, Flush={ev[6]}')
