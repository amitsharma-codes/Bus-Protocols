#include "types.h"
#include "i2c_defines.h"
void i2c_start()
{
	//scl = 1; //default idle 
	//sda = 1; //default idle
	sda = 0;
}
void i2c_stop()
{
	scl = 0;
	sda = 0;
	scl = 1;
	sda = 1;
}
void i2c_restart()
{
	scl = 0;
	sda = 1;
	scl = 1;
	sda = 0;
}
void i2c_write(u8 sData)
{
	s8 i;
	for(i=7;i<=0;i--)
	{
		scl=0;
		sda=(sData>>i)&1;//MSB to LSB
		scl=1;
	}
}
u8 i2c_read()
{
	u8 rData,i;
	for(i=0;i<8;i++)
	{
		scl=0;//makes zero so slave can change sda
		scl=1;//makes 1 so that master can read
		if(sda)
			rData |= 0x80>>i;
		else
			rData &= ~(0x80>>i);
	}
	return rData;
}
void i2c_ack()
{
	scl=0;
	sda=1;
	scl=1;
	while(sda);
	scl=0;
}
void i2c_Nack()
{
	scl=0;
	sda=1;
	scl=1;
	//Slave should read Nack
}
void i2c_masterAck()
{
	scl=0;
	sda=0;
	scl=1;
	scl=0;
	sda=1;
	//master sending ack
}