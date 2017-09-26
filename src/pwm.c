#include "pwm.h"

#define PWM_10bit

void PWM_initTimer1(){
 TCCR1A |= (1 << COM1A1);
 TCCR1A |= (1 << COM1B1);
 // set none-inverting mode
 #ifdef PWM_8bit
 TCCR1A |= (1 << WGM10);
 TCCR1B |= (1 << WGM12);
 #endif
 #ifdef PWM_10bit
 TCCR1A |= (1 << WGM11) | (1 << WGM10);
 TCCR1B |= (1 << WGM12);
 #endif
 // set 10bit phase corrected PWM Mode
 TCCR1B |= (1 << CS10);
}
void PWM_setOC1A(int value){
 OCR1A = value;
}
void PWM_setOC1B(int value){
 OCR1B = value;
}

