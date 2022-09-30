/*
 *  pc_i2c.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_I2C_H__
#define __PACIFICTURY_I2C_H__
#include "Conversion.h"

#define IIC_SLAVE_ADDRESS       0x50

#define IIC_DELAY_CNT	1

#define IIC_SCL    _pa7
#define IIC_SDA    _pa6
#define IIC_SCL_IO _pac7
#define IIC_SDA_IO _pac6

void i2c_init(void);
void pc_i2c_start();
void pc_i2c_stop();
void pc_i2c_ack();
void pc_i2c_noAck();
void pc_i2c_waitAck();
void pc_i2c_wByte(uint8 WData);
uint8 pc_i2c_rByte(uint8 ack);
#endif /* __PACIFICTURY_I2C_H__ */