#include"types.h"
#include"i2c_eeprom.h"
#include"delay.h"
#include"reg51.h"
#define EEPROM_SA 0xA0

sbit gLED=P3^5;
sbit rLED=P3^4;
void main()
{
	u8 t;
	gLED = rLED = 0;
	i2c_eeprom_byte_write(EEPROM_SA,0x00,'A');
	t=i2c_eeprom_random_read(EEPROM_SA,0x00);
	delay_ms(3000);
	if(t=='A')
		gLED=1;
	else
		rLED=1;
	while(1);
}