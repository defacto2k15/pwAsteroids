#include <Game.h>
#include "ViewManager.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "EmptyScreen.h"
#include <map>

void ViewManager::changeActiveScreen(std::string screenTitle)
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		if (screenTitle == (*it)->getTitle())
		{
			activeScreen = it;
			std::cout << "- Changed screen to " << (*activeScreen)->getTitle() << "\n";
			break;
		}
	}
}

void ViewManager::initializeScreens()
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		(*it)->initializeScreenElements();
	}
	std::cout << "Initialized " << screens.size() << " screens\n";
	activeScreen = screens.begin();
}

void ViewManager::start()
{
	Game g;
	g.update();

	std::string str = "MenuScreen";
	MenuScreen* menuScreen = new MenuScreen(str);
	screens.push_back(menuScreen);

	str = "GameScreen";
	GameScreen* gameScreen = new GameScreen(str);
	screens.push_back(gameScreen);

	/* str = "EmptyScreen";
	EmptyScreen* emptyScreen = new EmptyScreen(str);
	screens.push_back(emptyScreen); */

	initializeScreens();	// must be called before drawing screens!
	std::cout << "While(1) loop\n";
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		(*activeScreen)->eventAction(ev, this, &g);
		if (isExit) break;
	}
}

ViewManager::ViewManager(int screenWidth, int screenHeight)
{
	display = new Display(screenWidth, screenHeight);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Input events
	al_register_event_source(event_queue, al_get_mouse_event_source());		// Mouse events
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
