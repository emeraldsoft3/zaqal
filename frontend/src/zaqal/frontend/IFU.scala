package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class IFU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val fetch_req  = Flipped(Decoupled(new FetchRequest)) // From FTQ (Request - metadata only)
    val toIbuffer  = Decoupled(new FetchPacket)         // To IBuffer (Direct)
    val icache_ready = Input(Bool())
    val insts_in     = Input(Vec(fetchWidth, UInt(instBits.W)))
  })

  // IFU Logic: Take PC from FTQ
  val predecoders = Seq.fill(predictWidth)(Module(new Predecoder))
  val raw_bits = io.insts_in.asUInt

  val packet = Wire(new FetchPacket)
  packet.prediction  := io.fetch_req.bits.prediction
  packet.ftqPtr      := io.fetch_req.bits.ftqPtr
  packet.epoch       := io.fetch_req.bits.epoch

  val is_rvc = Wire(Vec(predictWidth, Bool()))
  val mask_reg = Wire(Vec(predictWidth, Bool()))

  for (i <- 0 until predictWidth) {
    val shift_amt = i.U * 16.U
    val inst_window = (raw_bits >> shift_amt)(31, 0)
    
    predecoders(i).io.inst := inst_window
    packet.instructions(i) := inst_window
    packet.pre_decoded(i)  := predecoders(i).io.out
    
    packet.pc(i)             := io.fetch_req.bits.pc + (i * 2).U
    packet.exception_type(i) := 0.U
    packet.debug_seqNum(i)   := 0.U
    
    is_rvc(i) := predecoders(i).io.out.is_rvc
  }

  for (i <- 0 until predictWidth) {
    val is_entry_slot = io.fetch_req.bits.mask(i) && (if (i == 0) true.B else !io.fetch_req.bits.mask(i-1, 0).orR)
    val prev_was_rvc  = if (i >= 1) mask_reg(i-1) && is_rvc(i-1) else false.B
    val prev_was_32b  = if (i >= 2) mask_reg(i-2) && !is_rvc(i-2) else false.B
    val valid_seq     = is_entry_slot || prev_was_rvc || prev_was_32b
    mask_reg(i)       := io.fetch_req.bits.mask(i) && valid_seq
  }
  
  packet.mask := mask_reg.asUInt

  // Pass through the handshake
  io.toIbuffer.valid := io.fetch_req.valid
  io.toIbuffer.bits  := packet
  io.fetch_req.ready := io.toIbuffer.ready && io.icache_ready
}
