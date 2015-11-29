
#ifndef PWASTEROIDS_DISPLAY_H
#define PWASTEROIDS_DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <stdexcept>
#include "Scene.h"
#include <boost/thread/thread.hpp>

class Display {
public:
	void drawSceneOnDisplay(Scene*);
	Display(int = 640, int = 480);
	~Display();
private:
	ALLEGRO_DISPLAY *display;
};

#endif