#include "types.h"
#include "mcp3204.h"
#include "reg51.h"
sbit gLED=P3^0;
sbit yLED=P3^1;
sbit rLED=P3^2;

main()
{
	f32 eAR;
	while(1)
	{
		eAR=read_ADC1(0);
		if(eAR>=0.0 && eAR<=1.0)
		{
			gLED = yLED = rLED=0;
		}
		else if(eAR>=1.0 && eAR<=2.0)
		{
			gLED =1; yLED = rLED=0;
		}
		else if(eAR>=2.0 && eAR<=3.0)
		{
			gLED =0; yLED =1; rLED=0;
		}
		else if(eAR>=3.0 && eAR<=4.0)
		{
			gLED = yLED =0; rLED =1;
		}
		else
		{
			gLED = yLED = rLED =1;
		}
	}
}