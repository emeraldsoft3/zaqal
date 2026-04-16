package zaqal.backend.fu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class ALU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xLen.W))
    val src2   = Input(UInt(xLen.W))
    val pc     = Input(UInt(xLen.W))
    val dec    = Input(new DecodeSignals)
    val result = Output(UInt(xLen.W))
  })

  // 1. Sub-Modules
  val adder      = Module(new Adder)
  val logical    = Module(new Logical)
  val shifter    = Module(new Shifter)
  val comparator = Module(new Comparator)
  val bitmanip   = Module(new Bitmanip)

  // 2. Wiring
  adder.io.src1    := io.src1
  adder.io.src2    := io.src2
  adder.io.is_sub  := io.dec.is_sub || io.dec.is_subw
  adder.io.is_word := io.dec.is_addw || io.dec.is_subw || io.dec.is_addiw

  logical.io.src1   := io.src1
  logical.io.src2   := io.src2
  logical.io.is_and  := io.dec.is_and  || io.dec.is_andi
  logical.io.is_or   := io.dec.is_or   || io.dec.is_ori
  logical.io.is_xor  := io.dec.is_xor  || io.dec.is_xori
  logical.io.is_andn := io.dec.is_andn
  logical.io.is_orn  := io.dec.is_orn
  logical.io.is_xorn := io.dec.is_xorn

  shifter.io.src1   := io.src1
  shifter.io.shamt  := io.src2(5, 0)
  shifter.io.is_sll  := io.dec.is_sll || io.dec.is_slli
  shifter.io.is_srl  := io.dec.is_srl || io.dec.is_srli
  shifter.io.is_sra  := io.dec.is_sra || io.dec.is_srai
  shifter.io.is_sllw := io.dec.is_sllw || io.dec.is_slliw
  shifter.io.is_srlw := io.dec.is_srlw || io.dec.is_srliw
  shifter.io.is_sraw := io.dec.is_sraw || io.dec.is_sraiw
  shifter.io.is_rol   := io.dec.is_rol
  shifter.io.is_ror   := io.dec.is_ror
  shifter.io.is_rori  := io.dec.is_rori
  shifter.io.is_rolw  := io.dec.is_rolw
  shifter.io.is_rorw  := io.dec.is_rorw
  shifter.io.is_roriw := io.dec.is_roriw

  comparator.io.src1    := io.src1
  comparator.io.src2    := io.src2

  bitmanip.io.src1     := io.src1
  bitmanip.io.src2     := io.src2
  bitmanip.io.is_clz   := io.dec.is_clz
  bitmanip.io.is_ctz   := io.dec.is_ctz
  bitmanip.io.is_cpop  := io.dec.is_cpop
  bitmanip.io.is_clzw  := io.dec.is_clzw
  bitmanip.io.is_ctzw  := io.dec.is_ctzw
  bitmanip.io.is_cpopw := io.dec.is_cpopw
  bitmanip.io.is_rev8   := io.dec.is_rev8
  bitmanip.io.is_orc_b  := io.dec.is_orc_b
  bitmanip.io.is_sextb  := io.dec.is_sextb
  bitmanip.io.is_sexth  := io.dec.is_sexth
  bitmanip.io.is_zexth  := io.dec.is_zexth
  bitmanip.io.is_min    := io.dec.is_min
  bitmanip.io.is_max    := io.dec.is_max
  bitmanip.io.is_minu   := io.dec.is_minu
  bitmanip.io.is_maxu   := io.dec.is_maxu
  bitmanip.io.is_bset   := io.dec.is_bset
  bitmanip.io.is_bseti  := io.dec.is_bseti
  bitmanip.io.is_bclr   := io.dec.is_bclr
  bitmanip.io.is_bclri  := io.dec.is_bclri
  bitmanip.io.is_binv   := io.dec.is_binv
  bitmanip.io.is_binvi  := io.dec.is_binvi
  bitmanip.io.is_bext   := io.dec.is_bext
  bitmanip.io.is_bexti  := io.dec.is_bexti

  // Zba — Address Generation combinational logic
  val zba_src1_zext = Cat(0.U(32.W), io.src1(31, 0))   // zero-extend lower 32 bits for .UW
  val sh1add_res    = io.src2 + (io.src1 << 1)
  val sh2add_res    = io.src2 + (io.src1 << 2)
  val sh3add_res    = io.src2 + (io.src1 << 3)
  val sh1add_uw_res = io.src2 + (zba_src1_zext << 1)
  val sh2add_uw_res = io.src2 + (zba_src1_zext << 2)
  val sh3add_uw_res = io.src2 + (zba_src1_zext << 3)

  // 3. Result Selection
  io.result := MuxCase(0.U, Seq(
    (io.dec.is_add || io.dec.is_addi || io.dec.is_sub || 
     io.dec.is_addw || io.dec.is_subw || io.dec.is_addiw) -> adder.io.result,
    (io.dec.is_auipc) -> (io.pc + io.src2), // Direct PC + Imm
    (io.dec.is_lui)   -> io.src2,           // Direct Imm
    (io.dec.is_and || io.dec.is_andi || 
     io.dec.is_or  || io.dec.is_ori  || 
     io.dec.is_xor || io.dec.is_xori ||
     io.dec.is_andn || io.dec.is_orn || io.dec.is_xorn) -> logical.io.result,
    (io.dec.is_sll || io.dec.is_srl || io.dec.is_sra ||
     io.dec.is_slli || io.dec.is_srli || io.dec.is_srai ||
     io.dec.is_sllw || io.dec.is_srlw || io.dec.is_sraw ||
     io.dec.is_slliw || io.dec.is_srliw || io.dec.is_sraiw ||
     io.dec.is_rol || io.dec.is_ror || io.dec.is_rori ||
     io.dec.is_rolw || io.dec.is_rorw || io.dec.is_roriw) -> shifter.io.result,
    (io.dec.is_slt || io.dec.is_slti)   -> comparator.io.lt.asUInt,
    (io.dec.is_sltu || io.dec.is_sltiu) -> comparator.io.ltu.asUInt,
    // Zba address generation
    (io.dec.is_sh1add)    -> sh1add_res,
    (io.dec.is_sh2add)    -> sh2add_res,
    (io.dec.is_sh3add)    -> sh3add_res,
    (io.dec.is_sh1add_uw) -> sh1add_uw_res,
    (io.dec.is_sh2add_uw) -> sh2add_uw_res,
    (io.dec.is_sh3add_uw) -> sh3add_uw_res,
    (io.dec.is_clz || io.dec.is_ctz || io.dec.is_cpop ||
     io.dec.is_clzw || io.dec.is_ctzw || io.dec.is_cpopw ||
     io.dec.is_rev8 || io.dec.is_orc_b || io.dec.is_sextb || io.dec.is_sexth ||
     io.dec.is_zexth || io.dec.is_min || io.dec.is_max || io.dec.is_minu ||
     io.dec.is_maxu || io.dec.is_bset || io.dec.is_bseti || io.dec.is_bclr ||
     io.dec.is_bclri || io.dec.is_binv || io.dec.is_binvi || io.dec.is_bext ||
     io.dec.is_bexti) -> bitmanip.io.result,
  ))
}
