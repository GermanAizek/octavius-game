#include "octavius.h"
#include <iostream>

struct Image {
	GLuint data;
	int width;
	int height;
};

void initVideo();
SDL_Surface* loadTexture(const char* fileName);
SDL_Surface* RenderText(const char* message, SDL_Color color, int x, int y, int size);

extern SDL_Window* window;

extern const int width;
extern const int height;