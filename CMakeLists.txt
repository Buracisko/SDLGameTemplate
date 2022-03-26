cmake_minimum_required(VERSION 3.13)

# Rename the project here
project(SDL2Game VERSION 1.0 LANGUAGES CXX)

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

# SDL2
add_subdirectory(libraries/SDL2)

# SDL_mixer
add_subdirectory(libraries/SDL_mixer)

# SDL_ttf
add_subdirectory(libraries/SDL_ttf)
add_library(SDL2::ttf ALIAS SDL2_ttf)

# SDL_image
# Hotfix for linux building
if (NOT MSVC)
	add_compile_options(-fPIC)
endif()
add_subdirectory(libraries/SDL_image)

# Bunch of warnings and warnings as errors
if (MSVC)
	# warning level 4 and all warnings as errors
	add_compile_options(/W3)
else()
	# lots of warnings and all warnings as errors
	add_compile_options(-Wall -Wextra -pedantic -Werror -Wshadow -Wno-unused-parameter)
endif()


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (WIN32)
add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
else()
add_executable(${PROJECT_NAME} ${SOURCES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::image SDL2::ttf SDL2::mixer)

if(WIN32)
	add_custom_command(
		TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			$<TARGET_FILE_DIR:SDL2>
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			$<TARGET_FILE_DIR:SDL2::image>
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			$<TARGET_FILE_DIR:SDL2::mixer>
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			$<TARGET_FILE_DIR:SDL2::ttf>
			$<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif()
