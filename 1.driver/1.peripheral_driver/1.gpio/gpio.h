#ifndef __GPIO_H__
#define __GPIO_H__
#include "../../../2.system/hw_stm32f407vet6.h"



void GpioInitOutput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t OutType,
                    uint8_t OutSpeed);
void GpioInitInput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t Pullmode);
void GpioWritePin(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t State);
                    
void GpioInitITinput(GPIO_TypeDef *GPIOx,
                    uint8_t Pin,
                    uint8_t Pullmode,
                    uint8_t TrigerMode,
                    uint8_t Priority);
uint8_t GpioReadPin(GPIO_TypeDef *GPIOx,
                    uint8_t Pin);
#endif 











