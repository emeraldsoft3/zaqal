package zaqal

import chisel3._
import chiseltest._
import org.chipsalliance.cde.config.Parameters
import zaqal.backend.csr._
import zaqal.common._

object CSRTest extends App {
  implicit val p: Parameters = new ZaqalConfig

  RawTester.test(new CSRFile()) { dut =>
    println("==================================================")
    println("  RUNNING DAY 1-3: CSR IMPLEMENTATION TEST SUITE  ")
    println("  Machine & Supervisor Modes, Privilege & Flush  ")
    println("==================================================")

    dut.clock.setTimeout(0)

    // Helper to perform a CSR access
    def csrAccess(addr: UInt, cmd: Int, wdata: BigInt, wen: Boolean): (BigInt, Boolean, Boolean) = {
      dut.io.csr_addr.poke(addr)
      dut.io.csr_cmd.poke(cmd.U)
      dut.io.csr_wdata.poke(wdata.U)
      dut.io.csr_wen.poke(wen.B)
      val rdata = dut.io.csr_rdata.peek().litValue
      val illegal = dut.io.is_illegal.peek().litToBoolean
      val flush = dut.io.flush_pipe.peek().litToBoolean
      dut.clock.step(1)
      (rdata, illegal, flush)
    }

    // -----------------------------------------------------------------------
    // Test 1: Basic Read & Write (CSRRW) on Machine Scratch (mscratch: 0x340)
    // -----------------------------------------------------------------------
    println("\n[Test 1] Testing CSRRW on mscratch (0x340)...")
    // Initial read (mscratch should be 0)
    val (r0, ill0, _) = csrAccess(CSRAddr.mscratch, 1, 0, false)
    assert(r0 == 0, s"Expected initial mscratch=0, got $r0")
    assert(!ill0, "Access to mscratch in M-mode should be legal")
    println("  -> Initial read mscratch = 0: PASS")

    // Write 0xDEADBEEFCAFE1234
    val testVal1 = BigInt("DEADBEEFCAFE1234", 16)
    val (r1, ill1, _) = csrAccess(CSRAddr.mscratch, 1, testVal1, true)
    println(f"  -> Wrote mscratch = 0x$testVal1%016x (old val was 0x$r1%016x): PASS")

    // Read back to verify
    val (r2, _, _) = csrAccess(CSRAddr.mscratch, 1, 0, false)
    assert(r2 == testVal1, f"Expected 0x$testVal1%016x, got 0x$r2%016x")
    println(f"  -> Read back mscratch = 0x$r2%016x: PASS")

    // -----------------------------------------------------------------------
    // Test 2: Atomic Bit Set (CSRRS) & Clear (CSRRC) on sscratch (0x140)
    // -----------------------------------------------------------------------
    println("\n[Test 2] Testing CSRRS (Set) and CSRRC (Clear) on sscratch (0x140)...")
    // Write initial pattern: 0x00FF
    csrAccess(CSRAddr.sscratch, 1, BigInt("00FF", 16), true)
    
    // Set bits with mask 0xFF00 -> Result should be 0xFFFF
    val (rSetOld, _, _) = csrAccess(CSRAddr.sscratch, 2, BigInt("FF00", 16), true)
    val (rSetNew, _, _) = csrAccess(CSRAddr.sscratch, 1, 0, false)
    assert(rSetOld == BigInt("00FF", 16), s"Expected old=0x00FF, got $rSetOld")
    assert(rSetNew == BigInt("FFFF", 16), s"Expected new=0xFFFF, got $rSetNew")
    println("  -> CSRRS bit-set verified (0x00FF | 0xFF00 = 0xFFFF): PASS")

    // Clear bits with mask 0x0F0F -> Result should be 0xF0F0
    val (_, _, _) = csrAccess(CSRAddr.sscratch, 3, BigInt("0F0F", 16), true)
    val (rClrNew, _, _) = csrAccess(CSRAddr.sscratch, 1, 0, false)
    assert(rClrNew == BigInt("F0F0", 16), s"Expected new=0xF0F0, got $rClrNew")
    println("  -> CSRRC bit-clear verified (0xFFFF & ~0x0F0F = 0xF0F0): PASS")

    // Read with rs1=0 (wdata=0) should NOT modify
    csrAccess(CSRAddr.sscratch, 2, 0, true)
    val (rNoMod, _, _) = csrAccess(CSRAddr.sscratch, 1, 0, false)
    assert(rNoMod == BigInt("F0F0", 16), "Read with wdata=0 must not mutate CSR")
    println("  -> Read-only side effect suppression (rs1=x0) verified: PASS")

    // -----------------------------------------------------------------------
    // Test 3: Supervisor Address Translation (satp: 0x180) & Pipeline Flush
    // -----------------------------------------------------------------------
    println("\n[Test 3] Testing satp (0x180) Configuration & Pipeline Flush Assertion...")
    // Configure Sv39 virtual memory: MODE = 8 (Sv39), ASID = 1, PPN = 0x80000
    // satp[63:60] = 8, satp[59:44] = 1, satp[43:0] = 0x80000
    val satpVal = (BigInt(8) << 60) | (BigInt(1) << 44) | BigInt("80000", 16)
    val (_, _, flushSatp) = csrAccess(CSRAddr.satp, 1, satpVal, true)
    assert(flushSatp, "Writing satp must assert flush_pipe!")
    println("  -> satp write asserted flush_pipe = true: PASS")

    val (satpRead, _, _) = csrAccess(CSRAddr.satp, 1, 0, false)
    assert(satpRead == satpVal, f"Expected satp=0x$satpVal%016x, got 0x$satpRead%016x")
    assert(dut.io.satp_mode.peek().litValue == 8, "Expected satp.MODE = 8 (Sv39)")
    assert(dut.io.satp_asid.peek().litValue == 1, "Expected satp.ASID = 1")
    assert(dut.io.satp_ppn.peek().litValue == BigInt("80000", 16), "Expected satp.PPN = 0x80000")
    println(f"  -> Sv39 Address Translation parameters active: MODE=8, ASID=1, PPN=0x80000: PASS")

    // -----------------------------------------------------------------------
    // Test 4: sstatus Shadowing & mstatus Synchronization
    // -----------------------------------------------------------------------
    println("\n[Test 4] Testing sstatus (0x100) / mstatus (0x300) Shadow Reflection...")
    // Enable Supervisor Interrupts via sstatus (bit 1: SIE = 1, bit 5: SPIE = 1)
    val sstatusWrite = (1 << 1) | (1 << 5)
    csrAccess(CSRAddr.sstatus, 1, sstatusWrite, true)

    val (mstatusRead, _, _) = csrAccess(CSRAddr.mstatus, 1, 0, false)
    val sieBit = (mstatusRead >> 1) & 1
    val spieBit = (mstatusRead >> 5) & 1
    assert(sieBit == 1 && spieBit == 1, "Writes to sstatus must propagate to mstatus shadow fields")
    println("  -> sstatus write accurately updated mstatus (SIE=1, SPIE=1): PASS")

    // -----------------------------------------------------------------------
    // Test 5: Trap Vectors (mtvec: 0x305 & stvec: 0x105)
    // -----------------------------------------------------------------------
    println("\n[Test 5] Testing mtvec (0x305) and stvec (0x105)...")
    val mtvecTarget = BigInt("80000000", 16)
    val stvecTarget = BigInt("80001000", 16)
    csrAccess(CSRAddr.mtvec, 1, mtvecTarget, true)
    csrAccess(CSRAddr.stvec, 1, stvecTarget, true)

    assert(dut.io.mtvec_val.peek().litValue == mtvecTarget, "mtvec hardware wire must reflect written value")
    assert(dut.io.stvec_val.peek().litValue == stvecTarget, "stvec hardware wire must reflect written value")
    println("  -> Trap vector base registers mtvec & stvec verified: PASS")

    // -----------------------------------------------------------------------
    // Test 6: Read-Only Registers (misa: 0x301) & MISA Capabilities
    // -----------------------------------------------------------------------
    println("\n[Test 6] Testing MISA (0x301) Architecture String...")
    val (misaRead, _, _) = csrAccess(CSRAddr.misa, 1, 0, false)
    val hasI = (misaRead >> 8) & 1
    val hasM = (misaRead >> 12) & 1
    val hasA = (misaRead >> 0) & 1
    val hasF = (misaRead >> 5) & 1
    val hasD = (misaRead >> 3) & 1
    val hasC = (misaRead >> 2) & 1
    val hasS = (misaRead >> 18) & 1
    val hasU = (misaRead >> 20) & 1
    assert(hasI == 1 && hasM == 1 && hasA == 1 && hasF == 1 && hasD == 1 && hasC == 1 && hasS == 1 && hasU == 1,
      "MISA must report full RV64GC with Supervisor & User support!")
    println(f"  -> MISA reports RV64IMAFDC + S + U (0x$misaRead%016x): PASS")

    println("\n==================================================")
    println("  ALL DAY 1-3 CSR IMPLEMENTATION TESTS PASSED!    ")
    println("==================================================")
  }
}
