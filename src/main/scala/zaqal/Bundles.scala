package zaqal

import chisel3._
import chisel3.util._

// Metadata for branch prediction
class PredictionMeta extends Bundle {
  val target    = UInt(64.W) // Where we think we are jumping
  val taken     = Bool()     // Did we actually jump?
  val slot      = UInt(3.W)  // Which of the 8 instructions is the branch? (0-7)
}

// Packet of instructions fetched from I-Cache
class FetchPacket extends Bundle {
  val pc           = UInt(64.W)
  val instructions = Vec(8, UInt(32.W))
  val pre_decoded  = Vec(8, new PreDecodeSignals)
  val mask         = UInt(8.W)
  val prediction   = new PredictionMeta
  val ftqPtr       = UInt(6.W) // Pointer to FTQ entry (64 entries)
}

// Signals produced by the Frontend Predecoder (Kunminghu Alignment)
class PreDecodeSignals extends Bundle {
  val is_rvc = Bool() // Compressed ISA hint
  val is_cfi = Bool() // Control Flow Instruction hint
}

// Signals produced by the Backend Main Decoder
class DecodeSignals extends Bundle {
  val is_addi = Bool()
  val rd      = UInt(5.W)
  val rs1     = UInt(5.W)
  val imm     = SInt(64.W)
}

// The "Language" spoken between Frontend and Backend (Kunminghu)
// Frontend produces raw instructions + hints
class MicroOp extends Bundle {
  val pc       = UInt(64.W)
  val inst_raw = UInt(32.W)
  val pre      = new PreDecodeSignals
  val ftqPtr   = UInt(6.W) // Track origin FTQ entry
}

// Redirect signal from Backend to Frontend
class BPURedirect extends Bundle {
  val valid  = Bool()
  val target = UInt(64.W)
}
