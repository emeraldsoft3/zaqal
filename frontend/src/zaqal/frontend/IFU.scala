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

  val blockOffsetBits = log2Ceil(fetchWidth * 4)
  val pc_offset = io.fetch_req.bits.pc(blockOffsetBits - 1, 1)

  val is_rvc = Wire(Vec(predictWidth, Bool()))
  val mask_reg = Wire(Vec(predictWidth, Bool()))

  val max_half_words = (fetchWidth * 4) / 2

  for (i <- 0 until predictWidth) {
    val parcel_idx = pc_offset + i.U
    val shift_amt = parcel_idx * 16.U
    
    val inst_window = Mux(parcel_idx >= max_half_words.U, "h00000013".U(32.W), (raw_bits >> shift_amt)(31, 0))
    
    predecoders(i).io.inst := inst_window
    packet.instructions(i) := inst_window
    packet.pre_decoded(i)  := predecoders(i).io.out
    
    packet.pc(i)             := io.fetch_req.bits.pc + (i * 2).U
    packet.exception_type(i) := 0.U
    packet.debug_seqNum(i)   := 0.U
    
    is_rvc(i) := predecoders(i).io.out.is_rvc
  }

  mask_reg(0) := io.fetch_req.bits.mask(0) && (pc_offset < max_half_words.U)
  for (i <- 1 until predictWidth) {
    val prev_was_rvc = mask_reg(i-1) && is_rvc(i-1)
    val prev_was_32b = if (i >= 2) mask_reg(i-2) && !is_rvc(i-2) else false.B
    mask_reg(i) := io.fetch_req.bits.mask(i) && (prev_was_rvc || prev_was_32b) && (pc_offset + i.U < max_half_words.U)
  }
  
  packet.mask := mask_reg.asUInt

  // Pass through the handshake
  io.toIbuffer.valid := io.fetch_req.valid
  io.toIbuffer.bits  := packet
  io.fetch_req.ready := io.toIbuffer.ready && io.icache_ready
}
