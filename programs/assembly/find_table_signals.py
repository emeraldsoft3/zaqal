def find_table_signals():
    vcd_path = 'programs/vcd/Lithium.vcd'
    scope_stack = []
    with open(vcd_path, 'r') as f:
        for line in f:
            stripped = line.strip()
            if not stripped:
                continue
            if stripped.startswith('$scope'):
                parts = stripped.split()
                scope_stack.append(parts[2])
            elif stripped.startswith('$upscope'):
                if scope_stack:
                    scope_stack.pop()
            elif stripped.startswith('$var'):
                parts = stripped.split()
                symbol = parts[3]
                name_idx = 4
                while name_idx < len(parts) and parts[name_idx] != '$end':
                    name_idx += 1
                name = parts[4]
                full_path = ".".join(scope_stack) + "." + name
                if 'tables_0' in full_path and any(k in name.lower() for k in ['valid', 'ctr', 'tag', 'us']):
                    # Print only a few examples to see naming convention
                    print(f"{full_path} -> symbol {symbol}")
            elif stripped.startswith('$enddefinitions'):
                break

if __name__ == '__main__':
    find_table_signals()
