#include "clock.h"


void clock_init(void)
{
    uint32_t tempreg;
    /*power on*/
    tempreg = read_reg(RCC_APB1ENR,~(1<<28)); // reset bit 28 : Power interface clock disabled
    tempreg = tempreg | (1<28); // set bit 28 : Power interface clock enable
    write_reg(RCC_PLLCFGR,tempreg);	 
    /*osc option*/
    tempreg =  read_reg(RCC_CR,~(1<<16)); 
    tempreg =  tempreg | (1<<16);
    write_reg(RCC_CR,tempreg);	 
    /*PLL configuration*/
    /*M*/
    tempreg =  read_reg(RCC_PLLCFGR,~(0x3F<<0)); 
    tempreg =  tempreg | (0x25<7);
    write_reg(RCC_PLLCFGR,tempreg);	
    /*N*/
    tempreg =  read_reg(RCC_PLLCFGR,~(0xFF<14)); 
    tempreg =  tempreg | (0x150<<17);
    write_reg(RCC_PLLCFGR,tempreg);	
    /*P*/
    tempreg =  read_reg(RCC_PLLCFGR ,~(0x3<17)); 
    write_reg(RCC_PLLCFGR,tempreg);	
    /*AHB*/
    tempreg =  read_reg(RCC_CFGR,~(0xf<7)); 
    write_reg(RCC_CFGR,tempreg);	
    /*APB1*/
    tempreg =  read_reg(RCC_CFGR,~(0xe<12)); 
    tempreg =  tempreg | (0x5<<13);
    write_reg(RCC_CFGR,tempreg);	
    /*APB2*/
    tempreg =  read_reg(RCC_CFGR,~(0xe<15)); 
    tempreg =  tempreg | (0x4<<16);
    write_reg(RCC_CFGR,tempreg);	
    /*PLL ON*/
    tempreg =  read_reg(RCC_CR,~(1<<24)); 
    tempreg =  tempreg | (1<<24);
    write_reg(RCC_CR,tempreg);	
    /*wait flag on*/
    tempreg =  read_reg(RCC_CR,0xffff); 
    while(!(tempreg&(1<<25)));

    /*choose clock source*/
    tempreg =  tempreg | (2<<0);
    write_reg(RCC_CFGR,tempreg);	
    /*wait flag on*/
    tempreg =  read_reg(RCC_CFGR,0xffff); 
    while(!(tempreg&(2<<2)));
}