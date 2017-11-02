#include "ps2.h"
#include <avr/interrupt.h>



#define PS2_STATE_IDLE 0
#define PS2_STATE_READ 1
#define PS2_STATE_CRC  2

#define DATA (PINB & 1)
#define PS_BUFFER_SIZE 10

uint8_t ps2_buffer[PS_BUFFER_SIZE];
uint8_t ps2_read_pointer = 0;
uint8_t ps2_write_pointer = 0;

volatile char state = PS2_STATE_IDLE;
volatile char counter,data,crc;


void ps2_write(uint8_t);

ISR(INT0_vect){
 char d = DATA;
 if(state == PS2_STATE_IDLE && d == 0){
   state = PS2_STATE_READ;
   data = counter = 0;
   return;
 }
 
 if(state == PS2_STATE_READ){
  if(counter == 8) {
    crc = d;
    state = PS2_STATE_CRC;
  }
  else 
   data |= (d << counter++);
  
  return;
 }
 if(state == PS2_STATE_CRC && d == 1){
  state = PS2_STATE_IDLE;
  ps2_write(data);
  return;
 }
}

void ps2_init(){
 
 MCUCR |= (1 << ISC01) | (1 << ISC00);
 GICR |= (1 << INT0);
 DDRB &= ~(1 << PIN0);
 DDRD &= ~(1 << PIN2);

 DDRB |= (1 << PIN2);
 
 sei();
 
}

uint8_t ps2_available(){
 if(ps2_read_pointer == ps2_write_pointer)
  return 0;
 else if(ps2_read_pointer > ps2_write_pointer)
  return ps2_write_pointer - ps2_read_pointer + 1;
 else
  return (PS_BUFFER_SIZE - ps2_read_pointer) + ps2_write_pointer + 1;
}
uint8_t ps2_read() {
 uint8_t data = ps2_buffer[ps2_read_pointer++];
 if(ps2_read_pointer == PS_BUFFER_SIZE)
  ps2_read_pointer = 0;
 return data;
}

void ps2_write(uint8_t data){
 ps2_buffer[ps2_write_pointer++] = data;
 if(ps2_write_pointer == PS_BUFFER_SIZE)
  ps2_write_pointer = 0;
}
