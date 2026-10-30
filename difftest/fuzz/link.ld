OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY {
  RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 16M
}

SECTIONS {
  . = 0x80000000;

  .text.init : {
    *(.text.init)
  } > RAM

  .text : {
    *(.text .text.*)
  } > RAM

  .rodata : {
    *(.rodata .rodata.*)
  } > RAM

  .data : {
    *(.data .data.*)
    *(.sdata .sdata.*)
  } > RAM

  .bss : {
    __bss_start = .;
    *(.bss .bss.*)
    *(.sbss .sbss.*)
    __bss_end = .;
  } > RAM

  . = ALIGN(0x1000);
  .tohost : {
    *(.tohost)
  } > RAM

  . = ALIGN(16);
  .scratchpad (NOLOAD) : {
    _scratchpad_start = .;
    . += 0x10000; /* 64KB safe scratchpad for loads and stores */
    _scratchpad_end = .;
  } > RAM

  .stack (NOLOAD) : {
    . = ALIGN(16);
    . += 0x10000; /* 64KB stack */
    _stack_top = .;
  } > RAM

  _end = .;
}
