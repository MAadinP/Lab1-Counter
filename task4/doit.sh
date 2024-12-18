#!/bin/sh

# cleanup
rm -rf obj_dir/
rm -f top.vcd

# attach the Vbuddy
~/Documents/iac/lab0-devtools/tools/attach_usb.sh

# Run verilator to make verilog into C++ and also include the testbench
verilator -Wall -cc --trace top.sv --exe top_tb.cpp

# build C++ project via make automatically generated by verilator
make -j -C obj_dir/ -f Vtop.mk Vtop

# run executable file
obj_dir/Vtop

# Gtkwave bit as well
gtkwave counter.vcd