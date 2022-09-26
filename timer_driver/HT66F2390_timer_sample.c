#include "HT66F2390.h"
#include "pc_timer.h"


void main()
{
	_we0 = 1;
	_we1 = 0;
	_we2 = 1;
	_we3 = 0;
	_we4 = 1;
	
	/*WDT function disable*/
	timer_init();
	timer_open(0, 10); 
	while(1)
	{
		timer_process();	
	}

}

