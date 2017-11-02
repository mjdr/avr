#include "default.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "writer.h"
#include "eeprom_buffer.h"
#include "ps2.h"



void init(){
 ps2_init();
 
 DDRB |= 0b100;
}

void main(){
 init();
 while(1){
  if(ps2_available() > 0){
   WRITER_writeHex8(EBUFFER_writeChar, ps2_read());
   WRITER_writeString(EBUFFER_writeChar, "\n");
   PORTB ^= 0b100;
  }
 }

}
