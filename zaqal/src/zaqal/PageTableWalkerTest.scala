package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.backend.csr.PrivMode
import zaqal.backend.mmu._
import zaqal.common._

object PageTableWalkerTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  RawTester.test(new PageTableWalker()) { dut =>
    println("===============================================================")
    println("  RUNNING DAY 11-13: HARDWARE SV39 PAGE TABLE WALKER TEST SUITE")
    println("  3-Level Radix Tree, Superpages (1GB/2MB/4KB), PMP, Permissions")
    println("===============================================================")

    dut.clock.setTimeout(0)

    // Reset default signals
    dut.io.flush.poke(false.B)
    dut.io.req.valid.poke(false.B)
    dut.io.mem_req.ready.poke(true.B) // Memory system always ready to accept requests
    dut.io.mem_resp.valid.poke(false.B)
    dut.io.sstatus_sum.poke(false.B)
    dut.io.sstatus_mxr.poke(false.B)
    dut.io.priv_mode.poke(PrivMode.U)

    // Default PMP open (allow all)
    for (i <- 0 until 16) {
      dut.io.pmpcfg(i).l.poke(false.B)
      dut.io.pmpcfg(i).reserved.poke(0.U)
      dut.io.pmpcfg(i).a.poke(0.U)
      dut.io.pmpcfg(i).x.poke(false.B)
      dut.io.pmpcfg(i).w.poke(false.B)
      dut.io.pmpcfg(i).r.poke(false.B)
      dut.io.pmpaddr(i).poke(0.U)
    }

    // Configure Sv39 mode with root page table at 0x80000000 (PPN = 0x80000)
    val rootPPN = BigInt("80000", 16)
    dut.io.satp_mode.poke(8.U) // Sv39
    dut.io.satp_asid.poke(1.U)
    dut.io.satp_ppn.poke(rootPPN.U)

    dut.clock.step(2)

    def handleMemResp(pteData: BigInt): BigInt = {
      while (!dut.io.mem_req.valid.peek().litToBoolean) {
        dut.clock.step(1)
      }
      val addr = dut.io.mem_req.bits.peek().litValue
      dut.clock.step(1) // mem_req fires -> moves to s_MEM_WAIT
      dut.io.mem_resp.valid.poke(true.B)
      dut.io.mem_resp.bits.poke(pteData.U)
      dut.clock.step(1) // mem_resp latches -> moves to s_CHECK_PTE
      dut.io.mem_resp.valid.poke(false.B)
      addr
    }

    // =========================================================================
    // Test 1: Canonical Virtual Address Check
    // =========================================================================
    println("\n[Test 1] Testing Canonical Address Verification in Sv39...")
    val nonCanonicalVA = BigInt("8000000000", 16)
    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(nonCanonicalVA.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.LOAD)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    while (!dut.io.resp.valid.peek().litToBoolean) {
      dut.clock.step(1)
    }
    assert(dut.io.resp.bits.page_fault.peek().litToBoolean, "Page fault should be raised for non-canonical address")
    assert(dut.io.resp.bits.fault_cause.peek().litValue == 13, s"Cause should be 13 (Load Page Fault), got ${dut.io.resp.bits.fault_cause.peek().litValue}")
    println("  -> Non-canonical address 0x0000008000000000 correctly triggered Page Fault (cause=13): PASS")
    dut.clock.step(1)

    // =========================================================================
    // Test 2: Standard 3-Level 4KB Page Table Walk (L2 -> L1 -> L0 -> 4KB Leaf)
    // =========================================================================
    println("\n[Test 2] Testing Standard 3-Level Page Walk for 4KB Page...")
    // VA: VPN[2]=2, VPN[1]=0x80, VPN[0]=0x42, Offset=0x123
    val va4K = (BigInt(2) << 30) | (BigInt(0x80) << 21) | (BigInt(0x42) << 12) | BigInt(0x123)

    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(va4K.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.LOAD)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    // L2: rootPPN(0x80000) + VPN[2](2)*8 = 0x80000010
    val l2_ppn = BigInt("81000", 16)
    val l2_pte = (l2_ppn << 10) | BigInt(1) // Pointer
    val l2Addr = handleMemResp(l2_pte)
    println(f"  -> Level 2 PTE request issued at address: 0x$l2Addr%016x")
    assert(l2Addr == ((rootPPN << 12) + 2 * 8), f"L2 addr mismatch: 0x$l2Addr%x")

    // L1: l2_ppn(0x81000) + VPN[1](0x80)*8 = 0x81000400
    val l1_ppn = BigInt("82000", 16)
    val l1_pte = (l1_ppn << 10) | BigInt(1) // Pointer
    val l1Addr = handleMemResp(l1_pte)
    println(f"  -> Level 1 PTE request issued at address: 0x$l1Addr%016x")
    assert(l1Addr == ((l2_ppn << 12) + 0x80 * 8), f"L1 addr mismatch: 0x$l1Addr%x")

    // L0: l1_ppn(0x82000) + VPN[0](0x42)*8 = 0x82000210
    val leaf_ppn = BigInt("90000", 16)
    val leaf_flags = BigInt("df", 16) // D=1, A=1, U=1, X=1, W=1, R=1, V=1
    val l0_pte = (leaf_ppn << 10) | leaf_flags
    val l0Addr = handleMemResp(l0_pte)
    println(f"  -> Level 0 PTE request issued at address: 0x$l0Addr%016x")
    assert(l0Addr == ((l1_ppn << 12) + 0x42 * 8), f"L0 addr mismatch: 0x$l0Addr%x")

