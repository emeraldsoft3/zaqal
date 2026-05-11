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
    val debug_regs = Output(Vec(logicalRegs, UInt(xLen.W)))
    val debug_fp_regs = Output(Vec(32, UInt(fLen.W)))
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
  val rat = Module(new RenameTable)
  
  // Simple Free List / Pdest allocator (for demonstration)
  // In a real design, this would be a proper FreeList module.
  val pdest_ptr = RegInit(32.U(phyRegIdxWidth.W))
  val next_pdest_ptr = Wire(Vec(decodeWidth + 1, UInt(phyRegIdxWidth.W)))
  next_pdest_ptr(0) := pdest_ptr

  for (i <- 0 until decodeWidth) {
    val dec = decoded_uops(i).decode
    
    // 1. Connect Read Ports
    rat.io.readPorts(i)(0).addr := dec.rs1
    rat.io.readPorts(i)(1).addr := dec.rs2
    rat.io.readPorts(i)(2).addr := dec.rs3
    
    decoded_uops(i).psrs1 := rat.io.readPorts(i)(0).data
    decoded_uops(i).psrs2 := rat.io.readPorts(i)(1).data
    decoded_uops(i).psrs3 := rat.io.readPorts(i)(2).data
    
    // 2. Allocate Pdest if the instruction writes to a register
    // Simplified: any instruction with rd != 0 that is not a branch/store writes to RF
    val rf_wen = dec.rd =/= 0.U && !dec.is_branch && !dec.is_store
    
    decoded_uops(i).pdest := Mux(rf_wen, next_pdest_ptr(i), 0.U)
    next_pdest_ptr(i+1) := Mux(io.dispatch(i).fire && rf_wen, 
                               Mux(next_pdest_ptr(i) === (phyRegs-1).U, 32.U, next_pdest_ptr(i) + 1.U), 
                               next_pdest_ptr(i))
    
    // 3. Connect Rename Ports
    rat.io.renamePorts(i).wen  := io.dispatch(i).fire && rf_wen
    rat.io.renamePorts(i).addr := dec.rd
    rat.io.renamePorts(i).data := decoded_uops(i).pdest
    
    decoded_uops(i).old_pdest := rat.io.old_pdest(i)
    
    // Debug Print for Rename
    when(io.dispatch(i).valid) {
      printf(p"CORE RENAME [Cycle ${io.debug_cycle}] [Port $i]: pc=${Hexadecimal(decoded_uops(i).uop.pc)} inst=${Hexadecimal(decoded_uops(i).uop.inst_raw)} ")
      printf(p"lrs1=${dec.rs1}->prs1=${decoded_uops(i).psrs1} lrs2=${dec.rs2}->prs2=${decoded_uops(i).psrs2} ")
      when(rf_wen) {
        printf(p"lrd=${dec.rd}->pdest=${decoded_uops(i).pdest} (old=${decoded_uops(i).old_pdest})")
      }
      printf("\n")
    }
  }
  pdest_ptr := next_pdest_ptr(decodeWidth)
  
  // Tie off commit ports and redirect for now
  for (i <- 0 until decodeWidth) {
    rat.io.commitPorts(i).wen := false.B
    rat.io.commitPorts(i).addr := 0.U
    rat.io.commitPorts(i).data := 0.U
  }
  rat.io.redirect := false.B // TODO: Connect to actual redirect signal

  val exec = Module(new Execute)

  // Day 3/4: Still single-issue execution.
  // We feed the first renamed uop to the Execute module.
  exec.io.in.valid := io.dispatch(0).valid
  exec.io.in.bits  := decoded_uops(0)
  io.dispatch(0).ready := exec.io.in.ready

  for (i <- 1 until decodeWidth) {
    io.dispatch(i).ready := false.B
  }

  // Route redirection from Execute to Frontend
  io.redirect := exec.io.redirect
  io.debug_regs := exec.io.debug_regs
  io.debug_fp_regs := exec.io.debug_fp_regs
  exec.io.debug_cycle := io.debug_cycle
}
