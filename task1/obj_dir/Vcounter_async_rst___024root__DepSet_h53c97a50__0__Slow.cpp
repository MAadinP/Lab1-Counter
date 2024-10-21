// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_async_rst.h for the primary calling header

#include "verilated.h"

#include "Vcounter_async_rst___024root.h"

VL_ATTR_COLD void Vcounter_async_rst___024root___eval_initial(Vcounter_async_rst___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async_rst__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async_rst___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vcounter_async_rst___024root___eval_settle(Vcounter_async_rst___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async_rst__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async_rst___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vcounter_async_rst___024root___final(Vcounter_async_rst___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async_rst__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async_rst___024root___final\n"); );
}

VL_ATTR_COLD void Vcounter_async_rst___024root___ctor_var_reset(Vcounter_async_rst___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async_rst__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async_rst___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->count = VL_RAND_RESET_I(8);
}
