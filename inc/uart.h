#pragma once

#include <avr/io.h>
#define F_CPU 1000000 
#define BAUD 9600

void UART_init();
void UART_trasmit(char);
char UART_receive();
