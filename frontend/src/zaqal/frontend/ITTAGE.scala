package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal._

// Basic configuration for ITTAGE tables
trait ITTageConfig {
  val ittageNTables = 4
  val ittageUBits = 2
  val historyLengths = Seq(4, 12, 36, 108) // Geometrically increasing
  val tableRows = 64 // Target addresses are large, smaller table size
  val tagWidth = 8
}

// Predictor response bundle
class ITTagePrediction(implicit val p: Parameters) extends Bundle with HasZaqalParameter with ITTageConfig {
  val providerIdx = UInt(log2Up(ittageNTables).W)
  val target = UInt(xLen.W)
  val altTarget = UInt(xLen.W)
  val providerU = UInt(ittageUBits.W)
  val hit = Bool()
}

class ITTageTable(val histLen: Int, val tIdx: Int)(implicit val p: Parameters) extends Module with HasZaqalParameter with ITTageConfig {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    val hit = Output(Bool())
    val tag = Output(UInt(tagWidth.W))
    val target = Output(UInt(xLen.W))
    val u = Output(UInt(ittageUBits.W))
    
    // Update port
    val update_valid = Input(Bool())
    val update_pc = Input(UInt(xLen.W))
    val update_ghr = Input(UInt(128.W))
    val allocate = Input(Bool()) // If true, we allocate (set U=0, initialize target)
    val update_target = Input(UInt(xLen.W)) // The actual target
    val decrement_u = Input(Bool()) // For decay
    val update_u_val = Input(UInt(ittageUBits.W)) // the new U value
    val we_u = Input(Bool())
    val we_target = Input(Bool())
  })
  
  // Fold history for index and tag
  def fold(ghr: UInt, len: Int, foldWidth: Int): UInt = {
    val chunks = (len + foldWidth - 1) / foldWidth
    val parts = (0 until chunks).map { i =>
      val start = i * foldWidth
      val end = math.min((i + 1) * foldWidth, len)
      ghr(end - 1, start)
    }
    parts.reduce(_ ^ _)
  }
  
  val indexWidth = log2Up(tableRows)
  val idx_fh = fold(io.req_ghr, histLen, indexWidth)
  val tag_fh = fold(io.req_ghr, histLen, tagWidth)
  
  val req_idx = (io.req_pc(indexWidth - 1, 0) ^ idx_fh)(indexWidth - 1, 0)
  val req_tag = (io.req_pc(tagWidth - 1, 0) ^ tag_fh)(tagWidth - 1, 0)
  
  // Storage arrays
  val tags = Mem(tableRows, UInt(tagWidth.W))
  val targets = Mem(tableRows, UInt(xLen.W))
  val us = Mem(tableRows, UInt(ittageUBits.W))
  val valids = RegInit(VecInit(Seq.fill(tableRows)(false.B)))
  
  // Read logic
  val read_tag = tags.read(req_idx)
  val read_target = targets.read(req_idx)
  val read_u = us.read(req_idx)
  val read_valid = valids(req_idx)
  
  io.hit := read_valid && (read_tag === req_tag)
  io.tag := read_tag
  io.target := read_target
  io.u := read_u
  
  // Update Logic
  val u_idx_fh = fold(io.update_ghr, histLen, indexWidth)
  val u_tag_fh = fold(io.update_ghr, histLen, tagWidth)
  val u_idx = (io.update_pc(indexWidth - 1, 0) ^ u_idx_fh)(indexWidth - 1, 0)
  val u_tag = (io.update_pc(tagWidth - 1, 0) ^ u_tag_fh)(tagWidth - 1, 0)
  
  when(io.update_valid) {
    when(io.allocate) {
      valids(u_idx) := true.B
      tags(u_idx) := u_tag
      targets(u_idx) := io.update_target
      us(u_idx) := 0.U
    } .otherwise {
      when(io.decrement_u) {
        val old_u = us.read(u_idx)
        when(old_u > 0.U) {
          us(u_idx) := old_u - 1.U
        }
      }
      when(io.we_target) {
        targets(u_idx) := io.update_target
      }
      when(io.we_u) {
        us(u_idx) := io.update_u_val
      }
    }
  }
}

class ITTagePredictor(implicit val p: Parameters) extends Module with HasZaqalParameter with ITTageConfig {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    
    val pred = Output(new ITTagePrediction)
    
