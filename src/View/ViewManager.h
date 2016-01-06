
#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <vector>
#include "Scene.h"
#include "Screen.h"
#include "Display.h"
#include "Sound/SoundModule.h"
#include <boost/thread/thread.hpp>
#include <string>

const float FPS = 60;

class ViewManager {
public:
	void changeActiveScreen(std::string);
	void playSample(std::string sampleName, float volume, bool playOnce = true) { sm->playSample(sampleName, volume, playOnce); }
	void initializeScreens();
	void start();
	void exit() { isExit = true; }
	Display* getDisplay() { return display; }
	ViewManager(int, int);
	~ViewManager();

private:
	std::vector<Screen*> screens;
	std::vector<Screen*>::iterator activeScreen, it;
	Display* display;
	SoundModule* sm;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	boost::thread* timerThread;
	bool isExit = false;
};

#endif