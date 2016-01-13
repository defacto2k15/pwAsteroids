
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
#include <Controller/MenuScreenEventInterpreter.h>

const float FPS = 60;

class ViewManager {
public:
	ViewManager(Game &game, std::vector<AbstractAllegroEventListener *> allegroEventListeners,
                    Display *display, std::vector<ScreenEventInterpreter *> screenEventInterpreters,
                    std::vector<Screen *> screens, std::string initialScreen, SoundModule &soundModule);

	void changeActiveScreen(std::string );
	void playSample(std::string sampleName, float volume, bool playOnce = true) { soundModule_.playSample(sampleName, volume, playOnce); }
	void initializeScreens();
	void updateScreensAfterDisplayChanges();
	void start();
	void resizeDisplay( int newWidth, int newHeight );
	void exit() { isExit = true; }
	Display* getDisplay() { return display; }
	~ViewManager();

private:
	AllegroEventInterpreter allegroEventInterpreter_;
	std::vector<Screen*> screens;
	std::vector<Screen*>::iterator activeScreen, it;
	Display* display;
	SoundModule &soundModule_;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	boost::thread* timerThread;
	bool isExit = false;
	Game &game;
	std::vector<AbstractAllegroEventListener *> eventsListeners_;
	std::vector<ScreenEventInterpreter *> screenEventInterpreters_;
	ScreenEventInterpreter *activeInterpreter;
};

#endif