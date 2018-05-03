.PHONY: compile serial terminals terminal

compile:
	platformio run

serial:
	esptool.py --port `python -m serial.tools.list_ports 2>/dev/null|grep "usb"` erase_flash
	platformio run --target upload

terminals:
	platformio device list

terminal:
	platformio device monitor
