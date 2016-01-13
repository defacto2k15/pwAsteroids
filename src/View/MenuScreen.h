#pragma once
#ifndef PWASTEROIDS_MENUSCREEN_H
#define PWASTEROIDS_MENUSCREEN_H

#define NUMBER_OF_MENUS 4

#include "Screen.h"
#include <Game.h>
#include <menu/MenuModel.h>
#include <algorithm>
#include <menu/Submenu.h>

// forward declaration
class ViewManager;
class Game;
class DrawableObject;



class MenuScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void updateScreenAfterDisplayChanges();
	void initializeScreenElements();
	std::string getTitle() { return title; }

	MenuScreen(std::string newTitle, std::vector<MenuModel> menus, Display *display);
	~MenuScreen();

	void goDown();

	void goUp();

	void goLeft();

	void goRight();

	SUBMENU getCurrentSubmenu();

	MenuOptionTypes getCurrentOption();

	void enterSubmenu(SUBMENU submenu);

	std::string getValueOfOption(MenuOptionTypes type);

	void updateScreen();

private:

	std::string title;
	// add additional elements in that place - scenes, objects, variables etc.
	Scene* background;

	DrawableObject* logo;
	DrawableObject* resolutionButton;
	DrawableObject* selectedButton;
	std::map<SUBMENU, std::pair<MenuModel, std::pair<Scene *, std::vector<DrawableObject *>>>> menus_;
	SUBMENU currentMenu;
	int currentOption;
	Display *display_;
};

#endif#pragma once
#pragma once
