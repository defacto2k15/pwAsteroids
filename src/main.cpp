//
// Created by defacto on 14.10.15.
//

#include <iostream>
#include "View/ViewManager.h"
//#include <allegro5/allegro5.h>

int main(int, char**){
	std::cout << " END of program " << std::endl;	//the most important part of the program - the beginning of the journey..
	
	ViewManager* manager = new ViewManager(1024, 600);
	/*Scene *scene = manager->createNewScene();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			scene->addDrawableObject("resources/aa.bmp", 65*i, 56*j);
		}
	}
	scene->addDrawableObject("resources/aa.bmp", 512, 300);*/
	manager->start();
	//system("pause");
	//system("read  -r -p \"Press any key to continue...\" key");
	//system("read  -r -p \"Press any key to continue...\" key");
	delete manager;
	system("pause");

	return 0;
}