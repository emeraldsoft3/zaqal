package zaqal.common

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters

// Metadata for branch prediction
class PredictionMeta(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val target    = UInt(xLen.W) // Where we think we are jumping
  val taken     = Bool()     // Did we actually jump?
  val slot      = UInt(log2Up(predictWidth).W)  // Which instruction in the packet is the branch?
}

// Lightweight request from BPU to FTQ
class FetchRequest(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc         = UInt(xLen.W)
  val mask       = UInt(predictWidth.W)
  val prediction = new PredictionMeta
  val ftqPtr     = UInt(ftqPtrWidth.W) // Added to help IFU tag the packet
  val epoch      = Bool()    // Track valid fetch path
}

// Packet of instructions fetched from I-Cache
class FetchPacket(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc           = UInt(xLen.W)
  val instructions = Vec(predictWidth, UInt(instBits.W))
  val pre_decoded  = Vec(predictWidth, new PreDecodeSignals)
  val mask         = UInt(predictWidth.W)
  val prediction   = new PredictionMeta
  val ftqPtr       = UInt(ftqPtrWidth.W) // Pointer to FTQ entry
  val epoch        = Bool()
}

// Signals produced by the Frontend Predecoder (Kunminghu Alignment)
class PreDecodeSignals extends Bundle {
  val is_rvc = Bool() // Compressed ISA hint
  val is_cfi = Bool() // Control Flow Instruction hint
  val expanded_inst = UInt(32.W) // Expanded 32-bit instruction
}

