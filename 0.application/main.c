#include "main.h"



int main(void)
{
    Sys_init();
    ClockInit(PLL, AHBDIV1, APB1DIV4, APB2DIV2, PLLENABLE, HSE, 4, 168, 2);
    GpioInitOutput(GPIOA, GPIO_PIN_6, PUSHPULL, MEDIUMSPEED);
    GpioInitITinput(GPIOE, GPIO_PIN_4, PULLUP, RISINGFALLING, 15);
    GpioInitITinput(GPIOE, GPIO_PIN_3, PULLUP, RISINGFALLING, 15);
    GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    while (1)
    {
        GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        Systick_delay_ms(50);
        GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        Systick_delay_ms(50);
    }
}