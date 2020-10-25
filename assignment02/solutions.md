1 Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program
only once to increment “counter”. 

a) What is the value of the “counter” from the “Locals” window?
- 2147483647

b) What is the value of the “counter” in the “Registers” window?
- 0X7FFFFFFF

c) Please note down if the N and/or V flags are set in the APSR register. And explain why.
- none of the flags are set. The reason the N flag is not set is because it is not a negative number. The reason v flag is also not set is because incrementing by one did not cause overflow.
