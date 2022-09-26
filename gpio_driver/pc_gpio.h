/*
 *  pc_gpio.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 */

#ifndef __PACIFICTURY_GPIO_H__
#define __PACIFICTURY_GPIO_H__
#include "Conversion.h"

/*

Numberring

PA0 = index0 ~
PA7 = index7
PB0 = index8
PB1 = index9
*/

#define PULL_HIGH 	1
#define PULL_LOW  	0
#define SET_INPUT 	1
#define SET_OUTPUT 	0

void pcgpio_init(void);


void gpio_setWakeUpPin(uint16 index, uint8 data);

void gpio_setPullHigh(uint8 index, uint8 data);
void gpio_setInOut(uint8 index, uint8 data);
void gpio_setValue(uint8 index, uint8 data);
void gpio_setInterruptPin(uint8 index);
uint8 gpio_getValue(uint8 index);

uint8 gpio_read(uint8 index);
void gpio_write(uint8 index, uint8 data);

#endif /* __PACIFICTURY_UART_H__ */