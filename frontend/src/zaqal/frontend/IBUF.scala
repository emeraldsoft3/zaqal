package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class IBUF(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst_data = Flipped(Decoupled(new FetchPacket))
    val flush     = Input(Bool())
    val out       = Vec(decodeWidth, Decoupled(new MicroOp))
  })

  val ibufSize = 64
  val buffer = Reg(Vec(ibufSize, new MicroOp))
  val valid  = RegInit(VecInit.fill(ibufSize)(false.B))
  val head   = RegInit(0.U(6.W))
  val tail   = RegInit(0.U(6.W))

  val enq_mask = io.inst_data.bits.mask
  val enq_count = PopCount(enq_mask)
  val can_enq = (ibufSize.U - PopCount(valid.asUInt)) >= enq_count
  io.inst_data.ready := can_enq && !io.flush

  // Pre-calculate indices to avoid scope escape
  val offsets = (0 until predictWidth).map(i => if (i == 0) 0.U else PopCount(enq_mask(i-1, 0)))
  val indices = offsets.map(o => (tail +& o)(5, 0))

  when(io.inst_data.fire) {
    for (i <- 0 until predictWidth) {
      val idx = indices(i)
      when(enq_mask(i)) {
        val entry = Wire(new MicroOp)
        entry.pc       := io.inst_data.bits.pc(i)
        entry.inst_raw := io.inst_data.bits.instructions(i)
        entry.pre      := io.inst_data.bits.pre_decoded(i)
        entry.ftqPtr   := io.inst_data.bits.ftqPtr
        entry.epoch    := io.inst_data.bits.epoch
        entry.is_predicted_taken := io.inst_data.bits.prediction.taken && (i.U === io.inst_data.bits.prediction.slot)
        
        buffer(idx) := entry
        valid(idx) := true.B
      }
    }
    tail := (tail +& enq_count)(5, 0)
  }

  // Dequeue Logic
  val deq_fire_mask = VecInit(io.out.map(_.fire))
  val deq_count = PopCount(deq_fire_mask)

  val deq_valid_mask = (0 until decodeWidth).map { i =>
    val ptr = (head +& i.U)(5, 0)
    valid(ptr)
  }.scanLeft(true.B)(_ && _).tail

  for (i <- 0 until decodeWidth) {
    val ptr = (head +& i.U)(5, 0)
    io.out(i).valid := deq_valid_mask(i) && !io.flush
    io.out(i).bits  := buffer(ptr)
  }

  when(deq_count > 0.U) {
    for (i <- 0 until ibufSize) {
      val idx = i.U
      val fired = Mux(head +& deq_count <= ibufSize.U,
                      idx >= head && idx < head +& deq_count,
                      idx >= head || idx < (head +& deq_count)(5, 0))
      when(fired) { valid(idx) := false.B }
    }
    head := (head +& deq_count)(5, 0)
  }

  when(io.flush) {
    valid.foreach(_ := false.B)
    head := 0.U
    tail := 0.U
  }
}
