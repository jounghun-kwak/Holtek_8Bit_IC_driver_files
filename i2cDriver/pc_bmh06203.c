/*
 *  pc_i2c.c
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#include "HT66F2390.h"
#include "pc_bmh06203.h"
#include "pc_i2c.h"

void IRSensor_SendCOM(uint8 lu8v_com,uint16 lu16v_data)
{
	pc_i2c_start();
	pc_i2c_wByte(IIC_SLAVE_ADDRESS);
	pc_i2c_waitAck();
	pc_i2c_wByte(lu8v_com);
	pc_i2c_waitAck();
	pc_i2c_wByte(lu16v_data & 0x00ff);
	pc_i2c_waitAck();
	pc_i2c_wByte(lu16v_data >> 8);
	pc_i2c_waitAck();		
	pc_i2c_wByte((lu16v_data >> 8) + (lu16v_data & 0x00ff) + lu8v_com);
	pc_i2c_waitAck();
	pc_i2c_stop();
	GCC_DELAY(IIC_DELAY_CNT);
}
uint16	IRSensor_ReadTemp(uint8 lu8v_com)
{
	volatile uint16 		lu16v_tempbyte1;
	volatile uint16 		lu16v_tempbyte2;
	volatile uint8 		lu8v_i;
	volatile uint8 		lu8v_checksum;	
	pc_i2c_start();
	pc_i2c_wByte(IIC_SLAVE_ADDRESS);		
	pc_i2c_waitAck();
	pc_i2c_wByte(lu8v_com);		
	pc_i2c_waitAck();	
	GCC_DELAY(800);
	pc_i2c_start();
	pc_i2c_wByte(IIC_SLAVE_ADDRESS + 1);		
	pc_i2c_waitAck();
	lu16v_tempbyte1 		= pc_i2c_rByte(1);GCC_DELAY(50);
	lu16v_tempbyte2 		= pc_i2c_rByte(1);GCC_DELAY(50);
	lu8v_checksum			= pc_i2c_rByte(0);GCC_DELAY(50);
	pc_i2c_stop();
	lu8v_i = lu16v_tempbyte1 + lu16v_tempbyte2;
	if(lu8v_checksum == lu8v_i)
	{
		return	(lu16v_tempbyte1 + ((lu16v_tempbyte2)<<8));
	}
	return	0;
}