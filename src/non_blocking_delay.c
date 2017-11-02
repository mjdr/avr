#include "non_blocking_delay.h"


uint32_t (*timeFunction)() = 0;

void Delay_setTimeFunction(uint32_t (*tf)()){
	timeFunction = tf;
}
void Delay_setup(Delay* delay, uint16_t duration){
	delay->startTime = (*timeFunction)();
	delay->duration = duration;
}
char Delay_isOver(Delay* delay){
	if(delay->startTime == -1)
		return 1;
	uint32_t t = (*timeFunction)();

	if(delay->startTime + delay->duration <= t){
		delay->startTime = -1;
		return 1;
	}

	return 0;
}
