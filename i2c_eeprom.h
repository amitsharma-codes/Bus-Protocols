#ifndef __I2C_EEPROM_H__
#define __I2C_EEPROM_H__
#include "types.h"
#include "i2c.h"
u8 i2c_eeprom_random_read(u8 Saddr,u8 rBufAddr);
void i2c_eeprom_byte_write(u8 Saddr,u8 wBufAddr,u8 dat);
#endif