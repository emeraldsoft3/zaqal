package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class DCache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new Bundle {
      val addr = UInt(xLen.W)
      val data = UInt(xLen.W)
      val is_write = Bool()
      val load_id = UInt(6.W)
    }))
    val resp = Decoupled(new Bundle {
      val data = UInt(xLen.W)
      val load_id = UInt(6.W)
    })
    val mem = new MemoryBus(xLen, 256)
  })

  // Basic Cache Parameters (Direct Mapped for simplicity initially)
  val numSets = 64
  val lineBits = log2Ceil(numSets)
  val blockOffsetBits = 5 // 32 bytes = 256 bits

  val validArray = RegInit(VecInit(Seq.fill(numSets)(false.B)))
  val dirtyArray = RegInit(VecInit(Seq.fill(numSets)(false.B)))
  val tagArray = RegInit(VecInit(Seq.fill(numSets)(0.U((xLen - lineBits - blockOffsetBits).W))))
  val dataArray = RegInit(VecInit(Seq.fill(numSets)(VecInit(Seq.fill(8)(0.U(32.W))))))

  // Decode Address
  val reqIndex = io.req.bits.addr(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val reqTag = io.req.bits.addr(xLen - 1, lineBits + blockOffsetBits)
  val reqWordOffset = io.req.bits.addr(blockOffsetBits - 1, 2)

  // Hit Logic
  val isHit = validArray(reqIndex) && (tagArray(reqIndex) === reqTag)
  
  // MSHR Integration
  val mshr = Module(new MSHR)
  mshr.io.mem_req <> io.mem.req
  mshr.io.mem_resp <> io.mem.resp

  // Defaults
  io.req.ready := false.B
  io.resp.valid := false.B
  io.resp.bits.data := 0.U
  io.resp.bits.load_id := 0.U
  mshr.io.alloc.valid := false.B
  mshr.io.alloc.bits.addr := io.req.bits.addr
  mshr.io.alloc.bits.load_id := io.req.bits.load_id
  mshr.io.refill_out.ready := true.B

  // Pipeline Logic
  when(io.req.valid) {
    when(isHit) {
      io.req.ready := true.B
      when(io.req.bits.is_write) {
        dataArray(reqIndex)(reqWordOffset) := io.req.bits.data
        dirtyArray(reqIndex) := true.B
      } .otherwise {
        io.resp.valid := true.B
        io.resp.bits.data := dataArray(reqIndex)(reqWordOffset)
        io.resp.bits.load_id := io.req.bits.load_id
      }
    } .otherwise {
      // Miss - Allocate MSHR
      io.req.ready := mshr.io.alloc.ready
      mshr.io.alloc.valid := true.B
    }
  }

  // Refill Handling
  when(mshr.io.refill_out.fire) {
    val refillIndex = mshr.io.refill_out.bits.addr(lineBits + blockOffsetBits - 1, blockOffsetBits)
    val refillTag = mshr.io.refill_out.bits.addr(xLen - 1, lineBits + blockOffsetBits)
    
    validArray(refillIndex) := true.B
    tagArray(refillIndex) := refillTag
    dirtyArray(refillIndex) := false.B
    
    for (i <- 0 until 8) {
      dataArray(refillIndex)(i) := mshr.io.refill_out.bits.data((i + 1) * 32 - 1, i * 32)
    }

    // Wakeup LSU via resp
    io.resp.valid := true.B
    val wordOffset = mshr.io.refill_out.bits.addr(blockOffsetBits - 1, 2)
    io.resp.bits.data := mshr.io.refill_out.bits.data >> (wordOffset * 32.U)
    io.resp.bits.load_id := mshr.io.refill_out.bits.load_id
  }
}
