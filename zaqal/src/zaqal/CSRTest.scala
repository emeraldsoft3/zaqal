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

    dut.io.trap_in.valid.poke(false.B)
    dut.io.trap_in.epc.poke(0.U)
    dut.io.trap_in.cause.poke(0.U)
    dut.io.trap_in.tval.poke(0.U)
    dut.io.mret_valid.poke(false.B)
    dut.io.sret_valid.poke(false.B)

    // Helper to perform a CSR access
    def csrAccess(addr: UInt, cmd: Int, wdata: BigInt, wen: Boolean): (BigInt, Boolean, Boolean) = {
      dut.io.trap_in.valid.poke(false.B)
      dut.io.mret_valid.poke(false.B)
      dut.io.sret_valid.poke(false.B)
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
    // Test 4b: 32-bit Compatibility Mode / XLEN Fields (mstatus.UXL, mstatus.SXL, sstatus.UXL)
    // -----------------------------------------------------------------------
    println("\n[Test 4b] Testing 32-bit Compatibility Mode / XLEN Fields (SXL & UXL)...")
    val (mstatusInit, _, _) = csrAccess(CSRAddr.mstatus, 1, 0, false)
    val (sstatusInit, _, _) = csrAccess(CSRAddr.sstatus, 1, 0, false)

    val mstatusSXL = (mstatusInit >> 34) & 3
    val mstatusUXL = (mstatusInit >> 32) & 3
    val sstatusUXL = (sstatusInit >> 32) & 3

    assert(mstatusSXL == 2, s"Expected mstatus.SXL = 2 (RV64), got $mstatusSXL")
    assert(mstatusUXL == 2, s"Expected mstatus.UXL = 2 (RV64), got $mstatusUXL")
    assert(sstatusUXL == 2, s"Expected sstatus.UXL = 2 (RV64), got $sstatusUXL")
    println(f"  -> Initial XLEN fields verified: mstatus.SXL=$mstatusSXL, mstatus.UXL=$mstatusUXL, sstatus.UXL=$sstatusUXL: PASS")

    // Attempt to write RV32 (1) into UXL/SXL via mstatus (bits 35:32)
    val attemptVal = (BigInt(1) << 34) | (BigInt(1) << 32)
    csrAccess(CSRAddr.mstatus, 1, attemptVal, true)
    val (mstatusAfterWrite, _, _) = csrAccess(CSRAddr.mstatus, 1, 0, false)
    val (sstatusAfterWrite, _, _) = csrAccess(CSRAddr.sstatus, 1, 0, false)

    val sxlAfter = (mstatusAfterWrite >> 34) & 3
    val uxlAfter = (mstatusAfterWrite >> 32) & 3
    val sstatusUxlAfter = (sstatusAfterWrite >> 32) & 3

    assert(sxlAfter == 2, s"mstatus.SXL must remain 2 (WARL read-only in pure RV64), got $sxlAfter")
    assert(uxlAfter == 2, s"mstatus.UXL must remain 2 (WARL read-only in pure RV64), got $uxlAfter")
    assert(sstatusUxlAfter == 2, s"sstatus.UXL must remain 2 (WARL read-only in pure RV64), got $sstatusUxlAfter")
    println("  -> WARL read-only hardwire verified: SXL and UXL cannot be overwritten: PASS")

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

    // -----------------------------------------------------------------------
    // Test 7: Privilege Transition M -> U via MRET (Day 4-5)
    // -----------------------------------------------------------------------
    println("\n[Test 7] Testing MRET Privilege Transition (Machine -> User)...")
    assert(dut.io.priv_mode.peek().litValue == PrivMode.M.litValue, "Initial mode must be M")

    // Setup mstatus.MPP = U (0) and mepc = 0x80002000
    csrAccess(CSRAddr.mstatus, 1, 0, true) // MPP = 0
    csrAccess(CSRAddr.mepc, 1, BigInt("80002000", 16), true)

    // Execute MRET
    dut.io.csr_wen.poke(false.B)
    dut.io.csr_cmd.poke(0.U)
    dut.io.mret_valid.poke(true.B)
    dut.clock.step(1)
    dut.io.mret_valid.poke(false.B)

    // Verify priv_mode transitioned to U (0)
    val privAfterMret = dut.io.priv_mode.peek().litValue
    assert(privAfterMret == PrivMode.U.litValue, s"Expected priv_mode=U (0), got $privAfterMret")
    println("  -> MRET successfully transitioned CPU to User mode (priv_mode = 0): PASS")

    // -----------------------------------------------------------------------
    // Test 8: Privilege Protection in User Mode (Day 4-5)
    // -----------------------------------------------------------------------
    println("\n[Test 8] Testing Privilege Protection in User Mode...")
    // In User mode, accessing Machine CSR (mscratch: 0x340) or Supervisor CSR (satp: 0x180) must be ILLEGAL!
    dut.io.csr_addr.poke(CSRAddr.mscratch)
    dut.io.csr_cmd.poke(1.U)
    dut.io.csr_wen.poke(true.B)
    dut.io.csr_wdata.poke(0x123.U)
    assert(dut.io.is_illegal.peek().litToBoolean, "User mode access to mscratch must be illegal!")

    dut.io.csr_addr.poke(CSRAddr.satp)
    assert(dut.io.is_illegal.peek().litToBoolean, "User mode access to satp must be illegal!")
    println("  -> User mode illegal CSR accesses correctly rejected: PASS")

    // -----------------------------------------------------------------------
    // Test 9: Privilege Escalation via ECALL (User -> Machine) (Day 4-5)
    // -----------------------------------------------------------------------
    println("\n[Test 9] Testing ECALL Trap Entry (User -> Machine Mode)...")
    // Trigger ECALL from User mode (Cause 8 = User ECALL, PC = 0x80002010)
    dut.io.csr_wen.poke(false.B)
    dut.io.csr_cmd.poke(0.U)
    dut.io.trap_in.valid.poke(true.B)
    dut.io.trap_in.epc.poke(BigInt("80002010", 16).U)
    dut.io.trap_in.cause.poke(8.U) // User ECALL
    dut.io.trap_in.tval.poke(0.U)
    dut.clock.step(1)
    dut.io.trap_in.valid.poke(false.B)

    // Priv mode should escalate back to M (3)
    val privAfterTrap = dut.io.priv_mode.peek().litValue
    assert(privAfterTrap == PrivMode.M.litValue, s"Expected priv_mode=M (3), got $privAfterTrap")

    // mepc should record 0x80002010, mcause should record 8
    val (mepcRead, _, _) = csrAccess(CSRAddr.mepc, 1, 0, false)
    val (mcauseRead, _, _) = csrAccess(CSRAddr.mcause, 1, 0, false)
    assert(mepcRead == BigInt("80002010", 16), f"Expected mepc=0x80002010, got 0x$mepcRead%08x")
    assert(mcauseRead == 8, s"Expected mcause=8, got $mcauseRead")
    println("  -> ECALL correctly escalated privilege to M-mode, mepc=0x80002010, mcause=8: PASS")

    // -----------------------------------------------------------------------
    // Test 10: Exception Delegation to Supervisor Mode (medeleg) (Day 4-5)
    // -----------------------------------------------------------------------
    println("\n[Test 10] Testing Exception Delegation (medeleg)...")
    // Delegate User ECALL (bit 8) to Supervisor mode via medeleg
    csrAccess(CSRAddr.medeleg, 1, BigInt(1 << 8), true)

    // Drop back to User mode via MRET
    csrAccess(CSRAddr.mstatus, 1, 0, true) // MPP = U
    dut.io.mret_valid.poke(true.B)
    dut.clock.step(1)
    dut.io.mret_valid.poke(false.B)
    assert(dut.io.priv_mode.peek().litValue == PrivMode.U.litValue)

    // Trigger User ECALL (Cause 8) again
    dut.io.trap_in.valid.poke(true.B)
    dut.io.trap_in.epc.poke(BigInt("80003000", 16).U)
    dut.io.trap_in.cause.poke(8.U)
    dut.io.trap_in.tval.poke(0.U)
    dut.clock.step(1)
    dut.io.trap_in.valid.poke(false.B)

    // With bit 8 set in medeleg, privilege should escalate to Supervisor mode (S = 1)!
    val privDelegated = dut.io.priv_mode.peek().litValue
    assert(privDelegated == PrivMode.S.litValue, s"Expected priv_mode=S (1), got $privDelegated")
    val (sepcRead, _, _) = csrAccess(CSRAddr.sepc, 1, 0, false)
    val (scauseRead, _, _) = csrAccess(CSRAddr.scause, 1, 0, false)
    assert(sepcRead == BigInt("80003000", 16), f"Expected sepc=0x80003000, got 0x$sepcRead%08x")
    assert(scauseRead == 8, s"Expected scause=8, got $scauseRead")
    println("  -> Exception successfully delegated to Supervisor Mode (priv_mode=1, sepc=0x80003000, scause=8): PASS")

    println("\n==================================================")
    println("  ALL DAY 1-5 PRIVILEGE & CSR TESTS PASSED!       ")
    println("==================================================")
  }
}
