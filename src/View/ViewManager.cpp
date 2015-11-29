#include "ViewManager.h"

int ViewManager::numberOfScenes()
{
	return scenes.size();
}

void ViewManager::drawAllScenesOnDisplay()
{
	for (auto scene : scenes)
	{
		if(scene->isActive()) display->drawSceneOnDisplay(scene);
	}
}

void ViewManager::startTimer()
{
	timerThread = new boost::thread(boost::bind(&ViewManager::startTimerEvent, this));
}

Scene * ViewManager::createNewScene()
{
	Scene* newScene = new Scene();
	scenes.push_back(newScene);
	return newScene;
}

ViewManager::ViewManager()
{
	display = new Display();
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
}

ViewManager::ViewManager(int screenWidth, int screenHeight)
{
	display = new Display(screenWidth, screenHeight);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
}

ViewManager::~ViewManager()
{
	al_stop_timer(timer);
	timerThread->interrupt();
	std::cout << "Timer stopped\n";
	delete display;
	// TO DO: also delete each scene in scenes
}

void ViewManager::startTimerEvent()
{
	boost::mutex mtx;
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			std::cout << "Timer event (FPS: " << FPS << ")\n";
			mtx.lock();
			//drawAllScenesOnDisplay();			// THAT'S NOT THREAD SAFE FOR ALLEGRO!!!
			mtx.unlock();
		}
	}
}
