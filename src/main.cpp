//
// Created by defacto on 14.10.15.
//

#include <iostream>
#include "View/ViewManager.h"
#include "Game.h"
//#include <allegro5/allegro5.h>

int main(int, char**){
	std::cout << " END of program " << std::endl;	//the most important part of the program - the beginning of the journey..


	ViewManager* manager = new ViewManager(1024, 600);
	manager->start();
	system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	delete manager;
	//system("read  -r -p \"Press any key to continue...\" key");
	system("read  -r -p \"Press any key to continue...\" key");

	return 0;
}