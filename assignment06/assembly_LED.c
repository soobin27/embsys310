#include"stm32l475xx.h"
#include"system_stm32l4xx.h"
#include<stdint.h>

/* 
#define GPIOA_BASE 0x48000000
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+ 0x14)))
*/
void control_user_led1(int, int);// Control user LED prototype
void delay(int);


void main(void)
{

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;  // Enable clock to GPIOA. Sets RCC_AHB2ENR bit 1 to 1
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;  // GPIOA typedef __IO Mode Register 5 to control LED1
    GPIOA->MODER |= GPIO_MODER_MODE5_0;   // GPIOA Set Mode Register bits 11:10 as 0:1 to set as output 
    //uint32_t duration = 0x11110000;
    //duration |= 1UL << 4;
    //duration |= 0UL << 4;    
    
    while (1)                             
    {

        control_user_led1(1,10000);
        delay(1000000);                           // Call delay function

        //control_user_led1(1,100);
    }         
}
