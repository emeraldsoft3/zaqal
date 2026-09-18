import sys

signals_to_find = {
    "TOP.Core.backend.exec.io_int_in_0_valid": "int0_v",
    "TOP.Core.backend.exec.io_int_in_0_bits_uop_pc": "int0_pc",
    "TOP.Core.backend.exec.io_int_in_1_valid": "int1_v",
    "TOP.Core.backend.exec.io_int_in_1_bits_uop_pc": "int1_pc",
    "TOP.Core.backend.exec.io_int_in_2_valid": "int2_v",
    "TOP.Core.backend.exec.io_int_in_2_bits_uop_pc": "int2_pc",
    "TOP.Core.backend.exec.io_int_in_3_valid": "int3_v",
    "TOP.Core.backend.exec.io_int_in_3_bits_uop_pc": "int3_pc",
    "TOP.Core.backend.exec.io_mem_in_0_valid": "mem0_v",
    "TOP.Core.backend.exec.io_mem_in_2_valid": "mem2_v",
}

id_to_name = {}
scopes = []
with open("/home/emerald/zaqal/programs/vcd/Lithium.vcd") as f:
    for line in f:
        if "$enddefinitions" in line:
            break
        parts = line.strip().split()
        if not parts:
            continue
        if parts[0] == "$scope":
            scopes.append(parts[2])
        elif parts[0] == "$upscope":
            if scopes:
                scopes.pop()
        elif parts[0] == "$var":
            if len(parts) >= 5:
                sig_id = parts[3]
                sig_name = parts[4]
                full_name = ".".join(scopes) + "." + sig_name
                if full_name in signals_to_find:
                    id_to_name[sig_id] = signals_to_find[full_name]

print("Found watched signal IDs:", id_to_name)

current_time = 0
events = []
with open("/home/emerald/zaqal/programs/vcd/Lithium.vcd") as f:
    for line in f:
        if "$enddefinitions" in line:
            break
    for line in f:
        line = line.strip()
        if not line:
            continue
        if line.startswith("#"):
            current_time = int(line[1:])
            continue
        if line[0] in "01xXzZ" and len(line) > 1 and not line.startswith("b"):
            val = line[0]
            sig_id = line[1:]
            if sig_id in id_to_name:
                name = id_to_name[sig_id]
                events.append((current_time, name, val))
        elif line.startswith("b"):
            parts = line[1:].split()
            if len(parts) == 2:
                val = parts[0]
                sig_id = parts[1]
                if sig_id in id_to_name:
                    name = id_to_name[sig_id]
                    events.append((current_time, name, val))

time_grouped = {}
for t, name, val in events:
    time_grouped.setdefault(t, {})[name] = val

for t in sorted(time_grouped.keys()):
    items = time_grouped[t]
    cycle = t // 2
    if cycle >= 370 and cycle <= 500:
        # print non-empty
        # convert bin to hex if long
        str_items = {}
        for k, v in items.items():
            if len(v) > 4:
                str_items[k] = hex(int(v, 2))
            else:
                str_items[k] = v
        print(f"Cycle {cycle} (t={t}): {str_items}")
