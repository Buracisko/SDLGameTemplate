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
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (MSVC)
	add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
	# warning level 3
	target_compile_options(${PROJECT_NAME} PRIVATE /W3)

	list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

	# SDL2
	set(SDL2_NO_DEFAULT_PATH TRUE)
	set(SDL2_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2-2.0.16" CACHE PATH "" FORCE)
	find_package(SDL2 REQUIRED)

	# SDL2_image
	set(SDL2_IMAGE_NO_DEFAULT_PATH TRUE)
	set(SDL2_IMAGE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2_image-2.0.5" CACHE PATH "" FORCE)
	find_package(SDL2_image REQUIRED)

	# SDL_Mixer
	set(SDL2_MIXER_NO_DEFAULT_PATH TRUE)
	set(SDL2_MIXER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2_mixer-2.0.4" CACHE PATH "" FORCE)
	find_package(SDL2_mixer REQUIRED)

	# SDL_ttf
	set(SDL2_TTF_NO_DEFAULT_PATH TRUE)
	set(SDL2_TTF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SDL2_ttf-2.0.18" CACHE PATH "" FORCE)
	find_package(SDL2_ttf REQUIRED)

	target_link_libraries(${PROJECT_NAME} PRIVATE
		SDL2::Core
		SDL2::Main
		SDL2::Image
		SDL2::Mixer
		SDL2::TTF
	)
else()
	# SDL2 libraries
	add_subdirectory(libraries/SDL2)
	add_subdirectory(libraries/SDL_mixer)
	add_subdirectory(libraries/SDL_ttf)
	# Add alias if its still missing
	add_library(SDL2::ttf ALIAS SDL2_ttf)

	# SDL_image Linux hotfix building
	if (NOT MSVC)
	add_compile_options(-fPIC)
	endif()
	add_subdirectory(libraries/SDL_image)
	add_executable(${PROJECT_NAME} ${SOURCES})

	# lots of warnings and all warnings as errors
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror -Wconversion -Wshadow -Wno-unused-parameter)

	target_link_libraries(${PROJECT_NAME} PRIVATE
		SDL2::SDL2
		SDL2::SDL2main
		SDL2::image
		SDL2::ttf
		SDL2::mixer
	)
endif()

#TODO: This needs elevated privileges on windows. Lets use some tailored script instead
#add_custom_command(
#	TARGET ${PROJECT_NAME} POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E create_symlink
#		${CMAKE_SOURCE_DIR}/assets
#		$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
#)

if(MSVC)
	add_custom_command(
		TARGET ${PROJECT_NAME} POST_BUILD 
			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${SDL2_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${SDL2_IMAGE_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${SDL2_MIXER_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>

			COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${SDL2_TTF_PATH}/lib/x64"
			$<TARGET_FILE_DIR:${PROJECT_NAME}>
	)
endif()
