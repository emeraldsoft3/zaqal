package zaqal.backend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._
import zaqal.common._

class Decoder(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst = Input(UInt(instBits.W))
    val out  = Output(new DecodeSignals)
  })

  val opcode = io.inst(6, 0)
  val funct3 = io.inst(14, 12)
  val funct7 = io.inst(31, 25)

  io.out.rd  := io.inst(11, 7)
  io.out.rs1 := io.inst(19, 15)
  io.out.rs2 := io.inst(24, 20)
  // RISC-V immediate extraction
  val i_imm = io.inst(31, 20).asSInt
  val b_imm = Cat(io.inst(31), io.inst(7), io.inst(30, 25), io.inst(11, 8), 0.U(1.W)).asSInt
  val u_imm = Cat(io.inst(31, 12), 0.U(12.W)).asSInt
  val j_imm = Cat(io.inst(31), io.inst(19, 12), io.inst(20), io.inst(30, 21), 0.U(1.W)).asSInt
  val s_imm = Cat(io.inst(31, 25), io.inst(11, 7)).asSInt


  io.out.is_addi := (opcode === "b0010011".U) && (funct3 === "b000".U)
  io.out.is_andi := (opcode === "b0010011".U) && (funct3 === "b111".U)
  io.out.is_ori  := (opcode === "b0010011".U) && (funct3 === "b110".U)
  io.out.is_xori := (opcode === "b0010011".U) && (funct3 === "b100".U)
  
  io.out.is_slli := (opcode === "b0010011".U) && (funct3 === "b001".U) && (io.inst(31, 26) === 0.U)
  io.out.is_srli := (opcode === "b0010011".U) && (funct3 === "b101".U) && (io.inst(31, 26) === 0.U)
  io.out.is_srai := (opcode === "b0010011".U) && (funct3 === "b101".U) && (io.inst(31, 26) === "b010000".U)

  io.out.is_slti  := (opcode === "b0010011".U) && (funct3 === "b010".U)
  io.out.is_sltiu := (opcode === "b0010011".U) && (funct3 === "b011".U)
  io.out.is_sub   := (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0100000".U)

  io.out.imm     := i_imm

  io.out.is_add  := (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000000".U)
  io.out.is_and  := (opcode === "b0110011".U) && (funct3 === "b111".U) && (funct7 === "b0000000".U)
  io.out.is_or   := (opcode === "b0110011".U) && (funct3 === "b110".U) && (funct7 === "b0000000".U)
  io.out.is_xor  := (opcode === "b0110011".U) && (funct3 === "b100".U) && (funct7 === "b0000000".U)
  io.out.is_sll  := (opcode === "b0110011".U) && (funct3 === "b001".U) && (funct7 === "b0000000".U)
  io.out.is_srl  := (opcode === "b0110011".U) && (funct3 === "b101".U) && (funct7 === "b0000000".U)
  io.out.is_sra  := (opcode === "b0110011".U) && (funct3 === "b101".U) && (funct7 === "b0100000".U)
  
  io.out.is_addw := (opcode === "b0111011".U) && (funct3 === "b000".U) && (funct7 === "b0000000".U)
  io.out.is_subw := (opcode === "b0111011".U) && (funct3 === "b000".U) && (funct7 === "b0100000".U)
  
  io.out.is_sllw := (opcode === "b0111011".U) && (funct3 === "b001".U) && (funct7 === "b0000000".U)
  io.out.is_srlw := (opcode === "b0111011".U) && (funct3 === "b101".U) && (funct7 === "b0000000".U)
  io.out.is_sraw := (opcode === "b0111011".U) && (funct3 === "b101".U) && (funct7 === "b0100000".U)
  // 32-bit Word Immediate shifts (opcode 0x1B = "b0011011")
  // shamt is inst[24:20] (5 bits), funct7 differentiates SRLIW vs SRAIW
  io.out.is_slliw := (opcode === "b0011011".U) && (funct3 === "b001".U) && (io.inst(31, 25) === "b0000000".U)
  io.out.is_srliw := (opcode === "b0011011".U) && (funct3 === "b101".U) && (io.inst(31, 25) === "b0000000".U)
  io.out.is_sraiw := (opcode === "b0011011".U) && (funct3 === "b101".U) && (io.inst(31, 25) === "b0100000".U)
  io.out.is_addiw := (opcode === "b0011011".U) && (funct3 === "b000".U)
  io.out.is_slt  := (opcode === "b0110011".U) && (funct3 === "b010".U) && (funct7 === "b0000000".U)
  io.out.is_sltu := (opcode === "b0110011".U) && (funct3 === "b011".U) && (funct7 === "b0000000".U)

  io.out.is_lui   := (opcode === "b0110111".U)
  io.out.is_auipc := (opcode === "b0010111".U)


  io.out.is_mul    := (opcode === "b0110011".U) && (funct3 === "b000".U) && (funct7 === "b0000001".U)
  io.out.is_mulh   := (opcode === "b0110011".U) && (funct3 === "b001".U) && (funct7 === "b0000001".U)
  io.out.is_mulhsu := (opcode === "b0110011".U) && (funct3 === "b010".U) && (funct7 === "b0000001".U)
  io.out.is_mulhu  := (opcode === "b0110011".U) && (funct3 === "b011".U) && (funct7 === "b0000001".U)
  io.out.is_mulw   := (opcode === "b0111011".U) && (funct3 === "b000".U) && (funct7 === "b0000001".U)

  io.out.is_div    := (opcode === "b0110011".U) && (funct3 === "b100".U) && (funct7 === "b0000001".U)
  io.out.is_divu   := (opcode === "b0110011".U) && (funct3 === "b101".U) && (funct7 === "b0000001".U)
  io.out.is_rem    := (opcode === "b0110011".U) && (funct3 === "b110".U) && (funct7 === "b0000001".U)
  io.out.is_remu   := (opcode === "b0110011".U) && (funct3 === "b111".U) && (funct7 === "b0000001".U)
  
  io.out.is_divw   := (opcode === "b0111011".U) && (funct3 === "b100".U) && (funct7 === "b0000001".U)
  io.out.is_divuw  := (opcode === "b0111011".U) && (funct3 === "b101".U) && (funct7 === "b0000001".U)
  io.out.is_remw   := (opcode === "b0111011".U) && (funct3 === "b110".U) && (funct7 === "b0000001".U)
  io.out.is_remuw  := (opcode === "b0111011".U) && (funct3 === "b111".U) && (funct7 === "b0000001".U)


  io.out.is_beq    := (opcode === "b1100011".U) && (funct3 === "b000".U)
  io.out.is_bne    := (opcode === "b1100011".U) && (funct3 === "b001".U)
  io.out.is_branch := (opcode === "b1100011".U)
  io.out.is_jal    := (opcode === "b1101111".U)
  io.out.is_jalr   := (opcode === "b1100111".U)

  io.out.is_blt := (opcode === "b1100011".U) && (funct3 === "b100".U)
  io.out.is_bge := (opcode === "b1100011".U) && (funct3 === "b101".U)
  io.out.is_bltu := (opcode === "b1100011".U) && (funct3 === "b110".U)
  io.out.is_bgeu := (opcode === "b1100011".U) && (funct3 === "b111".U)
  
  // Load Instructions (Opcode 0x03 = "b0000011")
  io.out.is_lb   := (opcode === "b0000011".U) && (funct3 === "b000".U)
  io.out.is_lh   := (opcode === "b0000011".U) && (funct3 === "b001".U)
  io.out.is_lw   := (opcode === "b0000011".U) && (funct3 === "b010".U)
  io.out.is_ld   := (opcode === "b0000011".U) && (funct3 === "b011".U)
  io.out.is_lbu  := (opcode === "b0000011".U) && (funct3 === "b100".U)
  io.out.is_lhu  := (opcode === "b0000011".U) && (funct3 === "b101".U)
  io.out.is_lwu  := (opcode === "b0000011".U) && (funct3 === "b110".U)
  io.out.is_load := (opcode === "b0000011".U)
  
  // Store Instructions (Opcode 0x23 = "b0100011")
  io.out.is_sb    := (opcode === "b0100011".U) && (funct3 === "b000".U)
  io.out.is_sh    := (opcode === "b0100011".U) && (funct3 === "b001".U)
  io.out.is_sw    := (opcode === "b0100011".U) && (funct3 === "b010".U)
  io.out.is_sd    := (opcode === "b0100011".U) && (funct3 === "b011".U)
  io.out.is_store := (opcode === "b0100011".U)
  
  // Atomic Instructions (Opcode 0x2F = "b0101111")
  val funct5 = funct7(6, 2)
  io.out.is_lr     := (opcode === "b0101111".U) && (funct5 === "b00010".U)
  io.out.is_sc     := (opcode === "b0101111".U) && (funct5 === "b00011".U)
  io.out.is_lr_w   := io.out.is_lr && (funct3 === "b010".U)
  io.out.is_lr_d   := io.out.is_lr && (funct3 === "b011".U)
  io.out.is_sc_w   := io.out.is_sc && (funct3 === "b010".U)
  io.out.is_sc_d   := io.out.is_sc && (funct3 === "b011".U)

  io.out.is_amoadd  := (opcode === "b0101111".U) && (funct5 === "b00000".U)
  io.out.is_amoswap := (opcode === "b0101111".U) && (funct5 === "b00001".U)
  io.out.is_amoxor  := (opcode === "b0101111".U) && (funct5 === "b00100".U)
  io.out.is_amoand  := (opcode === "b0101111".U) && (funct5 === "b01100".U)
  io.out.is_amoor   := (opcode === "b0101111".U) && (funct5 === "b01000".U)
  io.out.is_amomin  := (opcode === "b0101111".U) && (funct5 === "b10000".U)
  io.out.is_amomax  := (opcode === "b0101111".U) && (funct5 === "b10100".U)
  io.out.is_amominu := (opcode === "b0101111".U) && (funct5 === "b11000".U)
  io.out.is_amomaxu := (opcode === "b0101111".U) && (funct5 === "b11100".U)

  io.out.is_amo_w := (opcode === "b0101111".U) && (funct3 === "b010".U) && !io.out.is_lr && !io.out.is_sc
  io.out.is_amo_d := (opcode === "b0101111".U) && (funct3 === "b011".U) && !io.out.is_lr && !io.out.is_sc
  
  io.out.is_atomic := (opcode === "b0101111".U)

  // Select immediate based on instruction type
  when(io.out.is_branch) {
    io.out.imm := b_imm
  } .elsewhen(io.out.is_lui || io.out.is_auipc) {
    io.out.imm := u_imm
  } .elsewhen(io.out.is_jal) {
    io.out.imm := j_imm
  } .elsewhen(io.out.is_load || io.out.is_lr) {
    io.out.imm := i_imm // Loads and LR use I-type immediate (though LR imm is usually 0)
  } .elsewhen(io.out.is_store || io.out.is_sc) {
    io.out.imm := s_imm // Stores and SC use S-type immediate (though SC imm is usually 0)
  }
}
