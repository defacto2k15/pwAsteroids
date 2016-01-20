#include "Scene.h"
#include <iostream>
#include <iomanip>

DrawableObject* Scene::addDrawableObject(int x, int y, const char* path, const char* text, float a, float z, int tx, int ty)
{
	DrawableObject* newObject = new DrawableObject(x, y, path, text, a, z, tx, ty);
	objects.push_back(newObject);
	return newObject;
}

void Scene::removeDrawableObject(DrawableObject *removedDO)
{
	int removedIndex = -1;
	for (int i = 0; i < objects.size(); ++i) {
		if (objects[i] == removedDO) {
			removedIndex = i;
			break;
		}
	}
	if (removedIndex != -1) {
		delete objects[removedIndex];
		objects.erase(objects.begin() + removedIndex);
		std::cout << "Object removed, number of objects : " << objects.size() << "\n";
	}
	else {
		std::cout << "  Object remove failed\n";
	}
}

std::vector<DrawableObject*> Scene::getSceneObjects()
{
	return objects;
}

void Scene::changeActiveState()
{
	if (active == false) active = true;
	else active = false;
}

Scene::Scene()
{
	active = true;
}

Scene::~Scene()
{
	for (int i = 0; i < objects.size(); ++i) {
		delete objects[i];
	}
}
