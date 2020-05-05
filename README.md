## Automatic Pokemon Breeder

This will automate the breeding process for quicker shiny hunting/competitive breeding. Note that this is automated, but is slower than hatching the eggs by hand because it will fully hatch an egg before grabbing another. Note that this does not always work for eggs that have under 3840 base steps. This is because an egg is not always ready for pickup by the time the egg hatches. This can be fixed by modifying the code to bike around for a bit after the egg hatches (for eggs with base steps 1280 and 2560). 

#### How to use

Go into ```Defaults.h``` and change only two things. First, uncomment (delete the //) or comment out (adding the // before a line of code) the beginning ```#define```'s with ```BREED``` in their name so only the ```#define``` with proper number of steps is uncommented. For example, if I am planning on hatching Rolycolys, I should have ```#define BREED_3840``` uncommented and the rest of those lines commented. It is very important that only ONE of these lines is uncommented or the code will not work. If you don't know the base number of steps for the Pokemon your are hatching, look it up on [Serebii.net](https://serebii.net/). Again, for any eggs with base steps below 3840, issues may occur without modification to the code. If you still want to try and hatch these, uncomment ```#define BREED_3840```. Second, change the number next to ```NUM_BOXES``` to however many boxes you want hatched. The breeder will stop after hatching that many boxes of eggs.

The following prerequisites must be met:
* both Pokemon must be in the daycare on Route 5 (NOT in the wild area)
* an egg must be ready to grab (the daycare lady's arms must be crossed)
* a Pokemon with flame body must be in your party, NOT in the first party slot
* your party must be full
* there must be no eggs in your party
* your menu must be hovering over the map option (if you press plus, the cursor must start over the map)
* you must start on your bike
* you must have the oval charm (to make eggs ready for pickup more frequently)
* make sure the Pokemon you are hatching is already registered in your pokedex
* the first Pokemon in your party should not be holding an item (when they are moved to a box the game will ask what you want to do with their item creating an additional dialog box the breeder doesn't expect).

Also, the following settings must be set:
* send to box must be manual
* give nicknames should be set to don't
* text speed should be set to fast

If all these prereqs are met, flash the Arduino and plug it into your console/dock when your character is on Route 5 and your menu is not open (you should be able to see your character and, again, you should be on your bike). It will take a bit and then start the breeding process by opening your menu. If all is set up properly, you should be good to go.

This repository has been tested using an Arduino Uno R3.

#### Compiling and Flashing onto the Arduino UNO R3
You will need to set your [Arduino in DFU mode](https://www.arduino.cc/en/Hacking/DFUProgramming8U2), and flash its USB controller. (Note for Mac users - try [brew](https://brew.sh/index_it.html) to install the dfu-programmer with `brew install dfu-programmer`.) Setting an Arduino UNO R3 in DFU mode is quite easy, all you need is a jumper (the boards come with the needed pins in place). Please note that once the board is flashed, you will need to flash it back with the original firmware to make it work again as a standard Arduino. To compile this project you will need the AVR GCC Compiler and Tools. (Again for Mac users - try brew, adding the [osx-cross/avr](osx-cross/avr) repository, all you need to do is to type `brew tap osx-cross/avr` and `brew install avr-gcc`.) 

LUFA has been included as a git submodule, so cloning the repo like this:

```
git clone --recursive git@github.com:lathorne/swsh-pokemon-breeder.git
```

will put LUFA in the right directory.

Finally, open a terminal window in the `swsh-pokemon-breeder` directory, edit the `makefile` setting `MCU = atmega16u2`, and compile by typing `make`. Follow the [DFU mode directions](https://www.arduino.cc/en/Hacking/DFUProgramming8U2) to flash `Joystick.hex` onto your Arduino UNO R3 and you are done.

#### Possible Issues

There are occasions when I have left this running over night and it wasn't working properly in the morning. I suggest saving before plugging in the device to make sure you can restart the game if something like this happens and no progress is interrupted. Here are some known issues:

- In case you see issues with controller conflicts while in docked mode, try using a USB-C to USB-A adapter in handheld mode. In dock mode, changes in the HDMI connection will briefly make the Switch not respond to incoming USB commands, skipping parts of the sequence. These changes may include turning off the TV, or switching the HDMI input. (Switching to the internal tuner will be OK, if this doesn't trigger a change in the HDMI input.)

- Again, breeding eggs with under 3840 base steps may cause issues. When breeding eggs with 2560 bases steps, I get through 4-8 boxes before an issue occurs. The code may be adjusted to fix this.

Issues occur very rarely and can be fixed by restarting the game and the breeding process. Remember to save your game before plugging in the Arduino. Let me know if you are having other issues and I can take a look.

#### Thanks

Thank you to everyone who worked on this project before me! I just changed it to work for breeding in sword and shield. If I have failed to credit anyone who deserves it, please let me know. The following are thanks from the forked repo:

Thanks to Shiny Quagsire for his [Splatoon post printer](https://github.com/shinyquagsire23/Switch-Fightstick) and progmem for his [original discovery](https://github.com/progmem/Switch-Fightstick).

Thanks to [exsilium](https://github.com/bertrandom/snowball-thrower/pull/1) for improving the command structure, optimizing the waiting times, and handling the failure scenarios. It can now run indefinitely!
