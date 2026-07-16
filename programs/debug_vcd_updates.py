with open('programs/vcd/Lithium.vcd', 'r') as f:
    symbol_to_signal = {}
    sig_values = {}
    
    # Parse header
    for line in f:
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith('$var'):
            parts = stripped.split()
            symbol = parts[3]
            name = parts[4]
            symbol_to_signal[symbol] = name
        elif stripped.startswith('$enddefinitions'):
            break

    # Parse changes
    clock_sym = None
    for sym, name in symbol_to_signal.items():
        if name == 'clock':
            clock_sym = sym
            
    time = 0
    for line in f:
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith('#'):
            time = int(stripped[1:])
            continue
        
        if stripped.startswith('b') or stripped.startswith('r'):
            parts = stripped.split()
            if len(parts) == 2:
                val, sym = parts
                sig_values[sym] = val
        else:
            val = stripped[0]
            sym = stripped[1:]
            sig_values[sym] = val
            
        # Check updates when update_valid changes
        if sym in symbol_to_signal:
            name = symbol_to_signal[sym]
            if 'update_valid' in name.lower() or 'allocate' in name.lower() or 'tags_mport_en' in name.lower():
                print(f"Time {time}: {name} = {val}")
