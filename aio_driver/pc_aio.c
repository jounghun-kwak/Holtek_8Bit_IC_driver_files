#include "HT66F2390.h"
#include "pc_aio.h"

unsigned short vr;
void __attribute((interrupt(0x1C))) aio_isr(void)
{
	_start=1; _start=0;									//Start A/D conversion			
	vr=(_sadoh*256)+_sadol;
}

void aio_init(void)
{
	_wdtc=0xAB;										//Turn off the watchdog timer
	_sadc0=0b00111000;								//ADEN=ADRFS=1, SAC[3:0]=1000(AN8)
	_pds0=0x03;										//Set PD0 function to AN8
	_ade=1;											//Enable ADC interrupt
	_emi=1;											//Enable EMI
	_start=1; _start=0;								////Start A/D conversion
}
uint16 aio_getValue(uint8 index)
{
	uint16 result = 0;
	result = vr;
	return result; 
}