#!/bin/bash

sudo apt-get install libssl-dev
sudo apt-get install curl

cmp=$(pwd)/tools/arm-bcm2708/arm-linux-gnueabihf/bin

PATH=$PATH:/$cmp


cmake -DON_PI=ON -D SYSROOT=./tools/arm-bcm2708/arm-linux-gnueabihf/arm-linux-gnueabihf/sysroot .
make
sudo make install DESTDIR=../
LD_LIBRARY_PATH=./usr/local/lib ./usr/local/bin/Facade
