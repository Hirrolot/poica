#!/bin/bash

wget http://libdill.org/libdill-2.14.tar.gz
tar -xzf libdill-2.14.tar.gz
cd libdill-2.14
./configure
make -j 8
sudo make install
