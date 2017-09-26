#include "default.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "adc.h"
#include "eeprom_buffer.h"
#include "uart.h"
#include "writer.h"
#include "pwm.h"

#define E EBUFFER_writeChar
#define U UART_send


#define LED_PORT PORTB
#define LED_PIN 0
#define LED_ON LED_PORT |= (1 << LED_PIN)
#define LED_OFF LED_PORT &= ~(1 << LED_PIN)






void main(){
 DDRB |= 0b111;
 /*
 ADC_init();
 ADC_setChannel(5);
 
 
 while(1){
  int adc_val = ADC_read();
  if(adc_val > 500)
   LED_OFF;
  if(adc_val < 400)
   LED_ON;
 }
 */

 PWM_initTimer1();
 char dir = 1;
 int val = 0;
 
 while(1){ 
  PWM_setOC1A(128);
  PWM_setOC1B(128);
 }

 
}


