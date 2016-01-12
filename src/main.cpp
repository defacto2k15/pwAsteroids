//
// Created by defacto on 14.10.15.
//

#include <iostream>
#include "View/ViewManager.h"
#include "Game.h"
#include <map>
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

	std::map<ImagePrimitiveType, Point> imageSizes{
			{ImagePrimitiveType::Asteroid, Point( 60, 60)},
			{ImagePrimitiveType::BorderIndicator, Point(15, 15)},
			{ImagePrimitiveType::Projectile, Point(15, 15)},
			{ImagePrimitiveType::Rocket, Point(60, 60)},
			{ImagePrimitiveType::RocketTail, Point(60, 60)},
			{ImagePrimitiveType::Heart, Point( 60, 60)},
			{ImagePrimitiveType::SecondPlayerTarget, Point( 60, 60)}
	};

	std::shared_ptr<ViewManager> manager(new ViewManager(1024, 600, imageSizes));
	manager->start();
	system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	system("read  -r -p \"Press any key to continue...\" key");

	return 0;
}