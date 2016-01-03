#include "Scene.h"

DrawableObject* Scene::addDrawableObject(int x, int y, const char* path, const char* text, float a, float z, int tx, int ty)
{
	DrawableObject* newObject = new DrawableObject(x, y, path, text, a, z, tx, ty);
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
