
#ifndef PWASTEROIDS_DRAWABLEOBJECT_H
#define PWASTEROIDS_DRAWABLEOBJECT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

class DrawableObject {
public:
	ALLEGRO_BITMAP* getBitmap();
	std::string getText() { return text; }
	void setText(std::string newText) { text = newText; }
	bool isText() { return typeIsText; }
	int getPozX() { return pozX; }
	void setPozX(int newX) { pozX = newX; }
	int getPozY() { return pozY; }
	void setPozY(int newY) { pozY = newY; }
	float getAngle() { return angle; }
	void setAngle(float newAngle) { angle = newAngle; }
	float getZoom() { return zoom; }
	void setZoom(float newZoom) { zoom = newZoom; }
	DrawableObject(bool, const char*, int, int, float = 0.0f, float = 1.0f);
private:
	ALLEGRO_BITMAP* bitmap;
	std::string text;
	bool typeIsText;
	int pozX;
	int pozY;
	float angle;
	float zoom;
};

#endif