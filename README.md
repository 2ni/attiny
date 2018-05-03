Communication by I2C between esp8266 and attiny167 based on Wire.h and USIWire.h

- arduino environment
- compiling using platformio
- attiny167 is loaded with micronucleus (digispark PRO)

# compile and flash i2c slave on attiny167
cd i2c/attiny167
pio lib install 1567
make flash
<connect attiny to usb when asked>

# compile and flash i2c master on esp
cd i2c/esp
<connect esp to usb>
make serial && make terminal

# connections
- attiny167
  SDA -> PB0 / 0
  SCL -> PB2 / 2

- esp
  SDA -> 4
  SCL -> 5

# Useful links
http://electronut.in/getting-started-with-attiny85-avr-programming/
https://digistump.com/wiki/digispark/tutorials/debugging

# Useful links i2c
https://github.com/nadavmatalon/TinyWireS
https://github.com/DzikuVx/attiny_photoresistor_i2c
pio lib info 1567

# SETUP micronucleus
git clone https://github.com/micronucleus/micronucleus
cd micronucleus/commandline
(brew install libusb libusb-compat)
make
sudo make install

# Upgrade attiny
cd micronucleus/upgrade/releases
micronucleus --run upgrade-t167_default.hex
<connect attiny to usb when asked>

# SETUP (avr-gcc)
brew tap osx-cross/avr
brew install osx-cross/avr/avr-gcc
brew install avrdude --with-usb

# SETUP (platformio)
pio init --board digispark-pro
pio update
pio lib update

# Compile with avr-gcc (native) / flash with micronucleus
WORK IN PROGRESS
(see also i2c/attiny167/modules/Makefile)
cd i2c/attiny167/modules
make flash

# i2c with TinyWire works also with attiny85 (but not with attiny167)
based on https://arduino.stackexchange.com/questions/9658/arduino-uno-master-and-attiny85-slave-i2c-connection-not-working
with TinyWire
use TinyWire from git and copy subfolder TinyWireS to lib. pio lib tynwire does not work with attiny167
set board = digispark-tiny on platformio.ini
