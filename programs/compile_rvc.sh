#!/bin/bash

# Default to riscv64-unknown-elf-gcc if linux one is not found
CC=riscv64-unknown-linux-gnu-gcc
if ! command -v $CC &> /dev/null
then
    CC=riscv64-unknown-elf-gcc
fi

OBJCOPY=riscv64-unknown-elf-objcopy
if ! command -v $OBJCOPY &> /dev/null
then
    OBJCOPY=riscv64-linux-gnu-objcopy
fi

echo "Using compiler: $CC"

# Compile with RVC enabled and Integer-only ABI (since FP is not yet implemented)
$CC -march=rv64imac -mabi=lp64 -static -nostdlib -T link.ld crt0.s c/rvc_test.c -o rvc_test.elf
$CC -march=rv64imac -mabi=lp64 -static -nostdlib -T link.ld rvc_test_simple.s -o rvc_simple.elf

# Compile CoreMark-FP (Requires F extension)
$CC -march=rv64imafdc -mabi=lp64d -mcmodel=medany -static -nostdlib -T link.ld c/coremark_fp.c -o coremark_fp.elf

# Extract binary
$OBJCOPY -O binary rvc_test.elf rvc_test.bin
$OBJCOPY -O binary rvc_simple.elf rvc_simple.bin
$OBJCOPY -O binary coremark_fp.elf coremark_fp.bin

# Convert to hex
hexdump -v -e '1/4 "%08x" "\n"' rvc_test.bin > hex/rvc_test.hex
hexdump -v -e '1/4 "%08x" "\n"' rvc_simple.bin > hex/rvc_simple.hex
hexdump -v -e '1/4 "%08x" "\n"' coremark_fp.bin > hex/coremark_fp.hex

# 5. RVC FP Test
$CC -march=rv64imafdc -mabi=lp64d -static -nostdlib -T link.ld c/rvc_fp.c -o rvc_fp.elf
$OBJCOPY -O binary rvc_fp.elf rvc_fp.bin
hexdump -v -e '1/4 "%08x" "\n"' rvc_fp.bin > hex/rvc_fp.hex

echo "Generated hex/rvc_test.hex, hex/rvc_simple.hex, hex/coremark_fp.hex, and hex/rvc_fp.hex"
