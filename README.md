# AVR
Some libraries for avr microcontrollers 

## ADC
 ```c 
 void ADC_init();
 void ADC_setChannel(char);
 uint16_t ADC_read();
 
 ```

## EEPROM_BUFFER
```c 
 void EBUFFER_writeChar(char);
```
## SPI
```c
 void SPI_init();
 char SPI_transmit(char);
 void SPI_send(char);
 char SPI_receive(void);
```
## UART
```c
 void UART_init();
 void UART_trasmit(char);
 char UART_receive();
```






