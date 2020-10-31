#if 1

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

#define CNT 50000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+ 0x14)))

#define ORD5 (0x20)


int main()
{
int counter = 0;
    RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA
    GPIOA_MODER = 0xABFFF7FF;           // Set GPIOA to General Purpose output mode
   while (1)
    {
        counter = 0;
        while (counter < CNT)
        {
            counter++;
        }
       GPIOA_ODR ^= ORD5;              // **** Assignment toggle LED using bitwise XOR
        
       counter = 0;
       while (counter < CNT)
       {
           counter++;
       }
       GPIOA_ODR ^= ORD5;              // **** Assignment toggle LED using bitwise XOR
       }         
}
#endif
