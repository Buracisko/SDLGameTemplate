#!/bin/bash
mkdir build 2> /dev/null
cmake -S . -B ./build
ln -srfn assets build/assets
