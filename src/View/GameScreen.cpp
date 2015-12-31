#include "GameScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

void GameScreen::eventAction(ALLEGRO_EVENT& ev, ViewManager* vm, Game* g)
{
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		if (key[KEY_UP]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AccelerateKey);
		}

		if (key[KEY_DOWN]) {
			//object->setPozY(object->getPozY() + speed/20);
		}

		if (key[KEY_LEFT]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1LeftKey);
		}

		if (key[KEY_RIGHT]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1RightKey);
		}

		if (key[KEY_DOWN]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AttackKey);
		}

		numberOfObjects->setText("Number of objects: " + boost::lexical_cast<std::string>(background->getNumberOfObjects()));

		g->update();

		auto primitivesVec = g->getOutGameScreenModel()->getImagePrimitives();
		for (auto &primitive : primitivesVec) {
			if (drawableObjects.count(primitive.getActorId()) == 0) {
				const char *pathToImage;
				if (primitive.getImageType() == ImagePrimitiveType::Asteroid) {
					pathToImage = "../res/asteroid.bmp";
				}
				else if (primitive.getImageType() == ImagePrimitiveType::Projectile) {
					pathToImage = "../res/proj.bmp";
				}
				else {
					pathToImage = "../res/aa.bmp";
				}
				drawableObjects[primitive.getActorId()] = background->addDrawableObject(false, pathToImage, 512, 300);
				drawableObjects[primitive.getActorId()]->setZoom((float)((1 + rand() % 200) / 50.0f));	// sets scale only for Bitmaps, not models!
			}
			drawableObjects[primitive.getActorId()]->setPozX(primitive.getPosition().getX());
			drawableObjects[primitive.getActorId()]->setPozY(primitive.getPosition().getY());
			drawableObjects[primitive.getActorId()]->setAngle(double(primitive.getRotation())*0.0174532925f);
		}

		drawAllScenesOnDisplay(vm->getDisplay());	// refresh the screen
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		vm->exit();
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			key[KEY_UP] = true;
			break;

		case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = true;
			break;

		case ALLEGRO_KEY_LEFT:
			key[KEY_LEFT] = true;
			break;

		case ALLEGRO_KEY_RIGHT:
			key[KEY_RIGHT] = true;
			break;
		case ALLEGRO_KEY_SPACE:
			++spaceClicks;
			spaceClickText->setText("Space clicks: " + boost::lexical_cast<std::string>(spaceClicks));
			if (spaceClicks >= 5) DrawableObject* yaayText = texts->addDrawableObject(true, "Yaay!!!",
				rand() % al_get_display_width(vm->getDisplay()->getDisplay()), rand() % al_get_display_height(vm->getDisplay()->getDisplay()));
			else spaceClickText->setText(spaceClickText->getText() + " (few more...)");
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			key[KEY_UP] = false;
			break;

		case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = false;
			break;

		case ALLEGRO_KEY_LEFT:
			key[KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			key[KEY_RIGHT] = false;
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		switch (ev.mouse.button) {
		case LMB:
			mouseInfo->setText("[LMB clicked");
			break;
		case RMB:
			mouseInfo->setText("[RMB clicked");
			break;
		case MMB:
			mouseInfo->setText("[MMB clicked");
			break;
		}
		al_get_mouse_state(&msestate);
		mouseInfo->setText(mouseInfo->getText() + ", x=" + boost::lexical_cast<std::string>(al_get_mouse_state_axis(&msestate, 0)) +
			", y=" + boost::lexical_cast<std::string>(al_get_mouse_state_axis(&msestate, 1)) + "]");
	}
}

void GameScreen::initializeScreenElements()
{
	// scenes
	background = createNewScene();
	texts = createNewScene();
	// drawable objects
	spaceClickText = texts->addDrawableObject(true, "Space clicks: 0 (few more..)", 30, 20);	// true means 'it's a text'
	mouseInfo = texts->addDrawableObject(true, "[Mouse info - let's click!]", 30, 80);	// true means 'it's a text'
	numberOfObjects = texts->addDrawableObject(true, ("Number of objects: " + boost::lexical_cast<std::string>(background->getNumberOfObjects())).c_str(), 30, 50);

	std::cout << title << " initialized\n";
}

GameScreen::GameScreen(std::string& t)
{
	title = t;
}

GameScreen::~GameScreen()
{
}
