#ifndef PWASTEROIDS_EMPTYSCREEN_H
#define PWASTEROIDS_EMPTYSCREEN_H

#include "Screen.h"
#include <Game.h>

// forward declaration
class ViewManager;
class Game;
class DrawableObject;

class EmptyScreen : public Screen {
public:
	void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	void initializeScreenElements();
	std::string getTitle() { return title; }
	EmptyScreen(std::string&);
	~EmptyScreen();
private:
	std::string title;
	// add additional elements in that place - scenes, objects, variables etc.
	Scene* background;
	DrawableObject* text;
};

#endif
