.PHONY: compile flash

compile:
	platformio run

flash: compile
	micronucleus --run .pioenvs/digispark-pro/firmware.hex
	# pio run -t upload (micronucleus 2.2 not recognized by platformio)
