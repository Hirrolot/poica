#!/bin/bash

wget https://github.com/boostorg/preprocessor/archive/boost-1.73.0.tar.gz
tar -xvzf boost-1.73.0.tar.gz
cd preprocessor-boost-1.73.0
sudo cp include/boost /usr/include -rf
