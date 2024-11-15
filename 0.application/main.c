#include "main.h"

int main(void)
{
    ClockInit(PLL,AHBDIV1,APB1DIV4,APB2DIV2,PLLENABLE,HSE,4,168,2);
    GpioInitOutput(GPIOA,GPIO_PIN_6,PUSHPULL,MEDIUMSPEED);
    while (1)
    {
        GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
        delay_ms(1000);
        GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
        delay_ms(1000);
    }
}