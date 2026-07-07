package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal._

// Basic configuration for TAGE tables
trait TageConfig {
  val tageNTables = 4
  val tageCtrBits = 3
  val tageUBits = 2
  val historyLengths = Seq(4, 12, 36, 108) // Geometrically increasing
  val tableRows = 128
  val tagWidth = 8
}

// Predictor response bundle
class TagePrediction extends Bundle with TageConfig {
  val providerIdx = UInt(log2Up(tageNTables).W)
  val taken = Bool()
  val altTaken = Bool()
  val providerU = UInt(tageUBits.W)
  val providerCtr = UInt(tageCtrBits.W)
  val hit = Bool()
}

class TageTable(val histLen: Int, val tIdx: Int)(implicit val p: Parameters) extends Module with HasZaqalParameter with TageConfig {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    val hit = Output(Bool())
    val tag = Output(UInt(tagWidth.W))
    val ctr = Output(UInt(tageCtrBits.W))
    val u = Output(UInt(tageUBits.W))
    
    // Update port
    val update_valid = Input(Bool())
    val update_pc = Input(UInt(xLen.W))
    val update_ghr = Input(UInt(128.W))
    val allocate = Input(Bool()) // If true, we allocate (set U=0, initialize ctr)
    val update_dir = Input(Bool()) // The actual direction
    val decrement_u = Input(Bool()) // For decay
    val update_u_val = Input(UInt(tageUBits.W)) // the new U value
    val update_ctr = Input(UInt(tageCtrBits.W))
    val we_u = Input(Bool())
    val we_ctr = Input(Bool())
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
  val ctrs = Mem(tableRows, UInt(tageCtrBits.W))
  val us = Mem(tableRows, UInt(tageUBits.W))
  val valids = RegInit(VecInit(Seq.fill(tableRows)(false.B)))
  
  // Read logic
  val read_tag = tags.read(req_idx)
  val read_ctr = ctrs.read(req_idx)
  val read_u = us.read(req_idx)
  val read_valid = valids(req_idx)
  
  io.hit := read_valid && (read_tag === req_tag)
  io.tag := read_tag
  io.ctr := read_ctr
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
      ctrs(u_idx) := Mux(io.update_dir, 4.U, 3.U) // Weak taken or weak not taken
      us(u_idx) := 0.U
    } .otherwise {
      when(io.decrement_u) {
        val old_u = us.read(u_idx)
        when(old_u > 0.U) {
          us(u_idx) := old_u - 1.U
        }
      }
      when(io.we_ctr) {
        ctrs(u_idx) := io.update_ctr
      }
      when(io.we_u) {
        us(u_idx) := io.update_u_val
      }
    }
  }
}

class TagePredictor(implicit val p: Parameters) extends Module with HasZaqalParameter with TageConfig {
  val io = IO(new Bundle {
    val req_pc = Input(UInt(xLen.W))
    val req_ghr = Input(UInt(128.W))
    
    val pred = Output(new TagePrediction)
    
    // Update port
    val update_valid = Input(Bool())
    val update_pc = Input(UInt(xLen.W))
    val update_ghr = Input(UInt(128.W))
    val update_dir = Input(Bool()) // actual outcome
    val providerIdx = Input(UInt(log2Up(tageNTables).W))
    val providerHit = Input(Bool())
    val providerCtr = Input(UInt(tageCtrBits.W))
    val altTaken = Input(Bool())
    val providerU = Input(UInt(tageUBits.W))
  })
  
  // Base Predictor (Bimodal)
  val baseTable = Mem(tableRows, UInt(2.W))
  val req_base_idx = io.req_pc(log2Up(tableRows) - 1, 0)
  val base_pred = baseTable.read(req_base_idx)
  val base_taken = base_pred(1)
  
  val tables = historyLengths.zipWithIndex.map { case (len, i) =>
    val t = Module(new TageTable(len, i))
    t.io.req_pc := io.req_pc
    t.io.req_ghr := io.req_ghr
    
    t.io.update_valid := false.B
    t.io.update_pc := io.update_pc
    t.io.update_ghr := io.update_ghr
    t.io.allocate := false.B
    t.io.update_dir := io.update_dir
    t.io.decrement_u := false.B
    t.io.update_u_val := 0.U
    t.io.update_ctr := 0.U
    t.io.we_u := false.B
    t.io.we_ctr := false.B
    t
  }
  
