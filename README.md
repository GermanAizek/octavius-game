# Slot game
Simple slot machine game based on SDL2.
Render implemented on OpenGL.

Requirements
----------
  - CMake
  - libsdl2-dev, libsdl2-ttf-dev, libsdl2-image-dev (only Linux)
  - Any compiler for CMake
  

Build on Windows
----------
       * git clone https://github.com/GermanAizek/octavius-game.git
       * cd octavius-game
       * mkdir build
       * cd build
       * cmake .. -G "Visual Studio 16 2019" (in -G parameter select your compiler)
       * Open octavius-game.sln in build directory
       * Select "Debug" or "Release" build mode
       * Build solution
       * run the script "copy_resources_*_*.bat" to copy resources by choosing your build mode and architecture
       * Profit!
       
Build on Linux
----------
       * sudo apt install cmake libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev g++
       * git clone https://github.com/GermanAizek/octavius-game.git
       * cd octavius-game
       * mkdir build
       * cd build
       * cmake .. -G "Unix Makefiles" (in -G parameter select your compiler)
       * make (PLEASE WRITE FULL INSTRUCTION)
