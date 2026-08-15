package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal._

class BPUComposer(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    val tage_pred_taken = Input(Bool())
    val sc_pred_taken = Input(Bool())
    
    // The final chosen prediction
    val final_pred_taken = Output(Bool())
    
    // Update port
    val update_valid = Input(Bool())
    val update_pc = Input(UInt(xLen.W))
    val update_ghr = Input(UInt(128.W))
    val update_tage_pred = Input(Bool())
    val update_sc_pred = Input(Bool())
    val update_actual_dir = Input(Bool())
  })

  // We use a 2K entry table of 2-bit counters for the Chooser
  val composerEntries = 2048
  val indexWidth = log2Up(composerEntries)
  
  // Fold history for index
  def fold(ghr: UInt, len: Int, foldWidth: Int): UInt = {
    val chunks = (len + foldWidth - 1) / foldWidth
    val parts = (0 until chunks).map { i =>
      val start = i * foldWidth
      val end = math.min((i + 1) * foldWidth, len)
      ghr(end - 1, start)
    }
    parts.reduce(_ ^ _)
  }
  
  // Hash function for Chooser
  val req_idx_fh = fold(io.req_ghr, 32, indexWidth) // Use 32 bits of history
  val req_idx = (io.req_pc(indexWidth - 1, 0) ^ req_idx_fh)(indexWidth - 1, 0)
  
  // Array of 2-bit saturating counters (0,1 = Trust TAGE, 2,3 = Trust SC)
  // Indexed by PC ^ GHR
  val chooserTable = Mem(composerEntries, UInt(2.W))
  
  val read_ctr = chooserTable.read(req_idx)
  val trust_sc = read_ctr(1) // MSB determines trust
  
  io.final_pred_taken := Mux(trust_sc, io.sc_pred_taken, io.tage_pred_taken)
  
  // Update logic
  val upd_idx_fh = fold(io.update_ghr, 32, indexWidth)
  val upd_idx = (io.update_pc(indexWidth - 1, 0) ^ upd_idx_fh)(indexWidth - 1, 0)
  val upd_ctr = chooserTable.read(upd_idx)
  
  when(io.update_valid) {
    val tage_correct = (io.update_tage_pred === io.update_actual_dir)
    val sc_correct = (io.update_sc_pred === io.update_actual_dir)
    
    when(sc_correct && !tage_correct) {
      // SC was right, TAGE was wrong -> Increment counter (Trust SC more)
      chooserTable(upd_idx) := Mux(upd_ctr === 3.U, 3.U, upd_ctr + 1.U)
    } .elsewhen(tage_correct && !sc_correct) {
      // TAGE was right, SC was wrong -> Decrement counter (Trust TAGE more)
      chooserTable(upd_idx) := Mux(upd_ctr === 0.U, 0.U, upd_ctr - 1.U)
    }
    // If both correct or both wrong, do not update.
  }
}
