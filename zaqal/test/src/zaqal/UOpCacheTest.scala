package zaqal

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import zaqal.frontend.UOpCache
import zaqal.common._

class UOpCacheTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "UOpCache"

  it should "miss on first access and hit on second access (loop behavior)" in {
    implicit val p = (new ZaqalConfig)
    test(new UOpCache()) { dut =>
      dut.clock.setTimeout(0)

      // Initial state read request
      dut.io.read.req.valid.poke(true.B)
      dut.io.read.req.bits.pc.poke("h80000000".U)
      
      dut.clock.step(1)
      
      // Should miss initially
      dut.io.read.resp.hit.expect(false.B)
      
      // Simulate backend writing decoded uOps into the cache
      dut.io.write.req.valid.poke(true.B)
      dut.io.write.req.bits.pc.poke("h80000000".U)
      // Poke a dummy value into the first uOp's raw instruction just to track it
      dut.io.write.req.bits.uops(0).inst_raw.poke("hdeadbeef".U) 
      dut.clock.step(1)
      
      dut.io.write.req.valid.poke(false.B)
      
      // Second iteration of the loop (same PC)
      dut.io.read.req.bits.pc.poke("h80000000".U)
      dut.clock.step(1)
      
      // Should hit now
      dut.io.read.resp.hit.expect(true.B)
      dut.io.read.resp.uops(0).inst_raw.expect("hdeadbeef".U)
    }
  }
}
