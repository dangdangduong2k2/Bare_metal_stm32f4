#ifndef __HW_STM32F407VET6_H__
#define __HW_STM32F407VET6_H__
#include <stdint.h>
#define __IO     volatile             /*!< Defines 'read / write' permissions */
#define __IM     volatile const      
#define __OM     volatile           
#define __IOM    volatile     

                                      /* HARDWARE DEFINE*/ 
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/*Peripherals block*/
#define PERIPH_BASE                0x40000000UL 
#define APB1PERIPH_BASE            PERIPH_BASE
#define APB2PERIPH_BASE            (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE            (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE            (PERIPH_BASE + 0x10000000UL)

/*Core block*/
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /*!< DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /*!< TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */


/*Systemtick block*/
typedef struct 
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;
#define SysTick_BASE                (SCS_BASE +  0x0010UL)
#define STK                         ((SysTick_Type*) SysTick_BASE)



/*Power block*/
typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;
#define PWR_BASE                   (APB1PERIPH_BASE + 0x7000UL)
#define PWR                        ((PWR_TypeDef *) PWR_BASE)

/*EXTI block*/
typedef struct
{
  __IO uint32_t IMR;    /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
  __IO uint32_t EMR;    /*!< EXTI Event mask register,                Address offset: 0x04 */
  __IO uint32_t RTSR;   /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
  __IO uint32_t FTSR;   /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
  __IO uint32_t SWIER;  /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
  __IO uint32_t PR;     /*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;
#define EXTI_BASE                   0x40013C00UL
#define EXTI                        ((EXTI_TypeDef*) EXTI_BASE)

/*NVIC*/
typedef struct
{
  __IOM uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  __IOM uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[24U];
  __IOM uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  __IOM uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  __IOM uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  __IOM uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  __OM  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;             
#define NVIC                        ((NVIC_Type*) NVIC_BASE)

/*System block*/
typedef struct
{
  __IO uint32_t MEMRMP;       /*!< SYSCFG memory remap register,                      Address offset: 0x00      */
  __IO uint32_t PMC;          /*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
  __IO uint32_t EXTICR[4];    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
  __IO uint32_t RESERVED[2];  /*!< Reserved, 0x18-0x1C                                                          */
  __IO uint32_t CMPCR;        /*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
} SYSCFG_TypeDef;
#define SYSCFG_BASE                 0x40013800UL 
#define SYSCFG                      ((SYSCFG_TypeDef*) SYSCFG_BASE)

/*Flash block*/
typedef struct
{
  __IO uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  __IO uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  __IO uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  __IO uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  __IO uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  __IO uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  __IO uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;
#define FLASH_ADDR_BASE            (AHB1PERIPH_BASE + 0x3C00UL)
#define FLASH                      ((FLASH_TypeDef *) FLASH_ADDR_BASE)

/*RCC block*/
typedef struct
{
  __IO uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  __IO uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  __IO uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  __IO uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  __IO uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  __IO uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  __IO uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  __IO uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  __IO uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  __IO uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  __IO uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  __IO uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  __IO uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  __IO uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  __IO uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  __IO uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  __IO uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
} RCC_TypeDef;
#define BASE_ADDR_RCC              0x40023800UL
#define RCC                        ((RCC_TypeDef*)BASE_ADDR_RCC)

/*GPIO block*/
typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;
#define BASE_ADDR_GPIOA            (AHB1PERIPH_BASE + 0x0000UL)
#define BASE_ADDR_GPIOB            (AHB1PERIPH_BASE + 0x0400UL)
#define BASE_ADDR_GPIOC            (AHB1PERIPH_BASE + 0x0800UL)
#define BASE_ADDR_GPIOD            (AHB1PERIPH_BASE + 0x0C00UL)
#define BASE_ADDR_GPIOE            (AHB1PERIPH_BASE + 0x1000UL)
#define BASE_ADDR_GPIOF            (AHB1PERIPH_BASE + 0x1400UL)
#define BASE_ADDR_GPIOG            (AHB1PERIPH_BASE + 0x1800UL)
#define BASE_ADDR_GPIOH            (AHB1PERIPH_BASE + 0x1C00UL)
#define BASE_ADDR_GPIOI            (AHB1PERIPH_BASE + 0x2000UL)
#define BASE_ADDR_GPIOJ            (AHB1PERIPH_BASE + 0x2400UL)
#define BASE_ADDR_GPIOK            (AHB1PERIPH_BASE + 0x2800UL)
#define GPIOA                      ((GPIO_TypeDef *) BASE_ADDR_GPIOA)
#define GPIOB                      ((GPIO_TypeDef *) BASE_ADDR_GPIOB)
#define GPIOC                      ((GPIO_TypeDef *) BASE_ADDR_GPIOC)
#define GPIOD                      ((GPIO_TypeDef *) BASE_ADDR_GPIOD)
#define GPIOE                      ((GPIO_TypeDef *) BASE_ADDR_GPIOE)
#define GPIOF                      ((GPIO_TypeDef *) BASE_ADDR_GPIOF)
#define GPIOG                      ((GPIO_TypeDef *) BASE_ADDR_GPIOG)
#define GPIOH                      ((GPIO_TypeDef *) BASE_ADDR_GPIOH)
#define GPIOI                      ((GPIO_TypeDef *) BASE_ADDR_GPIOI)
#define GPIOJ                      ((GPIO_TypeDef *) BASE_ADDR_GPIOJ)
#define GPIOK                      ((GPIO_TypeDef *) BASE_ADDR_GPIOK)


                                      /* DEVICE_DRIVER DEFINE*/ 
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*Clock */
#define HSI_FREQ          16000000   // Tần số HSI (16 MHz)
#define HSE_FREQ          8000000    // Tần số HSE (8 MHz)

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
#define PLLP2       0
#define PLLP4       1
#define PLLP6       2
#define PLLP8       3
// 00: PLLP = 2
// 01: PLLP = 4
// 10: PLLP = 6
// 11: PLLP = 8
extern uint32_t SystemClock;

extern __IO uint32_t SysTick;

/* GPIO */
#define INPUT             0u
#define OUTPUT            1u
#define ALT               2u
#define ANALOG            3u

#define PUSHPULL          0u
#define OPENDRAIN         1u

#define LOWSPEED          0u
#define MEDIUMSPEED       1u
#define HIGHSPEED         2u
#define VERYHIGHSPEED     3u

#define NOPULL            0u
#define PULLUP            1u
#define PULLDOWN          2u

#define GPIO_PIN_0        0u
#define GPIO_PIN_1        1u
#define GPIO_PIN_2        2u
#define GPIO_PIN_3        3u
#define GPIO_PIN_4        4u
#define GPIO_PIN_5        5u
#define GPIO_PIN_6        6u
#define GPIO_PIN_7        7u
#define GPIO_PIN_8        8u
#define GPIO_PIN_9        9u
#define GPIO_PIN_10       10u
#define GPIO_PIN_11       11u
#define GPIO_PIN_12       12u
#define GPIO_PIN_13       13u
#define GPIO_PIN_14       14u
#define GPIO_PIN_15       15u

#define GPIO_PIN_RESET    0u
#define GPIO_PIN_SET      1u

#define RISING            0u
#define FALLLING          1u
#define RISINGFALLING     2u


#endif 