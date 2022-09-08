/*
 *  HT66F2390_uart_sample.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/
#include "HT66F2390.h"
#include "pc_uart.h"


void main()
{
	uart_init();
	while(1)
	{
		uart_receive();	
	}
}