package zaqal.backend.decode

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
  * FusionDecoder: Dedicated Macro-op & Micro-op Fusion Module
  * 
  * Provides 1:1 parity with XiangShan's FusionDecoder (Nanhu & Kunminghu).
  * Evaluates 6-wide decode packets using pairwise arbitration.
  * When a fusable pair (inst[i], inst[i+1]) matches:
  *   - inst[i] is transformed into a compound fused micro-op.
  *   - inst[i+1] is cleared/squashed (clear(i+1) = true).
  */
class FusionDecoderIO(val fusionWidth: Int)(implicit val p: Parameters) extends Bundle {
  val in             = Input(Vec(fusionWidth, new DecodedMicroOp))
  val dispatch_valid = Input(Vec(fusionWidth, Bool()))
  val out            = Output(Vec(fusionWidth, new DecodedMicroOp))
  val clear          = Output(Vec(fusionWidth, Bool()))
  val is_fused_pair  = Output(Vec(fusionWidth, Bool()))
}

class FusionDecoder(val fusionWidth: Int = 6)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new FusionDecoderIO(fusionWidth))

  // Default passthrough
  for (i <- 0 until fusionWidth) {
    io.out(i) := io.in(i)
  }

  val clear_vec = Wire(Vec(fusionWidth, Bool()))
  clear_vec(0) := false.B

  for (i <- 0 until fusionWidth) {
    if (i == fusionWidth - 1) {
      io.is_fused_pair(i) := false.B
    } else {
      val ui = io.in(i)
      val unext = io.in(i + 1)
      val both_valid = io.dispatch_valid(i) && io.dispatch_valid(i + 1)

      val is_imm_alu = unext.decode.is_addi || unext.decode.is_andi || unext.decode.is_ori ||
                       unext.decode.is_xori || unext.decode.is_slli || unext.decode.is_srli || unext.decode.is_srai
      
      val alu_op = MuxCase(0.U, Seq(
        unext.decode.is_addi -> 0.U,
        unext.decode.is_andi -> 1.U,
        unext.decode.is_ori  -> 2.U,
        unext.decode.is_xori -> 3.U,
        unext.decode.is_slli -> 4.U,
        unext.decode.is_srli -> 5.U,
        unext.decode.is_srai -> 6.U
      ))

      // 1. LUI/AUIPC + ADDI(W) Fusion (LUI32 / LUI32W)
      val can_fuse_lui_addi = (ui.decode.is_lui || ui.decode.is_auipc) && 
                              (unext.decode.is_addi || unext.decode.is_addiw) && 
                              (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                              (ui.decode.rd =/= 0.U) && both_valid

      // 2. SH1ADD, SH2ADD, SH3ADD, SH4ADD (SLLI + ADD)
      val can_fuse_shxadd = ui.decode.is_slli && (ui.decode.imm >= 1.S && ui.decode.imm <= 4.S) &&
                            unext.decode.is_add && (unext.decode.rs1 =/= unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rs1 || ui.decode.rd === unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rd) && (ui.decode.rd =/= 0.U) && both_valid

      val shx_fused_type = MuxLookup(ui.decode.imm.asUInt, FusionType.NONE)(Seq(
        1.U -> FusionType.SH1ADD,
        2.U -> FusionType.SH2ADD,
        3.U -> FusionType.SH3ADD,
        4.U -> FusionType.SH4ADD
      ))
      val shx_rs2 = Mux(ui.decode.rd === unext.decode.rs1, unext.decode.rs2, unext.decode.rs1)

      // 3. ZEXT.W (SLLI 32 + SRLI 32)
      val can_fuse_zextw = ui.decode.is_slli && (ui.decode.imm === 32.S) &&
                           unext.decode.is_srli && (unext.decode.imm === 32.S) &&
                           (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                           (ui.decode.rd =/= 0.U) && both_valid

      // 4. ZEXT.H (SLLI 48 + SRLI 48 or SLLIW 16 + SRLIW 16)
      val can_fuse_zexth = ((ui.decode.is_slli && ui.decode.imm === 48.S && unext.decode.is_srli && unext.decode.imm === 48.S) ||
                            (ui.decode.is_slliw && ui.decode.imm === 16.S && unext.decode.is_srliw && unext.decode.imm === 16.S)) &&
                           (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                           (ui.decode.rd =/= 0.U) && both_valid

      // 5. SEXT.H (SLLIW 16 + SRAIW 16)
      val can_fuse_sexth = ui.decode.is_slliw && (ui.decode.imm === 16.S) &&
                           unext.decode.is_sraiw && (unext.decode.imm === 16.S) &&
                           (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                           (ui.decode.rd =/= 0.U) && both_valid

      // 6. BYTE2 (SRLI 8 + ANDI 255)
      val can_fuse_byte2 = ui.decode.is_srli && (ui.decode.imm === 8.S) &&
                           unext.decode.is_andi && (unext.decode.imm === 255.S) &&
                           (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                           (ui.decode.rd =/= 0.U) && both_valid

      // 7. LOGIC_LSB ((AND|OR|XOR) + ANDI 1)
      val ui_is_logic = ui.decode.is_and || ui.decode.is_andi || ui.decode.is_or || ui.decode.is_ori || ui.decode.is_xor || ui.decode.is_xori
      val can_fuse_logic_lsb = ui_is_logic && unext.decode.is_andi && (unext.decode.imm === 1.S) &&
                               (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                               (ui.decode.rd =/= 0.U) && both_valid

      // 8. ADD_LSB / ADD_BYTE (ADD(W) + ANDI 1 or 255)
      val ui_is_add_op = ui.decode.is_add || ui.decode.is_addi || ui.decode.is_addw || ui.decode.is_addiw
      val can_fuse_add_lsb = ui_is_add_op && unext.decode.is_andi && (unext.decode.imm === 1.S) &&
                             (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                             (ui.decode.rd =/= 0.U) && both_valid

      val can_fuse_add_byte = ui_is_add_op && unext.decode.is_andi && (unext.decode.imm === 255.S) &&
                              (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                              (ui.decode.rd =/= 0.U) && both_valid

      // 9. XiangShan Specialized Bitmanip: SR29ADD..SR32ADD (SRLI 29..32 + ADD)
      val can_fuse_srxadd = ui.decode.is_srli && (ui.decode.imm >= 29.S && ui.decode.imm <= 32.S) &&
                            unext.decode.is_add && (unext.decode.rs1 =/= unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rs1 || ui.decode.rd === unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rd) && (ui.decode.rd =/= 0.U) && both_valid

      val srx_fused_type = MuxLookup(ui.decode.imm.asUInt, FusionType.NONE)(Seq(
        29.U -> FusionType.SR29ADD,
        30.U -> FusionType.SR30ADD,
        31.U -> FusionType.SR31ADD,
        32.U -> FusionType.SR32ADD
      ))
      val srx_rs2 = Mux(ui.decode.rd === unext.decode.rs1, unext.decode.rs2, unext.decode.rs1)

      // 10. XiangShan Specialized Bitmanip: SZEWL1..3 (SLLI 32 + SRLI 29..31)
      val can_fuse_szewl = ui.decode.is_slli && (ui.decode.imm === 32.S) &&
                           unext.decode.is_srli && (unext.decode.imm >= 29.S && unext.decode.imm <= 31.S) &&
                           (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                           (ui.decode.rd =/= 0.U) && both_valid

      val szewl_fused_type = MuxLookup(unext.decode.imm.asUInt, FusionType.NONE)(Seq(
        31.U -> FusionType.SZEWL1,
        30.U -> FusionType.SZEWL2,
        29.U -> FusionType.SZEWL3
      ))

      // 11. XiangShan Specialized Bitmanip: ODDADD / ODDADDW (ANDI 1 + ADD/ADDW)
      val can_fuse_oddadd = ui.decode.is_andi && (ui.decode.imm === 1.S) &&
                            unext.decode.is_add && (unext.decode.rs1 =/= unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rs1 || ui.decode.rd === unext.decode.rs2) &&
                            (ui.decode.rd === unext.decode.rd) && (ui.decode.rd =/= 0.U) && both_valid

      val can_fuse_oddaddw = ui.decode.is_andi && (ui.decode.imm === 1.S) &&
                             unext.decode.is_addw && (unext.decode.rs1 =/= unext.decode.rs2) &&
                             (ui.decode.rd === unext.decode.rs1 || ui.decode.rd === unext.decode.rs2) &&
                             (ui.decode.rd === unext.decode.rd) && (ui.decode.rd =/= 0.U) && both_valid

      val odd_rs2 = Mux(ui.decode.rd === unext.decode.rs1, unext.decode.rs2, unext.decode.rs1)

      // 12. Compare + Branch Fusion (SLT(U) + BNE/BEQ)
      val ui_is_slt = ui.decode.is_slt || ui.decode.is_sltu
      val unext_is_b_zero = (unext.decode.is_bne || unext.decode.is_beq) && (unext.decode.rs2 === 0.U)
      val can_fuse_cmp_branch = ui_is_slt && unext_is_b_zero && (unext.decode.rs1 === ui.decode.rd) &&
                                (ui.decode.rd =/= 0.U) && both_valid

      // 13. Load + ALU Fusion (e.g. LW/LD + ADDI/ANDI/ORI/XORI/SLLI/SRLI/SRAI)
      val can_fuse_load_alu = ui.decode.is_load && !ui.decode.is_fload && 
                              is_imm_alu && 
                              (ui.decode.rd === unext.decode.rs1) && (ui.decode.rd === unext.decode.rd) &&
                              (ui.decode.rd =/= 0.U) && both_valid

      // 14. ADDI + Store Fusion (ADDI + SW)
      val can_fuse_alu_store = ui.decode.is_addi && 
                               unext.decode.is_store && 
                               (ui.decode.rd === unext.decode.rs2) &&
                               (ui.decode.rd =/= 0.U) && both_valid

      val fuse_any = can_fuse_lui_addi || can_fuse_shxadd || can_fuse_zextw || can_fuse_zexth || can_fuse_sexth ||
                     can_fuse_byte2 || can_fuse_logic_lsb || can_fuse_add_lsb || can_fuse_add_byte ||
                     can_fuse_srxadd || can_fuse_szewl || can_fuse_oddadd || can_fuse_oddaddw ||
                     can_fuse_cmp_branch || can_fuse_load_alu || can_fuse_alu_store

      val can_fuse_here = !clear_vec(i) && fuse_any

      io.is_fused_pair(i) := can_fuse_here
      clear_vec(i + 1) := can_fuse_here

      when(can_fuse_here) {
        io.out(i).decode.is_fused := true.B
        io.out(i).decode.is_fused_lui_addi := can_fuse_lui_addi
        io.out(i).decode.is_fused_load_alu := can_fuse_load_alu
        io.out(i).decode.is_fused_alu_store := can_fuse_alu_store
        io.out(i).decode.fused_alu_op := alu_op

        when(can_fuse_lui_addi) {
          io.out(i).decode.imm := ui.decode.imm + unext.decode.imm
          io.out(i).decode.fused_imm := unext.decode.imm
          io.out(i).decode.fused_type := Mux(unext.decode.is_addiw, FusionType.LUI32W, FusionType.LUI32)
        } .elsewhen(can_fuse_shxadd) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := shx_rs2
          io.out(i).decode.rs2_use := true.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := shx_fused_type
        } .elsewhen(can_fuse_zextw) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2_use := false.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ZEXTW
        } .elsewhen(can_fuse_zexth) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2_use := false.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ZEXTH
        } .elsewhen(can_fuse_sexth) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2_use := false.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.SEXTH
        } .elsewhen(can_fuse_byte2) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2_use := false.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.BYTE2
        } .elsewhen(can_fuse_logic_lsb) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := ui.decode.rs2
          io.out(i).decode.rs2_use := ui.decode.rs2_use
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.LOGIC_LSB
        } .elsewhen(can_fuse_add_lsb) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := ui.decode.rs2
          io.out(i).decode.rs2_use := ui.decode.rs2_use
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ADD_LSB
        } .elsewhen(can_fuse_add_byte) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := ui.decode.rs2
          io.out(i).decode.rs2_use := ui.decode.rs2_use
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ADD_BYTE
        } .elsewhen(can_fuse_srxadd) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := srx_rs2
          io.out(i).decode.rs2_use := true.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := srx_fused_type
        } .elsewhen(can_fuse_szewl) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2_use := false.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := szewl_fused_type
        } .elsewhen(can_fuse_oddadd) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := odd_rs2
          io.out(i).decode.rs2_use := true.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ODDADD
        } .elsewhen(can_fuse_oddaddw) {
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := odd_rs2
          io.out(i).decode.rs2_use := true.B
          io.out(i).decode.rd := unext.decode.rd
          io.out(i).decode.fused_type := FusionType.ODDADDW
        } .elsewhen(can_fuse_cmp_branch) {
          io.out(i).decode.is_branch := true.B
          io.out(i).decode.is_blt := (ui.decode.is_slt && unext.decode.is_bne)
          io.out(i).decode.is_bge := (ui.decode.is_slt && unext.decode.is_beq)
          io.out(i).decode.is_bltu := (ui.decode.is_sltu && unext.decode.is_bne)
          io.out(i).decode.is_bgeu := (ui.decode.is_sltu && unext.decode.is_beq)
          io.out(i).decode.is_slt := false.B
          io.out(i).decode.is_sltu := false.B
          io.out(i).decode.rs1 := ui.decode.rs1
          io.out(i).decode.rs2 := ui.decode.rs2
          io.out(i).decode.rs1_use := true.B
          io.out(i).decode.rs2_use := true.B
          io.out(i).decode.rd := 0.U
          io.out(i).decode.imm := unext.decode.imm + Mux(ui.decode.is_rvc, 2.S, 4.S)
          io.out(i).decode.fused_type := FusionType.CMP_BRANCH
        } .elsewhen(can_fuse_load_alu) {
          io.out(i).decode.fused_imm := unext.decode.imm
          io.out(i).decode.fused_type := FusionType.LOAD_ALU
        } .elsewhen(can_fuse_alu_store) {
          io.out(i).decode.fused_imm := unext.decode.imm
          io.out(i).decode.rs2 := unext.decode.rs1
          io.out(i).decode.fused_type := FusionType.ALU_STORE
        }
      }
    }
  }

  io.clear := clear_vec
}
