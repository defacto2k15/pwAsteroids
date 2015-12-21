
#ifndef PWASTEROIDS_DRAWABLEOBJECT_H
#define PWASTEROIDS_DRAWABLEOBJECT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class DrawableObject {
public:
	ALLEGRO_BITMAP* getBitmap();
	int getPozX() { return pozX; }
	void setPozX(int newX) { pozX = newX; }
	int getPozY() { return pozY; }
	void setPozY(int newY) { pozY = newY; }
	float getAngle() { return angle; }
	void setAngle(float newAngle) { angle = newAngle; }
	DrawableObject(const char*, int, int, float = 0);
private:
	ALLEGRO_BITMAP* bitmap;
	int pozX;
	int pozY;
	float angle;
};

#endif