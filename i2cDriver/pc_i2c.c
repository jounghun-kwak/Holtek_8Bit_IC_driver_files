/*
 *  pc_i2c.c
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#include "HT66F2390.h"
#include "pc_i2c.h"



void i2c_init(void)
{
	;
}
void pc_i2c_start()
{
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SCL_IO = 0;
	IIC_SDA_IO = 0;
	IIC_SDA = 1;
	IIC_SCL = 1;
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SDA = 0;
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SCL = 0;
}
void pc_i2c_stop()
{
	IIC_SDA = 0;
	IIC_SDA_IO = 0;
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SCL = 1;
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SDA = 1;
	GCC_DELAY(IIC_DELAY_CNT);
}
void pc_i2c_ack()
{
	IIC_SDA_IO=0;//set SDA as output
	IIC_SDA=0;GCC_DELAY(IIC_DELAY_CNT);//SDA=0
	IIC_SCL=1;GCC_DELAY(IIC_DELAY_CNT);//SCL=1
	IIC_SCL=0;GCC_DELAY(IIC_DELAY_CNT);//SCL=0
	IIC_SDA=1;GCC_DELAY(IIC_DELAY_CNT);//SDA=1
	GCC_DELAY(80);
}
void pc_i2c_noAck()
{
	IIC_SDA_IO=0;//set SDA as output
	IIC_SDA=1;GCC_DELAY(IIC_DELAY_CNT);//SDA=1
	IIC_SCL=1;GCC_DELAY(IIC_DELAY_CNT);//SCL=1
	IIC_SCL=0;GCC_DELAY(IIC_DELAY_CNT);//SCL=0
	GCC_DELAY(80);
}
void pc_i2c_waitAck()
{
	volatile unsigned char i=0;
	IIC_SDA_IO = 1;
	GCC_DELAY(IIC_DELAY_CNT);
	IIC_SCL = 1;		
	while((IIC_SDA == 1)&&(i<250))
	{
	 	i++;
	}
	IIC_SCL = 0;
	GCC_DELAY(80);
}
void pc_i2c_wByte(uint8 WData)
{
 	unsigned char i;
	IIC_SDA_IO = 0; 
 	for(i=0;i<8;i++)
 	{
 		IIC_SCL = 0;
 		GCC_DELAY(IIC_DELAY_CNT);
 		if(WData&0x80)
 		{
 	 		IIC_SDA = 1;
 		}
 		else
 		{
 			IIC_SDA = 0;
 		}
 		GCC_DELAY(IIC_DELAY_CNT);
 		IIC_SCL = 1;
 		GCC_DELAY(IIC_DELAY_CNT);
 		WData<<=1;
 	}
 	IIC_SCL = 0;
	IIC_SDA_IO = 1;
}
uint8 pc_i2c_rByte(uint8 ack)
{
	unsigned char i,RData=0;
	IIC_SDA_IO = 1;
 	IIC_SCL = 0;
 	GCC_DELAY(IIC_DELAY_CNT);
 	IIC_SCL = 1;
	for(i=0;i<8;i++)
	{
		IIC_SCL=1;
		GCC_DELAY(IIC_DELAY_CNT);
		RData=(RData<<1)|IIC_SDA;
		IIC_SCL=0;
		GCC_DELAY(IIC_DELAY_CNT);
	}
	if (ack){
		pc_i2c_ack();
	}
	else{
		pc_i2c_noAck();
	}
	return RData;
}