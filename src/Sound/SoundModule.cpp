#include "SoundModule.h"
#include <iostream>

void SoundModule::playSample(std::string sampleName, float volume, bool playOnce)
{
	if(playOnce) al_play_sample(samples[sampleName].first, volume, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, samples[sampleName].second);
	else al_play_sample(samples[sampleName].first, volume, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}

void SoundModule::stopSample(std::string sampleName)
{
	al_stop_sample(samples[sampleName].second);
}

SoundModule::SoundModule()
{
	if (!al_install_audio()) {
		throw std::runtime_error("Failed to initialize audio!");
	}

	if (!al_init_acodec_addon()) {
		throw std::runtime_error("Failed to initialize audio codec addon!");
	}

	if (!al_reserve_samples(10)) {
		throw std::runtime_error("Failed to reserve samples!");
	}

	// samples
	samples["Test drive"].first = al_load_sample("../res/sound/11-Test_drive.ogg");
	samples["Blaster Imperial"].first = al_load_sample("../res/sound/Blaster-Imperial.wav");
	samples["The Gauntlet"].first = al_load_sample("../res/sound/The Gauntlet.ogg");
	samples["RocketFailure"].first = al_load_sample("../res/sound/rocketFailure.wav");
	samples["AsteroidCollision"].first = al_load_sample("../res/sound/bomb.wav");
	samples["SecondPlayerShoot"].first = al_load_sample("../res/sound/secondPlayerShoot.wav");

	for (auto sample : samples) {
		if (!(sample.second).first) {
			throw std::runtime_error("Failed to load sample!");
		}
	}
}

SoundModule::~SoundModule()
{
	for (auto sample : samples) {
		al_destroy_sample((sample.second).first);
	}
	std::cout << "SoundModule deleted\n";
}
