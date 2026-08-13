package zaqal.cache

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class ICache(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val pc = Input(UInt(xLen.W))
    val insts = Output(Vec(fetchWidth, UInt(instBits.W)))
    val ready = Output(Bool())
    
    // External Memory Interface (Connects to simulated RAM in testbench)
    val mem = new MemoryBus(xLen, instBits * fetchWidth)
  })

  // Basic Cache Parameters (Simplified direct-mapped for now, can be scaled later)
  val numLines = 64
  val blockBytes = (instBits / 8) * fetchWidth
  val lineBits = log2Ceil(numLines)
  val blockOffsetBits = log2Ceil(blockBytes)
  val tagBits = xLen - lineBits - blockOffsetBits

  // SRAM Arrays
  val validArray = RegInit(VecInit.fill(numLines)(false.B))
  val tagArray = Reg(Vec(numLines, UInt(tagBits.W)))
  // Each line stores 'fetchWidth' instructions
  val dataArray = Reg(Vec(numLines, Vec(fetchWidth, UInt(instBits.W))))

  // Address Decoding
  val reqIndex = io.pc(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val reqTag = io.pc(xLen - 1, lineBits + blockOffsetBits)

  // Cache Controller FSM
  val s_IDLE :: s_MISS_REQ :: s_REFILL :: Nil = Enum(3)
  val state = RegInit(s_IDLE)
  
  // Register to latch the missing PC
  val missAddress = Reg(UInt(xLen.W))
  val missIndex = missAddress(lineBits + blockOffsetBits - 1, blockOffsetBits)
  val missTag = missAddress(xLen - 1, lineBits + blockOffsetBits)

  // Hit Detection
  val isHit = validArray(reqIndex) && (tagArray(reqIndex) === reqTag)
  val readData = dataArray(reqIndex)

  // Default Outputs
  io.ready := (state === s_IDLE) && isHit
  io.insts := readData
  
  io.mem.req.valid := false.B
  io.mem.req.bits.addr := 0.U
  io.mem.req.bits.burstLen := 1.U
  io.mem.req.bits.isWrite := false.B
  io.mem.resp.ready := false.B

  // FSM Logic
  switch(state) {
    is(s_IDLE) {
      // If we have a PC but no hit, we need to fetch from memory
      when(!isHit) {
        missAddress := io.pc
        state := s_MISS_REQ
      }
    }
    is(s_MISS_REQ) {
      io.mem.req.valid := true.B
      // Align latched address to block boundary
      io.mem.req.bits.addr := Cat(missTag, missIndex, 0.U(blockOffsetBits.W))
      
      when(io.mem.req.fire) {
        state := s_REFILL
      }
    }
    is(s_REFILL) {
      io.mem.resp.ready := true.B
      
      when(io.mem.resp.fire) {
        // Refill the cache line using the latched address
        validArray(missIndex) := true.B
        tagArray(missIndex) := missTag
        // Extract individual instructions from the wide data bus
        for (i <- 0 until fetchWidth) {
          dataArray(missIndex)(i) := io.mem.resp.bits.data((i + 1) * instBits - 1, i * instBits)
        }
        
        // Go back to IDLE so the IFU can retry and get a Hit!
        state := s_IDLE
      }
    }
  }
}
