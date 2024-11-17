#include "main.h"

int main(void)
{
    ClockInit(PLL,AHBDIV1,APB1DIV4,APB2DIV2,PLLENABLE,HSE,4,168,2);
    GpioInitOutput(GPIOA,GPIO_PIN_6,PUSHPULL,MEDIUMSPEED);
    GpioInitOutput(GPIOA,GPIO_PIN_7,PUSHPULL,MEDIUMSPEED);
    GpioInitInput(GPIOE,GPIO_PIN_4,PULLUP);
    GpioInitInput(GPIOE,GPIO_PIN_3,PULLUP);
    GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
    GpioWritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET); 
    while (1)
    {
        if(GpioReadPin(GPIOE,GPIO_PIN_4)==0)
        {
            GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
            GpioWritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET); 
        }
        if(GpioReadPin(GPIOE,GPIO_PIN_3)==0)
        {
            GpioWritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
            GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET); 
        }
    }
}