#ifndef __HW_STM32F407VET6_H__
#define __HW_STM32F407VET6_H__
#include <stdint.h>
#define write_reg(addr,value)  *((uint32_t*)(addr)) = value
#define read_reg(addr,mask)  *((uint32_t*)(addr)) & mask


/*RCC block*/
#define BASE_ADDR_RCC                           0x40023800u

#define RCC_CR_OFFSET                           0x00u
#define RCC_CR                                  BASE_ADDR_RCC + RCC_CR_OFFSET

#define RCC_PLLCFGR_OFFSET                      0x04u
#define RCC_PLLCFGR                             (BASE_ADDR_RCC + RCC_PLLCFGR_OFFSET)

#define RCC_CFGR_OFFSET                         0x08u
#define RCC_CFGR                                BASE_ADDR_RCC + RCC_CFGR_OFFSET

#define RCC_CIR_OFFSET                          0x0cu
#define RCC_CIR                                 BASE_ADDR_RCC + RCC_CIR_OFFSET

#define RCC_AHB1RSTR_OFFSET                     0x10u
#define RCC_AHB1RSTR                            BASE_ADDR_RCC + RCC_AHB1RSTR_OFFSET

#define RCC_AHB2RSTR_OFFSET                     0x14u
#define RCC_AHB2RSTR                            BASE_ADDR_RCC + RCC_AHB2RSTR_OFFSET 

#define RCC_AHB3RSTR_OFFSET                     0x18u
#define RCC_AHB3RSTR                            BASE_ADDR_RCC + RCC_AHB3RSTR_OFFSET

#define RCC_APB1RSTR_OFFSET                     0x20u
#define RCC_APB1RSTR                            BASE_ADDR_RCC + RCC_APB1RSTR_OFFSET

#define RCC_APB2RSTR_OFFSET                     0x24u
#define RCC_APB2RSTR                            BASE_ADDR_RCC + RCC_APB2RSTR_OFFSET

#define RCC_AHB1ENR_OFFSET                      0x30u
#define RCC_AHB1ENR                             BASE_ADDR_RCC + RCC_AHB1ENR_OFFSET

#define RCC_AHB2ENR_OFFSET                      0x34u
#define RCC_AHB2ENR                             BASE_ADDR_RCC + RCC_AHB2ENR_OFFSET

#define RCC_AHB3ENR_OFFSET                      0x38u
#define RCC_AHB3ENR                             BASE_ADDR_RCC + RCC_AHB3ENR_OFFSET

#define RCC_APB1ENR_OFFSET                      0x40u
#define RCC_APB1ENR                             BASE_ADDR_RCC + RCC_APB1ENR_OFFSET

#define RCC_APB2ENR_OFFSET                      0x44u
#define RCC_APB2ENR                             BASE_ADDR_RCC + RCC_APB2ENR_OFFSET

#define RCC_AHB1LPENR_OFFSET                    0x50u
#define RCC_AHB1LPENR                           BASE_ADDR_RCC + RCC_AHB1LPENR_OFFSET

#define RCC_AHB2LPENR_OFFSET                    0x54u
#define RCC_AHB2LPENR                           BASE_ADDR_RCC + RCC_AHB2LPENR_OFFSET

#define RCC_AHB3LPENR_OFFSET                    0x58u
#define RCC_AHB3LPENR                           BASE_ADDR_RCC + RCC_AHB3LPENR_OFFSET

#define RCC_APB1LPENR_OFFSET                    0x60u
#define RCC_APB1LPENR                           BASE_ADDR_RCC + RCC_APB1LPENR_OFFSET

#define RCC_APB2LPENR_OFFSET                    0x64u
#define RCC_APB2LPENR                           BASE_ADDR_RCC + RCC_APB2LPENR_OFFSET

#define RCC_BDCR_OFFSET                         0x70u
#define RCC_BDCR                                BASE_ADDR_RCC + RCC_BDCR_OFFSET

#define RCC_CSR_OFFSET                          0x74u
#define RCC_CSR                                 BASE_ADDR_RCC + RCC_CSR_OFFSET

#define RCC_SSCGR_OFFSET                        0x80u
#define RCC_SSCGR                               BASE_ADDR_RCC + RCC_SSCGR_OFFSET 

#define RCC_PLLI2SCFGR_OFFSET                   0x84u
#define RCC_PLLI2SCFGR                          BASE_ADDR_RCC + RCC_PLLI2SCFGR_OFFSET

#define RCC_PLLSAICFGR_OFFSET                   0x88u
#define RCC_PLLSAICFGR                          BASE_ADDR_RCC + RCC_PLLSAICFGR_OFFSET

#define RCC_DCKCFGR_OFFSET                      0x8Cu
#define RCC_DCKCFGR                             BASE_ADDR_RCC + RCC_DCKCFGR_OFFSET


#endif 