package zaqal

import zaqal.common._
import chisel3._
import chiseltest._
import java.io.{File, PrintWriter}
import java.nio.file.{Files, StandardCopyOption}

object CoreMarkFPTest extends App {
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  // Configure for CoreMark-FP
  implicit val p = (new ZaqalConfig).alter((site, here, up) => {
    case ZaqalParamsKey => up(ZaqalParamsKey).copy(
      programFile = "programs/hex/coremark_fp.hex"
    )
  })
  val params = p(ZaqalParamsKey)

  RawTester.test(new Core(), Seq()) { dut =>
    println("--- Starting ZAQAL Phase 3 Benchmarking (CoreMark-FP) ---")
    dut.clock.setTimeout(0) // Disable timeout for long runs
    
    var instructionsRetired = 0
    val maxCycles = 5000 
    val resetCycles = 10

    for (cycle <- 0 until maxCycles) {
      dut.reset.poke((cycle < resetCycles).B)
      
      // Track retired instructions for IPC calculation
      // We assume an instruction is retired when it fires into the backend
      // and doesn't cause a redirect (simplified)
      val fire = dut.debug.get.ftq_valid_out.peek().litToBoolean && dut.debug.get.ftq_ready_out.peek().litToBoolean
      if (fire && cycle >= resetCycles) {
          instructionsRetired += 1
      }

      dut.clock.step(1)
      
      if (cycle % 1000 == 0 && cycle > 0) {
          println(s"[Cycle $cycle] Instructions Retired: $instructionsRetired | Current IPC: ${instructionsRetired.toDouble / (cycle - resetCycles)}")
      }
    }

    println("--- Benchmarking Finished ---")
    val totalCycles = maxCycles - resetCycles
    val ipc = instructionsRetired.toDouble / totalCycles
    println(s"Total Cycles: $totalCycles")
    println(s"Total Instructions Retired: $instructionsRetired")
    println(f"Final CoreMark-FP IPC: $ipc%.4f")
    
    println("--- Final Register State ---")
    for (i <- 0 until 32) {
      val regVal = dut.debug.get.regs(i).peek().litValue
      println(f"x$i%02d: 0x$regVal%016x")
    }

    println("--- Final FP Register State ---")
    for (i <- 0 until 32) {
      val regVal = dut.debug.get.fp_regs(i).peek().litValue
      println(f"f$i%02d: 0x$regVal%016x")
    }
  }

  // VCD Cleanup
  val targetVcd = new File("programs/vcd/CoreMarkFP.vcd")
  val testRunDir = new File("test_run_dir")
  if (testRunDir.exists()) {
    val vcdFiles = testRunDir.listFiles().filter(_.isDirectory).flatMap(_.listFiles()).filter(_.getName.endsWith(".vcd"))
    if (vcdFiles.nonEmpty) {
      Files.copy(vcdFiles.sortBy(_.lastModified()).last.toPath, targetVcd.toPath, StandardCopyOption.REPLACE_EXISTING)
      println(s"Waveform copied to: ${targetVcd.getAbsolutePath}")
    }
  }
}
