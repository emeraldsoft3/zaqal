package zaqal.backend.csr

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class PMAChecker(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val addr          = Input(UInt(xLen.W))
    val is_fetch      = Input(Bool())

    val is_cacheable  = Output(Bool())
    val is_executable = Output(Bool())
    val fault         = Output(Bool()) // Raised if instruction fetch targets non-executable region
  })

  // Physical Memory Map
  // 0x8000_0000 to 0xFFFF_FFFF: Main Memory (DRAM) - Cacheable, Executable
  // 0x0000_0000 to 0x7FFF_FFFF: MMIO Peripherals (UART, PLIC, CLINT) - Non-Cacheable, Non-Executable
  val is_dram = io.addr >= "h80000000".U && io.addr <= "hffffffff".U

  io.is_cacheable  := is_dram
  io.is_executable := is_dram

  // If instruction fetch targets non-executable physical memory (e.g. MMIO), fault immediately
  io.fault := io.is_fetch && !io.is_executable
}
