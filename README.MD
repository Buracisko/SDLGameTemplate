# SDL2 Game Template
You can clone it, remove the remote and change the project name inside the CMakeLists.txt file.

## Linux prerequisites
libfreetype6-dev

## TODO
Have to update SDL_ttf with this and make a PR
~~~
target_include_directories(SDL2_ttf
  PUBLIC $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/SDL2>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
~~~

SDL_Image needs an fix regarding -fPIC

Update SDL_mixer include_directories and make a PR
~~~
target_include_directories(SDL2_mixer
    PUBLIC include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
~~~
This is just a temp solution. Proper fix should be as with the SDL_ttf

~~~
git clone https://github.com/Buracisko/SDLGameTemplate.git SDLGameTemplate
cd SDLGameTemplate
git submodule init
git submodule update
~~~
