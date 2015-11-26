
#ifndef PWASTEROIDS_DRAWABLEOBJECT_H
#define PWASTEROIDS_DRAWABLEOBJECT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class DrawableObject {
public:
	ALLEGRO_BITMAP* getBitmap();
	int getPozX() { return pozX; }
	int getPozY() { return pozY; }
	DrawableObject(const char*, int, int);
private:
	ALLEGRO_BITMAP* bitmap;
	int pozX;
	int pozY;
};

#endif