#include "EmptyScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

void EmptyScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{
	// TODO: reactions for events

	if (ev.type == ALLEGRO_EVENT_TIMER) {
		drawAllScenesOnDisplay(vm->getDisplay()); // remember to refresh the screen in a proper place
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		vm->exit();		// remember to include exit signal!
	}
}

void EmptyScreen::initializeScreenElements()
{
	// TODO: initialize additional elements

	// scenes
	background = createNewScene();
	// drawable objects
	text = background->addDrawableObject(30, 20, NULL, "Empty Screen"); // true means it's a text object

	std::cout << title << " initialized\n";
}

EmptyScreen::EmptyScreen(std::string &t)
{
	title = t;
}

EmptyScreen::~EmptyScreen()
{
}
