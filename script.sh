#!/bin/bash
make clean
make
sudo dfu-programmer atmega16u2 erase
ls
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash Joystick.hex
ls
sudo dfu-programmer atmega16u2 flash Joystick.hex
sudo dfu-programmer atmega16u2 reset 
ls
sudo dfu-programmer atmega16u2 reset
