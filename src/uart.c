#include "uart.h"


#define MYUBRR (F_CPU/16/BAUD-1)
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1) 



void UART_init(){
 UBRRH = (unsigned char)(MYUBRR>>8);
 UBRRL = (unsigned char) MYUBRR;
 UCSRB = (1<<RXEN)|(1<<TXEN);
 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void UART_trasmit(char data){
 //wait_for_one(UCSRA, UDRE);
 while ( !( UCSRA & (1<<UDRE)) );
 UDR = data;
}

char UART_receive(){
 wait_for_one(UCSRA, RXC);
 return UDR;
}




