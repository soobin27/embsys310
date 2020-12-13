/*******************************************************************************
Assignment 6.2
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
    // <TODO> Implement function in assembly

    CMP         R0, #0          // check if the user passed 0
    BEQ         clearbit        // move to body if value is 0
    CMP         R0, #1          // check if the user passed 1
    BEQ         setbit          // move to body if value is 1
    BNE         exit            // branch to exit if value is not 0 or 1

setbit
    LDR         R2, =GPIOA_BASE // Move GPIOA base address to R2 for offset
    LDR         R3, =GPIOA_ODR  // Move Output Data Register offset to R3   
    ADD         R2, R3          // offset GPIOA Base address and store to R2
    LDR         R3, [R2]        // load GPIOA output bits to R3 for manipulation
    ORR.W       R3, R3, #32     // set bit 5 of GPIOA ODR read out using OR
    STR         R3, [R2]        // store changed data to GPIOA ODR

duration
    SUB         R1, R1, #1      // start decrementing from the duration value
    CMP         R1, #0          // check if counter value is 0
    BNE         duration        // loop until counter value is 0
    STR         R1, [R2]        // turn off LED

clearbit
    LDR         R2, =GPIOA_BASE // Move GPIOA base address to R2 for offset
    LDR         R3, =GPIOA_ODR  // Move Output Data Register offset to R3
    ADD         R2, R3          // offset GPIOA Base address and store to R2     
    LDR         R3, [R2]        // load GPIOA output bits to R3 for manipulation
    BICS.W      R3, R3, #32     // clear bit 5 of GPIOA ODR read out   
    STR         R3, [R2]        // store value to GPIOA ODR address
exit
    BX          LR                       // Return to main.c
    END
