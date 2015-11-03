//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_DRAWINGSYSTEM_H
#define PWASTEROIDS_DRAWINGSYSTEM_H


#include <PrimitiveTypes/Point.h>
#include <PrimitiveTypes/AliasedTypes.h>
#include <PrimitiveTypes/ScaleToScreen.h>
#include "ImagePrimitiveType.h"
#include "IPrimitivesToDrawContainer.h"

class DrawingSystem {
	IPrimitivesToDrawContainer &primitivesContainer_;
public:
	DrawingSystem( IPrimitivesToDrawContainer &primitivesContainer);

	void drawImage(ImagePrimitiveType type, Point position, Rotation rotation);
private:
	ScaleToScreen getScale(ImagePrimitiveType type);
};


#endif //PWASTEROIDS_DRAWINGSYSTEM_H
