#include "octavius.h"
#include <iostream>

struct Image
{
	GLuint data;
	int width;
	int height;
};

typedef struct
{
	SDL_Rect drawRect;
	SDL_Surface* surface;
	SDL_Surface* surfaceHold;

	bool pressed = false;
} Button;

void initVideo();
SDL_Surface* loadTexture(const char* fileName);
SDL_Surface* RenderText(const char* message, SDL_Color color, int x, int y, int size);
void button_process_event(Button* btn, const SDL_Event* ev);
bool button(SDL_Surface* screen, Button* btn);

extern SDL_Window* window;

extern const int width;
extern const int height;