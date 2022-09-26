/*
 *  pc_timer.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_TIMER_H__
#define __PACIFICTURY_TIMER_H__
#include "Conversion.h"
void timer_init(void);
void timer_open(uint8 TimerID, uint16 delayTime);
void timer_close(uint8 TimerID);
void timer_process(void);

/*Holtek-gcc does not yet support function pointer. so i made this Funtion*/
void timer_handler0(void);
void timer_handler1(void);
void timer_handler2(void);
void timer_handler3(void);
void timer_handler4(void);

#endif /* __PACIFICTURY_TIMER_H__ */