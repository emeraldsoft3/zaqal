import os
import re

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

def parse_log():
    log_path = 'sim_output2.txt'
    if not os.path.exists(log_path):
        print(f"Error: {log_path} not found.")
        return

    with open(log_path, 'r') as f:
        lines = f.readlines()

    current_sim_cycle = 0
    current_cpu_cycle = 0

    all_renamed = []
    # prf holds the values of physical registers
    prf = {i: 0 for i in range(160)}
    # rat holds the speculative mappings
    rat = {i: i for i in range(32)}
    # arat holds the architectural mappings (for committed state)
    arat = {i: i for i in range(32)}
    # committed register values
    comm_regs = {i: 0 for i in range(32)}

    # FTB state
    ftb = {0: "EMPTY", 1: "EMPTY"}

    # Current GHR
    current_ghr = 0
    current_phr = 0

    # Last seen redirect pc
    last_redirect_pc = None

    for line in lines:
        # 1. Track Cycle
        m = re.match(r'\[TESTBENCH\] Cycle (\d+)', line)
        if m:
            current_sim_cycle = int(m.group(1))
            current_cpu_cycle = current_sim_cycle - 5
            continue

        # 2. Track GHR spec shift
        m = re.search(r'\[BPU GHR SPEC SHIFT\] ghr=([0-9a-fA-F]+)', line)
        if m:
            current_ghr = int(m.group(1), 16)
            continue

        # 3. Track GHR restore
        m = re.search(r'\[BPU GHR RESTORE\] ghr=([0-9a-fA-F]+)', line)
        if m:
            current_ghr = int(m.group(1), 16)
            continue

        # 4. FTB updates
        m = re.search(r'\[FTB UPDATE\] pc=([0-9a-fA-F]+) index=\s*(\d+).*target=([0-9a-fA-F]+)', line)
        if m:
            src = int(m.group(1), 16) & 0xff
            idx = int(m.group(2))
            tgt = int(m.group(3), 16) & 0xff
            ftb[idx] = f"x{src:02x} - x{tgt:02x}"
            continue

        # 5. CORE RENAME
        m = re.search(r'CORE RENAME \[Cycle\s+(\d+)\].*pc=([0-9a-fA-F]+).*inst=([0-9a-fA-F]+)', line)
        if m:
            rename_cpu_cycle = int(m.group(1))
            pc_val = int(m.group(2), 16)
            inst_hex = m.group(3)
            
            # Filter out odd 2-byte slot alignments (second halves of 32-bit instructions)
            if (pc_val & 0x3) != 0:
                continue

            # Parse lrd and pdest
            lrd = None
            pdest = None
            m_lrd = re.search(r'lrd=\s*(\d+)', line)
            m_pdest = re.search(r'pdest=\s*(\d+)', line)
            if m_lrd: lrd = int(m_lrd.group(1))
            if m_pdest: pdest = int(m_pdest.group(1))

            pc_offset = pc_val & 0xff
            inst_text = disasm.get(pc_offset, f"unknown (0x{inst_hex})")

            # Record instruction
            inst_dict = {
                'pc_val': pc_val,
                'pc_short': f"x{pc_offset:02x}",
                'instruction': inst_text,
                'lrd': lrd,
                'pdest': pdest,
                'rename_cycle': rename_cpu_cycle,
                'commit_cycle': None,
                'bru_cycle': None,
                'flushed': False,
                'x1': 0, 'x4': 0, 'x5': 0, 'x14': 0, 'x15': 0, 'x17': 0,
                'ftb0': ftb[0], 'ftb1': ftb[1],
                'ghr': f"0b{current_ghr:b}",
                'phr': f"0b{current_phr:b}",
                'tage': "",
                'ittage': ""
            }
            
            # Update spec RAT
            if lrd is not None and pdest is not None:
                rat[lrd] = pdest

            all_renamed.append(inst_dict)
            continue

        # 6. BRU REDIRECT
        m = re.search(r'\[BRU REDIRECT\] pc=([0-9a-fA-F]+) target=([0-9a-fA-F]+) actual_taken=(\d+)', line)
        if m:
            pc_val = int(m.group(1), 16)
            last_redirect_pc = pc_val
            # Match to the oldest active instruction with this pc
            for inst in all_renamed:
                if inst['pc_val'] == pc_val and inst['bru_cycle'] is None and not inst['flushed']:
                    inst['bru_cycle'] = current_cpu_cycle
                    break
            continue

        # 7. REGFILE WRITE
        m = re.search(r'\[REGFILE WRITE Port \d+\]: addr=\s*(\d+) data=([0-9a-fA-F]+) at cycle=\s*(\d+)', line)
        if m:
            pReg = int(m.group(1))
            val = int(m.group(2), 16)
            write_cycle = int(m.group(3))
            prf[pReg] = val

            # Find matching rename instruction and mark commit
            # We look for the oldest uncommitted instruction with this pdest
            for inst in all_renamed:
                if inst['pdest'] == pReg and inst['commit_cycle'] is None and not inst['flushed']:
                    inst['commit_cycle'] = write_cycle
                    # Update committed register values at commit time
                    arat[inst['lrd']] = pReg
                    comm_regs[inst['lrd']] = val
                    break
            continue

        # 8. Flush Detection
        m = re.search(r'FRONTEND FLUSH', line)
        if m:
            if last_redirect_pc is not None:
                found_redirector = False
                for inst in all_renamed:
                    if inst['pc_val'] == last_redirect_pc and not inst['flushed']:
                        found_redirector = True
                        continue
                    if found_redirector:
                        inst['flushed'] = True
            continue

    print(f"Parsed {len(all_renamed)} total instructions.")
    for i, inst in enumerate(all_renamed[:40]):
        print(f"PC: {inst['pc_short']} | Inst: {inst['instruction']} | Rename: {inst['rename_cycle']} | Commit: {inst['commit_cycle']} | BRU: {inst['bru_cycle']} | Flushed: {inst['flushed']}")

if __name__ == '__main__':
    parse_log()
