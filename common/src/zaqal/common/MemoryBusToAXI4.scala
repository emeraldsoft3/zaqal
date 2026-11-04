package zaqal.common

import chisel3._
import chisel3.util._

/**
  * MemoryBus to AMBA AXI4 Protocol Bridge
  *
  * Translates wide internal cache refill requests (e.g. 256-bit cache line)
  * into standard multi-beat AXI4 burst transactions (e.g. 4 beats x 64-bit).
  */
class MemoryBusToAXI4(
  val memAddrWidth: Int = 64,
  val memDataWidth: Int = 256,
  val axiConfig:    AXI4Config = AXI4Config(addrWidth = 64, dataWidth = 64, idWidth = 4)
) extends Module {
  val io = IO(new Bundle {
    val mem = Flipped(new MemoryBus(memAddrWidth, memDataWidth))
    val axi = new AXI4Bundle(axiConfig)
  })

  val beatsPerLine = memDataWidth / axiConfig.dataWidth
  val axiSizeBytes = log2Ceil(axiConfig.strbWidth) // e.g. 3 for 64-bit

  // Default tie-offs
  io.axi.aw.bits.lock  := false.B
  io.axi.aw.bits.cache := AXI4Parameters.CACHE_MODIFIABLE
  io.axi.aw.bits.prot  := AXI4Parameters.PROT_PRIVILEGED
  io.axi.aw.bits.qos   := 0.U

  io.axi.ar.bits.lock  := false.B
  io.axi.ar.bits.cache := AXI4Parameters.CACHE_MODIFIABLE
  io.axi.ar.bits.prot  := AXI4Parameters.PROT_PRIVILEGED
  io.axi.ar.bits.qos   := 0.U

  // =========================================================================
  // 1. READ CHANNEL ADAPTER (AR + R)
  // =========================================================================
  val sR_IDLE :: sR_AR :: sR_BURST :: sR_RESP :: Nil = Enum(4)
  val r_state    = RegInit(sR_IDLE)
  val r_addr     = RegInit(0.U(memAddrWidth.W))
  val r_beat_cnt = RegInit(0.U(log2Up(beatsPerLine + 1).W))
  val r_buffer   = Reg(Vec(beatsPerLine, UInt(axiConfig.dataWidth.W)))

  io.mem.req.ready := (r_state === sR_IDLE) && !io.mem.req.bits.isWrite

  when(io.mem.req.fire && !io.mem.req.bits.isWrite) {
    r_addr     := io.mem.req.bits.addr
    r_beat_cnt := 0.U
    r_state    := sR_AR
  }

  // Drive AR Channel
  io.axi.ar.valid     := (r_state === sR_AR)
  io.axi.ar.bits.id   := 0.U
  io.axi.ar.bits.addr := r_addr
  io.axi.ar.bits.len  := (beatsPerLine - 1).U
  io.axi.ar.bits.size := axiSizeBytes.U
  io.axi.ar.bits.burst := AXI4Parameters.BURST_INCR

  when(io.axi.ar.fire) {
    r_state := sR_BURST
  }

  // Collect R beats into wide buffer
  io.axi.r.ready := (r_state === sR_BURST)

  when(io.axi.r.fire) {
    r_buffer(r_beat_cnt(log2Ceil(beatsPerLine) - 1, 0)) := io.axi.r.bits.data
    r_beat_cnt := r_beat_cnt + 1.U

    when(io.axi.r.bits.last || (r_beat_cnt === (beatsPerLine - 1).U)) {
      r_state := sR_RESP
    }
  }

  // Drive Response back to MemoryBus
  io.mem.resp.valid     := (r_state === sR_RESP)
  io.mem.resp.bits.data := Cat(r_buffer.reverse)
  io.mem.resp.bits.last := true.B

  when(io.mem.resp.fire) {
    r_state := sR_IDLE
  }

  // =========================================================================
  // 2. WRITE CHANNEL ADAPTER (AW + W + B) - for D-Cache Line Eviction
  // =========================================================================
  val sW_IDLE :: sW_AW :: sW_BURST :: sW_RESP :: Nil = Enum(4)
  val w_state    = RegInit(sW_IDLE)
  val w_addr     = RegInit(0.U(memAddrWidth.W))
  val w_beat_cnt = RegInit(0.U(log2Up(beatsPerLine + 1).W))

  // Tie off for read-only if not in write
  io.axi.aw.valid     := (w_state === sW_AW)
  io.axi.aw.bits.id   := 0.U
  io.axi.aw.bits.addr := w_addr
  io.axi.aw.bits.len  := (beatsPerLine - 1).U
  io.axi.aw.bits.size := axiSizeBytes.U
  io.axi.aw.bits.burst := AXI4Parameters.BURST_INCR

  io.axi.w.valid     := (w_state === sW_BURST)
  io.axi.w.bits.data := 0.U
  io.axi.w.bits.strb := Fill(axiConfig.strbWidth, 1.U(1.W))
  io.axi.w.bits.last := (w_beat_cnt === (beatsPerLine - 1).U)

  io.axi.b.ready     := (w_state === sW_RESP)

  when(w_state === sW_AW && io.axi.aw.fire) {
    w_state := sW_BURST
  }
  when(w_state === sW_BURST && io.axi.w.fire) {
    w_beat_cnt := w_beat_cnt + 1.U
    when(w_beat_cnt === (beatsPerLine - 1).U) {
      w_state := sW_RESP
    }
  }
  when(w_state === sW_RESP && io.axi.b.fire) {
    w_state := sW_IDLE
  }
}
