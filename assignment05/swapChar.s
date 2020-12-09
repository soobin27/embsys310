    PUBLIC swapChar
    
    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB

/*******************************************************************************
Function Name   : swapChar
Description     : 
C Prototype     : int SwapChar (val)
                : 
Parameters      : R0: integer val
Return value    : R0
*******************************************************************************/

// The main function passes char1 and char2 which contain a character each
// passed through R0 and R1 to the function swapChar

// For some reason in the Tera Term output, PrintString function printed extra letter. Did not have time to debug...

swapChar
    CMP	        R0, R1          // compare value of R0 and R1
    BNE 	swap            // branch if not equal, skip to label swap
    MOVS        R0, #0          // else preparing to return 0 by moving 0 to R0
    B          exit             // branch to exit back to LR location
swap
    LDRB	R2, [R0]        // move value stored in address of R0 to R2
    LDRB	R3, [R1]        // move value stored in address of R1 to R3
    STRB        R3, [R0]        // store value in R3 to memory address in R0
    STRB        R2, [R1]        // store value in R2 to memory address in R0
    MOVS	R0, #1
exit                            // exit label   
    BX  LR
    END
