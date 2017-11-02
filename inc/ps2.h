#pragma once

#include "default.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#include "eeprom_buffer.h"
#include "writer.h"


void ps2_init();
uint8_t ps2_read();
uint8_t ps2_available();
