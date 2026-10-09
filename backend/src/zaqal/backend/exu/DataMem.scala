package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.backend.devices.{CLINT, PLIC}

class DataMem(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val raddr = Vec(2, Input(UInt(xLen.W)))
    val rdata = Vec(2, Output(UInt((xLen * 2).W)))
    val addr  = Input(UInt(xLen.W))
    val data  = Output(UInt((xLen * 2).W)) // Returns 128-bit window
    
    val wen   = Input(Bool())
    val wmask = Input(UInt(16.W))          // 16-bit strobe for 128 bits
    val wdata = Input(UInt((xLen * 2).W))

    // Dedicated Page Table Walker Read Port
    val ptw_raddr = Input(UInt(xLen.W))
    val ptw_rdata = Output(UInt(64.W))

    // UART 16550 Serial Console Ports (Day 14-16)
    val uart_tx_valid = Output(Bool())
    val uart_tx_char  = Output(UInt(8.W))

    // Hardware Interrupt Lines (CLINT & PLIC - Day 17-20)
    val clint_mtip   = Output(Bool())
    val clint_msip   = Output(Bool())
    val plic_meip    = Output(Bool())
    val plic_seip    = Output(Bool())
    val plic_ext_irq = Input(UInt(32.W))
  })

  // =========================================================================
  // Peripherals: CLINT and PLIC (Day 17-20)
  // =========================================================================
  val clint = Module(new CLINT)
  val plic  = Module(new PLIC(32))

  plic.io.external_sources := io.plic_ext_irq
  io.clint_mtip := clint.io.mtip
  io.clint_msip := clint.io.msip
  io.plic_meip  := plic.io.meip
  io.plic_seip  := plic.io.seip

  clint.io.wen   := io.wen
  clint.io.waddr := io.addr
  clint.io.wdata := io.wdata
  clint.io.wmask := io.wmask

  plic.io.wen   := io.wen
  plic.io.waddr := io.addr
  plic.io.wdata := io.wdata
  plic.io.wmask := io.wmask

  // =========================================================================
  // UART 16550 Serial Peripheral (MMIO Base 0x10000000 - 0x100000FF)
  // =========================================================================
  val r_uart_ier = RegInit(0.U(8.W))
  val r_uart_lcr = RegInit("h03".U(8.W))
  val r_uart_mcr = RegInit(0.U(8.W))
  val r_uart_scr = RegInit(0.U(8.W))

  val is_uart_write = io.wen && (io.addr >= "h10000000".U && io.addr < "h10000100".U)
  val uart_w_offset = io.addr(7, 0)
  val uart_w_lane   = io.addr(2, 0)
  val uart_w_byte   = (io.wdata >> (uart_w_lane << 3))(7, 0)

  val uart_tx_fire  = is_uart_write && (uart_w_offset === 0.U)
  io.uart_tx_valid  := uart_tx_fire
  io.uart_tx_char   := uart_w_byte

  when(is_uart_write) {
    switch(uart_w_offset) {
      is(0.U) {
        printf("[UART CONSOLE]: %c (ASCII 0x%x)\n", uart_w_byte, uart_w_byte)
      }
      is(1.U) { r_uart_ier := uart_w_byte }
      is(3.U) { r_uart_lcr := uart_w_byte }
      is(4.U) { r_uart_mcr := uart_w_byte }
      is(7.U) { r_uart_scr := uart_w_byte }
    }
  }

  // Memory uses RegInit to allow persistent writes
  // mem has 2048 entries (16KB) to support 3-level page tables:
  // Page 0 (0x0000 - 0x0FF8): Root Level 2 Page Table (PPN=0)
  // Page 1 (0x1000 - 0x1FF8): Level 1 Page Table (PPN=1)
  // Page 2 (0x2000 - 0x2FF8): Level 0 Page Table (PPN=2)
  val memInit = Seq.tabulate(2048) { i =>
    if (i == 0) "h00000000200000DF".U(64.W)       // 0x0000: Sv39 1GB Root Leaf PTE for VPN[2]=0 -> PA 0x80000000 (Test 1)
    else if (i == 1) "h0000000000000401".U(64.W) // 0x0008: Sv39 Level 2 Pointer PTE for VPN[2]=1 -> Points to Level 1 table at PPN=1 (0x1000) (Tests 2 & 3)
    else if (i == 2) "hFFEEDDCCBBAA9988".U(64.W) // 0x0010: Test 1 loaded data (at PA 0x80000010)
    else if (i == 3) "h706050403020100F".U(64.W) // 0x0018: Offset test
    else if (i == 4) "h1122334455667788".U(64.W) // 0x0020: Test 2 loaded data (at PA 0x80000020)
    else if (i == 6) "hAABBCCDDEEFF0011".U(64.W) // 0x0030: Test 3 loaded data (at PA 0x80000030)
    else if (i == 513) "h00000000200000DF".U(64.W) // 0x1008: Sv39 Level 1 2MB Megapage Leaf PTE for VPN[1]=1 -> PA 0x80000000 (Test 2)
    else if (i == 514) "h0000000000000801".U(64.W) // 0x1010: Sv39 Level 1 Pointer PTE for VPN[1]=2 -> Points to Level 0 table at PPN=2 (0x2000) (Test 3)
    else if (i == 515) "h0000000020000059".U(64.W) // 0x1018: Sv39 Level 1 2MB Execute-Only Leaf PTE (R=0, X=1, V=1) for VPN[1]=3 (Test 6 Permission Violation)
    else if (i == 1025) "h00000000200000DF".U(64.W) // 0x2008: Sv39 Level 0 4KB Standard Page Leaf PTE for VPN[0]=1 -> PA 0x80000000 (Test 3)
    else 0.U(64.W)
  }
  val mem = RegInit(VecInit(memInit))

  for (p <- 0 until 2) {
    clint.io.raddr(p) := io.raddr(p)
    plic.io.raddr(p)  := io.raddr(p)

    val is_uart_read  = io.raddr(p) >= "h10000000".U && io.raddr(p) < "h10000100".U
    val is_clint_read = clint.io.rvalid(p)
    val is_plic_read  = plic.io.rvalid(p)

    val uart_r_offset = io.raddr(p)(7, 0)
    val uart_r_byte = MuxLookup(uart_r_offset, 0.U(8.W))(Seq(
      0.U -> 0.U(8.W),     // RBR (empty)
      1.U -> r_uart_ier,   // IER
      2.U -> "h01".U(8.W), // IIR (no interrupt)
      3.U -> r_uart_lcr,   // LCR
      4.U -> r_uart_mcr,   // MCR
      5.U -> "h60".U(8.W), // LSR (0x60 = TEMT | THRE: Transmitter Empty and Ready)
      7.U -> r_uart_scr    // SCR
    ))
    val uart_r_data = (uart_r_byte.pad(128)) << (io.raddr(p)(2, 0) << 3)

    val idx = io.raddr(p)(13, 3)
    val idx_next = Mux(idx === 2047.U, 0.U, idx + 1.U)
    val sram_r_data = Cat(mem(idx_next), mem(idx))

    io.rdata(p) := Mux(is_uart_read, uart_r_data,
                   Mux(is_clint_read, clint.io.rdata(p),
                   Mux(is_plic_read,  plic.io.rdata(p), sram_r_data)))
  }

  // Basic address decoding using bits (13, 3) for 2048 doubleword capacity (16KB)
  val index = io.addr(13, 3) 
  val index_next = Mux(index === 2047.U, 0.U, index + 1.U)
  io.data := Cat(mem(index_next), mem(index))

  // Dedicated PTW port read
  io.ptw_rdata := mem(io.ptw_raddr(13, 3))

  // Masked Write Implementation (16-bit) - Protected against MMIO address space
  val bitMask = Cat(Seq.tabulate(16)(i => Fill(8, io.wmask(i))).reverse)
  val is_mmio_write = is_uart_write || 
                      (io.addr >= "h02000000".U && io.addr < "h02010000".U) || 
                      (io.addr >= "h0C000000".U && io.addr < "h0C400000".U)
  
  when(io.wen && !is_mmio_write) {
    val fullData = (io.data & ~bitMask) | (io.wdata & bitMask)
    mem(index)      := fullData(63, 0)
    mem(index_next) := fullData(127, 64)
    
    printf(p"DATA MEM WRITE: addr=${Hexadecimal(io.addr)} index=$index wmask=${Binary(io.wmask)}\n")
    printf(p"                index=${index} data=${Hexadecimal(fullData(63,0))}\n")
    printf(p"                index=${index_next} data=${Hexadecimal(fullData(127,64))}\n")
  }
}
