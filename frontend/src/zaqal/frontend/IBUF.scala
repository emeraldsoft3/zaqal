package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class IBUF(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst_data = Flipped(Decoupled(new FetchPacket)) // From IFU
    val flush     = Input(Bool())
    val out       = Vec(decodeWidth, Decoupled(new MicroOp)) // To Backend (6-wide)
  })

  // IBuffer Parameters
  val ibufSize = 64 // Capacity in instructions

  // Storage (Register-based for multi-wide async read)
  val buffer = Reg(Vec(ibufSize, new MicroOp))
  val valid  = RegInit(VecInit.fill(ibufSize)(false.B))
  
  val head = RegInit(0.U(log2Up(ibufSize).W))
  val tail = RegInit(0.U(log2Up(ibufSize).W))

  // 1. ENQUEUE LOGIC (XiangShan style - Distributed Write)
  val enq_mask = io.inst_data.bits.mask
  val enq_count = PopCount(enq_mask)
  
  val can_enq = (ibufSize.U - PopCount(valid.asUInt)) >= enq_count
  io.inst_data.ready := can_enq && !io.flush

  // Pre-calculate internal offsets for each slot in the incoming packet
  val enq_offsets = Wire(Vec(predictWidth, UInt(log2Up(predictWidth + 1).W)))
  for (i <- 0 until predictWidth) {
    if (i == 0) enq_offsets(i) := 0.U
    else enq_offsets(i) := PopCount(enq_mask(i-1, 0))
  }

  for (idx <- 0 until ibufSize) {
    val entry_match_mask = Wire(Vec(predictWidth, Bool()))
    for (i <- 0 until predictWidth) {
      entry_match_mask(i) := io.inst_data.fire && enq_mask(i) && ((tail + enq_offsets(i)) % ibufSize.U === idx.U)
    }
    
    val wen = entry_match_mask.asUInt.orR
    when(wen) {
      val sel = PriorityEncoder(entry_match_mask)
      val entry = Wire(new MicroOp)
      entry.pc       := io.inst_data.bits.pc(sel)
      entry.inst_raw := io.inst_data.bits.instructions(sel)
      entry.pre      := io.inst_data.bits.pre_decoded(sel)
      entry.ftqPtr   := io.inst_data.bits.ftqPtr
      entry.epoch    := io.inst_data.bits.epoch
      
      val is_pred_taken = io.inst_data.bits.prediction.taken && (sel === io.inst_data.bits.prediction.slot)
      entry.is_predicted_taken := is_pred_taken

      buffer(idx) := entry
      valid(idx)  := true.B
    }
  }

  when(io.inst_data.fire) {
    tail := (tail + enq_count) % ibufSize.U
  }

  // 2. DEQUEUE LOGIC (Banked Parallel Read)
  val deq_potential_mask = Wire(Vec(decodeWidth, Bool()))
  for (i <- 0 until decodeWidth) {
    val ptr = (head + i.U) % ibufSize.U
    deq_potential_mask(i) := valid(ptr)
  }

  // Strict ordered dequeue: Slot i is valid only if [0...i-1] were also valid
  val deq_valid_mask = Wire(Vec(decodeWidth, Bool()))
  deq_valid_mask(0) := deq_potential_mask(0)
  for (i <- 1 until decodeWidth) {
    deq_valid_mask(i) := deq_valid_mask(i-1) && deq_potential_mask(i)
  }

  for (i <- 0 until decodeWidth) {
    val ptr = (head + i.U) % ibufSize.U
    io.out(i).valid := deq_valid_mask(i) && !io.flush
    io.out(i).bits  := buffer(ptr)
  }

  val deq_fire_mask = VecInit(io.out.map(_.fire))
  val deq_count = PopCount(deq_fire_mask)

  when(deq_count > 0.U) {
    for (i <- 0 until ibufSize) {
      val idx = i.U
      val fired = Mux(head + deq_count <= ibufSize.U,
                      idx >= head && idx < head + deq_count,
                      idx >= head || idx < (head + deq_count) % ibufSize.U)
      when(fired) {
        valid(i) := false.B
      }
    }
    head := (head + deq_count) % ibufSize.U
  }

  // 3. FLUSH LOGIC
  when(io.flush) {
    head := 0.U
    tail := 0.U
    for (i <- 0 until ibufSize) {
      valid(i) := false.B
    }
  }
}
