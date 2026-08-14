package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RAS(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Speculative BPU Interface
    val spec_push_valid    = Input(Bool())
    val spec_push_addr     = Input(UInt(xLen.W))
    val spec_pop_valid     = Input(Bool())
    val spec_pop_addr      = Output(UInt(xLen.W))
    val spec_pop_valid_out = Output(Bool())
    val spec_sp            = Output(UInt(log2Up(rasEntries).W))
    
    // Architectural Commit Interface (From ROB)
    val commit_push_valid  = Input(Bool())
    val commit_push_addr   = Input(UInt(xLen.W))
    val commit_pop_valid   = Input(Bool())

    // Restore Interface (From BRU / FTQ)
    val restore_en         = Input(Bool())
    val restore_sp         = Input(UInt(log2Up(rasEntries).W))
  })

  // Dual Stack Structures
  val arch_stack = RegInit(VecInit(Seq.fill(rasEntries)(0.U(xLen.W))))
  val arch_sp    = RegInit(0.U(log2Up(rasEntries).W))

  val spec_stack = RegInit(VecInit(Seq.fill(rasEntries)(0.U(xLen.W))))
  val spec_sp    = RegInit(0.U(log2Up(rasEntries).W))

  // 1. Architectural Stack Logic (Safe, non-speculative)
  when(io.commit_push_valid && !io.commit_pop_valid) {
    arch_stack(arch_sp) := io.commit_push_addr
    arch_sp := arch_sp + 1.U
  } .elsewhen(io.commit_pop_valid && !io.commit_push_valid) {
    arch_sp := arch_sp - 1.U
  } .elsewhen(io.commit_push_valid && io.commit_pop_valid) {
    arch_stack(arch_sp - 1.U) := io.commit_push_addr
  }

  // 2. Speculative Stack Logic (Fast, can be corrupted)
  when(io.restore_en) {
    // On a branch misprediction, restore the pointer snapshot.
    // If the snapshot pointer is less than the architectural pointer, it means 
    // wrong-path pops went too deep. We pull the true value from arch_stack.
    spec_sp := io.restore_sp
    for (i <- 0 until rasEntries) {
      spec_stack(i) := arch_stack(i) // Aggressive 1-cycle copy for simplicity
    }
  } .elsewhen(io.spec_push_valid && !io.spec_pop_valid) {
    spec_stack(spec_sp) := io.spec_push_addr
    spec_sp := spec_sp + 1.U
  } .elsewhen(io.spec_pop_valid && !io.spec_push_valid) {
    spec_sp := spec_sp - 1.U
  } .elsewhen(io.spec_push_valid && io.spec_pop_valid) {
    spec_stack(spec_sp - 1.U) := io.spec_push_addr
  }

  val top_idx = Mux(spec_sp === 0.U, (rasEntries - 1).U, spec_sp - 1.U)
  io.spec_pop_addr      := spec_stack(top_idx)
  io.spec_pop_valid_out := spec_sp > 0.U
  io.spec_sp            := spec_sp
}
