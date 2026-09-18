package zaqal

import chisel3._
import chisel3.util._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.backend.mdp._
import zaqal.backend.lsu._

object MDPTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  println("=================================================================")
  println("  Day 25: Memory Dependence Predictor (MDP) Verification Suite   ")
  println("  XiangShan Parity: Store Sets (SSIT + LFST) & RAW Violation     ")
  println("=================================================================")

  // -------------------------------------------------------------
  // Test Suite 1: SSIT (Store Set Identifier Table)
  // -------------------------------------------------------------
  RawTester.test(new SSIT) { dut =>
    println("\n[Test 1] SSIT Training & Query Tests")

    // Initially, PC 0x1000 and 0x2000 should be unassigned (valid = false)
    dut.io.pc(0).poke("h1000".U)
    dut.io.pc(1).poke("h2000".U)
    dut.io.update.valid.poke(false.B)
    dut.clock.step(1)

    dut.io.resp(0).valid.expect(false.B)
    dut.io.resp(1).valid.expect(false.B)
    println("  -> Initial lookup unassigned: PASS")

    // Case 1: Memory violation between Load (0x1000) and Store (0x2000)
    // Both unassigned -> Allocate new shared SSID
    dut.io.update.valid.poke(true.B)
    dut.io.update.ldpc.poke("h1000".U)
    dut.io.update.stpc.poke("h2000".U)
    dut.clock.step(1)
    dut.io.update.valid.poke(false.B)
    dut.clock.step(1)

    dut.io.pc(0).poke("h1000".U)
    dut.io.pc(1).poke("h2000".U)
    dut.clock.step(1)

    dut.io.resp(0).valid.expect(true.B)
    dut.io.resp(1).valid.expect(true.B)
    val ssidLd = dut.io.resp(0).ssid.peek().litValue
    val ssidSt = dut.io.resp(1).ssid.peek().litValue
    assert(ssidLd == ssidSt, s"Expected matching SSID for paired load and store, got ld=$ssidLd, st=$ssidSt")
    println(s"  -> Case 1 (Pair Allocation): Assigned shared SSID = $ssidLd: PASS")

    // Case 2: Another Store (0x3000) collides with Load (0x1000)
    // Load already assigned -> Add Store 0x3000 to the same SSID
    dut.io.update.valid.poke(true.B)
    dut.io.update.ldpc.poke("h1000".U)
    dut.io.update.stpc.poke("h3000".U)
    dut.clock.step(1)
    dut.io.update.valid.poke(false.B)
    dut.clock.step(1)

    dut.io.pc(0).poke("h3000".U)
    dut.clock.step(1)
    dut.io.resp(0).valid.expect(true.B)
    dut.io.resp(0).ssid.expect(ssidLd.U)
    println(s"  -> Case 2 (Join existing Store Set): Store 0x3000 joined SSID = $ssidLd: PASS")
  }

  // -------------------------------------------------------------
  // Test Suite 2: LFST (Last Fetched Store Table)
  // -------------------------------------------------------------
  RawTester.test(new LFST) { dut =>
    println("\n[Test 2] LFST Query, Bypass, and Resolution Tests")

    dut.io.robHeadPtr.poke(0.U)
    dut.io.redirect.valid.poke(false.B)
    dut.io.storeResolved.valid.poke(false.B)

    for (i <- 0 until 6) {
      dut.io.req(i).valid.poke(false.B)
      dut.io.req(i).bits.isStore.poke(false.B)
      dut.io.req(i).bits.ssid.poke(0.U)
      dut.io.req(i).bits.robIdx.poke(0.U)
    }
    dut.clock.step(1)

    // Cycle 1: Dispatched Store at Port 0 with SSID=7, robIdx=15
    dut.io.req(0).valid.poke(true.B)
    dut.io.req(0).bits.isStore.poke(true.B)
    dut.io.req(0).bits.ssid.poke(7.U)
    dut.io.req(0).bits.robIdx.poke(15.U)
    dut.clock.step(1)

    // Cycle 2: Dispatched Load at Port 0 with SSID=7
    // Should detect the in-flight store and return shouldWait=true, robIdx=15
    dut.io.req(0).valid.poke(true.B)
    dut.io.req(0).bits.isStore.poke(false.B)
    dut.io.req(0).bits.ssid.poke(7.U)
    dut.clock.step(1)

    dut.io.resp(0).shouldWait.expect(true.B)
    dut.io.resp(0).robIdx.expect(15.U)
    println("  -> Inter-cycle Store -> Load dependency tracking: PASS")

    // Cycle 3: Store Resolution in AGU (robIdx=15 finished)
    dut.io.req(0).valid.poke(false.B)
    dut.io.storeResolved.valid.poke(true.B)
    dut.io.storeResolved.bits.poke(15.U)
    dut.clock.step(1)
    dut.io.storeResolved.valid.poke(false.B)

    // Cycle 4: Subsequent Load with SSID=7 should NOT wait anymore
    dut.io.req(0).valid.poke(true.B)
    dut.io.req(0).bits.isStore.poke(false.B)
    dut.io.req(0).bits.ssid.poke(7.U)
    dut.clock.step(1)
    dut.io.resp(0).shouldWait.expect(false.B)
    println("  -> Store resolution clears wait condition: PASS")

    // Cycle 5: Intra-bundle bypass test!
    // Store at Port 1 (SSID=12, robIdx=24), Load at Port 2 (SSID=12) in same cycle
    dut.io.req(0).valid.poke(false.B)
    dut.io.req(1).valid.poke(true.B)
    dut.io.req(1).bits.isStore.poke(true.B)
    dut.io.req(1).bits.ssid.poke(12.U)
    dut.io.req(1).bits.robIdx.poke(24.U)

    dut.io.req(2).valid.poke(true.B)
    dut.io.req(2).bits.isStore.poke(false.B)
    dut.io.req(2).bits.ssid.poke(12.U)
    dut.clock.step(1)

    dut.io.resp(2).shouldWait.expect(true.B)
    dut.io.resp(2).robIdx.expect(24.U)
    println("  -> Intra-bundle superscalar store-to-load bypass: PASS")
  }

  // -------------------------------------------------------------
  // Test Suite 3: LoadQueue RAW Violation Detection
  // -------------------------------------------------------------
  RawTester.test(new LoadQueue(16)) { dut =>
    println("\n[Test 3] LoadQueue Memory Ordering Violation Detection Tests")

    dut.io.robHeadPtr.poke(0.U)
    dut.io.snptDeqPtr.poke(0.U)
    dut.io.redirect.valid.poke(false.B)
    dut.io.commit.valid.foreach(_.poke(false.B))
    dut.io.store_snoop.valid.poke(false.B)
    dut.io.exec_update.foreach(_.valid.poke(false.B))
    dut.io.enq.foreach(_.valid.poke(false.B))
    dut.clock.step(1)

    // 1. Allocate Load in LQ: robIdx=20, snapshotIdx=2, pc=0x80001000
    dut.io.enq(0).valid.poke(true.B)
    dut.io.enq(0).bits.robIdx.poke(20.U)
    dut.io.enq(0).bits.snapshotIdx.poke(2.U)
    dut.io.enq(0).bits.pc.poke("h80001000".U)
    dut.clock.step(1)
    dut.io.enq(0).valid.poke(false.B)

    // 2. Load executes prematurely at AGU: paddr=0x80000040, mask=0x000F
    dut.io.exec_update(0).valid.poke(true.B)
    dut.io.exec_update(0).robIdx.poke(20.U)
    dut.io.exec_update(0).paddr.poke("h80000040".U)
    dut.io.exec_update(0).mask.poke("h000F".U)
    dut.io.exec_update(0).pc.poke("h80001000".U)
    dut.clock.step(1)
    dut.io.exec_update(0).valid.poke(false.B)

    // 3. Older Store (robIdx=10, pc=0x80002000) calculates its address: paddr=0x80000040, mask=0x000F
    // This is an out-of-order RAW violation!
    dut.io.store_snoop.valid.poke(true.B)
    dut.io.store_snoop.robIdx.poke(10.U)
    dut.io.store_snoop.paddr.poke("h80000040".U)
    dut.io.store_snoop.mask.poke("h000F".U)
    dut.io.store_snoop.pc.poke("h80002000".U)
    dut.clock.step(1)

    dut.io.violation.valid.expect(true.B)
    dut.io.violation.loadRobIdx.expect(20.U)
    dut.io.violation.loadPC.expect("h80001000".U)
    dut.io.violation.storePC.expect("h80002000".U)
    println("  -> RAW collision detected correctly (Load 0x80001000 collided with older Store 0x80002000): PASS")

    // 4. Test non-colliding address: older store writes to 0x80000080
    dut.io.store_snoop.paddr.poke("h80000080".U)
    dut.clock.step(1)
    dut.io.violation.valid.expect(false.B)
    println("  -> Independent memory addresses do not violate: PASS")

    // 5. Test younger store: store robIdx=25 (younger than load robIdx=20) writes same address 0x80000040
    // In program order, Store is younger, so Load reading old value is LEGAL in OoO!
    dut.io.store_snoop.robIdx.poke(25.U)
    dut.io.store_snoop.paddr.poke("h80000040".U)
    dut.clock.step(1)
    dut.io.violation.valid.expect(false.B)
    println("  -> Younger store executing after older load correctly allowed (no violation): PASS")
  }

  // -------------------------------------------------------------
  // Test Suite 4: Top-Level StoreSet End-to-End Integration
  // -------------------------------------------------------------
  RawTester.test(new StoreSet) { dut =>
    println("\n[Test 4] Top-Level StoreSet Integration: Violation -> Training -> Wait")

    dut.io.robHeadPtr.poke(0.U)
    dut.io.redirect.valid.poke(false.B)
    dut.io.store_resolved.valid.poke(false.B)
    dut.io.update.valid.poke(false.B)
    dut.io.dispatch_req.foreach(_.valid.poke(false.B))
    dut.io.decode_pc.foreach(_.poke(0.U))
    dut.clock.step(1)

    // 1. Memory violation occurs: Load at 0x1000 collided with Store at 0x2000
    dut.io.update.valid.poke(true.B)
    dut.io.update.ldpc.poke("h1000".U)
    dut.io.update.stpc.poke("h2000".U)
    dut.clock.step(1)
    dut.io.update.valid.poke(false.B)
    dut.clock.step(1)

    // 2. Subsequent Fetch: Store at 0x2000 passes Decode stage
    dut.io.decode_pc(0).poke("h2000".U)
    dut.clock.step(1)
    dut.io.decode_ssit(0).valid.expect(true.B)
    val stSsid = dut.io.decode_ssit(0).ssid.peek().litValue

    // 3. Store at 0x2000 dispatched: robIdx=8
    dut.io.dispatch_req(0).valid.poke(true.B)
    dut.io.dispatch_req(0).bits.isStore.poke(true.B)
    dut.io.dispatch_req(0).bits.ssid.poke(stSsid.U)
    dut.io.dispatch_req(0).bits.robIdx.poke(8.U)
    dut.clock.step(1)
    dut.io.dispatch_req(0).valid.poke(false.B)

    // 4. Load at 0x1000 passes Decode stage: Gets matching SSID!
    dut.io.decode_pc(0).poke("h1000".U)
    dut.clock.step(1)
    dut.io.decode_ssit(0).valid.expect(true.B)
    dut.io.decode_ssit(0).ssid.expect(stSsid.U)

    // 5. Load at 0x1000 dispatched: LFST predicts collision with Store robIdx=8!
    dut.io.dispatch_req(0).valid.poke(true.B)
    dut.io.dispatch_req(0).bits.isStore.poke(false.B)
    dut.io.dispatch_req(0).bits.ssid.poke(stSsid.U)
    dut.clock.step(1)

    dut.io.dispatch_resp(0).shouldWait.expect(true.B)
    dut.io.dispatch_resp(0).robIdx.expect(8.U)
    println(s"  -> Full MDP closed-loop: SSIT trained, LFST predicted load wait on Store robIdx=8: PASS")
  }

  println("\n=================================================================")
  println("  ALL DAY 25 MEMORY DEPENDENCE PREDICTOR TESTS PASSED!           ")
  println("=================================================================\n")
}
