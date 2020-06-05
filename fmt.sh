#!/bin/bash

find . -iname *.h -o -iname *.c | xargs clang-format -i
