package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class Dispatch(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // 6-wide Renamed micro-ops from Rename Stage
    val in = Vec(decodeWidth, Flipped(Decoupled(new DecodedMicroOp)))
    
    // Fusion feedback: identifies instructions fused away
    val is_fused_away = Input(Vec(decodeWidth, Bool()))
    
    // Distributed Output Ports (6-wide each to feed distributed queues)
    val aluOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val memOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val bruOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    val fpuOut = Vec(decodeWidth, Decoupled(new DecodedMicroOp))
    
    // Structural Hazard/Ready signals from target queues/functional units
    val aluReady = Input(Vec(decodeWidth, Bool()))
    val memReady = Input(Vec(decodeWidth, Bool()))
    val bruReady = Input(Vec(decodeWidth, Bool()))
    val fpuReady = Input(Vec(decodeWidth, Bool()))
  })

  // 1. Port Target Decoding & Classification for each lane
  val port_ready = Wire(Vec(decodeWidth, Bool()))

  // Shadow parcel logic (dynamic scanning based on RVC status)
  val is_shadow = Wire(Vec(decodeWidth, Bool()))
  val is_val_inst = Wire(Vec(decodeWidth, Bool()))
  is_shadow(0) := false.B
  is_val_inst(0) := true.B
  for (j <- 1 until decodeWidth) {
    is_shadow(j) := is_val_inst(j - 1) && !io.in(j - 1).bits.decode.is_rvc
    is_val_inst(j) := !is_shadow(j)
  }

  // Capacity parameters for the current execution cluster
  val max_alu_units   = 2.U
  val max_mem_units   = 1.U
  val max_bru_units   = 1.U
  val max_fpu_units   = 1.U
  val max_total_ports = 6.U  // Support up to 6-wide dispatch per cycle

  // Track resource requests per slot
  val req_alu = Wire(Vec(decodeWidth, Bool()))
  val req_mem = Wire(Vec(decodeWidth, Bool()))
  val req_bru = Wire(Vec(decodeWidth, Bool()))
  val req_fpu = Wire(Vec(decodeWidth, Bool()))
  val req_any = Wire(Vec(decodeWidth, Bool()))

  for (i <- 0 until decodeWidth) {
    val dec = io.in(i).bits.decode
    val is_mem = dec.is_load || dec.is_store || dec.is_fload || dec.is_fstore || dec.is_atomic
    val is_bru = dec.is_branch || dec.is_jal || dec.is_jalr
    val is_fpu = (dec.rd_is_fp || dec.rs1_is_fp || dec.rs2_is_fp || dec.rs3_is_fp || dec.is_fcsr_access) && !is_mem
    val is_alu = !is_mem && !is_bru && !is_fpu

    val active = io.in(i).valid && !is_shadow(i) && !io.is_fused_away(i)
    req_alu(i) := active && is_alu
    req_mem(i) := active && is_mem
    req_bru(i) := active && is_bru
    req_fpu(i) := active && is_fpu
    req_any(i) := active
  }

  // Calculate cumulative resource allocations before slot i
  val alu_allocated   = Wire(Vec(decodeWidth, UInt(3.W)))
  val mem_allocated   = Wire(Vec(decodeWidth, UInt(3.W)))
  val bru_allocated   = Wire(Vec(decodeWidth, UInt(3.W)))
  val fpu_allocated   = Wire(Vec(decodeWidth, UInt(3.W)))
  val total_allocated = Wire(Vec(decodeWidth, UInt(3.W)))

  alu_allocated(0)   := 0.U
  mem_allocated(0)   := 0.U
  bru_allocated(0)   := 0.U
  fpu_allocated(0)   := 0.U
  total_allocated(0) := 0.U

  for (i <- 1 until decodeWidth) {
    alu_allocated(i)   := alu_allocated(i - 1) + Mux(req_alu(i - 1), 1.U, 0.U)
    mem_allocated(i)   := mem_allocated(i - 1) + Mux(req_mem(i - 1), 1.U, 0.U)
    bru_allocated(i)   := bru_allocated(i - 1) + Mux(req_bru(i - 1), 1.U, 0.U)
    fpu_allocated(i)   := fpu_allocated(i - 1) + Mux(req_fpu(i - 1), 1.U, 0.U)
    total_allocated(i) := total_allocated(i - 1) + Mux(req_any(i - 1), 1.U, 0.U)
  }

  // Detect structural hazards for each slot i
  val hazard_detected = Wire(Vec(decodeWidth, Bool()))
  for (i <- 0 until decodeWidth) {
    hazard_detected(i) := MuxCase(false.B, Seq(
      req_alu(i) -> (alu_allocated(i) >= max_alu_units),
      req_mem(i) -> (mem_allocated(i) >= max_mem_units),
      req_bru(i) -> (bru_allocated(i) >= max_bru_units),
      req_fpu(i) -> (fpu_allocated(i) >= max_fpu_units)
    )) || (total_allocated(i) >= max_total_ports && req_any(i))
  }

  for (i <- 0 until decodeWidth) {
    val dec = io.in(i).bits.decode
    val is_mem_op = dec.is_load || dec.is_store || dec.is_fload || dec.is_fstore || dec.is_atomic
    val is_bru_op = dec.is_branch || dec.is_jal || dec.is_jalr
    val is_fpu_op = (dec.rd_is_fp || dec.rs1_is_fp || dec.rs2_is_fp || dec.rs3_is_fp || dec.is_fcsr_access) && !is_mem_op
    val is_alu_op = !is_mem_op && !is_bru_op && !is_fpu_op

    // Port readiness calculation including structural hazard checks
    port_ready(i) := !io.in(i).valid || is_shadow(i) || io.is_fused_away(i) || (MuxCase(false.B, Seq(
      is_alu_op -> io.aluReady(i),
      is_mem_op -> io.memReady(i),
      is_bru_op -> io.bruReady(i),
      is_fpu_op -> io.fpuReady(i)
    )) && !hazard_detected(i))
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

    val active = io.in(i).valid && !is_shadow(i) && !io.is_fused_away(i)

    // ALU Output Port Routing
    io.aluOut(i).valid := active && io.in(i).ready && is_alu_op
    io.aluOut(i).bits  := io.in(i).bits

    // MEM Output Port Routing
    io.memOut(i).valid := active && io.in(i).ready && is_mem_op
    io.memOut(i).bits  := io.in(i).bits

    // BRU Output Port Routing
    io.bruOut(i).valid := active && io.in(i).ready && is_bru_op
    io.bruOut(i).bits  := io.in(i).bits

    // FPU Output Port Routing
    io.fpuOut(i).valid := active && io.in(i).ready && is_fpu_op
    io.fpuOut(i).bits  := io.in(i).bits
    
    // Debug output prints for active dispatch decisions
    when(io.in(i).valid && io.in(i).ready) {
      // printf(p"CORE DISPATCH: pc=${Hexadecimal(io.in(i).bits.uop.pc)} inst=${Hexadecimal(io.in(i).bits.uop.inst_raw)} -> Routed to [")
      // when(is_alu_op) { printf("ALU") }
      // when(is_mem_op) { printf("MEM") }
      // when(is_bru_op) { printf("BRU") }
      // when(is_fpu_op) { printf("FPU") }
      // printf("]\n")
    }
  }
}
