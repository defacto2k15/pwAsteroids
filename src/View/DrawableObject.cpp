#include "DrawableObject.h"

ALLEGRO_BITMAP * DrawableObject::getBitmap()
{
	return bitmap;
}

DrawableObject::DrawableObject(const char *path, int x, int y, float a)
{
	bitmap = al_load_bitmap(path);
	pozX = x;
	pozY = y;
	angle = a;
}
