#include <Game.h>
#include "ViewManager.h"
#include <map>

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

int ViewManager::numberOfScenes()
{
	return scenes.size();
}

void ViewManager::drawAllScenesOnDisplay()
{
	display->clearDisplay(40, 120, 120);
	for (auto scene : scenes)
	{
		if(scene->isActive()) display->drawSceneOnDisplay(scene);
	}
	display->flipDisplay();
}

void ViewManager::start()
{
	std::map<ActorId, DrawableObject*> drawableObjects;
	Scene* scene = createNewScene();
	Scene* texts = createNewScene();
	//DrawableObject* rocket = scene->addDrawableObject("../res/aa.bmp", 512, 300);	// example bitmap to be moved
	int spaceClicks = 0;
	DrawableObject* spaceClickText = texts->addDrawableObject(true, "Space clicks: 0 (few more..)", 50, 50);	// true means 'it's a text'
	bool key[4] = { false, false, false, false };
	//int speed = 20;
	Game g;
	g.update();
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP]) {
				g.getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AccelerateKey);
			}

			if (key[KEY_DOWN]) {
				//object->setPozY(object->getPozY() + speed/20);
			}

			if (key[KEY_LEFT]) {
				g.getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1LeftKey);
			}

			if (key[KEY_RIGHT]) {
				g.getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1RightKey);
			}

			if( key[KEY_DOWN]) {
				g.getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AttackKey);
			}
			//if(speed < 360) speed += 1;
			//if (!key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_LEFT] && !key[KEY_RIGHT]) speed = 20;
			g.update();

			auto primitivesVec = g.getOutGameScreenModel()->getImagePrimitives();
			for( auto &primitive : primitivesVec){
				if( drawableObjects.count(primitive.getActorId()) == 0){
					const char *pathToImage;
					if( primitive.getImageType() == ImagePrimitiveType::Asteroid){
						pathToImage = "../res/asteroid.bmp";
					} else if( primitive.getImageType() == ImagePrimitiveType::Projectile) {
						pathToImage = "../res/proj.bmp";
					} else {
						pathToImage = "../res/aa.bmp";
					}
					drawableObjects[primitive.getActorId()] = scene->addDrawableObject(false, pathToImage, 512, 300);
					drawableObjects[primitive.getActorId()]->setZoom((float)((1 + rand() % 200) / 50.0f));	// sets scale only for Bitmaps, not models!
				}
				drawableObjects[primitive.getActorId()]->setPozX( primitive.getPosition().getX());
				drawableObjects[primitive.getActorId()]->setPozY(primitive.getPosition().getY());
				drawableObjects[primitive.getActorId()]->setAngle( double(primitive.getRotation())*0.0174532925f);

				//std::cout << "pos: " << primitive.getPosition().toString() << " rot " << primitive.getRotation() << std::endl;
			}


			drawAllScenesOnDisplay();	// refresh the screen
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
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
				std::string str = "Space clicks: ";
				spaceClickText->setText(str + boost::lexical_cast<std::string>(spaceClicks));
				if(spaceClicks >= 5) DrawableObject* yaayText = texts->addDrawableObject(true, "Yaay!!!",
					  rand()%al_get_display_width(display->getDisplay()), rand() % al_get_display_height(display->getDisplay()));
				else spaceClickText->setText(spaceClickText->getText() + " (few more..)");
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
	}
}

Scene* ViewManager::createNewScene()
{
	Scene* newScene = new Scene();
	scenes.push_back(newScene);
	return newScene;
}

ViewManager::ViewManager(int screenWidth, int screenHeight)
{
	display = new Display(screenWidth, screenHeight);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Keyboard events
	al_start_timer(timer);
}

ViewManager::~ViewManager()
{
	al_stop_timer(timer);
	//timerThread->interrupt();
	std::cout << "Timer stopped\n";
	delete display;
	// TO DO: also delete each scene in scenes
}

void ViewManager::startTimerEvent()
{
	boost::mutex mtx;
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			std::cout << "Timer event (FPS: " << FPS << ")\n";
			mtx.lock();
			//drawAllScenesOnDisplay();			// THAT'S NOT THREAD SAFE FOR ALLEGRO!!!
			mtx.unlock();
		}
	}
}
