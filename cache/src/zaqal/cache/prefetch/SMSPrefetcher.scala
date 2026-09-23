package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class SMSTrainBundle(val xLen: Int) extends Bundle {
  val pc   = UInt(xLen.W)
  val addr = UInt(xLen.W)
}

class AGTEntry(val tagBits: Int, val xLen: Int) extends Bundle {
  val valid          = Bool()
  val region_tag     = UInt(tagBits.W)
  val trigger_pc     = UInt(xLen.W)
  val trigger_offset = UInt(5.W)
  val bit_vec        = UInt(32.W)
}

class PHTEntry(val tagBits: Int) extends Bundle {
  val valid      = Bool()
  val tag        = UInt(tagBits.W)
  val bit_vec    = UInt(32.W)
  val confidence = UInt(2.W)
}

class SMSPrefetcher(val numAGT: Int = 8, val numPHT: Int = 32)(implicit val p: Parameters)
    extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val train        = Flipped(Valid(new SMSTrainBundle(xLen)))
    val prefetch_req = Valid(new PrefetchReqBundle(xLen))
    val flush        = Input(Bool())
  })

  val regionBits = 10 // 1024-byte region
  val blockBits  = 5  // 32-byte block
  val tagBits    = xLen - regionBits
  val phtTagBits = 12

  def pcHash(pc: UInt): UInt = {
    val shifted = pc >> 2
    (shifted(phtTagBits - 1, 0) ^ (pc >> (phtTagBits + 2))(phtTagBits - 1, 0))
  }

  // Active Generation Table (AGT)
  val agt = Reg(Vec(numAGT, new AGTEntry(tagBits, xLen)))
  val agtRrp = RegInit(0.U(log2Up(numAGT).W))

  // Pattern History Table (PHT)
  val pht = Reg(Vec(numPHT, new PHTEntry(phtTagBits)))
  val phtRrp = RegInit(0.U(log2Up(numPHT).W))

  // Prefetch Generator State (bursting blocks from a recalled footprint)
  val pfPendingMask = RegInit(0.U(32.W))
  val pfRegionTag   = RegInit(0.U(tagBits.W))
  val pfConfReg     = RegInit(0.U(2.W))

  val pfValidReg = RegInit(false.B)
  val pfAddrReg  = RegInit(0.U(xLen.W))
  val pfOutConf  = RegInit(0.U(2.W))

  // Default registered output
  pfValidReg := false.B

  // Helper to write an evicted AGT footprint into the PHT
  def writebackToPHT(triggerPc: UInt, footprint: UInt): Unit = {
    val phtTag = pcHash(triggerPc)
    val matchVec = VecInit((0 until numPHT).map(i => pht(i).valid && pht(i).tag === phtTag))
    val hit = matchVec.asUInt.orR
    val hitIdx = PriorityEncoder(matchVec)

    when(hit) {
      val entry = pht(hitIdx)
      when(entry.bit_vec === footprint) {
        when(entry.confidence < 3.U) {
          entry.confidence := entry.confidence + 1.U
        }
      }.otherwise {
        when(entry.confidence > 0.U) {
          entry.confidence := entry.confidence - 1.U
        }
        when(entry.confidence <= 1.U) {
          entry.bit_vec := footprint
        }
      }
    }.otherwise {
      val allocIdx = phtRrp
      pht(allocIdx).valid      := true.B
      pht(allocIdx).tag        := phtTag
      pht(allocIdx).bit_vec    := footprint
      pht(allocIdx).confidence := 1.U
      phtRrp := Mux(phtRrp === (numPHT - 1).U, 0.U, phtRrp + 1.U)
    }
  }

  when(io.flush) {
    for (i <- 0 until numAGT) {
      agt(i).valid := false.B
    }
    for (i <- 0 until numPHT) {
      pht(i).valid := false.B
    }
    agtRrp := 0.U
    phtRrp := 0.U
    pfPendingMask := 0.U
    pfValidReg := false.B
  }.otherwise {
    // 1. Service pending prefetch burst from recalled PHT footprint
    when(pfPendingMask =/= 0.U) {
      val nextBlockIdx = PriorityEncoder(pfPendingMask)(4, 0)
      val nextBlockMask = (1.U(32.W) << nextBlockIdx)
      pfPendingMask := pfPendingMask & ~nextBlockMask

      val candidateAddr = Cat(pfRegionTag, nextBlockIdx, 0.U(5.W))
      pfValidReg := true.B
      pfAddrReg  := candidateAddr
      pfOutConf  := pfConfReg
    }

    // 2. Process training load access
    when(io.train.valid) {
      val trainPc   = io.train.bits.pc
      val trainAddr = io.train.bits.addr
      val regTag    = trainAddr(xLen - 1, regionBits)
      val blkOff    = trainAddr(regionBits - 1, blockBits)
      val blkMask   = (1.U(32.W) << blkOff)

      // Search AGT for active region match
      val agtMatchVec = VecInit((0 until numAGT).map(i => agt(i).valid && agt(i).region_tag === regTag))
      val agtHit = agtMatchVec.asUInt.orR
      val agtHitIdx = PriorityEncoder(agtMatchVec)

      when(agtHit) {
        // Accumulate block access in active region footprint
        agt(agtHitIdx).bit_vec := agt(agtHitIdx).bit_vec | blkMask
      }.otherwise {
        // New region entered! First, query PHT using trigger PC
        val phtTag = pcHash(trainPc)
        val phtMatchVec = VecInit((0 until numPHT).map(i => pht(i).valid && pht(i).tag === phtTag))
        val phtHit = phtMatchVec.asUInt.orR
        val phtHitIdx = PriorityEncoder(phtMatchVec)

        when(phtHit) {
          val recalledFootprint = pht(phtHitIdx).bit_vec & ~blkMask // Mask out demand block
          when(recalledFootprint =/= 0.U && pht(phtHitIdx).confidence >= 1.U) {
            val firstBlockIdx = PriorityEncoder(recalledFootprint)(4, 0)
            val firstBlockMask = (1.U(32.W) << firstBlockIdx)
            pfPendingMask := recalledFootprint & ~firstBlockMask
            pfRegionTag   := regTag
            pfConfReg     := pht(phtHitIdx).confidence

            // Immediately register the first block into the output stage with exact 5-bit width
            pfValidReg := true.B
            pfAddrReg  := Cat(regTag, firstBlockIdx, 0.U(5.W))
            pfOutConf  := pht(phtHitIdx).confidence
          }
        }

        // Second, allocate new AGT entry, evicting oldest entry if full
        val victimIdx = agtRrp
        val victim = agt(victimIdx)

        // If victim was valid and had at least 2 distinct blocks touched, write back to PHT
        when(victim.valid && PopCount(victim.bit_vec) >= 2.U) {
          writebackToPHT(victim.trigger_pc, victim.bit_vec)
        }

        // Initialize new AGT entry
        agt(victimIdx).valid          := true.B
        agt(victimIdx).region_tag     := regTag
        agt(victimIdx).trigger_pc     := trainPc
        agt(victimIdx).trigger_offset := blkOff
        agt(victimIdx).bit_vec        := blkMask

        agtRrp := Mux(agtRrp === (numAGT - 1).U, 0.U, agtRrp + 1.U)
      }
    }
  }

  io.prefetch_req.valid := pfValidReg
  io.prefetch_req.bits.addr := pfAddrReg
  io.prefetch_req.bits.confidence := pfOutConf
  io.prefetch_req.bits.sink_is_l2 := false.B
}
