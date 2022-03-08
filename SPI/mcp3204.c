#include "mcp3204_defines.h"
#include "types.h"
f32 read_ADC1(u8 chNo)
{
	u16 adcDval;
	u8 i;
	cs=din=dout=clk=1;//master initialises the bus
	cs=0;
	//din=1;
	clk=0;clk=1;//clock out start bit
	//din=1;
	clk=0;clk=1;//clock out for single ended
	//din=1;
	clk=0;clk=1;//Dont care for D2
	//Selecting channel is next
	din=(chNo>>1)&1;
	clk=0;clk=1;//MSB of channel
	din=(chNo)&1;
	clk=0;clk=1;//LSB of channel
	
	clk=0;clk=1;//continue and end sampling
	clk=0;clk=1;//clk out for slave to issue
	            //null bit across dout
	for(i=0;i<12;i++)
	{
		clk=0;
		if(dout)
			adcDval |= 1<<(11-i);//update 1 @ bit pos
		else
			adcDval &= ~(1<<(11-i));//udate 0 @ bit pos
		clk=1;
	}
	cs=1;//to end communication session
	return (adcDval*(5.0/4096));
}