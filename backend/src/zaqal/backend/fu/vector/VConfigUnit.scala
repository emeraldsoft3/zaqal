package zaqal.backend.fu.vector

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * RVV 1.0 Vector Configuration Unit (VConfigUnit)
 *
 * Implements:
 * - vsetvli  rd, rs1, vtypei
 * - vsetivli rd, uimm, vtypei
 * - vsetvl   rd, rs1, rs2
 *
 * Dynamically computes VLMAX, evaluates AVL constraints, sets the architectural
 * vtype and vl state, and produces the scalar result for register rd.
 */
class VConfigUnit(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val valid       = Input(Bool())
    val is_vsetvli  = Input(Bool())
    val is_vsetivli = Input(Bool())
    val is_vsetvl   = Input(Bool())

    val rd_idx      = Input(UInt(5.W))
    val rs1_idx     = Input(UInt(5.W))
    val rs1_val     = Input(UInt(xLen.W))
    val rs2_val     = Input(UInt(xLen.W))
    val zimm        = Input(UInt(11.W))

    // Outputs
    val vl_out      = Output(UInt(xLen.W)) // Value written to integer register rd
    val vtype_out   = Output(UInt(xLen.W)) // Architectural vtype
    val vl_val      = Output(UInt(xLen.W)) // Architectural vl
    val vlmax       = Output(UInt(xLen.W)) // Current VLMAX
    val is_vill     = Output(Bool())       // Illegal configuration flag
  })

  // Architectural Configuration Registers
  val r_vl    = RegInit(0.U(xLen.W))
  val r_vtype = RegInit(Cat(1.U(1.W), 0.U((xLen - 1).W))) // Reset with vill = 1

  // Extract requested vtype components
  val req_raw_vtype = Mux(io.is_vsetvl, io.rs2_val, Mux(io.is_vsetivli, io.zimm(9, 0), io.zimm))
  val req_ma    = req_raw_vtype(7)
  val req_ta    = req_raw_vtype(6)
  val req_vsew  = req_raw_vtype(5, 3)
  val req_vlmul = req_raw_vtype(2, 0)

  // Legality Checking
  // 1. vsew must be <= 3 (8, 16, 32, 64)
  val vsew_legal = req_vsew <= 3.U
  // 2. vlmul != 4 (reserved)
  val vlmul_legal = req_vlmul =/= 4.U
  // 3. Minimum fractional element constraint:
  //    (vLen / SEW) * LMUL >= 1
  //    For 128-bit VLEN:
  //      SEW=64 (2 elem): mf4, mf8 illegal
  //      SEW=32 (4 elem): mf8 illegal
  val frac_legal = WireDefault(true.B)
  when(req_vsew === VSew.e64) {
    frac_legal := (req_vlmul =/= VLmul.mf4) && (req_vlmul =/= VLmul.mf8)
  }.elsewhen(req_vsew === VSew.e32) {
    frac_legal := (req_vlmul =/= VLmul.mf8)
  }

  val config_legal = vsew_legal && vlmul_legal && frac_legal

  // Calculate VLMAX based on VLEN, SEW, and LMUL
  // Base elements in one 128-bit register:
  // e8 -> 16, e16 -> 8, e32 -> 4, e64 -> 2
  val base_elems = WireDefault(0.U(8.W))
  switch(req_vsew) {
    is(VSew.e8)  { base_elems := (vLen / 8).U }
    is(VSew.e16) { base_elems := (vLen / 16).U }
    is(VSew.e32) { base_elems := (vLen / 32).U }
    is(VSew.e64) { base_elems := (vLen / 64).U }
  }

  val calc_vlmax = WireDefault(0.U(xLen.W))
  switch(req_vlmul) {
    is(VLmul.m1)  { calc_vlmax := base_elems }
    is(VLmul.m2)  { calc_vlmax := base_elems << 1 }
    is(VLmul.m4)  { calc_vlmax := base_elems << 2 }
    is(VLmul.m8)  { calc_vlmax := base_elems << 3 }
    is(VLmul.mf2) { calc_vlmax := base_elems >> 1 }
    is(VLmul.mf4) { calc_vlmax := base_elems >> 2 }
    is(VLmul.mf8) { calc_vlmax := base_elems >> 3 }
  }

  // Calculate AVL (Application Vector Length)
  val req_avl = Wire(UInt(xLen.W))
  when(io.is_vsetivli) {
    // 5-bit zero-extended immediate from rs1 field
    req_avl := io.rs1_idx
  }.otherwise {
    when(io.rs1_idx =/= 0.U) {
      req_avl := io.rs1_val
    }.elsewhen(io.rd_idx =/= 0.U) {
      // rs1 == x0, rd != x0: Set AVL to maximum possible (VLMAX)
      req_avl := calc_vlmax
    }.otherwise {
      // rs1 == x0, rd == x0: Keep existing vl (clamped to new VLMAX)
      req_avl := r_vl
    }
  }

  // Compute final new_vl and new_vtype
  val new_vl = Wire(UInt(xLen.W))
  val new_vtype = Wire(UInt(xLen.W))

  when(!config_legal) {
    new_vl    := 0.U
    new_vtype := Cat(1.U(1.W), 0.U((xLen - 1).W)) // vill = 1
  }.otherwise {
    new_vl    := Mux(req_avl <= calc_vlmax, req_avl, calc_vlmax)
    new_vtype := Cat(0.U((xLen - 8).W), req_ma, req_ta, req_vsew, req_vlmul)
  }

  // State Updates on Valid Instruction
  when(io.valid) {
    r_vl    := new_vl
    r_vtype := new_vtype
  }

  // Combinational Outputs
  io.vl_out    := new_vl
  io.vtype_out := Mux(io.valid, new_vtype, r_vtype)
  io.vl_val    := Mux(io.valid, new_vl, r_vl)
  io.vlmax     := calc_vlmax
  io.is_vill   := !config_legal
}
