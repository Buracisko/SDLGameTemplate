cmake_minimum_required(VERSION 3.13)

# Rename the project here
project(SDLGame VERSION 1.0 LANGUAGES CXX)

# Add your sources here
set(SOURCES
	src/engine.h
	src/engine.cpp
	src/main.cpp
)

source_group("Headers" FILES
	src/engine.h
)

# Set a default build type if none was specified
# Use -DCMAKE_BUILD_TYPE=XXX to se build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message("Setting build type to 'Debug' as none was specified.")
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find SDL2 and its libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

if (MSVC)
	add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
	# warning level 3
	target_compile_options(${PROJECT_NAME} PRIVATE /W3)
else()
	add_executable(${PROJECT_NAME} ${SOURCES})
	# Warn a lot
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Wconversion -Wshadow -Wno-unused-parameter)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
	SDL2::Core
	SDL2::Main
	SDL2::Image
	SDL2::Mixer
	SDL2::TTF
)

if(MSVC)
	add_custom_command(
		TARGET ${PROJECT_NAME} POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_SOURCE_DIR}/${SDL2_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_SOURCE_DIR}/${SDL2_IMAGE_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_SOURCE_DIR}/${SDL2_MIXER_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_SOURCE_DIR}/${SDL2_TTF_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif()
