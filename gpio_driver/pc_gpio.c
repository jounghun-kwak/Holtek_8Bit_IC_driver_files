#include "HT66F2390.h"
#include "pc_gpio.h"

void gpio_setWakeUpPin(uint16 index, uint8 data)
{
	if (data == 1) _pawu = _pawu | (0x01 << index);
	else _pawu = _pawu & ~ (0x01 << index);
	return;
}
void gpio_setPullHigh(uint8 index, uint8 data)
{
	uint8 i;
	i = index / 8;
	if(i == 0) 
	{
		if(data == 1) _papu = _papu | (0x01 << (index % 8));
		else _papu = _papu & ~ (0x01 << (index % 8));
	}else if(i == 1) 
	{
		if(data == 1) _pbpu = _pbpu | (0x01 << (index % 8));
		else _pbpu = _pbpu & ~ (0x01 << (index % 8));
	}else if(i == 2) 
	{
		if(data == 1) _pcpu = _pcpu | (0x01 << (index % 8));
		else _pcpu = _pcpu & ~ (0x01 << (index % 8));
	}else if(i == 3) 
	{
		if(data == 1) _pdpu = _pdpu | (0x01 << (index % 8));
		else _pdpu = _pdpu & ~ (0x01 << (index % 8));
	}else if(i == 4) 
	{
		if(data == 1) _pepu = _pepu | (0x01 << (index % 8));
		else _pepu = _pepu & ~ (0x01 << (index % 8));
	}else if(i == 5) 
	{
		if(data == 1) _pfpu = _pfpu | (0x01 << (index % 8));
		else _pfpu = _pfpu & ~ (0x01 << (index % 8));
	}else if(i == 6) 
	{
		if(data == 1) _pgpu = _pgpu | (0x01 << (index % 8));
		else _pgpu = _pgpu & ~ (0x01 << (index % 8));
	}else if(i == 7) 
	{
		if(data == 1) _phpu = _phpu | (0x01 << (index % 8));
		else _phpu = _phpu & ~ (0x01 << (index % 8));
	}
	return;
} 
void gpio_setInOut(uint8 index, uint8 data)
{
	uint8 i;
	i = index / 8;
	if(i == 0) 
	{
		if(data == 1) _pac = _pac | (0x01 << (index % 8));
		else _pac = _pac & ~ (0x01 << (index % 8));
	}else if(i == 1) 
	{
		if(data == 1) _pbc = _pbc | (0x01 << (index % 8));
		else _pbc = _pbc & ~ (0x01 << (index % 8));
	}else if(i == 2) 
	{
		if(data == 1) _pcc = _pcc | (0x01 << (index % 8));
		else _pcc = _pcc & ~ (0x01 << (index % 8));
	}else if(i == 3) 
	{
		if(data == 1) _pdc = _pdc | (0x01 << (index % 8));
		else _pdc = _pdc & ~ (0x01 << (index % 8));
	}else if(i == 4) 
	{
		if(data == 1) _pec = _pec | (0x01 << (index % 8));
		else _pec = _pec & ~ (0x01 << (index % 8));
	}else if(i == 5) 
	{
		if(data == 1) _pfc = _pfc | (0x01 << (index % 8));
		else _pfc = _pfc & ~ (0x01 << (index % 8));
	}else if(i == 6) 
	{
		if(data == 1) _pgc = _pgc | (0x01 << (index % 8));
		else _pgc = _pgc & ~ (0x01 << (index % 8));
	}else if(i == 7) 
	{
		if(data == 1) _phc = _phc | (0x01 << (index % 8));
		else _phc = _phc & ~ (0x01 << (index % 8));
	}
	return;
}
void gpio_setValue(uint8 index, uint8 data)
{
	uint8 i;
	i = index / 8;
	if(i == 0) 
	{
		if(data == 1) _pa = _pa | (0x01 << (index % 8));
		else _pa = _pa & ~ (0x01 << (index % 8));
	}else if(i == 1) 
	{
		if(data == 1) _pb = _pb | (0x01 << (index % 8));
		else _pb = _pb & ~ (0x01 << (index % 8));
	}else if(i == 2) 
	{
		if(data == 1) _pc = _pc | (0x01 << (index % 8));
		else _pc = _pc & ~ (0x01 << (index % 8));
	}else if(i == 3) 
	{
		if(data == 1) _pd = _pd | (0x01 << (index % 8));
		else _pd = _pd & ~ (0x01 << (index % 8));
	}else if(i == 4) 
	{
		if(data == 1) _pe = _pe | (0x01 << (index % 8));
		else _pe = _pe & ~ (0x01 << (index % 8));
	}else if(i == 5) 
	{
		if(data == 1) _pf = _pf | (0x01 << (index % 8));
		else _pf = _pf & ~ (0x01 << (index % 8));
	}else if(i == 6) 
	{
		if(data == 1) _pg = _pg | (0x01 << (index % 8));
		else _pg = _pg & ~ (0x01 << (index % 8));
	}else if(i == 7) 
	{
		if(data == 1) _ph = _ph | (0x01 << (index % 8));
		else _ph = _ph & ~ (0x01 << (index % 8));
	}
	return;
}
void gpio_setInterruptPin(uint8 index)
{
	if(index == 0)
	{

	}else if(index == 1)
	{

	}else if(index == 2)
	{

	}else if(index == 3)
	{

	}else if(index == 4)
	{

	}else if(index == 5)
	{

	}else if(index == 6)
	{

	}else if(index == 7)
	{
	/*
		_pas1 = (_pas1 & 0x3f) | 0x80;
		_integ = _integ | 0x0c;
		_intc0 = _intc0 | 0x24;
		_ifs2 = _ifs2 | 0x02;
	*/
		_pas1 = 0x80;
		_integ = 0x04;
		_intc0 = 0x24;
		_ifs2 = 0x02;
	}

	return;
}
uint8 gpio_getValue(uint8 index)
{
	uint8 result = 0;
	uint8 i;
	i = index / 8;
	if(i == 0) 
	{
		if((_pa & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 1) 
	{
		if((_pb & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 2) 
	{
		if((_pc & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 3) 
	{
		if((_pd & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 4) 
	{
		if((_pe & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 5) 
	{
		if((_pf & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 6) 
	{
		if((_pg & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}else if(i == 7) 
	{
		if((_ph & (0x01 << (index % 8))) == (0x01 << (index % 8))) result = 1;
		else result = 0;
	}
	return result; 
}
void pcgpio_init(void)
{
	return;	
}