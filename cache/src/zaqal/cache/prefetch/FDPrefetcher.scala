package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class FDPTrainBundle(val xLen: Int) extends Bundle {
  val pc   = UInt(xLen.W)
  val addr = UInt(xLen.W)
}

class BDTEntry(val tagBits: Int, val xLen: Int) extends Bundle {
  val branch_tag     = UInt(tagBits.W)
  val target_tag     = UInt(tagBits.W)
  val last_data_addr = UInt(xLen.W)
  val stride         = SInt(32.W)
  val confidence     = UInt(2.W)
}

/**
  * Frontend Data Prefetcher (FDP)
  * Day 32-33: Uses early branch prediction signals (from BPU/FTQ) to prefetch
  * data cache lines into L1-D tens of cycles before backend load execution.
  *
  * Correlates branch PCs and branch target PCs with memory reference patterns.
  * When a branch is predicted taken, the Branch-to-Data Table (BDT) issues an early
  * speculative prefetch request for the next iteration's data block.
  */
class FDPrefetcher(val numEntries: Int = 16)(implicit val p: Parameters)
    extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Frontend branch prediction signal (BPU / FTQ)
    val branch_signal = Input(Valid(new BranchPredictionBus))
    // Backend load execution training (LSU / Commit)
    val train         = Flipped(Valid(new FDPTrainBundle(xLen)))
    // Speculative prefetch request to L1-D prefetch queue
    val prefetch_req  = Valid(new PrefetchReqBundle(xLen))
    // Pipeline redirect / misprediction flush
    val flush         = Input(Bool())
  })

  val tagBits = 12
  def pcHash(pc: UInt): UInt = {
    val shifted = pc >> 2
    (shifted(tagBits - 1, 0) ^ (pc >> (tagBits + 2))(tagBits - 1, 0))
  }

  val entries = Reg(Vec(numEntries, new BDTEntry(tagBits, xLen)))
  val valids  = RegInit(VecInit(Seq.fill(numEntries)(false.B)))
  val rrp     = RegInit(0.U(log2Up(numEntries).W))

  // Branch tracking to associate loads with preceding branches
  val last_branch_pc     = RegInit(0.U(xLen.W))
  val last_branch_target = RegInit(0.U(xLen.W))
  val has_recent_branch  = RegInit(false.B)

  when(io.branch_signal.valid && io.branch_signal.bits.taken) {
    last_branch_pc     := io.branch_signal.bits.pc
    last_branch_target := io.branch_signal.bits.target
    has_recent_branch  := true.B
  }

  // Registered prefetch output for clean timing
  val pfValidReg = RegInit(false.B)
  val pfAddrReg  = RegInit(0.U(xLen.W))
  val pfConfReg  = RegInit(0.U(2.W))

  pfValidReg := false.B

  // -------------------------------------------------------------
  // 1. FRONTEND LOOKUP & SPECULATIVE PREFETCH GENERATION
  // -------------------------------------------------------------
  when(io.branch_signal.valid && io.branch_signal.bits.taken) {
    val brTag     = pcHash(io.branch_signal.bits.pc)
    val targetTag = pcHash(io.branch_signal.bits.target)

    val matchVec = VecInit((0 until numEntries).map { i =>
      valids(i) && (entries(i).branch_tag === brTag ||
                    entries(i).target_tag === targetTag ||
                    entries(i).branch_tag === targetTag)
    })
    val hit    = matchVec.asUInt.orR
    val hitIdx = PriorityEncoder(matchVec)

    when(hit) {
      val entry = entries(hitIdx)
      // Only prefetch if confidence >= 2 (confident or steady-state)
      when(entry.confidence >= 2.U && entry.stride =/= 0.S) {
        val nextAddr = (entry.last_data_addr.asSInt + entry.stride).asUInt
        // Cache block alignment (32 bytes = 5 offset bits)
        val blockAlignedAddr = Cat(nextAddr(xLen - 1, 5), 0.U(5.W))

        pfValidReg := true.B
        pfAddrReg  := blockAlignedAddr
        pfConfReg  := entry.confidence

        // Advance last_data_addr optimistically for consecutive loop iterations
        entry.last_data_addr := nextAddr
      }
    }
  }

  // -------------------------------------------------------------
  // 2. BACKEND TRAINING (LSU / Commit Load Address Association)
  // -------------------------------------------------------------
  when(io.train.valid) {
    val trainTag = pcHash(io.train.bits.pc)

    val matchVec = VecInit((0 until numEntries).map { i =>
      valids(i) && (entries(i).branch_tag === trainTag ||
                    entries(i).target_tag === trainTag ||
                    (has_recent_branch && (entries(i).branch_tag === pcHash(last_branch_pc) ||
                                           entries(i).target_tag === pcHash(last_branch_target))))
    })
    val hit    = matchVec.asUInt.orR
    val hitIdx = PriorityEncoder(matchVec)

    when(hit) {
      val entry = entries(hitIdx)
      val newStride = (io.train.bits.addr.asSInt - entry.last_data_addr.asSInt)(31, 0).asSInt

      when(entry.stride =/= 0.S && newStride === entry.stride) {
        // Stride confirmed: increment confidence counter up to 3
        entry.confidence := Mux(entry.confidence === 3.U, 3.U, entry.confidence + 1.U)
      }.elsewhen(entry.stride === 0.S && newStride =/= 0.S) {
        // First stride learned: initialize stride and start confidence at 1
        entry.stride     := newStride
        entry.confidence := 1.U
      }.otherwise {
        // Stride mismatch: adjust confidence or update stride
        when(entry.confidence <= 1.U) {
          entry.stride := newStride
        }.otherwise {
          entry.confidence := entry.confidence - 1.U
        }
      }
      entry.last_data_addr := io.train.bits.addr
    }.otherwise {
      // Allocate new entry using round-robin or first free entry
      val hasFree = !valids.asUInt.andR
      val allocIdx = Mux(hasFree, PriorityEncoder(~valids.asUInt), rrp)

      when(!hasFree) {
        rrp := Mux(rrp === (numEntries - 1).U, 0.U, rrp + 1.U)
      }

      valids(allocIdx) := true.B
      when(has_recent_branch) {
        entries(allocIdx).branch_tag := pcHash(last_branch_pc)
        entries(allocIdx).target_tag := pcHash(last_branch_target)
      }.otherwise {
        entries(allocIdx).branch_tag := trainTag
        entries(allocIdx).target_tag := trainTag
      }
      entries(allocIdx).last_data_addr := io.train.bits.addr
      entries(allocIdx).stride         := 0.S
      entries(allocIdx).confidence     := 0.U
    }
  }

  // -------------------------------------------------------------
  // 3. SPECULATION RECOVERY & FLUSH
  // -------------------------------------------------------------
  when(io.flush) {
    pfValidReg        := false.B
    has_recent_branch := false.B
  }

  io.prefetch_req.valid           := pfValidReg && !io.flush
  io.prefetch_req.bits.addr       := pfAddrReg
  io.prefetch_req.bits.confidence := pfConfReg
  io.prefetch_req.bits.sink_is_l2 := false.B
}
