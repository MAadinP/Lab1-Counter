// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_async_rst.h for the primary calling header

#include "verilated.h"

#include "Vcounter_async_rst__Syms.h"
#include "Vcounter_async_rst___024root.h"

void Vcounter_async_rst___024root___ctor_var_reset(Vcounter_async_rst___024root* vlSelf);

Vcounter_async_rst___024root::Vcounter_async_rst___024root(Vcounter_async_rst__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcounter_async_rst___024root___ctor_var_reset(this);
}

void Vcounter_async_rst___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcounter_async_rst___024root::~Vcounter_async_rst___024root() {
}
