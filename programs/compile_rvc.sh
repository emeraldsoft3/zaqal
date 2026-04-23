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

# Extract binary
$OBJCOPY -O binary rvc_test.elf rvc_test.bin
$OBJCOPY -O binary rvc_simple.elf rvc_simple.bin

# Convert to hex
hexdump -v -e '1/4 "%08x" "\n"' rvc_test.bin > hex/rvc_test.hex
hexdump -v -e '1/4 "%08x" "\n"' rvc_simple.bin > hex/rvc_simple.hex

echo "Generated hex/rvc_test.hex and hex/rvc_simple.hex"
