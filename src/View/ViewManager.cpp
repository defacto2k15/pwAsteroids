#include <Game.h>
#include "ViewManager.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "EmptyScreen.h"
#include <map>

void ViewManager::changeActiveScreen(std::string screenTitle)
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		if (screenTitle == (*it)->getTitle())
		{
			activeScreen = it;
			std::cout << "- Changed screen to " << (*activeScreen)->getTitle() << "\n";
			break;
		}
	}
}

void ViewManager::initializeScreens()
{
	for (it = screens.begin(); it != screens.end(); ++it)
	{
		(*it)->initializeScreenElements();
	}
	std::cout << "Initialized " << screens.size() << " screens\n";
	activeScreen = screens.begin();
}

void ViewManager::start()
{
	Game g;
	g.update();

	std::string str = "MenuScreen";
	MenuScreen* menuScreen = new MenuScreen(str);
	screens.push_back(menuScreen);

	str = "GameScreen";
	GameScreen* gameScreen = new GameScreen(str);
	screens.push_back(gameScreen);

	/* str = "EmptyScreen";
	EmptyScreen* emptyScreen = new EmptyScreen(str);
	screens.push_back(emptyScreen); */

	initializeScreens();	// must be called before drawing screens!
	std::cout << "While(1) loop\n";
	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		(*activeScreen)->eventAction(ev, this, &g);
		if (isExit) break;

			if (key[KEY_UP]) {
				g.getInKeyboardStateGetter()->gameKeyIsPressed(Keys::Player1AccelerateKey);
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

			for( auto &kv : drawableObjects ){
				kv.second->setPozX(-100);
				kv.second->setPozY(-100);
			}

			auto primitivesVec = g.getOutGameScreenModel()->getImagePrimitives();
			for( auto &primitive : primitivesVec){
				if( drawableObjects.count(primitive.getActorId()) == 0){
					const char *pathToImage;
					if( primitive.getImageType() == ImagePrimitiveType::Asteroid){
						pathToImage = "../res/asteroid.bmp";
					} else if( primitive.getImageType() == ImagePrimitiveType::Projectile) {
						pathToImage = "../res/proj.bmp";
					} else if( primitive.getImageType() == ImagePrimitiveType::BorderIndicator){
						pathToImage = "../res/arrow.bmp";
					} else if(primitive.getImageType() == ImagePrimitiveType::Heart){
						pathToImage = "../res/arrow.bmp";
					} else {
						pathToImage = "../res/aa.bmp";
					}
					drawableObjects[primitive.getActorId()] = scene->addDrawableObject(pathToImage, 512, 300);
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

ViewManager::ViewManager(int screenWidth, int screenHeight)
{
	display = new Display(screenWidth, screenHeight);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));	// Timer events (refresh)
	al_register_event_source(event_queue, al_get_display_event_source(display->getDisplay()));	// Display events (like "close" with 'X')
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// Keyboard events
	al_register_event_source(event_queue, al_get_mouse_event_source());		// Mouse events
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
