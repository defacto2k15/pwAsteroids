#include "GameScreen.h"
#include "ViewManager.h"
#include "DrawableObject.h"

struct ImageData{
	unsigned int xSize;
	unsigned int ySize;
	const char *path;
};

std::map<ImagePrimitiveType, ImageData> imageDataMap_;


void GameScreen::eventAction(ALLEGRO_EVENT& ev, ViewManager* vm, Game* g)
{
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		if (key[KEY_UP]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AccelerateKey);
		}

		if (key[KEY_LEFT]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1LeftKey);
		}

		if (key[KEY_RIGHT]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1RightKey);
		}

		if (key[KEY_SPACE]) {
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AttackKey);
		}

		if( key[KEY_LMB]){
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player2AttackKey);
		}

		if( key[KEY_RMB]){
			g->getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player2LeftKey);
		}

		numberOfObjects->setText("Number of objects: " + boost::lexical_cast<std::string>(background->getNumberOfObjects()));

		g->update();

		auto primitivesVec = g->getOutGameScreenModel()->getImagePrimitives();
		for( auto &pair : drawableObjects){
			pair.second->setPozX(-100);
			pair.second->setPozY(-100);
		}

		for (auto &primitive : primitivesVec) {
			if (drawableObjects.count(primitive.getActorId()) == 0) {

				assert(imageDataMap_.count(primitive.getImageType()) == 1);
				const char *pathToImage = imageDataMap_[primitive.getImageType()].path;
				drawableObjects[primitive.getActorId()] = background->addDrawableObject(false, pathToImage, 512, 300);
				int xImageSize = 1024;
				float zoom = (xImageSize * primitive.getScale().getX())/ (imageDataMap_[primitive.getImageType()].xSize);

				drawableObjects[primitive.getActorId()]->setZoom(zoom);	// sets scale only for Bitmaps, not models!
			}
			drawableObjects[primitive.getActorId()]->setPozX(primitive.getPosition().getX());
			drawableObjects[primitive.getActorId()]->setPozY(primitive.getPosition().getY());
			drawableObjects[primitive.getActorId()]->setAngle(double(primitive.getRotation()) * 0.0174532925f);
		}

		auto textPrimitivesVec = g->getOutGameScreenModel()->getTextPrimitives();

		for (auto &primitive : textPrimitivesVec) {
			if (drawableObjects.count(primitive.getActorId()) == 0) {
				std::cout << "Writing one primitive with text "<< primitive.getTextToWrite() << std::endl;
				drawableObjects[primitive.getActorId()] = background->addDrawableObject(true, primitive.getTextToWrite().c_str(), 512, 300);
			}
			drawableObjects[primitive.getActorId()]->setText(primitive.getTextToWrite());
			drawableObjects[primitive.getActorId()]->setPozX(primitive.getPosition().getX());
			drawableObjects[primitive.getActorId()]->setPozY(primitive.getPosition().getY());
			drawableObjects[primitive.getActorId()]->setAngle(0);
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
			key[KEY_SPACE] = true;
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
		case ALLEGRO_KEY_SPACE:
			key[KEY_SPACE] = false;
		}

	}
	else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		switch (ev.mouse.button) {
		case LMB:
			key[KEY_LMB] = true;
			break;
		case RMB:
			key[KEY_RMB] = true;
			break;
		case MMB:
			key[KEY_MMB] = true;
			break;
		}
		al_get_mouse_state(&msestate);
		mouseInfo->setText(mouseInfo->getText() + ", x=" + boost::lexical_cast<std::string>(al_get_mouse_state_axis(&msestate, 0)) +
			", y=" + boost::lexical_cast<std::string>(al_get_mouse_state_axis(&msestate, 1)) + "]");
	}
	else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		switch (ev.mouse.button) {
			case LMB:
				key[KEY_LMB] = false;
				break;
			case RMB:
				key[KEY_RMB] = false;
				break;
			case MMB:
				key[KEY_MMB] = false;
				break;
		}
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
	imageDataMap_[ImagePrimitiveType::Asteroid] = ImageData{ 55, 61,  "../res/asteroid.bmp" };
	imageDataMap_[ImagePrimitiveType::BorderIndicator] = ImageData{15, 15, "../res/arrow.bmp"};
	imageDataMap_[ImagePrimitiveType::Projectile] = ImageData{15, 15, "../res/proj.bmp"};
	imageDataMap_[ImagePrimitiveType::Rocket] = ImageData{55, 61, "../res/aa.bmp"};
	imageDataMap_[ImagePrimitiveType::RocketTail] = ImageData{55, 61, "../res/aa.bmp"};
	imageDataMap_[ImagePrimitiveType::Heart] = ImageData{ 55, 61, "../res/aa.bmp"};
}

GameScreen::~GameScreen()
{
}
