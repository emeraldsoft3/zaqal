#!/bin/bash
# Script to generate definitive disassembly for the user's hex strings
OUTPUT="programs/assembly/definitive_disassembly.txt"

# Create a temporary binary file
echo "00080137 01322105 006000ef 1101a001 1000ec22 222347a9 47d1fef4 fef42023 fe042623 fe042423 2783a815 8b85fe84 eb892781 fec42703 fe442783 26239fb9 a801fef4 fec42703 fe042783 26239fb9 2783fef4 2785fe84 fef42423 fe842783 0007871b d2e34791 a001fce7" > tmp.hex

# Convert hex words to binary (handling little-endianness of the words)
# We assume the user's hex list is a sequence of 32-bit words
python3 -c "
import struct
with open('tmp.hex', 'r') as f:
    hex_list = f.read().split()
with open('tmp.bin', 'wb') as f:
    for h in hex_list:
        # Each word is 4 bytes. We write it as-is for the disassembler
        val = int(h, 16)
        f.write(struct.pack('<I', val))
"

# Disassemble
riscv64-unknown-elf-objdump -b binary -m riscv:rv64 -M no-aliases,numeric -D tmp.bin > $OUTPUT

echo "Disassembly generated in $OUTPUT"
rm tmp.hex tmp.bin
