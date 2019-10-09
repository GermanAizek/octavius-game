#include "../octavius.h"

class Sound
{
private:
	SDL_AudioDeviceID deviceId;
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;

public:
	Sound() {
		// SDL audio device init
		SDL_Init(SDL_INIT_AUDIO);
	}
	SDL_AudioDeviceID getID() { return deviceId; }
	Uint8* loadSound(const char* sound);
	bool play();
};