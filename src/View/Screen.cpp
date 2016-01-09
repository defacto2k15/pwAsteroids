#include "Screen.h"
#include "Display.h"
#include "ViewManager.h"

void Screen::eventAction(ALLEGRO_EVENT& ev, ViewManager *, Game *)
{
	std::cout << "Screen base event action!\n";
}

void Screen::updateScreenAfterDisplayChanges()
{
	std::cout << "Screen update after display changes\n";
}

void Screen::drawAllScenesOnDisplay(Display* display)
{
	display->clearDisplay(0,0,0);
	for (auto scene : scenes)
	{
		if (scene->isActive()) display->drawSceneOnDisplay(scene);
	}
	display->flipDisplay();
}

Scene* Screen::createNewScene()
{
	Scene* newScene = new Scene();
	scenes.push_back(newScene);
	return newScene;
}

Screen::Screen()
{
}

Screen::~Screen()
{
}
