#include "octavius.h"
#include "Classes/SlotMachine.h"
#include "Classes/Timer.h"
#include "Classes/Render.h"
#include "Classes/Sound.h"

SDL_Window* window;

//extern const int width = 1920;
//extern const int height = 1080;

//items
// dumb code, I was in a hurry
std::string textureBanana("gamedata/textures/icon_banana.png");
std::string textureBar("gamedata/textures/icon_bar.png");
std::string textureBell("gamedata/textures/icon_bell.png");
std::string textureCherry("gamedata/textures/icon_cherry.png");
std::string textureLemon("gamedata/textures/icon_lemon.png");
std::string textureOrange("gamedata/textures/icon_orange.png");
std::string texturePlum("gamedata/textures/icon_plum.png");
std::string textureSeven("gamedata/textures/icon_seven.png");
std::string textureWatermelon("gamedata/textures/icon_watermelon.png");

SDL_Surface* banana = loadTexture(textureBanana);
SDL_Surface* bar = loadTexture(textureBar);
SDL_Surface* bell = loadTexture(textureBell);
SDL_Surface* cherry = loadTexture(textureCherry);
SDL_Surface* lemon = loadTexture(textureLemon);
SDL_Surface* orange = loadTexture(textureOrange);
SDL_Surface* plum = loadTexture(texturePlum);
SDL_Surface* seven = loadTexture(textureSeven);
SDL_Surface* watermelon = loadTexture(textureWatermelon);
SDL_Rect rcBanana, rcBar, rcBell, rcCherry, rcLemon, rcOrange, rcPlum, rcSeven, rcWatermelon;

std::vector<SDL_Rect> bananas;
std::vector<SDL_Rect> bars;
std::vector<SDL_Rect> bells;
std::vector<SDL_Rect> cherrys;
std::vector<SDL_Rect> lemons;
std::vector<SDL_Rect> oranges;
std::vector<SDL_Rect> plums;
std::vector<SDL_Rect> sevens;
std::vector<SDL_Rect> watermelons;

void clearItems()
{
	// hack-dump code
	for (int i = 0; i < bananas.size(); i++)
	{
		bananas[i].x = 5000;
		bananas[i].y = 5000;
		bananas.erase(bananas.begin() + i);
	}
	
	for (int i = 0; i < bars.size(); i++)
	{
		bars[i].x = 5000;
		bars[i].y = 5000;
		bars.erase(bars.begin() + i);
	}

	for (int i = 0; i < bells.size(); i++)
	{
		bells[i].x = 5000;
		bells[i].y = 5000;
		bells.erase(bells.begin() + i);
	}

	for (int i = 0; i < cherrys.size(); i++)
	{
		cherrys[i].x = 5000;
		cherrys[i].y = 5000;
		cherrys.erase(cherrys.begin() + i);
	}

	for (int i = 0; i < lemons.size(); i++)
	{
		lemons[i].x = 5000;
		lemons[i].y = 5000;
		lemons.erase(lemons.begin() + i);
	}

	for (int i = 0; i < oranges.size(); i++)
	{
		oranges[i].x = 5000;
		oranges[i].y = 5000;
		oranges.erase(oranges.begin() + i);
	}

	for (int i = 0; i < plums.size(); i++)
	{
		plums[i].x = 5000;
		plums[i].y = 5000;
		plums.erase(plums.begin() + i);
	}

	for (int i = 0; i < sevens.size(); i++)
	{
		sevens[i].x = 5000;
		sevens[i].y = 5000;
		sevens.erase(sevens.begin() + i);
	}

	for (int i = 0; i < watermelons.size(); i++)
	{
		watermelons[i].x = 5000;
		watermelons[i].y = 5000;
		watermelons.erase(watermelons.begin() + i);
	}
}

