/*
 *  pc_timer.c
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#include "HT66F2390.h"
#include "pc_timer.h"
#include "pc_gpio.h"

/*
This timer is based on a 1ms timer.
If you want to change it, change the code.
*/
#define MAX_COUNTER 5
uint8 g_TimerID[MAX_COUNTER];
uint16 g_TimerCounter[MAX_COUNTER];
uint16 g_TimerLim[MAX_COUNTER];

uint8 switch_gpio;

#define input_index 7
#define led_index 5
uint8 i;
void __attribute((interrupt(0x14))) timer_Inter(void)
{
	_stm0af=0;
	uint8 i;
	for(i = 0; i < MAX_COUNTER; i++)
	{
		if(g_TimerID[i] == 1)
		{
			if(g_TimerCounter[i] > 200) g_TimerCounter[i] = 0;
			else g_TimerCounter[i]++; 
		}
	}

}

void timer_init(void)
{
	uint8 i;
	
	for(i = 0; i < 3; i++)
	{
		g_TimerID[i] = 0;
		g_TimerCounter[i] = 0;
		g_TimerLim[i] = 0;
	}
	/*STnCK2~STnCK0: Select STMn Counter clock
	000: fSYS/4
	001: fSYS
	010: fH/16
	011: fH/64
	100: fSUB
	101: fSUB
	110: STCKn rising edge clock
	111: STCKn falling edge clock
	These three bits are used to select th

	(8M / 64) * 0.001 = 125
	*/
    switch_gpio = 0;
    _st0ck0 = 1;
    _st0ck1 = 0;
    _st0ck2 = 0;

	_mf0e=1;_mf0f=0; //使?多??中?
	_stm0af = 0;
	_stm0ae = 1;

	_stm0c0=0b00010000;
	_stm0c1=0b11000001;
	

	_stm0ah = 32;
	_stm0al = 0;
	
	
	_st0on = 1;
	_emi=1;  //?啟?中?
	
	
	gpio_setInOut(led_index, SET_OUTPUT);
	gpio_setValue(led_index, 1);
	
	return;	
}
void timer_open(uint8 TimerID , uint16 delayTime)
{
	g_TimerID[TimerID] = 1;
	g_TimerCounter[TimerID] = 0;
	g_TimerLim[TimerID] = delayTime;
}
void timer_close(uint8 TimerID)
{
	g_TimerID[TimerID] = 0;
	g_TimerCounter[TimerID] = 0;
	g_TimerLim[TimerID] = 0;
}

/*Never use delays in interrupt handling routines.*/
void timer_process(void)
{
	
	if(g_TimerCounter[0] > g_TimerLim[0])
	{
		g_TimerCounter[0] = 0;
		timer_handler0();
	}else if(g_TimerCounter[1] > g_TimerLim[1])
	{
		g_TimerCounter[1] = 0;
		timer_handler1();	
	}else if(g_TimerCounter[2] > g_TimerLim[2])
	{
		g_TimerCounter[2] = 0;
		timer_handler2();	
	}else if(g_TimerCounter[3] > g_TimerLim[3])
	{
		g_TimerCounter[3] = 0;
		timer_handler3();	
	}else if(g_TimerCounter[4] > g_TimerLim[4])
	{
		g_TimerCounter[4] = 0;
		timer_handler4();	
	}
	
     
}

void timer_handler0(void)
{
	if(switch_gpio == 0){
		gpio_setValue(led_index, 1);
		switch_gpio = 1;
	}else{
		gpio_setValue(led_index, 0);
		switch_gpio = 0;	
	}	
}
void timer_handler1(void)
{
	;
}
void timer_handler2(void)
{
	;
}
void timer_handler3(void)
{
	;
}
void timer_handler4(void)
{
	;
}



