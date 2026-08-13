package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class MSHR(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val alloc = Flipped(Decoupled(new Bundle {
      val addr = UInt(xLen.W)
      val load_id = UInt(6.W) // ID of the load instruction
    }))
    val mem_req = Decoupled(new MemoryBusReq(xLen))
    val mem_resp = Flipped(Decoupled(new MemoryBusResp(256)))
    val refill_out = Decoupled(new Bundle {
      val addr = UInt(xLen.W)
      val data = UInt(256.W) // Full cache line
      val load_id = UInt(6.W)
    })
  })

  val s_IDLE :: s_WAIT_MEM :: s_REFILL :: Nil = Enum(3)
  val state = RegInit(s_IDLE)

  val reqAddr = Reg(UInt(xLen.W))
  val reqLoadId = Reg(UInt(6.W))
  val refillData = Reg(UInt(256.W))

  // Allocation
  io.alloc.ready := (state === s_IDLE)
  when(io.alloc.fire) {
    reqAddr := io.alloc.bits.addr
    reqLoadId := io.alloc.bits.load_id
    state := s_WAIT_MEM
  }

  // Memory Request
  io.mem_req.valid := (state === s_WAIT_MEM)
  io.mem_req.bits.addr := reqAddr
  io.mem_req.bits.burstLen := 1.U
  io.mem_req.bits.isWrite := false.B
  
  when(io.mem_req.fire) {
    // Already sent to memory, just wait for response (in reality, mem_req could be decoupled from WAIT_MEM)
  }

  // Memory Response
  io.mem_resp.ready := (state === s_WAIT_MEM)
  when(io.mem_resp.fire) {
    refillData := io.mem_resp.bits.data
    state := s_REFILL
  }

  // Refill Cache & Wakeup LSU
  io.refill_out.valid := (state === s_REFILL)
  io.refill_out.bits.addr := reqAddr
  io.refill_out.bits.data := refillData
  io.refill_out.bits.load_id := reqLoadId

  when(io.refill_out.fire) {
    state := s_IDLE
  }
}
