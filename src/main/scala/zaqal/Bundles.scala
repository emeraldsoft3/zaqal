package zaqal

import chisel3._
import chisel3.util._

// Metadata for branch prediction
class PredictionMeta extends Bundle {
  val target    = UInt(64.W) // Where we think we are jumping
  val taken     = Bool()     // Did we actually jump?
  val slot      = UInt(3.W)  // Which of the 8 instructions is the branch? (0-7)
}

// Lightweight request from BPU to FTQ
class FetchRequest extends Bundle {
  val pc         = UInt(64.W)
  val mask       = UInt(8.W)
  val prediction = new PredictionMeta
  val ftqPtr     = UInt(6.W) // Added to help IFU tag the packet
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
  val is_add  = Bool()  // R-type ADD
  val is_mul  = Bool()  // M-extension MUL
  val is_div  = Bool()  // M-extension DIV (signed)
  val is_bne  = Bool()  // B-type BNE
  val is_blt  = Bool()  // B-type BLT
  val is_and  = Bool()  // R-type AND
  val is_or   = Bool()  // R-type OR
  val is_xor  = Bool()  // R-type XOR
  val is_andi = Bool()  // I-type ANDI
  val is_ori  = Bool()  // I-type ORI
  val is_xori = Bool()  // I-type XORI
  val is_sll  = Bool()  // R-type SLL
  val is_srl  = Bool()  // R-type SRL
  val is_sra  = Bool()  // R-type SRA
  val is_sllw = Bool()  // R-type SLLW
  val is_srlw = Bool()  // R-type SRLW
  val is_sraw = Bool()  // R-type SRAW
  val is_slli  = Bool()  // I-type SLLI (64-bit)
  val is_srli  = Bool()  // I-type SRLI (64-bit)
  val is_srai  = Bool()  // I-type SRAI (64-bit)
  val is_slliw = Bool()  // I-type SLLIW (32-bit Word)
  val is_srliw = Bool()  // I-type SRLIW (32-bit Word)
  val is_sraiw = Bool()  // I-type SRAIW (32-bit Word)
  val is_slt  = Bool()  // R-type SLT
  val is_sltu = Bool()  // R-type SLTU
  val is_slti = Bool()  // I-type SLTI
  val is_sltiu = Bool() // I-type SLTIU
  val is_lui   = Bool() // U-type LUI
  val is_auipc = Bool() // U-type AUIPC
  val is_branch = Bool() // General branch hint
  val rd      = UInt(5.W)
  val rs1     = UInt(5.W)
  val rs2     = UInt(5.W)  // Source register 2 (R-type)
  val imm     = SInt(64.W)
}

// The "Language" spoken between Frontend and Backend (Kunminghu)
// Frontend produces raw instructions + hints
class MicroOp extends Bundle {
  val pc       = UInt(64.W)
  val inst_raw = UInt(32.W)
  val pre      = new PreDecodeSignals
  val ftqPtr   = UInt(6.W) // Track origin FTQ entry
  val is_predicted_taken = Bool()
}

// Redirect signal from Backend to Frontend
class BPURedirect extends Bundle {
  val valid  = Bool()
  val target = UInt(64.W)
}
