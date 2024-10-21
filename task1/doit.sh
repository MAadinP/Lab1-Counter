#!/bin/sh

# cleanup
rm -rf obj/dir
rm -f counter.vcd

# Run verilator to make verilog into C++ and also include the testbench
verilator -Wall -cc --trace counter.sv --exe counter_tb.cpp

# build C++ project via make automatically generated by verilator
make -j -C obj_dir/ -f Vcounter.mk Vcounter

# run executable file
obj_dir/Vcounter

# Gtkwave bit as well
gtkwave counter.vcd