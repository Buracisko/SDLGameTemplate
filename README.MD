# SDL2 Game Template

## Windows setup
### 1. Clone this repository
Clone this repository.
~~~
git clone <path> MyGame
~~~

### 2. Configure project
Run the **configure.bat** file to configure the project.

### 3. Open and build project
You can find prepared project in the **build** folder including **.sln** file.
Don't forget to set your project as the one being run by default.

## Linux setup
### 0. Have a required libraries installed
In order to buil the project, you need dev libraries: *SL2*, *SDL2_image*, *SDL2_mixer* and *SDL2_ttf*.
You can get usually get those from your system package manager. In case of **Debian**/**Ubuntu**
~~~
apt-get update
apt-get install ibsdl2-dev libsdl2-mixer-dev libsdl2-image-dev libsdl2-ttf-dev
~~~
### 1. Clone this repository
Clone this repository.
~~~
git clone <path> MyGame
~~~

### 2. Configure project
Run the **configure.sh** file to configure the project.

### 3. Build and run the project
Build the project depending on your generator. It is *make* in most cases.
~~~
cd ./build
make
./SDLGame
~~~
