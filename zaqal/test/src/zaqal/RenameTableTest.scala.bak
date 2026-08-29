package zaqal

import zaqal.common._
import zaqal.backend._
import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import org.scalatest.flatspec.AnyFlatSpec

class RenameTableTest extends AnyFlatSpec with ChiselScalatestTester {
  implicit val p: Parameters = new ZaqalConfig

  "RenameTable" should "handle intra-bundle dependencies correctly" in {
    test(new RenameTable(32, false)) { dut =>
      dut.io.redirect.poke(false.B)
      
      // Initialize commit ports to 0
      for (i <- 0 until 6) {
        dut.io.commitPorts(i).wen.poke(false.B)
        dut.io.commitPorts(i).addr.poke(0.U)
        dut.io.commitPorts(i).data.poke(0.U)
      }

      // Cycle 0: Bundle with dependency
      // Inst 0: x1 = x2 + x3  (lrd=1, lrs1=2, lrs2=3)
      // Inst 1: x4 = x1 + x5  (lrd=4, lrs1=1, lrs2=5) -> rs1 should bypass from Inst 0's pdest
      
      val pdest0 = 40.U
      val pdest1 = 41.U
      
      // Inst 0
      dut.io.readPorts(0)(0).addr.poke(2.U)
      dut.io.readPorts(0)(1).addr.poke(3.U)
      dut.io.renamePorts(0).wen.poke(true.B)
      dut.io.renamePorts(0).addr.poke(1.U)
      dut.io.renamePorts(0).data.poke(pdest0)
      
      // Inst 1
      dut.io.readPorts(1)(0).addr.poke(1.U) // Dependency on Inst 0
      dut.io.readPorts(1)(1).addr.poke(5.U)
      dut.io.renamePorts(1).wen.poke(true.B)
      dut.io.renamePorts(1).addr.poke(4.U)
      dut.io.renamePorts(1).data.poke(pdest1)
      
      // Other ports idle
      for (i <- 2 until 6) {
        dut.io.renamePorts(i).wen.poke(false.B)
      }

      // Verify immediate read (intra-bundle bypass)
      dut.io.readPorts(0)(0).data.expect(2.U) // Initial mapping x2 -> p2
      dut.io.readPorts(0)(1).data.expect(3.U) // Initial mapping x3 -> p3
      
      dut.io.readPorts(1)(0).data.expect(pdest0) // Bypassed from Inst 0
      dut.io.readPorts(1)(1).data.expect(5.U)    // Initial mapping x5 -> p5
      
      dut.clock.step(1)
      
      // Verify x1 and x4 are now mapped in the spec table
      dut.io.readPorts(0)(0).addr.poke(1.U)
      dut.io.readPorts(0)(0).data.expect(pdest0)
      
      dut.io.readPorts(0)(1).addr.poke(4.U)
      dut.io.readPorts(0)(1).data.expect(pdest1)
    }
  }

  it should "ensure x0 always maps to p0" in {
    test(new RenameTable(32, false)) { dut =>
      dut.io.redirect.poke(false.B)
      
      // Try to rename x0 to p50
      dut.io.renamePorts(0).wen.poke(true.B)
      dut.io.renamePorts(0).addr.poke(0.U)
      dut.io.renamePorts(0).data.poke(50.U)
      
      // Read x0 in the same bundle
      dut.io.readPorts(1)(0).addr.poke(0.U)
      dut.io.readPorts(1)(0).data.expect(0.U)
      
      dut.clock.step(1)
      
      // Read x0 in next bundle
      dut.io.readPorts(0)(0).addr.poke(0.U)
      dut.io.readPorts(0)(0).data.expect(0.U)
    }
  }
}
