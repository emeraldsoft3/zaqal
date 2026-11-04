package zaqal.common

import chisel3._
import chisel3.util._

/**
  * Standard AXI4 Boot ROM module
  * Pre-loaded with reset vector instructions (e.g. jump to DRAM 0x80000000).
  */
class AXI4ROM(val config: AXI4Config, val romSizeBytes: Int = 4096) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new AXI4Bundle(config))
  })

  // Read-only memory: Writes respond with OKAY or SLVERR without changing contents
  val sW_IDLE :: sW_DATA :: sW_RESP :: Nil = Enum(3)
  val w_state = RegInit(sW_IDLE)
  val w_id    = RegInit(0.U(config.idWidth.W))

  io.in.aw.ready := (w_state === sW_IDLE)
  io.in.w.ready  := (w_state === sW_DATA)

  when(io.in.aw.fire) {
    w_id    := io.in.aw.bits.id
    w_state := sW_DATA
  }
  when(io.in.w.fire) {
    w_state := sW_RESP
  }

  io.in.b.valid     := (w_state === sW_RESP)
  io.in.b.bits.id   := w_id
  io.in.b.bits.resp := AXI4Parameters.RESP_OKAY

  when(io.in.b.fire) {
    w_state := sW_IDLE
  }

  // ROM Read Channel
  // Pre-load simple reset boot code:
  // 0x00: 0x00000297  auipc t0, 0
  // 0x04: 0x0182b283  ld t0, 24(t0) -> loads target address from 0x18
  // 0x08: 0x00028067  jr t0
  // 0x0C: 0x00000013  nop
  // 0x10: 0x00000013  nop
  // 0x14: 0x00000013  nop
  // 0x18: 0x80000000 (Target DRAM start address in 64-bit)
  val numWords = (romSizeBytes / 8).max(8)
  val defaultWords = Seq.tabulate(numWords) { i =>
    if (i == 0) BigInt("0182b28300000297", 16) // [auipc t0, 0] [ld t0, 24(t0)]
    else if (i == 1) BigInt("0000001300028067", 16) // [jr t0] [nop]
    else if (i == 3) BigInt("0000000080000000", 16) // Target DRAM address 0x80000000
    else BigInt(0)
  }

  val rom = VecInit(defaultWords.map(_.U(64.W)))

  val sR_IDLE :: sR_BURST :: Nil = Enum(2)
  val r_state = RegInit(sR_IDLE)
  val r_id    = RegInit(0.U(config.idWidth.W))
  val r_addr  = RegInit(0.U(config.addrWidth.W))
  val r_len   = RegInit(0.U(8.W))
  val r_count = RegInit(0.U(8.W))

  io.in.ar.ready := (r_state === sR_IDLE)

  when(io.in.ar.fire) {
    r_id    := io.in.ar.bits.id
    r_addr  := io.in.ar.bits.addr
    r_len   := io.in.ar.bits.len
    r_count := 0.U
    r_state := sR_BURST
  }

  val word_idx = (r_addr >> 3) % numWords.U

  io.in.r.valid     := (r_state === sR_BURST)
  io.in.r.bits.id   := r_id
  io.in.r.bits.data := rom(word_idx)
  io.in.r.bits.resp := AXI4Parameters.RESP_OKAY
  io.in.r.bits.last := (r_count === r_len)

  when(io.in.r.fire) {
    when(r_count === r_len) {
      r_state := sR_IDLE
    }.otherwise {
      r_count := r_count + 1.U
      r_addr  := r_addr + 8.U
    }
  }
}
