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
	ConsoleScreen(std::string&);
	~ConsoleScreen();
private:
	std::string title;
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
