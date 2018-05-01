# Links
see garduino/wifisensor/attiny85/README.md
http://electronut.in/getting-started-with-attiny85-avr-programming/
https://digistump.com/wiki/digispark/tutorials/debugging

# Links i2c
https://github.com/nadavmatalon/TinyWireS

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
