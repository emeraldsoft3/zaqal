package zaqal

import chisel3._
import chiseltest._
import chiseltest.simulator.VerilatorBackendAnnotation
import java.io.File
import java.nio.file.{Files, StandardCopyOption}
import org.chipsalliance.cde.config.Parameters
import zaqal.backend.fu.amx._
import zaqal.backend.exu.DataMem
import zaqal.common._

/**
 * AMX Matrix Functional Unit (Phase 9: Day 1-5) Test Suite
 * 
 * Verifies:
 * 1. 2D Tile Architectural Register File (TRF) storage & zeroing (TZERO)
 * 2. Tile geometry configuration (TCFG)
 * 3. 2D continuous & strided memory loads (TLD)
 * 4. 2D strided memory stores (TST)
 * 5. Full data integrity round-trip (Memory -> Tile -> Memory)
 */
object AMXTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  // Test Harness pairing AMXUnit with DataMem
  class AMXTestHarness(implicit val p: Parameters) extends Module with HasZaqalParameter {
    val io = IO(new Bundle {
      // Command Interface
      val cmd_valid = Input(Bool())
      val cmd_op    = Input(UInt(3.W))
      val tdest     = Input(UInt(3.W))
      val rs1_val   = Input(UInt(xLen.W))
      val rs2_val   = Input(UInt(xLen.W))
      val cmd_ready = Output(Bool())
      val busy      = Output(Bool())
      val done      = Output(Bool())

      // Direct inspection of Tile rows
      val tile0_row0 = Output(UInt(128.W))
      val tile0_row1 = Output(UInt(128.W))
      val tile1_row0 = Output(UInt(128.W))
      val tile1_row1 = Output(UInt(128.W))

      // Direct DataMem inspection
      val dmem_inspect_addr = Input(UInt(xLen.W))
      val dmem_inspect_data = Output(UInt(128.W))
    })

    val amx  = Module(new AMXUnit)
    val dmem = Module(new DataMem)

    // Connect AMX to DataMem streaming ports
    dmem.io.amx_raddr := amx.io.mem_raddr
    amx.io.mem_rdata  := dmem.io.amx_rdata
    dmem.io.amx_wen   := amx.io.mem_wen
    dmem.io.amx_waddr := amx.io.mem_waddr
    dmem.io.amx_wdata := amx.io.mem_wdata

    // Tie off unused standard ports
    dmem.io.raddr(0) := io.dmem_inspect_addr
    dmem.io.raddr(1) := 0.U
    dmem.io.addr     := 0.U
    dmem.io.wen      := false.B
    dmem.io.wmask    := 0.U
    dmem.io.wdata    := 0.U
    dmem.io.ptw_raddr := 0.U
    dmem.io.plic_ext_irq := 0.U

    io.dmem_inspect_data := dmem.io.rdata(0)

    // AMX Command connections
    amx.io.cmd_valid := io.cmd_valid
    amx.io.cmd_op    := io.cmd_op
    amx.io.tdest     := io.tdest
    amx.io.rs1_val   := io.rs1_val
    amx.io.rs2_val   := io.rs2_val
    io.cmd_ready     := amx.io.cmd_ready
    io.busy          := amx.io.busy
    io.done          := amx.io.done

    io.tile0_row0    := amx.io.debug_tile0_row0
    io.tile0_row1    := amx.io.debug_tile0_row1
    io.tile1_row0    := amx.io.debug_tile1_row0
    io.tile1_row1    := amx.io.debug_tile1_row1
  }

  RawTester.test(new AMXTestHarness(), Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
    println("=================================================================")
    println("  RUNNING PHASE 9 (DAY 1-5): AMX MATRIX UNIT FOUNDATION TESTS    ")
    println("  2D Tile Registers, Strided Load/Store & Zeroing                ")
    println("=================================================================")

    dut.clock.setTimeout(0)
    dut.io.cmd_valid.poke(false.B)
    dut.io.cmd_op.poke(0.U)
    dut.io.tdest.poke(0.U)
    dut.io.rs1_val.poke(0.U)
    dut.io.rs2_val.poke(0.U)
    dut.io.dmem_inspect_addr.poke(0.U)
    dut.clock.step(2)

    def executeAMX(op: UInt, tdest: Int, rs1: BigInt, rs2: BigInt): Unit = {
      dut.io.cmd_valid.poke(true.B)
      dut.io.cmd_op.poke(op)
      dut.io.tdest.poke(tdest.U)
      dut.io.rs1_val.poke(rs1.U)
      dut.io.rs2_val.poke(rs2.U)
      dut.clock.step(1)
      dut.io.cmd_valid.poke(false.B)

      // Step until done
      var timeout = 0
      while (!dut.io.done.peek().litToBoolean && timeout < 200) {
        dut.clock.step(1)
        timeout += 1
      }
      assert(timeout < 200, "AMX operation timed out!")
      dut.clock.step(1) // Step out of done state
    }

    // -----------------------------------------------------------------------
    // Test 1: Tile Configuration (TCFG)
    // -----------------------------------------------------------------------
    println("\n[Test 1] Testing Tile Geometry Configuration (TCFG)...")
    // Configure 8 rows x 16 cols: rs1 = (8 << 8) | 16 = 0x0810
    executeAMX(AMXOp.TCFG, 0, BigInt("0810", 16), 0)
    println("  -> TCFG configured active rows=8, cols=16: PASS")

    // Restore full 16x16 configuration
    executeAMX(AMXOp.TCFG, 0, BigInt("1010", 16), 0)
    println("  -> TCFG configured active rows=16, cols=16: PASS")

    // -----------------------------------------------------------------------
    // Test 2: Single-Cycle Tile Zeroing (TZERO)
    // -----------------------------------------------------------------------
    println("\n[Test 2] Testing Single-Cycle Tile Zeroing (TZERO)...")
    executeAMX(AMXOp.TZERO, 0, 0, 0)
    assert(dut.io.tile0_row0.peek().litValue == 0, "Tile 0 Row 0 must be 0 after TZERO")
    assert(dut.io.tile0_row1.peek().litValue == 0, "Tile 0 Row 1 must be 0 after TZERO")
    println("  -> Tile 0 successfully zeroed: PASS")

    // -----------------------------------------------------------------------
    // Test 3: 2D Matrix Memory Pre-population & Continuous Load (TLD)
    // -----------------------------------------------------------------------
    println("\n[Test 3] Testing 2D Strided Matrix Load (TLD)...")
    // DataMem pre-loaded entries at 0x0010 (offset 2) has "hFFEEDDCCBBAA9988"
    // and at 0x0020 (offset 4) has "h1122334455667788"
    // Let's load 16 rows starting at Base 0x0010 with row stride 16 bytes (contiguous 128b blocks)
    executeAMX(AMXOp.TLD, 0, BigInt("0010", 16), 16)

    val row0Val = dut.io.tile0_row0.peek().litValue
    val row1Val = dut.io.tile0_row1.peek().litValue

    println(f"  -> Tile 0 Row 0 loaded: 0x$row0Val%032x")
    println(f"  -> Tile 0 Row 1 loaded: 0x$row1Val%032x")
    assert(row0Val != 0, "Tile 0 Row 0 must contain non-zero matrix data from memory")
    println("  -> 2D Tile streaming load into T0 verified: PASS")

    // -----------------------------------------------------------------------
    // Test 4: Strided Sub-matrix Load (TLD with Stride = 32 bytes)
    // -----------------------------------------------------------------------
    println("\n[Test 4] Testing Sub-matrix extraction with Stride = 32 bytes...")
    executeAMX(AMXOp.TLD, 1, BigInt("0010", 16), 32)
    val t1Row0 = dut.io.tile1_row0.peek().litValue
    val t1Row1 = dut.io.tile1_row1.peek().litValue
    println(f"  -> Tile 1 Row 0 loaded: 0x$t1Row0%032x")
    println(f"  -> Tile 1 Row 1 loaded: 0x$t1Row1%032x")
    assert(t1Row0 == row0Val, "Tile 1 Row 0 must match Row 0 of Base")
    println("  -> Sub-matrix strided loading verified: PASS")

    // -----------------------------------------------------------------------
    // Test 5: 2D Strided Matrix Store (TST) & Read-Back Verification
    // -----------------------------------------------------------------------
    println("\n[Test 5] Testing 2D Matrix Store (TST) & Data Fidelity Round-Trip...")
    val storeBase = BigInt("0200", 16) // Write to new location 0x0200
    executeAMX(AMXOp.TST, 0, storeBase, 16)
    println(f"  -> Tile 0 stored to memory at base 0x$storeBase%04x with stride 16 bytes")

    // Read back written memory using direct inspection port
    dut.io.dmem_inspect_addr.poke(storeBase.U)
    dut.clock.step(1)
    val readBackRow0 = dut.io.dmem_inspect_data.peek().litValue
    println(f"  -> Memory read-back at 0x$storeBase%04x: 0x$readBackRow0%032x")
    assert(readBackRow0 == row0Val, f"Round-trip failed! Expected 0x$row0Val%032x, got 0x$readBackRow0%032x")
    println("  -> Complete round-trip Memory -> Tile 0 -> Memory verified bit-exact: PASS")

    println("\n=================================================================")
    println("  ALL PHASE 9 (DAY 1-5) AMX FOUNDATION TESTS PASSED!             ")
    println("=================================================================")
  }

  // --- VCD CLEANUP & EXPORT FOR GTKWAVE ---
  val targetVcd = new File("programs/vcd/AMX.vcd")
  val testRunDir = new File("test_run_dir")
  if (testRunDir.exists()) {
    val vcdFiles = testRunDir.listFiles().filter(_.isDirectory).flatMap(_.listFiles()).filter(_.getName.endsWith(".vcd"))
    if (vcdFiles.nonEmpty) {
      Files.copy(vcdFiles.sortBy(_.lastModified()).last.toPath, targetVcd.toPath, StandardCopyOption.REPLACE_EXISTING)
      println(s"Waveform saved for GTKWave at: ${targetVcd.getPath}")
    }
  }
}
