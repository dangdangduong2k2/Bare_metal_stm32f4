#include "gpio.h"
/*GPIO*/
static void GpioEnable(GPIO_TypeDef *GPIOx)
{
    switch ((uint32_t)GPIOx)
    {
        case (uint32_t)GPIOA:
            RCC->AHB1ENR |= (1 << 0); 
            break;
        case (uint32_t)GPIOB:
            RCC->AHB1ENR |= (1 << 1); 
            break;
        case (uint32_t)GPIOC:
            RCC->AHB1ENR |= (1 << 2); 
            break;
        case (uint32_t)GPIOD:
            RCC->AHB1ENR |= (1 << 3); 
            break;
        case (uint32_t)GPIOE:
            RCC->AHB1ENR |= (1 << 4); 
            break;
        case (uint32_t)GPIOF:
            RCC->AHB1ENR |= (1 << 5); 
            break;
        case (uint32_t)GPIOG:
            RCC->AHB1ENR |= (1 << 6); 
            break;
        case (uint32_t)GPIOH:
            RCC->AHB1ENR |= (1 << 7);
            break;
        case (uint32_t)GPIOI:
            RCC->AHB1ENR |= (1 << 8); 
            break;
        default:
            break;
    }
}

void GpioInitOutput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t OutType,
                    uint8_t OutSpeed)
{
    GpioEnable(GPIOx);
    GPIOx->MODER   |= OUTPUT   << (Pin*2);
    GPIOx->OTYPER  |= OutType  << (Pin);
    GPIOx->OSPEEDR |= OutSpeed << (Pin*2);
}

void GpioInitInput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t Pullmode)
{
    GpioEnable(GPIOx);
    GPIOx->MODER   |= INPUT    << (Pin*2);
    GPIOx->PUPDR   |= Pullmode << (Pin*2);
}

void GpioInitITinput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t Pullmode,
                    uint8_t Line, 
                    uint8_t TrigerMode,
                    uint8_t Priority)
{
    GpioEnable(GPIOx);
    GPIOx->MODER   |= INPUT    << (Pin*2);
    GPIOx->PUPDR   |= Pullmode << (Pin*2);
    //enable exti
    EXTI->IMR |= (1<<Line);
    //system alow exti
    switch ((uint32_t)GPIOx)
    {
        case (uint32_t)GPIOA:
            SYSCFG->EXTICR[Line / 4]|=(0<<Line); 
            break;
        case (uint32_t)GPIOB:
            SYSCFG->EXTICR[Line / 4]|=(1<<Line); 
            break;
        case (uint32_t)GPIOC:
            SYSCFG->EXTICR[Line / 4]|=(2<<Line); 
            break;
        case (uint32_t)GPIOH:
            SYSCFG->EXTICR[Line / 4]|=(7<<Line); 
            break;
        default:
            break;
    }
    //set priority
    if(15<Priority)
    {
        Priority=15;
    }
    if(Line==0)
    {
        NVIC->IP[6] |= (Priority<<4);
        NVIC->ISER[0] |= (1<<6);
    }
    else if(Line==1)
    {
        NVIC->IP[7] |= (Priority<<4);
        NVIC->ISER[0] |= (1<<7);
    }
    else if(Line==2)
    {
        NVIC->IP[8] |= (Priority<<4);
        NVIC->ISER[1] |= (1<<0);
    }
    else if(Line==3)
    {
        NVIC->IP[9] |= (Priority<<4);
        NVIC->ISER[1] |= (1<<1);
    }
    else if(Line==4)
    {
        NVIC->IP[10] |= (Priority<<4);
        NVIC->ISER[1] |= (1<<2);
    }
    else if(5<=Line<=9)
    {
        NVIC->IP[23] |= (Priority<<4);
        NVIC->ISER[2] |= (1<<0);
    }
    else if(10<=Line<=15)
    {
        NVIC->IP[40] |= (Priority<<4);
        NVIC->ISER[40] |= (1<<10);
    }
    __asm__("cpsie i");
}

void GpioWritePin(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t State)
{
   if(State==GPIO_PIN_SET)
   {
      GPIOx->BSRR    |= 1 << Pin;
      GPIOx->BSRR    &= ~(1 << (Pin+16));
   }
   if(State==GPIO_PIN_RESET)
   {
      GPIOx->BSRR    &= ~(1 << Pin);
      GPIOx->BSRR    |= (1 << (Pin+16));
   }
}

uint8_t GpioReadPin(GPIO_TypeDef *GPIOx,
                    uint8_t Pin)
{
   return ((GPIOx->IDR) >> Pin) & 0x1UL;
}


