
coremark_fp.elf:     file format elf64-littleriscv


Disassembly of section .text:

0000000080000000 <_start>:
    80000000:	7179                	addi	sp,sp,-48
    80000002:	f422                	sd	s0,40(sp)
    80000004:	1800                	addi	s0,sp,48
    80000006:	00020137          	lui	sp,0x20
    8000000a:	2105                	addiw	sp,sp,1
    8000000c:	013a                	slli	sp,sp,0xe
    8000000e:	00000797          	auipc	a5,0x0
    80000012:	0c278793          	addi	a5,a5,194 # 800000d0 <_start+0xd0>
    80000016:	0007a787          	flw	fa5,0(a5)
    8000001a:	fcf42e27          	fsw	fa5,-36(s0)
    8000001e:	00000797          	auipc	a5,0x0
    80000022:	0b678793          	addi	a5,a5,182 # 800000d4 <_start+0xd4>
    80000026:	0007a787          	flw	fa5,0(a5)
    8000002a:	fcf42c27          	fsw	fa5,-40(s0)
    8000002e:	fc042a23          	sw	zero,-44(s0)
    80000032:	fe042623          	sw	zero,-20(s0)
    80000036:	a88d                	j	800000a8 <_start+0xa8>
    80000038:	fdc42707          	flw	fa4,-36(s0)
    8000003c:	fd842787          	flw	fa5,-40(s0)
    80000040:	10f77753          	fmul.s	fa4,fa4,fa5
    80000044:	fdc42787          	flw	fa5,-36(s0)
    80000048:	00f777d3          	fadd.s	fa5,fa4,fa5
    8000004c:	fcf42a27          	fsw	fa5,-44(s0)
    80000050:	fd442707          	flw	fa4,-44(s0)
    80000054:	fd842787          	flw	fa5,-40(s0)
    80000058:	08f777d3          	fsub.s	fa5,fa4,fa5
    8000005c:	fcf42e27          	fsw	fa5,-36(s0)
    80000060:	fd442707          	flw	fa4,-44(s0)
    80000064:	fdc42787          	flw	fa5,-36(s0)
    80000068:	18f777d3          	fdiv.s	fa5,fa4,fa5
    8000006c:	fcf42c27          	fsw	fa5,-40(s0)
    80000070:	fd842707          	flw	fa4,-40(s0)
    80000074:	00000797          	auipc	a5,0x0
    80000078:	06478793          	addi	a5,a5,100 # 800000d8 <_start+0xd8>
    8000007c:	0007a787          	flw	fa5,0(a5)
    80000080:	a0e797d3          	flt.s	a5,fa5,fa4
    80000084:	cf89                	beqz	a5,8000009e <_start+0x9e>
    80000086:	fd842707          	flw	fa4,-40(s0)
    8000008a:	00000797          	auipc	a5,0x0
    8000008e:	05278793          	addi	a5,a5,82 # 800000dc <_start+0xdc>
    80000092:	0007a787          	flw	fa5,0(a5)
    80000096:	18f777d3          	fdiv.s	fa5,fa4,fa5
    8000009a:	fcf42c27          	fsw	fa5,-40(s0)
    8000009e:	fec42783          	lw	a5,-20(s0)
    800000a2:	2785                	addiw	a5,a5,1
    800000a4:	fef42623          	sw	a5,-20(s0)
    800000a8:	fec42783          	lw	a5,-20(s0)
    800000ac:	0007871b          	sext.w	a4,a5
    800000b0:	03100793          	li	a5,49
    800000b4:	f8e7d2e3          	bge	a5,a4,80000038 <_start+0x38>
    800000b8:	400017b7          	lui	a5,0x40001
    800000bc:	0786                	slli	a5,a5,0x1
    800000be:	fef43023          	sd	a5,-32(s0)
    800000c2:	fd442787          	flw	fa5,-44(s0)
    800000c6:	fe043783          	ld	a5,-32(s0)
    800000ca:	00f7a027          	fsw	fa5,0(a5) # 40001000 <_start-0x3ffff000>
    800000ce:	a001                	j	800000ce <_start+0xce>
