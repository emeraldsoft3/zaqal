package zaqal.common

import chisel3._
import chisel3.util._

/**
  * Standard Memory-Mapped SPI Controller with AXI4 Interface
  * Supports SPI Flash and SD-Card communication.
  *
  * Register Map (offset from base address, e.g. 0x10040000 / 0x20000000):
  * - 0x00: SPICR  - SPI Control Register (bit 0: SPE enable, bit 1: Master, bit 2: CPOL, bit 3: CPHA)
  * - 0x04: SPISR  - SPI Status Register  (bit 0: TX_FULL, bit 1: TX_EMPTY, bit 2: RX_EMPTY, bit 3: RX_FULL, bit 4: BUSY)
  * - 0x08: SPIDR  - SPI Data Register    (Write: TX FIFO, Read: RX FIFO)
  * - 0x0C: SPISSR - Slave Select Register (active-low chip select bits for SPI devices)
  * - 0x10: SPIDIV - Clock Divisor Register
  */
class AXI4SPI(val config: AXI4Config) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new AXI4Bundle(config))

    // Physical SPI Pins
    val sck  = Output(Bool())
    val mosi = Output(Bool())
    val miso = Input(Bool())
    val cs_n = Output(UInt(4.W))

    val irq  = Output(Bool())
  })

  // Registers
  val r_spicr  = RegInit(3.U(8.W))       // SPE=1, Master=1 by default
  val r_spissr = RegInit("h0f".U(4.W))   // All CS de-asserted (active-low)
  val r_spidiv = RegInit(4.U(8.W))       // Clock divider

  // FIFOs
  val tx_fifo = Module(new Queue(UInt(8.W), entries = 8))
  val rx_fifo = Module(new Queue(UInt(8.W), entries = 8))

  // SPI Shift Engine
  val sSPI_IDLE :: sSPI_TRANSFER :: Nil = Enum(2)
  val spi_state   = RegInit(sSPI_IDLE)
  val bit_cnt     = RegInit(0.U(3.W))
  val clk_cnt     = RegInit(0.U(8.W))
  val tx_shift    = RegInit(0.U(8.W))
  val rx_shift    = RegInit(0.U(8.W))
  val sck_reg     = RegInit(false.B)

  val busy = (spi_state =/= sSPI_IDLE) || tx_fifo.io.deq.valid

  // SPI Transfer Sequencer
  tx_fifo.io.deq.ready := (spi_state === sSPI_IDLE) && tx_fifo.io.deq.valid
  rx_fifo.io.enq.valid := false.B
  rx_fifo.io.enq.bits  := rx_shift

  when(spi_state === sSPI_IDLE) {
    sck_reg := false.B
    when(tx_fifo.io.deq.fire) {
      tx_shift  := tx_fifo.io.deq.bits
      bit_cnt   := 7.U
      clk_cnt   := 0.U
      spi_state := sSPI_TRANSFER
    }
  }.elsewhen(spi_state === sSPI_TRANSFER) {
    when(clk_cnt >= r_spidiv) {
      clk_cnt := 0.U
      when(!sck_reg) {
        // SCK Rising Edge: Sample MISO
        sck_reg  := true.B
        rx_shift := Cat(rx_shift(6, 0), io.miso)
      }.otherwise {
        // SCK Falling Edge: Shift next MOSI bit
        sck_reg := false.B
        when(bit_cnt === 0.U) {
          rx_fifo.io.enq.valid := true.B
          spi_state := sSPI_IDLE
        }.otherwise {
          bit_cnt  := bit_cnt - 1.U
          tx_shift := Cat(tx_shift(6, 0), 0.U(1.W))
        }
      }
    }.otherwise {
      clk_cnt := clk_cnt + 1.U
    }
  }

  io.sck  := sck_reg
  io.mosi := tx_shift(7)
  io.cs_n := r_spissr
  io.irq  := rx_fifo.io.deq.valid

  val status = Cat(
    0.U(3.W),
    busy,
    !rx_fifo.io.enq.ready,
    !rx_fifo.io.deq.valid,
    !tx_fifo.io.deq.valid,
    !tx_fifo.io.enq.ready
  )

  // =========================================================================
  // AXI4 WRITE CHANNEL
  // =========================================================================
  val sW_IDLE :: sW_DATA :: sW_RESP :: Nil = Enum(3)
  val w_state = RegInit(sW_IDLE)
  val w_id    = RegInit(0.U(config.idWidth.W))
  val w_addr  = RegInit(0.U(config.addrWidth.W))

  io.in.aw.ready := (w_state === sW_IDLE)
  io.in.w.ready  := (w_state === sW_DATA)

  when(io.in.aw.fire) {
    w_id    := io.in.aw.bits.id
    w_addr  := io.in.aw.bits.addr
    w_state := sW_DATA
  }

  tx_fifo.io.enq.valid := false.B
  tx_fifo.io.enq.bits  := io.in.w.bits.data(7, 0)

  when(io.in.w.fire) {
    val reg_offset = w_addr(4, 0)
    switch(reg_offset) {
      is("h00".U) { r_spicr  := io.in.w.bits.data(7, 0) }
      is("h08".U) { tx_fifo.io.enq.valid := true.B }
      is("h0C".U) { r_spissr := io.in.w.bits.data(3, 0) }
      is("h10".U) { r_spidiv := io.in.w.bits.data(7, 0) }
    }
    w_state := sW_RESP
  }

  io.in.b.valid     := (w_state === sW_RESP)
  io.in.b.bits.id   := w_id
  io.in.b.bits.resp := AXI4Parameters.RESP_OKAY

  when(io.in.b.fire) {
    w_state := sW_IDLE
  }

  // =========================================================================
  // AXI4 READ CHANNEL
  // =========================================================================
  val sR_IDLE :: sR_RESP :: Nil = Enum(2)
  val r_state = RegInit(sR_IDLE)
  val r_id    = RegInit(0.U(config.idWidth.W))
  val r_addr  = RegInit(0.U(config.addrWidth.W))

  io.in.ar.ready := (r_state === sR_IDLE)

  when(io.in.ar.fire) {
    r_id    := io.in.ar.bits.id
    r_addr  := io.in.ar.bits.addr
    r_state := sR_RESP
  }

  rx_fifo.io.deq.ready := false.B
  val r_word = WireDefault(0.U(32.W))
  val r_offset = r_addr(4, 0)

  switch(r_offset) {
    is("h00".U) { r_word := r_spicr }
    is("h04".U) { r_word := status }
    is("h08".U) {
      when(r_state === sR_RESP && io.in.r.fire) {
        rx_fifo.io.deq.ready := true.B
      }
      r_word := rx_fifo.io.deq.bits
    }
    is("h0C".U) { r_word := r_spissr }
    is("h10".U) { r_word := r_spidiv }
  }

  io.in.r.valid     := (r_state === sR_RESP)
  io.in.r.bits.id   := r_id
  io.in.r.bits.data := r_word.pad(config.dataWidth)
  io.in.r.bits.resp := AXI4Parameters.RESP_OKAY
  io.in.r.bits.last := true.B

  when(io.in.r.fire) {
    r_state := sR_IDLE
  }
}
