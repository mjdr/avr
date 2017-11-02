/*
 * time.c
 *
 *  Created on: Nov 2, 2017
 *      Author: root
 */

#include "time.h"
#include <avr/interrupt.h>


//1 time unit is 0.1 sec

uint32_t time;

ISR(TIMER0_OVF_vect){
	TCNT0 = 157;
	time++;
}



void Time_init(){
	TCCR0 |= (1 << CS02) | (1 << CS00); //prescaler
	TIMSK |= (1 << TOIE0);
	time = 0;
	sei();
}

uint32_t Time_get(){
	return time;
}

