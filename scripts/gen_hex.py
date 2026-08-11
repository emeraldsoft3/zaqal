def enc_i(opcode, funct3, rd, rs1, imm):
    return ((imm & 0xFFF) << 20) | (rs1 << 15) | (funct3 << 12) | (rd << 7) | opcode
def enc_b(opcode, funct3, rs1, rs2, imm):
    return (((imm >> 12) & 1) << 31) | (((imm >> 5) & 0x3F) << 25) | (rs2 << 20) | (rs1 << 15) | (funct3 << 12) | (((imm >> 1) & 0xF) << 8) | (((imm >> 11) & 1) << 7) | opcode
def enc_j(opcode, rd, imm):
    return (((imm >> 20) & 1) << 31) | (((imm >> 1) & 0x3FF) << 21) | (((imm >> 11) & 1) << 20) | (((imm >> 12) & 0xFF) << 12) | (rd << 7) | opcode

print(f'{enc_b(0x63, 0, 20, 0, 88):08x}')      # 0x08: beq x20, x0, 88
print(f'{enc_j(0x6F, 1, 96):08x}')             # 0x20: jal x1, 96
print(f'{enc_j(0x6F, 0, -60):08x}')            # 0x44: jal x0, -60
