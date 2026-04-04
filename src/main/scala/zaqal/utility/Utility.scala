package zaqal.utility

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common.HasZaqalParameter

/**
  * SkidBuffer (Elastic Buffer)
  * A 2-entry decoupled buffer that breaks the combinatorial path from deq.ready to enq.ready.
  * This is essential for high-frequency timing closure in decoupled handshakes.
  */
class SkidBuffer[T <: Data](gen: T)(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val enq   = Flipped(Decoupled(gen))
    val deq   = Decoupled(gen)
    val flush = Input(Bool())
  })

  // Two slots to ensure full throughput + registered ready
  val slot0_data  = Reg(gen)
  val slot0_valid = RegInit(false.B)
  val slot1_data  = Reg(gen)
  val slot1_valid = RegInit(false.B)

  // Enqueue logic
  // We are ready if at least one slot is empty
  io.enq.ready := !slot1_valid

  when (io.flush) {
    slot0_valid := false.B
    slot1_valid := false.B
  } .otherwise {
    when (io.enq.fire) {
      when (!slot0_valid || (io.deq.ready && !slot1_valid)) {
        // Direct to slot 0 if it's empty or being cleared
        slot0_data  := io.enq.bits
        slot0_valid := true.B
      } .otherwise {
        // "Skid" into slot 1
        slot1_data  := io.enq.bits
        slot1_valid := true.B
      }
    } .elsewhen (io.deq.ready) {
      // Move skid to main slot if deq happens without enq
      slot0_data  := slot1_data
      slot0_valid := slot1_valid
      slot1_valid := false.B
    }
  }

  // Dequeue logic
  io.deq.valid := slot0_valid
  io.deq.bits  := slot0_data
}

object SkidBuffer {
  def apply[T <: Data](enq: DecoupledIO[T], flush: Bool = false.B)(implicit p: Parameters): DecoupledIO[T] = {
    val buf = Module(new SkidBuffer(chiselTypeOf(enq.bits)))
    buf.io.enq   <> enq
    buf.io.flush := flush
    buf.io.deq
  }
}

/**
  * PipelineRegister
  * Standardized pipeline stage helper for DecoupledIO.
  */
object PipelineRegister {
  def apply[T <: Data](enq: DecoupledIO[T], flush: Bool = false.B)(implicit p: Parameters): DecoupledIO[T] = {
    // A 1-entry queue with pipe=true, flow=true is a simple pipeline register.
    // For standardized utility, we use a Queue or a custom RegNext wrapper.
    val q = Module(new Queue(chiselTypeOf(enq.bits), entries = 1, pipe = true, flow = true))
    q.io.enq <> enq
    // Note: Standard Queue doesn't have a flush port in Chisel 3.5 without reset.
    // Use reset as flush if needed, or implement a manual one.
    q.io.deq
  }
}
