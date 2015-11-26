
#ifndef PWASTEROIDS_VIEWMANAGER_H
#define PWASTEROIDS_VIEWMANAGER_H

#include <vector>
#include "Scene.h"
#include "Display.h"


class ViewManager {
public:
	int numberOfScenes();
	void drawSceneOnDisplay(Scene* scene) { display->drawSceneOnDisplay(scene); }
	Scene* createNewScene();
	ViewManager();
	~ViewManager();

private:
	std::vector<Scene*> scenes;
	Display* display;
};

#endif