#include "GameScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"
#include "ImageData.h"




void GameScreen::eventAction(ALLEGRO_EVENT& ev, ViewManager* vm, Game* g)
{

}

void GameScreen::updateScreenAfterDisplayChanges()
{

}

void GameScreen::initializeScreenElements()
{
	// scenes
	background = createNewScene();
	texts = createNewScene();
	// drawable objects
	std::cout << title << " initialized\n";
}

GameScreen::GameScreen(std::string t, Display *display) : display_(display)
{
	title = t;
}

GameScreen::~GameScreen()
{
}

void GameScreen::refreshScreen() {
	drawAllScenesOnDisplay(display_);
}

void GameScreen::createImage(ActorId id, std::string path) {
	drawableObjects[id] = background->addDrawableObject(512, 300, path.c_str(), "Sth");
}

void GameScreen::createText(ActorId id, std::string text) {
	drawableObjects[id] = background->addDrawableObject(512, 300, NULL, text.c_str());
}

void GameScreen::updateObject(ActorId id, Point point, Rotation rotation, float zoom) {
	assert( drawableObjects.count(id) > 0);
	drawableObjects[id]->setPozX(point.getX());
	drawableObjects[id]->setPozY(point.getY());
	drawableObjects[id]->setAngle(rotation* 0.0174532925f);
	drawableObjects[id]->setZoom(zoom);
}

void GameScreen::deleteObject(ActorId id)
{
	assert(drawableObjects.count(id) > 0);
	background->removeDrawableObject(drawableObjects[id]);
}
