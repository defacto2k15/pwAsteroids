
#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <Game.h>
#include <vector>
#include "Scene.h"
#include "Screen.h"
#include "Display.h"
#include "Sound/SoundModule.h"
#include <boost/thread/thread.hpp>
#include <string>
#include <Controller/AbstractAllegroEventListener.h>
#include <Controller/GameScreenEventInterpreter.h>
#include <Controller/AllegroEventInterpreter.h>

const float FPS = 60;

class ViewManager {
public:
	void changeActiveScreen(std::string );
	void playSample(std::string sampleName, float volume, bool playOnce = true) { sm->playSample(sampleName, volume, playOnce); }
	void initializeScreens();
	void updateScreensAfterDisplayChanges();
	void start();
	void resizeDisplay( int newWidth, int newHeight );
	void exit() { isExit = true; }
	Display* getDisplay() { return display; }
	ViewManager(int, int, Game &game, std::vector<AbstractAllegroEventListener *>,
				GameScreenEventInterpreter &interpreter, GameScreen *gameScreen, Display *inDisplay);
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
	Game &game;
	std::vector<AbstractAllegroEventListener *> eventsListener_;
	GameScreenEventInterpreter &interpreter_;
	AllegroEventInterpreter allegroEventInterpreter_;
};

#endif