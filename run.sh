#!/bin/bash

apt-get install libcurl4-openssl-dev
sudo apt-get install sendmail
sudo apt install gnutls-dev
sudo apt-get install libghc-gsasl-dev

cd /Decorator/cpp-sources/configs
touch config.ini
echo '''[chat]
token=864316932:AAE-lSpWQAogQ3wGhGclGhko34NjCF9fKbw
chat_id=-1001188063631
[email]
from=icpcchampion@gmail.com
to=dmitrygrigorev2000@gmail.com
password=dadadimas''' > config.ini

cmake .
make
sudo make install
