#include "clock.h"

void ClockInit(uint8_t SystemClockSource,
                uint8_t AHB,
                uint8_t APB1,
                uint8_t APB2,
                uint8_t PLLEnable,
                uint8_t ClockInputPLL,
                uint16_t PLLM,
                uint16_t PLLN,
                uint16_t PLLP)
{
    /*Power CLock On*/
    RCC->APB1ENR |= 1<<28;
    /*Voltage scaling config*/
    PWR->CR |= 3<<14;
    /*FLASH PREFETCH*/
    FLASH->ACR = (1<<8) | (1<<9)| (1<<10)| (5<<0);
    /*HSE or HSI on*/
    if(ClockInputPLL==HSE)
    {
        RCC->CR |= 1<<0;  
        while (!(RCC->CR & (1<<1)));
        /*PLL use HSE or HSI*/
        RCC->PLLCFGR |= (1<<22);
    }
    else if(ClockInputPLL==HSI)
    {
        RCC->CR |= 1<<16;  
        while (!(RCC->CR & (1<<17)));
        /*PLL use HSE or HSI*/
        RCC->PLLCFGR &= ~(1<<22);
    }    
    /*PLL MNP*/
    RCC->PLLCFGR = (PLLM <<0) | (PLLN << 6) | (PLLP <<16); //25/336/2
    /*Prescaler config*/
    RCC->CFGR |= (AHB<<7); /*AHB PR 1*/
    /*APB1 PR*/
    RCC->CFGR |= (APB1<<12); /*APB1 PR 4*/
    RCC->CFGR |= (APB2<<15); /*APB2 PR 2*/
    /*PLL On*/
    if(PLLEnable==PLLENABLE)
    {
        RCC->CR &= ~(1<<24);
    }
    else if (PLLEnable==PLLDISABLE)
    {
        RCC->CR |= (1<<24);
        while (!(RCC->CR & (1<<25))); //wait flag
    }
    
    /*PLL to sysclk*/
    RCC->CFGR |= (SystemClockSource<<0);
    while (!(RCC->CFGR & (SystemClockSource<<2))); //wait flag
}
