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
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player1AccelerateKey);
		}

		if (key[KEY_LEFT]) {
			//g->getInputStateGetter()->gameKeyIsPressed( Keys::PauseKey);
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player1LeftKey);
		}

		if (key[KEY_RIGHT]) {
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player1RightKey);
		}

		if (key[KEY_SPACE]) {
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player1AttackKey);
		}

		if( key[KEY_LMB]){
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player2AttackKey);
		}

		if( key[KEY_RMB]){
			g->getInputStateGetter()->gameKeyIsPressed(Keys::Player2LeftKey);
		}

		numberOfObjects->setText("Number of objects: " + boost::lexical_cast<std::string>(background->getNumberOfObjects()));
		
		g->update();

		auto musicInstances = g->getOutGameMusicModel()->getMusicInstances();
		for( MusicInstance oneInstance : musicInstances){
			switch (oneInstance.getElement()){
				case MusicElements::AsteroidCollisionSound:
					vm->playSample("AsteroidCollision", oneInstance.getVolume(), true);
					break;
				case MusicElements::RocketDestructionSound:
					vm->playSample("RocketFailure", oneInstance.getVolume(), true);
					break;
				case ShootSound:
					vm->playSample("Blaster Imperial", oneInstance.getVolume(), true);
					break;
				case SecondPlayerAsteroidShoot:
					vm->playSample("SecondPlayerShoot", oneInstance.getVolume(), true);
					break;
			}
		}

		auto primitivesVec = g->getOutGameScreenModel()->getImagePrimitives();
		for( auto &pair : drawableObjects){
			pair.second->setPozX(-100);
			pair.second->setPozY(-100);
		}
		
		for (auto &primitive : primitivesVec) {
			if (drawableObjects.count(primitive.getActorId()) == 0) {

				assert(imageDataMap_.count(primitive.getImageType()) == 1);
				const char *pathToImage = imageDataMap_[primitive.getImageType()].path;
				if(primitive.getImageType() == ImagePrimitiveType::Rocket) drawableObjects[primitive.getActorId()] = background->addDrawableObject(512, 300, pathToImage, "Jeste rakieta!");
				else drawableObjects[primitive.getActorId()] = background->addDrawableObject(512, 300, pathToImage);
				if( primitive.getImageType() == ImagePrimitiveType::SecondPlayerTarget){
					int k = 22;
				}
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
				drawableObjects[primitive.getActorId()] = background->addDrawableObject(512, 300, NULL, primitive.getTextToWrite().c_str());
			}
			drawableObjects[primitive.getActorId()]->setText(primitive.getTextToWrite());
			drawableObjects[primitive.getActorId()]->setPozX(primitive.getPosition().getX());
			drawableObjects[primitive.getActorId()]->setPozY(primitive.getPosition().getY());
			drawableObjects[primitive.getActorId()]->setAngle(0);
		}

		al_get_mouse_state(&msestate);
		g->getInputStateGetter()->setMousePosition(al_get_mouse_state_axis(&msestate, 0),al_get_mouse_state_axis(&msestate, 1));

		drawAllScenesOnDisplay(vm->getDisplay());	// refresh the screen
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		vm->exit();
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		std::string str;
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
			break;

		case ALLEGRO_KEY_ESCAPE:
			str = "MenuScreen";
			vm->changeActiveScreen(str);
			break;

		case ALLEGRO_KEY_TILDE:
			str = "ConsoleScreen";
			vm->changeActiveScreen(str);
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
	spaceClickText = texts->addDrawableObject(30, 20, NULL, "Space clicks: 0 (few more..)");
	mouseInfo = texts->addDrawableObject(30, 80, NULL, "[Mouse info - let's click!]");
	numberOfObjects = texts->addDrawableObject(30, 50, NULL, ("Number of objects: "+boost::lexical_cast<std::string>(background->getNumberOfObjects())).c_str());
	std::cout << title << " initialized\n";
}

GameScreen::GameScreen(std::string& t)
{
	title = t;
	imageDataMap_[ImagePrimitiveType::Asteroid] = ImageData{ 55, 61,  "../res/asteroid.bmp" };
	imageDataMap_[ImagePrimitiveType::BorderIndicator] = ImageData{15, 15, "../res/arrow.bmp"};
	imageDataMap_[ImagePrimitiveType::Projectile] = ImageData{15, 15, "../res/proj.bmp"};
	imageDataMap_[ImagePrimitiveType::Rocket] = ImageData{60, 60, "../res/rocket.bmp"};
	imageDataMap_[ImagePrimitiveType::RocketTail] = ImageData{55, 61, "../res/aa.bmp"};
	imageDataMap_[ImagePrimitiveType::Heart] = ImageData{ 55, 61, "../res/aa.bmp"};
	imageDataMap_[ImagePrimitiveType::SecondPlayerTarget] = ImageData{ 55, 61, "../res/aa.bmp"};
}

GameScreen::~GameScreen()
{
}
