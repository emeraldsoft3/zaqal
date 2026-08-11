import struct

def r32(val): return val & 0xFFFFFFFF
def jal(rd, offset):
    imm = offset
    imm20 = (imm >> 20) & 1
    imm10_1 = (imm >> 1) & 0x3FF
    imm11 = (imm >> 11) & 1
    imm19_12 = (imm >> 12) & 0xFF
    return (imm20 << 31) | (imm10_1 << 21) | (imm11 << 20) | (imm19_12 << 12) | (rd << 7) | 0x6f

def addi(rd, rs1, imm):
    return ((imm & 0xFFF) << 20) | (rs1 << 15) | (0 << 12) | (rd << 7) | 0x13

insts = []
for i in range(1, 9):
    insts.append(addi(i, i, i))

for i in range(8):
    insts.append(addi(0, 0, 0))

for i in range(7):
    insts.append(addi(0, 0, 0))

# jal x0, -92 (from inst 23 to inst 0)
insts.append(jal(0, -92))

for i, inst in enumerate(insts):
    print(f'\"h{inst:08x}\".U, // {i:02d}')
