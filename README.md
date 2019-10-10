# Slot game
Simple slot machine game based on SDL2.
Render implemented on OpenGL.

Screenshots:
----------
![Slotgame](https://germanaizek.github.io/screens/octavius.png "Slotgame")

Requirements
----------
  - CMake
  - Any compiler for CMake
  - libsdl2-dev, libsdl2-ttf-dev, libsdl2-image-dev (only Linux), freeglut3-dev (if not in system Linux)

Build on Windows
----------
       * git clone https://github.com/GermanAizek/octavius-game.git
       * cd octavius-game
       * mkdir build
       * cd build
       * cmake .. -G "Visual Studio 16 2019" (in -G parameter select your compiler)
       * Open octavius-game.sln in build directory
       * Select "Debug" or "Release" build mode and build solution
       * run the script "copy_resources_*_*.bat" to copy resources by choosing your build mode and architecture
       * run octavius.exe in build directory
       * Profit!
       
Build on Linux
----------
       * sudo apt install cmake libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev freeglut3-dev g++
       * git clone https://github.com/GermanAizek/octavius-game.git
       * cd octavius-game
       * mkdir build
       * cd build
       * cmake .. -G "Ninja" (in -G parameter select your compiler)
       * ninja
       * copy gamedata folder from res to build directory
       * run ./octavius in build directory
       * Profit!
