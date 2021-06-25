#!/bin/bash

#install sdl2
sudo apt install libsdl2-dev libsdl2-2.0-0 -y;
echo “\nSDL installed Successfully\n”

#install sdl image  - if you want to display images
sudo apt install libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y;
echo “\nSDL Image installed Successfully\n”

#install sdl mixer  - if you want sound
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y;
echo “\nSDL Mixer installed Successfully\n”

#install sdl true type fonts - if you want to use text
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y;
echo “\nSDL Font installed Successfully\n”
#building the game
make;
#Message showing the game installed
echo “WOI-1971 installed Successfully”

#Making Update executable
chmod +x update.sh;
#Running the game
#make play;

