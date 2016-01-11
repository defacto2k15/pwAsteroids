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
	GameScreen(std::string&);
	~GameScreen();


	void createImage(ActorId id, std::string path){
		drawableObjects[id] = background->addDrawableObject(512, 300, path.c_str());
	}

	void createText(ActorId id, std::string text){
		drawableObjects[id] = background->addDrawableObject(512, 300, NULL, text.c_str());
	}

	void updateObject(ActorId id, Point point, Rotation rotation, ScaleToScreen screen){
		assert( drawableObjects.count(id) > 0);
		drawableObjects[id]->setPozX(point.getX());
		drawableObjects[id]->setPozY(point.getY());
		drawableObjects[id]->setAngle(rotation* 0.0174532925f);

		int xImageSize = 1024;
		float zoom = (xImageSize * screen.getX())/ (imageDataMap_[primitive.getImageType()].xSize);
		drawableObjects[id]->set
	}

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
	bool key[9] = { false, false, false, false, false, false ,false,false };

	int spaceClicks = 0;
};

#endif
