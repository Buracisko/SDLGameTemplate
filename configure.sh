#!/bin/bash
mkdir build 2> /dev/null
cmake -S . -B ./build
ln -s "../assets" "./build/assets"
