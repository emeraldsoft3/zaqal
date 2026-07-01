package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FTBEntry(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid            = Bool()
  val tag              = UInt(53.W) // Tag size = 64 - indexWidth - offsetWidth = 64 - 6 - 5 = 53
  val target           = UInt(xLen.W)
  val br_type          = UInt(2.W)  // 0: cond, 1: jal, 2: jalr, 3: call
  val offset           = UInt(3.W)  // Instruction offset within fetch packet (0-7)
  val taken            = Bool()     // Direction prediction
}

class FTB(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req_pc  = Input(UInt(xLen.W))
    val hit     = Output(Bool())
    val target  = Output(UInt(xLen.W))
    val taken   = Output(Bool())
    val slot    = Output(UInt(3.W))
    
    // Update interface from BRU
    val update_valid = Input(Bool())
    val update_pc    = Input(UInt(xLen.W))
    val update_target= Input(UInt(xLen.W))
    val update_taken = Input(Bool())
    val update_is_cfi= Input(Bool())
    val update_is_jalr= Input(Bool())
  })

  val numEntries = 64
  val indexWidth = log2Up(numEntries)       // 6 bits
  val offsetWidth = log2Up(fetchWidth * 4)   // 5 bits (fetchWidth = 8 instructions * 4 bytes = 32-byte blocks)
  val tagWidth = xLen - indexWidth - offsetWidth // 53 bits

  // Storage array
  val entries = RegInit(VecInit(Seq.fill(numEntries)(0.U.asTypeOf(new FTBEntry))))

  // Index, Tag, Offset helpers
  def getIndex(pc: UInt): UInt = pc(indexWidth + offsetWidth - 1, offsetWidth)
  def getTag(pc: UInt): UInt = pc(xLen - 1, indexWidth + offsetWidth)
  def getOffset(pc: UInt): UInt = pc(offsetWidth - 1, 2)

  // Lookup logic
  val index = getIndex(io.req_pc)
  val tag   = getTag(io.req_pc)
  val entry = entries(index)

  val hit = entry.valid && (entry.tag === tag)
  io.hit    := hit
  io.target := Mux(hit, entry.target, io.req_pc + 32.U)
  io.taken  := hit && entry.taken
  io.slot   := Mux(hit, entry.offset, 0.U)

  // Update logic
  val update_index = getIndex(io.update_pc)
  val update_tag   = getTag(io.update_pc)
  val update_offset = getOffset(io.update_pc)

  when(io.update_valid && io.update_is_cfi) {
    val new_entry = Wire(new FTBEntry)
    new_entry.valid   := true.B
    new_entry.tag     := update_tag
    new_entry.target  := io.update_target
    new_entry.br_type := Mux(io.update_is_jalr, 2.U, 0.U)
    new_entry.offset  := update_offset
    new_entry.taken   := io.update_taken
    
    entries(update_index) := new_entry
    printf(p"[FTB UPDATE] pc=${Hexadecimal(io.update_pc)} index=$update_index tag=$update_tag offset=$update_offset target=${Hexadecimal(io.update_target)} taken=${io.update_taken}\n")
  }
}
