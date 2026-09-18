package zaqal.backend.exu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Kunminghu Parity Execution Queue Interfaces
    val int_in = Vec(4, Flipped(Decoupled(new DecodedMicroOp)))
    val mem_in = Vec(3, Flipped(Decoupled(new DecodedMicroOp)))
    val fp_in  = Vec(4, Flipped(Decoupled(new DecodedMicroOp)))

    val redirect = Output(new BPURedirect)
    val bpu_update = Output(new BPUUpdate)
    val exuWriteback = Output(Vec(14, Valid(new ExuOutput)))
    val debug_cycle = Input(UInt(64.W))
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val wakeup = Vec(14, Output(new WakeupBus))
    val snptValids = Input(Vec(renameSnapshotNum, Bool()))
    val snptDeqPtr = Input(UInt(log2Up(renameSnapshotNum).W))
    val dcache_req = Decoupled(new Bundle {
      val addr = UInt(xLen.W)
      val data = UInt(xLen.W)
      val is_write = Bool()
      val load_id = UInt(6.W)
    })
    val dcache_resp = Flipped(Decoupled(new Bundle {
      val data = UInt(xLen.W)
      val load_id = UInt(6.W)
    }))

    // LSQ Commit & Allocation Interfaces
    val robCommits = Input(new RobCommitIO)
    val robCommitIdx = Input(Vec(decodeWidth, UInt(log2Up(128).W)))
    val robDeqPtr = Input(UInt(log2Up(128).W))
    val sq_enq = Vec(decodeWidth, Flipped(Decoupled(new Bundle {
      val robIdx = UInt(log2Up(128).W)
      val snapshotIdx = UInt(log2Up(renameSnapshotNum).W)
    })))
    val lq_enq = Vec(decodeWidth, Flipped(Decoupled(new Bundle {
      val robIdx = UInt(log2Up(128).W)
      val snapshotIdx = UInt(log2Up(renameSnapshotNum).W)
      val pc = UInt(xLen.W)
    })))
    val sq_count = Output(UInt(5.W))
    val lq_count = Output(UInt(5.W))

    // XiangShan MDP Connections
    val memPredUpdate = Output(new MemPredUpdateReq)
    val store_resolved = Output(Valid(UInt(log2Up(128).W)))
  })

  // ---------------- EXECUTION UNITS (KUNMINGHU PARITY) ----------------
  val alu  = Seq.fill(4)(Module(new ALU))
  val bru  = Seq.fill(2)(Module(new BRU))
  val lsu  = Seq.fill(3)(Module(new LSU))
  val mul  = Seq.fill(2)(Module(new Multiplier))
  val div  = Seq.fill(2)(Module(new Divider))
  val fpu  = Seq.fill(4)(Module(new FPU))
  val fpdiv = Module(new FPDivider)
  val fpmisc = Seq.fill(2)(Module(new FPMisc))
  val dmem = Module(new DataMem)
  val tlb  = Seq.fill(3)(Module(new FastTLB))
  val fcsr = Module(new FCSR)

  // ---------------- LOAD / STORE QUEUES ----------------
  val sq = Module(new zaqal.backend.lsu.StoreQueue(16))
  val lq = Module(new zaqal.backend.lsu.LoadQueue(16))

  sq.io.enq <> io.sq_enq
  lq.io.enq <> io.lq_enq
  io.sq_count := sq.io.count
  io.lq_count := lq.io.count

  sq.io.robHeadPtr := io.robDeqPtr
  sq.io.snptDeqPtr := io.snptDeqPtr
  lq.io.snptDeqPtr := io.snptDeqPtr
  lq.io.robHeadPtr := io.robDeqPtr

  for (i <- 0 until decodeWidth) {
    sq.io.commit.valid(i)  := io.robCommits.commitValid(i)
    sq.io.commit.robIdx(i) := io.robCommitIdx(i)
    lq.io.commit.valid(i)  := io.robCommits.commitValid(i)
    lq.io.commit.robIdx(i) := io.robCommitIdx(i)
  }

  sq.io.redirect.valid        := io.redirect.valid
  sq.io.redirect.is_exception := io.redirect.is_exception
  sq.io.redirect.snapshotIdx  := io.redirect.snapshotIdx
  sq.io.redirect.robIdx       := io.redirect.robIdx

  lq.io.redirect.valid        := io.redirect.valid
  lq.io.redirect.is_exception := io.redirect.is_exception
  lq.io.redirect.snapshotIdx  := io.redirect.snapshotIdx
  lq.io.redirect.robIdx       := io.redirect.robIdx

  // ---------------- AGU-TO-CACHE PIPELINE REGISTERS (MEM STAGE 2) ----------------
  val r_agu_val   = RegInit(VecInit(Seq.fill(3)(false.B)))
  val r_agu_uop   = Reg(Vec(3, new DecodedMicroOp))
  val r_agu_vaddr = Reg(Vec(3, UInt(xLen.W)))
  val r_agu_paddr = Reg(Vec(3, UInt(xLen.W)))
  val r_agu_src2  = Reg(Vec(3, UInt(xLen.W)))
  val r_agu_fsrc2 = Reg(Vec(3, UInt(fLen.W)))

  // Multi-cycle Dividers tracking
  val div_rd_latch = RegInit(VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val div_snap_latch = RegInit(VecInit(Seq.fill(2)(0.U(log2Up(renameSnapshotNum).W))))
  val div_robIdx_latch = RegInit(VecInit(Seq.fill(2)(0.U(log2Up(128).W))))

  val fpdiv_rd_latch = RegInit(0.U(phyRegIdxWidth.W))
  val fpdiv_snap_latch = RegInit(0.U(log2Up(renameSnapshotNum).W))
  val fpdiv_robIdx_latch = RegInit(0.U(log2Up(128).W))

  // ---------------- REGISTER FILES & REGISTER CACHES ----------------
  // Integer PRF: 16 Read Ports, 11 Write Ports
  // FP PRF: 15 Read Ports, 8 Write Ports
  val regFile = Module(new RegFile(numReadPorts = 16, numWritePorts = 11))
  val fpRegFile = Module(new FPRegFile(numReadPorts = 15, numWritePorts = 8))

  val intRC = Module(new zaqal.backend.rename.RegisterCache(32, numReadPorts = 16, numWritePorts = 11))
  val fpRC  = Module(new zaqal.backend.rename.RegisterCache(32, numReadPorts = 15, numWritePorts = 8))

  intRC.io.flush := io.redirect.valid
  fpRC.io.flush  := io.redirect.valid

  // Write-back Staging Registers (Cycle 3) for Integer PRF
  val r_regFile_wen   = RegInit(VecInit(Seq.fill(11)(false.B)))
  val r_regFile_waddr = RegInit(VecInit(Seq.fill(11)(0.U(phyRegIdxWidth.W))))
  val r_regFile_wdata = RegInit(VecInit(Seq.fill(11)(0.U(xLen.W))))

  val next_regFile_wen   = WireDefault(VecInit(Seq.fill(11)(false.B)))
  val next_regFile_waddr = WireDefault(VecInit(Seq.fill(11)(0.U(phyRegIdxWidth.W))))
  val next_regFile_wdata = WireDefault(VecInit(Seq.fill(11)(0.U(xLen.W))))

  for (i <- 0 until 11) {
    r_regFile_wen(i)   := next_regFile_wen(i)
    r_regFile_waddr(i) := next_regFile_waddr(i)
    r_regFile_wdata(i) := next_regFile_wdata(i)

    regFile.io.wen(i)   := r_regFile_wen(i)
    regFile.io.waddr(i) := r_regFile_waddr(i)
    regFile.io.wdata(i) := r_regFile_wdata(i)

    intRC.io.wen(i)     := r_regFile_wen(i)
    intRC.io.waddr(i)   := r_regFile_waddr(i)
    intRC.io.wdata(i)   := r_regFile_wdata(i)
  }

  for (i <- 0 until 8) {
    fpRegFile.io.wen(i)   := false.B
    fpRegFile.io.waddr(i) := 0.U
    fpRegFile.io.wdata(i) := 0.U

    fpRC.io.wen(i)        := false.B
    fpRC.io.waddr(i)      := 0.U
    fpRC.io.wdata(i)      := 0.U
  }

  for (i <- 0 until 14) {
    io.wakeup(i).valid := false.B
    io.wakeup(i).pdest := 0.U
    io.wakeup(i).is_fp := false.B
  }

  io.redirect.valid := false.B
  io.redirect.target := 0.U
  io.redirect.epoch := 0.U
  io.redirect.is_exception := false.B
  io.redirect.exc_cause := 0.U
  io.redirect.snapshotIdx := 0.U
  io.redirect.pc := 0.U
  io.redirect.taken := false.B
  io.redirect.is_cfi := false.B
  io.redirect.is_jal := false.B
  io.redirect.is_jalr := false.B
  io.redirect.ftqPtr := 0.U
  io.redirect.robIdx := 0.U

  io.memPredUpdate.valid := false.B
  io.memPredUpdate.ldpc  := 0.U
  io.memPredUpdate.stpc  := 0.U
  io.store_resolved.valid := false.B
  io.store_resolved.bits  := 0.U

  io.bpu_update.valid := false.B
  io.bpu_update.pc := 0.U
  io.bpu_update.target := 0.U
  io.bpu_update.taken := false.B
  io.bpu_update.is_cfi := false.B
  io.bpu_update.is_jal := false.B
  io.bpu_update.is_jalr := false.B
  io.bpu_update.ftqPtr := 0.U
  io.bpu_update.robIdx := 0.U
  
  fcsr.io.csr_addr  := 0.U
  fcsr.io.csr_wen   := false.B
  fcsr.io.csr_wdata := 0.U
  fcsr.io.set_flags := false.B
  fcsr.io.flags_to_set := 0.U

  // ---------------- READ STAGE (CYCLE 1) DEFINITIONS ----------------
  val decInt = (0 until 4).map(i => io.int_in(i).bits.decode)
  val is_div_op0 = decInt(0).is_div || decInt(0).is_divu || decInt(0).is_rem || decInt(0).is_remu ||
                   decInt(0).is_divw || decInt(0).is_divuw || decInt(0).is_remw || decInt(0).is_remuw
  val is_mul_op0 = decInt(0).is_mul || decInt(0).is_mulh || decInt(0).is_mulhsu || decInt(0).is_mulhu || decInt(0).is_mulw

  val is_div_op1 = decInt(1).is_div || decInt(1).is_divu || decInt(1).is_rem || decInt(1).is_remu ||
                   decInt(1).is_divw || decInt(1).is_divuw || decInt(1).is_remw || decInt(1).is_remuw
  val is_mul_op1 = decInt(1).is_mul || decInt(1).is_mulh || decInt(1).is_mulhsu || decInt(1).is_mulhu || decInt(1).is_mulw

  val decMem = (0 until 3).map(i => io.mem_in(i).bits.decode)
  val decFp  = (0 until 4).map(i => io.fp_in(i).bits.decode)

  // Register Cache Hits
  val hit_int = Wire(Vec(4, Bool()))
  val wait_int = RegInit(VecInit(Seq.fill(4)(false.B)))
  for (i <- 0 until 4) {
    hit_int(i) := intRC.io.rhits(i * 2) && intRC.io.rhits(i * 2 + 1)
    when(io.int_in(i).valid && !wait_int(i) && !hit_int(i)) { wait_int(i) := true.B } .otherwise { wait_int(i) := false.B }
  }
  io.int_in(0).ready := Mux(is_div_op0, div(0).io.ready, true.B) && (hit_int(0) || wait_int(0))
  io.int_in(1).ready := Mux(is_div_op1, div(1).io.ready, true.B) && (hit_int(1) || wait_int(1))
  io.int_in(2).ready := (hit_int(2) || wait_int(2))
  io.int_in(3).ready := (hit_int(3) || wait_int(3))

  val hit_mem = Wire(Vec(3, Bool()))
  val wait_mem = RegInit(VecInit(Seq.fill(3)(false.B)))
  for (i <- 0 until 3) {
    hit_mem(i) := intRC.io.rhits(8 + i * 2) && intRC.io.rhits(8 + i * 2 + 1) && fpRC.io.rhits(12 + i)
    when(io.mem_in(i).valid && !wait_mem(i) && !hit_mem(i)) { wait_mem(i) := true.B } .otherwise { wait_mem(i) := false.B }
    io.mem_in(i).ready := (hit_mem(i) || wait_mem(i))
  }

  val hit_fp = Wire(Vec(4, Bool()))
  val wait_fp = RegInit(VecInit(Seq.fill(4)(false.B)))
  for (i <- 0 until 4) {
    val is_fp_int_src = decFp(i).is_fmv_w_x || decFp(i).is_fmv_d_x || decFp(i).is_fcvt_i2f
    val is_fp_fma     = decFp(i).is_fmadd || decFp(i).is_fmsub || decFp(i).is_fnmadd || decFp(i).is_fnmsub
    val fp_int_hit    = if (i >= 2) intRC.io.rhits(14 + (i - 2)) else false.B
    val fp_src_hit    = fpRC.io.rhits(i * 3) && fpRC.io.rhits(i * 3 + 1) && Mux(is_fp_fma, fpRC.io.rhits(i * 3 + 2), true.B)
    hit_fp(i) := Mux(is_fp_int_src, fp_int_hit, fp_src_hit)
    when(io.fp_in(i).valid && !wait_fp(i) && !hit_fp(i)) { wait_fp(i) := true.B } .otherwise { wait_fp(i) := false.B }
  }
  io.fp_in(0).ready := (hit_fp(0) || wait_fp(0))
  io.fp_in(1).ready := (hit_fp(1) || wait_fp(1))
  io.fp_in(2).ready := (hit_fp(2) || wait_fp(2))
  io.fp_in(3).ready := fpdiv.io.ready && (hit_fp(3) || wait_fp(3))

  // ---------------- READ-TO-EXECUTE PIPELINE REGISTERS ----------------
  def is_younger_than_redirect(snapIdx: UInt): Bool = {
    val deqPtr = io.snptDeqPtr
    val restoreIdx = io.redirect.snapshotIdx
    def circDist(ptr: UInt): UInt = Mux(ptr >= deqPtr, ptr - deqPtr, ptr + renameSnapshotNum.U - deqPtr)
    circDist(snapIdx) > circDist(restoreIdx)
  }

  val exe_val_int = RegInit(VecInit(Seq.fill(4)(false.B)))
  val exe_uop_int = Reg(Vec(4, new DecodedMicroOp))
  for (i <- 0 until 4) {
    val next_val = io.int_in(i).fire
    val next_uop = Mux(io.int_in(i).ready, io.int_in(i).bits, exe_uop_int(i))
    when(io.redirect.valid && is_younger_than_redirect(next_uop.snapshotIdx)) {
      exe_val_int(i) := false.B
    } .otherwise {
      exe_val_int(i) := next_val
    }
    when(io.int_in(i).ready) { exe_uop_int(i) := io.int_in(i).bits }
  }

  val exe_val_mem = RegInit(VecInit(Seq.fill(3)(false.B)))
  val exe_uop_mem = Reg(Vec(3, new DecodedMicroOp))
  for (i <- 0 until 3) {
    val next_val = io.mem_in(i).fire
    val next_uop = Mux(io.mem_in(i).ready, io.mem_in(i).bits, exe_uop_mem(i))
    when(io.redirect.valid && is_younger_than_redirect(next_uop.snapshotIdx)) {
      exe_val_mem(i) := false.B
    } .otherwise {
      exe_val_mem(i) := next_val
    }
    when(io.mem_in(i).ready) { exe_uop_mem(i) := io.mem_in(i).bits }
  }

  val exe_val_fp = RegInit(VecInit(Seq.fill(4)(false.B)))
  val exe_uop_fp = Reg(Vec(4, new DecodedMicroOp))
  for (i <- 0 until 4) {
    val next_val = io.fp_in(i).fire
    val next_uop = Mux(io.fp_in(i).ready, io.fp_in(i).bits, exe_uop_fp(i))
    when(io.redirect.valid && is_younger_than_redirect(next_uop.snapshotIdx)) {
      exe_val_fp(i) := false.B
    } .otherwise {
      exe_val_fp(i) := next_val
    }
    when(io.fp_in(i).ready) { exe_uop_fp(i) := io.fp_in(i).bits }
  }

  // ---------------- REGISTER FILE ACCESS (CYCLE 1: READ STAGE) ----------------
  // INT read addresses
  for (i <- 0 until 4) {
    intRC.io.raddr(i * 2)     := io.int_in(i).bits.psrs1; regFile.io.raddr(i * 2)     := io.int_in(i).bits.psrs1
    intRC.io.raddr(i * 2 + 1) := io.int_in(i).bits.psrs2; regFile.io.raddr(i * 2 + 1) := io.int_in(i).bits.psrs2
  }
  for (i <- 0 until 3) {
    intRC.io.raddr(8 + i * 2)     := io.mem_in(i).bits.psrs1; regFile.io.raddr(8 + i * 2)     := io.mem_in(i).bits.psrs1
    intRC.io.raddr(8 + i * 2 + 1) := io.mem_in(i).bits.psrs2; regFile.io.raddr(8 + i * 2 + 1) := io.mem_in(i).bits.psrs2
  }
  intRC.io.raddr(14) := io.fp_in(2).bits.psrs1; regFile.io.raddr(14) := io.fp_in(2).bits.psrs1
  intRC.io.raddr(15) := io.fp_in(3).bits.psrs1; regFile.io.raddr(15) := io.fp_in(3).bits.psrs1

  // FP read addresses
  for (i <- 0 until 4) {
    fpRC.io.raddr(i * 3)     := io.fp_in(i).bits.psrs1; fpRegFile.io.raddr(i * 3)     := io.fp_in(i).bits.psrs1
    fpRC.io.raddr(i * 3 + 1) := io.fp_in(i).bits.psrs2; fpRegFile.io.raddr(i * 3 + 1) := io.fp_in(i).bits.psrs2
    fpRC.io.raddr(i * 3 + 2) := io.fp_in(i).bits.psrs3; fpRegFile.io.raddr(i * 3 + 2) := io.fp_in(i).bits.psrs3
  }
  for (i <- 0 until 3) {
    fpRC.io.raddr(12 + i) := io.mem_in(i).bits.psrs2; fpRegFile.io.raddr(12 + i) := io.mem_in(i).bits.psrs2
  }

  // Register File Read Data Registers (latched at end of Cycle 1)
  val r_int_rdata = Reg(Vec(16, UInt(xLen.W)))
  for (i <- 0 until 4) {
    when(io.int_in(i).ready) {
      r_int_rdata(i * 2)     := Mux(hit_int(i), intRC.io.rdata(i * 2),     regFile.io.rdata(i * 2))
      r_int_rdata(i * 2 + 1) := Mux(hit_int(i), intRC.io.rdata(i * 2 + 1), regFile.io.rdata(i * 2 + 1))
    }
  }
  for (i <- 0 until 3) {
    when(io.mem_in(i).ready) {
      r_int_rdata(8 + i * 2)     := Mux(hit_mem(i), intRC.io.rdata(8 + i * 2),     regFile.io.rdata(8 + i * 2))
      r_int_rdata(8 + i * 2 + 1) := Mux(hit_mem(i), intRC.io.rdata(8 + i * 2 + 1), regFile.io.rdata(8 + i * 2 + 1))
    }
  }
  when(io.fp_in(2).ready) { r_int_rdata(14) := Mux(intRC.io.rhits(14), intRC.io.rdata(14), regFile.io.rdata(14)) }
  when(io.fp_in(3).ready) { r_int_rdata(15) := Mux(intRC.io.rhits(15), intRC.io.rdata(15), regFile.io.rdata(15)) }

  val r_fp_rdata = Reg(Vec(15, UInt(fLen.W)))
  for (i <- 0 until 4) {
    when(io.fp_in(i).ready) {
      r_fp_rdata(i * 3)     := Mux(fpRC.io.rhits(i * 3),     fpRC.io.rdata(i * 3),     fpRegFile.io.rdata(i * 3))
      r_fp_rdata(i * 3 + 1) := Mux(fpRC.io.rhits(i * 3 + 1), fpRC.io.rdata(i * 3 + 1), fpRegFile.io.rdata(i * 3 + 1))
      r_fp_rdata(i * 3 + 2) := Mux(fpRC.io.rhits(i * 3 + 2), fpRC.io.rdata(i * 3 + 2), fpRegFile.io.rdata(i * 3 + 2))
    }
  }
  for (i <- 0 until 3) {
    when(io.mem_in(i).ready) {
      r_fp_rdata(12 + i) := Mux(fpRC.io.rhits(12 + i), fpRC.io.rdata(12 + i), fpRegFile.io.rdata(12 + i))
    }
  }

  // ---------------- BYPASS NETWORK (CYCLE 2: EXECUTE STAGE) ----------------
  val exe_dec_int = (0 until 4).map(i => exe_uop_int(i).decode)
  val exe_uop_raw_int = (0 until 4).map(i => exe_uop_int(i).uop)

  val exe_is_div_op0 = exe_dec_int(0).is_div || exe_dec_int(0).is_divu || exe_dec_int(0).is_rem || exe_dec_int(0).is_remu ||
                       exe_dec_int(0).is_divw || exe_dec_int(0).is_divuw || exe_dec_int(0).is_remw || exe_dec_int(0).is_remuw
  val exe_is_mul_op0 = exe_dec_int(0).is_mul || exe_dec_int(0).is_mulh || exe_dec_int(0).is_mulhsu || exe_dec_int(0).is_mulhu || exe_dec_int(0).is_mulw
  val exe_is_link0   = exe_dec_int(0).is_jal || exe_dec_int(0).is_jalr
  val exe_link_addr0 = exe_uop_raw_int(0).pc + Mux(exe_uop_raw_int(0).pre.is_rvc, 2.U, 4.U)

  val exe_is_div_op1 = exe_dec_int(1).is_div || exe_dec_int(1).is_divu || exe_dec_int(1).is_rem || exe_dec_int(1).is_remu ||
                       exe_dec_int(1).is_divw || exe_dec_int(1).is_divuw || exe_dec_int(1).is_remw || exe_dec_int(1).is_remuw
  val exe_is_mul_op1 = exe_dec_int(1).is_mul || exe_dec_int(1).is_mulh || exe_dec_int(1).is_mulhsu || exe_dec_int(1).is_mulhu || exe_dec_int(1).is_mulw
  val exe_is_link1   = exe_dec_int(1).is_jal || exe_dec_int(1).is_jalr
  val exe_link_addr1 = exe_uop_raw_int(1).pc + Mux(exe_uop_raw_int(1).pre.is_rvc, 2.U, 4.U)

  // Combinational ALU writeback signals
  val wb_alu_val  = Wire(Vec(4, Bool()))
  val wb_alu_dest = Wire(Vec(4, UInt(phyRegIdxWidth.W)))
  val wb_alu_data = Wire(Vec(4, UInt(xLen.W)))

  wb_alu_val(0)  := exe_val_int(0) && exe_uop_int(0).pdest =/= 0.U && !exe_is_div_op0 && ((!exe_dec_int(0).is_branch) || exe_is_link0)
  wb_alu_dest(0) := exe_uop_int(0).pdest
  wb_alu_data(0) := Mux(exe_is_link0, exe_link_addr0, alu(0).io.result)

  wb_alu_val(1)  := exe_val_int(1) && exe_uop_int(1).pdest =/= 0.U && !exe_is_div_op1 && ((!exe_dec_int(1).is_branch) || exe_is_link1)
  wb_alu_dest(1) := exe_uop_int(1).pdest
  wb_alu_data(1) := Mux(exe_is_link1, exe_link_addr1, alu(1).io.result)

  wb_alu_val(2)  := exe_val_int(2) && exe_uop_int(2).pdest =/= 0.U && !exe_dec_int(2).is_branch
  wb_alu_dest(2) := exe_uop_int(2).pdest
  wb_alu_data(2) := alu(2).io.result

  wb_alu_val(3)  := exe_val_int(3) && exe_uop_int(3).pdest =/= 0.U && !exe_dec_int(3).is_branch
  wb_alu_dest(3) := exe_uop_int(3).pdest
  wb_alu_data(3) := alu(3).io.result

  // Dividers done signals
  val wb_div_val  = VecInit(div(0).io.done && div_rd_latch(0) =/= 0.U, div(1).io.done && div_rd_latch(1) =/= 0.U)
  val wb_div_dest = div_rd_latch
  val wb_div_data = VecInit(div(0).io.result, div(1).io.result)

  // 2-Cycle Multipliers staging registers
  val r_mul_val    = RegInit(VecInit(Seq.fill(2)(false.B)))
  val r_mul_pdest  = RegInit(VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r_mul_robIdx = RegInit(VecInit(Seq.fill(2)(0.U(log2Up(128).W))))
  val r2_mul_val   = RegInit(VecInit(Seq.fill(2)(false.B)))
  val r2_mul_pdest = RegInit(VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r2_mul_robIdx = RegInit(VecInit(Seq.fill(2)(0.U(log2Up(128).W))))

  r_mul_val(0)    := exe_val_int(0) && exe_is_mul_op0
  r_mul_pdest(0)  := exe_uop_int(0).pdest
  r_mul_robIdx(0) := exe_uop_int(0).robIdx
  r2_mul_val(0)   := r_mul_val(0)
  r2_mul_pdest(0) := r_mul_pdest(0)
  r2_mul_robIdx(0):= r_mul_robIdx(0)

  r_mul_val(1)    := exe_val_int(1) && exe_is_mul_op1
  r_mul_pdest(1)  := exe_uop_int(1).pdest
  r_mul_robIdx(1) := exe_uop_int(1).robIdx
  r2_mul_val(1)   := r_mul_val(1)
  r2_mul_pdest(1) := r_mul_pdest(1)
  r2_mul_robIdx(1):= r_mul_robIdx(1)

  val wb_mul_val  = VecInit(r2_mul_val(0) && r2_mul_pdest(0) =/= 0.U, r2_mul_val(1) && r2_mul_pdest(1) =/= 0.U)
  val wb_mul_dest = r2_mul_pdest
  val wb_mul_data = VecInit(mul(0).io.result, mul(1).io.result)

  // Load Writeback (Cycle 3)
  val wb_ld_val  = Wire(Vec(2, Bool()))
  val wb_ld_dest = Wire(Vec(2, UInt(phyRegIdxWidth.W)))
  val wb_ld_data = Wire(Vec(2, UInt(xLen.W)))

  for (i <- 0 until 2) {
    wb_ld_val(i)  := r_agu_val(i) && r_agu_uop(i).pdest =/= 0.U && !r_agu_uop(i).decode.is_fload && (r_agu_uop(i).decode.is_load || r_agu_uop(i).decode.is_atomic)
    wb_ld_dest(i) := r_agu_uop(i).pdest
    val raw_ld = lsu(i).io.result
    val fused_alu = MuxLookup(r_agu_uop(i).decode.fused_alu_op, raw_ld)(Seq(
      0.U -> (raw_ld.asSInt + r_agu_uop(i).decode.fused_imm).asUInt,
      1.U -> (raw_ld & r_agu_uop(i).decode.fused_imm.asUInt),
      2.U -> (raw_ld | r_agu_uop(i).decode.fused_imm.asUInt),
      3.U -> (raw_ld ^ r_agu_uop(i).decode.fused_imm.asUInt),
      4.U -> (raw_ld << r_agu_uop(i).decode.fused_imm(5, 0)),
      5.U -> (raw_ld >> r_agu_uop(i).decode.fused_imm(5, 0)),
      6.U -> (raw_ld.asSInt >> r_agu_uop(i).decode.fused_imm(5, 0)).asUInt
    ))
    wb_ld_data(i) := Mux(r_agu_uop(i).decode.is_fused_load_alu, fused_alu, raw_ld)
  }

  // FP to INT writeback
  val exe_dec_fp = (0 until 4).map(i => exe_uop_fp(i).decode)
  val exe_is_fp_wb_to_int2 = exe_dec_fp(2).is_fmv_x_w || exe_dec_fp(2).is_fmv_x_d || exe_dec_fp(2).is_fcvt_f2i || exe_dec_fp(2).is_feq || exe_dec_fp(2).is_flt || exe_dec_fp(2).is_fle || exe_dec_fp(2).is_fclass
  val exe_is_fp_wb_to_int3 = exe_dec_fp(3).is_fmv_x_w || exe_dec_fp(3).is_fmv_x_d || exe_dec_fp(3).is_fcvt_f2i || exe_dec_fp(3).is_feq || exe_dec_fp(3).is_flt || exe_dec_fp(3).is_fle || exe_dec_fp(3).is_fclass

  val wb_fp2int_val  = (exe_val_fp(2) && exe_uop_fp(2).pdest =/= 0.U && exe_is_fp_wb_to_int2) ||
                       (exe_val_fp(3) && exe_uop_fp(3).pdest =/= 0.U && exe_is_fp_wb_to_int3)
  val wb_fp2int_dest = Mux(exe_val_fp(2) && exe_is_fp_wb_to_int2, exe_uop_fp(2).pdest, exe_uop_fp(3).pdest)
  val wb_fp2int_data = Mux(exe_val_fp(2) && exe_is_fp_wb_to_int2, fpmisc(0).io.result_int, fpmisc(1).io.result_int)

  // Registered bypass signals (Level 1)
  val r_wb_alu_val  = RegNext(wb_alu_val, VecInit(Seq.fill(4)(false.B)))
  val r_wb_alu_dest = RegNext(wb_alu_dest, VecInit(Seq.fill(4)(0.U(phyRegIdxWidth.W))))
  val r_wb_alu_data = RegNext(wb_alu_data, VecInit(Seq.fill(4)(0.U(xLen.W))))

  val r_wb_ld_val   = RegNext(wb_ld_val, VecInit(Seq.fill(2)(false.B)))
  val r_wb_ld_dest  = RegNext(wb_ld_dest, VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r_wb_ld_data  = RegNext(wb_ld_data, VecInit(Seq.fill(2)(0.U(xLen.W))))

  val r_wb_div_val  = RegNext(wb_div_val, VecInit(Seq.fill(2)(false.B)))
  val r_wb_div_dest = RegNext(wb_div_dest, VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r_wb_div_data = RegNext(wb_div_data, VecInit(Seq.fill(2)(0.U(xLen.W))))

  val r_wb_mul_val  = RegNext(wb_mul_val, VecInit(Seq.fill(2)(false.B)))
  val r_wb_mul_dest = RegNext(wb_mul_dest, VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r_wb_mul_data = RegNext(wb_mul_data, VecInit(Seq.fill(2)(0.U(xLen.W))))

  val r_wb_fp2int_val  = RegNext(wb_fp2int_val, false.B)
  val r_wb_fp2int_dest = RegNext(wb_fp2int_dest, 0.U)
  val r_wb_fp2int_data = RegNext(wb_fp2int_data, 0.U)

  // Level 2 Registered bypass signals
  val r2_wb_alu_val  = RegNext(r_wb_alu_val, VecInit(Seq.fill(4)(false.B)))
  val r2_wb_alu_dest = RegNext(r_wb_alu_dest, VecInit(Seq.fill(4)(0.U(phyRegIdxWidth.W))))
  val r2_wb_alu_data = RegNext(r_wb_alu_data, VecInit(Seq.fill(4)(0.U(xLen.W))))

  val r2_wb_ld_val   = RegNext(r_wb_ld_val, VecInit(Seq.fill(2)(false.B)))
  val r2_wb_ld_dest  = RegNext(r_wb_ld_dest, VecInit(Seq.fill(2)(0.U(phyRegIdxWidth.W))))
  val r2_wb_ld_data  = RegNext(r_wb_ld_data, VecInit(Seq.fill(2)(0.U(xLen.W))))

  case class BypassChannel(valid: Bool, pdest: UInt, data: UInt)

  val bypassChannels = Seq(
    BypassChannel(wb_ld_val(0), wb_ld_dest(0), wb_ld_data(0)),
    BypassChannel(wb_ld_val(1), wb_ld_dest(1), wb_ld_data(1)),
    BypassChannel(r_wb_alu_val(0), r_wb_alu_dest(0), r_wb_alu_data(0)),
    BypassChannel(r_wb_alu_val(1), r_wb_alu_dest(1), r_wb_alu_data(1)),
    BypassChannel(r_wb_alu_val(2), r_wb_alu_dest(2), r_wb_alu_data(2)),
    BypassChannel(r_wb_alu_val(3), r_wb_alu_dest(3), r_wb_alu_data(3)),
    BypassChannel(r_wb_ld_val(0), r_wb_ld_dest(0), r_wb_ld_data(0)),
    BypassChannel(r_wb_ld_val(1), r_wb_ld_dest(1), r_wb_ld_data(1)),
    BypassChannel(r_wb_div_val(0), r_wb_div_dest(0), r_wb_div_data(0)),
    BypassChannel(r_wb_div_val(1), r_wb_div_dest(1), r_wb_div_data(1)),
    BypassChannel(r_wb_mul_val(0), r_wb_mul_dest(0), r_wb_mul_data(0)),
    BypassChannel(r_wb_mul_val(1), r_wb_mul_dest(1), r_wb_mul_data(1)),
    BypassChannel(r_wb_fp2int_val, r_wb_fp2int_dest, r_wb_fp2int_data),
    BypassChannel(r2_wb_alu_val(0), r2_wb_alu_dest(0), r2_wb_alu_data(0)),
    BypassChannel(r2_wb_alu_val(1), r2_wb_alu_dest(1), r2_wb_alu_data(1)),
    BypassChannel(r2_wb_alu_val(2), r2_wb_alu_dest(2), r2_wb_alu_data(2)),
    BypassChannel(r2_wb_alu_val(3), r2_wb_alu_dest(3), r2_wb_alu_data(3)),
    BypassChannel(r2_wb_ld_val(0), r2_wb_ld_dest(0), r2_wb_ld_data(0)),
    BypassChannel(r2_wb_ld_val(1), r2_wb_ld_dest(1), r2_wb_ld_data(1))
  )

  def bypass(raddr: UInt, rdata: UInt): UInt = {
    val matches = bypassChannels.map(ch => ch.valid && (ch.pdest === raddr) && (raddr =/= 0.U))
    val datas   = bypassChannels.map(_.data)
    MuxCase(rdata, matches.zip(datas))
  }

  // ---------------- INT 0..3 EXECUTION ----------------
  val src_int_1 = Wire(Vec(4, UInt(xLen.W)))
  val src_int_2 = Wire(Vec(4, UInt(xLen.W)))

  for (i <- 0 until 4) {
    src_int_1(i) := bypass(exe_uop_int(i).psrs1, r_int_rdata(i * 2))
    src_int_2(i) := bypass(exe_uop_int(i).psrs2, r_int_rdata(i * 2 + 1))

    alu(i).io.src1 := src_int_1(i)
    alu(i).io.src2 := Mux(exe_dec_int(i).is_fused_lui_addi, exe_dec_int(i).imm.asUInt,
                      Mux(!exe_dec_int(i).rs2_use, exe_dec_int(i).imm.asUInt, src_int_2(i)))
    alu(i).io.pc   := exe_uop_raw_int(i).pc
    alu(i).io.dec  := exe_dec_int(i)
  }

  // BRUs on Lane 0 and Lane 1
  for (i <- 0 until 2) {
    bru(i).io.src1 := src_int_1(i)
    bru(i).io.src2 := Mux(exe_dec_int(i).is_jalr || exe_dec_int(i).is_branch, src_int_2(i), exe_dec_int(i).imm.asUInt)
    bru(i).io.pc   := exe_uop_raw_int(i).pc
    bru(i).io.is_rvc := exe_uop_raw_int(i).pre.is_rvc
    bru(i).io.pred_taken := exe_uop_raw_int(i).is_predicted_taken
    bru(i).io.pred_target := exe_uop_raw_int(i).predicted_target
    bru(i).io.dec  := exe_dec_int(i)
  }

  // Multipliers on Lane 0 & Lane 1
  mul(0).io.src1 := src_int_1(0); mul(0).io.src2 := src_int_2(0); mul(0).io.dec := exe_dec_int(0)
  mul(1).io.src1 := src_int_1(1); mul(1).io.src2 := src_int_2(1); mul(1).io.dec := exe_dec_int(1)

  // Dividers on Lane 0 & Lane 1
  for (i <- 0 until 2) {
    val is_div_op = if (i == 0) exe_is_div_op0 else exe_is_div_op1
    div(i).io.src1 := src_int_1(i)
    div(i).io.src2 := src_int_2(i)
    div(i).io.dec  := exe_dec_int(i)
    div(i).io.fire := exe_val_int(i) && is_div_op
    val div_is_younger = is_younger_than_redirect(div_snap_latch(i))
    div(i).io.flush := io.redirect.valid && (io.redirect.is_exception || div_is_younger)
    when(div(i).io.flush) { div_rd_latch(i) := 0.U }
  }

  // Age-Priority Redirect/Flush Filter across BRU 0, BRU 1, and LoadQueue Replay
  val r0_snap = exe_uop_int(0).snapshotIdx
  val r1_snap = exe_uop_int(1).snapshotIdx

  val dist0 = Mux(r0_snap >= io.snptDeqPtr, r0_snap - io.snptDeqPtr, r0_snap - io.snptDeqPtr + renameSnapshotNum.U)
  val dist1 = Mux(r1_snap >= io.snptDeqPtr, r1_snap - io.snptDeqPtr, r1_snap - io.snptDeqPtr + renameSnapshotNum.U)
  val lane0_is_older = dist0 < dist1

  val r0_valid = exe_val_int(0) && (bru(0).io.exc_valid || bru(0).io.mispredict) && io.snptValids(r0_snap)
  val r1_valid = exe_val_int(1) && (bru(1).io.exc_valid || bru(1).io.mispredict) && io.snptValids(r1_snap)

  when(r0_valid && r1_valid) {
    io.redirect.valid := true.B
    io.redirect.target := Mux(lane0_is_older, bru(0).io.target, bru(1).io.target)
    io.redirect.epoch  := Mux(lane0_is_older, exe_uop_raw_int(0).epoch, exe_uop_raw_int(1).epoch)
    io.redirect.is_exception := Mux(lane0_is_older, bru(0).io.exc_valid, bru(1).io.exc_valid)
    io.redirect.exc_cause    := Mux(lane0_is_older, bru(0).io.exc_cause, bru(1).io.exc_cause)
    io.redirect.snapshotIdx  := Mux(lane0_is_older, r0_snap, r1_snap)
    io.redirect.pc           := Mux(lane0_is_older, exe_uop_raw_int(0).pc, exe_uop_raw_int(1).pc)
    io.redirect.taken        := Mux(lane0_is_older, bru(0).io.taken, bru(1).io.taken)
    io.redirect.is_cfi       := Mux(lane0_is_older, exe_dec_int(0).is_branch || exe_dec_int(0).is_jal || exe_dec_int(0).is_jalr, exe_dec_int(1).is_branch || exe_dec_int(1).is_jal || exe_dec_int(1).is_jalr)
    io.redirect.is_jal       := Mux(lane0_is_older, exe_dec_int(0).is_jal, exe_dec_int(1).is_jal)
    io.redirect.is_jalr      := Mux(lane0_is_older, exe_dec_int(0).is_jalr, exe_dec_int(1).is_jalr)
    io.redirect.ftqPtr       := Mux(lane0_is_older, exe_uop_raw_int(0).ftqPtr, exe_uop_raw_int(1).ftqPtr)
    io.redirect.robIdx       := Mux(lane0_is_older, exe_uop_int(0).robIdx, exe_uop_int(1).robIdx)
  } .elsewhen(r0_valid) {
    io.redirect.valid := true.B
    io.redirect.target := bru(0).io.target
    io.redirect.epoch  := exe_uop_raw_int(0).epoch
    io.redirect.is_exception := bru(0).io.exc_valid
    io.redirect.exc_cause    := bru(0).io.exc_cause
    io.redirect.snapshotIdx  := r0_snap
    io.redirect.pc           := exe_uop_raw_int(0).pc
    io.redirect.taken        := bru(0).io.taken
    io.redirect.is_cfi       := exe_dec_int(0).is_branch || exe_dec_int(0).is_jal || exe_dec_int(0).is_jalr
    io.redirect.is_jal       := exe_dec_int(0).is_jal
    io.redirect.is_jalr      := exe_dec_int(0).is_jalr
    io.redirect.ftqPtr       := exe_uop_raw_int(0).ftqPtr
    io.redirect.robIdx       := exe_uop_int(0).robIdx
  } .elsewhen(r1_valid) {
    io.redirect.valid := true.B
    io.redirect.target := bru(1).io.target
    io.redirect.epoch  := exe_uop_raw_int(1).epoch
    io.redirect.is_exception := bru(1).io.exc_valid
    io.redirect.exc_cause    := bru(1).io.exc_cause
    io.redirect.snapshotIdx  := r1_snap
    io.redirect.pc           := exe_uop_raw_int(1).pc
    io.redirect.taken        := bru(1).io.taken
    io.redirect.is_cfi       := exe_dec_int(1).is_branch || exe_dec_int(1).is_jal || exe_dec_int(1).is_jalr
    io.redirect.is_jal       := exe_dec_int(1).is_jal
    io.redirect.is_jalr      := exe_dec_int(1).is_jalr
    io.redirect.ftqPtr       := exe_uop_raw_int(1).ftqPtr
    io.redirect.robIdx       := exe_uop_int(1).robIdx
  } .elsewhen(lq.io.violation.valid && io.snptValids(lq.io.violation.snapshotIdx)) {
    io.redirect.valid := true.B
    io.redirect.target := lq.io.violation.loadPC
    io.redirect.epoch  := false.B
    io.redirect.is_exception := false.B
    io.redirect.exc_cause    := 0.U
    io.redirect.snapshotIdx  := lq.io.violation.snapshotIdx
    io.redirect.pc           := lq.io.violation.loadPC
    io.redirect.taken        := false.B
    io.redirect.is_cfi       := false.B
    io.redirect.is_jal       := false.B
    io.redirect.is_jalr      := false.B
    io.redirect.ftqPtr       := 0.U
    io.redirect.robIdx       := lq.io.violation.loadRobIdx

    io.memPredUpdate.valid   := true.B
    io.memPredUpdate.ldpc    := lq.io.violation.loadPC
    io.memPredUpdate.stpc    := lq.io.violation.storePC
  }

  // Non-Flushing BPU Update
  val update0_valid = exe_val_int(0) && (exe_dec_int(0).is_branch || exe_dec_int(0).is_jal || exe_dec_int(0).is_jalr) && !r0_valid && io.snptValids(r0_snap)
  val update1_valid = exe_val_int(1) && (exe_dec_int(1).is_branch || exe_dec_int(1).is_jal || exe_dec_int(1).is_jalr) && !r1_valid && io.snptValids(r1_snap)

  when(update0_valid) {
    io.bpu_update.valid  := true.B
    io.bpu_update.pc     := exe_uop_raw_int(0).pc
    io.bpu_update.target := bru(0).io.target
    io.bpu_update.taken  := bru(0).io.taken
    io.bpu_update.is_cfi := true.B
    io.bpu_update.is_jal := exe_dec_int(0).is_jal
    io.bpu_update.is_jalr:= exe_dec_int(0).is_jalr
    io.bpu_update.ftqPtr := exe_uop_raw_int(0).ftqPtr
    io.bpu_update.robIdx := exe_uop_int(0).robIdx
  } .elsewhen(update1_valid) {
    io.bpu_update.valid  := true.B
    io.bpu_update.pc     := exe_uop_raw_int(1).pc
    io.bpu_update.target := bru(1).io.target
    io.bpu_update.taken  := bru(1).io.taken
    io.bpu_update.is_cfi := true.B
    io.bpu_update.is_jal := exe_dec_int(1).is_jal
    io.bpu_update.is_jalr:= exe_dec_int(1).is_jalr
    io.bpu_update.ftqPtr := exe_uop_raw_int(1).ftqPtr
    io.bpu_update.robIdx := exe_uop_int(1).robIdx
  }

  // Writebacks from ALUs 0..3
  for (i <- 0 until 4) {
    when(exe_val_int(i)) {
      val is_div_op = if (i == 0) exe_is_div_op0 else if (i == 1) exe_is_div_op1 else false.B
      val is_mul_op = if (i == 0) exe_is_mul_op0 else if (i == 1) exe_is_mul_op1 else false.B
      val is_link   = if (i == 0) exe_is_link0   else if (i == 1) exe_is_link1   else false.B
      val link_addr = if (i == 0) exe_link_addr0 else if (i == 1) exe_link_addr1 else 0.U

      when(exe_uop_int(i).pdest =/= 0.U && !is_div_op && !is_mul_op) {
        next_regFile_wen(i)   := (!exe_dec_int(i).is_branch) || is_link
        next_regFile_waddr(i) := exe_uop_int(i).pdest
        next_regFile_wdata(i) := Mux(is_link, link_addr, alu(i).io.result)
      }
      if (i < 2) {
        when(is_div_op) {
          div_rd_latch(i) := exe_uop_int(i).pdest
          div_snap_latch(i) := exe_uop_int(i).snapshotIdx
          div_robIdx_latch(i) := exe_uop_int(i).robIdx
        }
      }
    }
  }

  // Writeback for Multipliers (Ports 6, 7)
  for (i <- 0 until 2) {
    when(r2_mul_val(i)) {
      next_regFile_wen(6 + i)   := true.B
      next_regFile_waddr(6 + i) := r2_mul_pdest(i)
      next_regFile_wdata(6 + i) := mul(i).io.result
    }
  }

  // Writeback for Dividers (Ports 8, 9)
  for (i <- 0 until 2) {
    when(div(i).io.done) {
      next_regFile_wen(8 + i)   := true.B
      next_regFile_waddr(8 + i) := div_rd_latch(i)
      next_regFile_wdata(8 + i) := div(i).io.result
    }
  }

  // Wakeup for ALUs and MULs
  for (i <- 0 until 2) {
    val is_div_op = if (i == 0) is_div_op0 else is_div_op1
    val is_mul_op = if (i == 0) is_mul_op0 else is_mul_op1

    val wu_val_raw = io.int_in(i).fire && io.int_in(i).bits.pdest =/= 0.U && !is_div_op && !is_mul_op
    val r_wu_val   = RegNext(wu_val_raw, false.B)
    val r_wu_pdest = RegNext(io.int_in(i).bits.pdest, 0.U)

    val r_mul_wu_raw = RegNext(io.int_in(i).fire && io.int_in(i).bits.pdest =/= 0.U && is_mul_op, false.B)
    val r_mul_wu_pdest_raw = RegNext(io.int_in(i).bits.pdest, 0.U)
    val r_mul_wu_val = RegNext(r_mul_wu_raw, false.B)
    val r_mul_wu_pdest = RegNext(r_mul_wu_pdest_raw, 0.U)

    io.wakeup(i).valid := r_wu_val || r_mul_wu_val
    io.wakeup(i).pdest := Mux(r_wu_val, r_wu_pdest, r_mul_wu_pdest)
    io.wakeup(i).is_fp := false.B
  }

  // Wakeup for ALU 2 and ALU 3
  for (i <- 2 until 4) {
    val wu_raw = io.int_in(i).fire && io.int_in(i).bits.pdest =/= 0.U && !decInt(i).is_branch
    val r_wu_val = RegNext(wu_raw, false.B)
    val r_wu_pdest = RegNext(io.int_in(i).bits.pdest, 0.U)
    io.wakeup(i).valid := r_wu_val
    io.wakeup(i).pdest := r_wu_pdest
    io.wakeup(i).is_fp := false.B
  }

  // Wakeup for Dividers (Wakeup 6, 7)
  for (i <- 0 until 2) {
    val wu_div_val = div(i).io.done && div_rd_latch(i) =/= 0.U
    val r_wu_div_val = RegNext(wu_div_val, false.B)
    val r_wu_div_pdest = RegNext(div_rd_latch(i), 0.U)
    io.wakeup(6 + i).valid := r_wu_div_val
    io.wakeup(6 + i).pdest := r_wu_div_pdest
    io.wakeup(6 + i).is_fp := false.B
  }

  // ---------------- MEMORY PIPELINES (LSU 0..2) ----------------
  val src_mem_1 = Wire(Vec(3, UInt(xLen.W)))
  val src_mem_2 = Wire(Vec(3, UInt(xLen.W)))
  val fsrc_mem_2 = Wire(Vec(3, UInt(fLen.W)))

  for (i <- 0 until 3) {
    src_mem_1(i) := bypass(exe_uop_mem(i).psrs1, r_int_rdata(8 + i * 2))
    src_mem_2(i) := bypass(exe_uop_mem(i).psrs2, r_int_rdata(8 + i * 2 + 1))
    fsrc_mem_2(i) := r_fp_rdata(12 + i)

    val agu_vaddr = Mux(exe_uop_mem(i).decode.is_atomic, src_mem_1(i), (src_mem_1(i).asSInt + exe_uop_mem(i).decode.imm).asUInt)
    tlb(i).io.vaddr := agu_vaddr

    val next_r_val = exe_val_mem(i)
    when(io.redirect.valid && is_younger_than_redirect(exe_uop_mem(i).snapshotIdx)) {
      r_agu_val(i) := false.B
    } .otherwise {
      r_agu_val(i) := next_r_val
    }
    r_agu_uop(i)   := exe_uop_mem(i)
    r_agu_vaddr(i) := agu_vaddr
    r_agu_paddr(i) := tlb(i).io.paddr
    r_agu_src2(i)  := src_mem_2(i)
    r_agu_fsrc2(i) := fsrc_mem_2(i)
  }

  // MEM (CACHE ACCESS STAGE - CYCLE 3)
  // LSU 0 & LSU 1 (Load pipes)
  for (i <- 0 until 2) {
    lsu(i).io.src1 := r_agu_paddr(i)
    lsu(i).io.src2 := Mux(r_agu_uop(i).decode.is_fstore, r_agu_fsrc2(i), r_agu_src2(i))
    lsu(i).io.imm  := 0.S
    lsu(i).io.dec  := r_agu_uop(i).decode

    val ld_mask = MuxCase("h000f".U(16.W), Seq(
      (r_agu_uop(i).decode.is_lb || r_agu_uop(i).decode.is_lbu) -> ("h0001".U(16.W) << lsu(i).io.mem_addr(2, 0)),
      (r_agu_uop(i).decode.is_lh || r_agu_uop(i).decode.is_lhu) -> ("h0003".U(16.W) << lsu(i).io.mem_addr(2, 0)),
      (r_agu_uop(i).decode.is_lw || r_agu_uop(i).decode.is_lwu || r_agu_uop(i).decode.is_flw) -> ("h000f".U(16.W) << lsu(i).io.mem_addr(2, 0)),
      (r_agu_uop(i).decode.is_ld || r_agu_uop(i).decode.is_fld) -> ("h00ff".U(16.W) << lsu(i).io.mem_addr(2, 0))
    ))

    sq.io.stlf_query(i).valid  := r_agu_val(i) && (r_agu_uop(i).decode.is_load || r_agu_uop(i).decode.is_fload)
    sq.io.stlf_query(i).robIdx := r_agu_uop(i).robIdx
    sq.io.stlf_query(i).paddr  := lsu(i).io.mem_addr
    sq.io.stlf_query(i).mask   := ld_mask

    lq.io.exec_update(i).valid  := r_agu_val(i) && (r_agu_uop(i).decode.is_load || r_agu_uop(i).decode.is_fload)
    lq.io.exec_update(i).robIdx := r_agu_uop(i).robIdx
    lq.io.exec_update(i).paddr  := lsu(i).io.mem_addr
    lq.io.exec_update(i).mask   := ld_mask
    lq.io.exec_update(i).pc     := r_agu_uop(i).uop.pc

    val stlf_hit = sq.io.stlf_resp(i).hit
    lsu(i).io.mem_data := Mux(stlf_hit, sq.io.stlf_resp(i).wdata, dmem.io.rdata(i))

    // Writeback to PRF / Write-back Staging (Port 4 for LSU 0, Port 5 for LSU 1)
    when(r_agu_val(i) && r_agu_uop(i).pdest =/= 0.U) {
      when(r_agu_uop(i).decode.is_load || r_agu_uop(i).decode.is_atomic) {
        when(!r_agu_uop(i).decode.is_fload) {
          next_regFile_wen(4 + i)   := true.B
          next_regFile_waddr(4 + i) := r_agu_uop(i).pdest
          next_regFile_wdata(4 + i) := wb_ld_data(i)
        } .otherwise {
          val fload_data = Mux(r_agu_uop(i).decode.is_fld, lsu(i).io.result(63, 0), Cat("hffffffff".U(32.W), lsu(i).io.result(31, 0)))
          fpRegFile.io.wen(4 + i)   := true.B
          fpRegFile.io.waddr(4 + i) := r_agu_uop(i).pdest
          fpRegFile.io.wdata(4 + i) := fload_data
          fpRC.io.wen(4 + i)        := true.B
          fpRC.io.waddr(4 + i)      := r_agu_uop(i).pdest
          fpRC.io.wdata(4 + i)      := fload_data
        }
      }
    }

    // Wakeup for Load pipes (Wakeup 4, 5)
    val wu_mem_raw = io.mem_in(i).fire && io.mem_in(i).bits.pdest =/= 0.U
    val r_wu_mem_val = RegNext(wu_mem_raw, false.B)
    val r_wu_mem_pdest = RegNext(io.mem_in(i).bits.pdest, 0.U)
    val r_wu_mem_fload = RegNext(decMem(i).is_fload, false.B)

    io.wakeup(4 + i).valid := r_wu_mem_val || (i == 0).B && (io.dcache_resp.valid && io.dcache_resp.bits.load_id =/= 0.U)
    io.wakeup(4 + i).pdest := Mux((i == 0).B && io.dcache_resp.valid, io.dcache_resp.bits.load_id, r_wu_mem_pdest)
    io.wakeup(4 + i).is_fp := r_wu_mem_fload
  }

  // LSU 2 (Store pipe)
  lsu(2).io.src1 := r_agu_paddr(2)
  lsu(2).io.src2 := Mux(r_agu_uop(2).decode.is_fstore, r_agu_fsrc2(2), r_agu_src2(2))
  lsu(2).io.imm  := 0.S
  lsu(2).io.dec  := r_agu_uop(2).decode
  lsu(2).io.mem_data := 0.U

  sq.io.write.valid  := r_agu_val(2) && (r_agu_uop(2).decode.is_store || r_agu_uop(2).decode.is_fstore)
  sq.io.write.robIdx := r_agu_uop(2).robIdx
  sq.io.write.paddr  := lsu(2).io.mem_addr
  sq.io.write.wmask  := lsu(2).io.mem_wmask
  sq.io.write.wdata  := lsu(2).io.mem_wdata

  lq.io.store_snoop.valid  := r_agu_val(2) && (r_agu_uop(2).decode.is_store || r_agu_uop(2).decode.is_fstore)
  lq.io.store_snoop.robIdx := r_agu_uop(2).robIdx
  lq.io.store_snoop.paddr  := lsu(2).io.mem_addr
  lq.io.store_snoop.mask   := lsu(2).io.mem_wmask
  lq.io.store_snoop.pc     := r_agu_uop(2).uop.pc

  io.store_resolved.valid  := r_agu_val(2) && (r_agu_uop(2).decode.is_store || r_agu_uop(2).decode.is_fstore)
  io.store_resolved.bits   := r_agu_uop(2).robIdx

  // DataMem connections
  dmem.io.raddr(0) := lsu(0).io.mem_addr
  dmem.io.raddr(1) := lsu(1).io.mem_addr
  dmem.io.addr  := Mux(sq.io.drain.valid, sq.io.drain.paddr, lsu(0).io.mem_addr)
  dmem.io.wen   := sq.io.drain.valid
  dmem.io.wmask := sq.io.drain.wmask
  dmem.io.wdata := sq.io.drain.wdata
  sq.io.drain_ready := true.B

  io.dcache_req.valid := sq.io.drain.valid || (r_agu_val(0) && r_agu_uop(0).decode.is_load && !sq.io.stlf_resp(0).hit)
  io.dcache_req.bits.addr := Mux(sq.io.drain.valid, sq.io.drain.paddr, lsu(0).io.mem_addr)
  io.dcache_req.bits.data := sq.io.drain.wdata
  io.dcache_req.bits.is_write := sq.io.drain.valid
  io.dcache_req.bits.load_id := r_agu_uop(0).pdest
  io.dcache_resp.ready := true.B

  when(io.dcache_resp.valid && io.dcache_resp.bits.load_id =/= 0.U) {
    next_regFile_wen(4)   := true.B
    next_regFile_waddr(4) := io.dcache_resp.bits.load_id
    next_regFile_wdata(4) := wb_ld_data(0)
  }

  // ---------------- FP EXECUTION (FPU 0..3) ----------------
  val fsrc1 = (0 until 4).map(i => r_fp_rdata(i * 3))
  val fsrc2 = (0 until 4).map(i => r_fp_rdata(i * 3 + 1))
  val fsrc3 = (0 until 4).map(i => r_fp_rdata(i * 3 + 2))

  for (i <- 0 until 4) {
    fpu(i).io.src1 := fsrc1(i)
    fpu(i).io.src2 := fsrc2(i)
    fpu(i).io.src3 := fsrc3(i)
    fpu(i).io.dec  := exe_dec_fp(i)
  }

  // FP Misc on Lane 2 & 3
  val srcFp_int_1 = bypass(exe_uop_fp(2).psrs1, r_int_rdata(14))
  val srcFp_int_2 = bypass(exe_uop_fp(3).psrs1, r_int_rdata(15))

  fpmisc(0).io.src1    := fsrc1(2)
  fpmisc(0).io.src2    := fsrc2(2)
  fpmisc(0).io.rs1_int := srcFp_int_1
  fpmisc(0).io.dec     := exe_dec_fp(2)
  fpmisc(0).io.inst    := exe_uop_fp(2).uop.inst_raw

  fpmisc(1).io.src1    := fsrc1(3)
  fpmisc(1).io.src2    := fsrc2(3)
  fpmisc(1).io.rs1_int := srcFp_int_2
  fpmisc(1).io.dec     := exe_dec_fp(3)
  fpmisc(1).io.inst    := exe_uop_fp(3).uop.inst_raw

  // FP Divider on Lane 3
  fpdiv.io.src1 := fsrc1(3)
  fpdiv.io.src2 := fsrc2(3)
  fpdiv.io.dec  := exe_dec_fp(3)
  fpdiv.io.fire := exe_val_fp(3) && (exe_dec_fp(3).is_fdiv || exe_dec_fp(3).is_fsqrt)
  val fpdiv_is_younger = is_younger_than_redirect(fpdiv_snap_latch)
  fpdiv.io.flush := io.redirect.valid && (io.redirect.is_exception || fpdiv_is_younger)
  when(fpdiv.io.flush) { fpdiv_rd_latch := 0.U }

  // FP Writeback
  for (i <- 0 until 4) {
    val exe_is_fp_wb_to_fp = exe_dec_fp(i).is_fadd || exe_dec_fp(i).is_fsub || exe_dec_fp(i).is_fmul || exe_dec_fp(i).is_fmadd ||
                             exe_dec_fp(i).is_fmsub || exe_dec_fp(i).is_fnmsub || exe_dec_fp(i).is_fnmadd ||
                             exe_dec_fp(i).is_fmv_w_x || exe_dec_fp(i).is_fmv_d_x || exe_dec_fp(i).is_fcvt_i2f ||
                             exe_dec_fp(i).is_fsgnj || exe_dec_fp(i).is_fminmax || exe_dec_fp(i).is_fcvt_s_d || exe_dec_fp(i).is_fcvt_d_s

    val exe_is_fp_wb_to_int = exe_dec_fp(i).is_fmv_x_w || exe_dec_fp(i).is_fmv_x_d || exe_dec_fp(i).is_fcvt_f2i || exe_dec_fp(i).is_feq || exe_dec_fp(i).is_flt || exe_dec_fp(i).is_fle || exe_dec_fp(i).is_fclass

    when(exe_val_fp(i)) {
      when(exe_uop_fp(i).pdest =/= 0.U) {
        when(exe_is_fp_wb_to_fp) {
          fpRegFile.io.wen(i)   := true.B
          fpRegFile.io.waddr(i) := exe_uop_fp(i).pdest
          val is_fpu_core = exe_dec_fp(i).is_fadd || exe_dec_fp(i).is_fsub || exe_dec_fp(i).is_fmul || exe_dec_fp(i).is_fmadd ||
                            exe_dec_fp(i).is_fmsub || exe_dec_fp(i).is_fnmsub || exe_dec_fp(i).is_fnmadd
          val misc_res = if (i >= 2) fpmisc(i - 2).io.result_fp else 0.U
          val fp_res = Mux(is_fpu_core, fpu(i).io.result, misc_res)
          fpRegFile.io.wdata(i) := fp_res
          fpRC.io.wen(i)        := true.B
          fpRC.io.waddr(i)      := exe_uop_fp(i).pdest
          fpRC.io.wdata(i)      := fp_res
        }
        when(exe_is_fp_wb_to_int && (i >= 2).B) {
          next_regFile_wen(10)   := true.B
          next_regFile_waddr(10) := exe_uop_fp(i).pdest
          next_regFile_wdata(10) := Mux((i == 2).B, fpmisc(0).io.result_int, fpmisc(1).io.result_int)
        }
      }
      if (i == 3) {
        when(exe_dec_fp(3).is_fdiv || exe_dec_fp(3).is_fsqrt) {
          fpdiv_rd_latch := exe_uop_fp(3).pdest
          fpdiv_snap_latch := exe_uop_fp(3).snapshotIdx
          fpdiv_robIdx_latch := exe_uop_fp(3).robIdx
        }
      }
    }
  }

  // FP Wakeup (Wakeup 8..11)
  for (i <- 0 until 4) {
    val wu_fp_val = io.fp_in(i).fire && io.fp_in(i).bits.pdest =/= 0.U && !(i == 3).B && !decFp(i).is_fdiv && !decFp(i).is_fsqrt
    val r_wu_fp_val = RegNext(wu_fp_val, false.B)
    val r_wu_fp_pdest = RegNext(io.fp_in(i).bits.pdest, 0.U)
    val is_int_wb = if (i >= 2) decFp(i).is_fmv_x_w || decFp(i).is_fmv_x_d || decFp(i).is_fcvt_f2i || decFp(i).is_feq || decFp(i).is_flt || decFp(i).is_fle || decFp(i).is_fclass else false.B
    val r_is_int_wb = RegNext(is_int_wb, false.B)

    io.wakeup(8 + i).valid := r_wu_fp_val
    io.wakeup(8 + i).pdest := r_wu_fp_pdest
    io.wakeup(8 + i).is_fp := !r_is_int_wb
  }

  // FPDiv Writeback and Wakeup (Wakeup 12)
  when(fpdiv.io.done) {
    fpRegFile.io.wen(6)   := true.B
    fpRegFile.io.waddr(6) := fpdiv_rd_latch
    fpRegFile.io.wdata(6) := fpdiv.io.result
    fpRC.io.wen(6)        := true.B
    fpRC.io.waddr(6)      := fpdiv_rd_latch
    fpRC.io.wdata(6)      := fpdiv.io.result
  }

  val wu_fpdiv_val = fpdiv.io.done && fpdiv_rd_latch =/= 0.U
  val r_wu_fpdiv_val = RegNext(wu_fpdiv_val, false.B)
  val r_wu_fpdiv_pdest = RegNext(fpdiv_rd_latch, 0.U)
  io.wakeup(12).valid := r_wu_fpdiv_val
  io.wakeup(12).pdest := r_wu_fpdiv_pdest
  io.wakeup(12).is_fp := true.B

  io.wakeup(13).valid := false.B
  io.wakeup(13).pdest := 0.U
  io.wakeup(13).is_fp := false.B

  io.debug_regs := regFile.io.debug_regs
  io.debug_fp_regs := fpRegFile.io.debug_regs

  // ---------------- ROB WRITEBACK (14 PORTS) ----------------
  for (i <- 0 until 14) {
    io.exuWriteback(i).valid := false.B
    io.exuWriteback(i).bits.robIdx := 0.U
    io.exuWriteback(i).bits.data := 0.U
    io.exuWriteback(i).bits.exceptionVec := 0.U
  }

  // ALU 0..3 (Ports 0..3)
  for (i <- 0 until 4) {
    val is_div = if (i == 0) exe_is_div_op0 else if (i == 1) exe_is_div_op1 else false.B
    val is_mul = if (i == 0) exe_is_mul_op0 else if (i == 1) exe_is_mul_op1 else false.B
    val is_link = if (i == 0) exe_is_link0 else if (i == 1) exe_is_link1 else false.B
    val link_addr = if (i == 0) exe_link_addr0 else if (i == 1) exe_link_addr1 else 0.U

    io.exuWriteback(i).valid := exe_val_int(i) && !is_div && !is_mul
    io.exuWriteback(i).bits.robIdx := exe_uop_int(i).robIdx
    io.exuWriteback(i).bits.data   := Mux(is_link, link_addr, alu(i).io.result)
    if (i < 2) {
      io.exuWriteback(i).bits.exceptionVec := Mux(bru(i).io.exc_valid, bru(i).io.exc_cause, 0.U)
    }
  }

  // LSU 0 & 1 (Load pipes, Ports 4, 5)
  for (i <- 0 until 2) {
    io.exuWriteback(4 + i).valid := r_agu_val(i)
    io.exuWriteback(4 + i).bits.robIdx := r_agu_uop(i).robIdx
    io.exuWriteback(4 + i).bits.data := wb_ld_data(i)
  }

  // LSU 2 (Store pipe, Port 6)
  io.exuWriteback(6).valid := r_agu_val(2)
  io.exuWriteback(6).bits.robIdx := r_agu_uop(2).robIdx

  // Dividers 0 & 1 (Ports 7, 8)
  for (i <- 0 until 2) {
    io.exuWriteback(7 + i).valid := div(i).io.done
    io.exuWriteback(7 + i).bits.robIdx := div_robIdx_latch(i)
  }

  // Multipliers 0 & 1 (Ports 9, 10)
  for (i <- 0 until 2) {
    io.exuWriteback(9 + i).valid := r2_mul_val(i)
    io.exuWriteback(9 + i).bits.robIdx := r2_mul_robIdx(i)
  }

  // FP 0/2 & FP 1/3 (Ports 11, 12)
  io.exuWriteback(11).valid := exe_val_fp(0) || exe_val_fp(2)
  io.exuWriteback(11).bits.robIdx := Mux(exe_val_fp(0), exe_uop_fp(0).robIdx, exe_uop_fp(2).robIdx)

  val exe_is_fpdiv = exe_dec_fp(3).is_fdiv || exe_dec_fp(3).is_fsqrt
  io.exuWriteback(12).valid := exe_val_fp(1) || (exe_val_fp(3) && !exe_is_fpdiv)
  io.exuWriteback(12).bits.robIdx := Mux(exe_val_fp(1), exe_uop_fp(1).robIdx, exe_uop_fp(3).robIdx)

  // FPDIV (Port 13)
  io.exuWriteback(13).valid := fpdiv.io.done
  io.exuWriteback(13).bits.robIdx := fpdiv_robIdx_latch
}
