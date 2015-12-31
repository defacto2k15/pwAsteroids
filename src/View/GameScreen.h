#pragma once
#ifndef PWASTEROIDS_GAMESCREEN_H
#define PWASTEROIDS_GAMESCREEN_H

#include "Screen.h"
#include <Game.h>
#include <map>

class ViewManager;	//forward declaration
class Game;
class DrawableObject;

class GameScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void initializeScreenElements();
	std::string getTitle() { return title; }
	GameScreen(std::string&);
	~GameScreen();
private:
	std::string title;
	// additional elements - scenes, objects, variables etc.
	Scene* background;
	Scene* texts;

	std::map<ActorId, DrawableObject*> drawableObjects;
	DrawableObject* spaceClickText;
	DrawableObject* mouseInfo;
	DrawableObject* numberOfObjects;

	ALLEGRO_MOUSE_STATE msestate;
	bool key[8] = { false, false, false, false, false, false ,false };

	int spaceClicks = 0;
};

#endif
