# SDL2 Game Template
## How to use this
### 1. Clone this repository and initialize its submodules
~~~
git clone https://github.com/Buracisko/SDLGameTemplate.git SDLGameTemplate
cd SDLGameTemplate
git submodule init
git submodule update
~~~
### 2. Create your build using CMake
- Its recomended to use "out-of-source" build (https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#out-of-source-build-trees) that means you should create a build folder next to the repository you cloned in the step one.
In this particular example its **SDLGameBuild**.

- From command line while you are in the SDLGameTemplate directory.
~~~
cmake -S . -B ../SDLGameBuild
~~~
- Using CMake GUI
  - Specify SDLGameTemplate folder as Source
  - Specify SDLGameBuild folder as Build folder.
  - Configure (Don't forget to use the right generator accordingly to what you have available)
  - Generate

### 3. Open and build project
You can find prepared project in the **SDLGameBuild** folder.
If you use Visual Studio, you can find **.sln** file there. Don't forget to set your project as the one being run by default.
In case of Linux you probably want to run your **make** here.

---
## Linux notes
### Prerequisities
On my Debian Linux i needed to install the libfreetype6-dev library.

### SDL_image build in certain situations
SDL_Image needs an fix regarding position independent code.

Could be solved in libraries/SDL_image/CMakeLists.txt by adding an option for PIC.
~~~
cmake_dependent_option(BUILD_PIC "Build with PIC enabled" ON BUILD_SHARED_LIBS ON)
if (BUILD_PIC)
	set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()
~~~
