package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend.fu._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val int_in = Vec(2, Flipped(Decoupled(new DecodedMicroOp)))
    val mem_in = Flipped(Decoupled(new DecodedMicroOp))
    val fp_in = Flipped(Decoupled(new DecodedMicroOp))
    val redirect = Output(new BPURedirect)
    val debug_cycle = Input(UInt(64.W))
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val wakeup = Vec(5, Output(new WakeupBus))
  })

  val alu  = Seq.fill(2)(Module(new ALU))
  val bru  = Module(new BRU)
  val lsu  = Module(new LSU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)
  val fpu  = Module(new FPU)
  val fpdiv = Module(new FPDivider)
  val fpmisc = Module(new FPMisc)
  val dmem = Module(new DataMem)
  val fcsr = Module(new FCSR)

  val div_rd_latch = RegInit(0.U(phyRegIdxWidth.W))
  val fpdiv_rd_latch = RegInit(0.U(phyRegIdxWidth.W))

  val regFile = Module(new RegFile(7, 5))
  val fpRegFile = Module(new FPRegFile(4, 3))

  for (i <- 0 until 5) { regFile.io.wen(i) := false.B; regFile.io.waddr(i) := 0.U; regFile.io.wdata(i) := 0.U }
  for (i <- 0 until 3) { fpRegFile.io.wen(i) := false.B; fpRegFile.io.waddr(i) := 0.U; fpRegFile.io.wdata(i) := 0.U }
  for (i <- 0 until 5) { io.wakeup(i).valid := false.B; io.wakeup(i).pdest := 0.U }
  io.redirect.valid := false.B
  io.redirect.target := 0.U
  io.redirect.epoch := 0.U
  io.redirect.is_exception := false.B
  io.redirect.exc_cause := 0.U
  
  fcsr.io.csr_addr  := 0.U
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := 0.U
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  // ---------------- INT 0 ----------------
  regFile.io.raddr(0) := io.int_in(0).bits.psrs1
  regFile.io.raddr(1) := io.int_in(0).bits.psrs2
  val src0_1 = regFile.io.rdata(0)
  val src0_2 = regFile.io.rdata(1)
  val dec0 = io.int_in(0).bits.decode
  val uop0 = io.int_in(0).bits.uop

  // Define division and multiplication operations checks
  val is_div_op0 = dec0.is_div || dec0.is_divu || dec0.is_rem || dec0.is_remu ||
                   dec0.is_divw || dec0.is_divuw || dec0.is_remw || dec0.is_remuw
  val is_mul_op0 = dec0.is_mul || dec0.is_mulh || dec0.is_mulhsu || dec0.is_mulhu || dec0.is_mulw

  alu(0).io.src1 := src0_1
  alu(0).io.src2 := Mux(dec0.is_fused_lui_addi, (dec0.imm + uop0.pc.asSInt).asUInt,
                 Mux(dec0.is_addi || dec0.is_jalr, dec0.imm.asUInt, src0_2))
  alu(0).io.pc   := uop0.pc
  alu(0).io.dec  := dec0

  bru.io.src1 := src0_1
  bru.io.src2 := Mux(dec0.is_jalr || dec0.is_branch, src0_2, dec0.imm.asUInt)
  bru.io.pc   := uop0.pc
  bru.io.is_rvc := uop0.pre.is_rvc
  bru.io.pred_taken := uop0.is_predicted_taken
  bru.io.dec  := dec0

  // ---------------- INT 1 ----------------
  regFile.io.raddr(2) := io.int_in(1).bits.psrs1
  regFile.io.raddr(3) := io.int_in(1).bits.psrs2
  val src1_1 = regFile.io.rdata(2)
  val src1_2 = regFile.io.rdata(3)
  val dec1 = io.int_in(1).bits.decode
  val uop1 = io.int_in(1).bits.uop

  val is_div_op1 = dec1.is_div || dec1.is_divu || dec1.is_rem || dec1.is_remu ||
                   dec1.is_divw || dec1.is_divuw || dec1.is_remw || dec1.is_remuw
  val is_mul_op1 = dec1.is_mul || dec1.is_mulh || dec1.is_mulhsu || dec1.is_mulhu || dec1.is_mulw

  alu(1).io.src1 := src1_1
  alu(1).io.src2 := Mux(dec1.is_fused_lui_addi, (dec1.imm + uop1.pc.asSInt).asUInt,
                 Mux(dec1.is_addi || dec1.is_jalr, dec1.imm.asUInt, src1_2))
  alu(1).io.pc   := uop1.pc
  alu(1).io.dec  := dec1

  // Share Multiplier and Divider inputs
  mul.io.src1 := Mux(is_mul_op0, src0_1, src1_1)
  mul.io.src2 := Mux(is_mul_op0, src0_2, src1_2)
  mul.io.dec  := Mux(is_mul_op0, dec0, dec1)

  div.io.src1 := Mux(is_div_op0, src0_1, src1_1)
  div.io.src2 := Mux(is_div_op0, src0_2, src1_2)
  div.io.dec  := Mux(is_div_op0, dec0, dec1)
  div.io.fire := Mux(is_div_op0, io.int_in(0).fire, io.int_in(1).fire)

  io.int_in(0).ready := Mux(is_div_op0, div.io.ready, true.B)
  io.int_in(1).ready := Mux(is_div_op1, div.io.ready, true.B)

  // Writebacks and latch registers
  when(io.int_in(0).fire) {
    val is_link = dec0.is_jal || dec0.is_jalr
    val link_addr = uop0.pc + Mux(uop0.pre.is_rvc, 2.U, 4.U)
    val result = Mux(dec0.is_fused_lui_addi, alu(0).io.result, Mux(is_mul_op0, mul.io.result, alu(0).io.result))

    when(io.int_in(0).bits.pdest =/= 0.U && !is_div_op0) {
      regFile.io.wen(0) := (!dec0.is_branch) || is_link
      regFile.io.waddr(0) := io.int_in(0).bits.pdest
      regFile.io.wdata(0) := Mux(is_link, link_addr, result)
    }
    when(is_div_op0) { div_rd_latch := io.int_in(0).bits.pdest }

    when(bru.io.exc_valid || bru.io.mispredict) {
      io.redirect.valid := true.B
      io.redirect.target := bru.io.target
      io.redirect.epoch  := uop0.epoch
      io.redirect.is_exception := bru.io.exc_valid
      io.redirect.exc_cause    := bru.io.exc_cause
    }
  }

  val wu0_valid = io.int_in(0).fire && io.int_in(0).bits.pdest =/= 0.U && !is_div_op0
  val r_wu0_valid = RegNext(wu0_valid, false.B)
  val r_wu0_pdest = RegNext(io.int_in(0).bits.pdest, 0.U)
  io.wakeup(0).valid := r_wu0_valid
  io.wakeup(0).pdest := r_wu0_pdest

  when(io.int_in(1).fire) {
    val result = Mux(is_mul_op1, mul.io.result, alu(1).io.result)
    when(io.int_in(1).bits.pdest =/= 0.U && !is_div_op1) {
      regFile.io.wen(1) := true.B
      regFile.io.waddr(1) := io.int_in(1).bits.pdest
      regFile.io.wdata(1) := result
    }
    when(is_div_op1) { div_rd_latch := io.int_in(1).bits.pdest }
  }

  val wu1_valid = io.int_in(1).fire && io.int_in(1).bits.pdest =/= 0.U && !is_div_op1
  val r_wu1_valid = RegNext(wu1_valid, false.B)
  val r_wu1_pdest = RegNext(io.int_in(1).bits.pdest, 0.U)
  io.wakeup(1).valid := r_wu1_valid
  io.wakeup(1).pdest := r_wu1_pdest

  when(div.io.done) {
    regFile.io.wen(2) := true.B
    regFile.io.waddr(2) := div_rd_latch
    regFile.io.wdata(2) := div.io.result
  }

  val wuDiv_valid = div.io.done && div_rd_latch =/= 0.U
  val r_wuDiv_valid = RegNext(wuDiv_valid, false.B)
  val r_wuDiv_pdest = RegNext(div_rd_latch, 0.U)
  io.wakeup(2).valid := r_wuDiv_valid
  io.wakeup(2).pdest := r_wuDiv_pdest

  // ---------------- MEM ----------------
  regFile.io.raddr(4) := io.mem_in.bits.psrs1
  regFile.io.raddr(5) := io.mem_in.bits.psrs2
  fpRegFile.io.raddr(3) := io.mem_in.bits.psrs2
  
  val srcMem_1 = regFile.io.rdata(4)
  val srcMem_2 = regFile.io.rdata(5)
  val fsrcMem_2 = fpRegFile.io.rdata(3)
  val decMem = io.mem_in.bits.decode

  lsu.io.src1 := srcMem_1
  lsu.io.src2 := Mux(decMem.is_fstore, fsrcMem_2, srcMem_2)
  lsu.io.imm  := decMem.imm
  lsu.io.dec  := decMem

  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen && io.mem_in.fire
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

  io.mem_in.ready := true.B

  when(io.mem_in.fire) {
    when(io.mem_in.bits.pdest =/= 0.U) {
      when(decMem.is_fload) {
        fpRegFile.io.wen(2) := true.B
        fpRegFile.io.waddr(2) := io.mem_in.bits.pdest
        fpRegFile.io.wdata(2) := lsu.io.result
      }.otherwise {
        regFile.io.wen(3) := decMem.is_load || decMem.is_atomic
        regFile.io.waddr(3) := io.mem_in.bits.pdest
        regFile.io.wdata(3) := lsu.io.result
      }
    }
  }
  
  val wuMem_valid = io.mem_in.fire && io.mem_in.bits.pdest =/= 0.U && !decMem.is_fload
  val r_wuMem_valid = RegNext(wuMem_valid, false.B)
  val r_wuMem_pdest = RegNext(io.mem_in.bits.pdest, 0.U)
  io.wakeup(3).valid := r_wuMem_valid
  io.wakeup(3).pdest := r_wuMem_pdest
  // We omit fload wakeup from integer WakeupBus since it wakes up FP regs

  // ---------------- FP ----------------
  fpRegFile.io.raddr(0) := io.fp_in.bits.psrs1
  fpRegFile.io.raddr(1) := io.fp_in.bits.psrs2
  fpRegFile.io.raddr(2) := io.fp_in.bits.psrs3
  regFile.io.raddr(6) := io.fp_in.bits.psrs1 // for fmv.w.x
  
  val fsrc1 = fpRegFile.io.rdata(0)
  val fsrc2 = fpRegFile.io.rdata(1)
  val fsrc3 = fpRegFile.io.rdata(2)
  val srcFp_1 = regFile.io.rdata(6)
  
  val decFp = io.fp_in.bits.decode
  val uopFp = io.fp_in.bits.uop

  fpu.io.src1 := fsrc1
  fpu.io.src2 := fsrc2
  fpu.io.src3 := fsrc3
  fpu.io.dec  := decFp

  fpdiv.io.src1 := fsrc1
  fpdiv.io.src2 := fsrc2
  fpdiv.io.dec  := decFp
  fpdiv.io.fire := io.fp_in.fire

  fpmisc.io.src1 := fsrc1
  fpmisc.io.src2 := fsrc2
  fpmisc.io.rs1_int := srcFp_1
  fpmisc.io.dec  := decFp
  fpmisc.io.inst := uopFp.inst_raw

  io.fp_in.ready := fpdiv.io.ready
  
  val is_fp_wb_to_fp = decFp.is_fadd || decFp.is_fsub || decFp.is_fmul || decFp.is_fmadd ||
                       decFp.is_fmv_w_x || decFp.is_fcvt_i2f || decFp.is_fsgnj || decFp.is_fminmax
  val is_fp_wb_to_int = decFp.is_fmv_x_w || decFp.is_fcvt_f2i || decFp.is_feq || decFp.is_flt || decFp.is_fle || decFp.is_fclass

  when(io.fp_in.fire) {
    when(io.fp_in.bits.pdest =/= 0.U) {
      when(is_fp_wb_to_fp) {
        fpRegFile.io.wen(0) := true.B
        fpRegFile.io.waddr(0) := io.fp_in.bits.pdest
        fpRegFile.io.wdata(0) := fpmisc.io.result_fp
      }
      when(is_fp_wb_to_int) {
        regFile.io.wen(4) := true.B
        regFile.io.waddr(4) := io.fp_in.bits.pdest
        regFile.io.wdata(4) := fpmisc.io.result_int
      }
    }
    when(decFp.is_fdiv || decFp.is_fsqrt) { fpdiv_rd_latch := io.fp_in.bits.pdest }
    
    fcsr.io.csr_addr  := uopFp.inst_raw(31, 20)
    fcsr.io.csr_wen   := false.B
    fcsr.io.csr_wdata := srcFp_1
  }
  
  val wuFp_valid = io.fp_in.fire && io.fp_in.bits.pdest =/= 0.U && is_fp_wb_to_int
  val r_wuFp_valid = RegNext(wuFp_valid, false.B)
  val r_wuFp_pdest = RegNext(io.fp_in.bits.pdest, 0.U)
  io.wakeup(4).valid := r_wuFp_valid
  io.wakeup(4).pdest := r_wuFp_pdest
  // Omit FP-to-FP wakeup from integer WakeupBus

  when(fpdiv.io.done) {
    fpRegFile.io.wen(1) := true.B
    fpRegFile.io.waddr(1) := fpdiv_rd_latch
    fpRegFile.io.wdata(1) := fpdiv.io.result
    // Wakeups for FP Regs are separate or we should put them on the wakeup bus if it's unified.
    // Zaqal seems to only have integer wakeups right now since fp wakeups were combined previously.
    // For now we don't wake up FP registers explicitly if they are always ready or handled in IQ.
  }

  io.debug_regs := regFile.io.debug_regs
  io.debug_fp_regs := fpRegFile.io.debug_regs
}
