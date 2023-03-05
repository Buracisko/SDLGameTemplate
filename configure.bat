@echo off
mkdir build
cmake -S . -B ./build ^
-DSDL2_PATH="libraries/SDL2-2.26.3" ^
-DSDL2_IMAGE_PATH="libraries/SDL2_image-2.6.3" ^
-DSDL2_MIXER_PATH="libraries/SDL2_mixer-2.6.3" ^
-DSDL2_TTF_PATH="libraries/SDL2_ttf-2.20.2"

mklink /j "build/assets" "./assets"

echo Solution ready
pause