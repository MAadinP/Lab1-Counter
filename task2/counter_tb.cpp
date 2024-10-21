#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i; //tracks the clock cycles. If clock goes high and then low that is one cycle
    int clk;

    Verilated::commandArgs(argc, argv);
    
    //init top Verilog instanc
    Vcounter* top = new Vcounter;

    // init trace dump -> turns on signal tracing and to dump it to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    //init Vbuddy
    if (vbdOpen() !=1) return(-1);
    vbdHeader("Lab 1: Counter");

    // init simulation inputs -> intial signal values (only the top level signals are visible)
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // running many simulations
    // i counts the clock cycles
    for(i=0; i<300; i++) {
        
        // Dump variables into vcd file and flop the clock signal
        // This also outputs the trace for each half of the clocks cycle 
        // and forces the model to to evaluate both edges of the clock
        for(clk=0; clk<2; clk++) {
            //clock is in ps
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        /*
        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) >> 16 & 0xF);
        OR OTHERWISE
        */ 

        vbdPlot(int(top->count), 0, 255);

        vbdCycle(i+1);
        // change rst and en during the sim
        top->rst = (i <2) | (i == 15);
        
        top->en = vbdFlag();
        // top->en = (i>4);

        if(Verilated::gotFinish()) exit(0);

    }

    vbdClose();

    tfp->close();
    exit(0);
}