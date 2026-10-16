package zaqal.backend.fu.vector

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * RVV 1.0 Vector Load/Store Unit (VectorLSU)
 *
 * Implements:
 * - Unit-Stride Vector Loads:  vle8.v,  vle16.v,  vle32.v,  vle64.v
 * - Unit-Stride Vector Stores: vse8.v,  vse16.v,  vse32.v,  vse64.v
 * - Strided Vector Loads:      vlse8.v, vlse16.v, vlse32.v, vlse64.v
 * - Strided Vector Stores:     vsse8.v, vsse16.v, vsse32.v, vsse64.v
 * - Connects to DataMem 128-bit streaming vector memory port
 * - Unit-stride completes immediately; strided operates with element gather/scatter
 */
class VectorLSU(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val valid       = Input(Bool())
    val is_load     = Input(Bool())
    val is_store    = Input(Bool())
    val is_strided  = Input(Bool())
    val elem_width  = Input(UInt(3.W)) // 0=8b, 1=16b, 2=32b, 3=64b
    val rs1_base    = Input(UInt(xLen.W))
    val rs2_stride  = Input(UInt(xLen.W))
    val vs3_data    = Input(UInt(vLen.W))
    val old_vd      = Input(UInt(vLen.W))
    val mask_v0     = Input(UInt(vLen.W))
    val vm          = Input(Bool())
    val vl          = Input(UInt(xLen.W))
    val vsew        = Input(UInt(3.W))

    // Interface to DataMem
    val mem_raddr   = Output(UInt(xLen.W))
    val mem_rdata   = Input(UInt(128.W))
    val mem_wen     = Output(Bool())
    val mem_waddr   = Output(UInt(xLen.W))
    val mem_wdata   = Output(UInt(128.W))
    val mem_wmask   = Output(UInt(16.W))

    // Outputs to VectorRegFile
    val done        = Output(Bool())
    val vd_wdata    = Output(UInt(vLen.W))
    val vd_wmask    = Output(UInt(vLenB.W))
  })

  // State Machine for Strided Gather/Scatter
  val s_idle :: s_strided_access :: s_done :: Nil = Enum(3)
  val state = RegInit(s_idle)
  val stride_idx = RegInit(0.U(log2Up(17).W))
  val gathered_reg = RegInit(0.U(vLen.W))

  // Active byte mask computation for unit-stride
  val active_wmask = Wire(Vec(vLenB, Bool()))
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
    active_wmask(b) := io.valid && is_active && mask_pass
  }
  val unit_stride_mask = Cat(active_wmask.reverse)

  // Current strided address: rs1_base + stride_idx * rs2_stride
  val current_stride_addr = io.rs1_base + (stride_idx * io.rs2_stride)

  // Strided state machine
  when(state === s_idle) {
    when(io.valid && io.is_strided && io.vl > 0.U) {
      state := s_strided_access
      stride_idx := 0.U
      gathered_reg := io.old_vd
    }
  }.elsewhen(state === s_strided_access) {
    when(io.is_load) {
      val byte_off = current_stride_addr(3, 0)
      val rdata_shifted = (io.mem_rdata >> (byte_off << 3))

      when(io.vsew === VSew.e8) {
        val mask_8 = Cat(Seq.tabulate(16)(i => Fill(8, (i.U === stride_idx).asUInt)))
        gathered_reg := (gathered_reg & ~mask_8) | (Cat(Seq.fill(16)(rdata_shifted(7, 0))) & mask_8)
      }.elsewhen(io.vsew === VSew.e16) {
        val mask_16 = Cat(Seq.tabulate(8)(i => Fill(16, (i.U === stride_idx).asUInt)))
        gathered_reg := (gathered_reg & ~mask_16) | (Cat(Seq.fill(8)(rdata_shifted(15, 0))) & mask_16)
      }.elsewhen(io.vsew === VSew.e32) {
        val mask_32 = Cat(Seq.tabulate(4)(i => Fill(32, (i.U === stride_idx).asUInt)))
        gathered_reg := (gathered_reg & ~mask_32) | (Cat(Seq.fill(4)(rdata_shifted(31, 0))) & mask_32)
      }.otherwise {
        val mask_64 = Cat(Seq.tabulate(2)(i => Fill(64, (i.U === stride_idx).asUInt)))
        gathered_reg := (gathered_reg & ~mask_64) | (Cat(Seq.fill(2)(rdata_shifted(63, 0))) & mask_64)
      }
    }

    when(stride_idx >= io.vl - 1.U) {
      state := s_done
    }.otherwise {
      stride_idx := stride_idx + 1.U
    }
  }.elsewhen(state === s_done) {
    state := s_idle
  }

  // Memory Interface Multiplexing
  val is_strided_active = (state === s_strided_access)
  io.mem_raddr := Mux(is_strided_active, current_stride_addr, io.rs1_base)
  io.mem_waddr := Mux(is_strided_active, current_stride_addr, io.rs1_base)

  // Strided store element extraction & alignment
  val store_elem_32 = MuxLookup(stride_idx, 0.U(32.W))(Seq(
    0.U -> io.vs3_data(31, 0),
    1.U -> io.vs3_data(63, 32),
    2.U -> io.vs3_data(95, 64),
    3.U -> io.vs3_data(127, 96)
  ))
  val strided_wdata = (store_elem_32.pad(128)) << (current_stride_addr(3, 0) << 3)
  val strided_wmask = ("hF".U(16.W)) << current_stride_addr(3, 0)

  io.mem_wdata := Mux(is_strided_active, strided_wdata, io.vs3_data)
  io.mem_wmask := Mux(is_strided_active, strided_wmask(15, 0), unit_stride_mask)
  io.mem_wen   := Mux(is_strided_active, io.is_store, io.valid && io.is_store && !io.is_strided)

  // Outputs to VRF
  io.done     := Mux(io.is_strided, (state === s_done), io.valid)
  io.vd_wdata := Mux(io.is_strided, gathered_reg, io.mem_rdata)
  io.vd_wmask := unit_stride_mask
}
