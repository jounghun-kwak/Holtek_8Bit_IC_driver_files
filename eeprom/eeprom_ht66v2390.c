#include "HT66F2390.h"
#include "pc_eeprom.h"

//static volatile unsigned char EEPROM_data[50] __attribute__ ((at(0x280)));

static unsigned char EEPROM_data[50];

void main()
{
	_wdtc = 0B10101111;
	
	uint16 i = 0;
	uint8 k = 0;
//	for(i=0;i<50;i++)
//  	{
//  		k = i;
//		Write_EEPROM(i,k);  
//  	}
  	
  	for(i=0;i<50;i++)
  	{
   		EEPROM_data[i] = 0x00;
   		EEPROM_data[i] = Read_EEPROM(i);  
  	}  
	while(1)
	{
		;	
	}

}