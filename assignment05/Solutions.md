1 Create a function in “C” that allows swapping of two pointers.
  a Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?
  
  The main function creates a stack in SRAM for 4 addresses. Two for its variables, one for Stack Pointer and one for Link Register
  
  b What are the values in R0 & R1 when swap_pointer() is called?
  
  R0 has address 0x200003F4, R1 has address 0x200003F0
  c Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to (similar to the picture below).
  
  ![Image of Hello World](https://github.com/soobin27/embsys310/blob/main/ImageFolder/solution5.jpg)
  
