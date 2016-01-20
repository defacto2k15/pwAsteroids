#ifndef PWASTEROIDS_SOUNDMODULE_H
#define PWASTEROIDS_SOUNDMODULE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdexcept>
#include <map>

class SoundModule {
public:
	void playSample(std::string, float volume = 0.5, bool = true);
	void stopSample(std::string);
	SoundModule();
	~SoundModule();
private:
	std::map<std::string, std::pair<ALLEGRO_SAMPLE*, ALLEGRO_SAMPLE_ID*>> samples;
};

#endif
