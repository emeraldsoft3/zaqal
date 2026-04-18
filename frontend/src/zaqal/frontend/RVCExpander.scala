package zaqal.frontend

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import zaqal.common._

class RVCExpander(implicit val p: Parameters) extends Module with HasZaqalParameter {
  val io = IO(new Bundle {
    val inst = Input(UInt(16.W))
    val out  = Output(UInt(32.W))
    val is_rvc = Output(Bool())
  })

  val inst = io.inst
  val op = inst(1, 0)
  val funct3 = inst(15, 13)
  val expanded = Wire(UInt(32.W))
  
  val is_rvc = op =/= "b11".U
  io.is_rvc := is_rvc

  // Register Map Helper: C-style register (3 bits) to X-style (5 bits: x8-x15)
  // rs1_p (common for Q0 and Q1/Misc)
  def rs1_p = Cat("b01".U(2.W), inst(9, 7))
  // rs2_p (mostly Q1/Misc and Q2)
  def rs2_p = Cat("b01".U(2.W), inst(4, 2))
  // rd_p_q0 (Destination for Q0 loads like c.lw, c.ld)
  def rd_p_q0 = rs2_p

  // Standard 5-bit register fields
  val rd_rs1 = inst(11, 7)
  val rs2    = inst(6, 2)

  // Default expansion is NOP
  expanded := "h00000013".U 

