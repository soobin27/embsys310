1 Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program
only once to increment “counter”. 

a) What is the value of the “counter” from the “Locals” window?
- -2147483648

b) What is the value of the “counter” in the “Registers” window?
- 0X80000000

c) Please note down if the N and/or V flags are set in the APSR register. And explain why.
- N flag is set because the value of counter turned negative
- V flag is also set because incrementing it by one caused overflow into negative value

2 If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program
once to increment “counter”

a) What happens to the value of “counter” in the “Locals” window?
- The value becomes 0

b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
- N flag is not set because the number went from -1 to 0
- V flag is not set because the operation did not cause overflow

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?

- 2147483648

b) Please note down if the N and/or V flags are set in the APSR register. And explain why.
- N flag is set 
- V flag is set

5. Move the “counter’ variable outside of main (at the top of the file):

a) What is the scope of the variable “counter”?
- counter becomes a global variable

b) Is it still visible in the “Locals” view?
- No

c) In which window view can we track “counter” now?
- We can track counter in the Watch window by adding the variable in Watch

d) What is the address of the “counter” variable in memory?
- 0x20000000 is the address of counter variable in memory

6. Change the source code to the following, then run the program in the simulator:
a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
- Value of counter is 4

b) Explain why the counter value has changed?
- The global variable counter is stored at location 0x20000000. pointer p_int was set to the same location as where counter is stored with first line in main(), then the value that the p_int was pointing to was incremented 3 times, plus the counter++. This incremented the value stored at 0x200000000 four times resulting in the counter having numeric value of 4.

7. Change the setting of IAR to run the same program on the evaluation board:

a) What is the address where “counter” is stored?
- 0x20000000

b) Is the “counter” variable stored in RAM or ROM?
- Counter is stored in RAM
- You cannot write to a ROM once it is locked
- STM32L475xx devices feature 128Kbyte of embedded SRAM which is split into two blocks.
  - 96Kbyte mapped at address 0x2000 0000 (SRAM1)
  - 32Kbyte mapped at address 0x1000 0000 with hardware parity check (SRAM2)

 
c) What is the value of “counter” at the end of the program (halting at the return 0 statement).
- Final value of counter is 4



