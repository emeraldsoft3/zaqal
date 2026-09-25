package zaqal.backend.csr

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object CSRAddr {
  // User-level Floating-Point & Counters
  val fflags    = "h001".U(12.W)
  val frm       = "h002".U(12.W)
  val fcsr      = "h003".U(12.W)
  val cycle     = "hc00".U(12.W)
  val time      = "hc01".U(12.W)
  val instret   = "hc02".U(12.W)

  // Supervisor-mode CSRs
  val sstatus   = "h100".U(12.W)
  val sie       = "h104".U(12.W)
  val stvec     = "h105".U(12.W)
  val sscratch  = "h140".U(12.W)
  val sepc      = "h141".U(12.W)
  val scause    = "h142".U(12.W)
  val stval     = "h143".U(12.W)
  val sip       = "h144".U(12.W)
  val satp      = "h180".U(12.W)

  // Machine-mode CSRs
  val mstatus   = "h300".U(12.W)
  val misa      = "h301".U(12.W)
  val medeleg   = "h302".U(12.W)
  val mideleg   = "h303".U(12.W)
  val mie       = "h304".U(12.W)
  val mtvec     = "h305".U(12.W)
  val mscratch  = "h340".U(12.W)
  val mepc      = "h341".U(12.W)
  val mcause    = "h342".U(12.W)
  val mtval     = "h343".U(12.W)
  val mip       = "h344".U(12.W)

  // Identification & Machine Counters
  val mvendorid = "hf11".U(12.W)
  val marchid   = "hf12".U(12.W)
  val mimpid    = "hf13".U(12.W)
  val mhartid   = "hf14".U(12.W)
  val mcycle    = "hb00".U(12.W)
  val minstret  = "hb02".U(12.W)
}

object PrivMode {
  val U = 0.U(2.W) // User mode
  val S = 1.U(2.W) // Supervisor mode
  val M = 3.U(2.W) // Machine mode
}

