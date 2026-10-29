# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VCore.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace-fst/--trace-saif/--trace-vcd)
VM_TRACE = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  VCore \
  VCore___024root__DepSet_h4a076b33__0 \
  VCore___024root__DepSet_h4a076b33__1 \
  VCore___024root__DepSet_h889bdcc7__0 \
  VCore___024root__DepSet_h889bdcc7__1 \
  VCore___024root__DepSet_h889bdcc7__2 \
  VCore___024root__DepSet_h889bdcc7__3 \
  VCore___024root__DepSet_h889bdcc7__4 \
  VCore___024root__DepSet_h889bdcc7__5 \
  VCore___024root__DepSet_h889bdcc7__6 \
  VCore___024root__DepSet_h889bdcc7__7 \
  VCore___024root__DepSet_h889bdcc7__8 \
  VCore___024root__DepSet_h889bdcc7__9 \
  VCore___024root__DepSet_h889bdcc7__10 \
  VCore___024root__DepSet_h889bdcc7__11 \
  VCore___024root__DepSet_h889bdcc7__12 \
  VCore___024root__DepSet_h889bdcc7__13 \
  VCore___024root__DepSet_h889bdcc7__14 \
  VCore___024root__DepSet_h889bdcc7__15 \
  VCore___024root__DepSet_h889bdcc7__16 \
  VCore___024root__DepSet_h889bdcc7__17 \
  VCore___024root__DepSet_h889bdcc7__18 \
  VCore___024root__DepSet_h889bdcc7__19 \
  VCore___024root__DepSet_h889bdcc7__20 \
  VCore___024root__DepSet_h889bdcc7__21 \
  VCore___024root__DepSet_h889bdcc7__22 \
  VCore___024root__DepSet_h889bdcc7__23 \
  VCore___024root__DepSet_h889bdcc7__24 \
  VCore___024root__DepSet_h889bdcc7__25 \
  VCore___024root__DepSet_h889bdcc7__26 \
  VCore___024root__DepSet_h889bdcc7__27 \
  VCore___024root__DepSet_h889bdcc7__28 \
  VCore___024root__DepSet_h889bdcc7__29 \
  VCore___024root__DepSet_h889bdcc7__30 \
  VCore___024root__DepSet_h889bdcc7__31 \
  VCore___024root__DepSet_h889bdcc7__32 \
  VCore___024root__DepSet_h889bdcc7__33 \
  VCore___024root__DepSet_h889bdcc7__34 \
  VCore___024root__DepSet_h889bdcc7__35 \
  VCore___024root__DepSet_h889bdcc7__36 \
  VCore___024root__DepSet_h889bdcc7__37 \
  VCore___024root__DepSet_h889bdcc7__38 \
  VCore___024root__DepSet_h889bdcc7__39 \
  VCore___024root__DepSet_h889bdcc7__40 \
  VCore___024root__DepSet_h889bdcc7__41 \
  VCore___024root__DepSet_h889bdcc7__42 \
  VCore___024root__DepSet_h889bdcc7__43 \
  VCore___024root__DepSet_h889bdcc7__44 \
  VCore___024root__DepSet_h889bdcc7__45 \
  VCore___024root__DepSet_h889bdcc7__46 \
  VCore___024root__DepSet_h889bdcc7__47 \
  VCore___024root__DepSet_h889bdcc7__48 \
  VCore___024root__DepSet_h889bdcc7__49 \
  VCore___024root__DepSet_h889bdcc7__50 \
  VCore___024root__DepSet_h889bdcc7__51 \
  VCore___024root__DepSet_h889bdcc7__52 \
  VCore___024root__DepSet_h889bdcc7__53 \
  VCore___024root__DepSet_h889bdcc7__54 \
  VCore___024root__DepSet_h889bdcc7__55 \
  VCore___024root__DepSet_h889bdcc7__56 \
  VCore___024root__DepSet_h889bdcc7__57 \
  VCore___024root__DepSet_h889bdcc7__58 \
  VCore___024root__DepSet_h889bdcc7__59 \
  VCore___024root__DepSet_h889bdcc7__60 \
  VCore___024root__DepSet_h889bdcc7__61 \
  VCore___024root__DepSet_h889bdcc7__62 \
  VCore___024root__DepSet_h889bdcc7__63 \
  VCore___024root__DepSet_h889bdcc7__64 \
  VCore___024root__DepSet_h889bdcc7__65 \
  VCore___024root__DepSet_h889bdcc7__66 \
  VCore___024root__DepSet_h889bdcc7__67 \
  VCore___024root__DepSet_h889bdcc7__68 \
  VCore___024root__DepSet_h889bdcc7__69 \
  VCore___024root__DepSet_h889bdcc7__70 \
  VCore___024root__DepSet_h889bdcc7__71 \
  VCore___024root__DepSet_h889bdcc7__72 \
  VCore___024root__DepSet_h889bdcc7__73 \
  VCore___024root__DepSet_h889bdcc7__74 \
  VCore___024root__DepSet_h889bdcc7__75 \
  VCore___024root__DepSet_h889bdcc7__76 \
  VCore___024root__DepSet_h889bdcc7__77 \
  VCore___024root__DepSet_h889bdcc7__78 \
  VCore___024root__DepSet_h889bdcc7__79 \
  VCore___024root__DepSet_h889bdcc7__80 \
  VCore___024root__DepSet_h889bdcc7__81 \
  VCore___024root__DepSet_h889bdcc7__82 \
  VCore___024root__DepSet_h889bdcc7__83 \
  VCore___024root__DepSet_h889bdcc7__84 \
  VCore___024root__DepSet_h889bdcc7__85 \
  VCore___024root__DepSet_h889bdcc7__86 \
  VCore___024root__DepSet_h889bdcc7__87 \
  VCore___024root__DepSet_h889bdcc7__88 \
  VCore___024root__DepSet_h889bdcc7__89 \
  VCore___024root__DepSet_h889bdcc7__90 \
  VCore___024root__DepSet_h889bdcc7__91 \
  VCore___024root__DepSet_h889bdcc7__92 \
  VCore___024root__DepSet_h889bdcc7__93 \
  VCore___024unit__DepSet_hdda2250c__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  VCore__ConstPool_0 \
  VCore___024root__Slow \
  VCore___024root__DepSet_h4a076b33__0__Slow \
  VCore___024root__DepSet_h889bdcc7__0__Slow \
  VCore___024root__DepSet_h889bdcc7__1__Slow \
  VCore___024root__DepSet_h889bdcc7__2__Slow \
  VCore___024root__DepSet_h889bdcc7__3__Slow \
  VCore___024root__DepSet_h889bdcc7__4__Slow \
  VCore___024root__DepSet_h889bdcc7__5__Slow \
  VCore___024root__DepSet_h889bdcc7__6__Slow \
  VCore___024root__DepSet_h889bdcc7__7__Slow \
  VCore___024root__DepSet_h889bdcc7__8__Slow \
  VCore___024root__DepSet_h889bdcc7__9__Slow \
  VCore___024root__DepSet_h889bdcc7__10__Slow \
  VCore___024root__DepSet_h889bdcc7__11__Slow \
  VCore___024root__DepSet_h889bdcc7__12__Slow \
  VCore___024root__DepSet_h889bdcc7__13__Slow \
  VCore___024root__DepSet_h889bdcc7__14__Slow \
  VCore___024root__DepSet_h889bdcc7__15__Slow \
  VCore___024root__DepSet_h889bdcc7__16__Slow \
  VCore___024root__DepSet_h889bdcc7__17__Slow \
  VCore___024root__DepSet_h889bdcc7__18__Slow \
  VCore___024root__DepSet_h889bdcc7__19__Slow \
  VCore___024root__DepSet_h889bdcc7__20__Slow \
  VCore___024root__DepSet_h889bdcc7__21__Slow \
  VCore___024root__DepSet_h889bdcc7__22__Slow \
  VCore___024root__DepSet_h889bdcc7__23__Slow \
  VCore___024root__DepSet_h889bdcc7__24__Slow \
  VCore___024root__DepSet_h889bdcc7__25__Slow \
  VCore___024root__DepSet_h889bdcc7__26__Slow \
  VCore___024root__DepSet_h889bdcc7__27__Slow \
  VCore___024root__DepSet_h889bdcc7__28__Slow \
  VCore___024root__DepSet_h889bdcc7__29__Slow \
  VCore___024root__DepSet_h889bdcc7__30__Slow \
  VCore___024root__DepSet_h889bdcc7__31__Slow \
  VCore___024root__DepSet_h889bdcc7__32__Slow \
  VCore___024root__DepSet_h889bdcc7__33__Slow \
  VCore___024root__DepSet_h889bdcc7__34__Slow \
  VCore___024root__DepSet_h889bdcc7__35__Slow \
  VCore___024root__DepSet_h889bdcc7__36__Slow \
  VCore___024root__DepSet_h889bdcc7__37__Slow \
  VCore___024root__DepSet_h889bdcc7__38__Slow \
  VCore___024root__DepSet_h889bdcc7__39__Slow \
  VCore___024root__DepSet_h889bdcc7__40__Slow \
  VCore___024root__DepSet_h889bdcc7__41__Slow \
  VCore___024root__DepSet_h889bdcc7__42__Slow \
  VCore___024root__DepSet_h889bdcc7__43__Slow \
  VCore___024root__DepSet_h889bdcc7__44__Slow \
  VCore___024root__DepSet_h889bdcc7__45__Slow \
  VCore___024root__DepSet_h889bdcc7__46__Slow \
  VCore___024unit__Slow \
  VCore___024unit__DepSet_h1e408efe__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  VCore__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  VCore__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_dpi \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
