#include "HT66F2390.h"
#include "pc_eeprom.h"


void Write_EEPROM(uint16 addr,uint8 data)
{
  unsigned char buffer = 0;
	  
  buffer = _emi;
  _eed = data;
//  _eea = addr;
  _eeal = 0xff & addr; 
  _eeah = 0xff & (addr >> 8);
  _mp1l = 0x40;
  _mp1h = 0x01;
  _emi = 0;


  
  _iar1 |= 0b00001000;  //Enable EEPROM write
  _iar1 |= 0b00000100;  //Start EEPROM write
  while((_iar1 & 0b00000100));  //Waiting EEPROM write
  _emi = buffer;
  _iar1 = 0x00;	
  _mp1h = 0;	
}

unsigned char Read_EEPROM(uint16 addr) 
{
  unsigned char buffer = 0;
	  
  buffer = _emi;
//  _eea = addr;
  _eeal = 0xff & addr; 
  _eeah = 0xff & (addr >> 8);
  _mp1l = 0x40;
  _mp1h = 0x01;
  _emi = 0;
  

  
  _iar1 |= 0b00000010;  //Enable EEPROM read
  _iar1 |= 0b00000001;  //Start EEPROM read
  
  while((_iar1 & 0b00000001));  //Waiting EEPROM read
  _emi = buffer;
  _iar1 = 0x00;	
  _mp1h = 0;
  return _eed;
}

