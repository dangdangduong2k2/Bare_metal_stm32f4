#ifndef __HW_STM32F407VET6_H__
#define __HW_STM32F407VET6_H__
#include <stdint.h>
#define __IO    volatile             /*!< Defines 'read / write' permissions */

/*Peripherals block*/
#define PERIPH_BASE                0x40000000UL 
#define APB1PERIPH_BASE            PERIPH_BASE
#define APB2PERIPH_BASE            (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE            (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE            (PERIPH_BASE + 0x10000000UL)

/*Power block*/
typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;
#define PWR_BASE                   (APB1PERIPH_BASE + 0x7000UL)
#define PWR                        ((PWR_TypeDef *) PWR_BASE)

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
#define FLASH_R_BASE               (AHB1PERIPH_BASE + 0x3C00UL)
#define FLASH                      ((FLASH_TypeDef *) FLASH_R_BASE)

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
#define GPIOA                      ((GPIO_TypeDef *) BASE_ADDR_GPIOA)
#define GPIOB                      ((GPIO_TypeDef *) BASE_ADDR_GPIOB)
#define GPIOC                      ((GPIO_TypeDef *) BASE_ADDR_GPIOC)
#define GPIOD                      ((GPIO_TypeDef *) BASE_ADDR_GPIOD)
#define GPIOE                      ((GPIO_TypeDef *) BASE_ADDR_GPIOE)
#define GPIOF                      ((GPIO_TypeDef *) BASE_ADDR_GPIOF)
#define GPIOG                      ((GPIO_TypeDef *) BASE_ADDR_GPIOG)
#define GPIOH                      ((GPIO_TypeDef *) BASE_ADDR_GPIOH)
#define GPIOI                      ((GPIO_TypeDef *) BASE_ADDR_GPIOI)































#endif 