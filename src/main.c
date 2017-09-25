#define F_CPU 1000000 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"
#include "eeprom_buffer.h"
#include "uart.h"
#include "writer.h"

#define E EBUFFER_writeChar
#define U UART_send



void main(){
 DDRD = 0xFF;
 //UART_init();
 ADC_init();
 ADC_setChannel(5);
 

 for(int i = 0;i < 50;i++){
  WRITER_writeDec16(E,ADC_read());
  WRITER_writeChar(E,'\n');
 }

 while(1);
 
}


