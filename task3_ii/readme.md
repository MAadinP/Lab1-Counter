Vbuddy’s flag register has two modes of operation. The default mode is TOGGLE, which means that everything the rotary encoder switch is pressed, the flag will toggle as indicated at the bottom of the TFT screen.

However, using the vbdSetMode(1) function, you can set the mode to ONE-SHOT behaviour. Whenever the switch is pressed, the flag register is set to ‘1’ as before – now the flag is “ARMED” ready to fire. However, when the flag register is read, it immediate resets to ‘0’.

Modify counter.sv so that pressing the switch on EC11 forces the counter to pre-set to Vbuddy’s parameter value. (How?) Compile and test your design.

**SV File**

- updated the sv file to remove the load and the v inputs
- Will now count up every cycle

![svfile_task3ii](image.png)

**GTKWave**

![wavesim_task3ii](image-1.png)

- Shows that there are no other inputs and that the couter just counts up every cycle

**Vbuddy**

![vbuddysim_task3ii](image-2.png)

- the output shows that it ends at 30 (HEX) so this equates to 48 (DEC), this is because there are two clock cyle delays at the start while resetting and the counter starting at 0
- The testbench only ran for 50 clock cycles