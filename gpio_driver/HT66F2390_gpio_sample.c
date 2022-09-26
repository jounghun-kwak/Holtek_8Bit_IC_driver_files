#include "HT66F2390.h"
#include "pc_gpio.h"
#include "pc_util.h"

#define input_index 7
#define led_index 5

void __attribute((interrupt(0x08))) button(void)
{
	//if(gpio_getValue(led_index) == 0)
	//{
	//	gpio_setValue(led_index, 0);
	//}
	//_intc0 = 0x00;
}

void main()
{
	_we0 = 1;
	_we1 = 0;
	_we2 = 1;
	_we3 = 0;
	_we4 = 1;
	
	/*WDT function disable*/
	gpio_setInOut(led_index, SET_OUTPUT);
	gpio_setValue(led_index, 0);
	
	gpio_setWakeUpPin(input_index, 1);
	gpio_setPullHigh(input_index, PULL_HIGH);
	gpio_setInOut(input_index, SET_INPUT);
	gpio_setInterruptPin(input_index);
	_emi = 1;
	while(1)
	{
		pc_delay(100);
		gpio_setValue(led_index, 1);
		pc_delay(100);	
		gpio_setValue(led_index, 0);
	}

}
