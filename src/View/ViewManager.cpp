#include <Game.h>
#include "ViewManager.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "EmptyScreen.h"
#include "ConsoleScreen.h"
#include <map>

void ViewManager::changeActiveScreen(std::string screenTitle)
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		if (screenTitle == (*it)->getTitle())
		{
			activeScreen = it;
			std::cout << "- Changed screen to " << (*activeScreen)->getTitle() << "\n";
			eventsListener_.push_back(&interpreter_);
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

void ViewManager::updateScreensAfterDisplayChanges()
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		(*it)->updateScreenAfterDisplayChanges();
	}
	std::cout << "Updated " << screens.size() << " screens\n";
}

void ViewManager::start()
{
	game.update();

	std::string str = "MenuScreen";
	MenuScreen* menuScreen = new MenuScreen(str);
	screens.push_back(menuScreen);

	/*str = "GameScreen";
	GameScreen* gameScreen = new GameScreen(str);
	screens.push_back(gameScreen);*/

	str = "ConsoleScreen";
	ConsoleScreen* consoleScreen = new ConsoleScreen(str);
	screens.push_back(consoleScreen);

	sm->playSample("Test drive", 0.2, false);
	//sm->playSample("The Gauntlet", false);

	/* str = "EmptyScreen";
	EmptyScreen* emptyScreen = new EmptyScreen(str);
	screens.push_back(emptyScreen); */

	initializeScreens();	// must be called before drawing screens!
	std::cout << "While(1) loop\n";
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//(*activeScreen)->eventAction(ev, this, &game);
		allegroEventInterpreter_.interpretEvent(ev);
		if (isExit) break;
	}

}

ViewManager::ViewManager(int screenWidth, int screenHeight, Game &g,
						 std::vector<AbstractAllegroEventListener *> eventListeners,
						 GameScreenEventInterpreter &interpreter, GameScreen *gameScreen, Display *inDisplay)
		: game(g), eventsListener_(eventListeners), interpreter_(interpreter), display(inDisplay)
{
	for( auto oneListener : eventListeners){
		allegroEventInterpreter_.addListener(oneListener);
	}
	allegroEventInterpreter_.addListener(&interpreter);



	sm = new SoundModule();
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Input events
	al_register_event_source(event_queue, al_get_mouse_event_source());		// Mouse events
	al_start_timer(timer);

	screens.push_back(gameScreen);
}

ViewManager::~ViewManager()
{
	al_stop_timer(timer);
	//timerThread->interrupt();
	std::cout << "Timer stopped\n";
	delete display;
	// TO DO: also delete each scene in scenes
}

/* Bartkowy kod */
void ViewManager::resizeDisplay(int newWidth, int newHeight) {
	display->resizeDisplay(newWidth, newHeight);
	game.setResolution(Point(newWidth, newHeight));
}
