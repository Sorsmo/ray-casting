#!/bin/bash
# chmod u+x comprun.sh
# ./comprun.sh

# exit script at first error
set -u -e

# Compile it and output to executable called 'main'
g++ -std=c++17 main.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -o main

# runs main.cpp
./main
