#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


void main(){
	DDRB |= (1 << PIN0);
	
	while(1){
		PORTB |= (1 << PIN0);
		_delay_ms(1000);
		PORTB &= ~(1 << PIN0);
		_delay_ms(1000);
	}
}
