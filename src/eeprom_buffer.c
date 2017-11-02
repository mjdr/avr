#include "eeprom_buffer.h"


uint8_t* ee_pointer = 0;

void EBUFFER_writeChar(char c){
 eeprom_write_byte(ee_pointer, c);
 ee_pointer++;
}



