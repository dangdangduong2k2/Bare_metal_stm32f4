#include "main.h"

int main(void)
{
    ClockInit(PLL,AHBDIV1,APB1DIV4,APB2DIV2,PLLENABLE,HSE,25,336,2);
    GpioInitOutput(GPIOA,GPIO_PIN_0,PUSHPULL,MEDIUMSPEED);
    while (1)
    {
        
    }
}