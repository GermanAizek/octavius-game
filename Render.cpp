#include "Classes/Render.h"

extern const int width = 1920;
extern const int height = 1080;

void initVideo()
{
	// SDL video device init
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Unable to init SDL, error: " << SDL_GetError() << '\n';
		exit(1);
	}

	// SDL TTF init
	TTF_Init();

	// SDL GL init
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	window = SDL_CreateWindow("Slot machine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);

	// init GLContext
	SDL_GLContext glcontext = SDL_GL_CreateContext(window);
	if (window == nullptr)
		exit(1);

	// init opengl
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

SDL_Surface* loadTexture(const std::string& fileName) {
	SDL_Surface* image = IMG_Load(fileName.c_str());
	if (!image)
	{
		printf("IMG_LoadTexture: %s\n", IMG_GetError());
		exit(0);
	}
	image = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_RGBA8888, 0);
	GLuint object;
	glGenTextures(1, &object);
	glBindTexture(GL_TEXTURE_2D, object);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

	return image;
}

SDL_Surface* RenderText(const std::string& message, SDL_Color color, int x, int y, int size) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(0, width, 0, height); // m_Width and m_Height is the resolution of window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	TTF_Font* font = TTF_OpenFont("gamedata/fonts/arial.ttf", size);
	if (!font)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}
	SDL_Surface* sFont = TTF_RenderText_Blended(font, message.c_str(), color);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, sFont->pixels);

	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); glVertex2f(x, y);
		glTexCoord2f(1, 0); glVertex2f(x + sFont->w, y);
		glTexCoord2f(1, 1); glVertex2f(x + sFont->w, y + sFont->h);
		glTexCoord2f(0, 1); glVertex2f(x, y + sFont->h);
	}
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glDeleteTextures(1, &texture);

	return sFont;
}

void button_process_event(Button* btn, const SDL_Event* ev)
{
	if (ev->type == SDL_MOUSEBUTTONDOWN)
	{
		if (ev->button.button == SDL_BUTTON_LEFT && ev->button.x >= btn->drawRect.x && ev->button.x <= (btn->drawRect.x + btn->drawRect.w) &&
			ev->button.y >= btn->drawRect.y && ev->button.y <= (btn->drawRect.y + btn->drawRect.h))
		{
			btn->pressed = true;
		}
	}
}

bool button(SDL_Surface* screen, Button* btn)
{
	SDL_BlitSurface(btn->surface, nullptr, screen, &btn->drawRect);

	if (btn->pressed)
	{
		SDL_BlitSurface(btn->surfaceHold, nullptr, screen, &btn->drawRect);
		btn->pressed = false;
		return true;
	}

	return false;
}
