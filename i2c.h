#ifndef __I2C_H__
#define __I2C_H__
#include"types.h"
void i2c_start();
void i2c_stop();
void i2c_write(u8);
u8 i2c_read();
void i2c_ack();
void i2c_Nack();
void i2c_masterAck();
void i2c_restart();
#endif