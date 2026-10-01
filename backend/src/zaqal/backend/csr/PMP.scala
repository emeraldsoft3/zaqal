package zaqal.backend.csr

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

object PMPAccessType {
  val FETCH = 0.U(2.W)
  val LOAD  = 1.U(2.W)
  val STORE = 2.U(2.W)
}

object PMPMode {
  val OFF   = 0.U(2.W)
  val TOR   = 1.U(2.W) // Top of Range
  val NA4   = 2.U(2.W) // Naturally aligned 4-byte
  val NAPOT = 3.U(2.W) // Naturally aligned power-of-two
}

class PMPConfig extends Bundle {
  val l = Bool()      // Bit 7: Lock bit
  val reserved = UInt(2.W) // Bits 6:5
  val a = UInt(2.W)   // Bits 4:3: Address matching mode
  val x = Bool()      // Bit 2: Execute
  val w = Bool()      // Bit 1: Write
  val r = Bool()      // Bit 0: Read
}

class PMPChecker(numEntries: Int = 16)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val addr        = Input(UInt(xLen.W))
    val access_type = Input(UInt(2.W)) // 0: FETCH, 1: LOAD, 2: STORE
    val priv_mode   = Input(UInt(2.W)) // 0: U, 1: S, 3: M

    val pmpcfg      = Input(Vec(numEntries, new PMPConfig))
    val pmpaddr     = Input(Vec(numEntries, UInt(xLen.W)))

    val fault       = Output(Bool())
  })

  val matches = Wire(Vec(numEntries, Bool()))
  val allowed = Wire(Vec(numEntries, Bool()))

  for (i <- 0 until numEntries) {
    val cfg = io.pmpcfg(i)
    val cur_addr = io.pmpaddr(i)
    val prev_addr = if (i == 0) 0.U(xLen.W) else io.pmpaddr(i - 1)

    // 1. Address Match Logic
    // TOR (Top of Range): prev_addr <= addr < cur_addr
    val is_tor = cfg.a === PMPMode.TOR
    val tor_match = (io.addr >= (prev_addr << 2)) && (io.addr < (cur_addr << 2))

    // NA4: Naturally aligned 4-byte slice
    val is_na4 = cfg.a === PMPMode.NA4
    val na4_match = (io.addr >> 2) === cur_addr(xLen - 3, 0)

    // NAPOT: Naturally aligned power-of-two
    // Trailing 1s in pmpaddr define block size:
    // ...0 -> 8-byte block
    // ...01 -> 16-byte block
    // ...011 -> 32-byte block
    val is_napot = cfg.a === PMPMode.NAPOT
    val trailing_ones = PriorityEncoder(~cur_addr)
    val napot_mask = ~(((1.U << (trailing_ones + 3.U)) - 1.U).asUInt)
    val napot_match = ((io.addr & napot_mask) === ((cur_addr << 2) & napot_mask))

    matches(i) := (cfg.a =/= PMPMode.OFF) && Mux(is_tor, tor_match,
                  Mux(is_na4, na4_match,
                  Mux(is_napot, napot_match, false.B)))

    // 2. Permission Evaluation
    val has_perm = MuxLookup(io.access_type, false.B)(Seq(
      PMPAccessType.FETCH -> cfg.x,
      PMPAccessType.LOAD  -> cfg.r,
      PMPAccessType.STORE -> cfg.w
    ))

    // Machine mode bypasses checks if Lock bit is 0
    val m_mode_bypass = (io.priv_mode === PrivMode.M) && !cfg.l
    allowed(i) := m_mode_bypass || has_perm
  }

  // 3. Priority Evaluation: Lowest numbered matching entry wins
  val any_match = matches.asUInt.orR
  val hit_idx = PriorityEncoder(matches.asUInt)
  val hit_allowed = allowed(hit_idx)

  // Default rule:
  // When at least one PMP entry is configured, default-deny applies to S/U modes.
  // When no PMP entries are enabled yet (pre-boot), non-M modes default to allowed.
  val any_pmp_enabled = io.pmpcfg.map(_.a =/= PMPMode.OFF).reduce(_ || _)
  val default_allowed = (io.priv_mode === PrivMode.M) || !any_pmp_enabled

  io.fault := Mux(any_match, !hit_allowed, !default_allowed)
}
