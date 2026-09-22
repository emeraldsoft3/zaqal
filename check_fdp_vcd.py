import sys

scopes = []
found = []
with open('/home/emerald/zaqal/programs/vcd/Lithium.vcd') as f:
    for line in f:
        if '' in line:
            break
        parts = line.strip().split()
        if not parts:
            continue
        if parts[0] == '':
            scopes.append(parts[2])
        elif parts[0] == '':
            if scopes:
                scopes.pop()
        elif parts[0] == '':
            if len(parts) >= 5:
                sig_name = parts[4]
                full_name = '.'.join(scopes) + '.' + sig_name
                if any(x in full_name.lower() for x in ['fdp', 'prefetch', 'branch_signal', 'mshr']):
                    found.append(full_name)

print('Total matching signals:', len(found))
for s in found[:30]:
    print(s)
