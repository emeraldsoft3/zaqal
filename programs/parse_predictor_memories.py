import os
import re

def write_tage_snapshot(t, update_idx, cycle, mem):
    for folder in ['debug/memory/snapshots', 'testing/memory/snapshots']:
        os.makedirs(folder, exist_ok=True)
        csv_file = f"{folder}/tage_table_{t}_update_{update_idx}_cycle_{cycle}.csv"
        with open(csv_file, 'w') as out:
            out.write("Row,Valid,Tag_Hex,Counter,Useful\n")
            for r in range(128):
                tag_hex = f"0x{mem['tags'][r]:02X}"
                out.write(f"{r},{mem['valids'][r]},{tag_hex},{mem['ctrs'][r]},{mem['us'][r]}\n")

def write_ittage_snapshot(t, update_idx, cycle, mem):
    for folder in ['debug/memory/snapshots', 'testing/memory/snapshots']:
        os.makedirs(folder, exist_ok=True)
        csv_file = f"{folder}/ittage_table_{t}_update_{update_idx}_cycle_{cycle}.csv"
        with open(csv_file, 'w') as out:
            out.write("Row,Valid,Tag_Hex,Target_Hex,Useful\n")
            for r in range(64):
                tag_hex = f"0x{mem['tags'][r]:02X}"
                tgt_hex = f"0x{mem['targets'][r]:08X}"
                out.write(f"{r},{mem['valids'][r]},{tag_hex},{tgt_hex},{mem['us'][r]}\n")

