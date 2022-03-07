cmake_minimum_required(VERSION 3.13)

# Rename the project here
project(SDLGameTemplate VERSION 1.0 LANGUAGES CXX)

# Add your sources here
set(SOURCES
  src/engine.h
  src/engine.cpp
  src/sprite.h
  src/sprite.cpp
  src/main.cpp
)

source_group("Headers" FILES
	src/engine.h
	src/sprite.h
)

# Set a default build type if none was specified
# Use -DCMAKE_BUILD_TYPE=XXX to se build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# Bunch of warnings and warnings as errors
if (MSVC)
	# warning level 4 and all warnings as errors
	add_compile_options(/W3)
else()
	# lots of warnings and all warnings as errors
	add_compile_options(-Wall -Wextra -pedantic -Werror -Wshadow -Wno-unused-parameter)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# SDL2
set(SDL2_NO_DEFAULT_PATH TRUE)
set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2 CACHE PATH "" FORCE)
find_package(SDL2 REQUIRED)

# SDL_Image
set(SDL2_IMAGE_NO_DEFAULT_PATH TRUE)
set(SDL2_IMAGE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL_Image CACHE PATH "" FORCE)
find_package(SDL2_image REQUIRED)

# SDL_Mixer
set(SDL2_MIXER_NO_DEFAULT_PATH TRUE)
set(SDL2_MIXER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL_Mixer CACHE PATH "" FORCE)
find_package(SDL2_mixer REQUIRED)

# SDL_ttf
set(SDL2_TTF_NO_DEFAULT_PATH TRUE)
set(SDL2_TTF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL_ttf CACHE PATH "" FORCE)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (WIN32)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
else()
add_executable(${PROJECT_NAME} ${SOURCES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::Core SDL2::Main SDL2::Image SDL2::Mixer SDL2::TTF)

if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  	  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    	    "${SDL2_PATH}/lib/x64/SDL2.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/SDL2_Image.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/zlib1.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/libpng16-16.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/libjpeg-9.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/libtiff-5.dll"
          "${SDL2_IMAGE_PATH}/lib/x64/libwebp-7.dll"
          "${SDL2_MIXER_PATH}/lib/x64/SDL2_mixer.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libvorbisfile-3.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libvorbis-0.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libopusfile-0.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libopus-0.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libogg-0.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libmpg123-0.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libmodplug-1.dll"
          "${SDL2_MIXER_PATH}/lib/x64/libFLAC-8.dll"
          "${SDL2_TTF_PATH}/lib/x64/SDL2_ttf.dll"
	    	  $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
