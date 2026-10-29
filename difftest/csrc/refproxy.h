#ifndef __REFPROXY_H__
#define __REFPROXY_H__

#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <string>

// Difftest direction constants
enum {
  DIFFTEST_TO_DUT = 0,
  DIFFTEST_TO_REF = 1
};

// Exact RISC-V 64 register state layout matching NEMU riscv64_CPU_state
struct RISCV64_CPU_State {
  uint64_t gpr[32];
  uint64_t fpr[32];
  uint64_t mode;
  uint64_t mstatus, sstatus;
  uint64_t mepc, sepc;
  uint64_t mtval, stval;
  uint64_t mtvec, stvec;
  uint64_t mcause, scause;
  uint64_t satp;
  uint64_t mip, mie;
  uint64_t mscratch, sscratch;
  uint64_t mideleg, medeleg;
  uint64_t pc;
  uint64_t ext_pad[128];
};

// Function pointer signatures matching NEMU exports
typedef void (*difftest_init_f)();
typedef void (*difftest_memcpy_f)(uint64_t dest, void *src, size_t n, bool direction);
typedef void (*difftest_regcpy_f)(void *dut, bool direction);
typedef void (*difftest_csrcpy_f)(void *dut, bool direction);
typedef void (*difftest_exec_f)(uint64_t n);
typedef void (*difftest_display_f)();
typedef int  (*isa_difftest_checkregs_f)(void *dut, uint64_t pc);

class RefProxy {
private:
  void *handle;

public:
  difftest_init_f init;
  difftest_memcpy_f memcpy;
  difftest_regcpy_f regcpy;
  difftest_csrcpy_f csrcpy;
  difftest_exec_f exec;
  difftest_display_f display;
  isa_difftest_checkregs_f checkregs;

  bool initialized;

  RefProxy() : handle(nullptr), initialized(false) {}

  bool load(const char *so_path) {
    handle = dlopen(so_path, RTLD_LAZY);
    if (!handle) {
      fprintf(stderr, "[Difftest] Failed to dlopen NEMU library '%s': %s\n", so_path, dlerror());
      return false;
    }

    init = (difftest_init_f)dlsym(handle, "difftest_init");
    memcpy = (difftest_memcpy_f)dlsym(handle, "difftest_memcpy");
    regcpy = (difftest_regcpy_f)dlsym(handle, "difftest_regcpy");
    csrcpy = (difftest_csrcpy_f)dlsym(handle, "difftest_csrcpy");
    exec = (difftest_exec_f)dlsym(handle, "difftest_exec");
    display = (difftest_display_f)dlsym(handle, "difftest_display");
    checkregs = (isa_difftest_checkregs_f)dlsym(handle, "isa_difftest_checkregs");

    if (!init || !memcpy || !regcpy || !exec) {
      fprintf(stderr, "[Difftest] Error loading required symbols from NEMU: %s\n", dlerror());
      dlclose(handle);
      handle = nullptr;
      return false;
    }

    init();
    initialized = true;
    printf("[Difftest] Successfully attached Golden Model: %s\n", so_path);
    return true;
  }

  ~RefProxy() {
    if (handle) {
      dlclose(handle);
    }
  }
};

extern RefProxy g_ref;

#endif // __REFPROXY_H__
