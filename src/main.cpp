//
// Created by defacto on 14.10.15.
//

#include <iostream>
#include "View/ViewManager.h"
#include "Game.h"
#include <map>
#include <Controller/GameScreenEventInterpreter.h>
#include <Controller/AllegroEventInterpreter.h>
#include <Controller/MenuScreenEventInterpreter.h>
#include <Controller/ResolutionsContainer.h>
#include <menu/MenuModel.h>
#include <Controller/ConsoleScreenEventInterpreter.h>
#include "View/MenuScreen.h"
//#include <allegro5/allegro5.h>

int main(int, char**){
	std::cout << " END of program " << std::endl;	//the most important part of the program - the beginning of the journey..

//    Game g;
//    while( true ){
//        std::string input;
//        std::getline( std::cin, input );
//        std::cout << "GOT "<< input << std::endl;
//        g.getInPythonModule()->addCommand(input);
//        g.update();
//
//    }


	KeyStateFetcher keyStateFetcher; // todo set as listener
	MousePositionFetcher mousePositionFetcher; // todo set as listener


	std::map<int, Keys> keyboardToGameMap{
			{ALLEGRO_KEY_W, Keys::Player1AccelerateKey},
			{ALLEGRO_KEY_A, Keys::Player1LeftKey},
			{ALLEGRO_KEY_D, Keys::Player1RightKey},
			{ALLEGRO_KEY_SPACE, Keys::Player1AttackKey},
			{ALLEGRO_KEY_LEFT, Keys::Player2LeftKey},
			{ALLEGRO_KEY_RIGHT, Keys::Player2RightKey},
	};
	std::map<int, Keys> mouseToGameMap{
			{1, Keys::Player2AttackKey}
	};


	AllegroToGameKeyMapper keyMapper(keyStateFetcher, keyboardToGameMap, mouseToGameMap);

	ImageDataContainer imageDataContainer;
	imageDataContainer.addData(ImagePrimitiveType::Asteroid , ImageData{ 240, 240,  "../res/asteroid3.bmp" });
	imageDataContainer.addData(ImagePrimitiveType::BorderIndicator , ImageData{60, 60, "../res/arrow.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::Projectile , ImageData{60, 60, "../res/projectile.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::Rocket , ImageData{160, 240, "../res/rX.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::RocketTail , ImageData{240, 240, "../res/rockettail2.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::Heart , ImageData{ 240, 240, "../res/rocket2.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::SecondPlayerTarget , ImageData{ 240, 240, "../res/target.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::NotVisibleElement, ImageData{ 240, 240, "../res/target.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::TripleShootPowerup, ImageData{ 240, 240, "../res/target.bmp"});
	imageDataContainer.addData(ImagePrimitiveType::HealthPowerup, ImageData{ 240, 240, "../res/rX.bmp"});
    imageDataContainer.addData(ImagePrimitiveType::ExplosionCloud , ImageData{ 240, 240,  "../res/asteroid3.bmp" });

	char y[2000];
	Game game(Point( 1024, 600), imageDataContainer.getImageSizesMap(0.25f));
	char x[1000];
	Display display(1024, 600);
	GameScreen gameScreen("GameScreen", &display);

	ScreenSize screenSize( Point(1024, 600));

	std::vector<AbstractAllegroEventListener *>eventListenersVector{ &keyStateFetcher, &mousePositionFetcher};

	SoundModule soundModule;

	GameScreenEventInterpreter gameScreenInterpreter(keyMapper, mousePositionFetcher, &gameScreen, imageDataContainer, game
			, screenSize, soundModule);

	ResolutionsContainer resolutionsContainer({ std::make_pair(1024, 600), std::make_pair(800, 600), std::make_pair(1280, 1024)});

	std::vector<MenuModel> menusVector;
	MenuOption startGameOption{ MenuOptionTypes::StartGame, {"StartGame"}, 0 };
	MenuOption optionsOption{ MenuOptionTypes::Options, {"Options"}, 0 };
	MenuOption aboutOption{ MenuOptionTypes::About, {"About"}, 0 };
	MenuOption exitOption { MenuOptionTypes::Exit, {"Exit"}, 0 };
	menusVector.push_back( MenuModel{ SUBMENU::SUBMENU_MAIN, {startGameOption, optionsOption, aboutOption, exitOption} });

	MenuOption backOption {MenuOptionTypes::Back, {"Back"}, 0 };
	MenuOption applyOption{MenuOptionTypes::Apply, {"Apply"}, 0 };
	MenuOption resolutionOption{MenuOptionTypes::Resolution, resolutionsContainer.getResoutionsAsText(), 0 };

	menusVector.push_back( MenuModel{ SUBMENU::SUBMENU_OPTIONS, {resolutionOption, backOption, applyOption} });

	MenuScreen menuScreen(std::string("MenuScreen"), menusVector, &display );

	MenuScreenEventInterpreter menuScreenInterpreter(&menuScreen, resolutionsContainer);

	ConsoleScreen consoleScreen("ConsoleScreen", &display);

	ConsoleScreenEventInterpreter consoleScreenEventInterpreter( &consoleScreen, game );

	std::vector< ScreenEventInterpreter*> screenEventInterpreters{
			&menuScreenInterpreter, &gameScreenInterpreter, &consoleScreenEventInterpreter
	};

	std::vector< Screen *>screensVec{
			&gameScreen, &consoleScreen, &menuScreen
	};


	ViewManager manager(game, eventListenersVector,
						&display, screenEventInterpreters, screensVec, "GameScreen", soundModule );


//	std::shared_ptr<ViewManager> manager(
//			new ViewManager(1024, 600, game, eventListenersVector, &display,
//							interpreter, &menuScreen));
	manager.start();
	system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	system("read  -r -p \"Press any key to continue...\" key");

	return 0;
}