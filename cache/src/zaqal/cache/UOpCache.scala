package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class UOpCacheReadReq(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc = UInt(xLen.W)
}

class UOpCacheData(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc           = Vec(predictWidth, UInt(xLen.W))
  val instructions = Vec(predictWidth, UInt(instBits.W))
  val pre_decoded  = Vec(predictWidth, new PreDecodeSignals)
  val mask         = UInt(predictWidth.W)
  val exception_type = Vec(predictWidth, UInt(2.W))
}

class UOpCacheReadResp(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val hit = Bool()
  val data = new UOpCacheData
}

class UOpCacheWriteReq(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  val pc = UInt(xLen.W)
  val data = new UOpCacheData
}

class UOpCache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val read = new Bundle {
      val req = Flipped(Valid(new UOpCacheReadReq))
      val resp = Output(new UOpCacheReadResp)
    }
    val write = new Bundle {
      val req = Flipped(Valid(new UOpCacheWriteReq))
    }
    val flush = Input(Bool())
  })

  // Set-Associative arrays: [Way][Set]
  val tags  = RegInit(VecInit.fill(uopCacheWays)(VecInit.fill(uopCacheSets)(0.U(xLen.W))))
  val valid = RegInit(VecInit.fill(uopCacheWays)(VecInit.fill(uopCacheSets)(false.B)))
  val data  = Reg(Vec(uopCacheWays, Vec(uopCacheSets, new UOpCacheData)))
  
  // Simple FIFO/Round-Robin replacement state (one counter per set)
  val repl_way = RegInit(VecInit.fill(uopCacheSets)(0.U(log2Ceil(uopCacheWays).W)))

  // Read logic
  val setIdxWidth = log2Ceil(uopCacheSets)
  val readIdx = io.read.req.bits.pc(setIdxWidth + 1, 2)
  val readTag = io.read.req.bits.pc

  // Check all ways for a hit
  val hits = VecInit((0 until uopCacheWays).map { w =>
    valid(w)(readIdx) && (tags(w)(readIdx) === readTag)
  })
  
  val hit = hits.asUInt.orR
  
  // Data read mux
  val hitWay = OHToUInt(hits)
  
  io.read.resp.hit := io.read.req.valid && hit
  io.read.resp.data := data(hitWay)(readIdx)

  // Write logic
  when(io.write.req.valid) {
    val writeIdx = io.write.req.bits.pc(setIdxWidth + 1, 2)
    
    // Choose allocation way: first invalid way, or repl_way if all valid
    val invalidWays = VecInit((0 until uopCacheWays).map(w => !valid(w)(writeIdx)))
    val hasInvalid = invalidWays.asUInt.orR
    val allocWay = Mux(hasInvalid, PriorityEncoder(invalidWays), repl_way(writeIdx))
    
    tags(allocWay)(writeIdx) := io.write.req.bits.pc
    valid(allocWay)(writeIdx) := true.B
    data(allocWay)(writeIdx) := io.write.req.bits.data
    
    // Update replacement counter
    repl_way(writeIdx) := repl_way(writeIdx) + 1.U
  }

  // Flush logic
  when(io.flush) {
    for (w <- 0 until uopCacheWays) {
      valid(w).foreach(_ := false.B)
    }
  }
}
