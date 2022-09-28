/*
 *  pc_pwm.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_PWM_H__
#define __PACIFICTURY_PWM_H__
#include "Conversion.h"
void pwm_init(void);
void pwm_open(uint8 index, uint8 duty);
void pwm_stop(uint8 index);
#endif /* __PACIFICTURY_PWM_H__ */