#include "ConsoleScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"
#include <boost/algorithm/string.hpp>

bool gotScreenshot = false;

void ConsoleScreen::eventAction(ALLEGRO_EVENT &ev, ViewManager *vm, Game *g)
{
}

void ConsoleScreen::updateScreenAfterDisplayChanges()
{
	gameScreen->setTextX(al_get_display_width(al_get_current_display()) / 2 - 20);
	gameScreen->setTextY(al_get_display_height(al_get_current_display()) / 2 - 20);
	std::cout << "X: " << gameScreen->getTextX() << ", Y: " << gameScreen->getTextY() << "\n";
	int i = (al_get_display_height(al_get_current_display()) - 40);
	for (int j = 0; j < NUMBER_OF_LINES; ++j) {
		commandLine[j]->setPozY(i);
		i -= 25;
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

ConsoleScreen::ConsoleScreen(std::string t, Display *display) : display_(display)
{
	title = t;
}

ConsoleScreen::~ConsoleScreen()
{
}

void ConsoleScreen::addCharacter(int unichar) {
	al_ustr_append_chr(input, unichar);
	commandLine[0]->setText("> " + boost::lexical_cast<std::string>(al_cstr(input)));
}

void ConsoleScreen::removeScreenshot() {
	gotScreenshot = false;
}

void ConsoleScreen::removeCharacter() {
	al_ustr_remove_chr(input, al_ustr_size(input) - 1);
	commandLine[0]->setText("> " + boost::lexical_cast<std::string>(al_cstr(input)));
}

std::string ConsoleScreen::getLastLine() {
	return boost::lexical_cast<std::string>(al_cstr(input));
}

void ConsoleScreen::addNewLine() {
	for (int j = NUMBER_OF_LINES - 1; j > 0; --j) commandLine[j]->setText(commandLine[j - 1]->getText());
	// call the command with parameter ' commandLine[1]->getText() '
	commandLine[0]->setText("> ");	// or print response from the python module
	al_ustr_truncate(input, 0);
}

bool ConsoleScreen::isScreenshotTaken() {
	return gotScreenshot;
}

void ConsoleScreen::takeScreenshot() {
	gameScreen->setBitmap(al_clone_bitmap(al_get_backbuffer(al_get_current_display())));
	gameScreen->setTint(160, 160, 160);
	gotScreenshot = true;
}

void ConsoleScreen::writeText(std::string line) {
	std::vector<std::string> strs;
	boost::split(strs, line, boost::is_any_of("\n"));
	int i = 0;
	for( auto &oneOutLine : strs ){
		for (int j = NUMBER_OF_LINES - 1; j > 0; --j) commandLine[j]->setText(commandLine[j - 1]->getText()); // uneffective but works
		commandLine[0]->setText(oneOutLine);
	}
}

void ConsoleScreen::updateScreen() {
	drawAllScenesOnDisplay(display_);
}