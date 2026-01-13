package zaqal

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

object ZaqalTest extends App {
  RawTester.test(new ZaqalCore(), Seq(WriteVcdAnnotation)) { dut =>
    println("Zaqal 8-Core Engine Starting...")
    dut.clock.setTimeout(0) 

    // Reset the core
    dut.reset.poke(true.B)
    dut.clock.step(1)
    dut.reset.poke(false.B)

    // Run for 20 cycles and watch the logs
    for (i <- 0 until 20) {
      // The printf inside ZaqalCore will show up in your terminal here
      dut.clock.step(1)
    }
    println("Done! Check your build folder for the .vcd file.")
  }
}