1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock to Port A, then answer the following:
  a. What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?
  - MOV     R0, #1
  - LDR.N   R1, [PC, 0x4C]  
  - STR     R0, [R1]
  
  b. What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?
  
  - LDR.N   R0, [PC, #0x54]
  - LDR     R1, [R0]  
  - ORRS.W R1, R1, #1
  - STR     R1, [R0]


