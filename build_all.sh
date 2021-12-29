#!/bin/bash

# Specify the binary directory as an argument

cmake -S . -B $1
cmake --build $1
