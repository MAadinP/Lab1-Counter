#include "Vcounter.h"
#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

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
        for(int j=0; j<2; j++) {
            //clock is in ps
            tfp->dump(2*i+j);
            top->clk = !top->clk;
            top->eval();
        }

        // change rst and en during the sim
        top->rst = (i<2) | (i == 15);
        top->en = (i>4);

        if(Verilated::gotFinish()) exit(0);

    }

    tfp->close();
    exit(0);
}