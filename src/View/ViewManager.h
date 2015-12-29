
#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <vector>
#include "Scene.h"
#include "Display.h"
#include <boost/thread/thread.hpp>
#include <string>

const float FPS = 60;

class ViewManager {
public:
	int numberOfScenes();
	void drawSceneOnDisplay(Scene* scene) { display->drawSceneOnDisplay(scene); }
	void drawAllScenesOnDisplay();
	void start();
	Scene* createNewScene();
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