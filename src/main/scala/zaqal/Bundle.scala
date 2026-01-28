package zaqal

import chisel3._ // This adds Bundle, UInt, Bool, etc.
import chisel3.util._

class FetchPacket extends Bundle {
  val pc        = UInt(64.W) // Match the 64-bit we decided on
  val mask      = UInt(8.W)
  val taken     = Bool()
  val target    = UInt(64.W)
  val instructions = Vec(8, UInt(32.W))
}

// Data coming out of the Decoder
class DecodedInst extends Bundle {
  val valid    = Bool()
  val pc       = UInt(64.W)
  val func     = UInt(7.W)  // For ALU operations
  val rs1_addr = UInt(5.W)
  val rs2_addr = UInt(5.W)
  val rd_addr  = UInt(5.W)
  val imm      = UInt(64.W)
  val has_dest = Bool()     // Does it write to a register?
  val is_jump  = Bool()
}

// The "Red Line" signal from Backend to Frontend
class BPURedirect extends Bundle {
  val valid  = Bool()
  val target = UInt(64.W)
}