# compile micronucleus
git submodule add https://github.com/micronucleus/micronucleus
brew install libsub libusb-compat
cd micronucleus/commandline
make
sudo make install

# upgrade attiny
cd micronucleus/upgrade/releases
micronucleus --run upgrade-t85_default.hex
<connect attiny to usb when asked>
