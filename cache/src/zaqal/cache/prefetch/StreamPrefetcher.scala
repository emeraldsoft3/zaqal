package zaqal.cache.prefetch

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class StreamTrainBundle(val xLen: Int) extends Bundle {
  val addr = UInt(xLen.W)
}

class StreamMetaBundle(val tagBits: Int) extends Bundle {
  val region_tag = UInt(tagBits.W)
  val bit_vec    = UInt(32.W) // 32 blocks of 32 bytes in a 1KB region
  val last_block = UInt(5.W)
  val isAscending = Bool()    // true: ascending, false: descending
  val active     = Bool()
  val count      = UInt(6.W)
}

class StreamPrefetcher(val numStreams: Int = 8, val lookaheadBlocks: Int = 2)(implicit val p: Parameters)
    extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val train        = Flipped(Valid(new StreamTrainBundle(xLen)))
    val prefetch_req = Valid(new PrefetchReqBundle(xLen))
    val flush        = Input(Bool())
  })

  val regionBits = 10 // 1024 bytes per region
  val blockBits = 5   // 32 bytes per cache block
  val tagBits = xLen - regionBits

  val streams = Reg(Vec(numStreams, new StreamMetaBundle(tagBits)))
  val valids  = RegInit(VecInit(Seq.fill(numStreams)(false.B)))
  val rrp     = RegInit(0.U(log2Up(numStreams).W))

  val pfValidReg = RegInit(false.B)
  val pfAddrReg  = RegInit(0.U(xLen.W))
  val pfConfReg  = RegInit(0.U(2.W))

  pfValidReg := false.B

  when(io.flush) {
    for (i <- 0 until numStreams) {
      valids(i) := false.B
    }
    rrp := 0.U
    pfValidReg := false.B
  }.elsewhen(io.train.valid) {
    val trainAddr = io.train.bits.addr
    val tag = trainAddr(xLen - 1, regionBits)
    val blockIdx = trainAddr(regionBits - 1, blockBits)

    val matchVec = VecInit((0 until numStreams).map(i => valids(i) && streams(i).region_tag === tag))
    val hit = matchVec.asUInt.orR
    val hitIdx = PriorityEncoder(matchVec)

    when(hit) {
      val s = streams(hitIdx)
      val blockMask = (1.U(32.W) << blockIdx)
      val isNewBlock = (s.bit_vec & blockMask) === 0.U

      s.bit_vec := s.bit_vec | blockMask

      val newCount = Mux(isNewBlock, s.count + 1.U, s.count)
      s.count := newCount

      // Detect stream direction immediately
      val newIsAscending = WireInit(s.isAscending)
      when(blockIdx > s.last_block) {
        newIsAscending := true.B
      }.elsewhen(blockIdx < s.last_block) {
        newIsAscending := false.B
      }
      s.isAscending := newIsAscending
      s.last_block := blockIdx

      // Activate stream once at least 2 distinct blocks are touched
      val willBeActive = s.active || (newCount >= 2.U)
      s.active := willBeActive

      when(willBeActive) {
        val nextPfBlock = Wire(UInt(5.W))
        val pfValid = Wire(Bool())

        when(newIsAscending) {
          // Ascending stream
          val candidate = blockIdx + lookaheadBlocks.U
          pfValid := candidate < 32.U
          nextPfBlock := candidate(4, 0)
        }.otherwise {
          // Descending stream
          val canDescend = blockIdx >= lookaheadBlocks.U
          pfValid := canDescend
          nextPfBlock := Mux(canDescend, blockIdx - lookaheadBlocks.U, 0.U)
        }

        // Only prefetch if the candidate block has not already been touched
        val targetBlockMask = (1.U(32.W) << nextPfBlock)
        val notTouchedYet = (s.bit_vec & targetBlockMask) === 0.U

        when(pfValid && notTouchedYet) {
          val pfAddr = Cat(s.region_tag, nextPfBlock, 0.U(5.W))
          pfValidReg := true.B
          pfAddrReg  := pfAddr
          pfConfReg  := 3.U // Stream prefetch has high confidence once active
        }
      }
    }.otherwise {
      // Allocate new stream entry
      val allocIdx = rrp
      valids(allocIdx) := true.B
      streams(allocIdx).region_tag := tag
      streams(allocIdx).bit_vec := (1.U(32.W) << blockIdx)
      streams(allocIdx).last_block := blockIdx
      streams(allocIdx).isAscending := true.B
      streams(allocIdx).active := false.B
      streams(allocIdx).count := 1.U

      rrp := Mux(rrp === (numStreams - 1).U, 0.U, rrp + 1.U)
    }
  }

  io.prefetch_req.valid := pfValidReg
  io.prefetch_req.bits.addr := pfAddrReg
  io.prefetch_req.bits.confidence := pfConfReg
}
