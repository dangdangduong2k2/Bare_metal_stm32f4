#include "delay.h"

void delay_us(uint32_t delay_time) 
{
    uint32_t delay_cycles = 1000 * SystemClock; 
    for (unsigned int i = 0; i < delay_cycles*delay_time; i++) 
    {
        asm("nop"); 
    }
}

void delay_ms(uint32_t delay_time) 
{
    uint32_t delay_cycles = 1000 * SystemClock; 
    for (unsigned int i = 0; i < delay_cycles*delay_time*1000; i++) 
    {
        asm("nop"); 
    }
}