
#ifndef PWASTEROIDS_DISPLAY_H
#define PWASTEROIDS_DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdexcept>
#include "Scene.h"

class Display {
public:
	void drawSceneOnDisplay(Scene*);
	void clearDisplay(int, int, int);
	void resizeDisplay(int, int);
	void flipDisplay() { al_flip_display(); }
	ALLEGRO_DISPLAY* getDisplay() { return display; }
	Display(int = 640, int = 480);
	~Display();
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_FONT* font;
};

#endif