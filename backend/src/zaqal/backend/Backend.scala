package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

import zaqal.backend.RenameTable
import zaqal.utility.SkidBuffer
import zaqal.backend.issue._


class Backend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val dispatch = Vec(decodeWidth, Flipped(Decoupled(new MicroOp)))
    val redirect = Output(new BPURedirect)
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(fLen.W)))
    val debug_cycle = Input(UInt(64.W))
  })

  def wrapAdd(ptr: UInt, add: UInt): UInt = {
    val next = ptr +& add
    Mux(next >= renameSnapshotNum.U, next - renameSnapshotNum.U, next)
  }

  // Instantiate Decoders
  val decoders = Seq.fill(decodeWidth)(Module(new Decoder))
  val decoded_uops_raw = Wire(Vec(decodeWidth, new DecodedMicroOp))

  for (i <- 0 until decodeWidth) {
    decoders(i).io.inst := io.dispatch(i).bits.pre.expanded_inst
    decoded_uops_raw(i).uop    := io.dispatch(i).bits
    decoded_uops_raw(i).decode := decoders(i).io.out
    
    // Default to raw
    decoded_uops_raw(i).psrs1 := 0.U
    decoded_uops_raw(i).psrs2 := 0.U
    decoded_uops_raw(i).psrs3 := 0.U
    decoded_uops_raw(i).pdest := 0.U
    decoded_uops_raw(i).old_pdest := 0.U
    decoded_uops_raw(i).snapshotIdx := 0.U
    decoded_uops_raw(i).is_fused_away := false.B
  }

  // Day 3.5: Instruction Fusion (Macro-Op Fusion)
  // Detect fusion between Port 0 and Port 1 (standard for RVC or user-requested alignment)
  val decoded_uops = Wire(Vec(decodeWidth, new DecodedMicroOp))
  for (i <- 0 until decodeWidth) {
    decoded_uops(i) := decoded_uops_raw(i)
  }

  val is_fused_with_next = WireInit(false.B)
  val u0_raw = decoded_uops_raw(0)
  
  // Select the next actual instruction (skip the shadow parcel if u0 is 32-bit)
  val u1_raw = Mux(u0_raw.decode.is_rvc, decoded_uops_raw(1), decoded_uops_raw(2))

  // 1. LUI/AUIPC + ADDI Fusion
  val can_fuse_lui_addi = (u0_raw.decode.is_lui || u0_raw.decode.is_auipc) && 
                          u1_raw.decode.is_addi && 
                          (u0_raw.decode.rd === u1_raw.decode.rs1) && (u0_raw.decode.rd === u1_raw.decode.rd) &&
                          (u0_raw.decode.rd =/= 0.U) && io.dispatch(0).valid && 
                          Mux(u0_raw.decode.is_rvc, io.dispatch(1).valid, io.dispatch(2).valid)

  // 2. Load + ADDI Fusion (LW + ADDI)
  val can_fuse_load_alu = u0_raw.decode.is_load && 
                          u1_raw.decode.is_addi && 
                          (u0_raw.decode.rd === u1_raw.decode.rs1) && (u0_raw.decode.rd === u1_raw.decode.rd) &&
                          (u0_raw.decode.rd =/= 0.U) && io.dispatch(0).valid && 
                          Mux(u0_raw.decode.is_rvc, io.dispatch(1).valid, io.dispatch(2).valid)

  // 3. ADDI + Store Fusion (ADDI + SW)
  val can_fuse_alu_store = u0_raw.decode.is_addi && 
                           u1_raw.decode.is_store && 
                           (u0_raw.decode.rd === u1_raw.decode.rs2) &&
                           (u0_raw.decode.rd =/= 0.U) && io.dispatch(0).valid && 
                           Mux(u0_raw.decode.is_rvc, io.dispatch(1).valid, io.dispatch(2).valid)

  // Use Mux for fusion assignments to avoid scope escape issues
  val fuse_any = can_fuse_lui_addi || can_fuse_load_alu || can_fuse_alu_store
  is_fused_with_next := fuse_any
  
  decoded_uops(0).decode.is_fused := fuse_any
  decoded_uops(0).decode.is_fused_lui_addi := can_fuse_lui_addi
  decoded_uops(0).decode.is_fused_load_alu := can_fuse_load_alu
  decoded_uops(0).decode.is_fused_alu_store := can_fuse_alu_store
  
  decoded_uops(0).decode.imm := Mux(can_fuse_lui_addi, (u0_raw.decode.imm + u1_raw.decode.imm), u0_raw.decode.imm)
  decoded_uops(0).decode.fused_imm := Mux(can_fuse_load_alu || can_fuse_alu_store, u1_raw.decode.imm, 0.S)
  decoded_uops(0).decode.rs2 := Mux(can_fuse_alu_store, u1_raw.decode.rs1, u0_raw.decode.rs2)

  // Day 4: Register Renaming (Map Table)
  val rat = Module(new RenameTableWrapper)
  
  // Day 5: Free List Management
  val intFreeList = Module(new FreeList(phyRegs, logicalRegs))
  val fpFreeList  = Module(new FreeList(phyRegs, logicalRegs))

  // Tie off redirect and archHeadPtr for now
  intFreeList.io.archHeadPtr := 0.U
  intFreeList.io.doAllocate := false.B // Will be set below

  fpFreeList.io.archHeadPtr := 0.U
  fpFreeList.io.doAllocate := false.B

  // Define has_branch and branch_slot
  val branch_mask = Wire(Vec(decodeWidth, Bool()))
  for (i <- 0 until decodeWidth) {
    branch_mask(i) := (decoded_uops(i).decode.is_branch || decoded_uops(i).decode.is_jalr || decoded_uops(i).decode.is_jal) && io.dispatch(i).fire
  }
  val has_branch = branch_mask.asUInt.orR
  val branch_slot = PriorityEncoder(branch_mask)

  val is_branch_op = has_branch

  // When a branch is renamed/dispatched, we enqueue a snapshot
  rat.io.snptEnq := is_branch_op
  rat.io.snptEnqIdx := branch_slot
  rat.io.snptDeq := false.B

  intFreeList.io.snptEnq := is_branch_op
  intFreeList.io.snptEnqIdx := branch_slot
  intFreeList.io.snptDeq := false.B

  fpFreeList.io.snptEnq := is_branch_op
  fpFreeList.io.snptEnqIdx := branch_slot
  fpFreeList.io.snptDeq := false.B

  // Wires for Execute redirection feedback
  val redirect_valid = Wire(Bool())
  val restore_idx = Wire(UInt(log2Up(renameSnapshotNum).W))

  rat.io.redirect := redirect_valid
  rat.io.useSnapshot := true.B
  rat.io.snptRestoreIdx := restore_idx

  intFreeList.io.redirect := redirect_valid
  intFreeList.io.useSnapshot := true.B
  intFreeList.io.snptRestoreIdx := restore_idx

  fpFreeList.io.redirect := redirect_valid
  fpFreeList.io.useSnapshot := true.B
  fpFreeList.io.snptRestoreIdx := restore_idx

  // Compute younger snapshot flush mask
  for (i <- 0 until renameSnapshotNum) {
    val enqPtr = rat.io.snptEnqPtr
    val is_younger = Mux(restore_idx < enqPtr,
                         i.U > restore_idx && i.U < enqPtr,
                         i.U > restore_idx || i.U < enqPtr)
    val flush = redirect_valid && is_younger && rat.io.snptValids(i)
    rat.io.snptFlushVec(i) := flush
    intFreeList.io.snptFlushVec(i) := flush
    fpFreeList.io.snptFlushVec(i) := flush
  }

  val can_allocate_all = intFreeList.io.canAllocate && fpFreeList.io.canAllocate

  val is_shadow_vec = Wire(Vec(decodeWidth, Bool()))
  val is_val_inst_vec = Wire(Vec(decodeWidth, Bool()))
  is_shadow_vec(0) := false.B
  is_val_inst_vec(0) := true.B
  for (j <- 1 until decodeWidth) {
    is_shadow_vec(j) := is_val_inst_vec(j - 1) && !decoded_uops(j - 1).decode.is_rvc
    is_val_inst_vec(j) := !is_shadow_vec(j)
  }

  for (i <- 0 until decodeWidth) {
    val dec = decoded_uops(i).decode
    
    // 1. Connect Decode and Read Ports
    rat.io.dec(i) := dec
    
    decoded_uops(i).psrs1 := rat.io.psrs1(i)
    decoded_uops(i).psrs2 := rat.io.psrs2(i)
    decoded_uops(i).psrs3 := rat.io.psrs3(i)
    
    // 2. Allocate Pdest if the instruction writes to a register
    // Mark the next instruction as fused away if fusion happened
    val is_fused_away = Mux(u0_raw.decode.is_rvc, i.U === 1.U, i.U === 2.U) && is_fused_with_next
    
    // Identify shadow parcel slots (second half of a 32-bit instruction)
    val is_shadow = is_shadow_vec(i)

    val rf_wen = dec.rd =/= 0.U && !dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic && !is_fused_away && !is_shadow
    val fp_wen = dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic && !is_fused_away && !is_shadow

    intFreeList.io.allocateReq(i) := rf_wen && io.dispatch(i).valid
    intFreeList.io.allocateFire(i) := rf_wen && io.dispatch(i).fire
    fpFreeList.io.allocateReq(i)  := fp_wen && io.dispatch(i).valid
    fpFreeList.io.allocateFire(i) := fp_wen && io.dispatch(i).fire

    decoded_uops(i).pdest := MuxCase(0.U, Seq(
      intFreeList.io.allocateReq(i) -> intFreeList.io.allocatePhyReg(i),
      fpFreeList.io.allocateReq(i)  -> fpFreeList.io.allocatePhyReg(i)
    ))

    // 3. Connect Rename Ports
    rat.io.renamePorts(i).wen  := io.dispatch(i).fire && (rf_wen || fp_wen)
    rat.io.renamePorts(i).addr := dec.rd
    rat.io.renamePorts(i).data := decoded_uops(i).pdest
    
    decoded_uops(i).old_pdest := rat.io.old_pdest(i)
    val slot_is_younger_than_branch = has_branch && (i.U > branch_slot)
    decoded_uops(i).snapshotIdx := wrapAdd(rat.io.snptEnqPtr, Mux(slot_is_younger_than_branch, 1.U, 0.U))
    decoded_uops(i).is_fused_away := is_fused_away
    
    // Debug Print for Rename
    when(io.dispatch(i).valid) {
      printf(p"CORE RENAME [Cycle ${io.debug_cycle}] [Port $i]: pc=${Hexadecimal(decoded_uops(i).uop.pc)} inst=${Hexadecimal(decoded_uops(i).uop.inst_raw)} ")
      printf(p"lrs1=${dec.rs1}->prs1=${decoded_uops(i).psrs1} lrs2=${dec.rs2}->prs2=${decoded_uops(i).psrs2} ")
      when(rf_wen || fp_wen) {
        printf(p"lrd=${dec.rd}->pdest=${decoded_uops(i).pdest} (old=${decoded_uops(i).old_pdest})")
      }
      when(i.U === 0.U && is_fused_with_next) {
        printf(" [FUSING WITH NEXT: u1_pc=%x u1_inst=%x]", u0_raw.uop.pc, u1_raw.uop.inst_raw)
      }
      printf("\n")
    }
  }

  // Update FreeList doAllocate based on whether any instruction in the bundle fired
  val bundle_fired = io.dispatch.map(_.fire).reduce(_ || _)
  intFreeList.io.doAllocate := bundle_fired
  fpFreeList.io.doAllocate  := bundle_fired
  
  // Tie off commit ports and redirect for now
  for (i <- 0 until decodeWidth) {
    rat.io.commitPorts(i).wen := false.B
    rat.io.commitPorts(i).addr := 0.U
    rat.io.commitPorts(i).data := 0.U
    rat.io.commit_is_fp(i) := false.B

    intFreeList.io.freeReq(i) := false.B
    intFreeList.io.freePhyReg(i) := 0.U
    fpFreeList.io.freeReq(i) := false.B
    fpFreeList.io.freePhyReg(i) := 0.U
  }
  val exec = Module(new Execute)

  val dispatch = Module(new Dispatch)
  
  val rename_out = Wire(Vec(decodeWidth, Decoupled(new DecodedMicroOp)))
  val dispatch_in_buffered = Wire(Vec(decodeWidth, Decoupled(new DecodedMicroOp)))

  val all_skids_ready = rename_out.map(_.ready).reduce(_ && _)

  for (i <- 0 until decodeWidth) {
    rename_out(i).valid := io.dispatch(i).valid && all_skids_ready && can_allocate_all
    rename_out(i).bits  := decoded_uops(i)
    
    dispatch_in_buffered(i) <> SkidBuffer(rename_out(i), exec.io.redirect.valid)
    
    dispatch.io.in(i).valid := dispatch_in_buffered(i).valid
    dispatch.io.in(i).bits  := dispatch_in_buffered(i).bits
    dispatch.io.is_fused_away(i) := dispatch_in_buffered(i).bits.is_fused_away
    dispatch_in_buffered(i).ready := dispatch.io.in(i).ready
  }

  val busyTable = Module(new BusyTable)
  val intIq = Module(new IssueQueue(16, decodeWidth, 2, 5))
  val memIq = Module(new IssueQueue(8, decodeWidth, 1, 5))
  val fpIq = Module(new IssueQueue(8, decodeWidth, 1, 5))

  for (i <- 0 until decodeWidth) {
    busyTable.io.allocPorts(i).valid := io.dispatch(i).fire && (intFreeList.io.allocateReq(i) || fpFreeList.io.allocateReq(i))
    busyTable.io.allocPorts(i).bits := decoded_uops(i).pdest

    busyTable.io.readPorts(i)(0).addr := dispatch_in_buffered(i).bits.psrs1
    busyTable.io.readPorts(i)(1).addr := dispatch_in_buffered(i).bits.psrs2
    busyTable.io.readPorts(i)(2).addr := dispatch_in_buffered(i).bits.psrs3

    intIq.io.rs1_ready_in(i) := busyTable.io.readPorts(i)(0).ready
    intIq.io.rs2_ready_in(i) := busyTable.io.readPorts(i)(1).ready
    intIq.io.rs3_ready_in(i) := busyTable.io.readPorts(i)(2).ready
    
    memIq.io.rs1_ready_in(i) := busyTable.io.readPorts(i)(0).ready
    memIq.io.rs2_ready_in(i) := busyTable.io.readPorts(i)(1).ready
    memIq.io.rs3_ready_in(i) := busyTable.io.readPorts(i)(2).ready

    fpIq.io.rs1_ready_in(i) := busyTable.io.readPorts(i)(0).ready
    fpIq.io.rs2_ready_in(i) := busyTable.io.readPorts(i)(1).ready
    fpIq.io.rs3_ready_in(i) := busyTable.io.readPorts(i)(2).ready
  }

  for (w <- 0 until 5) {
    if (w == 3) {
      val reg_wakeup = Wire(new WakeupBus)
      reg_wakeup.valid := RegNext(exec.io.wakeup(w).valid, false.B)
      reg_wakeup.pdest := RegNext(exec.io.wakeup(w).pdest, 0.U)

      busyTable.io.wakeupPorts(w).valid := reg_wakeup.valid
      busyTable.io.wakeupPorts(w).bits  := reg_wakeup.pdest
      
      intIq.io.wakeup(w) := exec.io.wakeup(w) // Keep it combinational for intIq load-to-branch zero stall
      memIq.io.wakeup(w) := reg_wakeup
      fpIq.io.wakeup(w)  := reg_wakeup
    } else {
      busyTable.io.wakeupPorts(w).valid := exec.io.wakeup(w).valid
      busyTable.io.wakeupPorts(w).bits := exec.io.wakeup(w).pdest
      
      intIq.io.wakeup(w) := exec.io.wakeup(w)
      memIq.io.wakeup(w) := exec.io.wakeup(w)
      fpIq.io.wakeup(w)  := exec.io.wakeup(w)
    }
  }
  for (w <- 5 until decodeWidth) {
    busyTable.io.wakeupPorts(w).valid := false.B
    busyTable.io.wakeupPorts(w).bits := 0.U
  }

  redirect_valid := exec.io.redirect.valid
  restore_idx := exec.io.redirect.snapshotIdx

  intIq.io.redirect_valid := redirect_valid
  intIq.io.redirect_restore_idx := restore_idx
  intIq.io.redirect_enq_ptr := rat.io.snptEnqPtr

  memIq.io.redirect_valid := redirect_valid
  memIq.io.redirect_restore_idx := restore_idx
  memIq.io.redirect_enq_ptr := rat.io.snptEnqPtr

  fpIq.io.redirect_valid := redirect_valid
  fpIq.io.redirect_restore_idx := restore_idx
  fpIq.io.redirect_enq_ptr := rat.io.snptEnqPtr

  for (i <- 0 until decodeWidth) {
    intIq.io.enq(i).valid := dispatch.io.aluOut(i).valid || dispatch.io.bruOut(i).valid
    intIq.io.enq(i).bits := Mux(dispatch.io.aluOut(i).valid, dispatch.io.aluOut(i).bits, dispatch.io.bruOut(i).bits)
    dispatch.io.aluOut(i).ready := intIq.io.enq(i).ready
    dispatch.io.bruOut(i).ready := intIq.io.enq(i).ready

    memIq.io.enq(i).valid := dispatch.io.memOut(i).valid
    memIq.io.enq(i).bits := dispatch.io.memOut(i).bits
    dispatch.io.memOut(i).ready := memIq.io.enq(i).ready

    fpIq.io.enq(i).valid := dispatch.io.fpuOut(i).valid
    fpIq.io.enq(i).bits := dispatch.io.fpuOut(i).bits
    dispatch.io.fpuOut(i).ready := fpIq.io.enq(i).ready
  }

  for (i <- 0 until decodeWidth) {
    dispatch.io.aluReady(i) := intIq.io.enq(i).ready
    dispatch.io.bruReady(i) := intIq.io.enq(i).ready
    dispatch.io.memReady(i) := memIq.io.enq(i).ready
    dispatch.io.fpuReady(i) := fpIq.io.enq(i).ready
  }

  exec.io.int_in(0) <> intIq.io.deq(0)
  exec.io.int_in(1) <> intIq.io.deq(1)
  exec.io.mem_in <> memIq.io.deq(0)
  exec.io.fp_in <> fpIq.io.deq(0)
  exec.io.snptValids := rat.io.snptValids
  exec.io.snptDeqPtr := rat.io.snptDeqPtr

  // Dispatch Ready Logic (Dynamic Backpressure) - Enforce lock-step dispatch
  for (i <- 0 until decodeWidth) {
    io.dispatch(i).ready := all_skids_ready && can_allocate_all
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
