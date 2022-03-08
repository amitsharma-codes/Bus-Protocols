#include "mcp3204.h"
u8 read_lm35(void)
{
return read_ADC1(0)*100;
}