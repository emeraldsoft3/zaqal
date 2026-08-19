package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.utility.SkidBuffer
import zaqal.cache._

class Frontend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect     = Input(new BPURedirect)
    val bpu_update   = Input(new BPUUpdate)
    val commits      = Input(new RobCommitIO)
    val dispatch     = Vec(decodeWidth, Decoupled(new MicroOp)) // Output to Backend (6-wide)
    val mem          = new MemoryBus(xLen, instBits * fetchWidth) // Connects to L1 I-Cache
    
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
  val bpu      = Module(new BPU)
  val ftq      = Module(new FTQ)
  val ifu      = Module(new IFU)
  val icache   = Module(new ICache)
  io.mem <> icache.io.mem
  val uopCache = Module(new UOpCache)
  dontTouch(uopCache.io) // Prevent optimization so it appears in GTKWave
  val ibuf     = Module(new IBUF)

  // Epoch Check Reg
  val fetch_epoch = RegInit(false.B)
  val is_valid_redirect = io.redirect.valid && (io.redirect.epoch === fetch_epoch)

  when(is_valid_redirect) {
    fetch_epoch := ~fetch_epoch
    printf(p"FRONTEND FLUSH: epoch=$fetch_epoch io.redirect.target=${Hexadecimal(io.redirect.target)}\n")
  }
  
  // 1. BPU -> FTQ (Prediction Path - Buffered!)
  val bpu_skid  = Module(new SkidBuffer(new FetchRequest))
  bpu_skid.io.enq <> bpu.io.out
  bpu_skid.io.flush := is_valid_redirect
  ftq.io.fromBpu.valid        := bpu_skid.io.deq.valid
  bpu_skid.io.deq.ready       := ftq.io.fromBpu.ready
  ftq.io.fromBpu.bits         := bpu_skid.io.deq.bits
  ftq.io.fromBpu.bits.epoch    := fetch_epoch

  // 2. FTQ -> IFU and ICache (Fetch Request Path - Buffered!)
  val ftq_skid  = Module(new SkidBuffer(new FetchRequest))
  ftq_skid.io.enq <> ftq.io.toIfu
  ftq_skid.io.flush := is_valid_redirect
  // Forward declarations to avoid Scala forward reference errors
  val ibuf_skids = Seq.fill(decodeWidth)(Module(new SkidBuffer(new MicroOp)))
  val ibuf_out_ready = Wire(Vec(decodeWidth, Bool()))

  // uOp Cache Hit Evaluation (Moved up for bypass)
  val uop_hit = uopCache.io.read.resp.hit && ftq_skid.io.deq.valid && enableUOpCache.B
  
  // Lock-step Handshake: Fire only if both are ready (or if we hit in uOp cache and ibuf is ready)
  ftq_skid.io.deq.ready := Mux(uop_hit, ibuf_out_ready(0), ifu.io.fetch_req.ready && icache.io.ready)
  ftq.io.toICache.ready := ftq_skid.io.deq.ready

  ifu.io.fetch_req.valid := ftq_skid.io.deq.valid && icache.io.ready && !uop_hit
  ifu.io.fetch_req.bits  := ftq_skid.io.deq.bits

  icache.io.pc := ftq_skid.io.deq.bits.pc

  // 3. ICache -> IFU (Instruction Data Path)
  ifu.io.icache_ready := icache.io.ready
  ifu.io.insts_in     := icache.io.insts

  // 4. IFU -> IBUF (Data Path - Buffered!)
  val ifu_skid = Module(new SkidBuffer(new FetchPacket))
  ifu_skid.io.enq <> ifu.io.toIbuffer
  ifu_skid.io.flush := is_valid_redirect
  ibuf.io.inst_data <> ifu_skid.io.deq

  // 5. uOp Cache Probe & Update Logic
  uopCache.io.read.req.valid := ftq_skid.io.deq.valid
  uopCache.io.read.req.bits.pc := ftq_skid.io.deq.bits.pc
  uopCache.io.flush := is_valid_redirect

  // Populate uOp Cache on IFU packet dispatch
  uopCache.io.write.req.valid := ifu_skid.io.deq.valid && !is_valid_redirect
  uopCache.io.write.req.bits.pc := ifu_skid.io.deq.bits.pc(0)
  for (i <- 0 until fetchWidth) {
    uopCache.io.write.req.bits.uops(i).pc       := ifu_skid.io.deq.bits.pc(i)
    uopCache.io.write.req.bits.uops(i).inst_raw := ifu_skid.io.deq.bits.instructions(i)
    uopCache.io.write.req.bits.uops(i).pre      := ifu_skid.io.deq.bits.pre_decoded(i)
    uopCache.io.write.req.bits.uops(i).ftqPtr   := ifu_skid.io.deq.bits.ftqPtr
    uopCache.io.write.req.bits.uops(i).epoch    := ifu_skid.io.deq.bits.epoch
    uopCache.io.write.req.bits.uops(i).is_predicted_taken := ifu_skid.io.deq.bits.prediction.taken && (i.U === ifu_skid.io.deq.bits.prediction.slot)
  }

  // Calculate Total Skid Buffer Occupancy
  val total_skid_occupancy = bpu_skid.io.occupancy +& ftq_skid.io.occupancy +& ifu_skid.io.occupancy
  ftq.io.totalInFlight := total_skid_occupancy

  // Wiring Redirect to FTQ for Dynamic Rollback
  ftq.io.redirect := io.redirect

  // 5. IBUF -> Backend (Dispatch Path - Pipelined Staging Boundary!)
  // SkidBuffers and ibuf_out_ready are instantiated above to avoid forward references

  ibuf_out_ready(0) := ibuf_skids(0).io.enq.ready
  for (i <- 1 until decodeWidth) {
    ibuf_out_ready(i) := ibuf_out_ready(i - 1) && ibuf_skids(i).io.enq.ready
  }

  for (i <- 0 until decodeWidth) {
    ibuf.io.out(i).ready := ibuf_out_ready(i) && !uop_hit
    
    val uop_valid = uop_hit && (i.U < fetchWidth.U) // Forward all fetched uOps on hit
    val ibuf_valid = ibuf.io.out(i).valid && !uop_hit
    
    ibuf_skids(i).io.enq.valid := (uop_valid || ibuf_valid) && ibuf_out_ready(i)
    // Avoid out-of-bounds index if decodeWidth > fetchWidth
    if (i < fetchWidth) {
      ibuf_skids(i).io.enq.bits  := Mux(uop_hit, uopCache.io.read.resp.uops(i), ibuf.io.out(i).bits)
    } else {
      ibuf_skids(i).io.enq.bits  := ibuf.io.out(i).bits
    }
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

  bpu.io.bpu_update := io.bpu_update
  bpu.io.commits := io.commits

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
