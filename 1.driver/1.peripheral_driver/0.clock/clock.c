#include "clock.h"

void ClockInit(void)
{
    /*Power CLock On*/
    RCC->APB1ENR |= 1<<28;
    /*Voltage scaling config*/
    PWR->CR |= 3<<14;
    /*FLASH PREFETCH*/
    FLASH->ACR = (1<<8) | (1<<9)| (1<<10)| (5<<0);
    /*HSE on*/
    RCC->CR |= 1<<16;  
    while (!(RCC->CR & (1<<17)));
    /*PLL config*/
    #define PLL_M 	25
    #define PLL_N 	336
    #define PLL_P 	2  
    RCC->PLLCFGR = (PLL_M <<0) | (PLL_N << 6) | (PLL_P <<16) | (1<<22);
    /*Prescaler config*/
    RCC->CFGR &= ~(1<<4); /*AHB PR 1*/
    /*APB1 PR*/
    RCC->CFGR |= (5<<10); /*APB1 PR 4*/
    RCC->CFGR |= (4<<13); /*APB2 PR 2*/
    /*PLL On*/
    RCC->CR |= (1<<24);
    while (!(RCC->CR & (1<<25))); //wait flag
    /*PLL to sysclk*/
    RCC->CFGR |= (2<<0);
    while (!(RCC->CFGR & (2<<2))); //wait flag
}
