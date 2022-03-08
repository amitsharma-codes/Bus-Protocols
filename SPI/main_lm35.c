#include "types.h"
#include "lm35.h"
#include "reg51.h"

sbit gLED = P3^0;
sbit yLED = P3^1;
sbit rLED = P3^2;

main()
{
	u8 degc;
	while(1)
	{
		degc = read_lm35();
		if(degc>=0 && degc<=20)
		{
			gLED = yLED = rLED=0;
		}
		else if(degc>=20 && degc<=40)
		{
			gLED =1; yLED = rLED=0;
		}
		else if(degc>=40 && degc<=60)
		{
			gLED =0; yLED =1; rLED=0;
		}
		else if(degc>=60 && degc<=80)
		{
			gLED = yLED =0; rLED =1;
		}
		else
		{
			gLED = yLED = rLED =1;
		}
	}
}