#include "../octavius.h"
#include <iostream>
#include <string>


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
SDL_Surface* loadTexture(std::string fileName);
SDL_Surface* RenderText(std::string message, SDL_Color color, int x, int y, int size);
void button_process_event(Button* btn, const SDL_Event* ev);
bool button(SDL_Surface* screen, Button* btn);

extern SDL_Window* window;

extern const int width;
extern const int height;