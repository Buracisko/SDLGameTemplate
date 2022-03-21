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

~~~
git clone https://github.com/Buracisko/SDLGameTemplate.git SDLGameTemplate
cd SDLGameTemplate
git submodule init
git submodule update
~~~
