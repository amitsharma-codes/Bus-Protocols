#include "i2c_eeprom.h"
u8 i2c_eeprom_random_read(u8 Saddr,u8 rBufAddr)
{
	u8 rData;
	i2c_start();
	i2c_write(Saddr);
	i2c_ack();
	i2c_write(rBufAddr);
	i2c_ack();
	i2c_restart();
	i2c_write(Saddr | 0x80);
	i2c_ack();
	rData=i2c_read();
	i2c_Nack();
	i2c_stop();
	return rData;
}