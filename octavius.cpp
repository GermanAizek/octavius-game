#include "octavius.h"
#include "Classes/SlotMachine.h"
#include "Render.h"
#include "Sound.h"

SDL_Window* window;

const int width = 1920;
const int height = 1080;

int main()
{
	int countLines = 1;
	SlotMachine* slotmachine = new SlotMachine();

	slotmachine->insertbill(100.0);
	slotmachine->insertcoin();
	//
	initVideo();
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	// sounds
	Sound sndStop, sndClick, sndCancel;
	Uint8* sndBufStop = sndStop.loadSound("gamedata/sounds/stop.wav");
	Uint8* sndBufClick = sndClick.loadSound("gamedata/sounds/click.wav");
	Uint8* sndBufCancel = sndCancel.loadSound("gamedata/sounds/cancel.wav");

	SDL_AudioDeviceID deviceId = sndStop.getID();

	// game

	// init font and text
	//TTF_Font* font = TTF_OpenFont("gamedata/fonts/arial.ttf", 25);

	SDL_Surface* background = loadTexture("gamedata/textures/background.png");
	SDL_Rect rcBackground;
	rcBackground.x = 0;
	rcBackground.y = 0;

	SDL_Surface* wheelOne = loadTexture("gamedata/textures/wheel.png");
	SDL_Surface* wheelTwo = loadTexture("gamedata/textures/wheel.png");
	SDL_Surface* wheelThree = loadTexture("gamedata/textures/wheel.png");
	SDL_Rect rcWheelOne, rcWheelTwo, rcWheelThree;
	rcWheelOne.x = 500;
	rcWheelOne.y = 70;
	rcWheelTwo.x = 500 + (wheelOne->w * 1.1);
	rcWheelTwo.y = 70;
	rcWheelThree.x = 500 + (wheelOne->w * 1.1) + (wheelTwo->w * 1.1);
	rcWheelThree.y = 70;

	SDL_Surface* header = loadTexture("gamedata/textures/header.png");
	SDL_Rect rcHeader;
	rcHeader.x = 0;
	rcHeader.y = 0;

	SDL_Surface* footer = loadTexture("gamedata/textures/footer.png");
	SDL_Rect rcFooter;
	rcFooter.x = 0;
	rcFooter.y = height - footer->h*2.2;

	SDL_Surface* spinButton = loadTexture("gamedata/textures/spin_button.png");
	SDL_Rect rcSpinButton;
	rcSpinButton.x = width * 0.6;
	rcSpinButton.y = height * 0.8;

	// texts
	SDL_Color color = { 255, 255, 255, 0 }; // Red
	SDL_Surface* bet;
	SDL_Rect rcBet;
	rcBet.x = width * 0.1;
	rcBet.y = height * 0.1;

	bool running = true;
	while (running)
	{
		bet = RenderText(std::to_string(countLines).c_str(), color, 100, 100, 25);

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;

				case SDLK_KP_SPACE:
					sndStop.play();
					slotmachine->forceStop();
					break;

				case SDLK_RETURN:
					sndStop.play();
					slotmachine->spin();
					break;

				case SDLK_UP:
					if (countLines < 5)
					{
						sndClick.play();
						countLines++;
						slotmachine->bet(countLines);
					}
					else
						sndCancel.play();

					break;

				case SDLK_DOWN:
					if (countLines > 1)
					{
						sndClick.play();
						countLines--;
						slotmachine->bet(countLines);
					}
					else
						sndCancel.play();

					break;
				}

				break;
			}
		}

		SDL_BlitSurface(background, nullptr, screen, &rcBackground);
		SDL_BlitSurface(wheelOne, nullptr, screen, &rcWheelOne);
		SDL_BlitSurface(wheelTwo, nullptr, screen, &rcWheelTwo);
		SDL_BlitSurface(wheelThree, nullptr, screen, &rcWheelThree);
		// UI frames
		SDL_BlitSurface(header, nullptr, screen, &rcHeader);
		SDL_BlitSurface(footer, nullptr, screen, &rcFooter);
		// UI text and buttons
		SDL_BlitSurface(bet, nullptr, screen, &rcBet);
		SDL_BlitSurface(spinButton, nullptr, screen, &rcSpinButton);


		// refresh frame
		glFlush();
		//SDL_GL_SwapWindow(window);
		SDL_UpdateWindowSurface(window);
	}

	delete(slotmachine);

	SDL_FreeWAV(sndBufStop);
	SDL_FreeWAV(sndBufClick);
	SDL_FreeWAV(sndBufCancel);
	
	SDL_FreeSurface(background);
	SDL_FreeSurface(wheelOne);
	SDL_FreeSurface(wheelTwo);
	SDL_FreeSurface(wheelThree);
	SDL_FreeSurface(header);
	SDL_FreeSurface(footer);
	SDL_FreeSurface(bet);


	//TTF_CloseFont(font);
	SDL_CloseAudioDevice(deviceId);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
