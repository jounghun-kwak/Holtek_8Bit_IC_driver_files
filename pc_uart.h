/*
 *  pc_uart.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#ifndef __PACIFICTURY_UART_H__
#define __PACIFICTURY_UART_H__
#include "Conversion.h"
void uart_init(void);
void uart_tx(uint8 index, uint8* data, uint8 len);
void uart_send_data(uint8 tx_data);
void uart_send_str(uint8 *tx_str);
int uart_receive(void);
void Delayms(uint16 del);

#endif /* __PACIFICTURY_UART_H__ */