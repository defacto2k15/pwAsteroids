#ifndef PWASTEROIDS_SCREEN_H
#define PWASTEROIDS_SCREEN_H

#include "Scene.h"
#include <iostream>
#include <string>

/* forward declarations */
class ViewManager;
class Display;
class Game;
/**
 *	Basic class for Screens.
*/
class Screen {
public:
	/**
	 *	Virtual method which does some actions when event occurs.
	 *	@param ev event which occured.
	 *	@param vm pointer to the ViewManager.
	 *	@param g pointer to the Game.
	*/
	virtual void eventAction(ALLEGRO_EVENT&ev, ViewManager*vm, Game*g);
	/**
	 *	Virtual method which is used to initialize special elements added to the Screen before it will be used
	*/
	virtual void initializeScreenElements() {}
	/**
	 *	Returns Screen title (Screen titles are used to organize Screens).
	 *	@return title of the screen.
	*/
	virtual std::string getTitle() { return "Screen"; }
	/**
	 *	Let's the Screen to change it's objects after changes in the display (like resolution).
	*/
	virtual void updateScreenAfterDisplayChanges();
	/**
	 *	Calls the draw for every active Scene added to the Screen.
	 *	@param pointer to the Display object.
	*/
	void drawAllScenesOnDisplay(Display*);
	/**
	 *	Adds new Scene to the Screen.
	 *	@return pointer to the newly created Scene.
	*/
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
