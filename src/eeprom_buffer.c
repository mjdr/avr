#include "eeprom_buffer.h"


uint16_t pointer = 0;

void EBUFFER_writeChar(char c){
 eeprom_write_byte((uint16_t *)pointer, c);
 pointer++;
}



