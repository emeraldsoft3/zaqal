package zaqal.utility

import chisel3._
import chisel3.util._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import java.io.File
import java.nio.file.{Files, StandardCopyOption}

object UtilityTest extends App {
  implicit val p: Parameters = new ZaqalConfig
  val vcdDir = "programs/vcd"
  new File(vcdDir).mkdirs()

  RawTester.test(new SkidBuffer(UInt(64.W)), Seq(WriteVcdAnnotation)) { dut =>
    println("--- Testing SkidBuffer with Waveform Generation ---")
    dut.io.enq.initSource().setSourceClock(dut.clock)
    dut.io.deq.initSink().setSinkClock(dut.clock)

    // Test 1: Linear flow
    println("Test 1: Linear flow")
    dut.io.deq.ready.poke(true.B)
    dut.io.enq.valid.poke(true.B)
    dut.io.enq.bits.poke(0x123.U)
    dut.clock.step(1)
    dut.io.deq.valid.expect(true.B)
    dut.io.deq.bits.expect(0x123.U)
    dut.io.enq.ready.expect(true.B)

    // Test 2: Back-pressure + Skid
    println("Test 2: Back-pressure + Skid")
    dut.io.deq.ready.poke(false.B)
    dut.io.enq.bits.poke(0xABC.U)
    dut.clock.step(1)
    dut.io.enq.ready.expect(false.B)
    dut.io.deq.valid.expect(true.B)
    dut.io.deq.bits.expect(0x123.U)

    // Test 3: Clear back-pressure
    println("Test 3: Clear back-pressure")
    dut.io.deq.ready.poke(true.B)
    dut.clock.step(1)
    dut.io.deq.valid.expect(true.B)
    dut.io.deq.bits.expect(0xABC.U)
    dut.io.enq.ready.expect(true.B)

    // Test 4: Flush
    println("Test 4: Flush")
    dut.io.enq.bits.poke(0xDEF.U)
    dut.clock.step(1)
    dut.io.flush.poke(true.B)
    dut.clock.step(1)
    dut.io.flush.poke(false.B)
    dut.io.deq.valid.expect(false.B)
    
    println("--- SkidBuffer Tests Passed! ---")
  }

  // --- VCD CLEANUP LOGIC ---
  val targetVcd = new File("programs/vcd/SkidBuffer.vcd")
  val testRunDir = new File("test_run_dir")
  if (testRunDir.exists()) {
    val vcdFiles = testRunDir.listFiles().filter(_.isDirectory).flatMap(_.listFiles()).filter(_.getName.endsWith(".vcd"))
    if (vcdFiles.nonEmpty) {
      Files.copy(vcdFiles.sortBy(_.lastModified()).last.toPath, targetVcd.toPath, StandardCopyOption.REPLACE_EXISTING)
      println(s"Waveform copied to: ${targetVcd.getAbsolutePath}")
    }
  }
}
