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
- 

c) In which window view can we track “counter” now?

d) What is the address of the “counter” variable in memory?
