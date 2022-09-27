#include "HT66F2390.h"
#include "pc_aio.h"
#include "pc_util.h"

uint16 g_aioValue;
void main()
{
	_we0 = 1;
	_we1 = 0;
	_we2 = 1;
	_we3 = 0;
	_we4 = 1;
	
	/*WDT function disable*/
	g_aioValue = 0;
	aio_init();
	while(1)
	{
		g_aioValue = aio_getValue(0);
		pc_delay(1);
	}


}
