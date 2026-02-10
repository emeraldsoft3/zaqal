
//for testing purpose only

package zaqal.backend

import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR // Correct import for LFSR
import zaqal._

class DummyBackend extends Module {
  val io = IO(new Bundle {
    val issue    = Flipped(Decoupled(new FetchPacket)) // Renamed to 'issue'
    val redirect = Output(new BPURedirect)             // Added 'redirect'
  })

  // Default redirect (always inactive for this test)
  io.redirect.valid  := false.B
  io.redirect.target := 0.U

  // Timer logic
  val busy_timer = RegInit(0.U(4.W))
  val is_busy    = busy_timer > 0.U

  // Random delay between 1 and 8 cycles
  val random_val = LFSR(8)
  val random_delay = random_val(2, 0) + 1.U

  when (is_busy) {
    busy_timer := busy_timer - 1.U
    io.issue.ready := false.B
  } .otherwise {
    // If FTQ has data, we take it and start a new random busy period
    io.issue.ready := io.issue.valid
    
    when (io.issue.fire) {
      busy_timer := random_delay
      // Chisel native printf uses %x for hex
      printf(p"Backend: Consumed PC 0x${io.issue.bits.pc}%x. Busy for $random_delay cycles.\n")
    }
  }
}