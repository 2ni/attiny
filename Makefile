.PHONY: compile flash

compile:
	platformio run

flash: compile
	micronucleus --run .pioenvs/digispark-pro/firmware.hex
