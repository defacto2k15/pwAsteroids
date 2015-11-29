#include "Scene.h"

DrawableObject* Scene::addDrawableObject(const char *path, int x, int y, float angle)
{
	DrawableObject* newObject = new DrawableObject(path, x, y, angle);
	objects.push_back(newObject);
	return newObject;
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
