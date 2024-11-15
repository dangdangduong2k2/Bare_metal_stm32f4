#ifndef __CLOCK_H__
#define __CLOCK_H__
#include "../hw_stm32f407vet6.h"

#define HSI        0u
#define HSE        1u
#define PLL        2u

#define PLLENABLE  1u
#define PLLDISABLE 0u

#define AHBDIV1    0u
#define AHBDIV2    8u
#define AHBDIV4    9u
#define AHBDIV8    10u
#define AHBDIV16   11u
#define AHBDIV64   12u
#define AHBDIV128  13u
#define AHBDIV256  14u
#define AHBDIV512  15u
// 0xxx: system clock not divided
// 1000: system clock divided by 2
// 1001: system clock divided by 4
// 1010: system clock divided by 8
// 1011: system clock divided by 16
// 1100: system clock divided by 64
// 1101: system clock divided by 128
// 1110: system clock divided by 256
// 1111: system clock divided by 512
#define APB1DIV1    0u
#define APB1DIV2    4u
#define APB1DIV4    5u
#define APB1DIV8    6u
#define APB1DIV16   7u
// 0xx: AHB clock not divided
// 100: AHB clock divided by 2
// 101: AHB clock divided by 4
// 110: AHB clock divided by 8
// 111: AHB clock divided by 16
#define APB2DIV1    0u
#define APB2DIV2    4u
#define APB2DIV4    5u
#define APB2DIV8    6u
#define APB2DIV16   7u
// 0xx: AHB clock not divided
// 100: AHB clock divided by 2
// 101: AHB clock divided by 4
// 110: AHB clock divided by 8
// 111: AHB clock divided by 16

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