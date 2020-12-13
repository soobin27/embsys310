#include"stm32l475xx.h"
#include"system_stm32l4xx.h"

/* ************************************************************************
*****   ASSIGNMENT 6.1 USE CMSIS TO IMPLEMENT CODE TO BLINK USER LED1*****
**************************************************************************/

void delay(void);                       // delay function prototype
void delay(void)                        // delay function
{
    uint32_t counter = 0;               // delay counter
    while (counter < 50000)             // while counter is less than duration value
    {
        counter++;
    }
}
void main(void)
{

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;  // Enable clock to GPIOA. Sets RCC_AHB2ENR bit 1 to 1
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;  // GPIOA typedef __IO Mode Register 5 to control LED1
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // GPIOA Set Mode Register bits 11:10 as 0:1 to set as output 
        
    while (1)                             
    {
        GPIOA->ODR |= GPIO_ODR_OD5;        // Setting GPIOA BIT 5 to one turns on LED
        delay();                           // Call delay function
        GPIOA->ODR &= ~GPIO_ODR_OD5;       // Setting GPIOA BIT 5 to zero turns off LED
        delay();                           // Call delay function
    }         
}