  // Find Provider and Alternate
  val hits = VecInit(tables.map(_.io.hit))
  
  // Provider is the highest matching table
  val providerMask = PriorityEncoderOH(hits.reverse).reverse
  val hasProvider = hits.asUInt.orR
  
  val altHits = WireInit(VecInit(Seq.fill(tageNTables)(false.B)))
  for (i <- 0 until tageNTables) {
    altHits(i) := hits(i) && !providerMask(i)
  }
  val altMask = PriorityEncoderOH(altHits.reverse).reverse
  val hasAlt = altHits.asUInt.orR
  
  val p_idx = PriorityEncoder(hits.reverse)
  val p_idx_actual = (tageNTables - 1).U - p_idx
  
  val provider_ctr = Mux1H(providerMask, tables.map(_.io.ctr))
  val provider_u = Mux1H(providerMask, tables.map(_.io.u))
  val provider_taken = provider_ctr(tageCtrBits - 1)
  
  val alt_taken = Mux(hasAlt, Mux1H(altMask, tables.map(_.io.ctr))(tageCtrBits - 1), base_taken)
  
  io.pred.providerIdx := p_idx_actual
  io.pred.hit := hasProvider
  io.pred.taken := Mux(hasProvider, provider_taken, base_taken)
  io.pred.altTaken := alt_taken
  io.pred.providerU := provider_u
  io.pred.providerCtr := provider_ctr
  
  // Base Predictor Update
  val u_base_idx = io.update_pc(log2Up(tableRows) - 1, 0)
  val u_base_ctr = baseTable.read(u_base_idx)
  when(io.update_valid && !io.providerHit) {
    val new_base_ctr = Mux(io.update_dir, 
      Mux(u_base_ctr === 3.U, 3.U, u_base_ctr + 1.U), 
      Mux(u_base_ctr === 0.U, 0.U, u_base_ctr - 1.U)
    )
    baseTable(u_base_idx) := new_base_ctr
  }
  
  // Tagged Table Update Logic
  when(io.update_valid) {
    val provider_pred = io.providerCtr(tageCtrBits - 1)
    
    // 1. Update Useful bits
    when(io.providerHit && (provider_pred =/= io.altTaken)) {
      val is_correct = (provider_pred === io.update_dir)
      val new_u = Mux(is_correct, 
        Mux(io.providerU === 3.U, 3.U, io.providerU + 1.U), 
        Mux(io.providerU === 0.U, 0.U, io.providerU - 1.U)
      )
      for (i <- 0 until tageNTables) {
        when (io.providerIdx === i.U) {
          tables(i).io.update_valid := true.B
          tables(i).io.we_u := true.B
          tables(i).io.update_u_val := new_u
        }
      }
    }
    
    // 2. Update Provider Counter
    when(io.providerHit) {
      val new_ctr = Mux(io.update_dir,
        Mux(io.providerCtr === 7.U, 7.U, io.providerCtr + 1.U),
        Mux(io.providerCtr === 0.U, 0.U, io.providerCtr - 1.U)
      )
      for (i <- 0 until tageNTables) {
        when (io.providerIdx === i.U) {
          tables(i).io.update_valid := true.B
          tables(i).io.we_ctr := true.B
          tables(i).io.update_ctr := new_ctr
        }
      }
    }
    
    // 3. Allocation on Misprediction
    val mispredict = (!io.providerHit && (base_taken =/= io.update_dir)) || (io.providerHit && (provider_pred =/= io.update_dir))
    when(mispredict) {
      // Find eligible tables (longer history, u == 0)
      val eligible = WireInit(VecInit(Seq.fill(tageNTables)(false.B)))
      val indexWidth = log2Up(tableRows)
      for(i <- 0 until tageNTables) {
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
        for(i <- 0 until tageNTables) {
          when(alloc_idx === i.U) {
            tables(i).io.update_valid := true.B
            tables(i).io.allocate := true.B
          }
        }
      } .otherwise {
        // Decay (decrement u) for all tables with longer history
        for(i <- 0 until tageNTables) {
          when(!io.providerHit || i.U > io.providerIdx) {
            tables(i).io.update_valid := true.B
            tables(i).io.decrement_u := true.B
          }
        }
      }
    }
  }
}
