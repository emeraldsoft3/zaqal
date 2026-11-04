package zaqal.common

import chisel3._
import chisel3.util._

/**
  * High-Performance AXI4 Synchronous SRAM / DRAM Controller Model
  *
  * Features:
  * - Multi-beat INCR burst read support with automatic address progression.
  * - Multi-beat masked write burst support using byte strobes (wstrb).
  * - Compliant with AMBA AXI4 standard (rlast, wlast, bresp, rresp).
  */
class AXI4RAM(
  val config:      AXI4Config,
  val memSizeBytes: BigInt = 16 * 1024 * 1024 // 16 MB default
) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new AXI4Bundle(config))
  })

  val bytesPerBeat = config.strbWidth
  val numWords     = (memSizeBytes / bytesPerBeat).toInt
  val addrOffsetBits = log2Ceil(bytesPerBeat)

  // Doubleword/Word storage
  val mem = Mem(numWords, Vec(bytesPerBeat, UInt(8.W)))

  // =========================================================================
  // 1. READ ENGINE (AR -> R)
  // =========================================================================
  val sR_IDLE :: sR_BURST :: Nil = Enum(2)
  val r_state    = RegInit(sR_IDLE)
  val r_id       = RegInit(0.U(config.idWidth.W))
  val r_addr     = RegInit(0.U(config.addrWidth.W))
  val r_len      = RegInit(0.U(8.W))
  val r_beat_cnt = RegInit(0.U(8.W))

  val r_word_idx = (r_addr >> addrOffsetBits)(log2Ceil(numWords) - 1, 0)
  val r_data_vec = mem.read(r_word_idx)
  val r_data_out = Cat(r_data_vec.reverse)

  io.in.ar.ready := (r_state === sR_IDLE)

  when(io.in.ar.fire) {
    r_id       := io.in.ar.bits.id
    r_addr     := io.in.ar.bits.addr
    r_len      := io.in.ar.bits.len
    r_beat_cnt := 0.U
    r_state    := sR_BURST
  }

  val r_is_last = (r_beat_cnt === r_len)
  io.in.r.valid := (r_state === sR_BURST)
  io.in.r.bits.id   := r_id
  io.in.r.bits.data := r_data_out
  io.in.r.bits.resp := AXI4Parameters.RESP_OKAY
  io.in.r.bits.last := r_is_last

  when(io.in.r.fire) {
    r_addr     := r_addr + bytesPerBeat.U
    r_beat_cnt := r_beat_cnt + 1.U
    when(r_is_last) {
      r_state := sR_IDLE
    }
  }

  // =========================================================================
  // 2. WRITE ENGINE (AW + W -> B)
  // =========================================================================
  val sW_IDLE :: sW_DATA :: sW_RESP :: Nil = Enum(3)
  val w_state    = RegInit(sW_IDLE)
  val w_id       = RegInit(0.U(config.idWidth.W))
  val w_addr     = RegInit(0.U(config.addrWidth.W))
  val w_len      = RegInit(0.U(8.W))
  val w_beat_cnt = RegInit(0.U(8.W))

  io.in.aw.ready := (w_state === sW_IDLE)
  io.in.w.ready  := (w_state === sW_DATA)

  when(io.in.aw.fire) {
    w_id       := io.in.aw.bits.id
    w_addr     := io.in.aw.bits.addr
    w_len      := io.in.aw.bits.len
    w_beat_cnt := 0.U
    w_state    := sW_DATA
  }

  val w_word_idx = (w_addr >> addrOffsetBits)(log2Ceil(numWords) - 1, 0)
  val w_bytes_in = VecInit((0 until bytesPerBeat).map(b => io.in.w.bits.data(8 * b + 7, 8 * b)))
  val w_mask_vec = VecInit((0 until bytesPerBeat).map(b => io.in.w.bits.strb(b).asBool))

  when(io.in.w.fire) {
    mem.write(w_word_idx, w_bytes_in, w_mask_vec)
    w_addr     := w_addr + bytesPerBeat.U
    w_beat_cnt := w_beat_cnt + 1.U

    when(io.in.w.bits.last || (w_beat_cnt === w_len)) {
      w_state := sW_RESP
    }
  }

  io.in.b.valid     := (w_state === sW_RESP)
  io.in.b.bits.id   := w_id
  io.in.b.bits.resp := AXI4Parameters.RESP_OKAY

  when(io.in.b.fire) {
    w_state := sW_IDLE
  }
}
