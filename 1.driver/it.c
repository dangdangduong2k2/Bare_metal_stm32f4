#include "it.h"


void EXTI0_IRQHandler(void)
{
    //start to do code

    //end to do code
    clr_line0_flag();
}
void EXTI1_IRQHandler(void)
{
    //start to do code

    //end to do code
    clr_line1_flag();
}
void EXTI2_IRQHandler(void)
{
    //start to do code

    //end to do code
    clr_line2_flag();
}
void EXTI3_IRQHandler(void)
{
    //start to do code
    //GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    //end to do code
    clr_line3_flag();
}
void EXTI4_IRQHandler(void)
{
    //start to do code
    //GpioWritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    //end to do code
    clr_line4_flag();
}
void EXTI9_5_IRQHandler(void)
{
    //line 5 interrupt
    if(line5_is_pending())
    {
        //start to do code

        //end to do code
        clr_line5_flag();   
    }
    //line 6 interrupt
    if(line6_is_pending())
    {
        //start to do code

        //end to do code
        clr_line6_flag();
    }
    //line 7 interrupt
    if(line7_is_pending())
    {
        //start to do code

        //end to do code
        clr_line7_flag();
    }   
    //line 8 interrupt
    if(line8_is_pending())  
    {
        //start to do code

        //end to do code
        clr_line8_flag();
    }
    //line 9 interrupt
    if(line9_is_pending())
    {
        //start to do code
        
        //end to do code
        clr_line9_flag();
    }
}
void EXTI15_10_IRQHandler(void)
{
    //line 10 interrupt
    if(line10_is_pending())
    {
        //start to do code

        //end to do code
        clr_line10_flag();
    }   
    //line 11 interrupt
    if(line11_is_pending())
    {
        //start to do code

        //end to do code
        clr_line11_flag();
    }
    //line 12 interrupt
    if(line12_is_pending())
    {
        //start to do code

        //end to do code
        clr_line12_flag();
    }
    //line 13 interrupt
    if(line13_is_pending())
    {
        //start to do code

        //end to do code
        clr_line13_flag();
    }
    //line 14 interrupt
    if(line14_is_pending())
    {
        //start to do code

        //end to do code
        clr_line14_flag();
    }
    //line 15 interrupt
    if(line15_is_pending())
    {
        //start to do code

        //end to do code
        clr_line15_flag();
    }
}
void SysTick_Handler(void)
{
    SysTick++;
}