package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class StrideTrainBundle(val xLen: Int) extends Bundle {
  val pc   = UInt(xLen.W)
  val addr = UInt(xLen.W)
}

class PrefetchReqBundle(val xLen: Int) extends Bundle {
  val addr       = UInt(xLen.W)
  val confidence = UInt(2.W)
}

class StrideMetaBundle(val tagBits: Int, val xLen: Int) extends Bundle {
  val tag        = UInt(tagBits.W)
  val prev_addr  = UInt(xLen.W)
  val stride     = SInt(32.W)
  val confidence = UInt(2.W)
}

class StridePrefetcher(val numEntries: Int = 16, val lookaheadBlocks: Int = 2)(implicit val p: Parameters)
    extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val train        = Flipped(Valid(new StrideTrainBundle(xLen)))
    val prefetch_req = Valid(new PrefetchReqBundle(xLen))
    val flush        = Input(Bool())
  })

  val tagBits = 12
  def pcHash(pc: UInt): UInt = {
    val shifted = pc >> 2
    (shifted(tagBits - 1, 0) ^ (pc >> (tagBits + 2))(tagBits - 1, 0))
  }

  val entries = Reg(Vec(numEntries, new StrideMetaBundle(tagBits, xLen)))
  val valids  = RegInit(VecInit(Seq.fill(numEntries)(false.B)))
  val rrp     = RegInit(0.U(log2Up(numEntries).W)) // Round-robin pointer for replacement

  // Pipelined registered prefetch output for clean timing
  val pfValidReg = RegInit(false.B)
  val pfAddrReg  = RegInit(0.U(xLen.W))
  val pfConfReg  = RegInit(0.U(2.W))

  // Default registered output update
  pfValidReg := false.B

  when(io.flush) {
    for (i <- 0 until numEntries) {
      valids(i) := false.B
    }
    rrp := 0.U
    pfValidReg := false.B
  }.elsewhen(io.train.valid) {
    val trainPc = io.train.bits.pc
    val trainAddr = io.train.bits.addr
    val tag = pcHash(trainPc)

    // Lookup matching entry
    val matchVec = VecInit((0 until numEntries).map(i => valids(i) && entries(i).tag === tag))
    val hit = matchVec.asUInt.orR
    val hitIdx = PriorityEncoder(matchVec)

    when(hit) {
      val entry = entries(hitIdx)
      val newStride = (trainAddr - entry.prev_addr).asSInt
      val strideMatch = (newStride === entry.stride) && (newStride =/= 0.S)

      val nextConf = Wire(UInt(2.W))
      when(strideMatch) {
        nextConf := Mux(entry.confidence < 3.U, entry.confidence + 1.U, 3.U)
        entry.confidence := nextConf
      }.otherwise {
        nextConf := Mux(entry.confidence > 0.U, entry.confidence - 1.U, 0.U)
        entry.confidence := nextConf
        when(entry.confidence <= 1.U) {
          entry.stride := newStride
        }
      }

      entry.prev_addr := trainAddr

      // Generate prefetch if confidence >= 2 (or stride confirmed with confidence reaching 2)
      val canPrefetch = (nextConf >= 2.U) && (entry.stride =/= 0.S)
      val pfOffset = entry.stride * lookaheadBlocks.S
      val pfAddr = (trainAddr.asSInt + pfOffset).asUInt

      // Check 4KB page boundary crossing: avoid prefetching into different page
      val samePage = (trainAddr ^ pfAddr)(xLen - 1, 12) === 0.U

      when(canPrefetch && samePage) {
        val alignedPfAddr = Cat(pfAddr(xLen - 1, 5), 0.U(5.W))
        pfValidReg := true.B
        pfAddrReg  := alignedPfAddr
        pfConfReg  := nextConf
      }
    }.otherwise {
      // Allocate new entry at rrp
      val allocIdx = rrp
      valids(allocIdx) := true.B
      entries(allocIdx).tag := tag
      entries(allocIdx).prev_addr := trainAddr
      entries(allocIdx).stride := 0.S
      entries(allocIdx).confidence := 0.U

      rrp := Mux(rrp === (numEntries - 1).U, 0.U, rrp + 1.U)
    }
  }

  io.prefetch_req.valid := pfValidReg
  io.prefetch_req.bits.addr := pfAddrReg
  io.prefetch_req.bits.confidence := pfConfReg
}
