#include "Scene.h"

void Scene::addDrawableObject(const char *path, int x, int y)
{
	DrawableObject* newObject = new DrawableObject(path, x, y);
	objects.push_back(newObject);
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
	active = false;
}
