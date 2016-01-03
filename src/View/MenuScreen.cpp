#include "MenuScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

enum OPTION { START, OPTIONS, ABOUT, EXIT };
int option = START;

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
			if (option > 0) {
				--option;
				selectedButton->setPozY(selectedButton->getPozY() - 80);
			}
			break;

		case ALLEGRO_KEY_DOWN:
			if (option < 3) {
				++option;
				selectedButton->setPozY(selectedButton->getPozY() + 80);
			}
			break;

		case ALLEGRO_KEY_LEFT:
			break;

		case ALLEGRO_KEY_RIGHT:
			break;
		case ALLEGRO_KEY_SPACE:
			if (option == START) {
				std::string str = "GameScreen";
				vm->changeActiveScreen(str);
			}
			else if (option == EXIT) {
				vm->exit();
			}
			break;
		}
	}
}

void MenuScreen::initializeScreenElements()
{
	// scenes
	background = createNewScene();
	// drawable objects
	text = background->addDrawableObject(410, 80, NULL, "pwAsteroids (cool logo)");
	button1 = background->addDrawableObject(340, 160, "../res/button.bmp", "Start the game", 0.0f, 1.0f, 110, 15);
	button2 = background->addDrawableObject(340, 240, "../res/button.bmp", "Options", 0.0f, 1.0f, 140, 15);
	button3 = background->addDrawableObject(340, 320, "../res/button.bmp", "About", 0.0f, 1.0f, 150, 15);
	button4 = background->addDrawableObject(340, 400, "../res/button.bmp", "Exit", 0.0f, 1.0f, 155, 15);
	selectedButton = background->addDrawableObject(320, 170, "../res/aa.bmp", NULL, 1.570796f, 0.75f);
	std::cout << title << " initialized\n";
}

MenuScreen::MenuScreen(std::string &t)
{
	title = t;
}

MenuScreen::~MenuScreen()
{
}