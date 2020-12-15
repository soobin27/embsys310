#include"stm32l475xx.h"
#include"system_stm32l4xx.h"
#include"delay.h"

// vector table


volatile unsigned int milliseconds; // 500 * 1mS = 0.5S. Makes light blink on/off every 1s 

#define SYS_CLOCK_HZ 4000u         // 1/4MHZ = 0.25uS. 4000 * 0.25uS = 1mS

void SysTick_Initialize(void);

/* 
#define GPIOA_BASE 0x48000000
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+ 0x14)))
*/


void main(void)
{

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;  // Enable clock to GPIOA. Sets RCC_AHB2ENR bit 1 to 1
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;  // GPIOA typedef __IO Mode Register 5 to control LED1
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // GPIOA Set Mode Register bits 11:10 as 0:1 to set as output 
    SysTick_Initialize();
    while (1)                             
    {
    GPIOA->ODR ^= GPIO_ODR_OD5;
    delay(500);
    }         
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
        __disable_irq();
       milliseconds--;
        __enable_irq();
}

    
    