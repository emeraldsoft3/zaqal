import ctypes

class NEMUState(ctypes.Structure):
    _fields_ = [
        ('gpr', ctypes.c_uint64 * 32),
        ('fpr', ctypes.c_uint64 * 32),
        ('mode', ctypes.c_uint64),
        ('mstatus', ctypes.c_uint64),
        ('sstatus', ctypes.c_uint64),
        ('mepc', ctypes.c_uint64),
        ('sepc', ctypes.c_uint64),
        ('mtval', ctypes.c_uint64),
        ('stval', ctypes.c_uint64),
        ('mtvec', ctypes.c_uint64),
        ('stvec', ctypes.c_uint64),
        ('mcause', ctypes.c_uint64),
        ('scause', ctypes.c_uint64),
        ('satp', ctypes.c_uint64),
        ('mip', ctypes.c_uint64),
        ('mie', ctypes.c_uint64),
        ('mscratch', ctypes.c_uint64),
        ('sscratch', ctypes.c_uint64),
        ('mideleg', ctypes.c_uint64),
        ('medeleg', ctypes.c_uint64),
        ('pc', ctypes.c_uint64),
        ('ext_pad', ctypes.c_uint64 * 128)
    ]

lib = ctypes.CDLL('/home/emerald/xs-env/NEMU/ready-to-run/riscv64-nemu-interpreter-so')
lib.difftest_init()

with open('/home/emerald/zaqal/difftest/fuzz/test_seed42.bin', 'rb') as f:
    code = f.read()

buf = (ctypes.c_uint8 * len(code)).from_buffer_copy(code)
lib.difftest_memcpy(0x80000000, buf, len(code), 1)

init_st = NEMUState()
init_st.pc = 0x80000000
init_st.mode = 3
lib.difftest_regcpy(ctypes.byref(init_st), 1)

print('Stepping NEMU 38 instructions on test_seed42.bin...')
for step in range(1, 39):
    lib.difftest_exec(1)
    curr = NEMUState()
    lib.difftest_regcpy(ctypes.byref(curr), 0)
    print(f'Step {step:02d}: PC=0x{curr.pc:08x}, s10(x26)=0x{curr.gpr[26]:08x}, a7(x17)=0x{curr.gpr[17]:08x}, t0(x5)=0x{curr.gpr[5]:08x}')
