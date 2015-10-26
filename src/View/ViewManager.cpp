#include "ViewManager.h"

int ViewManager::numberOfScenes()
{
	return scenes.size();
}

Scene * ViewManager::createNewScene()
{
	Scene* newScene = new Scene();
	scenes.push_back(newScene);
	return newScene;
}

ViewManager::ViewManager()
{
	display = new Display();
}

ViewManager::~ViewManager()
{
	delete display;
	// also delete for each scene in scenes
}
