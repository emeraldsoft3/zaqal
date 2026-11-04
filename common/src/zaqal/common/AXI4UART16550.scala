package zaqal.common

import chisel3._
import chisel3.util._

/**
  * Standard 16550-Compatible Serial UART AXI4 Peripheral
  *
  * Registers (offset from base address 0x10000000):
  * - 0x00: RBR (Receiver Buffer, Read) / THR (Transmitter Holding, Write)
  * - 0x01: IER (Interrupt Enable Register)
  * - 0x02: IIR (Interrupt Identification, Read) / FCR (FIFO Control, Write)
  * - 0x03: LCR (Line Control Register)
  * - 0x04: MCR (Modem Control Register)
  * - 0x05: LSR (Line Status Register - bit 5 THRE, bit 6 TEMT)
  * - 0x06: MSR (Modem Status Register)
  * - 0x07: SCR (Scratchpad Register)
  */
class AXI4UART16550(val config: AXI4Config) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new AXI4Bundle(config))

    // Hardware Console Pins
    val tx_valid = Output(Bool())
    val tx_char  = Output(UInt(8.W))
    val irq      = Output(Bool())
  })

  // 16550 Registers
  val r_ier = RegInit(0.U(8.W))
  val r_lcr = RegInit("h03".U(8.W)) // 8 data bits, 1 stop bit, no parity
  val r_mcr = RegInit(0.U(8.W))
  val r_scr = RegInit(0.U(8.W))

  // LSR defaults: Transmitter empty (TEMT=1, bit 6) and Holding Register empty (THRE=1, bit 5)
  val r_lsr = Cat(0.U(1.W), 1.U(1.W), 1.U(1.W), 0.U(5.W)) // 0x60

  // =========================================================================
  // 1. AXI4 WRITE LOGIC
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

  val reg_offset = w_addr(2, 0)
  val w_data_byte = (io.in.w.bits.data >> (reg_offset << 3))(7, 0)

  val tx_pulse = WireDefault(false.B)
  val tx_byte  = WireDefault(0.U(8.W))

  when(io.in.w.fire) {
    switch(reg_offset) {
      is(0.U) {
        // Write to Transmitter Holding Register (THR)
        tx_pulse := true.B
        tx_byte  := w_data_byte
        printf("[UART CONSOLE]: %c (ASCII 0x%x)\n", w_data_byte, w_data_byte)
      }
      is(1.U) { r_ier := w_data_byte }
      is(3.U) { r_lcr := w_data_byte }
      is(4.U) { r_mcr := w_data_byte }
      is(7.U) { r_scr := w_data_byte }
    }
    w_state := sW_RESP
  }

  io.tx_valid := tx_pulse
  io.tx_char  := tx_byte
  io.irq      := false.B

  io.in.b.valid     := (w_state === sW_RESP)
  io.in.b.bits.id   := w_id
  io.in.b.bits.resp := AXI4Parameters.RESP_OKAY

  when(io.in.b.fire) {
    w_state := sW_IDLE
  }

  // =========================================================================
  // 2. AXI4 READ LOGIC
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

  val r_offset = r_addr(2, 0)
  val r_byte = MuxLookup(r_offset, 0.U(8.W))(Seq(
    0.U -> 0.U(8.W),     // RBR (empty FIFO)
    1.U -> r_ier,        // IER
    2.U -> "h01".U(8.W), // IIR: No interrupt pending
    3.U -> r_lcr,        // LCR
    4.U -> r_mcr,        // MCR
    5.U -> r_lsr,        // LSR: THRE and TEMT ready
    6.U -> 0.U(8.W),     // MSR
    7.U -> r_scr         // SCR
  ))

  val r_data_shifted = (r_byte.pad(config.dataWidth)) << (r_offset << 3)

  io.in.r.valid     := (r_state === sR_RESP)
  io.in.r.bits.id   := r_id
  io.in.r.bits.data := r_data_shifted
  io.in.r.bits.resp := AXI4Parameters.RESP_OKAY
  io.in.r.bits.last := true.B

  when(io.in.r.fire) {
    r_state := sR_IDLE
  }
}
