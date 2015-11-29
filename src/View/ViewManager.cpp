#include "ViewManager.h"

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

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

void ViewManager::start()
{
	//timerThread = new boost::thread(boost::bind(&ViewManager::startTimerEvent, this));
	Scene *scene = createNewScene();
	DrawableObject* object = scene->addDrawableObject("resources/aa.bmp", 512, 300);	// example bitmap to be moved
	bool key[4] = { false, false, false, false };
	int speed = 20;
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP]) {
				object->setPozY(object->getPozY() - speed/20);
			}

			if (key[KEY_DOWN]) {
				object->setPozY(object->getPozY() + speed/20);
			}

			if (key[KEY_LEFT]) {
				object->setPozX(object->getPozX() - speed/20);
			}

			if (key[KEY_RIGHT]) {
				object->setPozX(object->getPozX() + speed/20);
			}
			if(speed < 360) speed += 1;
			if (!key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_LEFT] && !key[KEY_RIGHT]) speed = 20;
			drawAllScenesOnDisplay();	// refresh the screen
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			}
		}
	}
}

Scene * ViewManager::createNewScene()
{
	Scene* newScene = new Scene();
	scenes.push_back(newScene);
	return newScene;
}

ViewManager::ViewManager(int screenWidth, int screenHeight)
{
	display = new Display(screenWidth, screenHeight);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Keyboard events
	al_start_timer(timer);
}

ViewManager::~ViewManager()
{
	al_stop_timer(timer);
	//timerThread->interrupt();
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
