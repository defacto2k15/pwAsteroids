#ifndef PWASTEROIDS_SCREEN_H
#define PWASTEROIDS_SCREEN_H

#include "Scene.h"
#include <iostream>
#include <string>

class ViewManager;
class Display;
class Game;

class Screen {
public:
	virtual void eventAction(ALLEGRO_EVENT&, ViewManager*, Game*);
	virtual void initializeScreenElements() {}
	virtual std::string getTitle() { return "Screen"; }
	virtual void updateScreenAfterDisplayChanges();
	void drawAllScenesOnDisplay(Display*);
	Scene* createNewScene();
	void deleteScene(Scene*);
	Screen();
	~Screen();
private:
	std::vector<Scene*> scenes;
};

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE, KEY_LMB, KEY_RMB, KEY_MMB
};

enum MYMOUSEKEYS {
	LMB = 1, RMB, MMB
};

#endif
