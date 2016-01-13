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
	MenuScreen(std::string newTitle, std::vector<MenuModel> menus, Display *display)
			: title(newTitle), display_(display){
		background = createNewScene();
		logo = background->addDrawableObject(410, 80, NULL, "pwAsteroids (cool logo)");
		selectedButton = background->addDrawableObject(320, 170, "../res/aa.bmp", NULL, 1.570796f, 0.75f);

		for( auto &menuModel : menus){
			auto newScene = createNewScene();
			std::vector<DrawableObject *>objectsVec;
			int i = 0;
			for( auto &menuOption : menuModel.menuOptions){
				objectsVec.push_back(
						newScene->addDrawableObject(
								340, 160 + i*80, "../res/button.bmp",
								menuOption.optionTexts[menuOption.currentlySelectedText].c_str(),0.0f, 1.0f, 110, 15  ));
				i++;
			}
			newScene->changeActiveState();
			menus_[menuModel.menuType] = std::make_pair(menuModel, std::make_pair(newScene, objectsVec));
		}

		menus_[SUBMENU::SUBMENU_MAIN].second.first->changeActiveState();
		currentOption = 0;
		currentMenu = SUBMENU::SUBMENU_MAIN;
	}
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
