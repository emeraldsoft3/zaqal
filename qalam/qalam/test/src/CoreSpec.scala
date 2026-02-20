import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import qalam.Core

class CoreSpec extends AnyFlatSpec with ChiselScalatestTester {

  "Core" should "execute ADDI: x1 = x0 + 10" in {
    test(new Core) { c =>
      // ADDI x1, x0, 10  ->  imm=10, rs1=x0, rd=x1  ->  0x00a00093
      c.io.inst.poke("h00a00093".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(1.U)
      c.io.rd_data.expect(10.U)
    }
  }

  "Core" should "execute ADD: x3 = x1 + x2" in {
    test(new Core) { c =>
      // seed x1 = 7 via ADDI x1, x0, 7  -> 0x00700093
      c.io.inst.poke("h00700093".U)
      c.clock.step(1)
      // seed x2 = 3 via ADDI x2, x0, 3  -> 0x00300113
      c.io.inst.poke("h00300113".U)
      c.clock.step(1)
      // ADD x3, x1, x2  -> opcode=0110011, funct7=0000000, rs2=x2, rs1=x1, funct3=000, rd=x3
      // 0000000_00010_00001_000_00011_0110011  -> 0x002081b3
      c.io.inst.poke("h002081b3".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(3.U)
      c.io.rd_data.expect(10.U)
    }
  }

  "Core" should "execute MUL: x3 = x1 * x2" in {
    test(new Core) { c =>
      // seed x1 = 6 via ADDI x1, x0, 6  -> 0x00600093
      c.io.inst.poke("h00600093".U)
      c.clock.step(1)
      // seed x2 = 7 via ADDI x2, x0, 7  -> 0x00700113
      c.io.inst.poke("h00700113".U)
      c.clock.step(1)
      // MUL x3, x1, x2  -> opcode=0110011, funct7=0000001, rs2=x2, rs1=x1, funct3=000, rd=x3
      // 0000001_00010_00001_000_00011_0110011  -> 0x022081b3
      c.io.inst.poke("h022081b3".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(3.U)
      c.io.rd_data.expect(42.U)
    }
  }

  "Core" should "execute DIV: x3 = x1 / x2" in {
    test(new Core) { c =>
      // seed x1 = 20 via ADDI x1, x0, 20  -> 0x01400093
      c.io.inst.poke("h01400093".U)
      c.clock.step(1)
      // seed x2 = 4 via ADDI x2, x0, 4  -> 0x00400113
      c.io.inst.poke("h00400113".U)
      c.clock.step(1)
      // DIV x3, x1, x2  -> opcode=0110011, funct7=0000001, rs2=x2, rs1=x1, funct3=100, rd=x3
      // 0000001_00010_00001_100_00011_0110011  -> 0x0220c1b3
      c.io.inst.poke("h0220c1b3".U)
      c.clock.step(1)
      c.io.wen.expect(true.B)
      c.io.rd_addr.expect(3.U)
      c.io.rd_data.expect(5.U)
    }
  }
}
