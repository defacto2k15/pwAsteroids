#include <Game.h>
#include "ViewManager.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "EmptyScreen.h"
#include "ConsoleScreen.h"
#include <map>
#include <Controller/MenuScreenEventInterpreter.h>

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

	for( auto &oneInterpreter : screenEventInterpreters_ ){
		if( oneInterpreter->getScreenName() == screenTitle ){
			if( activeInterpreter != nullptr) {
				allegroEventInterpreter_.removeListener(activeInterpreter);
			}
			activeInterpreter = oneInterpreter;
			allegroEventInterpreter_.addListener(oneInterpreter);
			return;
		}
	}
	assert(false);
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


	soundModule_.playSample("Test drive", 0.5, false);
	//sm->playSample("The Gauntlet", false);

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

ViewManager::~ViewManager()
{
	al_stop_timer(timer);
	std::cout << "Timer stopped\n";
}

/* Bartkowy kod */
void ViewManager::resizeDisplay(int newWidth, int newHeight) {
	display->resizeDisplay(newWidth, newHeight);
	game.setResolution(Point(newWidth, newHeight));
}

ViewManager::ViewManager(Game &inGame, std::vector<AbstractAllegroEventListener *> allegroEventListeners,
						 Display *inDisplay, std::vector<ScreenEventInterpreter *> screenEventInterpreters,
						 std::vector<Screen *> inScreens, std::string initialScreen, SoundModule &soundModule)
		: game(inGame), eventsListeners_(allegroEventListeners), screenEventInterpreters_(screenEventInterpreters),
			screens(inScreens), display(inDisplay), soundModule_(soundModule), activeInterpreter(nullptr){
	for( auto oneListener : allegroEventListeners){
		allegroEventInterpreter_.addListener(oneListener);
	}

	for( auto oneScreenInterpreter : screenEventInterpreters){
		oneScreenInterpreter->setViewManager(this);
	}
	game.update();


	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Input events
	al_register_event_source(event_queue, al_get_mouse_event_source());		// Mouse events
	al_start_timer(timer);

	game.update();
	changeActiveScreen(initialScreen);
	game.update();
	game.update();
}
