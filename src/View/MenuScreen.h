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
	DrawableObject* button1, *button2, *button3, *button4;
	DrawableObject* selectedButton;
};

#endif#pragma once
#pragma once
