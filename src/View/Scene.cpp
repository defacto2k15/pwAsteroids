#include "Scene.h"

DrawableObject* Scene::addDrawableObject(bool isText, const char* parameter, int x, int y, float angle)
{
	DrawableObject* newObject = new DrawableObject(isText, parameter, x, y, angle);
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
