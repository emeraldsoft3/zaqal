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
  val decoded_uops = Wire(Vec(decodeWidth, new DecodedMicroOp))

  for (i <- 0 until decodeWidth) {
    decoders(i).io.inst := io.dispatch(i).bits.inst_raw
    decoded_uops(i).uop    := io.dispatch(i).bits
    decoded_uops(i).decode := decoders(i).io.out
  }

  // Day 4: Register Renaming (Map Table)
  val rat = Module(new RenameTableWrapper)
  
  // Day 5: Free List Management
  val intFreeList = Module(new FreeList(phyRegs, logicalRegs))
  val fpFreeList  = Module(new FreeList(phyRegs, logicalRegs))

  // Tie off redirect and archHeadPtr for now
  intFreeList.io.redirect := rat.io.redirect
  intFreeList.io.archHeadPtr := 0.U
  intFreeList.io.doAllocate := false.B // Will be set below

  fpFreeList.io.redirect := rat.io.redirect
  fpFreeList.io.archHeadPtr := 0.U
  fpFreeList.io.doAllocate := false.B

  val can_allocate_all = intFreeList.io.canAllocate && fpFreeList.io.canAllocate

  for (i <- 0 until decodeWidth) {
    val dec = decoded_uops(i).decode
    
    // 1. Connect Decode and Read Ports
    rat.io.dec(i) := dec
    
    decoded_uops(i).psrs1 := rat.io.psrs1(i)
    decoded_uops(i).psrs2 := rat.io.psrs2(i)
    decoded_uops(i).psrs3 := rat.io.psrs3(i)
    
    // 2. Allocate Pdest if the instruction writes to a register
    val rf_wen = dec.rd =/= 0.U && !dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic
    val fp_wen = dec.rd_is_fp && !dec.is_branch && !dec.is_store && !dec.is_fstore && !dec.is_atomic

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
    
    // Debug Print for Rename
    when(io.dispatch(i).valid) {
      printf(p"CORE RENAME [Cycle ${io.debug_cycle}] [Port $i]: pc=${Hexadecimal(decoded_uops(i).uop.pc)} inst=${Hexadecimal(decoded_uops(i).uop.inst_raw)} ")
      printf(p"lrs1=${dec.rs1}->prs1=${decoded_uops(i).psrs1} lrs2=${dec.rs2}->prs2=${decoded_uops(i).psrs2} ")
      when(rf_wen || fp_wen) {
        printf(p"lrd=${dec.rd}->pdest=${decoded_uops(i).pdest} (old=${decoded_uops(i).old_pdest})")
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
  rat.io.redirect := false.B // TODO: Connect to actual redirect signal

  val exec = Module(new Execute)

  // Day 3/4: Still single-issue execution.
  // We feed the first renamed uop to the Execute module.
  exec.io.in.valid := io.dispatch(0).valid && can_allocate_all
  exec.io.in.bits  := decoded_uops(0)
  io.dispatch(0).ready := exec.io.in.ready && can_allocate_all

  for (i <- 1 until decodeWidth) {
    io.dispatch(i).ready := false.B // Future: Multi-issue execution
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
