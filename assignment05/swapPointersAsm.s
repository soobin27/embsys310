    PUBLIC swapPointersAsm
    
    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB

/*******************************************************************************
Function Name   : swappointersAsm
Description     : 
C Prototype     : int swapPointersAsm (val)
                : 
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/

// The main function passes addresses of int1 and int2
// passed through R0 and R1 to the function swapPointersAsm
// This solution turned out to be pretty much same as swap char

swapPointersAsm
    LDRB        R2, [R0]        // before comparing, move value stored in address R0 to R2
    LDRB        R3, [R1]        // before comparing, move value stored in address R1 to R3
    CMP	        R2, R3          // compare value of R2 and R3
    BNE 	swap            // branch if not equal, skip to label swap
    MOVS        R0, #0          // else preparing to return 0 by moving 0 to R0
    B          exit             // branch to exit back to LR location
swap
    LDR 	R2, [R0]        // move value stored in address of R0 to R2
    LDR 	R3, [R1]        // move value stored in address of R1 to R3
    STR         R3, [R0]        // store value in R3 to memory address in R0
    STR         R2, [R1]        // store value in R2 to memory address in R0
    MOVS	R0, #1
exit                            // exit label   
    BX  LR
    END
