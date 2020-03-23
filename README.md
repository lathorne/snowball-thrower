## Automatic Pokemon Breeder

This will automate the breeding process for quicker shiny hunting/competitive breeding. Note that this is automated, but is slower than hatching the eggs by hand because it will fully hatch an egg before grabbing another. Note that this does not always work for eggs that have under 3840 base steps. This is because an egg is not always ready for pickup by the time the egg hatches. This can be fixed by modifying the code to bike around for a bit after the egg hatches (for eggs with base steps 1280 and 2560). 

#### How to use

The following prerequisites must be met:
*both Pokemon must be in the daycare on Route 5 (NOT in the wild area)
*an egg must be ready to grab (the daycare lady's arms must be crossed)
*a Pokemon with flame body must be in your party, NOT in the first party slot
*your part must be full
*there must be no eggs in your party
*your menu must be hovering over the map option (if you press plus, the cursor must start over the map)
*you must start on your bike
*you must have the oval charm (to make eggs ready for pickup more frequently)

If all these prereqs are met, flash the Arduino and plug it into your console/dock.

In case you see issues with controller conflicts while in docked mode, try using a USB-C to USB-A adapter in handheld mode. In dock mode, changes in the HDMI connection will briefly make the Switch not respond to incoming USB commands, skipping parts of the sequence. These changes may include turning off the TV, or switching the HDMI input. (Switching to the internal tuner will be OK, if this doesn't trigger a change in the HDMI input.)

This repository has been tested using an Arduino Uno R3.

#### Compiling and Flashing onto the Arduino UNO R3
You will need to set your [Arduino in DFU mode](https://www.arduino.cc/en/Hacking/DFUProgramming8U2), and flash its USB controller. (Note for Mac users - try [brew](https://brew.sh/index_it.html) to install the dfu-programmer with `brew install dfu-programmer`.) Setting an Arduino UNO R3 in DFU mode is quite easy, all you need is a jumper (the boards come with the needed pins in place). Please note that once the board is flashed, you will need to flash it back with the original firmware to make it work again as a standard Arduino. To compile this project you will need the AVR GCC Compiler and Tools. (Again for Mac users - try brew, adding the [osx-cross/avr](osx-cross/avr) repository, all you need to do is to type `brew tap osx-cross/avr` and `brew install avr-gcc`.) 

LUFA has been included as a git submodule, so cloning the repo like this:

```
git clone --recursive git@github.com:lathorne/swsh-pokemon-breeder.git
```

will put LUFA in the right directory.

Finally, open a terminal window in the `swsh-pokemon-breeder` directory, edit the `makefile` setting `MCU = atmega16u2`, and compile by typing `make`. Follow the [DFU mode directions](https://www.arduino.cc/en/Hacking/DFUProgramming8U2) to flash `Joystick.hex` onto your Arduino UNO R3 and you are done.

#### Thanks

Thanks to Shiny Quagsire for his [Splatoon post printer](https://github.com/shinyquagsire23/Switch-Fightstick) and progmem for his [original discovery](https://github.com/progmem/Switch-Fightstick).

Thanks to [exsilium](https://github.com/bertrandom/snowball-thrower/pull/1) for improving the command structure, optimizing the waiting times, and handling the failure scenarios. It can now run indefinitely!
