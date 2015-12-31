#pragma once
#ifndef PWASTEROIDS_MENUSCREEN_H
#define PWASTEROIDS_MENUSCREEN_H

#include "Screen.h"
#include <Game.h>

// forward declaration
class ViewManager;
class Game;
class DrawableObject;

class MenuScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void initializeScreenElements();
	std::string getTitle() { return title; }
	MenuScreen(std::string&);
	~MenuScreen();
private:
	std::string title;
	// add additional elements in that place - scenes, objects, variables etc.
	Scene* background;
	DrawableObject* text;
	DrawableObject* text2;

	bool key[4] = { false, false, false, false };
};

#endif#pragma once
#pragma once
