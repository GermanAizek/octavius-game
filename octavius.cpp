#include "octavius.h"
#include "Classes/SlotMachine.h"
#include "Render.h"
#include "Sound.h"

SDL_Window* window;

const int width = 1920;
const int height = 1080;

int main()
{
	SlotMachine* slotmachine = new SlotMachine();

	slotmachine->insertbill(5.00);
	slotmachine->insertcoin();

	slotmachine->bet(5);
	slotmachine->spin();

	slotmachine->bet(5);
	slotmachine->spin();
	//
	initVideo();
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	Sound snd;
	snd.initSound();

	// game

	// init font and text
	//TTF_Font* font = TTF_OpenFont("gamedata/fonts/arial.ttf", 25);
	//SDL_Color color = { 255, 255, 255, 0}; // Red
	//RenderText(font, color, 100, 100, 0, "HelloWorld");

	SDL_Surface* background = loadTexture("gamedata/textures/background.png");
	SDL_Rect rcBackground;
	rcBackground.x = 0;
	rcBackground.y = 0;

	SDL_Surface* header = loadTexture("gamedata/textures/header.png");
	SDL_Rect rcHeader;
	rcHeader.x = 0;
	rcHeader.y = 0;

	SDL_Surface* footer = loadTexture("gamedata/textures/footer.png");
	SDL_Rect rcFooter;
	rcFooter.x = 0;
	rcFooter.y = height - footer->h*2.2;


	bool running = true;
	float xrf = 0, yrf = 0, zrf = 0;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				delete(slotmachine);
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_KP_SPACE:
					snd.loadPlay("gamedata/sounds/stop.wav");
					slotmachine->forceStop();
					break;
				case SDLK_RETURN:
					snd.loadPlay("gamedata/sounds/stop.wav");
					slotmachine->spin();
					break;
				}

				break;
			}
		}

		// calc rotate
		xrf -= 0.5;
		yrf -= 0.5;
		zrf -= 0.5;

		// header
		SDL_BlitSurface(background, NULL, screen, &rcBackground);
		SDL_BlitSurface(header, NULL, screen, &rcHeader);
		SDL_BlitSurface(footer, NULL, screen, &rcFooter);


		// refresh
		glFlush();
		//SDL_GL_SwapWindow(window);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(background);
	SDL_FreeSurface(header);
	SDL_FreeSurface(footer);

	//TTF_CloseFont(font);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
