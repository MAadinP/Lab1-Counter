Vbuddy’s flag register has two modes of operation. The default mode is TOGGLE, which means that everything the rotary encoder switch is pressed, the flag will toggle as indicated at the bottom of the TFT screen.

However, using the vbdSetMode(1) function, you can set the mode to ONE-SHOT behaviour. Whenever the switch is pressed, the flag register is set to ‘1’ as before – now the flag is “ARMED” ready to fire. However, when the flag register is read, it immediate resets to ‘0’.

Modify counter.sv so that pressing the switch on EC11 forces the counter to pre-set to Vbuddy’s parameter value. (How?) Compile and test your design.