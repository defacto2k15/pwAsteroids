
#ifndef PWASTEROIDS_DISPLAY_H
#define PWASTEROIDS_DISPLAY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <stdexcept>
#include "Scene.h"

/**
 *	Class whoch organizes ALLEGRO_DISPLAY.
*/
class Display {
public:
	/**
	 *	Draws given Scene on Display.
	 *	@param pointer to the Scene.
	*/
	void drawSceneOnDisplay(Scene*);
	/**
	 *	Clears Display for the given color in RGB palette.
	 *	@param R color
	 *	@param G color
	 *	@param B color
	*/
	void clearDisplay(int, int, int);
	/**
	 *	Resizes Display for the given dimensions.
	 *	@param width
	 *	@param height
	*/
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