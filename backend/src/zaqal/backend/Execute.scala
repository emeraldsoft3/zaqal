package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend.fu._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new DecodedMicroOp))
    val redirect = Output(new BPURedirect)
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(fLen.W)))
    val debug_cycle = Input(UInt(64.W))
  })

  // Coordination state
  val div_rd_latch = RegInit(0.U(5.W))
  val div_pc_latch = RegInit(0.U(xLen.W))
  val fpdiv_rd_latch = RegInit(0.U(phyRegIdxWidth.W))
  val fpdiv_pc_latch = RegInit(0.U(xLen.W))

  // 1. Register File (Decoder is now external)
  val regFile = Module(new RegFile)
  val fpRegFile = Module(new FPRegFile)
  val fcsr      = Module(new FCSR)
  
  val dec = io.in.bits.decode
  val uop = io.in.bits.uop

  regFile.io.rs1_addr := io.in.bits.psrs1
  regFile.io.rs2_addr := io.in.bits.psrs2

  fpRegFile.io.rs1_addr := io.in.bits.psrs1
  fpRegFile.io.rs2_addr := io.in.bits.psrs2
  fpRegFile.io.rs3_addr := io.in.bits.psrs3
  
  val src1 = regFile.io.rs1_data
  val fsrc1 = fpRegFile.io.rs1_data
  val fsrc2 = fpRegFile.io.rs2_data
  val fsrc3 = fpRegFile.io.rs3_data
  val is_imm_type = dec.is_addi || dec.is_andi || dec.is_ori || dec.is_xori ||
                    dec.is_slli || dec.is_srli || dec.is_srai ||
                    dec.is_slliw || dec.is_srliw || dec.is_sraiw ||
                    dec.is_slti || dec.is_sltiu || dec.is_addiw ||
                    dec.is_lui  || dec.is_auipc || dec.is_load || dec.is_atomic ||
                    dec.is_rori || dec.is_roriw ||
                    dec.is_bseti || dec.is_bclri || dec.is_binvi || dec.is_bexti

  val operand2 = Mux(is_imm_type, dec.imm.asUInt, regFile.io.rs2_data)

  val is_mul_op = dec.is_mul || dec.is_mulh || dec.is_mulhsu || dec.is_mulhu || dec.is_mulw
  val is_div_op = dec.is_div || dec.is_divu || dec.is_rem || dec.is_remu ||
                  dec.is_divw || dec.is_divuw || dec.is_remw || dec.is_remuw

  // 2. Functional Units
  val alu  = Module(new ALU)
  val bru  = Module(new BRU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)
  val lsu  = Module(new LSU)
  val dmem = Module(new DataMem)
  val fpu  = Module(new FPU)
  val fpdiv = Module(new FPDivider)
  val fpmisc = Module(new FPMisc)

  // 3. Connect FUs
  alu.io.src1 := src1
  alu.io.src2 := operand2
  alu.io.pc   := uop.pc
  alu.io.dec  := dec
  
  bru.io.src1 := src1
  bru.io.src2 := regFile.io.rs2_data
  bru.io.dec  := dec
  bru.io.pc   := uop.pc
  bru.io.is_rvc := uop.pre.is_rvc
  bru.io.pred_taken := uop.is_predicted_taken

  mul.io.src1 := src1
  mul.io.src2 := regFile.io.rs2_data
  mul.io.dec  := dec

  div.io.src1 := src1
  div.io.src2 := regFile.io.rs2_data
  div.io.dec  := dec
  div.io.fire := io.in.fire

  lsu.io.src1 := src1
  lsu.io.src2 := Mux(dec.is_fstore, fsrc2, regFile.io.rs2_data)
  lsu.io.imm  := dec.imm
  lsu.io.dec  := dec
  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen && io.in.fire
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

  // 4. Connect FPU
  fpu.io.src1 := fsrc1
  fpu.io.src2 := fsrc2
  fpu.io.src3 := fsrc3
  fpu.io.dec  := dec

  fpdiv.io.src1 := fsrc1
  fpdiv.io.src2 := fsrc2
  fpdiv.io.dec  := dec
  fpdiv.io.fire := io.in.fire

  fpmisc.io.src1 := fsrc1
  fpmisc.io.src2 := fsrc2
  fpmisc.io.rs1_int := src1
  fpmisc.io.dec  := dec
  fpmisc.io.inst := uop.inst_raw

  // 4. Coordination & Handshake
  io.in.ready := div.io.ready && fpdiv.io.ready
  
  // Default RegFile write values
  regFile.io.wen     := false.B
  regFile.io.rd_addr := io.in.bits.pdest
  regFile.io.rd_data := 0.U

  fpRegFile.io.wen     := false.B
  fpRegFile.io.rd_addr := io.in.bits.pdest
  fpRegFile.io.rd_data := 0.U

  // FCSR defaults
  fcsr.io.csr_addr  := uop.inst_raw(31, 20)
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := src1
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  // FP Writeback Support
  val is_fp_wb_to_fp = dec.is_fload || dec.is_fadd || dec.is_fsub ||
                       dec.is_fmul || dec.is_fmadd ||
                       dec.is_fmv_w_x || dec.is_fcvt_i2f ||
                       dec.is_fsgnj || dec.is_fminmax
                       
  val is_fpdiv_op = dec.is_fdiv || dec.is_fsqrt
  
  val is_fp_wb_to_int = dec.is_fmv_x_w || dec.is_fcvt_f2i ||
                        dec.is_feq || dec.is_flt || dec.is_fle ||
                        dec.is_fclass

  // RISC-V 32-bit float NaN-boxing (if fLen=64)
  def nanBox(data: UInt): UInt = {
    if (fLen == 64) Cat("hffffffff".U(32.W), data(31, 0)) else data
  }

  // Branch redirection
  io.redirect.valid  := false.B
  io.redirect.target := bru.io.target
  io.redirect.epoch  := uop.epoch
  io.redirect.is_exception := bru.io.exc_valid
  io.redirect.exc_cause    := bru.io.exc_cause

  when(io.in.fire) {
    printf(p"CORE EXECUTE [Cycle ${io.debug_cycle}]: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} is_rvc=${uop.pre.is_rvc} epoch=${uop.epoch}")
    when(dec.is_fused) {
      printf(" [FUSED]")
    }
    printf("\n")
    // Writeback for single-cycle instructions
    when(dec.rd =/= 0.U) {
      val is_link = dec.is_jal || dec.is_jalr
      val link_addr = uop.pc + Mux(uop.pre.is_rvc, 2.U, 4.U)
      val result = Mux(is_mul_op, mul.io.result,
                   Mux(dec.is_load || dec.is_atomic, lsu.io.result, 
                   Mux(is_fp_wb_to_int, fpmisc.io.result_int, 
                   alu.io.result)))
                   
      regFile.io.wen     := ((!dec.is_branch && !is_div_op && !dec.is_store && 
                             !dec.is_fload && !is_fp_wb_to_fp) || 
                             is_link || dec.is_atomic || is_fp_wb_to_int)
      regFile.io.rd_data := Mux(is_link, link_addr, result)

      // FP Register File Writeback
      when(is_fp_wb_to_fp) {
        fpRegFile.io.wen := true.B
        fpRegFile.io.rd_data := Mux(dec.is_flw, nanBox(lsu.io.result),
                                Mux(dec.is_fld, lsu.io.result,
                                Mux(dec.is_fmv_w_x || dec.is_fcvt_i2f ||
                                    dec.is_fsgnj   || dec.is_fminmax, fpmisc.io.result_fp,
                                fpu.io.result)))
      }
    }

    // Day 27: Basic Trap Redirection
    // Note: This is hardcoded to 0x80000100 for now because the CSR file (mtvec)
    // has not been implemented yet. On Day 28, this will be replaced by a CSR lookup.
    val trapVector = "h80000100".U
    when(bru.io.exc_valid) {
      io.redirect.valid  := true.B
      io.redirect.target := trapVector
      printf(p"CORE EXECUTE: EXCEPTION! Instruction Address Misaligned at pc=${Hexadecimal(uop.pc)} target=${Hexadecimal(bru.io.target)} -> Redir to TrapVector=${Hexadecimal(trapVector)}\n")
    } .elsewhen(bru.io.mispredict) {
      io.redirect.valid := true.B
      printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} target=${Hexadecimal(bru.io.target)} pred_taken=${uop.is_predicted_taken} actual_taken=${bru.io.taken}\n")
    } .elsewhen(dec.is_branch) {
      printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} Branch Correct\n")
    }

    // Latch DIV metadata (unchanged)
    when(is_div_op) {
      div_rd_latch := dec.rd
      div_pc_latch := uop.pc
    }
    when(is_fpdiv_op) {
      fpdiv_rd_latch := io.in.bits.pdest
      fpdiv_pc_latch := uop.pc
    }

    // Printfs for ALU/MUL
    val is_alu_op = dec.is_addi || dec.is_add || dec.is_andi || dec.is_ori || 
                    dec.is_xori || dec.is_and || dec.is_or || dec.is_xor ||
                    dec.is_sll  || dec.is_srl || dec.is_sra ||
                    dec.is_slli || dec.is_srli || dec.is_srai ||
                    dec.is_sllw || dec.is_srlw || dec.is_sraw ||
                    dec.is_slliw || dec.is_srliw || dec.is_sraiw ||
                    dec.is_slt  || dec.is_sltu || dec.is_slti || dec.is_sltiu ||
                    dec.is_sub  || dec.is_addw || dec.is_subw || dec.is_addiw ||
                    dec.is_lui  || dec.is_auipc || dec.is_load || dec.is_store ||
                    dec.is_sh1add || dec.is_sh2add || dec.is_sh3add ||
                    dec.is_sh1add_uw || dec.is_sh2add_uw || dec.is_sh3add_uw ||
                    dec.is_clz || dec.is_ctz || dec.is_cpop ||
                    dec.is_clzw || dec.is_ctzw || dec.is_cpopw ||
                    dec.is_andn || dec.is_orn || dec.is_xorn ||
                    dec.is_rol || dec.is_ror || dec.is_rori ||
                    dec.is_rolw || dec.is_rorw || dec.is_roriw ||
                    dec.is_rev8 || dec.is_orc_b || dec.is_sextb ||
                    dec.is_sexth || dec.is_zexth ||
                    dec.is_min || dec.is_max || dec.is_minu ||
                    dec.is_maxu ||
                    dec.is_bset || dec.is_bseti ||
                    dec.is_bclr || dec.is_bclri ||
                    dec.is_binv || dec.is_binvi ||
                    dec.is_bext || dec.is_bexti

    when(is_alu_op || is_mul_op || dec.is_atomic) {
       when(dec.is_load) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=LOAD  src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(dec.imm.asUInt)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_store) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=STORE src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(regFile.io.rs2_data)} imm=${Hexadecimal(dec.imm.asUInt)}\n")
       } .elsewhen(dec.is_lr) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=LR    addr=${Hexadecimal(lsu.io.mem_addr)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_sc) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=SC    addr=${Hexadecimal(lsu.io.mem_addr)} data=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amoadd) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOADD addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amoswap) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOSWAP addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amoxor) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOXOR addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amomin) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOMIN  addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amomax) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOMAX  addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(dec.is_amoor) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=AMOOR   addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(is_mul_op) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=MUL   src1=${Hexadecimal(mul.io.src1)} src2=${Hexadecimal(mul.io.src2)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .otherwise {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} type=ALU   src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(alu.io.src2)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       }
    }
  }

  // FP Debug Prints
  val is_f_op = dec.is_fload || dec.is_fstore || dec.is_fadd || dec.is_fsub ||
                dec.is_fmul || dec.is_fdiv || dec.is_fmadd || dec.is_fmv ||
                dec.is_fcvt_f2i || dec.is_fcvt_i2f || dec.is_fsqrt || dec.is_feq || 
                dec.is_flt || dec.is_fle || dec.is_fminmax || dec.is_fsgnj || dec.is_fclass
  
  when(io.in.fire && is_f_op) {
    printf(p"CORE EXECUTE [Cycle ${io.debug_cycle}]: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} [FPU FRONT-END] prd=${io.in.bits.pdest} prs1=${io.in.bits.psrs1} prs2=${io.in.bits.psrs2} prs3=${io.in.bits.psrs3} fsrc1=${Hexadecimal(fsrc1)} fsrc2=${Hexadecimal(fsrc2)} fsrc3=${Hexadecimal(fsrc3)}\n")
  }

  // Handle Multi-cycle (DIV) writeback
  when(div.io.done) {
    regFile.io.wen     := true.B
    regFile.io.rd_addr := io.in.bits.pdest // Multi-cycle should also use pdest
    regFile.io.rd_data := div.io.result
    printf(p"CORE EXECUTE: pc=${Hexadecimal(div_pc_latch)} DIV Result: ${div.io.result} (after stall)\n")
  }

  when(fpdiv.io.done) {
    fpRegFile.io.wen     := true.B
    fpRegFile.io.rd_addr := fpdiv_rd_latch
    fpRegFile.io.rd_data := fpdiv.io.result
    printf(p"CORE EXECUTE: pc=${Hexadecimal(fpdiv_pc_latch)} FPDIV/FSQRT Result: ${Hexadecimal(fpdiv.io.result)} (after stall)\n")
  }

  io.debug_regs := regFile.io.debug_regs
  io.debug_fp_regs := fpRegFile.io.debug_regs
}