void playAnimation(SlotMachine* machine)
{
	std::vector<std::pair<int, int>> coordsGridsItems
	{
		{500, 70},
		{776, 70},
		{1032, 70},
		{500, 326},
		{776, 326},
		{1032, 326},
		{500, 582},
		{796, 582},
		{1052, 582}
	};

	//Timer timer = Timer();
	//timer.setInterval([&]() { machine->setSpinnable(false); }, 2000);

	int iter = 0;
	std::vector<int> screen = machine->getScreen();
	for (int i = 0; i < screen.size(); i++)
	{
		/*if (machine->getSpinnable())
		{
			while (machine->getSpinnable())
			{
				rcBanana.x = coordsGridsItems[i].first;
				rcBanana.y = iter;
				iter++;
				if (iter == height) iter = 0;
			}
		}
		else
		{*/
			switch (screen[i])
			{
			case SlotMachine::banana:
				if (bananas.size() == 0)
				{
					rcBanana.x = coordsGridsItems[i].first;
					rcBanana.y = coordsGridsItems[i].second;
					bananas.push_back(rcBanana);
				}
				else
				{
					SDL_Rect rcBananaClone;
					rcBananaClone.x = coordsGridsItems[i].first;
					rcBananaClone.y = coordsGridsItems[i].second;
					bananas.push_back(rcBananaClone);
				}
				break;
			case SlotMachine::bar:
				if (bars.size() == 0)
				{
					rcBar.x = coordsGridsItems[i].first;
					rcBar.y = coordsGridsItems[i].second;
					bars.push_back(rcBar);
				}
				else
				{
					SDL_Rect rcBarClone;
					rcBarClone.x = coordsGridsItems[i].first;
					rcBarClone.y = coordsGridsItems[i].second;
					bars.push_back(rcBarClone);
				}
				break;
			case SlotMachine::bell:
				if (bells.size() == 0)
				{
					rcBell.x = coordsGridsItems[i].first;
					rcBell.y = coordsGridsItems[i].second;
					bells.push_back(rcBell);
				}
				else
				{
					SDL_Rect rcBellClone;
					rcBellClone.x = coordsGridsItems[i].first;
					rcBellClone.y = coordsGridsItems[i].second;
					bells.push_back(rcBellClone);
				}
				break;
			case SlotMachine::cherry:
				if (cherrys.size() == 0)
				{
					rcCherry.x = coordsGridsItems[i].first;
					rcCherry.y = coordsGridsItems[i].second;
					cherrys.push_back(rcCherry);
				}
				else
				{
					SDL_Rect rcCherryClone;
					rcCherryClone.x = coordsGridsItems[i].first;
					rcCherryClone.y = coordsGridsItems[i].second;
					cherrys.push_back(rcCherryClone);
				}
				break;
			case SlotMachine::lemon:
				if (lemons.size() == 0)
				{
					rcLemon.x = coordsGridsItems[i].first;
					rcLemon.y = coordsGridsItems[i].second;
					lemons.push_back(rcLemon);
				}
				else
				{
					SDL_Rect rcLemonClone;
					rcLemonClone.x = coordsGridsItems[i].first;
					rcLemonClone.y = coordsGridsItems[i].second;
					lemons.push_back(rcLemonClone);
				}
				break;
			case SlotMachine::orange:
				if (oranges.size() == 0)
				{
					rcOrange.x = coordsGridsItems[i].first;
					rcOrange.y = coordsGridsItems[i].second;
					oranges.push_back(rcOrange);
				}
				else
				{
					SDL_Rect rcOrangeClone;
					rcOrangeClone.x = coordsGridsItems[i].first;
					rcOrangeClone.y = coordsGridsItems[i].second;
					oranges.push_back(rcOrangeClone);
				}
				break;
			case SlotMachine::plum:
				if (plums.size() == 0)
				{
					rcPlum.x = coordsGridsItems[i].first;
					rcPlum.y = coordsGridsItems[i].second;
					plums.push_back(rcPlum);
				}
				else
				{
					SDL_Rect rcPlumClone;
					rcPlumClone.x = coordsGridsItems[i].first;
					rcPlumClone.y = coordsGridsItems[i].second;
					plums.push_back(rcPlumClone);
				}
				break;
			case SlotMachine::seven:
				if (sevens.size() == 0)
				{
					rcSeven.x = coordsGridsItems[i].first;
					rcSeven.y = coordsGridsItems[i].second;
					sevens.push_back(rcSeven);
				}
				else
				{
					SDL_Rect rcSevenClone;
					rcSevenClone.x = coordsGridsItems[i].first;
					rcSevenClone.y = coordsGridsItems[i].second;
					sevens.push_back(rcSevenClone);
				}
				break;
			case SlotMachine::watermelon:
				if (watermelons.size() == 0)
				{
					rcWatermelon.x = coordsGridsItems[i].first;
					rcWatermelon.y = coordsGridsItems[i].second;
					watermelons.push_back(rcWatermelon);
				}
				else
				{
					SDL_Rect rcWatermelonClone;
					rcWatermelonClone.x = coordsGridsItems[i].first;
					rcWatermelonClone.y = coordsGridsItems[i].second;
					watermelons.push_back(rcWatermelonClone);
				}
				break;
			}
		//}
	}
}

