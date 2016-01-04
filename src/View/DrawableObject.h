
#ifndef PWASTEROIDS_DRAWABLEOBJECT_H
#define PWASTEROIDS_DRAWABLEOBJECT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

class DrawableObject {
public:
	ALLEGRO_BITMAP* getBitmap() { return bitmap; }
	void setBitmap(ALLEGRO_BITMAP* newBitmap) { bitmap = newBitmap; }
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
	int getTextX() { return textX; }
	void setTextX(int newTextX) { textX = newTextX; }
	int getTextY() { return textY; }
	void setTextY(int newTextY) { textX = newTextY; }
	int getTintR() { return tintR; }
	void setTintR(int newTintR) { tintR = newTintR; }
	int getTintG() { return tintG; }
	void setTintG(int newTintG) { tintG = newTintG; }
	int getTintB() { return tintB; }
	void setTintB(int newTintB) { tintB = newTintB; }
	void setTint(int newTintR, int newTintG, int newTintB) { tintR = newTintR; tintG = newTintG; tintB = newTintB; }
	DrawableObject(int x, int y, const char* path = NULL, const char* t = NULL, float a = 0.0f, float z = 1.0f, int tx = 0, int ty = 0);
private:
	ALLEGRO_BITMAP* bitmap = NULL;
	std::string text;
	bool typeIsText;
	int pozX;
	int pozY;
	int textX;
	int textY;
	float angle;
	float zoom;
	int tintR = 255, tintG = 255, tintB = 255;
};

#endif