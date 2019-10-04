#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
using namespace std;

SDL_Window* window;

const int width = 640;
const int height = 480;

void drawCube(float xrf, float yrf, float zrf);
