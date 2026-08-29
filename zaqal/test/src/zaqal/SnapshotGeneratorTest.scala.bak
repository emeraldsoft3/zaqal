package zaqal

import chisel3._
import chisel3.util._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import zaqal.backend.SnapshotGenerator
import zaqal.common._
import org.chipsalliance.cde.config.Parameters

class SnapshotGeneratorTest extends AnyFlatSpec with ChiselScalatestTester {
  implicit val p: Parameters = new ZaqalConfig

  behavior of "SnapshotGenerator"

  it should "enqueue, dequeue, and correctly restore enqPtr on flush" in {
    test(new SnapshotGenerator(UInt(32.W))).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // Init
      dut.io.enq.poke(false.B)
      dut.io.deq.poke(false.B)
      dut.io.redirect.poke(false.B)
      for (i <- 0 until p(ZaqalParamsKey).renameSnapshotNum) {
        dut.io.flushVec(i).poke(false.B)
      }
      dut.clock.step(1)

      // 1. Enqueue snapshot 0
      dut.io.enq.poke(true.B)
      dut.io.enqData.poke(100.U)
      dut.clock.step(1)
      
      // 2. Enqueue snapshot 1
      dut.io.enqData.poke(101.U)
      dut.clock.step(1)
      
      // 3. Enqueue snapshot 2
      dut.io.enqData.poke(102.U)
      dut.clock.step(1)
      
      dut.io.enq.poke(false.B)
      
      // Check enqPtr is now 3
      dut.io.enqPtr.expect(3.U)
      dut.io.snapshots(0).expect(100.U)
      dut.io.snapshots(1).expect(101.U)
      dut.io.snapshots(2).expect(102.U)
      
      // 4. Dequeue snapshot 0
      dut.io.deq.poke(true.B)
      dut.clock.step(1)
      dut.io.deq.poke(false.B)
      
      // Check deqPtr is now 1
      dut.io.deqPtr.expect(1.U)
      
      // 5. Simulate mispredict at snapshot 1. 
      // This flushes snapshot 2 (younger than 1).
      // We also do a redirect.
      dut.io.redirect.poke(true.B)
      dut.io.flushVec(2).poke(true.B)
      dut.clock.step(1)
      dut.io.redirect.poke(false.B)
      dut.io.flushVec(2).poke(false.B)
      
      // Now enqPtr should be restored to 2, because 2 was flushed.
      dut.io.enqPtr.expect(2.U)
      dut.io.valids(2).expect(false.B)
      dut.io.valids(1).expect(true.B)
    }
  }
}
