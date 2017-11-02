
CC = avr-gcc -I./inc -mmcu=atmega8 -Os -std=c99

all: clear compile upload

clear:
	clear
	rm -rf bin
	mkdir bin

compile:
	$(CC) -c src/*.c
	#$(CC) -o main.elf main.o adc.o uart.o eeprom_buffer.o writer.o pwm.o a_comp.o
	$(CC) -o main.elf main.o eeprom_buffer.o writer.o ps2.o
	mv *.o bin/
	mv *.elf bin/

upload:
	sudo avrdude -c stk200 -p m8 -U flash:w:bin/main.elf

ee:
	sudo avrdude -c stk200 -p m8 -U eeprom:r:eeprom.hex:i
	objcopy -I ihex eeprom.hex -O binary eeprom.txt
	echo '\n' >> eeprom.txt
	cat eeprom.txt
	rm -f eeprom.hex eeprom.txt
