#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int j;

    Verilated::commandArgs(argc, argv);
    
    //init top Verilog instanc
    Vcounter* top = new Vcounter;

    // init trace dump -> turns on signal tracing and to dump it to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    //init Vbuddy
    if (vbdOpen() != 1) return(-1);
    vbdHeader("Lab 1: Counter - Task 3 Challenge Step 2");

    // init simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->ld = 0;
    top->v = 10;

    // i counts the clock cycles
    for(i=0; i<600; i++) {
    
        for(j=0; j<2; j++) {
            //clock is in ps
            tfp->dump(2*i+j);
            top->clk = !top->clk;
            top->eval();
        }

        vbdSetMode(1);
        top->rst = (vbdValue() == 100); // We are going to reset the counter if the encoder val == 100
        top->clk = vbdFlag();

        vbdHex(4, (int(top->count) >> 16) & 0xF);
        vbdHex(3, (int(top->count) >> 8) & 0xF);
        vbdHex(2, (int(top->count) >> 4) & 0xF);
        vbdHex(1, int(top->count) & 0xF);
        vbdCycle(i+1);

        if(Verilated::gotFinish()) exit(0);

    }

    vbdClose();

    tfp->close();
    exit(0);
}