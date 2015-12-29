#include "DrawableObject.h"

ALLEGRO_BITMAP* DrawableObject::getBitmap()
{
	return bitmap;
}

DrawableObject::DrawableObject(bool isT, const char* path, int x, int y, float a, float z)
{
	typeIsText = isT;
	if (typeIsText) {
		text = path;
	}
	else {
		bitmap = al_load_bitmap(path);
	}
	pozX = x;
	pozY = y;
	angle = a;
	zoom = z;
}
