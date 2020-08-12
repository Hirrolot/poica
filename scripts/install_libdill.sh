#!/bin/bash

cd libdill
./configure
make -j 8
sudo make install
