package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class SCPredictor(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val req_pc  = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    
    val pred = Output(new Bundle {
      val taken = Bool()
      val sum = SInt(10.W)
      val strong = Bool()
    })

    val update_valid = Input(Bool())
    val update_pc    = Input(UInt(xLen.W))
    val update_ghr   = Input(UInt(128.W))
    val update_dir   = Input(Bool())
    val update_sum   = Input(SInt(10.W)) // Sum that was calculated at fetch time
  })

  val histLen = scHistLen
  val numWeights = scNumWeights
  val weightWidth = scWeightWidth
  val maxWeight = ((1 << (weightWidth - 1)) - 1).S(weightWidth.W)
  val minWeight = (-(1 << (weightWidth - 1))).S(weightWidth.W)
  val threshold = 12.S(10.W)

  val weightTable = RegInit(VecInit(Seq.fill(numWeights)(VecInit(Seq.fill(histLen + 1)(0.S(weightWidth.W))))))

  // Lookup
  val req_idx = (io.req_pc(5, 2)) ^ io.req_pc(9, 6) // Simple hash
  val req_row = weightTable(req_idx)

  val sum = Wire(Vec(histLen + 1, SInt(10.W)))
  sum(0) := req_row(0) // Bias
  for (i <- 0 until histLen) {
    val bit = io.req_ghr(i)
    val w = req_row(i+1)
    sum(i+1) := sum(i) + Mux(bit, w, -w)
  }

  val final_sum = sum(histLen)
  io.pred.sum := final_sum
  io.pred.taken := final_sum >= 0.S
  val abs_sum = Mux(final_sum >= 0.S, final_sum, -final_sum)
  io.pred.strong := abs_sum > threshold

  // Update
  val upd_idx = (io.update_pc(5, 2)) ^ io.update_pc(9, 6)
  
  // Only update if mispredicted or if sum is weak (absolute value <= threshold)
  val upd_pred_taken = io.update_sum >= 0.S
  val upd_abs_sum = Mux(upd_pred_taken, io.update_sum, -io.update_sum)
  val mispredicted = upd_pred_taken =/= io.update_dir
  val weak_sum = upd_abs_sum <= threshold
  
  when(io.update_valid && (mispredicted || weak_sum)) {
    val bias = weightTable(upd_idx)(0)
    weightTable(upd_idx)(0) := Mux(io.update_dir,
      Mux(bias < maxWeight, bias + 1.S, bias),
      Mux(bias > minWeight, bias - 1.S, bias))

    for (i <- 0 until histLen) {
      val bit = io.update_ghr(i)
      val w = weightTable(upd_idx)(i+1)
      val inc = io.update_dir === bit
      weightTable(upd_idx)(i+1) := Mux(inc,
        Mux(w < maxWeight, w + 1.S, w),
        Mux(w > minWeight, w - 1.S, w))
    }
  }
}
