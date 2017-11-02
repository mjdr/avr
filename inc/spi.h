#pragma once

#include <avr/io.h>

#define DDR_SPI DDRB
#define DD_MOSI 3
#define DD_SCK 5

void SPI_init();
char SPI_transmit(char);
void SPI_send(char);
char SPI_receive(void);


