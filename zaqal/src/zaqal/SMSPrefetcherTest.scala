package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.cache.prefetch._

object SMSPrefetcherTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  println("==================================================")
  println("  RUNNING DAY 29-31 SMS PREFETCHER TEST SUITE     ")
  println("==================================================")

  RawTester.test(new SMSPrefetcher(numAGT = 8, numPHT = 32)) { dut =>
    dut.io.flush.poke(false.B)
    dut.io.train.valid.poke(false.B)
    dut.clock.step(1)

    val triggerPc = 0x80005000L
    val region1Base = 0x10000L // 1KB region 0x40

    // -----------------------------------------------------------
    // Step 1: Record Spatial Footprint in Region 1
    // Access non-strided blocks: Block 0 (off 0), Block 5 (off 160), Block 7 (off 224)
    // -----------------------------------------------------------
    println("\n[Step 1] Recording irregular spatial access in Region 0x10000...")

    // Access Block 0 (Triggering access)
    println("  Access Block 0 (offset 0) with Trigger PC...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(triggerPc.U)
    dut.io.train.bits.addr.poke(region1Base.U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)
    dut.io.prefetch_req.valid.expect(false.B) // First time seeing this PC/region, no prefetch

    // Access Block 5 (offset 160 = 5 * 32)
    println("  Access Block 5 (offset 160)...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke((triggerPc + 4).U)
    dut.io.train.bits.addr.poke((region1Base + 5 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)
    dut.io.prefetch_req.valid.expect(false.B)

    // Access Block 7 (offset 224 = 7 * 32)
    println("  Access Block 7 (offset 224)...")
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke((triggerPc + 8).U)
    dut.io.train.bits.addr.poke((region1Base + 7 * 32L).U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)
    dut.io.prefetch_req.valid.expect(false.B)

    // -----------------------------------------------------------
    // Step 2: Evict Region 1 from AGT to trigger PHT writeback
    // Fill AGT with 8 new dummy regions (0x20000 ... 0x27000)
    // -----------------------------------------------------------
    println("\n[Step 2] Evicting Region 1 from AGT to store footprint into PHT...")
    for (i <- 1 to 8) {
      val dummyRegion = (0x20000L + (i * 1024L))
      dut.io.train.valid.poke(true.B)
      dut.io.train.bits.pc.poke((0x80009000L + i * 4).U)
      dut.io.train.bits.addr.poke(dummyRegion.U)
      dut.clock.step(1)
      dut.io.train.valid.poke(false.B)
    }
    println("  => Footprint (Blocks 0, 5, 7) written to PHT!")

    // -----------------------------------------------------------
    // Step 3: Predictive Playback on a brand new Region (0x50000)
    // When triggerPc accesses Block 0 in new region, PHT should recall
    // the spatial footprint and burst prefetches for Block 5 & Block 7!
    // -----------------------------------------------------------
    println("\n[Step 3] Entering brand new Region 0x50000 with trigger PC...")
    val newRegionBase = 0x50000L
    dut.io.train.valid.poke(true.B)
    dut.io.train.bits.pc.poke(triggerPc.U)
    dut.io.train.bits.addr.poke(newRegionBase.U)
    dut.clock.step(1)
    dut.io.train.valid.poke(false.B)

    // Cycle 1: SMS bursts first recalled block (Block 5: 0x50000 + 160 = 0x500A0)
    dut.io.prefetch_req.valid.expect(true.B)
    val expectedPf1 = newRegionBase + 5 * 32L
    dut.io.prefetch_req.bits.addr.expect(expectedPf1.U)
    println(s"  => PASS: Burst 1 Prefetch Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)} (Block 5)")

    dut.clock.step(1)

    // Cycle 2: SMS bursts second recalled block (Block 7: 0x50000 + 224 = 0x500E0)
    dut.io.prefetch_req.valid.expect(true.B)
    val expectedPf2 = newRegionBase + 7 * 32L
    dut.io.prefetch_req.bits.addr.expect(expectedPf2.U)
    println(s"  => PASS: Burst 2 Prefetch Addr: 0x${dut.io.prefetch_req.bits.addr.peek().litValue.toString(16)} (Block 7)")

    dut.clock.step(1)

    // Burst finished
    dut.io.prefetch_req.valid.expect(false.B)
    println("  => PASS: Spatial footprint playback completed!")
  }

  println("\n==================================================")
  println("  ALL SMS PREFETCHER TESTS PASSED SUCCESSFULLY!   ")
  println("==================================================")
}
