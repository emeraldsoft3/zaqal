package zaqal

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import zaqal.common._

class ZaqalTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Zaqal Core"
  it should "elaborate and run a basic execution" in {
    implicit val p = ZaqalParams()
    test(new Core).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      dut.clock.step(20)
    }
  }
}