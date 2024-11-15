#include "gpio.h"

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
    GPIOx->MODER   |= OUTPUT   << (Pin*2+1);
    GPIOx->OTYPER  |= OutType  << (Pin);
    GPIOx->OSPEEDR |= OutSpeed << (Pin*2+1);
}

void GpioInitInput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t Pullmode)
{
    GpioEnable(GPIOx);
    GPIOx->MODER   |= INPUT    << (Pin*2+1);
    GPIOx->PUPDR   |= Pullmode << (Pin*2+1);
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

