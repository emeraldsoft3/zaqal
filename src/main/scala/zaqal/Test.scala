package zaqal

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import java.io.File

object ZaqalTest extends App {
  // Create the directory if it doesn't exist
  val vcdPath = "programs/vcd"
  new File(vcdPath).mkdirs()

  RawTester.test(new Core(), Seq(
    WriteVcdAnnotation,
    // This forces the output to your specific folder
    // Note: ChiselTest usually generates 'Core.vcd' inside this dir
    TargetDirAnnotation(vcdPath) 
  )) { dut =>
    println("--- Starting ZAQAL Agile V1.0 Simulation ---")
    dut.clock.setTimeout(0)
    
    // Reset Sequence
    dut.reset.poke(true.B)
    dut.clock.step(5)
    dut.reset.poke(false.B)

    // Run for 40 cycles
    for (cycle <- 0 until 40) {
      dut.clock.step(1)
    }
    println(s"--- Simulation Finished. Waveform saved to $vcdPath ---")
  }
}