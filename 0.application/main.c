#include "main.h"

uint32_t a;
int main(void)
{
    ClockInit(PLL,AHBDIV1,APB1DIV4,APB2DIV2,PLLENABLE,HSE,4,168,2);
    Systick_init();
    GpioInitOutput(GPIOA,GPIO_PIN_6,PUSHPULL,MEDIUMSPEED);
    GpioInitITinput(GPIOE,GPIO_PIN_4,PULLUP,15,RISING);
    GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
   
    while (1)   
    {
        // a++;
        // delay_ms(1000);
        // if(GpioReadPin(GPIOE,GPIO_PIN_4)==0)
        // {
        //     GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
        //     delay_ms(100);
        //     GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
        //     delay_ms(100);
        // }
        // else if(GpioReadPin(GPIOE,GPIO_PIN_3)==0)
        // {
        //     GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
        //     delay_ms(100);
        //     GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
        //     delay_ms(100);
        // }
        // else
        // {
        //     GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
        // }
        // GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
        // Systick_delay_ms(1000);
        // GpioWritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
        // Systick_delay_ms(1000);

      
        
      
    }
}