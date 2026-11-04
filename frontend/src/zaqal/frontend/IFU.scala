package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class IFU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val fetch_req    = Flipped(Decoupled(new FetchRequest)) // From FTQ (Request - metadata only)
    val toIbuffer    = Decoupled(new FetchPacket)           // To IBuffer (Direct)
    val icache_ready = Input(Bool())
    val insts_in     = Input(Vec(fetchWidth, UInt(instBits.W)))
    val flush        = Input(Bool())
  })

  // Cross-line 32-bit instruction assembly buffer
  val cross_half_reg = RegInit(0.U(16.W))
  val has_cross_half = RegInit(false.B)

  when(io.flush) {
    has_cross_half := false.B
  }

  val predecoders = Seq.fill(predictWidth)(Module(new Predecoder))
  val raw_bits = io.insts_in.asUInt

  val packet = Wire(new FetchPacket)
  packet.prediction  := io.fetch_req.bits.prediction
  packet.ftqPtr      := io.fetch_req.bits.ftqPtr
  packet.epoch       := io.fetch_req.bits.epoch

  val is_rvc = Wire(Vec(predictWidth, Bool()))
  val mask_reg = Wire(Vec(predictWidth, Bool()))

  val slot0_inst = Mux(has_cross_half, Cat(raw_bits(15, 0), cross_half_reg), raw_bits(31, 0))
  val slot0_pc   = Mux(has_cross_half, io.fetch_req.bits.pc - 2.U, io.fetch_req.bits.pc)

  for (i <- 0 until predictWidth) {
    val inst = if (i == 0) slot0_inst else (raw_bits >> (i.U * 16.U))(31, 0)
    predecoders(i).io.inst := inst
    packet.instructions(i) := inst
    packet.pre_decoded(i)  := predecoders(i).io.out
    
    packet.pc(i)             := (if (i == 0) slot0_pc else io.fetch_req.bits.pc + (i * 2).U)
    packet.exception_type(i) := 0.U
    packet.debug_seqNum(i)   := 0.U
    
    is_rvc(i) := predecoders(i).io.out.is_rvc
  }

  val raw_mask = Wire(Vec(predictWidth, Bool()))
  for (i <- 0 until predictWidth) {
    val is_entry_slot = if (i == 0) {
      has_cross_half || io.fetch_req.bits.mask(0)
    } else {
      !has_cross_half && io.fetch_req.bits.mask(i) && !io.fetch_req.bits.mask(i-1, 0).orR
    }
    val prev_was_rvc  = if (i >= 1) raw_mask(i-1) && is_rvc(i-1) else false.B
    val prev_was_32b  = if (i == 1) (has_cross_half && raw_mask(0))
                        else if (i == 2) (!has_cross_half && raw_mask(0) && !is_rvc(0))
                        else if (i >= 3) (raw_mask(i-2) && !is_rvc(i-2)) else false.B
    val valid_seq     = is_entry_slot || prev_was_rvc || prev_was_32b
    val mask_cand     = if (i == 0) (has_cross_half || io.fetch_req.bits.mask(0)) else io.fetch_req.bits.mask(i)
    raw_mask(i)       := mask_cand && valid_seq
  }

  // Slot 15 cross-line detection: if slot 15 is valid and 32-bit, it crosses into the next line
  val slot15_crosses = raw_mask(predictWidth - 1) && !is_rvc(predictWidth - 1)
  for (i <- 0 until predictWidth) {
    mask_reg(i) := (if (i == predictWidth - 1) raw_mask(i) && !slot15_crosses else raw_mask(i))
  }
  
  packet.mask := mask_reg.asUInt

  when(io.toIbuffer.fire) {
    when(slot15_crosses) {
      cross_half_reg := (raw_bits >> ((predictWidth - 1) * 16))(15, 0)
      has_cross_half := true.B
    } .elsewhen(has_cross_half) {
      has_cross_half := false.B
    }
  }

  // Pass through the handshake
  io.toIbuffer.valid := io.fetch_req.valid
  io.toIbuffer.bits  := packet
  io.fetch_req.ready := io.toIbuffer.ready && io.icache_ready
}
