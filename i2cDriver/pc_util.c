#include "HT66F2390.h"
#include "pc_util.h"


void pc_delay(uint16 del)
{
	uint16 i;
	for(i = 0; i < del ; i++) GCC_DELAY(2000);
}
