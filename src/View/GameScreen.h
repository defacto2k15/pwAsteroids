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
	void updateScreenAfterDisplayChanges();
	void initializeScreenElements();
	std::string getTitle() { return title; }
	GameScreen(std::string, Display *display );
	~GameScreen();


	void createImage(ActorId id, std::string path);

	void createText(ActorId id, std::string text);

	void updateObject(ActorId id, Point point, Rotation rotation, float zoom);

	void deleteObject(ActorId id);

	void refreshScreen();

private:
	std::string title;
	// additional elements - scenes, objects, variables etc.
	Scene* background;
	Scene* texts;

	std::map<ActorId, DrawableObject*> drawableObjects;

	Display *display_;
};

#endif
