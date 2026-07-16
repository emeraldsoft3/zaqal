import os

hex_dir = 'programs/hex/'

def disassemble_word(word, pc):
    # opcode is lowest 7 bits
    opcode = word & 0x7f
    rd = (word >> 7) & 0x1f
    funct3 = (word >> 12) & 0x7
    rs1 = (word >> 15) & 0x1f
    rs2 = (word >> 20) & 0x1f
    
    # Sign-extended immediates
    def get_imm_i(w):
        imm = (w >> 20) & 0xfff
        if imm & 0x800:
            imm -= 0x1000
        return imm

    def get_imm_j(w):
        # [20|10:1|11|19:12]
        bit20 = (w >> 31) & 1
        bits10_1 = (w >> 21) & 0x3ff
        bit11 = (w >> 20) & 1
        bits19_12 = (w >> 12) & 0xff
        imm = (bit20 << 20) | (bits19_12 << 12) | (bit11 << 11) | (bits10_1 << 1)
        if imm & 0x100000:
            imm -= 0x200000
        return imm

    def get_imm_b(w):
        # [12|10:5] [4:1|11]
        bit12 = (w >> 31) & 1
        bit11 = (w >> 7) & 1
        bits10_5 = (w >> 25) & 0x3f
        bits4_1 = (w >> 8) & 0xf
        imm = (bit12 << 12) | (bit11 << 11) | (bits10_5 << 5) | (bits4_1 << 1)
        if imm & 0x1000:
            imm -= 0x2000
        return imm

    if opcode == 0x13: # OP-IMM
        imm = get_imm_i(word)
        if funct3 == 0:
            return f"addi x{rd}, x{rs1}, {imm}"
    elif opcode == 0x6f: # JAL
        imm = get_imm_j(word)
        return f"jal x{rd}, {imm} (target 0x{pc + imm:x})"
    elif opcode == 0x67: # JALR
        imm = get_imm_i(word)
        return f"jalr x{rd}, x{rs1}, {imm}"
    elif opcode == 0x63: # BRANCH
        imm = get_imm_b(word)
        mn = ["beq", "bne", "blt", "bge", "bltu", "bgetu"][funct3] if funct3 < 6 else "br"
        return f"{mn} x{rs1}, x{rs2}, {imm} (target 0x{pc + imm:x})"
        
    return f"word: 0x{word:08x}"

for fname in os.listdir(hex_dir):
    if not fname.endswith('.hex'):
        continue
    path = os.path.join(hex_dir, fname)
    with open(path, 'r') as f:
        content = f.read().strip()
        
    # Split by whitespace or newlines
    tokens = content.split()
    words = []
    for tok in tokens:
        try:
            words.append(int(tok, 16))
        except ValueError:
            pass
            
    # Try disassembling
    pc = 0
    found_jal = False
    lines = []
    for w in words:
        inst = disassemble_word(w, pc)
        lines.append(f"  0x{pc:02x}: {inst}")
        if "jal" in inst or "jalr" in inst or "bne" in inst:
            found_jal = True
        pc += 4
        
    if found_jal:
        print(f"File: {fname}")
        for ln in lines:
            print(ln)
        print("-" * 40)
