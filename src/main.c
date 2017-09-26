#include "default.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#include "pwm.h"





//960Hz


void main(){
 DDRB |= 0b1111;
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
 PWM_initTimer2();
 
 char dir = 1;
 int val = 0; 
 
 PWM_setOC1A(0x3FF >> 1);
 PWM_setOC1B(0x3FF >> 1);
 PWM_setOCR2(0xFF >> 1);
 _delay_ms(10000);
  
 
 while(1){ 
  if(val == 0) dir = 1;
  if(val == 0x3FF) dir = -1;
  
  PWM_setOC1A(val);
  PWM_setOC1B(val);
  PWM_setOCR2(val >> 2);
  _delay_ms(1000);
  val += dir;
 }

 
}


