
#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <vector>
#include "Scene.h"
#include "Display.h"
#include <boost/thread/thread.hpp>

const float FPS = 10;

class ViewManager {
public:
	int numberOfScenes();
	void drawSceneOnDisplay(Scene* scene) { display->drawSceneOnDisplay(scene); }
	void drawAllScenesOnDisplay();
	void startTimer();
	Scene* createNewScene();
	ViewManager();
	ViewManager(int, int);
	~ViewManager();

private:
	std::vector<Scene*> scenes;
	Display* display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	boost::thread* timerThread;
	void startTimerEvent();
};

#endif