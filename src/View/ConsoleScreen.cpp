#include "ConsoleScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"
#include <boost/algorithm/string.hpp>

bool gotScreenshot = false;

void ConsoleScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{
	if (!gotScreenshot) {
		gameScreen->setBitmap(al_clone_bitmap(al_get_backbuffer(al_get_current_display())));
		gameScreen->setTint(160, 160, 160);
		gotScreenshot = true;
	}

	/*Bartkowy kod - cos zwrocil python */
	std::string pythonOutput = g->getOutPythonModule().getOutput();
	if( pythonOutput.size() != 0 ){
		std::vector<std::string> strs;
		boost::split(strs, pythonOutput, boost::is_any_of("\n"));
		int i = 0;
		for( auto &oneOutLine : strs ){
			for (int j = NUMBER_OF_LINES - 1; j > 0; --j) commandLine[j]->setText(commandLine[j - 1]->getText()); // uneffective but works
			commandLine[0]->setText(oneOutLine);
		}
	}
	/* koniec */

	if (ev.type == ALLEGRO_EVENT_TIMER) {
		drawAllScenesOnDisplay(vm->getDisplay()); // remember to refresh the screen in a proper place
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		vm->exit();		// remember to include exit signal!
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
		int unichar = ev.keyboard.unichar;
		std::cout << "Unichar: " << unichar << "\n";
		if (unichar >= 32 && unichar != 96) {
			al_ustr_append_chr(input, unichar);
			commandLine[0]->setText("> " + boost::lexical_cast<std::string>(al_cstr(input)));
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_TILDE:
			gotScreenshot = false;
			str = "GameScreen";
			vm->changeActiveScreen(str);
			break;
		case ALLEGRO_KEY_BACKSPACE:
			al_ustr_remove_chr(input, al_ustr_size(input) - 1);
			commandLine[0]->setText("> " + boost::lexical_cast<std::string>(al_cstr(input)));
			break;
		case ALLEGRO_KEY_ENTER:
			/* BARTKOWY KOD */
			g->getInPythonModule().addCommand(boost::lexical_cast<std::string>(al_cstr(input)));
			g->update(); // ugly but necessary!
			/* KONIEC */

			for (int j = NUMBER_OF_LINES - 1; j > 0; --j) commandLine[j]->setText(commandLine[j - 1]->getText());
			// call the command with parameter ' commandLine[1]->getText() '
			commandLine[0]->setText("> ");	// or print response from the python module
			al_ustr_truncate(input, 0);
			break;
		}
	}
}

void ConsoleScreen::initializeScreenElements()
{
	// TODO: initialize additional elements

	// scenes
	background = createNewScene();
	texts = createNewScene();
	// drawable objects
	gameScreen = background->addDrawableObject(0, 0, NULL, "PAUSE", 0.0f, 1.0f, 460, 290);
	text = texts->addDrawableObject(0, 0, NULL, "CONSOLE SCREEN", 0.0f, 1.0f, 5, 5); // true means it's a text object
	int i = (al_get_display_height(al_get_current_display()) - 40);
	for (int j = 0; j < NUMBER_OF_LINES; ++j) {
		commandLine[j] = texts->addDrawableObject(20, i, NULL, "> ");
		i -= 25;
	}
	std::cout << title << " initialized\n";
}

ConsoleScreen::ConsoleScreen(std::string &t)
{
	title = t;
}

ConsoleScreen::~ConsoleScreen()
{
}
