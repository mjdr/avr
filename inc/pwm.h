#pragma once
#include <avr/io.h>

void PWM_initTimer1();
void PWM_setOC1A(int);
void PWM_setOC1B(int);

