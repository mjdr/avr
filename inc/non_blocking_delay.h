#pragma once

#include <stdint.h>

typedef struct {
 int32_t startTime;
 int16_t duration;
} Delay;



void Delay_setTimeFunction(uint32_t(*)());
void Delay_setup(Delay*, uint16_t);
char Delay_isOver(Delay*);
