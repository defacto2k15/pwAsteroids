#pragma once
#ifndef PWASTEROIDS_MENUSCREEN_H
#define PWASTEROIDS_MENUSCREEN_H

#define NUMBER_OF_MENUS 4

#include "Screen.h"
#include <Game.h>

// forward declaration
class ViewManager;
class Game;
class DrawableObject;

enum SUBMENU { SUBMENU_MAIN, SUBMENU_PLAY, SUBMENU_OPTIONS, SUBMENU_ABOUT };

struct MenuDescription{
public:
	SUBMENU submenu;
	std::vector<std::string> buttonsDesctiption;
};

class MenuScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void updateScreenAfterDisplayChanges();
	void initializeScreenElements();
	std::string getTitle() { return title; }
	MenuScreen(std::string&);
	~MenuScreen();
private:
	std::string title;
	// add additional elements in that place - scenes, objects, variables etc.
	Scene* background;
	Scene* menus[NUMBER_OF_MENUS];
	DrawableObject* logo;
	DrawableObject* resolutionButton;
	DrawableObject* selectedButton;
	DrawableObject* obj[6];
};

#endif#pragma once
#pragma once
