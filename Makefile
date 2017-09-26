
CC = avr-gcc -I./inc -mmcu=atmega8 -Os -std=c99

all: clear compile upload

clear:
	clear
	rm -f *.o main.elf
	rm -f eeprom.hex eeprom.txt
	rm -f main.hex

compile:
	$(CC) -c src/*.c
	$(CC) -o main.elf main.o adc.o uart.o eeprom_buffer.o writer.o pwm.o
	

upload:
	sudo avrdude -c stk200 -p m8 -U flash:w:main.elf

ee:
	sudo avrdude -c stk200 -p m8 -U eeprom:r:eeprom.hex:i
	objcopy -I ihex eeprom.hex -O binary eeprom.txt
	echo '\n' >> eeprom.txt
	cat eeprom.txt
	rm -f eeprom.hex eeprom.txt
	
