#include "main.h"

uint32_t a;

int main(void)
{
    ClockInit(PLL, AHBDIV1, APB1DIV4, APB2DIV2, PLLENABLE, HSE, 4, 168, 2);
    Systick_init();
    GpioInitOutput(GPIOA, GPIO_PIN_6, PUSHPULL, MEDIUMSPEED);
    GpioInitInput(GPIOE, GPIO_PIN_3, PULLUP);
    GpioInitITinput(GPIOE, GPIO_PIN_4, PULLUP, RISINGFALLING, 15);
    GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    while (1)
    {
        if(GpioReadPin(GPIOE, GPIO_PIN_3) == GPIO_PIN_RESET)
        {
            GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
            while (!GpioReadPin(GPIOE, GPIO_PIN_3));
        }


        GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        Systick_delay_ms(6000);
        

    }
}