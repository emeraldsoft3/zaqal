package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._

class Frontend(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val redirect     = Input(new BPURedirect)
    val dispatch     = Decoupled(new MicroOp) // Output to Backend
    
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
  
  // 1. BPU -> FTQ (Prediction Path)
  ftq.io.fromBpu.valid := bpu.io.out.valid
  bpu.io.out.ready     := ftq.io.fromBpu.ready
  ftq.io.fromBpu.bits  := bpu.io.out.bits
  ftq.io.fromBpu.bits.epoch := fetch_epoch

  // 2. FTQ -> IFU and ICache (Fetch Request Path)
  // Lock-step Handshake: Fire only if both are ready
  ftq.io.toIfu.ready    := ifu.io.fetch_req.ready && icache.io.ready
  ftq.io.toICache.ready := ftq.io.toIfu.ready

  ifu.io.fetch_req.valid := ftq.io.toIfu.valid && icache.io.ready
  ifu.io.fetch_req.bits  := ftq.io.toIfu.bits

  icache.io.pc := ftq.io.toICache.bits.pc
  // icache valid can be tied to ftq.io.toICache.valid & ifu.io.fetch_req.ready
  // but for a simple ROM, just driving PC is enough for now.

  // 3. ICache -> IFU (Instruction Data Path)
  ifu.io.icache_ready := icache.io.ready
  ifu.io.insts_in     := icache.io.insts

  // 4. IFU -> IBUF (Data Path - Direct!)
  ibuf.io.inst_data <> ifu.io.toIbuffer

  // 5. IBUF -> Backend (Dispatch Path)
  io.dispatch <> ibuf.io.out

  // 5. Backend -> FTQ (Metadata Read)
  ftq.io.readPtr := io.ftq_read_ptr
  io.ftq_read_data := ftq.io.readData

  // Epoch Check Logic
  val is_valid_redirect = io.redirect.valid && (io.redirect.epoch === fetch_epoch)

  when(is_valid_redirect) {
    fetch_epoch := ~fetch_epoch
  }

  // Handlers for Redirects (Branch Mispredictions)
  ftq.io.flush := is_valid_redirect
  ibuf.io.flush := is_valid_redirect
  
  bpu.io.redirect.valid  := is_valid_redirect
  bpu.io.redirect.target := io.redirect.target
  bpu.io.redirect.epoch  := io.redirect.epoch

  // 6. Debug Port Mapping
  io.debug_ftq_valid       := ftq.io.fromBpu.valid
  io.debug_ftq_flush       := ftq.io.flush
  io.debug_ftq_pc          := ftq.io.fromBpu.bits.pc
  io.debug_ftq_mask        := ftq.io.fromBpu.bits.mask
  io.debug_ftq_ready       := ftq.io.fromBpu.ready
  io.debug_ftq_pred_target := ftq.io.fromBpu.bits.prediction.target
  io.debug_ftq_pred_taken  := ftq.io.fromBpu.bits.prediction.taken
  io.debug_ftq_pred_slot   := ftq.io.fromBpu.bits.prediction.slot

  io.debug_ftq_occupancy := ftq.io.occupancy
  io.debug_ftq_insts     := icache.io.insts
}
