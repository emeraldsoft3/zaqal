package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Dispatch(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // 6-wide Renamed micro-ops from Rename Stage
    val in = Vec(decodeWidth, Flipped(Decoupled(new DecodedMicroOp)))
    
    // Distributed Output Ports (6-wide each to feed distributed queues)
    val aluOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val memOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val bruOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val fpuOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    
    // Structural Hazard/Ready signals from target queues/functional units
    val aluReady = Input(Bool())
    val memReady = Input(Bool())
    val bruReady = Input(Bool())
    val fpuReady = Input(Bool())
  })

  // 1. Port Target Decoding & Classification for each lane
  val port_ready = Wire(Vec(decodeWidth, Bool()))

  for (i <- 0 until decodeWidth) {
    val dec = io.in(i).bits.decode
    
    // Memory Port target rules: loads, stores, atomics, and FP loads/stores
    val is_mem_op = dec.is_load || dec.is_store || dec.is_fload || dec.is_fstore || dec.is_atomic
    
    // Branch Port target rules: branches, JAL, and JALR
    val is_bru_op = dec.is_branch || dec.is_jal || dec.is_jalr
    
    // Floating Point target rules: FP arithmetic/miscellaneous excluding memory loads/stores
    val is_fpu_op = (dec.rd_is_fp || dec.rs1_is_fp || dec.rs2_is_fp || dec.rs3_is_fp || dec.is_fcsr_access) && !is_mem_op
    
    // Integer ALU target rules: All other instructions default to Integer ALU cluster
    val is_alu_op = !is_mem_op && !is_bru_op && !is_fpu_op

    // Port readiness calculation for this lane
    port_ready(i) := !io.in(i).valid || MuxCase(false.B, Seq(
      is_alu_op -> io.aluReady,
      is_mem_op -> io.memReady,
      is_bru_op -> io.bruReady,
      is_fpu_op -> io.fpuReady
    ))
  }

  // 2. In-Order Cascaded Dispatch Backpressure
  // If instruction i cannot dispatch (because its target queue is full),
  // then all younger instructions (lanes i to 5) must also be stalled.
  val can_dispatch = Wire(Vec(decodeWidth, Bool()))
  can_dispatch(0) := port_ready(0)

  for (i <- 1 until decodeWidth) {
    can_dispatch(i) := can_dispatch(i - 1) && port_ready(i)
  }

  // Bind the ready outputs of the input decoupled interfaces
  for (i <- 0 until decodeWidth) {
    io.in(i).ready := can_dispatch(i)
  }

  // 3. Routing decoded and renamed micro-ops to target ports
  for (i <- 0 until decodeWidth) {
    val dec = io.in(i).bits.decode
    
    val is_mem_op = dec.is_load || dec.is_store || dec.is_fload || dec.is_fstore || dec.is_atomic
    val is_bru_op = dec.is_branch || dec.is_jal || dec.is_jalr
    val is_fpu_op = (dec.rd_is_fp || dec.rs1_is_fp || dec.rs2_is_fp || dec.rs3_is_fp || dec.is_fcsr_access) && !is_mem_op
    val is_alu_op = !is_mem_op && !is_bru_op && !is_fpu_op

    // ALU Output Port Routing
    io.aluOut(i).valid := io.in(i).valid && io.in(i).ready && is_alu_op
    io.aluOut(i).bits  := io.in(i).bits

    // MEM Output Port Routing
    io.memOut(i).valid := io.in(i).valid && io.in(i).ready && is_mem_op
    io.memOut(i).bits  := io.in(i).bits

    // BRU Output Port Routing
    io.bruOut(i).valid := io.in(i).valid && io.in(i).ready && is_bru_op
    io.bruOut(i).bits  := io.in(i).bits

    // FPU Output Port Routing
    io.fpuOut(i).valid := io.in(i).valid && io.in(i).ready && is_fpu_op
    io.fpuOut(i).bits  := io.in(i).bits
    
    // Debug output prints for active dispatch decisions
    when(io.in(i).valid && io.in(i).ready) {
      printf(p"CORE DISPATCH: pc=${Hexadecimal(io.in(i).bits.uop.pc)} inst=${Hexadecimal(io.in(i).bits.uop.inst_raw)} -> Routed to [")
      when(is_alu_op) { printf("ALU") }
      when(is_mem_op) { printf("MEM") }
      when(is_bru_op) { printf("BRU") }
      when(is_fpu_op) { printf("FPU") }
      printf("]\n")
    }
  }
}
