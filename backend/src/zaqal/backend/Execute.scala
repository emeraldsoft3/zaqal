package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal._
import zaqal.common._
import zaqal.backend.fu._

class Execute(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val in       = Flipped(Decoupled(new MicroOp))
    val redirect = Output(new BPURedirect)
  })

  // Coordination state
  val div_rd_latch = RegInit(0.U(5.W))
  val div_pc_latch = RegInit(0.U(xLen.W))

  // 1. Decoder & Register File
  val decoder = Module(new Decoder)
  val regFile = Module(new RegFile)
  
  decoder.io.inst := io.in.bits.inst_raw
  regFile.io.rs1_addr := decoder.io.out.rs1
  regFile.io.rs2_addr := decoder.io.out.rs2
  
  val src1 = regFile.io.rs1_data
  val is_imm_type = decoder.io.out.is_addi || decoder.io.out.is_andi || decoder.io.out.is_ori || decoder.io.out.is_xori ||
                    decoder.io.out.is_slli || decoder.io.out.is_srli || decoder.io.out.is_srai ||
                    decoder.io.out.is_slliw || decoder.io.out.is_srliw || decoder.io.out.is_sraiw ||
                    decoder.io.out.is_slti || decoder.io.out.is_sltiu || decoder.io.out.is_addiw ||
                    decoder.io.out.is_lui  || decoder.io.out.is_auipc || decoder.io.out.is_load

  val operand2 = Mux(is_imm_type, decoder.io.out.imm.asUInt, regFile.io.rs2_data)

  // 2. Functional Units
  val alu  = Module(new ALU)
  val bru  = Module(new BRU)
  val mul  = Module(new Multiplier)
  val div  = Module(new Divider)
  val lsu  = Module(new LSU)
  val dmem = Module(new DataMem)

  // 3. Connect FUs
  alu.io.src1 := src1
  alu.io.src2 := operand2
  alu.io.pc   := io.in.bits.pc
  alu.io.dec  := decoder.io.out
  
  // ... (bru, mul, div wiring remains similar)
  bru.io.src1 := src1
  bru.io.src2 := regFile.io.rs2_data
  bru.io.dec  := decoder.io.out
  bru.io.pc   := io.in.bits.pc
  bru.io.pred_taken := io.in.bits.is_predicted_taken

  mul.io.src1 := src1
  mul.io.src2 := regFile.io.rs2_data
  mul.io.dec  := decoder.io.out

  div.io.src1 := src1
  div.io.src2 := regFile.io.rs2_data
  div.io.dec  := decoder.io.out
  div.io.fire := io.in.fire

  lsu.io.src1 := src1
  lsu.io.src2 := regFile.io.rs2_data
  lsu.io.imm  := decoder.io.out.imm
  lsu.io.dec  := decoder.io.out
  dmem.io.addr  := lsu.io.mem_addr
  dmem.io.wen   := lsu.io.mem_wen
  dmem.io.wmask := lsu.io.mem_wmask
  dmem.io.wdata := lsu.io.mem_wdata
  lsu.io.mem_data := dmem.io.data

  // 4. Coordination & Handshake
  io.in.ready := div.io.ready
  
  // Default RegFile write values
  regFile.io.wen     := false.B
  regFile.io.rd_addr := decoder.io.out.rd
  regFile.io.rd_data := 0.U

  // Branch redirection
  io.redirect.valid  := false.B
  io.redirect.target := bru.io.target
  io.redirect.epoch  := io.in.bits.epoch

  when(io.in.fire) {
    // Writeback for single-cycle instructions
    when(decoder.io.out.rd =/= 0.U) {
      val is_link = decoder.io.out.is_jal || decoder.io.out.is_jalr
      val link_addr = io.in.bits.pc + 4.U
      val result = Mux(decoder.io.out.is_mul, mul.io.result, 
                   Mux(decoder.io.out.is_load, lsu.io.result, alu.io.result))
      regFile.io.wen     := (!decoder.io.out.is_branch && !decoder.io.out.is_div && !decoder.io.out.is_store) || is_link
      regFile.io.rd_data := Mux(is_link, link_addr, result)
    }

    // Branch Redirection Logic (unchanged)
    when(bru.io.mispredict) {
      io.redirect.valid := true.B
      printf(p"CORE EXECUTE: MISPREDICT! pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} target=${Hexadecimal(bru.io.target)} pred_taken=${io.in.bits.is_predicted_taken} actual_taken=${bru.io.taken}\n")
    } .elsewhen(decoder.io.out.is_branch) {
      printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} Branch Correct\n")
    }

    // Latch DIV metadata (unchanged)
    when(decoder.io.out.is_div) {
      div_rd_latch := decoder.io.out.rd
      div_pc_latch := io.in.bits.pc
    }

    // Printfs for ALU/MUL
    val is_alu_op = decoder.io.out.is_addi || decoder.io.out.is_add || decoder.io.out.is_andi || decoder.io.out.is_ori || 
                    decoder.io.out.is_xori || decoder.io.out.is_and || decoder.io.out.is_or || decoder.io.out.is_xor ||
                    decoder.io.out.is_sll  || decoder.io.out.is_srl || decoder.io.out.is_sra ||
                    decoder.io.out.is_slli || decoder.io.out.is_srli || decoder.io.out.is_srai ||
                    decoder.io.out.is_sllw || decoder.io.out.is_srlw || decoder.io.out.is_sraw ||
                    decoder.io.out.is_slliw || decoder.io.out.is_srliw || decoder.io.out.is_sraiw ||
                    decoder.io.out.is_slt  || decoder.io.out.is_sltu || decoder.io.out.is_slti || decoder.io.out.is_sltiu ||
                    decoder.io.out.is_sub  || decoder.io.out.is_addw || decoder.io.out.is_subw || decoder.io.out.is_addiw ||
                    decoder.io.out.is_lui  || decoder.io.out.is_auipc || decoder.io.out.is_load || decoder.io.out.is_store

    when(is_alu_op) {
       when(decoder.io.out.is_load) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=LOAD  src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(decoder.io.out.imm.asUInt)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       } .elsewhen(decoder.io.out.is_store) {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=STORE src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(regFile.io.rs2_data)} imm=${Hexadecimal(decoder.io.out.imm.asUInt)}\n")
       } .otherwise {
         printf(p"CORE EXECUTE: pc=${Hexadecimal(io.in.bits.pc)} inst=${Hexadecimal(io.in.bits.inst_raw)} type=ALU   src1=${Hexadecimal(alu.io.src1)} src2=${Hexadecimal(alu.io.src2)} res=${Hexadecimal(regFile.io.rd_data)}\n")
       }
    }
  }

  // Handle Multi-cycle (DIV) writeback
  when(div.io.done) {
    regFile.io.wen     := true.B
    regFile.io.rd_addr := div_rd_latch
    regFile.io.rd_data := div.io.result
    printf(p"CORE EXECUTE: pc=${Hexadecimal(div_pc_latch)} DIV Result: ${div.io.result} (after stall)\n")
  }
}
