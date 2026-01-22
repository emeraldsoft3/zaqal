package zaqal

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

object Test extends App {
  RawTester.test(new Core(), Seq(WriteVcdAnnotation)) { dut =>
    dut.clock.setTimeout(0)
    dut.reset.poke(true.B)
    dut.clock.step(5) // Hold reset for a few cycles
    dut.reset.poke(false.B)

    for (i <- 0 until 10) {
      dut.clock.step(1)
      // You don't need to peek anything manually; 
      // the printf in ZaqalCore will show the hex data!
    }
}
}