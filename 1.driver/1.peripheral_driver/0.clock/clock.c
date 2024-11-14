#include "clock.h"


void clock_init(void)
{
    uint32_t tempreg;
    tempreg = read_reg(RCC_PLLCFGR,0xffff);
    write_reg(RCC_PLLCFGR,(1<<22));	

}