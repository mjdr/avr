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
## WRITER
```c
 void WRITER_writeChar(void (*write_func)(char), char);
 void WRITER_writeString(void (*write_func)(char), char*);
 void WRITER_writeHex16(void (*write_func)(char), uint16_t);
 void WRITER_writeHex8(void (*write_func)(char), uint8_t);
 void WRITER_writeDec16(void (*write_func)(char), uint16_t);
```






