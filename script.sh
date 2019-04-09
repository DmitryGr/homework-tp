#!/bin/bash

sudo apt-get install libssl-dev
sudo apt-get install curl


cmake "-DON_PI=1" "-DSYSROOT=../tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/arm-bcm2708hardfp-linux-gnueabi/sysroot"
make
make install
LD_LIBRARY_PATH=../lib ./usr/local/bin/Facade
