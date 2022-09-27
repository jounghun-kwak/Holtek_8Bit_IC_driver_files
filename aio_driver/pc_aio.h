/*
 *  pc_aio.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_AIO_H__
#define __PACIFICTURY_AIO_H__
#include "Conversion.h"
void aio_init(void);
uint16 aio_getValue(uint8 index);

#endif /* __PACIFICTURY_AIO_H__ */