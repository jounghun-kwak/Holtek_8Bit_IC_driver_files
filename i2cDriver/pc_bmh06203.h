/*
 *  pc_bmh06203.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_bmh06203_H__
#define __PACIFICTURY_bmh06203_H__
#include "Conversion.h"

void IRSensor_SendCOM(uint8 lu8v_com,uint16 lu16v_data);
uint16	IRSensor_ReadTemp(uint8 lu8v_com);
#endif /* __PACIFICTURY_bmh06203_H__ */