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
    val snptValids = Input(Vec(renameSnapshotNum, Bool()))
    val snptDeqPtr = Input(UInt(log2Up(renameSnapshotNum).W))
  })

  val alu  = Seq.fill(2)(Module(new ALU))
  val bru  = Seq.fill(2)(Module(new BRU))
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
  io.redirect.snapshotIdx := 0.U
  
  fcsr.io.csr_addr  := 0.U
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := 0.U
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  // ---------------- READ STAGE (CYCLE 1) DEFINITIONS ----------------
  val dec0 = io.int_in(0).bits.decode
  val uop0 = io.int_in(0).bits.uop
  val is_div_op0 = dec0.is_div || dec0.is_divu || dec0.is_rem || dec0.is_remu ||
                   dec0.is_divw || dec0.is_divuw || dec0.is_remw || dec0.is_remuw

  val dec1 = io.int_in(1).bits.decode
  val uop1 = io.int_in(1).bits.uop
  val is_div_op1 = dec1.is_div || dec1.is_divu || dec1.is_rem || dec1.is_remu ||
                   dec1.is_divw || dec1.is_divuw || dec1.is_remw || dec1.is_remuw

  val decMem = io.mem_in.bits.decode
  val decFp = io.fp_in.bits.decode
  val uopFp = io.fp_in.bits.uop
  val is_fp_wb_to_int_top = decFp.is_fmv_x_w || decFp.is_fcvt_f2i || decFp.is_feq || decFp.is_flt || decFp.is_fle || decFp.is_fclass

  // Issue Queue ready signals driven by execution unit status
  io.int_in(0).ready := Mux(is_div_op0, div.io.ready, true.B)
  io.int_in(1).ready := Mux(is_div_op1, div.io.ready, true.B)
  io.mem_in.ready := true.B
  io.fp_in.ready := fpdiv.io.ready

  // ---------------- READ-TO-EXECUTE PIPELINE REGISTERS ----------------
  val exe_val0 = RegInit(false.B)
  val exe_uop0 = Reg(new DecodedMicroOp)
  when(io.redirect.valid) {
    exe_val0 := false.B
  } .elsewhen(io.int_in(0).ready) {
    exe_val0 := io.int_in(0).fire
    exe_uop0 := io.int_in(0).bits
  }

  val exe_val1 = RegInit(false.B)
  val exe_uop1 = Reg(new DecodedMicroOp)
  when(io.redirect.valid) {
    exe_val1 := false.B
  } .elsewhen(io.int_in(1).ready) {
    exe_val1 := io.int_in(1).fire
    exe_uop1 := io.int_in(1).bits
  }

  val exe_valMem = RegInit(false.B)
  val exe_uopMem = Reg(new DecodedMicroOp)
  when(io.redirect.valid) {
    exe_valMem := false.B
  } .elsewhen(io.mem_in.ready) {
    exe_valMem := io.mem_in.fire
    exe_uopMem := io.mem_in.bits
  }

  val exe_valFp = RegInit(false.B)
  val exe_uopFp = Reg(new DecodedMicroOp)
  when(io.redirect.valid) {
    exe_valFp := false.B
  } .elsewhen(io.fp_in.ready) {
    exe_valFp := io.fp_in.fire
    exe_uopFp := io.fp_in.bits
  }

  // ---------------- REGISTER FILE ACCESS (CYCLE 1: READ STAGE) ----------------
  regFile.io.raddr(0) := io.int_in(0).bits.psrs1
  regFile.io.raddr(1) := io.int_in(0).bits.psrs2
  regFile.io.raddr(2) := io.int_in(1).bits.psrs1
  regFile.io.raddr(3) := io.int_in(1).bits.psrs2
  regFile.io.raddr(4) := io.mem_in.bits.psrs1
  regFile.io.raddr(5) := io.mem_in.bits.psrs2
  regFile.io.raddr(6) := io.fp_in.bits.psrs1

  fpRegFile.io.raddr(0) := io.fp_in.bits.psrs1
  fpRegFile.io.raddr(1) := io.fp_in.bits.psrs2
  fpRegFile.io.raddr(2) := io.fp_in.bits.psrs3
  fpRegFile.io.raddr(3) := io.mem_in.bits.psrs2

  // Register File Read Data Registers (latched at end of Cycle 1)
  val r_regFile_rdata0 = Reg(UInt(xLen.W))
  val r_regFile_rdata1 = Reg(UInt(xLen.W))
  when(io.int_in(0).ready) {
    r_regFile_rdata0 := regFile.io.rdata(0)
    r_regFile_rdata1 := regFile.io.rdata(1)
  }

  val r_regFile_rdata2 = Reg(UInt(xLen.W))
  val r_regFile_rdata3 = Reg(UInt(xLen.W))
  when(io.int_in(1).ready) {
    r_regFile_rdata2 := regFile.io.rdata(2)
    r_regFile_rdata3 := regFile.io.rdata(3)
  }

  val r_regFile_rdata4 = Reg(UInt(xLen.W))
  val r_regFile_rdata5 = Reg(UInt(xLen.W))
  val r_fpRegFile_rdata3 = Reg(UInt(fLen.W))
  when(io.mem_in.ready) {
    r_regFile_rdata4 := regFile.io.rdata(4)
    r_regFile_rdata5 := regFile.io.rdata(5)
    r_fpRegFile_rdata3 := fpRegFile.io.rdata(3)
  }

  val r_fpRegFile_rdata0 = Reg(UInt(fLen.W))
  val r_fpRegFile_rdata1 = Reg(UInt(fLen.W))
  val r_fpRegFile_rdata2 = Reg(UInt(fLen.W))
  val r_regFile_rdata6 = Reg(UInt(xLen.W))
  when(io.fp_in.ready) {
    r_fpRegFile_rdata0 := fpRegFile.io.rdata(0)
    r_fpRegFile_rdata1 := fpRegFile.io.rdata(1)
    r_fpRegFile_rdata2 := fpRegFile.io.rdata(2)
    r_regFile_rdata6 := regFile.io.rdata(6)
  }

  // ---------------- BYPASS NETWORK DEFINITIONS (CYCLE 2: EXECUTE STAGE) ----------------
  val exe_dec0 = exe_uop0.decode
  val exe_uop_raw0 = exe_uop0.uop
  val exe_is_div_op0 = exe_dec0.is_div || exe_dec0.is_divu || exe_dec0.is_rem || exe_dec0.is_remu ||
                       exe_dec0.is_divw || exe_dec0.is_divuw || exe_dec0.is_remw || exe_dec0.is_remuw
  val exe_is_mul_op0 = exe_dec0.is_mul || exe_dec0.is_mulh || exe_dec0.is_mulhsu || exe_dec0.is_mulhu || exe_dec0.is_mulw
  val exe_is_link0 = exe_dec0.is_jal || exe_dec0.is_jalr
  val exe_link_addr0 = exe_uop_raw0.pc + Mux(exe_uop_raw0.pre.is_rvc, 2.U, 4.U)
  val exe_result0 = Mux(exe_dec0.is_fused_lui_addi, alu(0).io.result, Mux(exe_is_mul_op0, mul.io.result, alu(0).io.result))

  val exe_dec1 = exe_uop1.decode
  val exe_uop_raw1 = exe_uop1.uop
  val exe_is_div_op1 = exe_dec1.is_div || exe_dec1.is_divu || exe_dec1.is_rem || exe_dec1.is_remu ||
                       exe_dec1.is_divw || exe_dec1.is_divuw || exe_dec1.is_remw || exe_dec1.is_remuw
  val exe_is_mul_op1 = exe_dec1.is_mul || exe_dec1.is_mulh || exe_dec1.is_mulhsu || exe_dec1.is_mulhu || exe_dec1.is_mulw
  val exe_is_link1 = exe_dec1.is_jal || exe_dec1.is_jalr
  val exe_link_addr1 = exe_uop_raw1.pc + Mux(exe_uop_raw1.pre.is_rvc, 2.U, 4.U)
  val exe_result1 = Mux(exe_is_mul_op1, mul.io.result, alu(1).io.result)

  val exe_decMem = exe_uopMem.decode
  val exe_decFp = exe_uopFp.decode
  val exe_uop_rawFp = exe_uopFp.uop
  val exe_is_fp_wb_to_int_top = exe_decFp.is_fmv_x_w || exe_decFp.is_fcvt_f2i || exe_decFp.is_feq || exe_decFp.is_flt || exe_decFp.is_fle || exe_decFp.is_fclass

  // Raw bypass signals (combinational outputs from current execution cycle)
  val wb0_valid = exe_val0 && exe_uop0.pdest =/= 0.U && !exe_is_div_op0 && ((!exe_dec0.is_branch) || exe_is_link0)
  val wb0_pdest = exe_uop0.pdest
  val wb0_data  = Mux(exe_is_link0, exe_link_addr0, exe_result0)

  val wb1_valid = exe_val1 && exe_uop1.pdest =/= 0.U && !exe_is_div_op1 && ((!exe_dec1.is_branch) || exe_is_link1)
  val wb1_pdest = exe_uop1.pdest
  val wb1_data  = Mux(exe_is_link1, exe_link_addr1, exe_result1)

  val wb2_valid = div.io.done && div_rd_latch =/= 0.U
  val wb2_pdest = div_rd_latch
  val wb2_data  = div.io.result

  val wb3_valid = exe_valMem && exe_uopMem.pdest =/= 0.U && !exe_decMem.is_fload && (exe_decMem.is_load || exe_decMem.is_atomic)
  val wb3_pdest = exe_uopMem.pdest
  val wb3_data  = lsu.io.result

  val wb4_valid = exe_valFp && exe_uopFp.pdest =/= 0.U && exe_is_fp_wb_to_int_top
  val wb4_pdest = exe_uopFp.pdest
  val wb4_data  = fpmisc.io.result_int

  // Registered bypass signals (representing values that finished executing last cycle)
  val r_wb0_valid = RegNext(wb0_valid, false.B)
  val r_wb0_pdest = RegNext(wb0_pdest, 0.U)
  val r_wb0_data  = RegNext(wb0_data, 0.U)

  val r_wb1_valid = RegNext(wb1_valid, false.B)
  val r_wb1_pdest = RegNext(wb1_pdest, 0.U)
  val r_wb1_data  = RegNext(wb1_data, 0.U)

  val r_wb2_valid = RegNext(wb2_valid, false.B)
  val r_wb2_pdest = RegNext(wb2_pdest, 0.U)
  val r_wb2_data  = RegNext(wb2_data, 0.U)

  val r_wb3_valid = RegNext(wb3_valid, false.B)
  val r_wb3_pdest = RegNext(wb3_pdest, 0.U)
  val r_wb3_data  = RegNext(wb3_data, 0.U)

  val r_wb4_valid = RegNext(wb4_valid, false.B)
  val r_wb4_pdest = RegNext(wb4_pdest, 0.U)
  val r_wb4_data  = RegNext(wb4_data, 0.U)

  case class BypassChannel(valid: Bool, pdest: UInt, data: UInt)

  val bypassChannels = Seq(
    BypassChannel(r_wb0_valid, r_wb0_pdest, r_wb0_data),
    BypassChannel(r_wb1_valid, r_wb1_pdest, r_wb1_data),
    BypassChannel(r_wb2_valid, r_wb2_pdest, r_wb2_data),
    BypassChannel(r_wb3_valid, r_wb3_pdest, r_wb3_data),
    BypassChannel(r_wb4_valid, r_wb4_pdest, r_wb4_data)
  )

  // Bypass function: selects the latest available value (checking registered staging outputs first)
  def bypass(raddr: UInt, rdata: UInt): UInt = {
    val matches = bypassChannels.map(ch => ch.valid && (ch.pdest === raddr) && (raddr =/= 0.U))
    val datas   = bypassChannels.map(_.data)
    MuxCase(rdata, matches.zip(datas))
  }


  // ---------------- INT 0 ----------------
  val src0_1 = bypass(exe_uop0.psrs1, r_regFile_rdata0)
  val src0_2 = bypass(exe_uop0.psrs2, r_regFile_rdata1)

  alu(0).io.src1 := src0_1
  alu(0).io.src2 := Mux(exe_dec0.is_fused_lui_addi, (exe_dec0.imm + exe_uop_raw0.pc.asSInt).asUInt,
                 Mux(exe_dec0.is_addi || exe_dec0.is_jalr, exe_dec0.imm.asUInt, src0_2))
  alu(0).io.pc   := exe_uop_raw0.pc
  alu(0).io.dec  := exe_dec0

  bru(0).io.src1 := src0_1
  bru(0).io.src2 := Mux(exe_dec0.is_jalr || exe_dec0.is_branch, src0_2, exe_dec0.imm.asUInt)
  bru(0).io.pc   := exe_uop_raw0.pc
  bru(0).io.is_rvc := exe_uop_raw0.pre.is_rvc
  bru(0).io.pred_taken := exe_uop_raw0.is_predicted_taken
  bru(0).io.dec  := exe_dec0

  // ---------------- INT 1 ----------------
  val src1_1 = bypass(exe_uop1.psrs1, r_regFile_rdata2)
  val src1_2 = bypass(exe_uop1.psrs2, r_regFile_rdata3)

  alu(1).io.src1 := src1_1
  alu(1).io.src2 := Mux(exe_dec1.is_fused_lui_addi, (exe_dec1.imm + exe_uop_raw1.pc.asSInt).asUInt,
                 Mux(exe_dec1.is_addi || exe_dec1.is_jalr, exe_dec1.imm.asUInt, src1_2))
  alu(1).io.pc   := exe_uop_raw1.pc
  alu(1).io.dec  := exe_dec1

  bru(1).io.src1 := src1_1
  bru(1).io.src2 := Mux(exe_dec1.is_jalr || exe_dec1.is_branch, src1_2, exe_dec1.imm.asUInt)
  bru(1).io.pc   := exe_uop_raw1.pc
  bru(1).io.is_rvc := exe_uop_raw1.pre.is_rvc
  bru(1).io.pred_taken := exe_uop_raw1.is_predicted_taken
  bru(1).io.dec  := exe_dec1

  // Share Multiplier and Divider inputs
  mul.io.src1 := Mux(exe_is_mul_op0, src0_1, src1_1)
  mul.io.src2 := Mux(exe_is_mul_op0, src0_2, src1_2)
  mul.io.dec  := Mux(exe_is_mul_op0, exe_dec0, exe_dec1)

  div.io.src1 := Mux(exe_is_div_op0, src0_1, src1_1)
  div.io.src2 := Mux(exe_is_div_op0, src0_2, src1_2)
  div.io.dec  := Mux(exe_is_div_op0, exe_dec0, exe_dec1)
  div.io.fire := Mux(exe_is_div_op0, exe_val0, exe_val1)
  div.io.flush := io.redirect.valid

  // Age-Priority Redirect/Flush Filter
  val r0_snap = exe_uop0.snapshotIdx
  val r1_snap = exe_uop1.snapshotIdx

  val dist0 = Mux(r0_snap >= io.snptDeqPtr, r0_snap - io.snptDeqPtr, r0_snap - io.snptDeqPtr + renameSnapshotNum.U)
  val dist1 = Mux(r1_snap >= io.snptDeqPtr, r1_snap - io.snptDeqPtr, r1_snap - io.snptDeqPtr + renameSnapshotNum.U)
  val lane0_is_older = dist0 < dist1

  val r0_valid = exe_val0 && (bru(0).io.exc_valid || bru(0).io.mispredict) && io.snptValids(r0_snap)
  val r1_valid = exe_val1 && (bru(1).io.exc_valid || bru(1).io.mispredict) && io.snptValids(r1_snap)

  when(r0_valid && r1_valid) {
    io.redirect.valid := true.B
    io.redirect.target := Mux(lane0_is_older, bru(0).io.target, bru(1).io.target)
    io.redirect.epoch  := Mux(lane0_is_older, exe_uop_raw0.epoch, exe_uop_raw1.epoch)
    io.redirect.is_exception := Mux(lane0_is_older, bru(0).io.exc_valid, bru(1).io.exc_valid)
    io.redirect.exc_cause    := Mux(lane0_is_older, bru(0).io.exc_cause, bru(1).io.exc_cause)
    io.redirect.snapshotIdx  := Mux(lane0_is_older, r0_snap, r1_snap)
  } .elsewhen(r0_valid) {
    io.redirect.valid := true.B
    io.redirect.target := bru(0).io.target
    io.redirect.epoch  := exe_uop_raw0.epoch
    io.redirect.is_exception := bru(0).io.exc_valid
    io.redirect.exc_cause    := bru(0).io.exc_cause
    io.redirect.snapshotIdx  := r0_snap
  } .elsewhen(r1_valid) {
    io.redirect.valid := true.B
    io.redirect.target := bru(1).io.target
    io.redirect.epoch  := exe_uop_raw1.epoch
    io.redirect.is_exception := bru(1).io.exc_valid
    io.redirect.exc_cause    := bru(1).io.exc_cause
    io.redirect.snapshotIdx  := r1_snap
  }

  // Writebacks and latch registers
  when(exe_val0) {
    when(exe_uop0.pdest =/= 0.U && !exe_is_div_op0) {
      regFile.io.wen(0) := (!exe_dec0.is_branch) || exe_is_link0
      regFile.io.waddr(0) := exe_uop0.pdest
      regFile.io.wdata(0) := Mux(exe_is_link0, exe_link_addr0, exe_result0)
    }
    when(exe_is_div_op0) { div_rd_latch := exe_uop0.pdest }
  }

  val wu0_valid = io.int_in(0).fire && io.int_in(0).bits.pdest =/= 0.U && !is_div_op0
  val r_wu0_valid = RegNext(wu0_valid, false.B)
  val r_wu0_pdest = RegNext(io.int_in(0).bits.pdest, 0.U)
  io.wakeup(0).valid := r_wu0_valid
  io.wakeup(0).pdest := r_wu0_pdest

  when(exe_val1) {
    when(exe_uop1.pdest =/= 0.U && !exe_is_div_op1) {
      regFile.io.wen(1) := (!exe_dec1.is_branch) || exe_is_link1
      regFile.io.waddr(1) := exe_uop1.pdest
      regFile.io.wdata(1) := Mux(exe_is_link1, exe_link_addr1, exe_result1)
    }
    when(exe_is_div_op1) { div_rd_latch := exe_uop1.pdest }
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
  val srcMem_1 = bypass(exe_uopMem.psrs1, r_regFile_rdata4)
  val srcMem_2 = bypass(exe_uopMem.psrs2, r_regFile_rdata5)
  val fsrcMem_2 = r_fpRegFile_rdata3

  lsu.io.src1 := srcMem_1
  lsu.io.src2 := Mux(exe_decMem.is_fstore, fsrcMem_2, srcMem_2)
  lsu.io.imm  := exe_decMem.imm
  lsu.io.dec  := exe_decMem

  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen && exe_valMem
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

  when(exe_valMem) {
    when(exe_uopMem.pdest =/= 0.U) {
      when(exe_decMem.is_fload) {
        fpRegFile.io.wen(2) := true.B
        fpRegFile.io.waddr(2) := exe_uopMem.pdest
        fpRegFile.io.wdata(2) := lsu.io.result
      }.otherwise {
        regFile.io.wen(3) := exe_decMem.is_load || exe_decMem.is_atomic
        regFile.io.waddr(3) := exe_uopMem.pdest
        regFile.io.wdata(3) := lsu.io.result
      }
    }
  }

  val wuMem_valid = io.mem_in.fire && io.mem_in.bits.pdest =/= 0.U && !decMem.is_fload
  io.wakeup(3).valid := wuMem_valid
  io.wakeup(3).pdest := io.mem_in.bits.pdest

  // ---------------- FP ----------------
  val fsrc1 = r_fpRegFile_rdata0
  val fsrc2 = r_fpRegFile_rdata1
  val fsrc3 = r_fpRegFile_rdata2
  val srcFp_1 = bypass(exe_uopFp.psrs1, r_regFile_rdata6)

  fpu.io.src1 := fsrc1
  fpu.io.src2 := fsrc2
  fpu.io.src3 := fsrc3
  fpu.io.dec  := exe_decFp

  fpdiv.io.src1 := fsrc1
  fpdiv.io.src2 := fsrc2
  fpdiv.io.dec  := exe_decFp
  fpdiv.io.fire := exe_valFp && (exe_decFp.is_fdiv || exe_decFp.is_fsqrt)
  fpdiv.io.flush := io.redirect.valid

  fpmisc.io.src1 := fsrc1
  fpmisc.io.src2 := fsrc2
  fpmisc.io.rs1_int := srcFp_1
  fpmisc.io.dec  := exe_decFp
  fpmisc.io.inst := exe_uop_rawFp.inst_raw

  val exe_is_fp_wb_to_fp = exe_decFp.is_fadd || exe_decFp.is_fsub || exe_decFp.is_fmul || exe_decFp.is_fmadd ||
                           exe_decFp.is_fmv_w_x || exe_decFp.is_fcvt_i2f || exe_decFp.is_fsgnj || exe_decFp.is_fminmax
  val exe_is_fp_wb_to_int = exe_decFp.is_fmv_x_w || exe_decFp.is_fcvt_f2i || exe_decFp.is_feq || exe_decFp.is_flt || exe_decFp.is_fle || exe_decFp.is_fclass
  val is_fp_wb_to_int = decFp.is_fmv_x_w || decFp.is_fcvt_f2i || decFp.is_feq || decFp.is_flt || decFp.is_fle || decFp.is_fclass

  when(exe_valFp) {
    when(exe_uopFp.pdest =/= 0.U) {
      when(exe_is_fp_wb_to_fp) {
        fpRegFile.io.wen(0) := true.B
        fpRegFile.io.waddr(0) := exe_uopFp.pdest
        fpRegFile.io.wdata(0) := fpmisc.io.result_fp
      }
      when(exe_is_fp_wb_to_int) {
        regFile.io.wen(4) := true.B
        regFile.io.waddr(4) := exe_uopFp.pdest
        regFile.io.wdata(4) := fpmisc.io.result_int
      }
    }
    when(exe_decFp.is_fdiv || exe_decFp.is_fsqrt) { fpdiv_rd_latch := exe_uopFp.pdest }

    fcsr.io.csr_addr  := exe_uop_rawFp.inst_raw(31, 20)
    fcsr.io.csr_wen   := false.B
    fcsr.io.csr_wdata := srcFp_1
  }

  val wuFp_valid = io.fp_in.fire && io.fp_in.bits.pdest =/= 0.U && is_fp_wb_to_int
  val r_wuFp_valid = RegNext(wuFp_valid, false.B)
  val r_wuFp_pdest = RegNext(io.fp_in.bits.pdest, 0.U)
  io.wakeup(4).valid := r_wuFp_valid
  io.wakeup(4).pdest := r_wuFp_pdest

  when(fpdiv.io.done) {
    fpRegFile.io.wen(1) := true.B
    fpRegFile.io.waddr(1) := fpdiv_rd_latch
    fpRegFile.io.wdata(1) := fpdiv.io.result
    // Wakeups for FP Regs are separate or we should put them on the wakeup bus if it's unified.
    // Zaqal seems to only have integer wakeups right now since fp wakeups were combined previously.
    // For now we don't wake up FP registers explicitly if they are always ready or handled in IQ.
  }

  for (i <- 0 until 5) {
    when(regFile.io.wen(i) && regFile.io.waddr(i) =/= 0.U) {
      printf(p"  [REGFILE WRITE Port $i]: addr=${regFile.io.waddr(i)} data=${Hexadecimal(regFile.io.wdata(i))} at cycle=${io.debug_cycle}\n")
    }
  }

  io.debug_regs := regFile.io.debug_regs
  io.debug_fp_regs := fpRegFile.io.debug_regs
}
