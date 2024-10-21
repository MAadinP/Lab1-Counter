// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCOUNTER_ASYNC_RST__SYMS_H_
#define VERILATED_VCOUNTER_ASYNC_RST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcounter_async_rst.h"

// INCLUDE MODULE CLASSES
#include "Vcounter_async_rst___024root.h"

// SYMS CLASS (contains all model state)
class Vcounter_async_rst__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcounter_async_rst* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcounter_async_rst___024root   TOP;

    // CONSTRUCTORS
    Vcounter_async_rst__Syms(VerilatedContext* contextp, const char* namep, Vcounter_async_rst* modelp);
    ~Vcounter_async_rst__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
