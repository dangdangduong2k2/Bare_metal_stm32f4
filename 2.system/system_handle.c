#include "hw_stm32f407vet6.h"

uint32_t SystemClock;
__IO uint32_t SysTick;


void Systick_init(void)
{
    STK->CTRL &= ~(1<<0); // Disable systick
    STK->CTRL |= (1<<2); // use core clock, External Clock (AHB/8) :0, Processor Clock (AHB) :1
    STK->CTRL |= (1<<1); // Enable interrupt
    STK->LOAD = 0x000000; // clear reload value
    STK->VAL = 0x000000; // clear current value
    STK->LOAD = (SystemClock / 1000) - 1; // 1000: 1ms(fred what you want), HSI 16MHz default, reinit after init clock 
    STK->CTRL |= (1<<0); // Enable systick    
}
uint32_t Get_systick(void)
{
    return SysTick;
}
void Sys_init(void)
{   SystemClock=HSI_FREQ;
    Systick_init();
}
void Systick_delay_ms(uint32_t delay)
{
    uint32_t start_tick = 0;
    start_tick = Get_systick();
    while(Get_systick()-start_tick != delay);
}