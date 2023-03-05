# SDL2 Game Template
---
## Windows setup
### 1. Clone this repository
Clone this repository without initializing the git submodules.
~~~
git clone <path> MyGame
~~~

### 2. Configure project
Run the **configure.bat** file to configure the project.

### 3. Open and build project
You can find prepared project in the **build** folder including **.sln** file.
Don't forget to set your project as the one being run by default.

---
## Linux setup
**May be obsolete ATM**

On my Debian Linux i needed to install the libfreetype6-dev library.

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

- From command line while you are in the **SDLGameTemplate** directory.
~~~
$ cmake -S . -B ../SDLGameBuild
~~~

### 3. Build the project
You can find prepared project in the **SDLGameBuild** folder, where you can "make" it.
~~~
$ make
~~~

### 4. Create symlink to assets
In order to not copy all assets, create symlink in your built game to asset folder in the source.
While being in the **SDLGameBuild** folder, run:
~~~
$ ln -s "../SDLGameTemplate/assets/" "./assets"
~~~

### 5. Run the game
You can run the **SDLGame** executable in the **SDLGameBuild** folder
~~~
SDLGameBuild$ ./SDLGame
~~~