int main()
{
	SlotMachine* slotmachine = new SlotMachine();
	slotmachine->insertbill(100.0);
	slotmachine->insertcoin();

	int countLines = 1;
	int credits = 0;
	int lastWin = 0;
	
	initVideo();
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	// sounds
	std::string soundStart("gamedata/sounds/start.wav");
	std::string soundStop("gamedata/sounds/stop.wav");
	std::string soundClick("gamedata/sounds/click.wav");
	std::string soundCancel("gamedata/sounds/cancel.wav");
	std::string soundWin("gamedata/sounds/win.wav");


	Sound sndStart, sndStop, sndClick, sndCancel, sndWin;
	SDL_AudioDeviceID deviceId = sndStart.getID();
	Uint8* sndBufStart = sndStart.loadSound(soundStart);
	Uint8* sndBufStop = sndStop.loadSound(soundStop);
	Uint8* sndBufClick = sndClick.loadSound(soundClick);
	Uint8* sndBufCancel = sndCancel.loadSound(soundCancel);
	Uint8* sndBufWin = sndWin.loadSound(soundWin);

	// ui textures
	std::string textureBackground("gamedata/textures/background.png");
	std::string textureWheel("gamedata/textures/wheel.png");
	std::string textureHeader("gamedata/textures/header.png");
	std::string textureFooter("gamedata/textures/footer.png");
	std::string textureSpin("gamedata/textures/spin_button.png");
	std::string textureSpinHold("gamedata/textures/spin_button_hold.png");
	std::string textureStop("gamedata/textures/stop_button.png");
	std::string textureStopHold("gamedata/textures/stop_button_hold.png");
	std::string textureUp("gamedata/textures/up_button.png");
	std::string textureUpHold("gamedata/textures/up_button_hold.png");
	std::string textureDown("gamedata/textures/down_button.png");
	std::string textureDownHold("gamedata/textures/down_button_hold.png");


	SDL_Surface* background = loadTexture(textureBackground);
	SDL_Rect rcBackground;
	rcBackground.x = 0;
	rcBackground.y = 0;

	SDL_Surface* wheelOne = loadTexture(textureWheel);
	SDL_Surface* wheelTwo = loadTexture(textureWheel);
	SDL_Surface* wheelThree = loadTexture(textureWheel);
	SDL_Rect rcWheelOne, rcWheelTwo, rcWheelThree;
	rcWheelOne.x = 500;
	rcWheelOne.y = 70;
	rcWheelTwo.x = 500 + (wheelOne->w * 1.1);
	rcWheelTwo.y = 70;
	rcWheelThree.x = 500 + (wheelOne->w * 1.1) + (wheelTwo->w * 1.1);
	rcWheelThree.y = 70;

	SDL_Surface* header = loadTexture(textureHeader);
	SDL_Rect rcHeader;
	rcHeader.x = 0;
	rcHeader.y = 0;

	SDL_Surface* footer = loadTexture(textureFooter);
	SDL_Rect rcFooter;
	rcFooter.x = 0;
	rcFooter.y = height * 0.72;

	Button spinButton;
	spinButton.surface = loadTexture(textureSpin);
	spinButton.surfaceHold = loadTexture(textureSpinHold);
	spinButton.drawRect.x = width * 0.631;
	spinButton.drawRect.y = height * 0.77;
	spinButton.drawRect.w = spinButton.surface->w;
	spinButton.drawRect.h = spinButton.surface->h;

	Button stopButton;
	stopButton.surface = loadTexture(textureStop);
	stopButton.surfaceHold = loadTexture(textureStopHold);
	stopButton.drawRect.x = width * 0.485;
	stopButton.drawRect.y = height * 0.73;
	stopButton.drawRect.w = spinButton.surface->w;
	stopButton.drawRect.h = spinButton.surface->h;

	Button upButton;
	upButton.surface = loadTexture(textureUp);
	upButton.surfaceHold = loadTexture(textureUpHold);
	upButton.drawRect.x = 450;
	upButton.drawRect.y = 15;
	upButton.drawRect.w = spinButton.surface->w;
	upButton.drawRect.h = spinButton.surface->h;

	Button downButton;
	downButton.surface = loadTexture(textureDown);
	downButton.surfaceHold = loadTexture(textureDownHold);
	downButton.drawRect.x = 450;
	downButton.drawRect.y = 55;
	downButton.drawRect.w = spinButton.surface->w;
	downButton.drawRect.h = spinButton.surface->h;

	// texts
	SDL_Color color = { 255, 255, 255, 0 }; // Red
	SDL_Surface* bet;
	SDL_Surface* balance;
	SDL_Surface* win;
	SDL_Rect rcBet, rcBalance, rcWin;
	rcBet.x = 365;
	rcBet.y = 23;
	rcBalance.x = 820;
	rcBalance.y = 23;
	rcWin.x = 1400;
	rcWin.y = 795;

	bool running = true;
	while (running)
	{
		credits = slotmachine->getCredits();
		lastWin = slotmachine->getLastWinning();

		bet = RenderText(std::to_string(countLines).c_str(), color, 0, 0, 60);
		balance = RenderText(std::to_string(credits).c_str(), color, 0, 0, 60);
		win = RenderText(std::to_string(lastWin).c_str(), color, 0, 0, 40);

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				if (!slotmachine->getSpinnable())
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						running = false;
						break;

					case SDLK_RETURN:
						sndStart.play();
						clearItems();
						slotmachine->bet(countLines);
						slotmachine->spin();
						playAnimation(slotmachine);
						if (slotmachine->getLastWinning() > 0)
							sndWin.play();
						break;

					case SDLK_UP:
						if (countLines < 5)
						{
							sndClick.play();
							countLines++;
						}
						else
							sndCancel.play();

						break;

					case SDLK_DOWN:
						if (countLines > 1)
						{
							sndClick.play();
							countLines--;
						}
						else
							sndCancel.play();

						break;
					}
				}
				else
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						running = false;
						break;

					case SDLK_SPACE:
						sndStop.play();
						slotmachine->setSpinnable(false);
						clearItems();
						//slotmachine->forceStop();
						break;

					break;
					}
				}

				break;
			}

			button_process_event(&spinButton, &event);
			button_process_event(&stopButton, &event);
			button_process_event(&upButton, &event);
			button_process_event(&downButton, &event);
		}

		SDL_BlitSurface(background, nullptr, screen, &rcBackground);
		SDL_BlitSurface(wheelOne, nullptr, screen, &rcWheelOne);
		SDL_BlitSurface(wheelTwo, nullptr, screen, &rcWheelTwo);
		SDL_BlitSurface(wheelThree, nullptr, screen, &rcWheelThree);
		// items
		if (slotmachine->getSpinnable())
		{
			for (auto& p: bananas)
				SDL_BlitSurface(banana, nullptr, screen, &p);
			for (auto& p : bars)
				SDL_BlitSurface(bar, nullptr, screen, &p);
			for (auto& p : bells)
				SDL_BlitSurface(bell, nullptr, screen, &p);
			for (auto& p : cherrys)
				SDL_BlitSurface(cherry, nullptr, screen, &p);
			for (auto& p : lemons)
				SDL_BlitSurface(lemon, nullptr, screen, &p);
			for (auto& p : oranges)
				SDL_BlitSurface(orange, nullptr, screen, &p);
			for (auto& p : plums)
				SDL_BlitSurface(plum, nullptr, screen, &p);
			for (auto& p : sevens)
				SDL_BlitSurface(seven, nullptr, screen, &p);
			for (auto& p : watermelons)
				SDL_BlitSurface(watermelon, nullptr, screen, &p);
		}
		// UI frames
		SDL_BlitSurface(header, nullptr, screen, &rcHeader);
		SDL_BlitSurface(footer, nullptr, screen, &rcFooter);
		// UI text and buttons
		SDL_BlitSurface(bet, nullptr, screen, &rcBet);
		SDL_BlitSurface(balance, nullptr, screen, &rcBalance);
		SDL_BlitSurface(win, nullptr, screen, &rcWin);

		if (button(screen, &spinButton))
		{
			sndStart.play();
			clearItems();
			slotmachine->bet(countLines);
			slotmachine->spin();
			playAnimation(slotmachine);
			if (slotmachine->getLastWinning() > 0)
				sndWin.play();
		}

		if (button(screen, &stopButton))
		{
			sndStop.play();
			slotmachine->setSpinnable(false);
			clearItems();
		}

		if (button(screen, &upButton))
		{
			if (countLines < 5)
			{
				sndClick.play();
				countLines++;
			}
			else
				sndCancel.play();
		}

		if (button(screen, &downButton))
		{
			if (countLines > 1)
			{
				sndClick.play();
				countLines--;
			}
			else
				sndCancel.play();
		}


		// refresh frame
		glFlush();
		//SDL_GL_SwapWindow(window);
		SDL_UpdateWindowSurface(window);
	}

	delete(slotmachine);

	// dumb code, I was in a hurry
	SDL_FreeWAV(sndBufStart);
	SDL_FreeWAV(sndBufStop);
	SDL_FreeWAV(sndBufClick);
	SDL_FreeWAV(sndBufCancel);
	SDL_FreeWAV(sndBufWin);
	
	SDL_FreeSurface(background);
	SDL_FreeSurface(wheelOne);
	SDL_FreeSurface(wheelTwo);
	SDL_FreeSurface(wheelThree);
	SDL_FreeSurface(banana);
	SDL_FreeSurface(bar);
	SDL_FreeSurface(bell);
	SDL_FreeSurface(cherry);
	SDL_FreeSurface(lemon);
	SDL_FreeSurface(orange);
	SDL_FreeSurface(plum);
	SDL_FreeSurface(seven);
	SDL_FreeSurface(watermelon);
	SDL_FreeSurface(header);
	SDL_FreeSurface(footer);
	SDL_FreeSurface(bet);
	SDL_FreeSurface(balance);
	SDL_FreeSurface(win);


	//TTF_CloseFont(font);
	SDL_CloseAudioDevice(deviceId);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
