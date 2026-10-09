package zaqal.backend.devices

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

/**
  * Core-Local Interruptor (CLINT)
  * Standard RISC-V specification:
  *   0x0200_0000 - 0x0200_0003: msip (Machine Software Interrupt Pending)
  *   0x0200_4000 - 0x0200_4007: mtimecmp (Machine Timer Compare)
  *   0x0200_BFF8 - 0x0200_BFFF: mtime (Machine Real-Time Counter)
  */
class CLINTIO(implicit val p: Parameters) extends Bundle with HasZaqalParameter {
  // MMIO Read Port (2 parallel ports matching DataMem dual read channels)
  val raddr  = Vec(2, Input(UInt(xLen.W)))
  val rdata  = Vec(2, Output(UInt(128.W)))
  val rvalid = Vec(2, Output(Bool()))

  // MMIO Write Port
  val wen   = Input(Bool())
  val waddr = Input(UInt(xLen.W))
  val wdata = Input(UInt(128.W))
  val wmask = Input(UInt(16.W))

  // Hardware Interrupt Notification Wires directly to CSRFile
  val msip  = Output(Bool())
  val mtip  = Output(Bool())

  // Continuous cycle counter output
  val mtime = Output(UInt(64.W))
}

class CLINT(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new CLINTIO)

  // Architectural Registers
  val r_msip     = RegInit(0.U(32.W))
  val r_mtimecmp = RegInit(~0.U(64.W)) // Initialized to max value to prevent spurious timer interrupt on boot
  val r_mtime    = RegInit(0.U(64.W))

  // mtime increments every processor cycle
  r_mtime := r_mtime + 1.U
  io.mtime := r_mtime

  // Interrupt conditions
  io.msip := r_msip(0)
  io.mtip := r_mtime >= r_mtimecmp

  // MMIO Write Logic
  val is_clint_write = io.wen && (io.waddr >= "h02000000".U && io.waddr < "h02010000".U)
  val w_offset = io.waddr(15, 0)
  val w_lane   = io.waddr(3)
  val w_val64  = Mux(w_lane, io.wdata(127, 64), io.wdata(63, 0))

  when(is_clint_write) {
    when(w_offset === "h0000".U) {
      r_msip := w_val64(31, 0)
      printf(p"[CLINT WRITE] msip := ${Hexadecimal(w_val64(31, 0))}\n")
    } .elsewhen(w_offset >= "h4000".U && w_offset <= "h4007".U) {
      r_mtimecmp := w_val64
      printf(p"[CLINT WRITE] mtimecmp := ${Hexadecimal(w_val64)} (mtime=${Hexadecimal(r_mtime)})\n")
    } .elsewhen(w_offset >= "hBFF8".U && w_offset <= "hBFFF".U) {
      r_mtime := w_val64
      printf(p"[CLINT WRITE] mtime := ${Hexadecimal(w_val64)}\n")
    }
  }

  // MMIO Read Logic
  for (i <- 0 until 2) {
    val is_clint_read = io.raddr(i) >= "h02000000".U && io.raddr(i) < "h02010000".U
    val r_offset = io.raddr(i)(15, 0)
    val r_val64 = WireDefault(0.U(64.W))

    when(r_offset === "h0000".U) {
      r_val64 := r_msip
    } .elsewhen(r_offset >= "h4000".U && r_offset <= "h4007".U) {
      r_val64 := r_mtimecmp
    } .elsewhen(r_offset >= "hBFF8".U && r_offset <= "hBFFF".U) {
      r_val64 := r_mtime
    }

    io.rvalid(i) := is_clint_read
    val r_lane = io.raddr(i)(3)
    io.rdata(i) := Mux(r_lane, Cat(r_val64, 0.U(64.W)), Cat(0.U(64.W), r_val64))
  }
}
