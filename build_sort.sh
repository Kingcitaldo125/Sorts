#!/bin/bash

# Specify the binary directory, and the sort name (as snake/upppercase), as arguments

cmake -S . -B $1 -DBUILD_ALL=false -DBUILD_$2=true
cmake --build $1