def parse_vcd_and_dump():
    vcd_path = 'programs/vcd/Lithium.vcd'
    if not os.path.exists(vcd_path):
        print(f"Error: {vcd_path} not found.")
        return

    print("Parsing VCD file to reconstruct TAGE and ITTAGE memories...")

    scope_stack = []
    symbol_to_signals = {}
    
    with open(vcd_path, 'r') as f:
        # 1. Parse Header
        for line in f:
            stripped = line.strip()
            if not stripped:
                continue
            if stripped.startswith('$scope'):
                parts = stripped.split()
                scope_name = parts[2]
                scope_stack.append(scope_name)
            elif stripped.startswith('$upscope'):
                if scope_stack:
                    scope_stack.pop()
            elif stripped.startswith('$var'):
                parts = stripped.split()
                symbol = parts[3]
                name_idx = 4
                while name_idx < len(parts) and parts[name_idx] != '$end':
                    name_idx += 1
                name_parts = parts[4:name_idx]
                name = name_parts[0]
                
                full_path = ".".join(scope_stack) + "." + name
                if symbol not in symbol_to_signals:
                    symbol_to_signals[symbol] = []
                symbol_to_signals[symbol].append(full_path)
            elif stripped.startswith('$enddefinitions'):
                break

    print(f"Header parsed. Registered {len(symbol_to_signals)} unique symbols.")

    # 2. Build direct symbol lookups for each table to optimize execution
    tage_symbols = []
    for t in range(4):
        tage_symbols.append({
            'tag_en': [], 'tag_addr': [], 'tag_data': [],
            'ctr_en': [], 'ctr_addr': [], 'ctr_data': [],
            'us': {}, # port -> { 'en': [], 'addr': [], 'data': [] }
            'update_valid': [], 'allocate': []
        })

    ittage_symbols = []
    for t in range(4):
        ittage_symbols.append({
            'tag_en': [], 'tag_addr': [], 'tag_data': [],
            'tgt_en': [], 'tgt_addr': [], 'tgt_data': [],
            'us': {}, # port -> { 'en': [], 'addr': [], 'data': [] }
            'update_valid': [], 'allocate': []
        })

    clock_symbol = None

    for sym, paths in symbol_to_signals.items():
        for path in paths:
            if path.endswith(".clock") or path.endswith("_clock") or path == "TOP.clock":
                clock_symbol = sym

            # TAGE
            for t in range(4):
                prefix_dot = f"TOP.Core.frontend.bpu.tage.tables_{t}."
                prefix_under = f"TOP.Core.frontend.bpu.tage.tables_{t}_"
                if path.startswith(prefix_dot) or path.startswith(prefix_under):
                    if path.endswith(".tags_MPORT_en") or path.endswith("_tags_MPORT_en"):
                        tage_symbols[t]['tag_en'].append(sym)
                    elif path.endswith(".tags_MPORT_addr") or path.endswith("_tags_MPORT_addr"):
                        tage_symbols[t]['tag_addr'].append(sym)
                    elif path.endswith(".tags_MPORT_data") or path.endswith("_tags_MPORT_data"):
                        tage_symbols[t]['tag_data'].append(sym)
                    elif path.endswith(".ctrs_MPORT_en") or path.endswith("_ctrs_MPORT_en") or path.endswith(".ctrs_MPORT_1_en") or path.endswith("_ctrs_MPORT_1_en"):
                        tage_symbols[t]['ctr_en'].append(sym)
                    elif path.endswith(".ctrs_MPORT_addr") or path.endswith("_ctrs_MPORT_addr") or path.endswith(".ctrs_MPORT_1_addr") or path.endswith("_ctrs_MPORT_1_addr"):
                        tage_symbols[t]['ctr_addr'].append(sym)
                    elif path.endswith(".ctrs_MPORT_data") or path.endswith("_ctrs_MPORT_data") or path.endswith(".ctrs_MPORT_1_data") or path.endswith("_ctrs_MPORT_1_data"):
                        tage_symbols[t]['ctr_data'].append(sym)
                    elif "us_MPORT_" in path:
                        m = re.search(r'us_MPORT_(\d+)', path)
                        if m:
                            port = int(m.group(1))
                            if port not in tage_symbols[t]['us']:
                                tage_symbols[t]['us'][port] = {'en': [], 'addr': [], 'data': []}
                            if path.endswith("_en") or path.endswith(".en"):
                                tage_symbols[t]['us'][port]['en'].append(sym)
                            elif path.endswith("_addr") or path.endswith(".addr"):
                                tage_symbols[t]['us'][port]['addr'].append(sym)
                            elif path.endswith("_data") or path.endswith(".data"):
                                tage_symbols[t]['us'][port]['data'].append(sym)
                    elif path.endswith("io_update_valid"):
                        tage_symbols[t]['update_valid'].append(sym)
                    elif path.endswith("io_allocate"):
                        tage_symbols[t]['allocate'].append(sym)

            # ITTAGE
            for t in range(4):
                prefix_dot = f"TOP.Core.frontend.bpu.ittage.tables_{t}."
                prefix_under = f"TOP.Core.frontend.bpu.ittage.tables_{t}_"
                if path.startswith(prefix_dot) or path.startswith(prefix_under):
                    if path.endswith(".tags_MPORT_en") or path.endswith("_tags_MPORT_en"):
                        ittage_symbols[t]['tag_en'].append(sym)
                    elif path.endswith(".tags_MPORT_addr") or path.endswith("_tags_MPORT_addr"):
                        ittage_symbols[t]['tag_addr'].append(sym)
                    elif path.endswith(".tags_MPORT_data") or path.endswith("_tags_MPORT_data"):
                        ittage_symbols[t]['tag_data'].append(sym)
                    elif path.endswith(".targets_MPORT_en") or path.endswith("_targets_MPORT_en") or path.endswith(".targets_MPORT_1_en") or path.endswith("_targets_MPORT_1_en"):
                        ittage_symbols[t]['tgt_en'].append(sym)
                    elif path.endswith(".targets_MPORT_addr") or path.endswith("_targets_MPORT_addr") or path.endswith(".targets_MPORT_1_addr") or path.endswith("_targets_MPORT_1_addr"):
                        ittage_symbols[t]['tgt_addr'].append(sym)
                    elif path.endswith(".targets_MPORT_data") or path.endswith("_targets_MPORT_data") or path.endswith(".targets_MPORT_1_data") or path.endswith("_targets_MPORT_1_data"):
                        ittage_symbols[t]['tgt_data'].append(sym)
                    elif "us_MPORT_" in path:
                        m = re.search(r'us_MPORT_(\d+)', path)
                        if m:
                            port = int(m.group(1))
                            if port not in ittage_symbols[t]['us']:
                                ittage_symbols[t]['us'][port] = {'en': [], 'addr': [], 'data': []}
                            if path.endswith("_en") or path.endswith(".en"):
                                ittage_symbols[t]['us'][port]['en'].append(sym)
                            elif path.endswith("_addr") or path.endswith(".addr"):
                                ittage_symbols[t]['us'][port]['addr'].append(sym)
                            elif path.endswith("_data") or path.endswith(".data"):
                                ittage_symbols[t]['us'][port]['data'].append(sym)
                    elif path.endswith("io_update_valid"):
                        ittage_symbols[t]['update_valid'].append(sym)
                    elif path.endswith("io_allocate"):
                        ittage_symbols[t]['allocate'].append(sym)

    print(f"Direct symbol lookups built. Clock symbol is: {clock_symbol}")

    def parse_bin(val_str):
        if not val_str:
            return 0
        if val_str.startswith('b'):
            val_str = val_str[1:]
        try:
            return int(val_str, 2)
        except ValueError:
            return 0

    # Initialize memories
    tage_mem = []
    for t in range(4):
        tage_mem.append({
            'tags': [0] * 128,
            'ctrs': [3] * 128,
            'us': [0] * 128,
            'valids': [False] * 128
        })

    ittage_mem = []
    for t in range(4):
        ittage_mem.append({
            'tags': [0] * 64,
            'targets': [0] * 64,
            'us': [0] * 64,
            'valids': [False] * 64
        })

    symbol_values = {}
    prev_clock = '0'
    cycle_count = 0
    tage_update_counts = [0] * 4
    ittage_update_counts = [0] * 4

    with open(vcd_path, 'r') as f:
        # Skip header definitions again
        for line in f:
            if line.strip().startswith('$enddefinitions'):
                break

        # Process value changes
        for line in f:
            stripped = line.strip()
            if not stripped or stripped.startswith('#'):
                continue
            
            if stripped.startswith('b') or stripped.startswith('r'):
                parts = stripped.split()
                if len(parts) == 2:
                    val, sym = parts
                    symbol_values[sym] = val
            else:
                val = stripped[0]
                sym = stripped[1:]
                symbol_values[sym] = val

            # Clock rising edge check
            if clock_symbol and sym == clock_symbol:
                current_clock = val
                if prev_clock == '0' and current_clock == '1':
                    cycle_count += 1
                    # Process TAGE
                    for t in range(4):
                        syms = tage_symbols[t]
                        tag_en = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['tag_en'])
                        tag_addr = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tag_addr']), 0)
                        tag_data = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tag_data']), 0)

                        ctr_en = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['ctr_en'])
                        ctr_addr = next((parse_bin(symbol_values.get(s, '0')) for s in syms['ctr_addr']), 0)
                        ctr_data = next((parse_bin(symbol_values.get(s, '0')) for s in syms['ctr_data']), 0)

                        us_en = 0
                        us_addr = 0
                        us_data = 0
                        for port, port_syms in syms['us'].items():
                            if any(parse_bin(symbol_values.get(s, '0')) == 1 for s in port_syms['en']):
                                us_en = 1
                                us_addr = next((parse_bin(symbol_values.get(s, '0')) for s in port_syms['addr']), 0)
                                us_data = next((parse_bin(symbol_values.get(s, '0')) for s in port_syms['data']), 0)
                                break

                        update_valid = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['update_valid'])
                        allocate = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['allocate'])

                        updated = False
                        if tag_en:
                            tage_mem[t]['tags'][tag_addr] = tag_data
                            print(f"  [Write TAGE T{t}] Row {tag_addr} tag = 0x{tag_data:02X}")
                            updated = True
                        if ctr_en:
                            tage_mem[t]['ctrs'][ctr_addr] = ctr_data
                            print(f"  [Write TAGE T{t}] Row {ctr_addr} ctr = {ctr_data}")
                            updated = True
                        if us_en:
                            tage_mem[t]['us'][us_addr] = us_data
                            print(f"  [Write TAGE T{t}] Row {us_addr} u = {us_data}")
                            updated = True
                        if update_valid and allocate:
                            # Use the tag_addr or ctr_addr write address
                            u_idx = tag_addr if tag_en else (ctr_addr if ctr_en else 0)
                            tage_mem[t]['valids'][u_idx] = True
                            print(f"  [Allocate TAGE T{t}] Row {u_idx} valid = True")
                            updated = True

                        if updated:
                            tage_update_counts[t] += 1
                            write_tage_snapshot(t, tage_update_counts[t], cycle_count, tage_mem[t])

                    # Process ITTAGE
                    for t in range(4):
                        syms = ittage_symbols[t]
                        tag_en = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['tag_en'])
                        tag_addr = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tag_addr']), 0)
                        tag_data = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tag_data']), 0)

                        tgt_en = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['tgt_en'])
                        tgt_addr = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tgt_addr']), 0)
                        tgt_data = next((parse_bin(symbol_values.get(s, '0')) for s in syms['tgt_data']), 0)

                        us_en = 0
                        us_addr = 0
                        us_data = 0
                        for port, port_syms in syms['us'].items():
                            if any(parse_bin(symbol_values.get(s, '0')) == 1 for s in port_syms['en']):
                                us_en = 1
                                us_addr = next((parse_bin(symbol_values.get(s, '0')) for s in port_syms['addr']), 0)
                                us_data = next((parse_bin(symbol_values.get(s, '0')) for s in port_syms['data']), 0)
                                break

                        update_valid = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['update_valid'])
                        allocate = any(parse_bin(symbol_values.get(s, '0')) == 1 for s in syms['allocate'])

                        updated = False
                        if tag_en:
                            ittage_mem[t]['tags'][tag_addr] = tag_data
                            print(f"  [Write ITTAGE T{t}] Row {tag_addr} tag = 0x{tag_data:02X}")
                            updated = True
                        if tgt_en:
                            ittage_mem[t]['targets'][tgt_addr] = tgt_data
                            print(f"  [Write ITTAGE T{t}] Row {tgt_addr} target = 0x{tgt_data:X}")
                            updated = True
                        if us_en:
                            ittage_mem[t]['us'][us_addr] = us_data
                            print(f"  [Write ITTAGE T{t}] Row {us_addr} u = {us_data}")
                            updated = True
                        if update_valid and allocate:
                            u_idx = tag_addr if tag_en else (tgt_addr if tgt_en else 0)
                            ittage_mem[t]['valids'][u_idx] = True
                            print(f"  [Allocate ITTAGE T{t}] Row {u_idx} valid = True")
                            updated = True

                        if updated:
                            ittage_update_counts[t] += 1
                            write_ittage_snapshot(t, ittage_update_counts[t], cycle_count, ittage_mem[t])

                prev_clock = current_clock

    # 3. Write final CSVs
    for folder in ['debug/memory', 'testing/memory']:
        os.makedirs(folder, exist_ok=True)
        for t in range(4):
            csv_file = f"{folder}/tage_table_{t}.csv"
            with open(csv_file, 'w') as out:
                out.write("Row,Valid,Tag_Hex,Counter,Useful\n")
                for r in range(128):
                    val = tage_mem[t]
                    tag_hex = f"0x{val['tags'][r]:02X}"
                    out.write(f"{r},{val['valids'][r]},{tag_hex},{val['ctrs'][r]},{val['us'][r]}\n")
            print(f"Saved {csv_file}")
            
            csv_file = f"{folder}/ittage_table_{t}.csv"
            with open(csv_file, 'w') as out:
                out.write("Row,Valid,Tag_Hex,Target_Hex,Useful\n")
                for r in range(64):
                    val = ittage_mem[t]
                    tag_hex = f"0x{val['tags'][r]:02X}"
                    tgt_hex = f"0x{val['targets'][r]:08X}"
                    out.write(f"{r},{val['valids'][r]},{tag_hex},{tgt_hex},{val['us'][r]}\n")
            print(f"Saved {csv_file}")

    print("Reconstruction complete!")

if __name__ == '__main__':
    parse_vcd_and_dump()
