1 Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program
only once to increment “counter”. 

a) What is the value of the “counter” from the “Locals” window?
- -2147483648

b) What is the value of the “counter” in the “Registers” window?
- 0X80000000

c) Please note down if the N and/or V flags are set in the APSR register. And explain why.
- N flag is set because the number turned negative
- V flag is also set because incrementing it by one caused overflow into negative value
