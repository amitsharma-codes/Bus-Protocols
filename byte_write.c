#include "i2c_eeprom.h"
#include "delay.h"
void i2c_eeprom_byte_write(u8 Saddr,u8 wBufAddr,u8 dat)
{
	i2c_start();
	i2c_write(Saddr);//slave address with read or write r/w, read=1, write=0
	i2c_ack();//master takes ack
	i2c_write(wBufAddr);//writes address to start from
	i2c_ack();
	i2c_write(dat);
	i2c_ack();
	i2c_stop();
	delay_ms(10);
}
