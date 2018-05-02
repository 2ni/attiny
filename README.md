# Links
see garduino/wifisensor/attiny85/README.md
http://electronut.in/getting-started-with-attiny85-avr-programming/
https://digistump.com/wiki/digispark/tutorials/debugging

# Links i2c
https://github.com/nadavmatalon/TinyWireS
https://github.com/DzikuVx/attiny_photoresistor_i2c
pio lib info 1567

# SETUP micronucleus
git clone https://github.com/micronucleus/micronucleus
cd micronucleus/commandline
(brew install libusb libusb-compat)
make
sudo make install

# Upgrade Attiny
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

# Compile with platformio / flash with micronucleus
cd digistump/
make flash
<connect attiny to usb when asked>

# Compile with avr-gcc / flash with micronucleus
(see also modules/Makefile)
cd digistump/modules
make flash

# i2c with platformio & attiny85 works
based on https://arduino.stackexchange.com/questions/9658/arduino-uno-master-and-attiny85-slave-i2c-connection-not-working
with TinyWire
use TinyWire from git and copy subfolder TinyWireS to lib. pio lib tynwire does not work with attiny167
set board = digispark-tiny on platformio.ini

# i2c with platoformio & attiny167 works
based on https://github.com/x821938/UltraLowPower_WeatherStation/blob/master/AtTiny85/
see src/i2c_slave.cpp with UISWire
