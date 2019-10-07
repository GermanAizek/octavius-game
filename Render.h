#include "octavius.h"
#include <iostream>

struct Image {
	GLuint data;
	int width;
	int height;
};

void initVideo();
SDL_Surface* loadTexture(const char* fileName);

extern SDL_Window* window;

extern const int width;
extern const int height;