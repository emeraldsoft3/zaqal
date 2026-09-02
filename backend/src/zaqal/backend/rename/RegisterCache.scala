package zaqal.backend.rename

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RegisterCache(val numEntries: Int = 32, val numReadPorts: Int = 7, val numWritePorts: Int = 5)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    // Read ports (from Issue Queue waking up / Dispatch reading operands)
    val raddr = Vec(numReadPorts, Input(UInt(phyRegIdxWidth.W)))
    val rdata = Vec(numReadPorts, Output(UInt(xLen.W)))
    val rhits = Vec(numReadPorts, Output(Bool()))

    // Write ports (from Execution Units writing back)
    val wen   = Vec(numWritePorts, Input(Bool()))
    val waddr = Vec(numWritePorts, Input(UInt(phyRegIdxWidth.W)))
    val wdata = Vec(numWritePorts, Input(UInt(xLen.W)))
    
    // Invalidate ports (from flushes)
    val flush = Input(Bool())
  })

  // Direct-mapped cache indexed by the lower bits of the physical register ID
  val indexBits = log2Ceil(numEntries)
  val tagBits = phyRegIdxWidth - indexBits
  
  // Storage
  val validArray = RegInit(VecInit(Seq.fill(numEntries)(false.B)))
  val tagArray   = Reg(Vec(numEntries, UInt(tagBits.W)))
  val dataArray  = Reg(Vec(numEntries, UInt(xLen.W)))

  // 1. Read Path
  for (i <- 0 until numReadPorts) {
    val req_addr = io.raddr(i)
    val req_idx  = req_addr(indexBits - 1, 0)
    val req_tag  = req_addr(phyRegIdxWidth - 1, indexBits)
    
    val stored_valid = validArray(req_idx)
    val stored_tag   = tagArray(req_idx)
    
    // Physical register 0 is always 0 and always hits (for integer RC)
    val is_zero_reg = req_addr === 0.U
    
    io.rhits(i) := is_zero_reg || (stored_valid && stored_tag === req_tag)
    io.rdata(i) := Mux(is_zero_reg, 0.U, dataArray(req_idx))
  }

  // 2. Write Path
  for (i <- 0 until numWritePorts) {
    when(io.wen(i) && io.waddr(i) =/= 0.U) {
      val w_idx = io.waddr(i)(indexBits - 1, 0)
      val w_tag = io.waddr(i)(phyRegIdxWidth - 1, indexBits)
      
      validArray(w_idx) := true.B
      tagArray(w_idx)   := w_tag
      dataArray(w_idx)  := io.wdata(i)
    }
  }

  // 3. Flush Path (Invalidate all entries on a branch misprediction or exception)
  // When a flush occurs, physical registers might be recycled, meaning old tags could be invalid.
  when(io.flush) {
    for (i <- 0 until numEntries) {
      validArray(i) := false.B
    }
  }
}
