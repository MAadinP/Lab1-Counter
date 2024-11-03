#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int j;

    Verilated::commandArgs(argc, argv);
    
    //init top Verilog instanc
    Vtop* top = new Vtop;

    // init trace dump -> turns on signal tracing and to dump it to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    //init Vbuddy
    if (vbdOpen() !=1) return(-1);
    vbdHeader("Task 4 - Top");

    // init simulation inputs
    top->clk = 1;
    top->en = 1;
    top->rst = 1;
    top->v = vbdValue();

    // i counts the clock cycles
    for(i=0; i<200; i++) {
    
        for(j=0; j<2; j++) {
            //clock is in ps
            tfp->dump(2*i+j);
            top->clk = !top->clk;
            top->eval();
        }

        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) & 0xF);

        vbdCycle(i+1);

        top->rst = (i<2);
        
        vbdSetMode(1); // Put Vbuddy button to be armed mode
        top->en = vbdFlag();

        if(Verilated::gotFinish()) exit(0);

    }

    vbdClose();

    tfp->close();
    exit(0);
}