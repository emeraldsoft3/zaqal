package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.utility.SkidBuffer

class Frontend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect     = Input(new BPURedirect)
    val dispatch     = Vec(decodeWidth, Decoupled(new MicroOp)) // Output to Backend (6-wide)
    
    // Backend access to FTQ (XiangShan style)
    val ftq_read_ptr  = Input(UInt(ftqPtrWidth.W))
    val ftq_read_data = Output(new FetchPacket)

    // Debug ports
    val debug_ftq_valid       = Output(Bool())
    val debug_ftq_flush       = Output(Bool())
    val debug_ftq_pc          = Output(UInt(xLen.W))
    val debug_ftq_mask        = Output(UInt(fetchWidth.W))
    val debug_ftq_ready       = Output(Bool())
    val debug_ftq_pred_target = Output(UInt(xLen.W))
    val debug_ftq_pred_taken  = Output(Bool())
    val debug_ftq_pred_slot   = Output(UInt(log2Up(fetchWidth).W))

    val debug_ftq_occupancy = Output(UInt((ftqPtrWidth + 1).W))
    val debug_ftq_insts     = Output(Vec(fetchWidth, UInt(instBits.W)))
  })

  // 1. Instantiate the sub-modules
  val bpu  = Module(new BPU)
  val ftq  = Module(new FTQ)
  val ifu  = Module(new IFU)
  val icache = Module(new ICache)
  val ibuf = Module(new IBUF)

  // Epoch Check Reg
  val fetch_epoch = RegInit(false.B)
  val is_valid_redirect = io.redirect.valid && (io.redirect.epoch === fetch_epoch)

  when(is_valid_redirect) {
    fetch_epoch := ~fetch_epoch
    printf(p"FRONTEND FLUSH: epoch=$fetch_epoch io.redirect.target=${Hexadecimal(io.redirect.target)}\n")
  }
  
  // 1. BPU -> FTQ (Prediction Path - Buffered!)
  val bpu_out_buffered = SkidBuffer(bpu.io.out, is_valid_redirect)
  ftq.io.fromBpu.valid        := bpu_out_buffered.valid
  bpu_out_buffered.ready      := ftq.io.fromBpu.ready
  ftq.io.fromBpu.bits         := bpu_out_buffered.bits
  ftq.io.fromBpu.bits.epoch    := fetch_epoch

  // 2. FTQ -> IFU and ICache (Fetch Request Path - Buffered!)
  val ftq_to_ifu_buffered = SkidBuffer(ftq.io.toIfu, is_valid_redirect)
  
  // Lock-step Handshake: Fire only if both are ready
  // ftq.io.toIfu.ready should be driven by the buffer's ready
  // and we also need to inform ICache.
  ftq_to_ifu_buffered.ready := ifu.io.fetch_req.ready && icache.io.ready
  ftq.io.toICache.ready      := ftq_to_ifu_buffered.ready

  ifu.io.fetch_req.valid := ftq_to_ifu_buffered.valid && icache.io.ready
  ifu.io.fetch_req.bits  := ftq_to_ifu_buffered.bits

  icache.io.pc := ftq_to_ifu_buffered.bits.pc

  // 3. ICache -> IFU (Instruction Data Path)
  ifu.io.icache_ready := icache.io.ready
  ifu.io.insts_in     := icache.io.insts

  // 4. IFU -> IBUF (Data Path - Buffered!)
  ibuf.io.inst_data <> SkidBuffer(ifu.io.toIbuffer, is_valid_redirect)

  // 5. IBUF -> Backend (Dispatch Path - Pipelined Staging Boundary!)
  // We instantiate the SkidBuffers manually to enforce contiguous dequeue from IBUF.
  val ibuf_skids = Seq.fill(decodeWidth)(Module(new SkidBuffer(new MicroOp)))
  val ibuf_out_ready = Wire(Vec(decodeWidth, Bool()))

  ibuf_out_ready(0) := ibuf_skids(0).io.enq.ready
  for (i <- 1 until decodeWidth) {
    ibuf_out_ready(i) := ibuf_out_ready(i - 1) && ibuf_skids(i).io.enq.ready
  }

  for (i <- 0 until decodeWidth) {
    ibuf.io.out(i).ready := ibuf_out_ready(i)
    ibuf_skids(i).io.enq.valid := ibuf.io.out(i).valid && ibuf_out_ready(i)
    ibuf_skids(i).io.enq.bits  := ibuf.io.out(i).bits
    ibuf_skids(i).io.flush     := is_valid_redirect
    io.dispatch(i) <> ibuf_skids(i).io.deq
  }

  // 5. Backend -> FTQ (Metadata Read)
  ftq.io.readPtr := io.ftq_read_ptr
  io.ftq_read_data := ftq.io.readData

  // Epoch Check Logic
  when(is_valid_redirect) {
    fetch_epoch := ~fetch_epoch
  }

  // Handlers for Redirects (Branch Mispredictions)
  ftq.io.flush := is_valid_redirect
  ibuf.io.flush := is_valid_redirect
  
  bpu.io.redirect.valid  := is_valid_redirect
  bpu.io.redirect.target := io.redirect.target
  bpu.io.redirect.epoch  := io.redirect.epoch
  bpu.io.redirect.is_exception := io.redirect.is_exception
  bpu.io.redirect.exc_cause    := io.redirect.exc_cause
  bpu.io.redirect.snapshotIdx  := io.redirect.snapshotIdx
  bpu.io.redirect.pc           := io.redirect.pc
  bpu.io.redirect.taken        := io.redirect.taken
  bpu.io.redirect.is_cfi       := io.redirect.is_cfi
  bpu.io.redirect.is_jal       := io.redirect.is_jal
  bpu.io.redirect.is_jalr      := io.redirect.is_jalr
  bpu.io.redirect.ftqPtr       := io.redirect.ftqPtr

  // 6. Debug Port Mapping (Using the raw BPU signals for the trace)
  io.debug_ftq_valid       := bpu.io.out.valid
  io.debug_ftq_flush       := ftq.io.flush
  io.debug_ftq_pc          := bpu.io.out.bits.pc
  io.debug_ftq_mask        := bpu.io.out.bits.mask
  io.debug_ftq_ready       := bpu.io.out.ready
  io.debug_ftq_pred_target := bpu.io.out.bits.prediction.target
  io.debug_ftq_pred_taken  := bpu.io.out.bits.prediction.taken
  io.debug_ftq_pred_slot   := bpu.io.out.bits.prediction.slot

  io.debug_ftq_occupancy := ftq.io.occupancy
  io.debug_ftq_insts     := icache.io.insts
}
