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

def get_architectural_trace():
    pc = 0x80000000
    regs = {1: 0, 4: 0, 5: 0, 14: 0, 15: 0, 17: 0}
    trace = []
    
    for _ in range(50):
        pc_short = pc & 0xff
        inst_text = disasm.get(pc_short, f"unknown (0x{pc:X})")
        trace.append({
            'pc': pc,
            'pc_short': f"x{pc_short:02x}",
            'instruction': inst_text
        })
        
        if pc_short == 0x00:
            regs[1] = 10
            pc += 4
        elif pc_short == 0x04:
            regs[5] = 0
            pc += 4
        elif pc_short == 0x08:
            regs[5] += 6
            pc += 4
        elif pc_short == 0x0c:
            regs[14] = regs[5] & 3
            pc += 4
        elif pc_short == 0x10:
            if regs[14] == 0:
                pc += 8
            else:
                pc += 4
        elif pc_short == 0x14:
            regs[15] = 1
            pc += 4
        elif pc_short == 0x18:
            regs[17] = regs[14] << 2
            pc += 4
        elif pc_short == 0x1c:
            regs[4] = pc + 4
            pc = 0x80000030
        elif pc_short == 0x20:
            regs[15] = 10
            pc += 4
        elif pc_short == 0x24:
            pc = 0x80000024  # infinite loop
        elif pc_short == 0x28:
            regs[15] = 20
            pc += 4
        elif pc_short == 0x2c:
            pc = 0x8000003c
        elif pc_short == 0x30:
            regs[4] = regs[4] + regs[17]
            pc += 4
        elif pc_short == 0x34:
            temp = pc + 4
            pc = regs[4]
            regs[1] = temp
        elif pc_short == 0x38:
            regs[1] -= 1
            pc += 4
        elif pc_short == 0x3c:
            if regs[1] != 0:
                pc = 0x80000008
            else:
                pc += 4
        else:
            break
            
    return trace

for idx, t in enumerate(get_architectural_trace()):
    print(f"{idx+1}: {t['pc_short']} {t['instruction']}")
