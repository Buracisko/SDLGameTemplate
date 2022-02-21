# SDL2 Game Template
You can clone it, remove the remote and change the project name inside the CMakeLists.txt file.

## Configure and build
Use out of the source build in the folder separated from this Git repository

### Linux
~~~
mkdir build
cmake -S ./SDLGameTemplate -B ./build
make -C ./build/
~~~

### Windows
For our shool purposes, I recommend to use CMake GUI, because we dont have cmake easily available in the command line. Specify the source folder (Where is the source code) to this repository. Use different folder out of this repository as build folder (Where to build the binaries). Paths to SDL2 libraries will be needed in the process of configuration.

## Assets
Assets folder need to be next to the executable. You can easily achieve this by makind an junction folder.

### Linux
Example of symlink on linux. (You should use absolute path)
~~~
cd ./build/bin/assets
ln -s ($ABSOLUTE_PATH)/SDLGameTemplate/assets assets
~~~

### Windows
~~~
mklink /j ./build/assets ./SDLGameTemplate/assets
~~~