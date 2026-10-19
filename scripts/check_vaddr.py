symbols = {}
with open("/home/emerald/zaqal/programs/vcd/Lithium.vcd") as f:
    scope = []
    for line in f:
        line = line.strip()
        if line.startswith("$scope"):
            scope.append(line.split()[2])
        elif line.startswith("$upscope"):
            if scope: scope.pop()
        elif line.startswith("$var"):
            parts = line.split()
            sig_name = ".".join(scope) + "." + parts[4]
            sym = parts[3]
            if "tlb_0" in sig_name and "io_vaddr" in sig_name:
                symbols[sym] = sig_name
        elif line.startswith("$enddefinitions"):
            break

print("Found vaddr symbols:", symbols)

with open("/home/emerald/zaqal/programs/vcd/Lithium.vcd") as f:
    curr_time = 0
    for line in f:
        line = line.strip()
        if line.startswith("#"):
            try: curr_time = int(line[1:])
            except: pass
        else:
            for s, name in symbols.items():
                if line.endswith(" " + s):
                    val_bin = line[:-(len(s)+1)]
                    val_int = int(val_bin[1:], 2)
                    print(f"Time {curr_time}ps: {name} = 0x{val_int:x} (full: 0x{val_int:016x})")