  switch(op) {
    is("b00".U) { // Quadrant 0
      switch(funct3) {
        is("b000".U) { // c.addi4spn
          val uimm = Cat(inst(10, 7), inst(12, 11), inst(5), inst(6), 0.U(2.W))
          when(uimm =/= 0.U) {
            expanded := Cat(uimm.pad(12), 2.U(5.W), "b000".U, rd_p_q0, "b0010011".U)
          }
        }
        is("b010".U) { // c.lw
          val uimm = Cat(inst(5), inst(12, 10), inst(6), 0.U(2.W))
          expanded := Cat(uimm.pad(12), rs1_p, "b010".U, rd_p_q0, "b0000011".U)
        }
        is("b011".U) { // c.ld
          val uimm = Cat(inst(6, 5), inst(12, 10), 0.U(3.W))
          expanded := Cat(uimm.pad(12), rs1_p, "b011".U, rd_p_q0, "b0000011".U)
        }
        is("b110".U) { // c.sw
          val uimm = Cat(inst(5), inst(12, 10), inst(6), 0.U(2.W))
          expanded := Cat(uimm.pad(12)(11, 5), rs2_p, rs1_p, "b010".U, uimm(4, 0), "b0100011".U)
        }
        is("b111".U) { // c.sd
          val uimm = Cat(inst(6, 5), inst(12, 10), 0.U(3.W))
          expanded := Cat(uimm.pad(12)(11, 5), rs2_p, rs1_p, "b011".U, uimm(4, 0), "b0100011".U)
        }
      }
    }
    is("b01".U) { // Quadrant 1
      switch(funct3) {
        is("b000".U) { // c.addi or c.nop
          val imm = Cat(Fill(26, inst(12)), inst(12), inst(6, 2))
          when(rd_rs1 =/= 0.U) {
            expanded := Cat(imm(11, 0), rd_rs1, "b000".U, rd_rs1, "b0010011".U)
          }
        }
        is("b001".U) { // c.addiw (RV64)
          val imm = Cat(Fill(26, inst(12)), inst(12), inst(6, 2))
          expanded := Cat(imm(11, 0), rd_rs1, "b000".U, rd_rs1, "b0011011".U)
        }
        is("b010".U) { // c.li
          val imm = Cat(Fill(26, inst(12)), inst(12), inst(6, 2))
          expanded := Cat(imm(11, 0), 0.U(5.W), "b000".U, rd_rs1, "b0010011".U)
        }
        is("b011".U) { 
          when(rd_rs1 === 2.U) { // c.addi16sp
            val imm = Cat(Fill(22, inst(12)), inst(12), inst(4, 3), inst(5), inst(2), inst(6), 0.U(4.W))
            expanded := Cat(imm(11, 0), 2.U(5.W), "b000".U, 2.U(5.W), "b0010011".U)
          }.otherwise { // c.lui
            val imm = Cat(Fill(44, inst(12)), inst(12), inst(6, 2), 0.U(12.W))
            expanded := Cat(imm(31, 12), rd_rs1, "b0110111".U)
          }
        }
        is("b100".U) { // Misc ALU
          val funct2 = inst(11, 10)
          val imm = Cat(inst(12), inst(6, 2))
          switch(funct2) {
            is("b00".U) { expanded := Cat("b000000".U, imm, rs1_p, "b101".U, rs1_p, "b0010011".U) } // c.srli
            is("b01".U) { expanded := Cat("b010000".U, imm, rs1_p, "b101".U, rs1_p, "b0010011".U) } // c.srai
            is("b10".U) { expanded := Cat(Fill(6, imm(5)), imm, rs1_p, "b111".U, rs1_p, "b0010011".U) } // c.andi
            is("b11".U) {
              val is_w = inst(12) === 1.U
              val f2_low = inst(6, 5)
              val rs2_n = rs2_p
              val rd_n = rs1_p
              val op_arith = Mux(is_w, "b0111011".U, "b0110011".U)
              expanded := MuxCase("h00000013".U, Seq(
                (f2_low === "b00".U) -> Cat("b0100000".U, rs2_n, rd_n, "b000".U, rd_n, op_arith), // sub
                (f2_low === "b01".U) -> Cat("b0000000".U, rs2_n, rd_n, "b100".U, rd_n, "b0110011".U), // xor
                (f2_low === "b10".U) -> Cat("b0000000".U, rs2_n, rd_n, "b110".U, rd_n, "b0110011".U), // or
                (f2_low === "b11".U) -> Cat("b0000000".U, rs2_n, rd_n, "b111".U, rd_n, "b0110011".U)  // and
              ))
              // c.addw case (spec says funct[12]=1, funct[11:10]=11, funct[6:5]=01)
              when(is_w && f2_low === "b01".U) { expanded := Cat("b0000000".U, rs2_n, rd_n, "b000".U, rd_n, "b0111011".U) } 
            }
          }
        }
        is("b101".U) { // c.j
          val imm = Cat(Fill(20, inst(12)), inst(12), inst(8), inst(10, 9), inst(6), inst(7), inst(2), inst(11), inst(5, 3), 0.U(1.W))
          expanded := Cat(imm(20), imm(10, 1), imm(11), imm(19, 12), 0.U(5.W), "b1101111".U)
        }
        is("b110".U) { // c.beqz
          val imm = Cat(Fill(23, inst(12)), inst(12), inst(6, 5), inst(2), inst(11, 10), inst(4, 3), 0.U(1.W))
          expanded := Cat(imm(12), imm(10, 5), 0.U(5.W), rs1_p, "b000".U, imm(4, 1), imm(11), "b1100011".U)
        }
        is("b111".U) { // c.bnez
          val imm = Cat(Fill(23, inst(12)), inst(12), inst(6, 5), inst(2), inst(11, 10), inst(4, 3), 0.U(1.W))
          expanded := Cat(imm(12), imm(10, 5), 0.U(5.W), rs1_p, "b001".U, imm(4, 1), imm(11), "b1100011".U)
        }
      }
    }
    is("b10".U) { // Quadrant 2
      switch(funct3) {
        is("b000".U) { // c.slli
          val imm = Cat(inst(12), inst(6, 2))
          expanded := Cat("b000000".U, imm, rd_rs1, "b001".U, rd_rs1, "b0010011".U)
        }
        is("b010".U) { // c.lwsp
          val uimm = Cat(inst(3, 2), inst(12), inst(6, 4), 0.U(2.W))
          expanded := Cat(uimm.pad(12), 2.U(5.W), "b010".U, rd_rs1, "b0000011".U)
        }
        is("b011".U) { // c.ldsp
          val uimm = Cat(inst(4, 2), inst(12), inst(6, 5), 0.U(3.W))
          expanded := Cat(uimm.pad(12), 2.U(5.W), "b011".U, rd_rs1, "b0000011".U)
        }
        is("b100".U) { // mv, add, jr, jalr
          val bit12 = inst(12)
          when(bit12 === 0.U) {
            when(rs2 === 0.U) { // c.jr
              expanded := Cat(0.U(12.W), rd_rs1, "b000".U, 0.U(5.W), "b1100111".U)
            }.otherwise { // c.mv
              expanded := Cat(0.U(12.W), rs2, "b000".U, rd_rs1, "b0010011".U)
            }
          }.otherwise {
            when(rs2 === 0.U) {
              when(rd_rs1 === 0.U) { expanded := "h00100073".U } // c.ebreak
              .otherwise { expanded := Cat(0.U(12.W), rd_rs1, "b000".U, 1.U(5.W), "b1100111".U) } // c.jalr
            }.otherwise { // c.add
              expanded := Cat("b0000000".U, rs2, rd_rs1, "b000".U, rd_rs1, "b0110011".U)
            }
          }
        }
        is("b110".U) { // c.swsp
          val uimm = Cat(inst(8, 7), inst(12, 9), 0.U(2.W))
          expanded := Cat(uimm.pad(12)(11, 5), rs2, 2.U(5.W), "b010".U, uimm(4, 0), "b0100011".U)
        }
        is("b111".U) { // c.sdsp
          val uimm = Cat(inst(9, 7), inst(12, 10), 0.U(3.W))
          expanded := Cat(uimm.pad(12)(11, 5), rs2, 2.U(5.W), "b011".U, uimm(4, 0), "b0100011".U)
        }
      }
    }
  }

  io.out := expanded
}
