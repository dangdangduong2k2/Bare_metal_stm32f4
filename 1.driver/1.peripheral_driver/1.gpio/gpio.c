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
                    uint8_t TrigerMode,
                    uint8_t Priority)
{
    GpioEnable(GPIOx);
    GPIOx->MODER   |= INPUT    << (Pin*2);
    GPIOx->PUPDR   |= Pullmode << (Pin*2);

    //enable syscfg
    // Enable SYSCFG clock
    RCC->APB2ENR |= (1 << 14);
 // Bật clock SYSCFG

    // 2. Cấu hình PE4 làm input với pull-up
   

    // 3. Cấu hình EXTI4 kết nối với PE4
    SYSCFG->EXTICR[1] &= ~(0xF << (0 * 4)); // Xóa cấu hình EXTI4
    SYSCFG->EXTICR[1] |= (4 << (0 * 4));    // Chọn GPIOE cho EXTI4

    // 4. Cấu hình EXTI4 kích hoạt cạnh lên
    EXTI->IMR  |= (1 << 4);  // Bật ngắt cho EXTI4
    EXTI->RTSR &= ~(1 << 4);  // Kích hoạt cạnh lên (Rising edge)
    EXTI->FTSR |= (1 << 4); // Không kích hoạt cạnh xuống (Falling edge)

    // 5. Bật NVIC cho EXTI4
    NVIC->ISER[0] |= (1 << 10); // Bật ngắt EXTI4 (IRQ số 10)
    NVIC->IP[10] = (15 << 4);    // Đặt mức ưu tiên là 2 (dịch 4 bit trái)
/*
    if(15<Priority)
    {
        Priority=15;
    }
    else if(Priority<0)
    {
        Priority=0;
    }

    switch (Pin)
    {
        case GPIO_PIN_0:
            NVIC->IP[0] |= (Priority<<Pin);
            NVIC->ISER[0] |= (1<<6);
            break;
        case GPIO_PIN_1:
            NVIC->IP[0] |= (Priority<<Pin);
            NVIC->ISER[0] |= (1<<7);
            break;
        case GPIO_PIN_2:    
            NVIC->IP[0] |= (Priority<<Pin);
            NVIC->ISER[1] |= (1<<0);
            break;
        case GPIO_PIN_3:
            NVIC->IP[0] |= (Priority<<Pin);
            NVIC->ISER[1] |= (1<<1);
            break;
        case GPIO_PIN_4:
            NVIC->IP[1] |= (1<<0);
            NVIC->ISER[1] |= (1<<2);
            break;
        case GPIO_PIN_5 ... GPIO_PIN_9:
            NVIC->IP[23] |= (Priority<<4);
            NVIC->ISER[2] |= (1<<0);
            break;
        case GPIO_PIN_10 ... GPIO_PIN_15:
            NVIC->IP[40] |= (Priority<<4);
            NVIC->ISER[40] |= (1<<10);
            break;
        default:
            break;
    }



    //system alow exti
    switch ((uint32_t)GPIOx)
    {
        case (uint32_t)GPIOA:
            SYSCFG->EXTICR[Pin / 4]|=(0<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOB:
            SYSCFG->EXTICR[Pin / 4]|=(1<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOC:
            SYSCFG->EXTICR[Pin / 4]|=(2<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOD:
            SYSCFG->EXTICR[Pin / 4]|=(3<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOE:
            SYSCFG->EXTICR[1] |= (4<<0); 
            break;
        case (uint32_t)GPIOF:   
            SYSCFG->EXTICR[Pin / 4]|=(5<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOG:
            SYSCFG->EXTICR[Pin / 4]|=(6<<((Pin % 4) * 4)); 
            break;  
        case (uint32_t)GPIOH:
            SYSCFG->EXTICR[Pin / 4]|=(7<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOI:
            SYSCFG->EXTICR[Pin / 4]|=(8<<((Pin % 4) * 4)); 
            break;
        case (uint32_t)GPIOJ:
            SYSCFG->EXTICR[Pin / 4]|=(9<<((Pin % 4) * 4));
            break;
        case (uint32_t)GPIOK:
            SYSCFG->EXTICR[Pin / 4]|=(10<<((Pin % 4) * 4));
            break; 
        default:
            break;
    }

    
    switch (TrigerMode)
    {
        case RISING:
            EXTI->RTSR |= (1<<Pin);
            break;
        case FALLLING:
            EXTI->FTSR |= (1<<Pin);
            break;
        case RISINGFALLING:
            EXTI->RTSR |= (1<<Pin);
            EXTI->FTSR |= (1<<Pin);
            break;
        default:
            break;
    }
*/
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


