#pragma once
#ifndef PWASTEROIDS_CONSOLESCREEN_H
#define PWASTEROIDS_CONSOLESCREEN_H

#define NUMBER_OF_LINES 15

#include "Screen.h"
#include <Game.h>

// forward declaration
class ViewManager;
class Game;
class DrawableObject;

class ConsoleScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void updateScreenAfterDisplayChanges();
	void initializeScreenElements();
	std::string getTitle() { return title; }

	void updateScreen();
	ConsoleScreen(std::string, Display *display);
	~ConsoleScreen();

	void addCharacter(int character);

	void removeScreenshot();

	void removeCharacter();

	std::string getLastLine();

	void addNewLine();

	bool isScreenshotTaken();

	void takeScreenshot();

	void writeText(std::string line);

private:
	std::string title;
	Display *display_;
	// add additional elements in that place - scenes, objects, variables etc.
	Scene* background, *texts;
	DrawableObject* text;
	DrawableObject* gameScreen;
	DrawableObject* commandLine[NUMBER_OF_LINES];

	ALLEGRO_USTR *input = al_ustr_new("");
	std::string str, screen;
};

#endif#pragma once
#pragma once
