with open('sim_stdout.log', 'r') as f:
    lines = f.readlines()

print(f"Total lines in simulation log: {len(lines)}")

# Let's search for interesting events like flushes, redirects, and instruction execution
interesting_lines = []
for idx, line in enumerate(lines):
    l_lower = line.lower()
    # Check for redirect, flush, commit, or PC prints
    if 'flush' in l_lower or 'redirect' in l_lower or 'pc=' in l_lower or 'mport_data' in l_lower or 'final logical integer' in l_lower:
        interesting_lines.append((idx, line.strip()))

print(f"Found {len(interesting_lines)} interesting events. Printing first 100:")
for idx, (ln_num, line) in enumerate(interesting_lines[:150]):
    print(f"[{ln_num}] {line}")
