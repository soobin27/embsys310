### 1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to Port A, then answer the following:
##  a. What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?
  - MOV     R0, #1
  - LDR.N   R1, [PC, 0x4C]  
  - STR     R0, [R1]
  
## b. What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?
  
  - LDR.N   R0, [PC, #0x54]
  - LDR     R1, [R0]  
  - ORRS.W R1, R1, #1
  - STR     R1, [R0]
  
### 2. Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:

## a. How does the calling function “func2” pass the values to the called function “func1”?
  - The compiler seems to load the first argument into R0, then stores the argument in R0 to a memory location where stack pointer SP is pointing to 0x20001FE8.
  - Then compiler uses R3, R2, R1, R0 to store the rest of the arguments and then Branches to func1.
  

## b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
  - STR R0, [SP] was generated.
  
## c. What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?
- LDR R5, [SP, #0x8]
  
d. Any other observations?
- When I passed 7 arguments to func1, the compiler stored assigned each "extra" arguments to memory by storing first R0 to memory location in SP offset by 2 bytes.
- Then then the next memory was offset by 1, then finally the memory location in SP was used to store the last "extra" argument.

### 3. Following the queue data structure approach, design, implement and test a stack data structure:
a. The following is the list of requirements:
i. The stack should have a predefined size
ii. The stack supports “int” data types.
iii. Provide a function to initialize the stack internals.
iv. Provide a function to push an element onto the stack
v. Provide a function to pop an element off the stack.
vi. Provide a function that returns 1 if stack is empty.
vii. Provide a function that returns 1 if stack is full.
b. Provide a list of the test cases and their implementation inside of main.c
c. Separate the stack code from the rest of the test code (create stack.h & stack.c)