class CSRFile(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Instruction Execution Interface
    val csr_addr     = Input(UInt(12.W))
    val csr_cmd      = Input(UInt(3.W))
    val csr_wdata    = Input(UInt(xLen.W))
    val csr_wen      = Input(Bool())
    val csr_rdata    = Output(UInt(xLen.W))
    val is_illegal   = Output(Bool())
    val flush_pipe   = Output(Bool()) // Asserted on state-mutating writes

    // FPU Interface
    val frm          = Output(UInt(3.W))
    val set_flags    = Input(Bool())
    val flags_to_set = Input(UInt(5.W))

    // Architectural Status Outputs (for MMU, Trap & Pipeline Control)
    val priv_mode    = Output(UInt(2.W))
    val satp_mode    = Output(UInt(4.W))
    val satp_asid    = Output(UInt(16.W))
    val satp_ppn     = Output(UInt(44.W))
    val satp_val     = Output(UInt(xLen.W))
    val mstatus_val  = Output(UInt(xLen.W))
    val stvec_val    = Output(UInt(xLen.W))
    val mtvec_val    = Output(UInt(xLen.W))
  })

  // =========================================================================
  // Architectural State Registers
  // =========================================================================
  val priv_mode = RegInit(PrivMode.M) // Resets into Machine mode

  // Machine Status: FS=1 (Initial), MPP=Machine (3)
  val r_mstatus_mie  = RegInit(false.B)
  val r_mstatus_mpie = RegInit(false.B)
  val r_mstatus_mpp  = RegInit(PrivMode.M)
  val r_mstatus_sie  = RegInit(false.B)
  val r_mstatus_spie = RegInit(false.B)
  val r_mstatus_spp  = RegInit(0.U(1.W))
  val r_mstatus_fs   = RegInit(1.U(2.W)) // 1 = Initial (FPU on)

  val mstatus_sd = (r_mstatus_fs === 3.U)
  val mstatus = Cat(
    mstatus_sd.asUInt,            // 63: SD
    0.U((63 - 15).W),             // 62:15
    r_mstatus_fs,                 // 14:13: FS
    r_mstatus_mpp,                // 12:11: MPP
    0.U(2.W),                     // 10:9
    r_mstatus_spp,                // 8: SPP
    r_mstatus_mpie.asUInt,        // 7: MPIE
    0.U(1.W),                     // 6
    r_mstatus_spie.asUInt,        // 5: SPIE
    0.U(1.W),                     // 4
    r_mstatus_mie.asUInt,         // 3: MIE
    0.U(1.W),                     // 2
    r_mstatus_sie.asUInt,         // 1: SIE
    0.U(1.W)                      // 0
  )

  // Supervisor Status Shadow Mask (SIE, SPIE, SPP, FS, SD)
  val sstatus = Cat(
    mstatus_sd.asUInt,
    0.U((63 - 15).W),
    r_mstatus_fs,
    0.U(4.W),
    r_mstatus_spp,
    0.U(2.W),
    r_mstatus_spie.asUInt,
    0.U(3.W),
    r_mstatus_sie.asUInt,
    0.U(1.W)
  )

  // MISA: RV64GC (Base I + M, A, F, D, C, S, U)
  // [63:62] = 2 (XLEN = 64)
  // [20] = U, [18] = S, [12] = M, [8] = I, [5] = F, [3] = D, [2] = C, [0] = A
  val misa_val = (BigInt(2) << 62) |
                 (1 << 20) | (1 << 18) | (1 << 12) |
                 (1 << 8)  | (1 << 5)  | (1 << 3)  |
                 (1 << 2)  | (1 << 0)
  val r_misa = misa_val.U(xLen.W)

  // Trap Vector Base Registers
  val r_mtvec = RegInit(0.U(xLen.W))
  val r_stvec = RegInit(0.U(xLen.W))

  // Exception Delegation Registers
  val r_medeleg = RegInit(0.U(xLen.W))
  val r_mideleg = RegInit(0.U(xLen.W))

  // Interrupt Enable & Pending Registers
  val r_mie = RegInit(0.U(xLen.W))
  val r_mip = RegInit(0.U(xLen.W))

  // Scratch Registers
  val r_mscratch = RegInit(0.U(xLen.W))
  val r_sscratch = RegInit(0.U(xLen.W))

  // Exception Program Counters
  val r_mepc = RegInit(0.U(xLen.W))
  val r_sepc = RegInit(0.U(xLen.W))

  // Trap Causes & Values
  val r_mcause = RegInit(0.U(xLen.W))
  val r_scause = RegInit(0.U(xLen.W))
  val r_mtval  = RegInit(0.U(xLen.W))
  val r_stval  = RegInit(0.U(xLen.W))

  // Virtual Memory: satp (MODE 63:60, ASID 59:44, PPN 43:0)
  val r_satp = RegInit(0.U(xLen.W))

  // FPU Registers
  val r_frm    = RegInit(0.U(3.W))
  val r_fflags = RegInit(0.U(5.W))

  // Performance Counters
  val r_mcycle   = RegInit(0.U(xLen.W))
  val r_minstret = RegInit(0.U(xLen.W))

  r_mcycle := r_mcycle + 1.U

  // Accumulate FPU flags from execution units
  when(io.set_flags) {
    r_fflags := r_fflags | io.flags_to_set
    r_mstatus_fs := 3.U // Mark Dirty
  }

  // =========================================================================
  // CSR Read Multiplexer
  // =========================================================================
  val rdata = WireDefault(0.U(xLen.W))

  switch(io.csr_addr) {
    // User / Floating Point
    is(CSRAddr.fflags)    { rdata := r_fflags }
    is(CSRAddr.frm)       { rdata := r_frm }
    is(CSRAddr.fcsr)      { rdata := Cat(r_frm, r_fflags) }
    is(CSRAddr.cycle)     { rdata := r_mcycle }
    is(CSRAddr.time)      { rdata := r_mcycle }
    is(CSRAddr.instret)   { rdata := r_minstret }

    // Supervisor Mode
    is(CSRAddr.sstatus)   { rdata := sstatus }
    is(CSRAddr.sie)       { rdata := r_mie & r_mideleg }
    is(CSRAddr.stvec)     { rdata := r_stvec }
    is(CSRAddr.sscratch)  { rdata := r_sscratch }
    is(CSRAddr.sepc)      { rdata := r_sepc }
    is(CSRAddr.scause)    { rdata := r_scause }
    is(CSRAddr.stval)     { rdata := r_stval }
    is(CSRAddr.sip)       { rdata := r_mip & r_mideleg }
    is(CSRAddr.satp)      { rdata := r_satp }

    // Machine Mode
    is(CSRAddr.mstatus)   { rdata := mstatus }
    is(CSRAddr.misa)      { rdata := r_misa }
    is(CSRAddr.medeleg)   { rdata := r_medeleg }
    is(CSRAddr.mideleg)   { rdata := r_mideleg }
    is(CSRAddr.mie)       { rdata := r_mie }
    is(CSRAddr.mtvec)     { rdata := r_mtvec }
    is(CSRAddr.mscratch)  { rdata := r_mscratch }
    is(CSRAddr.mepc)      { rdata := r_mepc }
    is(CSRAddr.mcause)    { rdata := r_mcause }
    is(CSRAddr.mtval)     { rdata := r_mtval }
    is(CSRAddr.mip)       { rdata := r_mip }
    is(CSRAddr.mvendorid) { rdata := 0.U }
    is(CSRAddr.marchid)   { rdata := 0.U }
    is(CSRAddr.mimpid)    { rdata := 0.U }
    is(CSRAddr.mhartid)   { rdata := 0.U }
    is(CSRAddr.mcycle)    { rdata := r_mcycle }
    is(CSRAddr.minstret)  { rdata := r_minstret }
  }

  io.csr_rdata := rdata

  // =========================================================================
  // Privilege & Access Permission Check
  // =========================================================================
  val required_priv = io.csr_addr(9, 8)
  val is_read_only  = io.csr_addr(11, 10) === "b11".U

  // Read-only CSRs fail if written. Otherwise check required privilege.
  val is_illegal_priv = priv_mode < required_priv
  val is_illegal_ro_write = io.csr_wen && is_read_only
  io.is_illegal := is_illegal_priv || is_illegal_ro_write

  // =========================================================================
  // CSR Write & Atomic Modification Logic
  // =========================================================================
  // cmd: 1=RW, 2=RS (Set), 3=RC (Clear), 5=RWI, 6=RSI, 7=RCI
  val is_set   = (io.csr_cmd === 2.U || io.csr_cmd === 6.U)
  val is_clear = (io.csr_cmd === 3.U || io.csr_cmd === 7.U)
  val is_write = (io.csr_cmd === 1.U || io.csr_cmd === 5.U)

  val wdata_eff = Mux(is_set,   rdata | io.csr_wdata,
                  Mux(is_clear, rdata & (~io.csr_wdata).asUInt,
                                io.csr_wdata))

  // For RS/RC with rs1=0, write is suppressed (pure read)
  val write_suppressed = (is_set || is_clear) && (io.csr_wdata === 0.U)
  val do_write = io.csr_wen && !write_suppressed && !io.is_illegal

  // State-mutating writes that require refetch / pipeline flush
  val is_flush_csr = (io.csr_addr === CSRAddr.satp) ||
                     (io.csr_addr === CSRAddr.mstatus) ||
                     (io.csr_addr === CSRAddr.sstatus)
  io.flush_pipe := do_write && is_flush_csr

  when(do_write) {
    switch(io.csr_addr) {
      // User / FPU
      is(CSRAddr.fflags)   { r_fflags := wdata_eff(4, 0); r_mstatus_fs := 3.U }
      is(CSRAddr.frm)      { r_frm    := wdata_eff(2, 0); r_mstatus_fs := 3.U }
      is(CSRAddr.fcsr)     {
        r_frm    := wdata_eff(7, 5)
        r_fflags := wdata_eff(4, 0)
        r_mstatus_fs := 3.U
      }

      // Supervisor CSRs
      is(CSRAddr.sstatus)  {
        r_mstatus_sie  := wdata_eff(1)
        r_mstatus_spie := wdata_eff(5)
        r_mstatus_spp  := wdata_eff(8)
        r_mstatus_fs   := wdata_eff(14, 13)
      }
      is(CSRAddr.sie)      { r_mie := (r_mie & ~r_mideleg) | (wdata_eff & r_mideleg) }
      is(CSRAddr.stvec)    { r_stvec := wdata_eff }
      is(CSRAddr.sscratch) { r_sscratch := wdata_eff }
      is(CSRAddr.sepc)     { r_sepc := wdata_eff }
      is(CSRAddr.scause)   { r_scause := wdata_eff }
      is(CSRAddr.stval)    { r_stval := wdata_eff }
      is(CSRAddr.sip)      { r_mip := (r_mip & ~r_mideleg) | (wdata_eff & r_mideleg) }
      is(CSRAddr.satp)     { r_satp := wdata_eff }

      // Machine CSRs
      is(CSRAddr.mstatus)  {
        r_mstatus_sie  := wdata_eff(1)
        r_mstatus_mie  := wdata_eff(3)
        r_mstatus_spie := wdata_eff(5)
        r_mstatus_mpie := wdata_eff(7)
        r_mstatus_spp  := wdata_eff(8)
        r_mstatus_mpp  := wdata_eff(12, 11)
        r_mstatus_fs   := wdata_eff(14, 13)
      }
      is(CSRAddr.medeleg)  { r_medeleg := wdata_eff }
      is(CSRAddr.mideleg)  { r_mideleg := wdata_eff }
      is(CSRAddr.mie)      { r_mie := wdata_eff }
      is(CSRAddr.mtvec)    { r_mtvec := wdata_eff }
      is(CSRAddr.mscratch) { r_mscratch := wdata_eff }
      is(CSRAddr.mepc)     { r_mepc := wdata_eff }
      is(CSRAddr.mcause)   { r_mcause := wdata_eff }
      is(CSRAddr.mtval)    { r_mtval := wdata_eff }
      is(CSRAddr.mip)      { r_mip := wdata_eff }
      is(CSRAddr.mcycle)   { r_mcycle := wdata_eff }
      is(CSRAddr.minstret) { r_minstret := wdata_eff }
    }
  }

  // =========================================================================
  // Global Hardware Export Outputs
  // =========================================================================
  io.frm         := r_frm
  io.priv_mode   := priv_mode
  io.satp_mode   := r_satp(63, 60)
  io.satp_asid   := r_satp(59, 44)
  io.satp_ppn    := r_satp(43, 0)
  io.satp_val    := r_satp
  io.mstatus_val := mstatus
  io.stvec_val   := r_stvec
  io.mtvec_val   := r_mtvec
}
