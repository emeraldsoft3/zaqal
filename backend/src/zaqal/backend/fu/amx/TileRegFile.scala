package zaqal.backend.fu.amx

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
 * 2D Tile Architectural Register File (TRF) for Matrix Functional Unit (AMX)
 * 
 * Hardware Architecture:
 * - 8 Tile architectural registers: T0 to T7
 * - Each Tile is a 2D matrix of 16 rows x 16 columns of 8-bit elements (128 bits per row)
 * - Capacity per tile: 16 rows * 16 bytes = 256 bytes (2048 bits)
 * - Total TRF capacity: 8 * 256 bytes = 2048 bytes (2 KB)
 * 
 * Capabilities:
 * 1. High-throughput row-wise writes for 2D strided memory loads (TLD).
 * 2. High-throughput row-wise reads for 2D strided memory stores (TST).
 * 3. 1-cycle whole-tile zeroing (TZERO) for initializing accumulators.
 * 4. Dual 2D matrix read ports (16x128b) to feed systolic/parallel GEMM (Day 6-12).
 */
class TileRegFile(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Row-level Write Port (used by TileLoad or Matrix writeback)
    val wen        = Input(Bool())
    val wtile      = Input(UInt(3.W))   // T0 - T7 (8 tiles)
    val wrow       = Input(UInt(4.W))   // Row index 0 - 15
    val wdata      = Input(UInt(128.W)) // 16 bytes (128 bits)

    // Row-level Read Port (used by TileStore)
    val rtile      = Input(UInt(3.W))
    val rrow       = Input(UInt(4.W))
    val rdata      = Output(UInt(128.W))

    // Direct Single-Cycle Tile Zeroing (TZERO)
    val zero_en    = Input(Bool())
    val zero_tile  = Input(UInt(3.W))

    // 2D Matrix Read Ports for MMA Core (Day 6-12)
    val mma_tile_a   = Input(UInt(3.W))
    val mma_tile_b   = Input(UInt(3.W))
    val mma_tile_c   = Input(UInt(3.W))
    val mma_matrix_a = Output(Vec(16, UInt(128.W)))
    val mma_matrix_b = Output(Vec(16, UInt(128.W)))
    val mma_matrix_c = Output(Vec(16, UInt(128.W)))

    // Debug Ports for Simulation & GTKWave Waveform Observation
    val debug_tile0_row0 = Output(UInt(128.W))
    val debug_tile0_row1 = Output(UInt(128.W))
    val debug_tile1_row0 = Output(UInt(128.W))
    val debug_tile1_row1 = Output(UInt(128.W))
    val debug_tile2_row0 = Output(UInt(128.W))
    val debug_tile3_row0 = Output(UInt(128.W))
  })

  // 8 Tiles, each having 16 rows of 128-bit registers (total 2KB)
  val tiles = RegInit(VecInit(Seq.fill(amxNumTiles)(VecInit(Seq.fill(amxTileRows)(0.U(128.W))))))

  // 1. Row Read Port
  io.rdata := tiles(io.rtile)(io.rrow)

  // 2. Row Write Port & Tile Zeroing Port
  when(io.zero_en) {
    for (r <- 0 until amxTileRows) {
      tiles(io.zero_tile)(r) := 0.U
    }
  }.elsewhen(io.wen) {
    tiles(io.wtile)(io.wrow) := io.wdata
  }

  // 3. 2D Matrix Outputs for MMA (A, B, and initial Accumulator C)
  for (r <- 0 until 16) {
    io.mma_matrix_a(r) := tiles(io.mma_tile_a)(r)
    io.mma_matrix_b(r) := tiles(io.mma_tile_b)(r)
    io.mma_matrix_c(r) := tiles(io.mma_tile_c)(r)
  }

  // 4. Debug Inspection Wires (for GTKWave)
  io.debug_tile0_row0 := tiles(0)(0)
  io.debug_tile0_row1 := tiles(0)(1)
  io.debug_tile1_row0 := tiles(1)(0)
  io.debug_tile1_row1 := tiles(1)(1)
  io.debug_tile2_row0 := tiles(2)(0)
  io.debug_tile3_row0 := tiles(3)(0)
}
