#include "eeprom_buffer.h"


uint8_t* pointer = 0;

void EBUFFER_writeChar(char c){
 eeprom_write_byte(pointer, c);
 pointer++;
}



