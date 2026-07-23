import re
log_path = 'sim_output2.txt'
all_renamed = []
disasm = {
    0x00: "addi x1, x0, 10",
    0x04: "addi x5, x0, 0",
    0x08: "addi x5, x5, 6",
    0x0c: "andi x14, x5, 3",
    0x10: "beq x14, x0, 8",
    0x14: "addi x15, x0, 1",
    0x18: "slli x17, x14, 2",
    0x1c: "jal x4, 20",
    0x20: "addi x15, x0, 10",
    0x24: "jal x0, 24",
    0x28: "addi x15, x0, 20",
    0x2c: "jal x0, 16",
    0x30: "add x4, x4, x17",
    0x34: "jalr x1, x4, 0",
    0x38: "addi x1, x1, -1",
    0x3c: "bne x1, x0, -52",
    0x40: "addi x12, x0, 99"
}

current_cpu_cycle = 0

with open(log_path, 'r') as f:
    for line in f:
        m = re.match(r'\[TESTBENCH\] Cycle (\d+)', line)
        if m:
            current_cpu_cycle = int(m.group(1)) - 5
            continue

        m = re.search(r'CORE RENAME \[Cycle\s+(\d+)\].*pc=([0-9a-fA-F]+).*inst=([0-9a-fA-F]+)', line)
        if m:
            rename_cpu_cycle = int(m.group(1))
            pc_val = int(m.group(2), 16)
            inst_hex = m.group(3)
            if (pc_val & 0x3) != 0:
                continue
            pc_offset = pc_val & 0xff
            inst_text = disasm.get(pc_offset, f"unknown (0x{inst_hex})")
            all_renamed.append({
                'pc_val': pc_val,
                'pc_short': f"x{pc_offset:02x}",
                'instruction': inst_text,
                'rename_cycle': rename_cpu_cycle,
                'commit_cycle': None,
                'bru_cycle': None,
                'flushed': False
            })
            continue

        m = re.search(r'\[BPU GHR RESTORE\].*redirect_pc=([0-9a-fA-F]+)', line)
        if m:
            redirect_pc = int(m.group(1), 16)
            idx_redirect = -1
            for idx in range(len(all_renamed)):
                if all_renamed[idx]['pc_val'] == redirect_pc and not all_renamed[idx]['flushed']:
                    idx_redirect = idx
                    break
            if idx_redirect != -1:
                print(f"Flush at cycle={current_cpu_cycle} redirect_pc=x{redirect_pc&0xff:02x} idx_redirect={idx_redirect}")
                for idx in range(idx_redirect + 1, len(all_renamed)):
                    all_renamed[idx]['flushed'] = True
            else:
                print(f"Flush at cycle={current_cpu_cycle} redirect_pc=x{redirect_pc&0xff:02x} NOT FOUND")
            continue
