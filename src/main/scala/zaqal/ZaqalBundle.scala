package zaqal

import chisel3._ // This adds Bundle, UInt, Bool, etc.

class ZaqalFetchPacket extends Bundle {
  val pc        = UInt(64.W) // Match the 64-bit we decided on
  val mask      = UInt(8.W)
  val taken     = Bool()
  val target    = UInt(64.W)
}