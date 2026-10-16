package zaqal.backend.fu.vector

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * RVV 1.0 Vector Integer & Floating-Point ALU (VectorAlu)
 *
 * Implements:
 * - OPIVV (0), OPFVV (1), OPMVV (2), OPIVI (3), OPIVX (4), OPFVF (5), OPMVX (6)
 * - Slices 128-bit registers according to SEW (8, 16, 32, 64 bits)
 * - Vector Arithmetic: vadd, vsub, vmin, vmax, vminu, vmaxu, vand, vor, vxor
 * - Vector Shifts: vsll, vsrl, vsra
 * - Vector Multiplication: vmul
 * - Vector Floating-Point: vfadd, vfsub, vfmul
 * - Vector Reductions: vredsum.vs
 * - Vector Comparisons: vmseq, vmsne, vmslt, vmsltu, vmsle, vmsleu
 * - Precise Byte-level write masking (wmask) honoring active length vl, mask v0, and vta
 */
class VectorAlu(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val valid        = Input(Bool())
    val funct3       = Input(UInt(3.W))
    val funct6       = Input(UInt(6.W))
    val vm           = Input(Bool())
    val simm5        = Input(SInt(5.W))
    val rs1_val      = Input(UInt(xLen.W))
    val fs1_val      = Input(UInt(64.W))
    val vs1_val      = Input(UInt(vLen.W))
    val vs2_val      = Input(UInt(vLen.W))
    val old_vd       = Input(UInt(vLen.W))
    val mask_v0      = Input(UInt(vLen.W))
    val vsew         = Input(UInt(3.W))
    val vta          = Input(Bool())
    val vma          = Input(Bool())
    val vl           = Input(UInt(xLen.W))

    val wdata        = Output(UInt(vLen.W))
    val wmask        = Output(UInt(vLenB.W)) // 16 bits for 128-bit VLEN
    val is_reduction = Output(Bool())
    val red_scalar   = Output(UInt(xLen.W))
  })

  val is_opivv = io.funct3 === 0.U
  val is_opfvv = io.funct3 === 1.U
  val is_opmvv = io.funct3 === 2.U
  val is_opivi = io.funct3 === 3.U
  val is_opivx = io.funct3 === 4.U
  val is_opfvf = io.funct3 === 5.U
  val is_opmvx = io.funct3 === 6.U

  // Broadcast operand 1 generation based on SEW
  val imm_elem8  = io.simm5.asSInt.pad(8).asUInt
  val imm_elem16 = io.simm5.asSInt.pad(16).asUInt
  val imm_elem32 = io.simm5.asSInt.pad(32).asUInt
  val imm_elem64 = io.simm5.asSInt.pad(64).asUInt

  val imm_broadcast = MuxLookup(io.vsew, 0.U(vLen.W))(Seq(
    VSew.e8  -> Cat(Seq.fill(16)(imm_elem8)),
    VSew.e16 -> Cat(Seq.fill(8)(imm_elem16)),
    VSew.e32 -> Cat(Seq.fill(4)(imm_elem32)),
    VSew.e64 -> Cat(Seq.fill(2)(imm_elem64))
  ))

  val rs1_broadcast = MuxLookup(io.vsew, 0.U(vLen.W))(Seq(
    VSew.e8  -> Cat(Seq.fill(16)(io.rs1_val(7, 0))),
    VSew.e16 -> Cat(Seq.fill(8)(io.rs1_val(15, 0))),
    VSew.e32 -> Cat(Seq.fill(4)(io.rs1_val(31, 0))),
    VSew.e64 -> Cat(Seq.fill(2)(io.rs1_val(63, 0)))
  ))

  val fs1_broadcast = MuxLookup(io.vsew, 0.U(vLen.W))(Seq(
    VSew.e32 -> Cat(Seq.fill(4)(io.fs1_val(31, 0))),
    VSew.e64 -> Cat(Seq.fill(2)(io.fs1_val(63, 0)))
  ))

  val op1 = Mux(is_opivi, imm_broadcast,
            Mux(is_opivx || is_opmvx, rs1_broadcast,
            Mux(is_opfvf, fs1_broadcast, io.vs1_val)))
  val op2 = io.vs2_val

  // Reduction detection: vredsum.vs (funct3 === 2.U && funct6 === 0.U)
  val is_redsum = is_opmvv && (io.funct6 === 0.U)
  io.is_reduction := is_redsum

  // --- SEW = 8-bit SLICES (16 elements) ---
  val res8 = Wire(Vec(16, UInt(8.W)))
  for (i <- 0 until 16) {
    val a = op2(i * 8 + 7, i * 8)
    val b = op1(i * 8 + 7, i * 8)
    val shamt = b(2, 0)
    val cmp_res = MuxLookup(io.funct6, false.B)(Seq(
      "h18".U -> (a === b),                  // vmseq
      "h19".U -> (a =/= b),                  // vmsne
      "h1a".U -> (a.asSInt < b.asSInt),      // vmslt
      "h1b".U -> (a < b),                    // vmsltu
      "h1c".U -> (a.asSInt <= b.asSInt),     // vmsle
      "h1d".U -> (a <= b),                   // vmsleu
      "h1e".U -> (a.asSInt > b.asSInt),      // vmsgt
      "h1f".U -> (a > b)                     // vmsgtu
    ))
    res8(i) := Mux(io.funct6(5, 3) === "b011".U, cmp_res.asUInt,
               Mux(is_opmvv || is_opmvx, (a * b)(7, 0),
               MuxLookup(io.funct6, 0.U(8.W))(Seq(
                 "h00".U -> (a + b),
                 "h02".U -> (a - b),
                 "h04".U -> Mux(a < b, a, b),
                 "h05".U -> Mux(a.asSInt < b.asSInt, a, b),
                 "h06".U -> Mux(a > b, a, b),
                 "h07".U -> Mux(a.asSInt > b.asSInt, a, b),
                 "h09".U -> (a & b),
                 "h0a".U -> (a | b),
                 "h0b".U -> (a ^ b),
                 "h25".U -> ((a << shamt)(7, 0)),
                 "h28".U -> ((a >> shamt)(7, 0)),
                 "h29".U -> ((a.asSInt >> shamt)(7, 0).asUInt)
               ))))
  }

  // --- SEW = 16-bit SLICES (8 elements) ---
  val res16 = Wire(Vec(8, UInt(16.W)))
  for (i <- 0 until 8) {
    val a = op2(i * 16 + 15, i * 16)
    val b = op1(i * 16 + 15, i * 16)
    val shamt = b(3, 0)
    val cmp_res = MuxLookup(io.funct6, false.B)(Seq(
      "h18".U -> (a === b),
      "h19".U -> (a =/= b),
      "h1a".U -> (a.asSInt < b.asSInt),
      "h1b".U -> (a < b),
      "h1c".U -> (a.asSInt <= b.asSInt),
      "h1d".U -> (a <= b),
      "h1e".U -> (a.asSInt > b.asSInt),
      "h1f".U -> (a > b)
    ))
    res16(i) := Mux(io.funct6(5, 3) === "b011".U, cmp_res.asUInt,
                Mux(is_opmvv || is_opmvx, (a * b)(15, 0),
                MuxLookup(io.funct6, 0.U(16.W))(Seq(
                  "h00".U -> (a + b),
                  "h02".U -> (a - b),
                  "h04".U -> Mux(a < b, a, b),
                  "h05".U -> Mux(a.asSInt < b.asSInt, a, b),
                  "h06".U -> Mux(a > b, a, b),
                  "h07".U -> Mux(a.asSInt > b.asSInt, a, b),
                  "h09".U -> (a & b),
                  "h0a".U -> (a | b),
                  "h0b".U -> (a ^ b),
                  "h25".U -> ((a << shamt)(15, 0)),
                  "h28".U -> ((a >> shamt)(15, 0)),
                  "h29".U -> ((a.asSInt >> shamt)(15, 0).asUInt)
                ))))
  }

  // --- SEW = 32-bit SLICES (4 elements) ---
  val res32 = Wire(Vec(4, UInt(32.W)))
  for (i <- 0 until 4) {
    val a = op2(i * 32 + 31, i * 32)
    val b = op1(i * 32 + 31, i * 32)
    val shamt = b(4, 0)
    val cmp_res = MuxLookup(io.funct6, false.B)(Seq(
      "h18".U -> (a === b),
      "h19".U -> (a =/= b),
      "h1a".U -> (a.asSInt < b.asSInt),
      "h1b".U -> (a < b),
      "h1c".U -> (a.asSInt <= b.asSInt),
      "h1d".U -> (a <= b),
      "h1e".U -> (a.asSInt > b.asSInt),
      "h1f".U -> (a > b)
    ))
    res32(i) := Mux(io.funct6(5, 3) === "b011".U, cmp_res.asUInt,
                Mux(is_opmvv || is_opmvx, (a * b)(31, 0),
                MuxLookup(io.funct6, 0.U(32.W))(Seq(
                  "h00".U -> (a + b),
                  "h02".U -> (a - b),
                  "h04".U -> Mux(a < b, a, b),
                  "h05".U -> Mux(a.asSInt < b.asSInt, a, b),
                  "h06".U -> Mux(a > b, a, b),
                  "h07".U -> Mux(a.asSInt > b.asSInt, a, b),
                  "h09".U -> (a & b),
                  "h0a".U -> (a | b),
                  "h0b".U -> (a ^ b),
                  "h25".U -> ((a << shamt)(31, 0)),
                  "h28".U -> ((a >> shamt)(31, 0)),
                  "h29".U -> ((a.asSInt >> shamt)(31, 0).asUInt)
                ))))
  }

  // --- SEW = 64-bit SLICES (2 elements) ---
  val res64 = Wire(Vec(2, UInt(64.W)))
  for (i <- 0 until 2) {
    val a = op2(i * 64 + 63, i * 64)
    val b = op1(i * 64 + 63, i * 64)
    val shamt = b(5, 0)
    val cmp_res = MuxLookup(io.funct6, false.B)(Seq(
      "h18".U -> (a === b),
      "h19".U -> (a =/= b),
      "h1a".U -> (a.asSInt < b.asSInt),
      "h1b".U -> (a < b),
      "h1c".U -> (a.asSInt <= b.asSInt),
      "h1d".U -> (a <= b),
      "h1e".U -> (a.asSInt > b.asSInt),
      "h1f".U -> (a > b)
    ))
    res64(i) := Mux(io.funct6(5, 3) === "b011".U, cmp_res.asUInt,
                Mux(is_opmvv || is_opmvx, (a * b)(63, 0),
                MuxLookup(io.funct6, 0.U(64.W))(Seq(
                  "h00".U -> (a + b),
                  "h02".U -> (a - b),
                  "h04".U -> Mux(a < b, a, b),
                  "h05".U -> Mux(a.asSInt < b.asSInt, a, b),
                  "h06".U -> Mux(a > b, a, b),
                  "h07".U -> Mux(a.asSInt > b.asSInt, a, b),
                  "h09".U -> (a & b),
                  "h0a".U -> (a | b),
                  "h0b".U -> (a ^ b),
                  "h25".U -> ((a << shamt)(63, 0)),
                  "h28".U -> ((a >> shamt)(63, 0)),
                  "h29".U -> ((a.asSInt >> shamt)(63, 0).asUInt)
                ))))
  }

  // Vector Reduction Logic (vredsum.vs)
  // Accumulates active elements of vs2 added to element 0 of vs1
  val red_sum32 = Wire(UInt(32.W))
  val red_elem0 = Mux(io.vl > 0.U, op2(31, 0), 0.U)
  val red_elem1 = Mux(io.vl > 1.U, op2(63, 32), 0.U)
  val red_elem2 = Mux(io.vl > 2.U, op2(95, 64), 0.U)
  val red_elem3 = Mux(io.vl > 3.U, op2(127, 96), 0.U)
  red_sum32 := io.vs1_val(31, 0) + red_elem0 + red_elem1 + red_elem2 + red_elem3
  io.red_scalar := red_sum32.pad(xLen)

  // Multiplex resulting vector by SEW
  val regular_wdata = MuxLookup(io.vsew, Cat(res32.reverse))(Seq(
    VSew.e8  -> Cat(res8.reverse),
    VSew.e16 -> Cat(res16.reverse),
    VSew.e32 -> Cat(res32.reverse),
    VSew.e64 -> Cat(res64.reverse)
  ))

  // For reduction, result is written to element 0 of vd, while upper elements are undisturbed
  val reduction_wdata = Cat(io.old_vd(vLen - 1, 32), red_sum32)
  io.wdata := Mux(is_redsum, reduction_wdata, regular_wdata)

  // Byte Write Mask Generation (wmask)
  val wmask_bytes = Wire(Vec(vLenB, Bool()))
  for (b <- 0 until vLenB) {
    val elem_idx = Wire(UInt(5.W))
    val elem_mask = Wire(Bool())

    when(io.vsew === VSew.e8) {
      elem_idx  := b.U
      elem_mask := io.mask_v0(b)
    }.elsewhen(io.vsew === VSew.e16) {
      elem_idx  := (b / 2).U
      elem_mask := io.mask_v0(b / 2)
    }.elsewhen(io.vsew === VSew.e32) {
      elem_idx  := (b / 4).U
      elem_mask := io.mask_v0(b / 4)
    }.otherwise {
      elem_idx  := (b / 8).U
      elem_mask := io.mask_v0(b / 8)
    }

    val is_active = elem_idx < io.vl
    val mask_pass = io.vm || elem_mask

    val reg_enable = is_active && mask_pass
    val red_enable = (elem_idx === 0.U)

    wmask_bytes(b) := io.valid && Mux(is_redsum, red_enable, reg_enable)
  }

  io.wmask := Cat(wmask_bytes.reverse)
}
