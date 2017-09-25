#include "spi.h"



void SPI_init(){
 DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
 SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

char SPI_transmit(char data) {
 SPDR = data;
 while(!(SPSR & (1<<SPIF)));
 return SPDR;
}

void SPI_send(char data) {
 SPI_transmit(data);
}

char SPI_receive() {
 return SPI_transmit(0x00);
}


