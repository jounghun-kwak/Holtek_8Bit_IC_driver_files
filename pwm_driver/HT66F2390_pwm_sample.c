#include "HT66F2390.h"
#include "pc_pwm.h"

void main()
{
	_we0 = 1;
	_we1 = 0;
	_we2 = 1;
	_we3 = 0;
	_we4 = 1;
	
	/*WDT function disable*/
	pwm_init();
	pwm_open(0, 2);
	while(1);

}
