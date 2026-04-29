package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend.fu._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
    val debug_regs = Output(Vec(logicalRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(32, UInt(fLen.W)))
    val debug_cycle = Input(UInt(64.W))
  })

  // Coordination state
  val div_rd_latch = RegInit(0.U(5.W))
  val div_pc_latch = RegInit(0.U(xLen.W))
  val fpdiv_rd_latch = RegInit(0.U(5.W))
  val fpdiv_pc_latch = RegInit(0.U(xLen.W))

  // 1. Decoder & Register File
  val decoder = Module(new Decoder)
  val regFile = Module(new RegFile)
  val fpRegFile = Module(new FPRegFile)
  val fcsr      = Module(new FCSR)
  
  decoder.io.inst := io.in.bits.inst_raw
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := decoder.io.out.rs2

  fpRegFile.io.rs1_addr := decoder.io.out.rs1
  fpRegFile.io.rs2_addr := decoder.io.out.rs2
  fpRegFile.io.rs3_addr := decoder.io.out.rs3
  
  val src1 = regFile.io.rs1_data
  val fsrc1 = fpRegFile.io.rs1_data
  val fsrc2 = fpRegFile.io.rs2_data
  val fsrc3 = fpRegFile.io.rs3_data
  val is_imm_type = decoder.io.out.is_addi || decoder.io.out.is_andi || decoder.io.out.is_ori || decoder.io.out.is_xori ||
                    decoder.io.out.is_slli || decoder.io.out.is_srli || decoder.io.out.is_srai ||
                    decoder.io.out.is_slliw || decoder.io.out.is_srliw || decoder.io.out.is_sraiw ||
                    decoder.io.out.is_slti || decoder.io.out.is_sltiu || decoder.io.out.is_addiw ||
                    decoder.io.out.is_lui  || decoder.io.out.is_auipc || decoder.io.out.is_load || decoder.io.out.is_atomic ||
                    decoder.io.out.is_rori || decoder.io.out.is_roriw ||
                    decoder.io.out.is_bseti || decoder.io.out.is_bclri || decoder.io.out.is_binvi || decoder.io.out.is_bexti

  val operand2 = Mux(is_imm_type, decoder.io.out.imm.asUInt, regFile.io.rs2_data)

  val is_mul_op = decoder.io.out.is_mul || decoder.io.out.is_mulh || decoder.io.out.is_mulhsu || decoder.io.out.is_mulhu || decoder.io.out.is_mulw
  val is_div_op = decoder.io.out.is_div || decoder.io.out.is_divu || decoder.io.out.is_rem || decoder.io.out.is_remu ||
                  decoder.io.out.is_divw || decoder.io.out.is_divuw || decoder.io.out.is_remw || decoder.io.out.is_remuw

  // 2. Functional Units
  val alu  = Module(new ALU)
  val bru  = Module(new BRU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)
  val lsu  = Module(new LSU)
  val dmem = Module(new DataMem)
  val fpu  = Module(new FPU)
  val fpdiv = Module(new FPDivider)

  // 3. Connect FUs
  alu.io.src1 := src1
  alu.io.src2 := operand2
  alu.io.pc   := io.in.bits.pc
  alu.io.dec  := decoder.io.out
  
  // ... (bru, mul, div wiring remains similar)
  bru.io.src1 := src1
  bru.io.src2 := regFile.io.rs2_data
  bru.io.dec  := decoder.io.out
  bru.io.pc   := io.in.bits.pc
  bru.io.is_rvc := io.in.bits.pre.is_rvc
  bru.io.pred_taken := io.in.bits.is_predicted_taken

  mul.io.src1 := src1
  mul.io.src2 := regFile.io.rs2_data
  mul.io.dec  := decoder.io.out

  div.io.src1 := src1
  div.io.src2 := regFile.io.rs2_data
  div.io.dec  := decoder.io.out
  div.io.fire := io.in.fire

  lsu.io.src1 := src1
  lsu.io.src2 := Mux(decoder.io.out.is_fstore, fsrc2, regFile.io.rs2_data)
  lsu.io.imm  := decoder.io.out.imm
  lsu.io.dec  := decoder.io.out
  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

  // 4. Connect FPU
  fpu.io.src1 := fsrc1
  fpu.io.src2 := fsrc2
  fpu.io.src3 := fsrc3
  fpu.io.dec  := decoder.io.out

  fpdiv.io.src1 := fsrc1
  fpdiv.io.src2 := fsrc2
  fpdiv.io.dec  := decoder.io.out
  fpdiv.io.fire := io.in.fire

  // 4. Coordination & Handshake
  io.in.ready := div.io.ready && fpdiv.io.ready
  
  // Default RegFile write values
  regFile.io.wen     := false.B
  regFile.io.rd_addr := decoder.io.out.rd
  regFile.io.rd_data := 0.U

  fpRegFile.io.wen     := false.B
  fpRegFile.io.rd_addr := decoder.io.out.rd
  fpRegFile.io.rd_data := 0.U

  // FCSR defaults
  fcsr.io.csr_addr  := io.in.bits.inst_raw(31, 20)
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := src1
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  // FP Writeback Support
  val is_fp_wb_to_fp = decoder.io.out.is_fload || decoder.io.out.is_fadd || decoder.io.out.is_fsub ||
                       decoder.io.out.is_fmul || decoder.io.out.is_fmadd ||
                       decoder.io.out.is_fmv_w_x || decoder.io.out.is_fcvt_i2f ||
                       decoder.io.out.is_fsgnj || decoder.io.out.is_fminmax
                       
  val is_fpdiv_op = decoder.io.out.is_fdiv || decoder.io.out.is_fsqrt
  
  val is_fp_wb_to_int = decoder.io.out.is_fmv_x_w || decoder.io.out.is_fcvt_f2i ||
                        decoder.io.out.is_feq || decoder.io.out.is_flt || decoder.io.out.is_fle ||
                        decoder.io.out.is_fclass

  // RISC-V 32-bit float NaN-boxing (if fLen=64)
  def nanBox(data: UInt): UInt = {
    if (fLen == 64) Cat("hffffffff".U(32.W), data(31, 0)) else data
  }

  // Branch redirection
  io.redirect.valid  := false.B
  io.redirect.target := bru.io.target
  io.redirect.epoch  := io.in.bits.epoch
  io.redirect.is_exception := bru.io.exc_valid
  io.redirect.exc_cause    := bru.io.exc_cause

  when(io.in.fire) {
    printf(p"CORE EXECUTE [Cycle ${io.debug_cycle}]: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} is_rvc=${io.in.bits.pre.is_rvc} epoch=${io.in.bits.epoch}\n")
    // Writeback for single-cycle instructions
    when(decoder.io.out.rd =/= 0.U) {
      val is_link = decoder.io.out.is_jal || decoder.io.out.is_jalr
      val link_addr = io.in.bits.pc + Mux(io.in.bits.pre.is_rvc, 2.U, 4.U)
      val result = Mux(is_mul_op, mul.io.result,
                   Mux(decoder.io.out.is_load || decoder.io.out.is_atomic, lsu.io.result, 
                   Mux(is_fp_wb_to_int, fsrc1, // Placeholder for move/compare results
                   alu.io.result)))
                   
      regFile.io.wen     := ((!decoder.io.out.is_branch && !is_div_op && !decoder.io.out.is_store && 
                             !decoder.io.out.is_fload && !is_fp_wb_to_fp) || 
                             is_link || decoder.io.out.is_atomic || is_fp_wb_to_int)
      regFile.io.rd_data := Mux(is_link, link_addr, result)

      // FP Register File Writeback
      when(is_fp_wb_to_fp) {
        fpRegFile.io.wen := true.B
        fpRegFile.io.rd_data := Mux(decoder.io.out.is_fload, nanBox(lsu.io.result),
                                Mux(decoder.io.out.is_fmv_w_x || decoder.io.out.is_fcvt_i2f, nanBox(src1),
                                fpu.io.result))
      }
    }

    // Day 27: Basic Trap Redirection
    // Note: This is hardcoded to 0x80000100 for now because the CSR file (mtvec)
    // has not been implemented yet. On Day 28, this will be replaced by a CSR lookup.
    val trapVector = "h80000100".U
    when(bru.io.exc_valid) {
      io.redirect.valid  := true.B
      io.redirect.target := trapVector
      printf(p"CORE EXECUTE: EXCEPTION! Instruction Address Misaligned at pc=${Hexadecimal(io.in.bits.pc)} target=${Hexadecimal(bru.io.target)} -> Redir to TrapVector=${Hexadecimal(trapVector)}\n")
    } .elsewhen(bru.io.mispredict) {
      io.redirect.valid := true.B
      printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} target=${Hexadecimal(bru.io.target)} pred_taken=${io.in.bits.is_predicted_taken} actual_taken=${bru.io.taken}\n")
    } .elsewhen(decoder.io.out.is_branch) {
      printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} Branch Correct\n")
    }

    // Latch DIV metadata (unchanged)
    when(is_div_op) {
      div_rd_latch := decoder.io.out.rd
      div_pc_latch := io.in.bits.pc
    }
    when(is_fpdiv_op) {
      fpdiv_rd_latch := decoder.io.out.rd
      fpdiv_pc_latch := io.in.bits.pc
    }

    // Printfs for ALU/MUL
    val is_alu_op = decoder.io.out.is_addi || decoder.io.out.is_add || decoder.io.out.is_andi || decoder.io.out.is_ori || 
                    decoder.io.out.is_xori || decoder.io.out.is_and || decoder.io.out.is_or || decoder.io.out.is_xor ||
                    decoder.io.out.is_sll  || decoder.io.out.is_srl || decoder.io.out.is_sra ||
                    decoder.io.out.is_slli || decoder.io.out.is_srli || decoder.io.out.is_srai ||
                    decoder.io.out.is_sllw || decoder.io.out.is_srlw || decoder.io.out.is_sraw ||
                    decoder.io.out.is_slliw || decoder.io.out.is_srliw || decoder.io.out.is_sraiw ||
                    decoder.io.out.is_slt  || decoder.io.out.is_sltu || decoder.io.out.is_slti || decoder.io.out.is_sltiu ||
                    decoder.io.out.is_sub  || decoder.io.out.is_addw || decoder.io.out.is_subw || decoder.io.out.is_addiw ||
                    decoder.io.out.is_lui  || decoder.io.out.is_auipc || decoder.io.out.is_load || decoder.io.out.is_store ||
                    decoder.io.out.is_sh1add || decoder.io.out.is_sh2add || decoder.io.out.is_sh3add ||
                    decoder.io.out.is_sh1add_uw || decoder.io.out.is_sh2add_uw || decoder.io.out.is_sh3add_uw ||
                    decoder.io.out.is_clz || decoder.io.out.is_ctz || decoder.io.out.is_cpop ||
                    decoder.io.out.is_clzw || decoder.io.out.is_ctzw || decoder.io.out.is_cpopw ||
                    decoder.io.out.is_andn || decoder.io.out.is_orn || decoder.io.out.is_xorn ||
                    decoder.io.out.is_rol || decoder.io.out.is_ror || decoder.io.out.is_rori ||
                    decoder.io.out.is_rolw || decoder.io.out.is_rorw || decoder.io.out.is_roriw ||
                    decoder.io.out.is_rev8 || decoder.io.out.is_orc_b || decoder.io.out.is_sextb ||
                    decoder.io.out.is_sexth || decoder.io.out.is_zexth ||
                    decoder.io.out.is_min || decoder.io.out.is_max || decoder.io.out.is_minu ||
                    decoder.io.out.is_maxu ||
                    decoder.io.out.is_bset || decoder.io.out.is_bseti ||
                    decoder.io.out.is_bclr || decoder.io.out.is_bclri ||
                    decoder.io.out.is_binv || decoder.io.out.is_binvi ||
                    decoder.io.out.is_bext || decoder.io.out.is_bexti

    when(is_alu_op || is_mul_op || decoder.io.out.is_atomic) {
       when(decoder.io.out.is_load) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=LOAD  src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(decoder.io.out.imm.asUInt)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_store) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=STORE src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(regFile.io.rs2_data)} imm=${Hexadecimal(decoder.io.out.imm.asUInt)}\n")
       } .elsewhen(decoder.io.out.is_lr) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=LR    addr=${Hexadecimal(lsu.io.mem_addr)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_sc) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=SC    addr=${Hexadecimal(lsu.io.mem_addr)} data=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amoadd) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOADD addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amoswap) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOSWAP addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amoxor) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOXOR addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amomin) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOMIN  addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amomax) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOMAX  addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_amoor) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=AMOOR   addr=${Hexadecimal(lsu.io.mem_addr)} src2=${Hexadecimal(regFile.io.rs2_data)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(is_mul_op) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=MUL   src1=${Hexadecimal(mul.io.src1)} src2=${Hexadecimal(mul.io.src2)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .otherwise {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=ALU   src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(alu.io.src2)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       }
    }
  }

  // FP Debug Prints
  val is_f_op = decoder.io.out.is_fload || decoder.io.out.is_fstore || decoder.io.out.is_fadd || decoder.io.out.is_fsub ||
                decoder.io.out.is_fmul || decoder.io.out.is_fdiv || decoder.io.out.is_fmadd || decoder.io.out.is_fmv ||
                decoder.io.out.is_fcvt_f2i || decoder.io.out.is_fcvt_i2f || decoder.io.out.is_fsqrt || decoder.io.out.is_feq || decoder.io.out.is_flt || decoder.io.out.is_fle
  
  when(io.in.fire && is_f_op) {
    printf(p"CORE EXECUTE [Cycle ${io.debug_cycle}]: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} [FPU FRONT-END] frd=${decoder.io.out.rd} frs1=${decoder.io.out.rs1} frs2=${decoder.io.out.rs2} frs3=${decoder.io.out.rs3} fsrc1=${Hexadecimal(fsrc1)} fsrc2=${Hexadecimal(fsrc2)} fsrc3=${Hexadecimal(fsrc3)}\n")
  }

  // Handle Multi-cycle (DIV) writeback
  when(div.io.done) {
    regFile.io.wen     := true.B
    regFile.io.rd_addr := div_rd_latch
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
