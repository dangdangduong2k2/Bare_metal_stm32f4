#ifndef __CLOCK_H__
#define __CLOCK_H__
#include "hw_stm32f407vet6.h"

#define SYS_TIMEOUT 0u
#define SYS_OK      1u
#define SYS_ERROR   2u

void ClockInit(uint8_t SystemClockSource,
                uint8_t AHB,
                uint8_t APB1,
                uint8_t APB2,
                uint8_t PLLEnable,
                uint8_t ClockInputPLL,
                uint16_t PLLM,
                uint16_t PLLN,
                uint16_t PLLP);
#endif