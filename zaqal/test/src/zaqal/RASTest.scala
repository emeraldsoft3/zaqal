package zaqal

import zaqal.common._
import zaqal.frontend._
import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import org.scalatest.flatspec.AnyFlatSpec

class RASTest extends AnyFlatSpec with ChiselScalatestTester {
  implicit val p: Parameters = new ZaqalConfig

  "Return Address Stack (RAS)" should "push and pop return addresses in LIFO order" in {
    test(new RAS) { dut =>
      dut.io.restore_en.poke(false.B)
      dut.io.restore_sp.poke(0.U)

      // Cycle 0: Push Address 0x80000004 (Subroutine A)
      dut.io.push_valid.poke(true.B)
      dut.io.push_addr.poke("h8000_0004".U)
      dut.io.pop_valid.poke(false.B)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 1)

      // Cycle 1: Push Address 0x80000040 (Subroutine B - Nested Call)
      dut.io.push_valid.poke(true.B)
      dut.io.push_addr.poke("h8000_0040".U)
      dut.io.pop_valid.poke(false.B)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 2)
      dut.io.pop_addr.expect("h8000_0040".U) // Top of stack is Subroutine B return

      // Cycle 2: Pop Return Address (Return from Subroutine B)
      dut.io.push_valid.poke(false.B)
      dut.io.pop_valid.poke(true.B)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 1)
      dut.io.pop_addr.expect("h8000_0004".U) // Top of stack is now Subroutine A return

      // Cycle 3: Pop Return Address (Return from Subroutine A)
      dut.io.push_valid.poke(false.B)
      dut.io.pop_valid.poke(true.B)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 0)
    }
  }

  it should "restore stack pointer on misprediction redirection" in {
    test(new RAS) { dut =>
      // Push 3 return addresses
      dut.io.restore_en.poke(false.B)
      dut.io.push_valid.poke(true.B)
      dut.io.push_addr.poke("h8000_0100".U)
      dut.clock.step(1)

      dut.io.push_addr.poke("h8000_0200".U)
      dut.clock.step(1)

      dut.io.push_addr.poke("h8000_0300".U)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 3)

      // Simulate wrong-path call pushing corrupt address
      dut.io.push_addr.poke("hDEAD_BEEF".U)
      dut.clock.step(1)
      assert(dut.io.sp.peek().litValue == 4)

      // Misprediction redirection: restore stack pointer to 3 (state before wrong path)
      dut.io.push_valid.poke(false.B)
      dut.io.restore_en.poke(true.B)
      dut.io.restore_sp.poke(3.U)
      dut.clock.step(1)

      assert(dut.io.sp.peek().litValue == 3)
      dut.io.pop_addr.expect("h8000_0300".U)
    }
  }
}
