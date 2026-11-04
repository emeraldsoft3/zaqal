# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VZaqalSoCTop.mk for the caller.

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
VM_TRACE = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0
# Tracing output mode in SAIF format?  0/1 (from --trace-saif)
VM_TRACE_SAIF = 0
# Tracing output mode in VCD format?  0/1 (from --trace-vcd)
VM_TRACE_VCD = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
  VZaqalSoCTop \
  VZaqalSoCTop___024root__DepSet_he9bd6fd3__0 \
  VZaqalSoCTop___024root__DepSet_he9bd6fd3__1 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__0 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__1 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__2 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__3 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__4 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__5 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__6 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__7 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__8 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__9 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__10 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__11 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__12 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__13 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__14 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__15 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__16 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__17 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__18 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__19 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__20 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__21 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__22 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__23 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__24 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__25 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__26 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__27 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__28 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__29 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__30 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__31 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__32 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__33 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__34 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__35 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__36 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__37 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__38 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__39 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__40 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__41 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__42 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__43 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__44 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__45 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__46 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__47 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__48 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__49 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__50 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__51 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__52 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__53 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__54 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__55 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__56 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__57 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__58 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__59 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__60 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__61 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__62 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__63 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__64 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__65 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__66 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__67 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__68 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__69 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__70 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__71 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__72 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__73 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__74 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__75 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__76 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__77 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__78 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__79 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__80 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__81 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__82 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__83 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__84 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__85 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__86 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__87 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__88 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__89 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__90 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__91 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__92 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__93 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__94 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__95 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__96 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__97 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__98 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__99 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__100 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__101 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__102 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__103 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__104 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__105 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__106 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__107 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__108 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__109 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__110 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__111 \
  VZaqalSoCTop___024root__DepSet_h69af0f82__112 \
  VZaqalSoCTop___024unit__DepSet_hf12383c8__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
  VZaqalSoCTop__ConstPool_0 \
  VZaqalSoCTop___024root__Slow \
  VZaqalSoCTop___024root__DepSet_he9bd6fd3__0__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__0__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__1__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__2__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__3__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__4__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__5__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__6__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__7__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__8__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__9__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__10__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__11__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__12__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__13__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__14__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__15__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__16__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__17__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__18__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__19__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__20__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__21__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__22__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__23__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__24__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__25__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__26__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__27__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__28__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__29__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__30__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__31__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__32__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__33__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__34__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__35__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__36__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__37__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__38__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__39__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__40__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__41__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__42__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__43__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__44__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__45__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__46__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__47__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__48__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__49__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__50__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__51__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__52__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__53__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__54__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__55__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__56__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__57__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__58__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__59__Slow \
  VZaqalSoCTop___024root__DepSet_h69af0f82__60__Slow \
  VZaqalSoCTop___024unit__Slow \
  VZaqalSoCTop___024unit__DepSet_h514c7b8d__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
  VZaqalSoCTop__Dpi \
  VZaqalSoCTop__Trace__0 \
  VZaqalSoCTop__Trace__1 \
  VZaqalSoCTop__Trace__2 \
  VZaqalSoCTop__Trace__3 \
  VZaqalSoCTop__Trace__4 \
  VZaqalSoCTop__Trace__5 \
  VZaqalSoCTop__Trace__6 \
  VZaqalSoCTop__Trace__7 \
  VZaqalSoCTop__Trace__8 \
  VZaqalSoCTop__Trace__9 \
  VZaqalSoCTop__Trace__10 \
  VZaqalSoCTop__Trace__11 \
  VZaqalSoCTop__Trace__12 \
  VZaqalSoCTop__Trace__13 \
  VZaqalSoCTop__Trace__14 \
  VZaqalSoCTop__Trace__15 \
  VZaqalSoCTop__Trace__16 \
  VZaqalSoCTop__Trace__17 \
  VZaqalSoCTop__Trace__18 \
  VZaqalSoCTop__Trace__19 \
  VZaqalSoCTop__Trace__20 \
  VZaqalSoCTop__Trace__21 \
  VZaqalSoCTop__Trace__22 \
  VZaqalSoCTop__Trace__23 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
  VZaqalSoCTop__Syms \
  VZaqalSoCTop__Trace__0__Slow \
  VZaqalSoCTop__TraceDecls__0__Slow \
  VZaqalSoCTop__Trace__1__Slow \
  VZaqalSoCTop__Trace__2__Slow \
  VZaqalSoCTop__Trace__3__Slow \
  VZaqalSoCTop__Trace__4__Slow \
  VZaqalSoCTop__Trace__5__Slow \
  VZaqalSoCTop__Trace__6__Slow \
  VZaqalSoCTop__Trace__7__Slow \
  VZaqalSoCTop__Trace__8__Slow \
  VZaqalSoCTop__Trace__9__Slow \
  VZaqalSoCTop__Trace__10__Slow \
  VZaqalSoCTop__Trace__11__Slow \
  VZaqalSoCTop__Trace__12__Slow \
  VZaqalSoCTop__Trace__13__Slow \
  VZaqalSoCTop__Trace__14__Slow \
  VZaqalSoCTop__Trace__15__Slow \
  VZaqalSoCTop__Trace__16__Slow \
  VZaqalSoCTop__Trace__17__Slow \
  VZaqalSoCTop__Trace__18__Slow \
  VZaqalSoCTop__Trace__19__Slow \
  VZaqalSoCTop__Trace__20__Slow \
  VZaqalSoCTop__Trace__21__Slow \
  VZaqalSoCTop__Trace__22__Slow \
  VZaqalSoCTop__Trace__23__Slow \
  VZaqalSoCTop__Trace__24__Slow \
  VZaqalSoCTop__Trace__25__Slow \
  VZaqalSoCTop__Trace__26__Slow \
  VZaqalSoCTop__Trace__27__Slow \
  VZaqalSoCTop__Trace__28__Slow \
  VZaqalSoCTop__Trace__29__Slow \
  VZaqalSoCTop__Trace__30__Slow \
  VZaqalSoCTop__Trace__31__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
  verilated \
  verilated_dpi \
  verilated_vcd_c \
  verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \

# Verilated -*- Makefile -*-
