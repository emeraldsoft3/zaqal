package qalam

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.Suite

class CoreSpec extends Suite with AnyFlatSpec with ChiselScalatestTester {
  "Core" should "execute ADDI" in {
    test(new Core) { c =>
      // ADDI x1, x0, 10 -> 00a00093
      c.io.inst.poke("h00a00093".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(1.U)
      c.io.rd_data.expect(10.U)

      // ADDI x1, x1, 5 -> 00508093
      c.io.inst.poke("h00508093".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(1.U)
      c.io.rd_data.expect(15.U)
    }
  }
}
