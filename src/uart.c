#include "uart.h"


#define MYUBRR (F_CPU/16/BAUD-1)



void UART_init(){
 UBRRH = (unsigned char)(MYUBRR>>8);
 UBRRL = (unsigned char) MYUBRR;
 UCSRB = (1<<RXEN)|(1<<TXEN);
 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void UART_trasmit(char data){
 while ( !( UCSRA & (1<<UDRE)) );
 UDR = data;
}

char UART_receive(){
 while ( !(UCSRA & (1<<RXC)));
 return UDR;
}




