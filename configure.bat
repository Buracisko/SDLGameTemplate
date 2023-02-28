mkdir build
cmake -S . -B ./build
@rem -DSDL2_DIR="libraries/SDL2-2.0.16" ^
@rem -DSDL2_IMAGE_DIR="libraries/SDL2_image-2.0.5" ^
@rem -DSDL2_MIXER_DIR="libraries/SDL2_mixer-2.0.4" ^
@rem -DSDL2_TTF_DIR="libraries/SDL2_ttf-2.0.18"

mkdir "build\Debug"
@rem copy "libraries/SDL2-2.0.16\lib\x64\SDL2.dll" "build\Debug"
@rem copy "libraries/SDL2_image-2.0.5\lib\x64\*.dll" "build\Debug"
@rem copy "libraries/SDL2_mixer-2.0.4\lib\x64\*.dll" "build\Debug"
@rem copy "libraries/SDL2_ttf-2.0.18\lib\x64\*.dll" "build\Debug"

mkdir "build\Release"
@rem copy "libraries/SDL2-2.0.16\lib\x64\SDL2.dll" "build\Release"
@rem copy "libraries/SDL2_image-2.0.5\lib\x64\*.dll" "build\Release"
@rem copy "libraries/SDL2_mixer-2.0.4\lib\x64\*.dll" "build\Release"
@rem copy "libraries/SDL2_ttf-2.0.18\lib\x64\*.dll" "build\Release"

mklink /j "build/assets" "./assets"

pause