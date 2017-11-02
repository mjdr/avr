#pragma once

#include "default.h"
#include <avr/io.h>
#define BAUD 9600

void UART_init();
void UART_trasmit(char);
char UART_receive();
