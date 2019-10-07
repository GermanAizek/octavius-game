#include "octavius.h"

class Sound
{
private:
	SDL_AudioDeviceID deviceId;
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;

public:
	void initSound();
	bool loadPlay(const char* sound);
};