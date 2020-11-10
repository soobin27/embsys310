#if 1

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

#define DASHON 500000
#define DASHOFF 100000
#define DOTONOFF 100000
#define PAUSE 600000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+ 0x14)))

#define ORD5 (0x20)
volatile int counter = 0;


void dash(void);
void dot(void);
void FUNC_PAUSE(void);

int main()
{

    RCC_AHB2ENR |= 0x1;                 // RCC_AHB2ENR: Enable clock to GPIOA
    GPIOA_MODER = 0xABFFF7FF;           // Set GPIOA to General Purpose output mode
    
    char name[10] = "SCOTT";
    int i = 0;
    
    FUNC_PAUSE();
    while (name[i] != '\0')
    {
        switch(name[i])
        {
        case 'A' :
        dot();
        dash();
        break;

        case 'B' :
        dash();
        dot();
        dot();
        dot();
        break;

        case 'C' :
        dash();
        dot();
        dash();
        dot();
        break;

        case 'D' :
        dash();
        dot();
        dot();
        
        break;

        case 'E' :
        dot();
        break;

        case 'F' :
        dot();
        dot();
        dash();
        dot();
        break;

        case 'G' :
        dash();
        dash();
        dot();
        break;

        case 'H' :
        dot();
        dot();
        dot();
        dot();
        break;

        case 'I' :
        dot();
        dot();
        break;

        case 'J' :
        dot();
        dash();
        dash();
        dash();
        break;

        case 'K' :
        dash();
        dot();
        dash();
        break;

        case 'L' :
        dot();
        dash();
        dot();
        dot();
        break;

        case 'M' :
        dash();
        dash();
        break;
        
        case 'N' :
        dash();
        dot();
        break;
           
        case 'O' :
        dash();
        dash();
        dash();
        break;
        
        case 'P' :
        dot();
        dash();
        dash();
        dot();
        break;
        
        case 'Q' :
        dash();
        dash();
        dot();
        dash();
        break;
        
        case 'R' :
        dot();
        dash();
        dot();
        break;
        
        case 'S' :
        dot();
        dot();
        dot();
        break;
        
        case 'T' :
        dash();
        break;
        
        case 'U' :
        dot();
        dot();
        dash();
        break;
        
        case 'V' :
        dot();
        dot();
        dot();
        dash();
        break;
        
        case 'W' :
        dot();
        dash();
        dash();
        break;
        
        case 'X' :
        dot();
        dash();
        dash();
        break;
        
        case 'Y' :
        dash();
        dot();
        dash();
        dash();
        break;
        
        case 'Z' :              
        dash();
        dash();
        dot();
        dot();
        break;
        }
    FUNC_PAUSE();
    i++;

    }
}

void dash(void)
{
    counter = 0;
    GPIOA_ODR ^= ORD5;               // Turn LED ON
    while (counter < DASHON)         // Wait 
    {
        counter++;
    }
    GPIOA_ODR ^= ORD5;              // Turn LED off
    counter = 0;
    while (counter < DASHOFF)       // Wait before turnin goff
    {
        counter++;
    }
}

void dot(void)
{
    counter = 0;
    GPIOA_ODR ^= ORD5;               // Turn LED ON
    while (counter < DOTONOFF)       // Wait 
    {
        counter++;
    }
    GPIOA_ODR ^= ORD5;              // Turn LED off
    counter = 0;
    while (counter < DOTONOFF)       // Wait
    {
        counter++;
    }
}

void FUNC_PAUSE(void)
{
    counter = 0;  
    while (counter < PAUSE)             // Pause = 3x DOT time
    {
        counter ++;
    }
}

#endif
