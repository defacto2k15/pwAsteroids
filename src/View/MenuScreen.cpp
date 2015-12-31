#include "MenuScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

void MenuScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		drawAllScenesOnDisplay(vm->getDisplay()); // remember to refresh the screen in a proper place
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		vm->exit();		// remember to include exit signal!
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
		case ALLEGRO_KEY_SPACE:
			std::string str = "GameScreen";
			vm->changeActiveScreen(str);
			break;
		}
	}
}

void MenuScreen::initializeScreenElements()
{
	// scenes
	background = createNewScene();
	// drawable objects
	text = background->addDrawableObject(true, "pwAsteroids", 450, 200);
	text2 = background->addDrawableObject(true, "Press space to play :-)", 410, 300);

	std::cout << title << " initialized\n";
}

MenuScreen::MenuScreen(std::string &t)
{
	title = t;
}

MenuScreen::~MenuScreen()
{
}