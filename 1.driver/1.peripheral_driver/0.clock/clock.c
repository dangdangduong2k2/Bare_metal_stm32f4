#include "clock.h"
uint32_t SystemClock;
__IO uint32_t uwTick;
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
    /*HSE or HSI on*/
    if(ClockInputPLL==HSI || SystemClockSource == HSI)
    {
        RCC->CR |= 1<<0;  
        while (!(RCC->CR & (1<<1)));
       
    }
    else if(ClockInputPLL==HSE || SystemClockSource == HSE)
    {
        RCC->CR |= 1<<16;  
        while (!(RCC->CR & (1<<17)));
    }  
    /*Power CLock On*/
    RCC->APB1ENR |= 1<<28;
    /*Voltage scaling config*/
    PWR->CR |= 3<<14;
    /*FLASH PREFETCH*/
    FLASH->ACR = (1<<8) | (1<<9)| (1<<10)| (5<<0);
    /*Prescaler config*/
    RCC->CFGR |= (AHB<<4); /*AHB PR 1*/
    RCC->CFGR |= (APB1<<10); /*APB1 PR 4*/
    RCC->CFGR |= (APB2<<13); /*APB2 PR 2*/
    /*PLL MNP*/
    RCC->PLLCFGR = (PLLM <<0) | (PLLN << 6) | ((PLLP/2-1) <<16); //25/336/2
    if(ClockInputPLL==HSI)
    {
        /*PLL use HSE or HSI*/
        RCC->PLLCFGR &= ~(1<<22);
    }
    else if(ClockInputPLL==HSE)
    {
        RCC->PLLCFGR |= (1<<22);
    }  
    /*PLL On*/
    if(PLLEnable==PLLDISABLE)
    {
        RCC->CR &= ~(1<<24);
    }
    else if (PLLEnable==PLLENABLE)
    {
        RCC->CR |= (1<<24);
        while (!(RCC->CR & (1<<25))); //wait flag
    }
    /*PLL to sysclk*/
    RCC->CFGR |= (SystemClockSource<<0);
    while (!(RCC->CFGR & (SystemClockSource<<2))); //wait flag

    SystemClock = 0;  // Xung nhịp hệ thống (final system clock)
    uint32_t PLLClock = 0;     // Xung nhịp từ PLL
    uint32_t PLLClockOutput = 0;  // Xung nhịp đầu ra của PLL
    uint32_t AHBClock = 0;     // Xung nhịp AHB (từ hệ thống)
    uint32_t APB1Clock = 0;    // Xung nhịp APB1
    uint32_t APB2Clock = 0;    // Xung nhịp APB2

    // Xác định nguồn xung nhịp hệ thống
    if (SystemClockSource == HSI) { // Sử dụng HSI (HSI = 16 MHz)
        SystemClock = HSI_FREQ;
    }
    else if (SystemClockSource == HSE) { // Sử dụng HSE
        SystemClock = HSE_FREQ;
    }
    else if (SystemClockSource == PLL) { // Sử dụng PLL
        if (PLLEnable == PLLENABLE) {
            // Tính toán xung PLL đầu ra
            if (ClockInputPLL == HSI) { // Nếu nguồn PLL là HSI
                PLLClock = HSI_FREQ;
            }
            else if (ClockInputPLL == HSE) { // Nếu nguồn PLL là HSE
                PLLClock = HSE_FREQ;
            }
            // Tính xung PLL trước khi chia với PLLP
            PLLClockOutput = (PLLClock / PLLM) * PLLN;
            // Chia PLLClockOutput bởi PLLP để có xung hệ thống
            PLLClockOutput = PLLClockOutput / PLLP;
            // Xung hệ thống là xung đầu ra của PLL
            SystemClock = PLLClockOutput;
        }
    }
}
