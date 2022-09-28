/*
 *  pc_pwm.c
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#include "HT66F2390.h"
#include "pc_pwm.h"


void pwm_init(void)
{
	_pt0m0 = 0;
	_pt0m1 = 1;
	_ptm0dh = 0x02;
	_ptm0dl = 0x00;
	_ptm0rpl = 0x02;
	_ptm0rph = 0x00;

	_pcs04 = 0;
	_pcs05 = 1;

	_pt0ck0 = 0;
	_pt0ck1 = 0;
	_pt0ck2 = 1;

	_pt0io0 = 0;
	_pt0io1 = 1;

	_pt0on = 1;

	_ptm0al = 0x01;
	_ptm0ah = 0x00;

	_ptm0af = 1;
	_ptm0pf = 1;

	
	return;	
}
void pwm_open(uint8 index, uint8 duty)
{
	_pt0pau = 0;
	_ptm0rpl = duty;
	_ptm0rph = 0x00;
	return;
}
void pwm_stop(uint8 index)
{
	_pt0pau = 1;
	return;	
}