    // Await PTW refill response
    while (!dut.io.resp.valid.peek().litToBoolean) {
      dut.clock.step(1)
    }
    val translatedPaddr = dut.io.resp.bits.paddr.peek().litValue
    val expectedPaddr = (leaf_ppn << 12) | BigInt(0x123)
    assert(!dut.io.resp.bits.page_fault.peek().litToBoolean, "Walk should not report page fault")
    assert(translatedPaddr == expectedPaddr, f"Expected paddr 0x$expectedPaddr%016x, got 0x$translatedPaddr%016x")
    assert(dut.io.resp.bits.level.peek().litValue == 0, "Level should be 0 for 4KB page")
    println(f"  -> 4KB Leaf Refill: VA=0x$va4K%016x translated to PA=0x$translatedPaddr%016x: PASS")
    dut.clock.step(1)

    // =========================================================================
    // Test 3: 2MB Megapage Leaf Walk (Level 1 Leaf)
    // =========================================================================
    println("\n[Test 3] Testing 2MB Megapage Walk (Level 1 Leaf)...")
    val va2M = (BigInt(1) << 30) | (BigInt(4) << 21) | BigInt(0xABC)
    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(va2M.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.LOAD)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    // L2 points to L1 at 0x83000
    handleMemResp((BigInt("83000", 16) << 10) | BigInt(1))

    // L1 is a 2MB leaf at PPN 0x92000 (PPN[0]==0)
    val mega_ppn = BigInt("92000", 16)
    val mega_pte = (mega_ppn << 10) | BigInt("df", 16)
    handleMemResp(mega_pte)

    while (!dut.io.resp.valid.peek().litToBoolean) dut.clock.step(1)
    val megaPaddr = dut.io.resp.bits.paddr.peek().litValue
    val expectedMegaPaddr = (mega_ppn << 12) | (va2M & BigInt("1fffff", 16))
    assert(megaPaddr == expectedMegaPaddr, f"Expected 0x$expectedMegaPaddr%016x, got 0x$megaPaddr%016x")
    assert(dut.io.resp.bits.level.peek().litValue == 1, "Level should be 1 for 2MB page")
    println(f"  -> 2MB Megapage: VA=0x$va2M%016x translated to PA=0x$megaPaddr%016x: PASS")
    dut.clock.step(1)

    // =========================================================================
    // Test 4: 1GB Gigapage Leaf Walk (Level 2 Leaf)
    // =========================================================================
    println("\n[Test 4] Testing 1GB Gigapage Walk (Level 2 Leaf)...")
    val va1G = (BigInt(3) << 30) | BigInt(0x123456)
    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(va1G.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.LOAD)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    // L2 is 1GB leaf at PPN 0x80000 (PPN[1:0]==0)
    val giga_ppn = BigInt("80000", 16)
    val giga_pte = (giga_ppn << 10) | BigInt("df", 16)
    handleMemResp(giga_pte)

    while (!dut.io.resp.valid.peek().litToBoolean) dut.clock.step(1)
    val gigaPaddr = dut.io.resp.bits.paddr.peek().litValue
    val expectedGigaPaddr = (giga_ppn << 12) | (va1G & BigInt("3fffffff", 16))
    assert(gigaPaddr == expectedGigaPaddr, f"Expected 0x$expectedGigaPaddr%016x, got 0x$gigaPaddr%016x")
    assert(dut.io.resp.bits.level.peek().litValue == 2, "Level should be 2 for 1GB page")
    println(f"  -> 1GB Gigapage: VA=0x$va1G%016x translated to PA=0x$gigaPaddr%016x: PASS")
    dut.clock.step(1)

    // =========================================================================
    // Test 5: Permission Fault Check (Store to Read-Only Page)
    // =========================================================================
    println("\n[Test 5] Testing Permission Violation (Store to Read-Only Page)...")
    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(va1G.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.STORE)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    // Return PTE with R=1, W=0 (Read-Only), U=1, A=1, D=1 (0xD3)
    val ro_pte = (giga_ppn << 10) | BigInt("d3", 16)
    handleMemResp(ro_pte)

    while (!dut.io.resp.valid.peek().litToBoolean) dut.clock.step(1)
    assert(dut.io.resp.bits.page_fault.peek().litToBoolean, "Page fault should be reported")
    assert(dut.io.resp.bits.fault_cause.peek().litValue == 15, s"Cause must be 15 (Store Page Fault), got ${dut.io.resp.bits.fault_cause.peek().litValue}")
    println("  -> Store to Read-Only page correctly raised Store Page Fault (cause=15): PASS")
    dut.clock.step(1)

    // =========================================================================
    // Test 6: Superpage Misalignment Fault
    // =========================================================================
    println("\n[Test 6] Testing Superpage Misalignment Fault...")
    dut.io.req.valid.poke(true.B)
    dut.io.req.bits.vaddr.poke(va1G.U)
    dut.io.req.bits.access_type.poke(PTWAccessType.LOAD)
    dut.io.req.bits.priv_mode.poke(PrivMode.U)
    dut.clock.step(1)
    dut.io.req.valid.poke(false.B)

    // Return 1GB leaf with non-zero PPN[1:0] (unaligned!)
    val unaligned_ppn = BigInt("80001", 16)
    val unaligned_pte = (unaligned_ppn << 10) | BigInt("df", 16)
    handleMemResp(unaligned_pte)

    while (!dut.io.resp.valid.peek().litToBoolean) dut.clock.step(1)
    assert(dut.io.resp.bits.page_fault.peek().litToBoolean, "Unaligned superpage must trigger page fault")
    println("  -> Misaligned 1GB Superpage correctly raised Page Fault: PASS")

    println("\n===============================================================")
    println("  ALL HARDWARE SV39 PAGE TABLE WALKER TESTS PASSED SUCCESSFULLY!")
    println("===============================================================")
  }
}
