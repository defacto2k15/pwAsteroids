
#ifndef PWASTEROIDS_DRAWABLEOBJECT_H
#define PWASTEROIDS_DRAWABLEOBJECT_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

/**
 *	Basic object which is used to be drawn on Display.
*/
class DrawableObject {
public:
	/* getters and setters */
	ALLEGRO_BITMAP* getBitmap() { return bitmap; }
	void setBitmap(ALLEGRO_BITMAP* newBitmap);
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
	void setTextY(int newTextY) { textY = newTextY; }
	int getTintR() { return tintR; }
	void setTintR(int newTintR) { tintR = newTintR; }
	int getTintG() { return tintG; }
	void setTintG(int newTintG) { tintG = newTintG; }
	int getTintB() { return tintB; }
	void setTintB(int newTintB) { tintB = newTintB; }
	/**
	 *	Sets tint arguments - changes in colors of the bitmap.
	 *	@param tint for R color
	 *	@param tint for G color
	 *	@param tint for B color
	*/
	void setTint(int newTintR, int newTintG, int newTintB) { tintR = newTintR; tintG = newTintG; tintB = newTintB; }
	DrawableObject(int x, int y, const char* path = NULL, const char* t = NULL, float a = 0.0f, float z = 1.0f, int tx = 0, int ty = 0);
	~DrawableObject();
private:
	/** pointer to the ALLEGRO_BITMAP object */
	ALLEGRO_BITMAP* bitmap = NULL;
	/** text which is shown on the Display */
	std::string text;
	/** determines if the object is the text or the bitmap */
	bool typeIsText;
	/** horizontal position on the screen */
	int pozX;
	/** vertical position on the screen */
	int pozY;
	/** horizontal offset for the text */
	int textX;
	/** vertical offset for the text */
	int textY;
	float angle;
	float zoom;
	int tintR = 255, tintG = 255, tintB = 255;
};

#endif