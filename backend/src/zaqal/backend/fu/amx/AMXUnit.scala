package zaqal.backend.fu.amx

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object AMXOp {
  val TZERO     = 0.U(3.W) // Clear Tile
  val TCFG      = 1.U(3.W) // Configure Tile Dimensions (Rows & Cols)
  val TLD       = 2.U(3.W) // 2D Strided Matrix Load
  val TST       = 3.U(3.W) // 2D Strided Matrix Store
  val TMMA_I8   = 4.U(3.W) // INT8 Matrix Multiply-Accumulate (C += A * B)
  val TMMA_BF16 = 5.U(3.W) // BF16 Matrix Multiply-Accumulate (C += A * B)
  val TMMA_FP32 = 6.U(3.W) // FP32 Matrix Multiply-Accumulate (C += A * B)
}

/**
 * AMX Matrix Functional Unit (Phase 9, Day 6-12)
 * 
 * Manages 2D Tile Architectural Registers (T0-T7), high-bandwidth
 * 2D strided sub-matrix memory streaming (TLD/TST), and accelerates
 * multi-precision 2D GEMM via dedicated hardware MMA Engine.
 */
class AMXUnit(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Command Interface from Execution Pipeline
    val cmd_valid = Input(Bool())
    val cmd_op    = Input(UInt(3.W))    // AMXOp
    val tdest     = Input(UInt(3.W))    // Tile index 0-7 (Destination / C)
    val tsrc1     = Input(UInt(3.W))    // Tile index 0-7 (Source A)
    val tsrc2     = Input(UInt(3.W))    // Tile index 0-7 (Source B)
    val rs1_val   = Input(UInt(xLen.W)) // Base address (or Config in TCFG)
    val rs2_val   = Input(UInt(xLen.W)) // Row Stride in bytes
    val cmd_ready = Output(Bool())
    val busy      = Output(Bool())
    val done      = Output(Bool())

    // 128-bit Memory Streaming Interface (to DataMem / L1 Cache)
    val mem_raddr = Output(UInt(xLen.W))
    val mem_rdata = Input(UInt(128.W))
    val mem_wen   = Output(Bool())
    val mem_waddr = Output(UInt(xLen.W))
    val mem_wdata = Output(UInt(128.W))
    val mem_wmask = Output(UInt(16.W))

    // Waveform / GTKWave Telemetry
    val state            = Output(UInt(3.W))
    val active_rows      = Output(UInt(5.W))
    val active_cols      = Output(UInt(5.W))
    val current_row      = Output(UInt(4.W))
    val debug_tile0_row0 = Output(UInt(128.W))
    val debug_tile0_row1 = Output(UInt(128.W))
    val debug_tile1_row0 = Output(UInt(128.W))
    val debug_tile1_row1 = Output(UInt(128.W))
    val debug_tile2_row0 = Output(UInt(128.W))
    val debug_tile3_row0 = Output(UInt(128.W))
  })

  val trf = Module(new TileRegFile)
  val mma = Module(new MMAEngine)

  // Configuration Registers (default 16 rows x 16 cols)
  val r_rows = RegInit(16.U(5.W))
  val r_cols = RegInit(16.U(5.W))

  // State Tracking
  val s_idle :: s_load_req :: s_load_latch :: s_store_req :: s_mma_compute :: s_done :: Nil = Enum(6)
  val state = RegInit(s_idle)

  val r_tile   = RegInit(0.U(3.W))
  val r_tile_a = RegInit(0.U(3.W))
  val r_tile_b = RegInit(0.U(3.W))
  val r_base   = RegInit(0.U(xLen.W))
  val r_stride = RegInit(0.U(xLen.W))
  val r_row    = RegInit(0.U(4.W))

  // Connect TileRegFile 2D read ports to MMAEngine
  trf.io.mma_tile_a := r_tile_a
  trf.io.mma_tile_b := r_tile_b
  trf.io.mma_tile_c := r_tile
  mma.io.matrix_a   := trf.io.mma_matrix_a
  mma.io.matrix_b   := trf.io.mma_matrix_b
  mma.io.matrix_c   := trf.io.mma_matrix_c
  mma.io.active_rows:= r_rows

  // Default MMA inputs
  mma.io.start := false.B
  mma.io.prec  := MMAPrecision.INT8

  // Default TRF inputs (Muxed between Load stream, Zeroing, and MMA writeback)
  trf.io.wen        := mma.io.write_en
  trf.io.wtile      := Mux(mma.io.write_en, r_tile, r_tile)
  trf.io.wrow       := Mux(mma.io.write_en, mma.io.write_row, r_row)
  trf.io.wdata      := Mux(mma.io.write_en, mma.io.write_data, io.mem_rdata)
  trf.io.rtile      := r_tile
  trf.io.rrow       := r_row
  trf.io.zero_en    := false.B
  trf.io.zero_tile  := io.tdest

  // Default Memory outputs
  io.mem_raddr := r_base + (r_row * r_stride)
  io.mem_wen   := false.B
  io.mem_waddr := r_base + (r_row * r_stride)
  io.mem_wdata := trf.io.rdata
  io.mem_wmask := "hFFFF".U(16.W) // 16 bytes strobe

  io.cmd_ready := (state === s_idle) || (state === s_done)
  io.busy      := (state =/= s_idle) && (state =/= s_done)
  io.done      := (state === s_done)

  def startMMA(prec: UInt): Unit = {
    r_tile    := io.tdest
    r_tile_a  := io.tsrc1
    r_tile_b  := io.tsrc2
    mma.io.start := true.B
    mma.io.prec  := prec
    state := s_mma_compute
  }

  switch(state) {
    is(s_idle) {
      when(io.cmd_valid) {
        switch(io.cmd_op) {
          is(AMXOp.TCFG) {
            val new_rows = Mux(io.rs1_val(15, 8) === 0.U, 16.U, Mux(io.rs1_val(15, 8) > 16.U, 16.U, io.rs1_val(15, 8)))
            val new_cols = Mux(io.rs1_val(7, 0) === 0.U, 16.U, Mux(io.rs1_val(7, 0) > 16.U, 16.U, io.rs1_val(7, 0)))
            r_rows := new_rows
            r_cols := new_cols
            state  := s_done
          }
          is(AMXOp.TZERO) {
            trf.io.zero_en   := true.B
            trf.io.zero_tile := io.tdest
            state  := s_done
          }
          is(AMXOp.TLD) {
            r_tile   := io.tdest
            r_base   := io.rs1_val
            r_stride := Mux(io.rs2_val === 0.U, 16.U, io.rs2_val)
            r_row    := 0.U
            state    := s_load_req
          }
          is(AMXOp.TST) {
            r_tile   := io.tdest
            r_base   := io.rs1_val
            r_stride := Mux(io.rs2_val === 0.U, 16.U, io.rs2_val)
            r_row    := 0.U
            state    := s_store_req
          }
          is(AMXOp.TMMA_I8)   { startMMA(MMAPrecision.INT8) }
          is(AMXOp.TMMA_BF16) { startMMA(MMAPrecision.BF16) }
          is(AMXOp.TMMA_FP32) { startMMA(MMAPrecision.FP32) }
        }
      }
    }

    is(s_load_req) {
      state := s_load_latch
    }

    is(s_load_latch) {
      trf.io.wen   := true.B
      trf.io.wtile := r_tile
      trf.io.wrow  := r_row
      trf.io.wdata := io.mem_rdata

      when(r_row === (r_rows - 1.U)) {
        state := s_done
      }.otherwise {
        r_row := r_row + 1.U
        state := s_load_req
      }
    }

    is(s_store_req) {
      trf.io.rtile := r_tile
      trf.io.rrow  := r_row
      io.mem_wen   := true.B
      io.mem_waddr := r_base + (r_row * r_stride)
      io.mem_wdata := trf.io.rdata
      io.mem_wmask := "hFFFF".U(16.W)

      when(r_row === (r_rows - 1.U)) {
        state := s_done
      }.otherwise {
        r_row := r_row + 1.U
        state := s_store_req
      }
    }

    is(s_mma_compute) {
      when(mma.io.done) {
        state := s_done
      }
    }

    is(s_done) {
      when(io.cmd_valid) {
        switch(io.cmd_op) {
          is(AMXOp.TCFG) {
            val new_rows = Mux(io.rs1_val(15, 8) === 0.U, 16.U, Mux(io.rs1_val(15, 8) > 16.U, 16.U, io.rs1_val(15, 8)))
            val new_cols = Mux(io.rs1_val(7, 0) === 0.U, 16.U, Mux(io.rs1_val(7, 0) > 16.U, 16.U, io.rs1_val(7, 0)))
            r_rows := new_rows
            r_cols := new_cols
            state  := s_idle
          }
          is(AMXOp.TZERO) {
            trf.io.zero_en   := true.B
            trf.io.zero_tile := io.tdest
            state  := s_idle
          }
          is(AMXOp.TLD) {
            r_tile   := io.tdest
            r_base   := io.rs1_val
            r_stride := Mux(io.rs2_val === 0.U, 16.U, io.rs2_val)
            r_row    := 0.U
            state    := s_load_req
          }
          is(AMXOp.TST) {
            r_tile   := io.tdest
            r_base   := io.rs1_val
            r_stride := Mux(io.rs2_val === 0.U, 16.U, io.rs2_val)
            r_row    := 0.U
            state    := s_store_req
          }
          is(AMXOp.TMMA_I8)   { startMMA(MMAPrecision.INT8) }
          is(AMXOp.TMMA_BF16) { startMMA(MMAPrecision.BF16) }
          is(AMXOp.TMMA_FP32) { startMMA(MMAPrecision.FP32) }
        }
      }.otherwise {
        state := s_idle
      }
    }
  }

  // Telemetry outputs
  io.state            := state.asUInt
  io.active_rows      := r_rows
  io.active_cols      := r_cols
  io.current_row      := r_row
  io.debug_tile0_row0 := trf.io.debug_tile0_row0
  io.debug_tile0_row1 := trf.io.debug_tile0_row1
  io.debug_tile1_row0 := trf.io.debug_tile1_row0
  io.debug_tile1_row1 := trf.io.debug_tile1_row1
  io.debug_tile2_row0 := trf.io.debug_tile2_row0
  io.debug_tile3_row0 := trf.io.debug_tile3_row0

  // Preserve telemetry signals in Verilator / GTKWave
  dontTouch(io.state)
  dontTouch(io.active_rows)
  dontTouch(io.active_cols)
  dontTouch(io.current_row)
  dontTouch(io.debug_tile0_row0)
  dontTouch(io.mem_raddr)
  dontTouch(io.mem_waddr)
  dontTouch(io.mem_wdata)
  dontTouch(io.mem_wen)
  dontTouch(r_row)
  dontTouch(r_rows)
  dontTouch(state)
}