    // Update port
    val update_valid = Input(Bool())
    val update_pc = Input(UInt(xLen.W))
    val update_ghr = Input(UInt(128.W))
    val update_target = Input(UInt(xLen.W)) // actual outcome
    val providerIdx = Input(UInt(log2Up(ittageNTables).W))
    val providerHit = Input(Bool())
    val altTarget = Input(UInt(xLen.W))
    val providerU = Input(UInt(ittageUBits.W))
  })
  
  val tables = historyLengths.zipWithIndex.map { case (len, i) =>
    val t = Module(new ITTageTable(len, i))
    t.io.req_pc := io.req_pc
    t.io.req_ghr := io.req_ghr
    
    t.io.update_valid := false.B
    t.io.update_pc := io.update_pc
    t.io.update_ghr := io.update_ghr
    t.io.allocate := false.B
    t.io.update_target := io.update_target
    t.io.decrement_u := false.B
    t.io.update_u_val := 0.U
    t.io.we_u := false.B
    t.io.we_target := false.B
    t
  }
  
  // Find Provider and Alternate
  val hits = VecInit(tables.map(_.io.hit))
  val providerMask = PriorityEncoderOH(hits.reverse).reverse
  val hasProvider = hits.asUInt.orR
  
  val altHits = WireInit(VecInit(Seq.fill(ittageNTables)(false.B)))
  for (i <- 0 until ittageNTables) {
    altHits(i) := hits(i) && !providerMask(i)
  }
  val altMask = PriorityEncoderOH(altHits.reverse).reverse
  val hasAlt = altHits.asUInt.orR
  
  val p_idx = PriorityEncoder(hits.reverse)
  val p_idx_actual = (ittageNTables - 1).U - p_idx
  
  val provider_target = Mux1H(providerMask, tables.map(_.io.target))
  val provider_u = Mux1H(providerMask, tables.map(_.io.u))
  
  val alt_target = Mux(hasAlt, Mux1H(altMask, tables.map(_.io.target)), 0.U(xLen.W))
  
  io.pred.providerIdx := p_idx_actual
  io.pred.hit := hasProvider
  io.pred.target := provider_target
  io.pred.altTarget := alt_target
  io.pred.providerU := provider_u
  
  // Update Logic
  when(io.update_valid) {
    val provider_pred = provider_target
    
    // 1. Update Useful bits
    when(io.providerHit && (provider_pred =/= io.altTarget)) {
      val is_correct = (provider_pred === io.update_target)
      val new_u = Mux(is_correct, 
        Mux(io.providerU === 3.U, 3.U, io.providerU + 1.U), 
        Mux(io.providerU === 0.U, 0.U, io.providerU - 1.U)
      )
      for (i <- 0 until ittageNTables) {
        when (io.providerIdx === i.U) {
          tables(i).io.update_valid := true.B
          tables(i).io.we_u := true.B
          tables(i).io.update_u_val := new_u
        }
      }
    }
    
    // 2. Allocation on Misprediction
    val mispredict = (!io.providerHit) || (io.providerHit && (provider_pred =/= io.update_target))
    when(mispredict) {
      // Find eligible tables (longer history, u == 0)
      val eligible = WireInit(VecInit(Seq.fill(ittageNTables)(false.B)))
      val indexWidth = log2Up(tableRows)
      for(i <- 0 until ittageNTables) {
        val u_val = tables(i).us.read((io.update_pc(indexWidth - 1, 0) ^ tables(i).fold(io.update_ghr, tables(i).histLen, indexWidth))(indexWidth - 1, 0))
        if(i == 0) {
           eligible(i) := (!io.providerHit || io.providerIdx < i.U) && (u_val === 0.U)
        } else {
           eligible(i) := (!io.providerHit || io.providerIdx < i.U) && (u_val === 0.U)
        }
      }
      
      when(eligible.asUInt.orR) {
        // Allocate in the first eligible table (shortest history that fits criteria)
        val alloc_idx = PriorityEncoder(eligible)
        for(i <- 0 until ittageNTables) {
          when(alloc_idx === i.U) {
            tables(i).io.update_valid := true.B
            tables(i).io.allocate := true.B
          }
        }
      } .otherwise {
        // Decay (decrement u) for all tables with longer history
        for(i <- 0 until ittageNTables) {
          when(!io.providerHit || i.U > io.providerIdx) {
            tables(i).io.update_valid := true.B
            tables(i).io.decrement_u := true.B
          }
        }
      }
    }
  }
}
