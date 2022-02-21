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

### Windows - Visual Studio
1. Its good to create a root folder for the project, where we put copy of this repository, build folder and possibly the needed libraries. E.g.
~~~
GameTemplate
|-- SDLGameTemplate (this repository)
|-- build (build target directory)
|-- SDL2-2.0.16 (SDL2 library)
|-- SDL2_image-2.0.5 (SDL2_image library)
~~~

2. Download the **SDL2** and **SDL2-Image** **Development ibraries**. They could be downloaded here: [SDL2](https://www.libsdl.org/download-2.0.php), [SDL2-image](https://www.libsdl.org/projects/SDL_image/). Extract them to the folder from the point 1 or somewhere else on your computer, so you can refer them from multiple projects.

3. Clone this repository to the folder from point 1
~~~
git clone https://github.com/Buracisko/SDLGameTemplate.git
~~~

4. Run the CMake GUI app and setup
	1. **Where is the source code** to the clonned repository (SDLGameTemplate)
	2. **Where to build the binaries** to the build folder created in the root folder from point 1
	3. Click configure and wait for the error while the CMake is trying to find the SDL2 library.
	4. Set the **SDL2_PATH** to the directory where you extracted the library from step 2 (e.g. *C:\Development\SDL2-2.0.16*)
	5. Click configure again and do the same for **SDL2_IMAGE_PATH**
	6. After setting both SDL2, SDL2_Image libraries and successfull configuration, you should be able to **Generate** the project.
	7. Navigate to the **build** directory where the .sln file should be ready or click **Open Project**
5. In the Visual Studio's Solution Explorer set the SDLGameTemplate as a StartupProject.
6. You should be able to build and run project. In order to have all the assests available to the game you need to link the assets in the repository to the build folder - lower notes


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