// Signals produced by the Backend Main Decoder
class DecodeSignals(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val is_rvc = Bool()
  val is_addi = Bool()
  val is_add  = Bool()  // R-type ADD
  val is_mul   = Bool()  // M-extension MUL (low bits)
  val is_mulh  = Bool()  // M-extension MULH (signed-signed high)
  val is_mulhsu= Bool()  // M-extension MULHSU (signed-unsigned high)
  val is_mulhu = Bool()  // M-extension MULHU (unsigned-unsigned high)
  val is_mulw  = Bool()  // M-extension MULW (32-bit word MUL)
  val is_div   = Bool()  // M-extension DIV (signed)
  val is_divu  = Bool()  // M-extension DIVU (unsigned)
  val is_rem   = Bool()  // M-extension REM (signed)
  val is_remu  = Bool()  // M-extension REMU (unsigned)
  val is_divw  = Bool()  // M-extension DIVW
  val is_divuw = Bool()  // M-extension DIVUW
  val is_remw  = Bool()  // M-extension REMW
  val is_remuw = Bool()  // M-extension REMUW
  val is_beq  = Bool()  // B-type BEQ
  val is_bne  = Bool()  // B-type BNE
  val is_blt  = Bool()  // B-type BLT
  val is_bge  = Bool()  // B-type BGE
  val is_bltu = Bool()  // B-type BLTU
  val is_bgeu = Bool()  // B-type BGEU
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
  val is_sub   = Bool() // R-type SUB
  val is_addw  = Bool() // R-type ADDW
  val is_subw  = Bool() // R-type SUBW
  val is_addiw = Bool() // I-type ADDIW
  val is_lui   = Bool() // U-type LUI
  val is_auipc = Bool() // U-type AUIPC
  val is_branch = Bool() // General branch hint
  val is_jal  = Bool()  // J-type JAL
  val is_jalr = Bool()  // I-type JALR

  // Load Instructions (RV64I)
  val is_lb   = Bool()
  val is_lh   = Bool()
  val is_lw   = Bool()
  val is_ld   = Bool()
  val is_lbu  = Bool()
  val is_lhu  = Bool()
  val is_lwu  = Bool()
  val is_load = Bool()

  // Store Instructions (RV64I)
  val is_sb    = Bool()
  val is_sh    = Bool()
  val is_sw    = Bool()
  val is_sd    = Bool()
  val is_store = Bool()

  // Zba Address Generation (Bitmanip)
  val is_sh1add    = Bool()
  val is_sh2add    = Bool()
  val is_sh3add    = Bool()
  val is_sh1add_uw = Bool()
  val is_sh2add_uw = Bool()
  val is_sh3add_uw = Bool()

  // Zbb Basic Bit Ops (Bitmanip)
  val is_andn  = Bool()
  val is_orn   = Bool()
  val is_xorn  = Bool()
  val is_rol   = Bool()
  val is_ror   = Bool()
  val is_rori  = Bool()
  val is_rolw  = Bool()
  val is_rorw  = Bool()
  val is_roriw = Bool()
  val is_clz   = Bool()
  val is_ctz   = Bool()
  val is_cpop  = Bool()
  val is_clzw  = Bool()
  val is_ctzw  = Bool()
  val is_cpopw = Bool()
  val is_rev8  = Bool()
  val is_orc_b = Bool()
  val is_sextb = Bool()
  val is_sexth = Bool()
  val is_zexth = Bool()
  val is_min   = Bool()
  val is_max   = Bool()
  val is_minu  = Bool()
  val is_maxu  = Bool()

  // Zbs Single-bit (Bitmanip)
  val is_bset  = Bool()
  val is_bseti = Bool()
  val is_bclr  = Bool()
  val is_bclri = Bool()
  val is_binv  = Bool()
  val is_binvi = Bool()
  val is_bext  = Bool()
  val is_bexti = Bool()

  // Atomic Instructions (RV64A)
  val is_lr       = Bool()
  val is_sc       = Bool()
  val is_lr_w     = Bool()
  val is_lr_d     = Bool()
  val is_sc_w     = Bool()
  val is_sc_d     = Bool()
  val is_amoadd   = Bool()
  val is_amoswap  = Bool()
  val is_amoxor   = Bool()
  val is_amoand   = Bool()
  val is_amoor    = Bool()
  val is_amomin   = Bool()
  val is_amomax   = Bool()
  val is_amominu  = Bool()
  val is_amomaxu  = Bool()
  val is_amo_w    = Bool()
  val is_amo_d    = Bool()
  val is_atomic   = Bool()
  
  // Floating Point Instructions
  val is_fload    = Bool()
  val is_flw      = Bool()
  val is_fld      = Bool()
  val is_fstore   = Bool()
  val is_fsw      = Bool()
  val is_fsd      = Bool()
  val is_fmadd    = Bool()
  val is_fmsub    = Bool()
  val is_fnmsub   = Bool()
  val is_fnmadd   = Bool()
  val is_fadd     = Bool()
  val is_fsub     = Bool()
  val is_fmul     = Bool()
  val is_fdiv     = Bool()
  val is_fsqrt    = Bool()
  val is_fsgnj    = Bool()
  val is_fminmax  = Bool()
  val is_fcvt_f2i = Bool()
  val is_fcvt_i2f = Bool()
  val is_fmv      = Bool()
  val is_fmv_w_x  = Bool()
  val is_fmv_x_w  = Bool()
  val is_feq      = Bool()
  val is_flt      = Bool()
  val is_fle      = Bool()
  val is_fclass   = Bool()
  val is_fcsr_access = Bool()

  val rd      = UInt(5.W)
  val rs1     = UInt(5.W)
  val rs2     = UInt(5.W)  // Source register 2 (R-type)
  val rs3     = UInt(5.W)  // Source register 3 (R4-type FMA)
  val imm     = SInt(xLen.W)
}

// The "Language" spoken between Frontend and Backend (Kunminghu)
// Frontend produces raw instructions + hints
class MicroOp(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc       = UInt(xLen.W)
  val inst_raw = UInt(instBits.W)
  val pre      = new PreDecodeSignals
  val ftqPtr   = UInt(ftqPtrWidth.W) // Track origin FTQ entry
  val is_predicted_taken = Bool()
  val epoch    = Bool()
}

// Redirect signal from Backend to Frontend
class BPURedirect(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val valid  = Bool()
  val target = UInt(xLen.W)
  val epoch  = Bool()
  val is_exception = Bool()
  val exc_cause    = UInt(instBits.W)
}

object Causes {
  val inst_address_misaligned = 0.U
}

class BranchPredictionBus(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc = UInt(xLen.W)
  val target = UInt(xLen.W)
  val taken = Bool()
}

class PipelineFlushBus(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val flush = Bool()
  val targetPC = UInt(xLen.W)
}
