package zaqal.backend.exu

import chisel3._
import chisel3.util._
import chisel3.util.HasBlackBoxInline
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.backend.devices.{CLINT, PLIC}

class DataMemDpi extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock        = Input(Clock())
    val raddr0       = Input(UInt(64.W))
    val rdata0_lo    = Output(UInt(64.W))
    val rdata0_hi    = Output(UInt(64.W))

    val raddr1       = Input(UInt(64.W))
    val rdata1_lo    = Output(UInt(64.W))
    val rdata1_hi    = Output(UInt(64.W))

    val ptw_raddr    = Input(UInt(64.W))
    val ptw_rdata    = Output(UInt(64.W))

    val waddr        = Input(UInt(64.W))
    val wdata_lo     = Output(UInt(64.W))
    val wdata_hi     = Output(UInt(64.W))

    val wen          = Input(Bool())
    val store_addr   = Input(UInt(64.W))
    val store_wdata_lo = Input(UInt(64.W))
    val store_wdata_hi = Input(UInt(64.W))
    val store_wmask  = Input(UInt(16.W))
  })

  setInline("DataMemDpi.v",
    s"""
       |import "DPI-C" function longint ram_read_dword (input longint addr);
       |import "DPI-C" function void ram_write_byte (input longint addr, input byte data);
       |
       |module DataMemDpi (
       |  input             clock,
       |  input      [63:0] raddr0,
       |  output reg [63:0] rdata0_lo,
       |  output reg [63:0] rdata0_hi,
       |  input      [63:0] raddr1,
       |  output reg [63:0] rdata1_lo,
       |  output reg [63:0] rdata1_hi,
       |  input      [63:0] ptw_raddr,
       |  output reg [63:0] ptw_rdata,
       |  input      [63:0] waddr,
       |  output reg [63:0] wdata_lo,
       |  output reg [63:0] wdata_hi,
       |  input             wen,
       |  input      [63:0] store_addr,
       |  input      [63:0] store_wdata_lo,
       |  input      [63:0] store_wdata_hi,
       |  input      [15:0] store_wmask
       |);
       |
       |`ifndef SYNTHESIS
       |  always @* begin
       |    rdata0_lo = ram_read_dword(raddr0 & 64'hfffffffffffffff8);
       |    rdata0_hi = ram_read_dword((raddr0 & 64'hfffffffffffffff8) + 64'd8);
       |    rdata1_lo = ram_read_dword(raddr1 & 64'hfffffffffffffff8);
       |    rdata1_hi = ram_read_dword((raddr1 & 64'hfffffffffffffff8) + 64'd8);
       |    ptw_rdata = ram_read_dword(ptw_raddr & 64'hfffffffffffffff8);
       |    wdata_lo  = ram_read_dword(waddr & 64'hfffffffffffffff8);
       |    wdata_hi  = ram_read_dword((waddr & 64'hfffffffffffffff8) + 64'd8);
       |  end
       |
       |  always @(posedge clock) begin
       |    if (wen) begin
       |      for (int i = 0; i < 8; i = i + 1) begin
       |        if (store_wmask[i]) begin
       |          ram_write_byte((store_addr & 64'hfffffffffffffff8) + i, store_wdata_lo[i*8 +: 8]);
       |        end
       |      end
       |      for (int i = 0; i < 8; i = i + 1) begin
       |        if (store_wmask[i + 8]) begin
       |          ram_write_byte((store_addr & 64'hfffffffffffffff8) + 8 + i, store_wdata_hi[i*8 +: 8]);
       |        end
       |      end
       |    end
       |  end

       |`else
       |  always @* begin
       |    rdata0_lo = 64'd0;
       |    rdata0_hi = 64'd0;
       |    rdata1_lo = 64'd0;
       |    rdata1_hi = 64'd0;
       |    ptw_rdata = 64'd0;
       |    wdata_lo  = 64'd0;
       |    wdata_hi  = 64'd0;
       |  end
       |`endif
       |endmodule
       |""".stripMargin
  )
}

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

    // Dedicated AMX 2D Tile Streaming Memory Ports (Phase 9)
    val amx_raddr = Input(UInt(xLen.W))
    val amx_rdata = Output(UInt(128.W))
    val amx_wen   = Input(Bool())
    val amx_waddr = Input(UInt(xLen.W))
    val amx_wdata = Input(UInt(128.W))

    // Dedicated Vector Memory Ports (Phase 9, Day 18-20)
    val vec_raddr = Input(UInt(xLen.W))
    val vec_rdata = Output(UInt(128.W))
    val vec_wen   = Input(Bool())
    val vec_waddr = Input(UInt(xLen.W))
    val vec_wdata = Input(UInt(128.W))
    val vec_wmask = Input(UInt(16.W))

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
  val memInit = Seq.fill(2048)(0.U(64.W))
  val mem = RegInit(VecInit(memInit))

  // UART registers, CLINT, PLIC and DRAM DPI-C Backing
  val dpi = Module(new DataMemDpi)
  dpi.io.clock := clock
  dpi.io.raddr0 := io.raddr(0)
  dpi.io.raddr1 := io.raddr(1)
  dpi.io.ptw_raddr := io.ptw_raddr
  dpi.io.waddr := io.addr

  val is_dram_write = io.wen && (io.addr >= "h80000000".U)
  dpi.io.wen := is_dram_write
  dpi.io.store_addr := io.addr
  dpi.io.store_wdata_lo := io.wdata(63, 0)
  dpi.io.store_wdata_hi := io.wdata(127, 64)
  dpi.io.store_wmask := io.wmask

  for (p <- 0 until 2) {
    clint.io.raddr(p) := io.raddr(p)
    plic.io.raddr(p)  := io.raddr(p)

    val is_uart_read  = io.raddr(p) >= "h10000000".U && io.raddr(p) < "h10000100".U
    val is_clint_read = clint.io.rvalid(p)
    val is_plic_read  = plic.io.rvalid(p)
    val is_dram_read  = io.raddr(p) >= "h80000000".U

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
    val dram_rdata = if (p == 0) Cat(dpi.io.rdata0_hi, dpi.io.rdata0_lo) else Cat(dpi.io.rdata1_hi, dpi.io.rdata1_lo)

    io.rdata(p) := Mux(is_uart_read, uart_r_data,
                   Mux(is_clint_read, clint.io.rdata(p),
                   Mux(is_plic_read,  plic.io.rdata(p),
                   Mux(is_dram_read,  dram_rdata, sram_r_data))))
  }

  // Basic address decoding using bits (13, 3) for 2048 doubleword capacity (16KB)
  val index = io.addr(13, 3) 
  val index_next = Mux(index === 2047.U, 0.U, index + 1.U)
  val is_store_dram = io.addr >= "h80000000".U
  val dram_wdata = Cat(dpi.io.wdata_hi, dpi.io.wdata_lo)
  io.data := Mux(is_store_dram, dram_wdata, Cat(mem(index_next), mem(index)))

  // Dedicated PTW port read
  val is_ptw_dram = io.ptw_raddr >= "h80000000".U
  io.ptw_rdata := Mux(is_ptw_dram, dpi.io.ptw_rdata, mem(io.ptw_raddr(13, 3)))

  // Masked Write Implementation (16-bit) - Protected against MMIO address space
  val bitMask = Cat(Seq.tabulate(16)(i => Fill(8, io.wmask(i))).reverse)
  val is_mmio_write = is_uart_write || 
                      (io.addr >= "h02000000".U && io.addr < "h02010000".U) || 
                      (io.addr >= "h0C000000".U && io.addr < "h0C400000".U)
  
  when(io.wen && !is_mmio_write && !is_dram_write) {
    val fullData = (io.data & ~bitMask) | (io.wdata & bitMask)
    mem(index)      := fullData(63, 0)
    mem(index_next) := fullData(127, 64)
  }

  // Dedicated AMX Port Read (128-bit)
  val amx_r_idx = io.amx_raddr(13, 3)
  val amx_r_idx_next = Mux(amx_r_idx === 2047.U, 0.U, amx_r_idx + 1.U)
  io.amx_rdata := Cat(mem(amx_r_idx_next), mem(amx_r_idx))

  // Dedicated AMX Port Write (128-bit)
  when(io.amx_wen) {
    val amx_w_idx = io.amx_waddr(13, 3)
    val amx_w_idx_next = Mux(amx_w_idx === 2047.U, 0.U, amx_w_idx + 1.U)
    mem(amx_w_idx)      := io.amx_wdata(63, 0)
    mem(amx_w_idx_next) := io.amx_wdata(127, 64)
  }

  // Dedicated Vector Port Read (128-bit)
  val vec_r_idx = io.vec_raddr(13, 3)
  val vec_r_idx_next = Mux(vec_r_idx === 2047.U, 0.U, vec_r_idx + 1.U)
  io.vec_rdata := Cat(mem(vec_r_idx_next), mem(vec_r_idx))

  // Dedicated Vector Port Write (128-bit with byte write mask)
  when(io.vec_wen) {
    val vec_w_idx = io.vec_waddr(13, 3)
    val vec_w_idx_next = Mux(vec_w_idx === 2047.U, 0.U, vec_w_idx + 1.U)
    val cur_low  = mem(vec_w_idx)
    val cur_high = mem(vec_w_idx_next)
    val cur_full = Cat(cur_high, cur_low)
    val bitMask_vec = Cat(Seq.tabulate(16)(i => Fill(8, io.vec_wmask(i))).reverse)
    val fullData_vec = (cur_full & ~bitMask_vec) | (io.vec_wdata & bitMask_vec)
    mem(vec_w_idx)      := fullData_vec(63, 0)
    mem(vec_w_idx_next) := fullData_vec(127, 64)
  }
}
