#include "types.h"
void delay_ms(u16 itime)
{
	u16 i,j;
	for(i=0;i<itime;i++)
	for(j=0;j<122;j++);
}