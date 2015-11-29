#ifndef PWASTEROIDS_SCENE_H
#define PWASTEROIDS_SCENE_H

#include <allegro5/allegro.h>
#include <vector>
#include "DrawableObject.h"

class Scene {
public:
	void addDrawableObject(const char*, int = 10, int = 10, float = 0);
	std::vector<DrawableObject*> getSceneObjects();
	void changeActiveState();
	bool isActive() { return active; }
	Scene();
private:
	std::vector<DrawableObject*> objects;
	bool active;
};

#endif