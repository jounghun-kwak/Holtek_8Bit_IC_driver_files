#include "HT66F2390.h"
#include "Conversion.h"
#include "pc_bmh06203.h"

// RAM command
#define AMB_CMD 0x08              // Ambient temperature command
#define OBJ_CMD 0x09              // Object temperature command
#define BODY_CMD 0x0A             // Body temperature command

// EEPROM command
#define MODE_CMD 0x28             // Mode choose
#define EMISSIVITY_CMD 0x29       // Emissivity setting
#define PWM_MIN_CMD 0x2A          // Set the minimum temperature in PWM mode(default 0, unit 0.1�XC)
#define PWM_MAX_CMD 0x2B          // Set the maximum temperature in PWM mode(default 1000, unit 0.1�XC)
#define IO_CMD 0x2C               // Set the temperature threshold in IO mode(default 0, unit 0.1�XC)
#define SLEEP_CMD 0xFF            // Sleep mode setting
#define SLEEP_DATA 0x1234         // Sleep mode data

uint16 I2CRead(uint8);
void I2CWrite(uint8,uint16);
void Delay1ms(uint16);

uint16 Ambient,Object,Body,Emissivity;

void main()
{
	_wdtc=0xAB;
	i2c_init();
	
	while(1)
	{
		Emissivity=I2CRead(EMISSIVITY_CMD);		// Read emissivity value
		Delay1ms(100);
		
		Ambient=I2CRead(AMB_CMD);	// Read ambient temperature value
		Delay1ms(100);
	
		Object=I2CRead(OBJ_CMD);	// Read object temperature value
		Delay1ms(100);
	
		Body=I2CRead(BODY_CMD);		// Read body temperature value
		Delay1ms(100);
	}
}

uint16 I2CRead(uint8 command)
{    
	return IRSensor_ReadTemp(command);
}
void I2CWrite(uint8 command ,uint16 value)
{
	IRSensor_SendCOM(command,value);
}

void Delay1ms(uint16 delay)							//Delay1ms
{	
	uint16 i;											
	for(i=0;i<delay;i++) GCC_DELAY(2000);			//GCC_DELAY(0.5us)
}	
