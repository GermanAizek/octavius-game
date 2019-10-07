#include "Sound.h"

void Sound::initSound()
{
	// SDL audio device init
	SDL_Init(SDL_INIT_AUDIO);
}

bool Sound::loadPlay(const char* sound)
{
	SDL_LoadWAV(sound, &wavSpec, &wavBuffer, &wavLength);

	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	SDL_Delay(1);
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);

	return success;
}