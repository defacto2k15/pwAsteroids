//
// Created by defacto on 14.10.15.
//

#include <iostream>
#include "View/ViewManager.h"
//#include <allegro5/allegro5.h>

int main(int, char**){
	std::cout << " END of program " << std::endl;	//the most important part of the program - the beginning of the journey..
	
	ViewManager* manager = new ViewManager();
	Scene *scene = manager->createNewScene();
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 8; ++j) {
			scene->addDrawableObject("aa.bmp", 65*i, 56*j);
		}
	}
	manager->drawSceneOnDisplay(scene);
	system("read  -r -p \"Press any key to continue...\" key");
	delete manager;
	system("read  -r -p \"Press any key to continue...\" key");

	return 0;
}