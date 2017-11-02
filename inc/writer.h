#pragma once
#include <avr/io.h>


void WRITER_writeChar(void (*write_func)(char), char);
void WRITER_writeString(void (*write_func)(char), char*);
void WRITER_writeHex16(void (*write_func)(char), uint16_t);
void WRITER_writeHex8(void (*write_func)(char), uint8_t);
void WRITER_writeDec16(void (*write_func)(char), uint16_t);
