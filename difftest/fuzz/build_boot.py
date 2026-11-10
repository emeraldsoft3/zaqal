import os

DRAM_SIZE = 6 * 1024 * 1024 # 6MB
combined = bytearray(DRAM_SIZE)

# 1. ZSBL at 0x0 (0x80000000)
with open("/home/emerald/zaqal/difftest/fuzz/zsbl.bin", "rb") as f:
    zsbl = f.read()
combined[0:len(zsbl)] = zsbl
print(f"Placed ZSBL at 0x0 ({len(zsbl)} bytes)")

# 2. OpenSBI fw_jump at 0x10000 (0x80010000)
with open("/home/emerald/opensbi/build/platform/generic/firmware/fw_jump.bin", "rb") as f:
    fw_jump = f.read()
combined[0x10000:0x10000 + len(fw_jump)] = fw_jump
print(f"Placed OpenSBI fw_jump at 0x10000 ({len(fw_jump)} bytes)")

# 3. Payload at 0x200000 (0x80200000)
with open("/home/emerald/opensbi/build/platform/generic/firmware/payloads/test.bin", "rb") as f:
    payload = f.read()
combined[0x200000:0x200000 + len(payload)] = payload
print(f"Placed test payload at 0x200000 ({len(payload)} bytes)")

# 4. DTB at 0x400000 (0x80400000)
with open("/home/emerald/zaqal/difftest/fuzz/zaqal.dtb", "rb") as f:
    dtb = f.read()
combined[0x400000:0x400000 + len(dtb)] = dtb
print(f"Placed DTB at 0x400000 ({len(dtb)} bytes)")

out_path = "/home/emerald/zaqal/difftest/fuzz/combined_boot.bin"
with open(out_path, "wb") as f:
    f.write(combined)
print(f"Successfully generated {out_path} ({len(combined)} bytes)")
