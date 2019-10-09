#include "Classes/Sound.h"

Uint8* Sound::loadSound(const char* sound)
{
	SDL_LoadWAV(sound, &wavSpec, &wavBuffer, &wavLength);

	return wavBuffer;
}

bool Sound::play()
{
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	//SDL_Delay(1);

	return success;
}