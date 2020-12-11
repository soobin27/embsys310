#include"stm32l475xx.h"
#include"system_stm32l4xx.h"
/* 
#define GPIOA_BASE 0x48000000
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+ 0x14)))
*/
void delay(void);                       // delay function prototype
void delay(void)                        // delay function
{
    int counter = 0;
    while (counter < 50000)
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

