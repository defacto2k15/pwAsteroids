#include "DrawableObject.h"
#include <iostream>

ALLEGRO_BITMAP* DrawableObject::getBitmap()
{
	return bitmap;
}

DrawableObject::DrawableObject(int x, int y, const char* path, const char* t, float a, float z, int tx, int ty)
{
	typeIsText = true;
	pozX = x;
	pozY = y;
	if(path != NULL) {
		bitmap = al_load_bitmap(path);
		if (bitmap != NULL) {
			// bitmap loaded
			al_convert_mask_to_alpha(bitmap, al_map_rgb(255, 255, 255));	// alpha color - pure white
		}
	}
	if(t == NULL) text = ' ';
	else text = t;
	angle = a;
	zoom = z;
	textX = tx;
	textY = ty;
}
