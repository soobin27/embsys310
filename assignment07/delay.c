#include "delay.h"

extern int milliseconds;

void delay(unsigned int duration)
{
    milliseconds = duration;
    while (milliseconds > 0)
    {
    }


}