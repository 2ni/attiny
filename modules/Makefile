.PHONY: all flash clean

# install avr-gcc http://maxembedded.com/2015/06/setting-up-avr-gcc-toolchain-on-linux-and-mac-os-x/
# from https://blog.ithasu.org/2014/12/blinking-a-digispark-without-arduino-ide/

DEVICE     = attiny167           # avr35, see avr-help for all possible devices
CLOCK      = 16000000           # 16Mhz
OBJECTS    = main.o             # Add more objects for each .c file here

UPLOAD = micronucleus --run
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

# symbolic targets:
all:	main.hex

.c.o:
	$(COMPILE) -c $< -o $@

flash:	all
	$(UPLOAD) main.hex

clean:
	rm -f main.hex main.elf $(OBJECTS)

main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf

