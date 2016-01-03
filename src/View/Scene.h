#ifndef PWASTEROIDS_SCENE_H
#define PWASTEROIDS_SCENE_H

#include <allegro5/allegro.h>
#include <vector>
#include "DrawableObject.h"

class Scene {
public:
	DrawableObject* addDrawableObject(int x, int y, const char* path = NULL, const char* t = NULL, float a = 0.0f, float z = 1.0f, int tx = 0, int ty = 0);
	std::vector<DrawableObject*> getSceneObjects();
	int getNumberOfObjects() { return objects.size(); }
	void changeActiveState();
	bool isActive() { return active; }
	Scene();
private:
	std::vector<DrawableObject*> objects;
	bool active;
};

#endif