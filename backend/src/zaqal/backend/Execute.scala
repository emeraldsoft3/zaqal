package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend.fu._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new DecodedMicroOp))
    val redirect = Output(new BPURedirect)
    val debug_cycle = Input(UInt(64.W))
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(xLen.W)))
  })

  // 1. Instantiate Sub-Modules
  val alu  = Module(new ALU)
  val bru  = Module(new BRU)
  val lsu  = Module(new LSU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)
  val fpu  = Module(new FPU)
  val fpdiv = Module(new FPDivider)
  val fpmisc = Module(new FPMisc)
  val dmem = Module(new DataMem)
  val fcsr = Module(new FCSR)

  // Register File Latches
  val div_rd_latch = RegInit(0.U(phyRegIdxWidth.W))
  val div_pc_latch = RegInit(0.U(xLen.W))
  val fpdiv_rd_latch = RegInit(0.U(phyRegIdxWidth.W))
  val fpdiv_pc_latch = RegInit(0.U(xLen.W))

  // 1. Register File
  val regFile = Module(new RegFile)
  val fpRegFile = Module(new FPRegFile)
  
  val dec = io.in.bits.decode
  val uop = io.in.bits.uop

  regFile.io.rs1_addr := io.in.bits.psrs1
  regFile.io.rs2_addr := io.in.bits.psrs2
  regFile.io.rd_addr  := io.in.bits.pdest

  fpRegFile.io.rs1_addr := io.in.bits.psrs1
  fpRegFile.io.rs2_addr := io.in.bits.psrs2
  fpRegFile.io.rs3_addr := io.in.bits.psrs3
  fpRegFile.io.rd_addr  := io.in.bits.pdest
  
  val src1 = regFile.io.rs1_data
  val src2 = regFile.io.rs2_data
  val fsrc1 = fpRegFile.io.rs1_data
  val fsrc2 = fpRegFile.io.rs2_data
  val fsrc3 = fpRegFile.io.rs3_data

  // 2. Connect Modules
  alu.io.src1 := src1
  alu.io.src2 := Mux(dec.is_fused_lui_addi, (dec.imm + uop.pc.asSInt).asUInt,
                 Mux(dec.is_addi || dec.is_load || dec.is_store || dec.is_jalr, dec.imm.asUInt,
                 src2))
  alu.io.pc   := uop.pc
  alu.io.dec  := dec

  bru.io.src1 := src1
  bru.io.src2 := Mux(dec.is_jalr || dec.is_branch, src2, dec.imm.asUInt)
  bru.io.pc   := uop.pc
  bru.io.is_rvc := uop.pre.is_rvc
  bru.io.pred_taken := uop.is_predicted_taken
  bru.io.dec  := dec

  mul.io.src1 := src1
  mul.io.src2 := src2
  mul.io.dec  := dec

  div.io.src1 := src1
  div.io.src2 := src2
  div.io.dec  := dec
  div.io.fire := io.in.fire

  lsu.io.src1 := Mux(dec.is_fused_alu_store, src2, src1)
  lsu.io.src2 := Mux(dec.is_fused_alu_store, alu.io.result, 
                 Mux(dec.is_fstore, fsrc2, src2))
  lsu.io.imm  := Mux(dec.is_fused_alu_store, dec.fused_imm, dec.imm)
  lsu.io.dec  := dec
  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen && io.in.fire
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

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

  // 3. Coordination & Handshake
  io.in.ready := div.io.ready && fpdiv.io.ready
  
  // Default Writebacks
  regFile.io.wen     := false.B
  regFile.io.rd_data := 0.U
  fpRegFile.io.wen     := false.B
  fpRegFile.io.rd_data := 0.U

  fcsr.io.csr_addr  := uop.inst_raw(31, 20)
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := src1
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  val is_fp_wb_to_fp = dec.is_fload || dec.is_fadd || dec.is_fsub || dec.is_fmul || dec.is_fmadd ||
                       dec.is_fmv_w_x || dec.is_fcvt_i2f || dec.is_fsgnj || dec.is_fminmax
  val is_fp_wb_to_int = dec.is_fmv_x_w || dec.is_fcvt_f2i || dec.is_feq || dec.is_flt || dec.is_fle || dec.is_fclass

  // Branch Redirection
  io.redirect.valid  := false.B
  io.redirect.target := bru.io.target
  io.redirect.epoch  := uop.epoch
  io.redirect.is_exception := bru.io.exc_valid
  io.redirect.exc_cause    := bru.io.exc_cause

  when(io.in.fire) {
    printf(p"CORE EXECUTE [Cycle ${io.debug_cycle}]: pc=${Hexadecimal(uop.pc)} inst=${Hexadecimal(uop.inst_raw)} fused=${dec.is_fused}\n")
    
    when(io.in.bits.pdest =/= 0.U) {
      val is_link = dec.is_jal || dec.is_jalr
      val link_addr = uop.pc + Mux(uop.pre.is_rvc, 2.U, 4.U)
      val result = Mux(dec.is_fused_lui_addi, alu.io.result,
                   Mux(dec.is_fused_load_alu, (lsu.io.result.asSInt + dec.fused_imm).asUInt,
                   Mux(dec.is_load || dec.is_atomic, lsu.io.result,
                   Mux(dec.is_mul, mul.io.result,
                   Mux(is_fp_wb_to_int, fpmisc.io.result_int, alu.io.result)))))

      regFile.io.wen     := (!dec.is_branch && !dec.is_div && !dec.is_store && !dec.is_fload && !is_fp_wb_to_fp) || 
                             is_link || dec.is_atomic || is_fp_wb_to_int
      regFile.io.rd_data := Mux(is_link, link_addr, result)
      
      when(dec.is_fused_load_alu) {
        printf(p"CORE EXECUTE: FUSED LW+ADDI! mem=${Hexadecimal(lsu.io.result)} imm=${dec.fused_imm} res=${Hexadecimal(result)}\n")
      }

      when(is_fp_wb_to_fp) {
        fpRegFile.io.wen := true.B
        fpRegFile.io.rd_data := Mux(dec.is_flw, lsu.io.result, 
                                Mux(dec.is_fld, lsu.io.result, fpmisc.io.result_fp))
      }
    }

    // Exceptions & Mispredicts
    when(bru.io.exc_valid || bru.io.mispredict) {
      io.redirect.valid := true.B
    }

    // DIV Metadata
    when(dec.is_div) { div_rd_latch := io.in.bits.pdest; div_pc_latch := uop.pc }
    when(dec.is_fdiv || dec.is_fsqrt) { fpdiv_rd_latch := io.in.bits.pdest; fpdiv_pc_latch := uop.pc }
  }

  // Multi-cycle writeback
  when(div.io.done) {
    regFile.io.wen := true.B
    regFile.io.rd_addr := div_rd_latch
    regFile.io.rd_data := div.io.result
  }
  when(fpdiv.io.done) {
    fpRegFile.io.wen := true.B
    fpRegFile.io.rd_addr := fpdiv_rd_latch
    fpRegFile.io.rd_data := fpdiv.io.result
  }

  io.debug_regs := regFile.io.debug_regs
  io.debug_fp_regs := fpRegFile.io.debug_regs
}
