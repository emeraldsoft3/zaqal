package zaqal.backend.mmu

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.backend.csr.{PrivMode, PMPChecker, PMPAccessType, PMPConfig}

object PTWAccessType {
  val FETCH = 0.U(2.W)
  val LOAD  = 1.U(2.W)
  val STORE = 2.U(2.W)
}

class PTWReq(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val vaddr       = UInt(xLen.W)
  val access_type = UInt(2.W) // 0: FETCH, 1: LOAD, 2: STORE
  val priv_mode   = UInt(2.W)
}

class PTWResp(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val vaddr        = UInt(xLen.W)
  val paddr        = UInt(xLen.W)
  val pte          = UInt(64.W)
  val level        = UInt(2.W) // 2: 1GB, 1: 2MB, 0: 4KB
  val page_fault   = Bool()
  val access_fault = Bool()
  val fault_cause  = UInt(6.W)
}

class PageTableWalker(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // TLB Miss Request / Refill Handshake
    val req         = Flipped(Decoupled(new PTWReq))
    val resp        = Valid(new PTWResp)

    // CSR State
    val satp_mode   = Input(UInt(4.W))   // 0: Bare, 8: Sv39
    val satp_asid   = Input(UInt(16.W))
    val satp_ppn    = Input(UInt(44.W))  // Root page table base PPN
    val sstatus_sum = Input(Bool())      // Permit Supervisor User Memory access
    val sstatus_mxr = Input(Bool())      // Make Executable Readable
    val priv_mode   = Input(UInt(2.W))

    // PMP Configuration
    val pmpcfg      = Input(Vec(16, new PMPConfig))
    val pmpaddr     = Input(Vec(16, UInt(xLen.W)))

    // Memory Master Channel (for walking page tables in memory)
    val mem_req     = Decoupled(UInt(xLen.W))
    val mem_resp    = Flipped(Valid(UInt(64.W)))

    // Flush / Invalidation
    val flush       = Input(Bool())

    // Debug signals for GTKWave waveform analysis
    val debug_state            = Output(UInt(3.W))
    val debug_level            = Output(UInt(2.W))
    val debug_pte_addr         = Output(UInt(xLen.W))
    val debug_pte_data         = Output(UInt(64.W))
    val debug_translated_paddr = Output(UInt(xLen.W))
    val debug_page_fault       = Output(Bool())
    val debug_access_fault     = Output(Bool())
  })

  // ---------------- FSM State Definitions ----------------
  val s_IDLE :: s_ADDR_CHECK :: s_PMP_CHECK :: s_MEM_REQ :: s_MEM_WAIT :: s_CHECK_PTE :: s_REFILL :: s_FAULT :: Nil = Enum(8)
  val state = RegInit(s_IDLE)

  // Request latches
  val req_vaddr       = Reg(UInt(xLen.W))
  val req_access_type = Reg(UInt(2.W))
  val req_priv_mode   = Reg(UInt(2.W))

  // Radix-tree traversal registers
  val curr_level      = RegInit(2.U(2.W)) // Sv39 starts at Level 2
  val curr_ppn        = Reg(UInt(44.W))
  val pte_reg         = Reg(UInt(64.W))
  val fault_is_page   = RegInit(false.B)
  val fault_is_access = RegInit(false.B)
  val fault_cause_reg = RegInit(0.U(6.W))
  val translated_paddr= RegInit(0.U(xLen.W))

  // ---------------- PMP Checker for Page Table Loads ----------------
  val pmpChecker = Module(new PMPChecker(16))
  val pte_addr_wire = Wire(UInt(xLen.W))

  // VPN extraction for Sv39 (9 bits per level)
  val vpn_segments = VecInit(Seq(
    req_vaddr(20, 12), // Level 0 (4KB)
    req_vaddr(29, 21), // Level 1 (2MB)
    req_vaddr(38, 30)  // Level 2 (1GB)
  ))
  val curr_vpn = vpn_segments(curr_level)

  // RISC-V Sv39 PTE Address: (PPN << 12) + (VPN[level] * 8)
  pte_addr_wire := Cat(curr_ppn(43, 0), curr_vpn, 0.U(3.W))

  pmpChecker.io.addr        := pte_addr_wire
  pmpChecker.io.access_type := PMPAccessType.LOAD // PTE reads are supervisor loads
  pmpChecker.io.priv_mode   := PrivMode.S         // PTE memory walk always uses S-mode privilege
  pmpChecker.io.pmpcfg      := io.pmpcfg
  pmpChecker.io.pmpaddr     := io.pmpaddr

  // ---------------- Canonical Address Verification ----------------
  // In Sv39, bits [63:38] must be all equal to bit 38 (sign extension)
  val canonical_ok = (req_vaddr(63, 38) === Fill(26, req_vaddr(38)))

  // ---------------- PTE Fields Decomposition ----------------
  val pte_v    = pte_reg(0)
  val pte_r    = pte_reg(1)
  val pte_w    = pte_reg(2)
  val pte_x    = pte_reg(3)
  val pte_u    = pte_reg(4)
  val pte_g    = pte_reg(5)
  val pte_a    = pte_reg(6)
  val pte_d    = pte_reg(7)
  val pte_rsw  = pte_reg(9, 8)
  val pte_ppn  = pte_reg(53, 10)
  val pte_res  = pte_reg(63, 54)

  val is_leaf = (pte_r || pte_x) && pte_v
  val is_ptr  = (!pte_r && !pte_w && !pte_x) && pte_v

  // Exception Causes
  val cause_page_fault = MuxCase(13.U(6.W), Seq(
    (req_access_type === PTWAccessType.FETCH) -> 12.U(6.W), // Instruction Page Fault
    (req_access_type === PTWAccessType.LOAD)  -> 13.U(6.W), // Load Page Fault
    (req_access_type === PTWAccessType.STORE) -> 15.U(6.W)  // Store/AMO Page Fault
  ))

  val cause_access_fault = MuxCase(5.U(6.W), Seq(
    (req_access_type === PTWAccessType.FETCH) -> 1.U(6.W),  // Instruction Access Fault
    (req_access_type === PTWAccessType.LOAD)  -> 5.U(6.W),  // Load Access Fault
    (req_access_type === PTWAccessType.STORE) -> 7.U(6.W)  // Store/AMO Access Fault
  ))

  // Default IO handshakes
  io.req.ready     := (state === s_IDLE)
  io.mem_req.valid := (state === s_MEM_REQ)
  io.mem_req.bits  := pte_addr_wire

  io.resp.valid             := (state === s_REFILL) || (state === s_FAULT)
  io.resp.bits.vaddr        := req_vaddr
  io.resp.bits.paddr        := translated_paddr
  io.resp.bits.pte          := pte_reg
  io.resp.bits.level        := curr_level
  io.resp.bits.page_fault   := fault_is_page
  io.resp.bits.access_fault := fault_is_access
  io.resp.bits.fault_cause  := fault_cause_reg

  // Debug Ports
  io.debug_state            := state.asUInt
  io.debug_level            := curr_level
  io.debug_pte_addr         := pte_addr_wire
  io.debug_pte_data         := pte_reg
  io.debug_translated_paddr := translated_paddr
  io.debug_page_fault       := fault_is_page
  io.debug_access_fault     := fault_is_access

  // ---------------- State Machine Transitions ----------------
  switch(state) {
    is(s_IDLE) {
      when(io.req.fire) {
        req_vaddr       := io.req.bits.vaddr
        req_access_type := io.req.bits.access_type
        req_priv_mode   := io.req.bits.priv_mode
        curr_level      := 2.U
        curr_ppn        := io.satp_ppn
        fault_is_page   := false.B
        fault_is_access := false.B
        state           := s_ADDR_CHECK
      }
    }

    is(s_ADDR_CHECK) {
      // If address translation is disabled (Bare) or canonical check fails
      when(io.satp_mode =/= 8.U) {
        // Direct identity map / passthrough when Bare mode
        translated_paddr := req_vaddr
        state            := s_REFILL
      }.elsewhen(!canonical_ok) {
        // Non-canonical virtual address generates page fault
        fault_is_page   := true.B
        fault_cause_reg := cause_page_fault
        state           := s_FAULT
      }.otherwise {
        state := s_PMP_CHECK
      }
    }

    is(s_PMP_CHECK) {
      when(pmpChecker.io.fault) {
        // PMP check failure on page table directory access
        fault_is_access := true.B
        fault_cause_reg := cause_access_fault
        state           := s_FAULT
      }.otherwise {
        state := s_MEM_REQ
      }
    }

    is(s_MEM_REQ) {
      when(io.mem_req.fire) {
        state := s_MEM_WAIT
      }
    }

    is(s_MEM_WAIT) {
      when(io.mem_resp.valid) {
        pte_reg := io.mem_resp.bits
        state   := s_CHECK_PTE
      }
    }

    is(s_CHECK_PTE) {
      // Structural validity check
      val malformed_pte = (!pte_v) || (!pte_r && pte_w) || (pte_res =/= 0.U)

      when(malformed_pte) {
        fault_is_page   := true.B
        fault_cause_reg := cause_page_fault
        state           := s_FAULT
      }.elsewhen(is_ptr) {
        // Pointer to next-level page directory
        when(curr_level === 0.U) {
          // Cannot have pointer at level 0
          fault_is_page   := true.B
          fault_cause_reg := cause_page_fault
          state           := s_FAULT
        }.otherwise {
          // Step down one level
          curr_level := curr_level - 1.U
          curr_ppn   := pte_ppn
          state      := s_PMP_CHECK
        }
      }.elsewhen(is_leaf) {
        // Leaf Page Table Entry reached!
        // 1. Superpage alignment check
        val unaligned_superpage = (curr_level === 2.U && (pte_ppn(17, 0) =/= 0.U)) ||
                                  (curr_level === 1.U && (pte_ppn(8, 0)  =/= 0.U))

        // 2. Privilege protection check
        val priv_fault = Mux(req_priv_mode === PrivMode.U,
          !pte_u,                   // User mode cannot access supervisor pages (U=0)
          pte_u && !io.sstatus_sum  // Supervisor cannot access user pages (U=1) unless SUM=1
        )

        // 3. Access permission check
        val op_fault = MuxCase(false.B, Seq(
          (req_access_type === PTWAccessType.FETCH) -> !pte_x,
          (req_access_type === PTWAccessType.LOAD)  -> !(pte_r || (io.sstatus_mxr && pte_x)),
          (req_access_type === PTWAccessType.STORE) -> !pte_w
        ))

        // 4. Accessed & Dirty bit check (software managed A/D)
        val ad_fault = !pte_a || (req_access_type === PTWAccessType.STORE && !pte_d)

        val has_page_fault = unaligned_superpage || priv_fault || op_fault || ad_fault

        when(has_page_fault) {
          fault_is_page   := true.B
          fault_cause_reg := cause_page_fault
          state           := s_FAULT
        }.otherwise {
          // Compute final physical address based on page granularity
          val paddr_out = Wire(UInt(xLen.W))
          when(curr_level === 2.U) {
            // 1 GiB Gigapage: PPN[2] + VA[29:0]
            paddr_out := Cat(pte_ppn(43, 18), req_vaddr(29, 0))
          }.elsewhen(curr_level === 1.U) {
            // 2 MiB Megapage: PPN[2:1] + VA[20:0]
            paddr_out := Cat(pte_ppn(43, 9), req_vaddr(20, 0))
          }.otherwise {
            // 4 KiB Standard page: PPN[2:0] + VA[11:0]
            paddr_out := Cat(pte_ppn(43, 0), req_vaddr(11, 0))
          }

          translated_paddr := paddr_out
          state            := s_REFILL
        }
      }.otherwise {
        fault_is_page   := true.B
        fault_cause_reg := cause_page_fault
        state           := s_FAULT
      }
    }

    is(s_REFILL) {
      state := s_IDLE
    }

    is(s_FAULT) {
      state := s_IDLE
    }
  }

  // Pipeline flush overrides everything and resets FSM to IDLE
  when(io.flush) {
    state           := s_IDLE
    curr_level      := 2.U
    fault_is_page   := false.B
    fault_is_access := false.B
  }
}
