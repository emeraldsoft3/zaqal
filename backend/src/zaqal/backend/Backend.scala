package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

import zaqal.backend.RenameTable
import zaqal.utility.SkidBuffer


class Backend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val dispatch = Vec(decodeWidth, Flipped(Decoupled(new MicroOp)))
    val redirect = Output(new BPURedirect)
    val debug_regs = Output(Vec(phyRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(phyRegs, UInt(fLen.W)))
    val debug_cycle = Input(UInt(64.W))
  })

  // Instantiate Decoders
  val decoders = Seq.fill(decodeWidth)(Module(new Decoder))
  val decoded_uops_raw = Wire(Vec(decodeWidth, new DecodedMicroOp))

  for (i <- 0 until decodeWidth) {
    decoders(i).io.inst := io.dispatch(i).bits.inst_raw
    decoded_uops_raw(i).uop    := io.dispatch(i).bits
    decoded_uops_raw(i).decode := decoders(i).io.out
    
    // Default to raw
    decoded_uops_raw(i).psrs1 := 0.U
    decoded_uops_raw(i).psrs2 := 0.U
    decoded_uops_raw(i).psrs3 := 0.U
    decoded_uops_raw(i).pdest := 0.U
    decoded_uops_raw(i).old_pdest := 0.U
    decoded_uops_raw(i).snapshotIdx := 0.U
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

  // Define is_branch_op
  val is_branch_op = (decoded_uops(0).decode.is_branch || decoded_uops(0).decode.is_jalr) && io.dispatch(0).fire

  // When a branch is renamed/dispatched, we enqueue a snapshot
  rat.io.snptEnq := is_branch_op
  rat.io.snptEnqIdx := 0.U
  rat.io.snptDeq := false.B

  intFreeList.io.snptEnq := is_branch_op
  intFreeList.io.snptEnqIdx := 0.U
  intFreeList.io.snptDeq := false.B

  fpFreeList.io.snptEnq := is_branch_op
  fpFreeList.io.snptEnqIdx := 0.U
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
    val rf_wen = dec.rd =/= 0.U && !dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic && !is_fused_away
    val fp_wen = dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic && !is_fused_away

    intFreeList.io.allocateReq(i) := rf_wen && io.dispatch(i).valid
    fpFreeList.io.allocateReq(i)  := fp_wen && io.dispatch(i).valid

    decoded_uops(i).pdest := MuxCase(0.U, Seq(
      intFreeList.io.allocateReq(i) -> intFreeList.io.allocatePhyReg(i),
      fpFreeList.io.allocateReq(i)  -> fpFreeList.io.allocatePhyReg(i)
    ))

    // 3. Connect Rename Ports
    rat.io.renamePorts(i).wen  := io.dispatch(i).fire && (rf_wen || fp_wen)
    rat.io.renamePorts(i).addr := dec.rd
    rat.io.renamePorts(i).data := decoded_uops(i).pdest
    
    decoded_uops(i).old_pdest := rat.io.old_pdest(i)
    decoded_uops(i).snapshotIdx := Mux(i.U === 0.U && is_branch_op, rat.io.snptEnqPtr, 0.U)
    
    // Debug Print for Rename
    when(io.dispatch(i).valid) {
      printf(p"CORE RENAME [Cycle ${io.debug_cycle}] [Port $i]: pc=${Hexadecimal(decoded_uops(i).uop.pc)} inst=${Hexadecimal(decoded_uops(i).uop.inst_raw)} ")
      printf(p"lrs1=${dec.rs1}->prs1=${decoded_uops(i).psrs1} lrs2=${dec.rs2}->prs2=${decoded_uops(i).psrs2} ")
      when(rf_wen || fp_wen) {
        printf(p"lrd=${dec.rd}->pdest=${decoded_uops(i).pdest} (old=${decoded_uops(i).old_pdest})")
      }
      when(i.U === 0.U && is_fused_with_next) {
        printf(" [FUSING WITH NEXT: u1_pc=%x u1_inst=%x]", u1_raw.uop.pc, u1_raw.uop.inst_raw)
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

  redirect_valid := exec.io.redirect.valid
  restore_idx := exec.io.in.bits.snapshotIdx

  // Day 3/4: Still single-issue execution.
  // We feed the first renamed uop to the Execute module.
  exec.io.in.valid := io.dispatch(0).valid && can_allocate_all
  exec.io.in.bits  := decoded_uops(0)
  
  // Dispatch Ready Logic (16-bit parcel offsets)
  io.dispatch(0).ready := exec.io.in.ready && can_allocate_all
  
  // Port 1 is the second half of Port 0 if 32-bit
  io.dispatch(1).ready := (io.dispatch(0).ready && !u0_raw.decode.is_rvc) || (is_fused_with_next && io.dispatch(0).ready && u0_raw.decode.is_rvc)

  // Port 2 and 3 are consumed if Port 0 is 32-bit and fused with the next 32-bit instruction
  val consumes_port_2 = is_fused_with_next && io.dispatch(0).ready && !u0_raw.decode.is_rvc
  io.dispatch(2).ready := consumes_port_2
  io.dispatch(3).ready := consumes_port_2 && !u1_raw.decode.is_rvc
  
  // Day 4/5: Dispatch other ports (not used for fusion yet)
  for (i <- 4 until decodeWidth) {
    io.dispatch(i).ready := false.B 
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
