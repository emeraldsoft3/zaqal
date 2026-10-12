package zaqal.backend.fu.amx

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object AMXOp {
  val TZERO = 0.U(3.W) // Clear Tile
  val TCFG  = 1.U(3.W) // Configure Tile Dimensions (Rows & Cols)
  val TLD   = 2.U(3.W) // 2D Strided Matrix Load
  val TST   = 3.U(3.W) // 2D Strided Matrix Store
}

/**
 * AMX Matrix Functional Unit (Foundation)
 * 
 * Manages 2D Tile Architectural Registers and executes high-bandwidth
 * 2D strided sub-matrix streaming loads and stores directly between memory
 * and Tile registers (T0-T7).
 */
class AMXUnit(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Command Interface from Execution Pipeline
    val cmd_valid = Input(Bool())
    val cmd_op    = Input(UInt(3.W))    // AMXOp
    val tdest     = Input(UInt(3.W))    // Tile index 0-7
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

  // Configuration Registers (default 16 rows x 16 cols)
  val r_rows = RegInit(16.U(5.W))
  val r_cols = RegInit(16.U(5.W))

  // Streaming State Tracking
  val s_idle :: s_load_req :: s_load_latch :: s_store_req :: s_done :: Nil = Enum(5)
  val state = RegInit(s_idle)

  val r_tile   = RegInit(0.U(3.W))
  val r_base   = RegInit(0.U(xLen.W))
  val r_stride = RegInit(0.U(xLen.W))
  val r_row    = RegInit(0.U(4.W))

  // Default TRF inputs
  trf.io.wen        := false.B
  trf.io.wtile      := r_tile
  trf.io.wrow       := r_row
  trf.io.wdata      := io.mem_rdata
  trf.io.rtile      := r_tile
  trf.io.rrow       := r_row
  trf.io.zero_en    := false.B
  trf.io.zero_tile  := io.tdest
  trf.io.mma_tile_a := 0.U
  trf.io.mma_tile_b := 0.U

  // Default Memory outputs
  io.mem_raddr := r_base + (r_row * r_stride)
  io.mem_wen   := false.B
  io.mem_waddr := r_base + (r_row * r_stride)
  io.mem_wdata := trf.io.rdata
  io.mem_wmask := "hFFFF".U(16.W) // 16 bytes strobe

  io.cmd_ready := (state === s_idle) || (state === s_done)
  io.busy      := (state =/= s_idle) && (state =/= s_done)
  io.done      := (state === s_done)

  switch(state) {
    is(s_idle) {
      when(io.cmd_valid) {
        switch(io.cmd_op) {
          is(AMXOp.TCFG) {
            // rs1_val[15:8] = rows (1-16), rs1_val[7:0] = cols (1-16)
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
            r_stride := Mux(io.rs2_val === 0.U, 16.U, io.rs2_val) // Default stride is 16 bytes
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
        }
      }
    }

    is(s_load_req) {
      // Present memory address, data available in next cycle
      state := s_load_latch
    }

    is(s_load_latch) {
      // Latch memory read data into current tile row
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
      // Present memory write address and tile row read data
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
